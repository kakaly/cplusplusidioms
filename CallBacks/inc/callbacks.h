#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

typedef function<void(uint32_t)> cb_t;

class BasicDriven
{
public:
  BasicDriven(uint32_t arg) :
    m_arg(arg),
    m_callbacks()
  {
    cout << "BasicDriven constructor called\n\n";
  }

  ~BasicDriven()
  {
    cout << "BasicDriven destructor called\n\n";
  }

  void register_callbacks(cb_t cb)
  {
    cout << "Callback registered\n\n";
    m_callbacks.push_back(cb);
  }

  void fire_callbacks()
  {
    cout << "Callbacks fired\n\n";
    for(const auto& cb : m_callbacks)
    {
      cb(m_arg);
    }
  }

private:
  vector<cb_t> m_callbacks;
  uint32_t m_arg;
};


enum Event
{
  VIDEO_START,
  VIDEO_STOP 
};

struct EventCallBack
{
  cb_t callback;
  Event ev_t;
};

class EventDriven
{
public:
  EventDriven(Event evt) :
    m_evt(evt),
    m_callbacks()
  {
    cout << "EventDriven constructor called\n\n";
  }

  ~EventDriven()
  {
    cout << "EventDriven destructor called\n\n";
  }

  void register_callbacks(EventCallBack cb)
  {
    cout << "Callback registered\n\n";
    m_callbacks.push_back(cb);
  }

  void fire_callbacks()
  {
    for(auto const& cb : m_callbacks)
    {
      if(cb.ev_t == m_evt)
      {
        cb.callback(15);
      }
    }
  }
private:
  vector<EventCallBack> m_callbacks;
  Event m_evt;
};
