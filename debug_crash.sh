
### compile with CXX and CC flags  -DDEBUG -g

### add a start script.

```
#!/bin/bash

ulimit -S -c unlimited /path/to/binary/mybinary
sysctl -w kernel.core_pattern=/home/path/to/binary/dump
```

### after crash go to /home/path/to/binary/dump

```
gdb -c dump-file-......

(gdb)file /path/to/binary/mybinary
(gdb) bt

```

