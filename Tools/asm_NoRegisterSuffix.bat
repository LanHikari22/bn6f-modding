pushd .\.vscode\userTools
ctrlv > input
py RegisterSuffixRemover.py > output.c
vim -R output.c
popd