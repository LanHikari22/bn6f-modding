pushd .\.vscode\userTools
ctrlv > input
py MemoryAccessProtocol.py input struct > output.c
clip < output.c
vim -R output.c
popd