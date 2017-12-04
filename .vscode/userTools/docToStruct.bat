pushd .\.vscode\userTools
ctrlv > input
py StructDocGenerator.py --in input --gen struct > output.c
clip < output.c
vim -R output.c
popd