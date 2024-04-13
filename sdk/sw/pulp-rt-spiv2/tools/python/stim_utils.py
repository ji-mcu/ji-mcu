#
# Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves Technologies
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# 
# Authors: Germain Haugou, ETH (germain.haugou@iis.ee.ethz.ch)
#
from elftools.elf.elffile import ELFFile
import os
import os.path



class stim(object):


  def __init__(self):
    self.binaries = []
    self.mem = {}


  def add_binary(self, binary):
    self.binaries.append(binary)


  def __add_mem_word(self, base, size, data, width):

    aligned_base = base & ~(width - 1)

    shift = base - aligned_base
    iter_size = width - shift
    if iter_size > size:
      iter_size = size

    value = self.mem.get(str(aligned_base))
    if value is None:
      value = 0

    value &= ~(((1<<width) - 1) << (shift*8))
    value |= int.from_bytes(data[0:iter_size], byteorder='little') << (shift*8)

    self.mem[str(aligned_base)] = value

    return iter_size





  def __add_mem(self, base, size, data, width):

    while size > 0:

      iter_size = self.__add_mem_word(base, size, data, width)

      size -= iter_size
      base += iter_size
      data = data[iter_size:]


  def __gen_stim(self, filename, width):

    try:
      os.makedirs(os.path.dirname(filename))
    except:
      pass

    with open(filename, 'w') as file:
      for key in sorted(self.mem.keys()):
        file.write('%X_%0*X\n' % (int(key), width*2, self.mem.get(key)))


  def gen_stim_64(self, stim_file):

    for binary in self.binaries:

        with open(binary, 'rb') as file:
            elffile = ELFFile(file)

            for segment in elffile.iter_segments():

                if segment['p_type'] == 'PT_LOAD':

                    data = segment.data()
                    addr = segment['p_paddr']
                    size = len(data)

                    print ('Loading section (base: 0x%x, size: 0x%x)' % (addr, size))

                    self.__add_mem(addr, size, data, 8)

                    if segment['p_filesz'] < segment['p_memsz']:
                        addr = segment['p_paddr'] + segment['p_filesz']
                        size = segment['p_memsz'] - segment['p_filesz']
                        print ('Init section to 0 (base: 0x%x, size: 0x%x)' % (addr, size))
                        self.__add_mem(addr, size, [0] * size, 8)

    self.__gen_stim(stim_file, 8)
