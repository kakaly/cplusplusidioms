
#include "callbacks.h"

#include <iostream>
#include <utility>

using namespace std;


extern "C" void cFunctionCallback(uint32_t arg)
{
  cout << "C Function callback called\n\n";
}

class Client
{
public:
  void callback(uint32_t arg)
  {
    cout << "Client callback called\n\n";
  }
};

int main()
{
  cout << "\n\nCallbacks: Ways to register a callback\n\n";
  cout << "Basic Driver call back\n\n";
  
  BasicDriven bd(5);
  uint32_t result = 1;
  
  // Lambda function call back
  bd.register_callbacks([&result](uint32_t arg) -> void
  {
    cout << "Lambda function callback called\n";
    cout << "Given arg is: " << arg << "\n\n";
    result = arg;
  });

  // class function call back
  Client c1;
  bd.register_callbacks(bind(&Client::callback, &c1, placeholders::_1));

  // C Function call back
  bd.register_callbacks(&cFunctionCallback);

  bd.fire_callbacks();
  cout << "Result is: " << result << "\n\n";

  cout << "Event Driver call back\n\n";
  
  Event ev = VIDEO_START;
  EventDriven eventDriven(ev);
  
  // Lambda function call back
  eventDriven.register_callbacks({
    [&result](uint32_t arg) -> void
    {
      cout << "Lambda function callback called\n";
      cout << "Given arg is: " << arg << "\n\n";
      result = arg;
    },
    ev
  });

  // class function call back
  eventDriven.register_callbacks({bind(&Client::callback, &c1, placeholders::_1), ev});

  // C Function call back
  eventDriven.register_callbacks({&cFunctionCallback, ev});

  eventDriven.fire_callbacks();
  cout << "Result is: " << result << "\n";


}