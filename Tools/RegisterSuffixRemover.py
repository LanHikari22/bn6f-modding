


def parse(line: str):
    output = line
    for i in range(11):
        s1 = 'r%d_' % i
        s2 = 'r%d:' % i
        while s1 in output:
            output = output.replace(s1,'')
        while s2 in output:
            output = output.replace(s2,'')


    return output
if __name__ == "__main__":
    inputFile = open("input", "r")
    output = ''
    line = '\0'
    while line != '':
        line = inputFile.readline()
        output += parse(str(line))
    print(output)