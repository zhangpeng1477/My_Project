#include <iostream>
#include <stdexcept>
using namespace std;

#include "Socket.h"

Socket::Socket()
{
}

bool Socket::open(int flag)
{
	fd = ::socket(AF_INET, SOCK_STREAM, 0);
	return (-1 != fd) ? true : false;
}

bool Socket::bind(const in_addr_t ip, u_short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = ip;
	memset(addr.sin_zero, 0, 8);

	return s_bind(&addr);
}

bool Socket::bind(const char *ip, u_short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = ::inet_addr(ip);
	memset(addr.sin_zero, 0, 8);

	return s_bind(&addr);
}

bool Socket::bind(const String &ip, u_short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = ::inet_addr(ip.data());
	memset(addr.sin_zero, 0, 8);

	return s_bind(&addr);
}

bool Socket::s_bind(struct sockaddr_in *addr)
{
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int ret = ::bind(fd, (struct sockaddr *)addr, addrlen);
	return (-1 != ret) ? true : false;
}

bool Socket::s_connect(struct sockaddr_in *addr)
{
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int ret = ::connect(fd, (struct sockaddr *)addr, addrlen);
	return (-1 != ret) ? true : false;
}

//////////////////////////////////////////////////////////////////////////////////////////////

TcpSocket::TcpSocket()throw(invalid_argument)
{
	if(!open(0)){
		throw invalid_argument("fd is invalid");
	}else{
		cout << "Open ok." << endl;
	}
}

TcpSocket::TcpSocket(const int fd)
{
	this->fd = fd;
}

TcpSocket::TcpSocket(const TcpSocket &s)
{
	this->fd = s.fd;
}

bool TcpSocket::connect(const in_addr_t ip, u_short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = ip;
	memset(addr.sin_zero, 0, 8);
	
	return s_connect(&addr);
}

bool TcpSocket::connect(const String &ip, u_short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = ::inet_addr(ip.data());
	memset(addr.sin_zero, 0, 8);
	
	return s_connect(&addr);
}

bool TcpSocket::connect(const char *ip, u_short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = ::inet_addr(ip);
	memset(addr.sin_zero, 0, 8);
	
	return s_connect(&addr);
}

//////////////////////////////////////////////////////////////////////////////////////////////
TcpServer::TcpServer()throw(invalid_argument)
{
	if(!open(0)){
		throw invalid_argument("fd is invalid");
	}else{
		cout << "Open ok." << endl;
	}
}

TcpServer::~TcpServer()
{
	close();
}

#define WAITMAX 10

bool TcpServer::listen(const in_addr_t ip, u_short port)
{
	bool ret = bind(ip, port);
	if(ret){
		ret = (-1!=::listen(fd, WAITMAX)) ? true : false;
	}else{
		cout << this << " : " << __func__ << " : bind fail " << endl;
	}

	return ret; 
}

bool TcpServer::listen(const String &ip, u_short port)
{
	bool ret = bind(ip, port);
	if(ret){
		ret = (-1!=::listen(fd, WAITMAX)) ? true : false;
	}else{
		cout << this << " : " << __func__ << " : bind fail " << endl;
	}

	return ret; 
}

bool TcpServer::listen(const char *ip, u_short port)
{
	bool ret = bind(ip, port);
	if(ret){
		ret = (-1!=::listen(fd, WAITMAX)) ? true : false;
	}else{
		cout << this << " : " << __func__ << " : bind fail " << endl;
	}

	return ret; 
}

bool TcpServer::wait(TcpSocket &s)
{
	struct sockaddr_in addr;
	socklen_t addrlen = sizeof(addr);
	int rws = ::accept(fd, (struct sockaddr*)&addr, &addrlen);

	s = TcpSocket(rws);

	return (-1!=rws) ? true : false;
}
