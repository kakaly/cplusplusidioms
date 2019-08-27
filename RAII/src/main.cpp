
#include "socket.h"
#include "socket_manager.h"

#include <iostream>
#include <utility>

using namespace std;


int main()
{
  cout << "\n\nRAII: Socket Resource management using SocketManager\n\n";

  {
    cout << "Rule 1: Destructor\n";
    cout << "Socket gets destructed when SocketManager goes out of scope\n\n";
    SocketManager socketManager1(3001, "10.1.1.1");
    cout << "\nLeaving the scope of Rule 1\n\n";
  }

  {
    cout << "\n\nRule 2: Copy assignment operator\n\n";
    SocketManager socketManager1(3001, "10.1.1.1");
    cout << "\n\n";
    SocketManager socketManager2(3002, "10.1.1.2");
    cout << "\n\n";
    socketManager1 = socketManager2;
    cout << "\nLeaving the scope of Rule 2\n\n";
  }

  {
    cout << "\n\nRule 3: Copy constructor\n\n";
    SocketManager socketManager1(3001, "10.1.1.1");
    cout << "\n\n";
    SocketManager socketManager2(socketManager1);
    cout << "\nLeaving the scope of Rule 3\n\n";
  }

  {
    cout << "\n\nRule 4: Move constructor\n\n";
    SocketManager socketManager1(3001, "10.1.1.1");
    cout << "\n\n";
    SocketManager socketManager2(move(socketManager1));
    cout << "\nLeaving the scope of Rule 4\n\n";
  }

  {
    cout << "\n\nRule 5: Move assignment operator\n\n";
    SocketManager socketManager1(3001, "10.1.1.1");
    cout << "\n\n";
    SocketManager socketManager2;
    cout << "\n\n";
    socketManager2 = move(socketManager1);
    cout << "\nLeaving the scope of Rule 5\n\n";
  }
}