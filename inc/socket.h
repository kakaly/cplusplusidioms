#pragma once

#include <iostream>

using namespace std;

class Socket
{
public:
  Socket(int port)
   : m_port(port)
  {
    cout << "Socket " << m_port << " constructed on heap\n";
  }
  ~Socket()
  {
    cout << "Socket " << m_port << " destructed from heap\n";
  }
  Socket(Socket& r_socket) = default;
  Socket& operator=(Socket& r_socket) = default;
  Socket(Socket&& r_socket) = default;
  Socket& operator=(Socket&& r_socket) = default;

private:
  int m_port;
};