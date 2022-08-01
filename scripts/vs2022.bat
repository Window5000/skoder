@echo off

pushd ..
git submodule update --init --recursive
vendor\premake5.exe vs2022
popd
PAUSE