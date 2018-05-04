# BitSet in C
An implementation of bit sets in C.

### Building
To build the static library,  run the following commands from the terminal:
```bash
mkdir build && cd build && cmake .. && make ; cd ..
```
This will build ```libBitSet.a``` in ```./bin``` directory.

### Usage
Include ```BitSet.h``` in the source file and link to ```libBitSet.a``` while compiling the source file.

See ```include/BitsSet.h``` for information about functionality provided by this module.
