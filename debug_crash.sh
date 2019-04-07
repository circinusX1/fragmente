
* CXX CC FLAGS   +=  '-DDEBUG -g'

```
#!/bin/bash

ulimit -S -c unlimited /path/to/binary/mybinary
sysctl -w kernel.core_pattern=/home/path/to/binary/dump
```

* after crash go to /home/path/to/binary/dump

```
gdb -c dump-file-......

(gdb)file /path/to/binary/mybinary
(gdb) bt

```

