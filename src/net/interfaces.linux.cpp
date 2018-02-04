
#include <net/interfaces.hpp>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace network;

const Interface::Map& Interfaces::interfaces()
{
   // modify of list is saved, but the shared pointer saves the iterations
   std::lock_guard<std::mutex> lock( mIfaces.mMutex );

   // update of this list is necessary after 60 seconds
   if ( mIfaces.mStamp.newer( 60 ) )
      return mIfaces.mContainer;

   // clear the the container (error is signed so, that it has nto elements)
   mIfaces.mContainer.clear();

   // calculate interfaces
   struct ifaddrs *ifaddr;
//   int family, s;
//   char host[ NI_MAXHOST ];

   if ( getifaddrs( &ifaddr ) == -1 )
   {
      return mIfaces.mContainer;
   }

   for ( struct ifaddrs* ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next )
   {
      const char* name = ifa->ifa_name;
      (void) name;

//      std::shared_ptr<Interface> iface( new Interface( ifa->ifa_name ) );
//      mIfaces.mContainer[ iface.name() ] = iface;
   }

   freeifaddrs(ifaddr);

   return mIfaces.mContainer;
}

