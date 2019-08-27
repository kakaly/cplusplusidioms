#include "pimpl.h"

#include <iostream>
#include <memory>

using namespace std;

class MyClassPimpl
{
public:

  MyClassPimpl()
  {
    cout << "MyClassPimpl constructor called\n\n";
  }

  ~MyClassPimpl()
  {
    cout << "MyClassPimpl destructor called\n\n";
  }

  void doSomething(int a)
  {
    cout << "MyClassPimpl doSomething called\n";
    cout << a << "\n";
  }

};

MyClass::MyClass() :
  m_myClassPimpl(new MyClassPimpl())
{
  cout << "MyClass constructor called\n\n";
}

MyClass::~MyClass()
{
  cout << "MyClass destructor called\n\n";
  m_myClassPimpl.reset();
}

MyClass& MyClass::operator=(const MyClass& rhs) noexcept
{
  cout << "MyClass assignment operator called\n\n";
  // if(rhs.m_myClassPimpl.get() != nullptr)
  // {
  //   m_myClassPimpl = new MyClassPimpl();
  // }
  return *this;
}

MyClass::MyClass(MyClass& rhs) noexcept
{
  cout << "MyClass copy constructor called\n\n";
  this->m_myClassPimpl = move(rhs.m_myClassPimpl);
}

// Move constructor
MyClass::MyClass(MyClass&& rhs) noexcept = default;

MyClass& MyClass::operator=(MyClass&& rhs) noexcept = default;

void MyClass::doSomething(int a)
{
  cout << "MyClass doSomething called\n";
  m_MyPimpl()->doSomething(a);
}
