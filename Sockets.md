What is socket Programming? 
Socket Programming is a way to Make two Nodes communicate with each  other on the Router/Switch...
The server Waits for a connection from a client, and the client connects to the server.

1.Socket Creation
`int socketfd = socket(domain, type, protocol)`
- **sockfd:** socket descriptor, an integer (like a file handle)
- **domain:** integer, specifies communication domain. We use AF_ LOCAL as defined in the POSIX standard for communication between processes on the same host. For communicating between processes on different hosts connected by IPV4, we use AF_INET and AF_I NET 6 for processes connected by IPV6.
- **type:** communication type  
    SOCK_STREAM: TCP(reliable, connection-oriented)  
    SOCK_DGRAM: UDP(unreliable, connection-less)
- **protocol:** Protocol value for Internet Protocol(IP), which is 0. This is the same number that appears on the protocol field in the IP header of a packet.
A simple Socket that Uses IPV4 and a TCP/IP protocol would be something like this:
`int socketfd= socket(AF_INET,SOCK_STREAM,0)`
2.Creating a structure For our address
Using this header File  `<netinet/in.h>`
We can define Out Structure this [blog](https://man7.org/linux/man-pages/man3/sockaddr.3type.html) have great resources and explains the structures with great documentation.
3.Binding a Socket.

` bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`

After the creation of the socket, the bind function binds the socket to the address and port number specified in addr(custom data structure). In the example code, we bind the server to the localhost, hence we use INADDR_ANY to specify the IP address.
4.Listening 
`listen(int socketfd,int backlog);`
The socketfd argument  is  a file descriptor that refers to a socket of type SOCK_STREAM or SOCK_SEQPACKET, thus the argument backlog is just how many connection to listen too