import sys
import stim_utils

stim = stim_utils.stim()
stim.add_binary(sys.argv[1])
stim.gen_stim_64(sys.argv[2])
