#!/bin/sh

script_dir=$(dirname "$(readlink -f "$0")")

cd $script_dir

git clone https://github.com/dism-exe/bn6f
git clone https://github.com/luckytyphlosion/agbcc -b new_layout_with_libs

cd agbcc
make -j$(nproc)
make install prefix=../bn6f

cd ../bn6f/tools/gbagfx
make

cd ../..
make assets -j$(nproc)
make -j$(nproc)

git log | sed -n 1p | cut -d' ' -f2 > COMMIT

rm -rf .git
cd ..
rm -rf agbcc

python3 tools/replace_chunks_in_files.py hooking/hooks
cp hooking/modding.s bn6f/
