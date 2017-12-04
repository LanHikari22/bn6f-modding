pushd .\.vscode\userTools
ctrlv > input
py StructDocGenerator.py --in input --gen doc > output
clip < output
vim -R output
popd