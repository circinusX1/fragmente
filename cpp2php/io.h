#ifndef IO_H
#define IO_H


#include <unistd.h>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <string.h>
#include "main.h"

class Io
{
public:
    Io();
    ~Io();

    int pool();
    const char* read();
    int  write(const char* str);

    static void expose(SqEnv& e){
        Sqrat::Class<Io> cls(e.theVM(), _SC("Io"));
        cls.Func(_SC("pool"), &Io::pool);
        cls.Func(_SC("read"), &Io::read);
        cls.Func(_SC("write"), &Io::write);
        Sqrat::RootTable().Bind(_SC("Io"), cls);

    }

private:

    socklen_t al;//  = sizeof(struct sockaddr_un);
    int       sfd; // = socket(AF_UNIX, SOCK_DGRAM, 0);
    struct sockaddr_un cpp_addr;// = {0};
    std::string _inout;
};

#endif // IO_H
