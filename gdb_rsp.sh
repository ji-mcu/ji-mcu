# !/bin/bash

source ./set_env.sh

plpbridge --chip=pulpissimo --cable=ftdi@digilent gdb wait --rsp-port=1234
