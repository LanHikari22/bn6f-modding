import sys
import os
import argparse
from typing import Optional, List

class T:
    pass

tt = T()

def read_file_content(path: str) -> Optional[str]:
    if not os.path.exists(path):
        print("Error (fn read_file_content): path does not exist: " + path)
        return None

    with open(path, 'r') as f:
        s = f.read()
        return s

def write_file_content(path: str, new_content: str) -> Optional[str]:
    with open(path, 'w') as f:
        f.write(new_content)

class ReplaceInstruction:
    def __init__(self, path: str, old_chunk: str, new_chunk: str):
        self.path = path
        self.old_chunk = old_chunk
        self.new_chunk = new_chunk

    def run(self) -> Optional[T]:
        content = read_file_content(self.path)
        if not content:
            return

        if self.old_chunk not in content:
            print("Error (fn ReplaceInstruction::run): Content not present in file: " + self.path)
            return

        new_content = content.replace(self.old_chunk, self.new_chunk)

        write_file_content(self.path, new_content)

def parse_instructions_file(path: str) -> Optional[List[ReplaceInstruction]]:
    content = read_file_content(path)
    if not content:
        return

    mut_state = {}
    mut_state['out'] = []
    mut_state['opt_path'] = None
    mut_state['old_chunk'] = ''
    mut_state['new_chunk'] = ''

    def check_push_instruction() -> Optional[T]:
        if mut_state['opt_path'] is not None:
            if mut_state['old_chunk'] == '':
                print("Error (fn check_push_instruction): Did not specify anything to replace for path " + mut_state['opt_path'])
                return None

            mut_state['out'].append(ReplaceInstruction(mut_state['opt_path'], mut_state['old_chunk'], mut_state['new_chunk']))
            mut_state['old_chunk'] = ''
            mut_state['new_chunk'] = ''
            mut_state['opt_path'] = None

        return tt

    for line in content.splitlines():
        if line.startswith('#') or line.startswith('//') or line == '':
            continue
        if line.startswith('-'):
            mut_state['old_chunk'] += line[1:] + '\n'
        elif line.startswith('+'):
            mut_state['new_chunk'] += line[1:] + '\n'
        else:
            if not check_push_instruction():
                return None
            mut_state['opt_path'] = line

    if check_push_instruction() is None:
        return None

    return mut_state['out']



def main(args: argparse.Namespace):
    instructions = parse_instructions_file(args.instructions_path)
    if instructions is None:
        return

    for instruction in instructions:
        print("Replacing in " + instruction.path)
        instruction.run()



def parse_cmdline_args() -> argparse.Namespace:
    desc = '''
    Follows instructions to replace chunks in files.
    First line is the path to the file. Following lines either start with - or +. - indicates to-be-replaced, + to-replace.
    Empty lines and lines starting with '#' or '//' will be ignored.
    '''

    p = argparse.ArgumentParser(prog='replace_chunk_in_file', description=desc,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    
    p.add_argument('-v', '--verbose', action='count', default=0,
                   help='Increase verbosity level (use -v, -vv, or -vvv)')
    p.add_argument('instructions_path',
                    help='path to the file containing the instructions for replacing content in files.')
                   
    return(p.parse_args())

def _main():
    if sys.version_info<(3,5,0):
        sys.stderr.write("You need python 3.5 or later to run this script\n")
        sys.exit(1)

    args = parse_cmdline_args()
    return main(args)

if __name__ == '__main__':
    _main()
