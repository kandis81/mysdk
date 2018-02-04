
#include <net/interfacetype.hpp>

#include <cstring>

#pragma once

namespace network
{
   class IPV4 : public InterfaceType
   {
      public:
         static constexpr unsigned char CountOfLevels = 4;
         using Binary = unsigned char[ CountOfLevels ];
         using Key    = Binary;

      public:
         static const std::string& toAddress( std::string& aOut, const Binary aAddress )
         {
            aOut =  aAddress[0] + '.'
                 +  aAddress[1] + '.'
                 +  aAddress[2] + '.'
                 +  aAddress[3];
            return aOut;
         }

         static bool equal( const Binary x, const Binary y )
         {
            for ( int i = 0; i < CountOfLevels; ++i )
               if ( x[i] != y[i] )
                  return false;

            return true;
         }

      public:
         IPV4( Binary aAddress, Binary aNetmask )
            { memcpy( mAddress, aAddress, CountOfLevels);
              memcpy( mNetmask, aNetmask, CountOfLevels); }

      public:
         virtual const std::string&   address_s() const { return address.empty() ? toAddress( address, mAddress ) : address; }
         virtual const unsigned char* address_b() const { return mAddress; }

         virtual const std::string&   netmask_s() const { return netmask.empty() ? toAddress( netmask, mNetmask ) : netmask; }
         virtual const unsigned char* netmask_b() const { return mNetmask; }

      public:
         inline bool operator==(const IPV4& x) const
         {
            return equal( x.mAddress, mAddress )
                && equal( x.mNetmask, mNetmask );
         }

         inline bool operator!=(const IPV4& x) const
         {
            return !equal( x.mAddress, mAddress )
                || !equal( x.mNetmask, mNetmask );
         }

      private:
         Binary mAddress;
         Binary mNetmask;

         mutable std::string address;
         mutable std::string netmask;
   };
}

