#!/bin/bash

cpwd=$(pwd -P)

cd ~
source 664.sh
cd ${cpwd}

cd /besfs/users/songyx/workArea_664/TestRelease/TestRelease-00-00-80/cmt
cmt br cmt config
cmt br make clean
cmt br make
source setup.sh

cd ${cpwd}
