
#include "io.h"

static char *applic = "/tmp/xxxPHP";
static char *webphp = "/tmp/xxxCPP";

Io::Io()
{
    ::unlink(applic);
    ::unlink(webphp);

    al = sizeof(struct sockaddr_un);
    sfd = ::socket(AF_UNIX, SOCK_DGRAM, 0);
    memset(&cpp_addr,0,sizeof(cpp_addr));

    cpp_addr.sun_family = AF_UNIX;
    ::strcpy(cpp_addr.sun_path, "/tmp/xxxCPP");

    // creates socket file
    ::bind(sfd, (const struct sockaddr *) &cpp_addr, sizeof(cpp_addr));
    system("chmod 777 /tmp/xxxCPP");

}

int Io::pool()
{

    struct  sockaddr_un php_addr={0};
    int al = sizeof(struct sockaddr_un);

    struct timeval tv={0,10000};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sfd, &fds);
    _inout.clear();
    if (::select(sfd+1, &fds, 0, 0, &tv)==1)
    {
        char request [128];

        int bytes = ::recvfrom(sfd, request, 127, 0,
                   (struct sockaddr *) &(php_addr),
                    (socklen_t*)&al);
        if(bytes > 0)
        {
            request[bytes] = 0;
            _inout = request;
        }
    }
    ::msleep(10);
    return _inout.size();
}

const char* Io::read()
{
    return _inout.c_str();
}

int  Io::write(const char* str)
{
    struct  sockaddr_un php_addr;
    ::memset(&php_addr,0,sizeof(php_addr));
     al = sizeof(struct sockaddr_un);
     php_addr.sun_family = AF_UNIX;
    ::strcpy( php_addr.sun_path,"/tmp/xxxPHP");

    //make sure when this is called the php code is blocked in  socket_recvfrom
     ::msleep(10);

    return sendto(sfd,str,
                   ::strlen(str), 0,
                   (struct sockaddr *) &(php_addr),
                   al);
}

Io::~Io()
{
    ::close(sfd);
}




