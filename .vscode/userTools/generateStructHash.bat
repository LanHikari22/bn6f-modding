pushd .\.vscode\userTools
ctrlv > input
py MemoryAccessProtocol.py input hash > output.c
clip < output.c
vim -R output.c
popd