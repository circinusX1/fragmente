# Compiling s2w10lqt.creator  using qt 5.12.*

* Make sure you have qtcreator 5.12 or greater.

```
sudo apt-get install gcc-arm-none-eabi binutils
sudo apt-get install openocd
sudo apt-get install libusb-1.0-0-dev
sudo apt-get install build-essential libgtk-3-dev

wget http://mirrors.kernel.org/ubuntu/pool/universe/g/gdb-arm-none-eabi/gdb-arm-none-eabi_7.10-1ubuntu3+9_amd64.deb
wget http://http.us.debian.org/debian/pool/main/r/readline6/libreadline6-dev_6.3-8+b3_amd64.deb
wget http://mirrors.kernel.org/ubuntu/pool/main/r/readline6/libreadline6_6.3-8ubuntu2_amd64.deb
sudo dpkg -i libreadline6_6.3-8ubuntu2_amd64.deb
sudo dpkg -i gdb-arm-none-eabi_7.10-1ubuntu3+9_amd64.deb

git clone https://github.com/texane/stlink   (follow readme, and install it)

cd stlink
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install

# check followings 

$ which openocd
/usr/bin/openocd

$ which st-util
/usr/local/bin/st-util


```


* Main Menu -> Tools -> Options -> (Message Box NO) 
*     [Options] Left Pane -> Devices -> Tab [Bare Metal]


baremet-1.jpg
baremet-2.jpg

* Compiler

baremet-3
baremet-4

* Debugger

baremet-5

* KITS  (make a kit form compiler bare metal and debugger)



