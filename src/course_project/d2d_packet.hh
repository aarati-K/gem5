/**
* @file
* Declaration of the D2DPacket class.
*/

#ifndef __SRC_COURSE_PROJECT_D2D_PACKET_HH__
#define __SRC_COURSE_PROJECT_D2D_PACKET_HH__

#include <list>

#include "mem/packet.hh"

class D2DPacket;
typedef D2DPacket* D2DPacketPtr;
typedef std::list<D2DPacketPtr> D2DPacketList;

/**
* Assigning 8 bits for way number
* Cache associativity is rarely more than 32
* A 32-way associative cache will need 5+1 bits
*/
typedef uint8_t CacheWay;


class D2DPacket : public Packet {
  public:
    CacheWay getCacheWay();

    /**
    * Redeclaring all constructors from the base class
    */

    D2DPacket(const RequestPtr _req, MemCmd _cmd)
        :  Packet(_req, _cmd)
    {}

    D2DPacket(const RequestPtr _req, MemCmd _cmd, int _blkSize)
        :  Packet(_req, _cmd, _blkSize)
    {}

    D2DPacket(const D2DPacketPtr pkt, bool clear_flags, bool alloc_data)
        :  Packet(pkt, clear_flags, alloc_data)
    {}

    /**
    * Constructor-like methods
    */
    static D2DPacketPtr
    createRead(const RequestPtr req)
    {
        return new D2DPacket(req, makeReadCmd(req));
    }

    static D2DPacketPtr
    createWrite(const RequestPtr req)
    {
        return new D2DPacket(req, makeWriteCmd(req));
    }

  private:

  protected:

};

CacheWay D2DPacket::getCacheWay()
{
    D2DRequestPtr d2d_req = static_cast<D2DRequestPtr>(req);
    return d2d_req->getWayNo();
}

#endif // __SRC_COURSE_PROJECT_D2D_PACKET_HH__
