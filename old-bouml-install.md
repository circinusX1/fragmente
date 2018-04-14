 INSTALL OLD BOUML WITH FILE SAVE AND SUCH...
Ubuntu 13 and 14 

This is a BOUML version prior to licensing stuff. BOUML release 4.21
Prerequisites:

    Ubuntu: Ubuntu 16.XX

 - You  might be missing more dependencies, because I might have them installed but this is the procedure.

    Goto http://www.ubuntuupdates.org/package/core/precise/universe/base/bouml or download the 64 bit version from 
    
    Goto https://launchpad.net/ubuntu/quantal/amd64/libqt3-mt/3:3.3.8-b-8ubuntu3    or download the deb package from here
    Goto https://packages.debian.org/sid/amd64/libmng1/download  or download it from here
    Goto https://packages.debian.org/sid/amd64/libjpeg62-turbo/download or download the deb from here 
     
    Install packages in reverse order
    If you run in a package you dont have, search it and install it. On my machine I just need the libqt3-mt, libmng1 and libjpeg62-turbo
    or http://http.us.debian.org/debian/pool/main/libj/libjpeg-turbo/libjpeg62-turbo_1.3.1-12_amd64.deb

The bouml should be available under Main Menu - > Programming

### For full links check the post here:

http://comarius.blogspot.ca/2016/02/bouml-421-free-version-for-ubuntu-13-x64.html


### tips
ln -s /usr/lib/x86_64-linux-gnu/libmng.so.2 /usr/lib/x86_64-linux-gnu/libmng.so.1

 3052  sudo dpkg -i libjpeg62-turbo_1.5.2-2+b1_amd64.deb 
 3090  sudo dpkg -i libmng1_1.0.10+dfsg-3.1+b3_amd64.deb
 3091  sudo dpkg -i libqt3-mt_3.3.8-b-8ubuntu3_amd64.deb
 3093  sudo dpkg -i bouml_4.21-1_amd64.deb




