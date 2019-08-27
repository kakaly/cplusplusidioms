#pragma once

#include <iostream>
#include <memory>

using namespace std;


class MyClassPimpl;
class MyClass
{
public:

  MyClass();
  ~MyClass();

  // Copy constructor
  MyClass& operator=(const MyClass& rhs) noexcept;
  MyClass(MyClass& rhs) noexcept;

  // Move constructor
  MyClass(MyClass&& rhs) noexcept;
  MyClass& operator=(MyClass&& rhs) noexcept;

  void doSomething(int a);

private:

  unique_ptr<MyClassPimpl> m_myClassPimpl;

  MyClassPimpl* m_MyPimpl()
  {
    return m_myClassPimpl.get();
  }
};