
<?php

unlink("/tmp/xxxPHP");
$sock = socket_create (AF_UNIX, SOCK_DGRAM, 0 );
socket_bind ( $sock , "/tmp/xxxPHP" );
chmod("/tmp/xxxPHP", 0777);
socket_set_option($sock,SOL_SOCKET,SO_RCVTIMEO,array("sec"=>3,"usec"=>0));

function send($data)
{
    global $sock;
    socket_sendto($sock, $data, strlen($data), 0, "/tmp/xxxCPP", 0);
}

function receive()
{
    global $sock;
    $from=""; $buf="";$port=0;
    socket_recvfrom($sock, $buf, 1024, 0, $from, $port);
    return $buf;
}
if(isset($_GET['c']))
    send($_GET['c']);
else
    send("status");
echo receive();
socket_close($sock);

?>
