#pragma once

#include "socket.h"

#include <iostream>

using namespace std;

class SocketManager
{
public:
  // Constructor
  SocketManager() :
    m_socket(nullptr),
    m_ip("")
  {
    cout << "SocketManager default constructor\n";
  }

  SocketManager(int port, string ip) :
    m_socket(new Socket(port)),
    m_ip(ip)
  {
      cout << "SocketManager " << m_ip << " constructed\n";
  }

  // Destructor
  ~SocketManager()
  {
    cout << "SocketManager " << m_ip << " destructed\n";
    if(m_socket != nullptr)
    {
      delete m_socket;
    }
  }

  // Copy assignment operator
  SocketManager& operator=(SocketManager& r_socketManager)
  {
    cout << "SocketManager " << m_ip << " copy assignment operator\n";
    Socket* temp =  new Socket(*(r_socketManager.m_socket));
    delete this->m_socket;
    this->m_socket = temp;
    this->m_ip = r_socketManager.m_ip;

    return *this;
  }

  // Copy constructor
  SocketManager(SocketManager& r_socketManager)
  {
    cout << "SocketManager " << m_ip << " copy constructor\n";
    if(r_socketManager.m_socket != nullptr)
    {
      this->m_socket = new Socket(*(r_socketManager.m_socket));
    }
    this->m_ip = r_socketManager.m_ip;
  }

  // Move constructor
  SocketManager(SocketManager&& r_socketManager) :
    m_ip(r_socketManager.m_ip),
    m_socket(r_socketManager.m_socket)
  {
    cout << "SocketManager " << m_ip << "  move constructor\n";
    r_socketManager.m_socket = nullptr;
  }

  // Move assignment operator
  SocketManager& operator=(SocketManager&& r_socketManager)
  {
    cout << "SocketManager " << m_ip << " move assignment operator\n";
    if(this != &r_socketManager)
    {
      if(m_socket != nullptr)
      {
        delete m_socket;
      }
      m_socket = r_socketManager.m_socket;
      m_ip = r_socketManager.m_ip;
      r_socketManager.m_socket = nullptr;
    }

    return *this;
  }

// private:

  Socket* m_socket;
  string m_ip;
};