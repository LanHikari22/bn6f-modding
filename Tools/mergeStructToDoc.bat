pushd .\.vscode\userTools
ctrlv > input
py StructDocGenerator.py --in input --gen doc --merge input2 > output
clip < output
vim -R output
popd