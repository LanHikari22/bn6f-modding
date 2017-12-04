pushd .\.vscode\userTools
ctrlv > input
py MemoryAccessProtocol.py input functions > output.c
clip < output.c
vim -R output.c
popd