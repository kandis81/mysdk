
#include <interface.hpp>
#include <timestamp.hpp>

#include <mutex>

#pragma once

namespace network
{
   class Interfaces
   {
      public:
         static const Interface::Map& interfaces();

      private:

         static struct Ifaces
         {
            library::TimeStamp mStamp;     // last updated
            Interface::Map     mContainer; // collected interfaces
            std::mutex         mMutex;     // mutex the calculation
         } mIfaces;

   };

}

