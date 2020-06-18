#ifndef SOCKET_H
#define SOCKET_H

#include <stdexcept>
using namespace std;

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "String.h"
#include "BaseIO.h"

class Socket : public BaseIO{
protected:
	Socket();

public:
	bool bind(const in_addr_t ip, u_short port);
	bool bind(const char *ip, u_short port);
	bool bind(const String &ip, u_short port);

protected:
	virtual bool open(int flag);

	bool s_bind(struct sockaddr_in *addr);
	bool s_connect(struct sockaddr_in *addr);
};

class TcpSocket : public Socket{
public:
	TcpSocket()throw(invalid_argument);
	TcpSocket(const int);
	TcpSocket(const TcpSocket &);

public:
	bool connect(const in_addr_t ip, u_short port);
	bool connect(const String &ip, u_short port);
	bool connect(const char *ip, u_short port);
};

class TcpServer : protected Socket{
public:
	TcpServer()throw(invalid_argument);
	~TcpServer();
public:
	bool listen(const in_addr_t ip, u_short port);
	bool listen(const String &ip, u_short port);
	bool listen(const char *ip, u_short port);

	bool wait(TcpSocket &s);
};

#endif
