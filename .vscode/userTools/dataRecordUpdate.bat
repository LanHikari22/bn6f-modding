pushd .\.vscode\userTools
ctrlv > input
py DataRecord.py --in input --gen table > output
clip < output
vim -R output
popd