#!/bin/bash
PATH=./temp/sdk/
cd 
{ 
	cd $PATH
}

DIR=$(pwd)

source ./set_toolschain_env.sh
echo "DIR = $DIR"

cd $DIR/toolchain/bin/



