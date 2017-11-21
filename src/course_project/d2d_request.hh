#ifndef __COURSE_PROJECT_D2D_REQUEST_HH__
#define __COURSE_PROJECT_D2D_REQUEST_HH__

#include "course_project/d2d_packet.hh"
#include "mem/request.hh"

class D2DRequest;
typedef D2DRequest* D2DRequestPtr;

class D2DRequest : public Request
{
  private:
    CacheWay _wayNo;

  public:
    CacheWay getWayNo() {return _wayNo;}
    void setWayNo(CacheWay wayNo) {assert(wayNo > 0); _wayNo = wayNo;}

    virtual ~D2DRequest() {}
};

#endif // __COURSE_PROJECT_D2D_REQUEST_HH__