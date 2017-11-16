#ifndef __HPCA_TUTORIAL_HELLO_OBJECT_HH__
#define __HPCA_TUTORIAL_HELLO_OBJECT_HH__

#include "params/HelloObject.hh"
#include "sim/eventq.hh"
#include "sim/sim_object.hh"

class HelloObject : public SimObject
{
  private:
    void processEvent();

    EventWrapper<HelloObject, &HelloObject::processEvent> event;

  public:
    HelloObject(HelloObjectParams *params);

    void startup();
};

#endif
