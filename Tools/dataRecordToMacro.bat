pushd .\.vscode\userTools
ctrlv > input
py DataRecord.py --in input --gen macro > output
clip < output
vim -R output
popd