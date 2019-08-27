
#include "pimpl.h"

#include <iostream>
#include <utility>

using namespace std;


int main()
{
  cout << "\n\nPimpl: Pointer to Implementation Idiom\n\n";

  MyClass* myclass = new MyClass();
  myclass->doSomething(1);
}