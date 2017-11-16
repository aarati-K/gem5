#include "hpca_tutorial/hello_object.hh"

#include "debug/Hello.hh"

HelloObject::HelloObject(HelloObjectParams *params) :
    SimObject(params), event(*this)
{
    DPRINTF(Hello, "hello world from sim object %d\n", 10);
}

HelloObject *
HelloObjectParams::create()
{
    return new HelloObject(this);
}

void HelloObject::processEvent()
{
    DPRINTF(Hello, "Hello world! Processing the event\n");
}

void HelloObject::startup()
{
    schedule(event, 100);
}
