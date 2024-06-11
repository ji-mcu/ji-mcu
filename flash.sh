# /bin/bash

ACHITECUTRE=riscv:rv32
PORT=1234
ELF_PATH=/home/rupert/workpace/ji-mcu/sdk/sw/apps/vendor/build/vendor/vendor

gnome-terminal -- bash -c " source ./load.sh; ./riscv32-unknown-elf-gdb --eval-command='set architecture $ACHITECUTRE' --eval-command='target remote localhost:$PORT' --eval-command='file $ELF_PATH' --eval-command='load';exec bash"

source ./gdb_rsp.sh
	


