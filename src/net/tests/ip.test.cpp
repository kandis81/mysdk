#include <interfaces.hpp>
#include <interface.hpp>

#define BOOST_TEST_MODULE NetTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( Task1 )
{
   bool hasLocalInterface = false;
   network::IPV4::Binary localIpV4Address = { 127,   0,   0,   1 };
   network::IPV4::Binary localIpV4Netmask = { 127, 255, 255, 255 };
   network::IPV4         localIpV4Type( localIpV4Address, localIpV4Netmask );
   network::IPV6::Binary localIpV6Address = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
   network::IPV6::Binary localIpV6Netmask = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
   network::IPV6         localIpV6Type( localIpV6Address, localIpV6Netmask );
   network::Interface local( "lo" , localIpV4Type, localIpV6Type );

   const network::Interface::Map& interfaces = network::Interfaces::interfaces();

   for ( network::Interface::Map::const_iterator it = interfaces.begin(); it != interfaces.end(); ++it )
   {
      if ( local != *( it->second ) )
         continue;

      hasLocalInterface = true;
      break;
   }

   BOOST_CHECK( hasLocalInterface );
}

