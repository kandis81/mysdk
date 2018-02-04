
#include <net/interfacetype.hpp>

#pragma once

namespace network
{
   class IPV6 : public InterfaceType
   {
      public:
         static constexpr unsigned char CountOfLevels = 16;
         using Binary = unsigned char[ CountOfLevels ];
         using Key    = Binary;

      public:
         static const std::string& toAddress( std::string& aOut, const Binary aAddress )
         {
            #define SEPARATE aOut += ":"
            char hex[3];

            for ( int i= 0; i < CountOfLevels; ++i )
            {
               if ( i )
                  SEPARATE;

               if ( aAddress[i] )
               {
                  sprintf( hex, "%0x", aAddress[i] );
                  aOut += hex;

                  ++i;
                  SEPARATE;

                  sprintf( hex, "%0x", aAddress[i] );
                  aOut += hex;
               }
               else
               {
                  ++i;
                  SEPARATE;
               }
            }

            #undef SEPARATE
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
         IPV6( Binary aAddress, Binary aNetmask )
            { memcpy( mAddress, aAddress, CountOfLevels);
              memcpy( mNetmask, aNetmask, CountOfLevels); }

      public:
         virtual const std::string&   address_s() const { return address.empty() ? toAddress( address, mAddress ) : address; }
         virtual const unsigned char* address_b() const { return mAddress; }

         virtual const std::string&   netmask_s() const { return netmask.empty() ? toAddress( netmask, mNetmask ) : netmask; }
         virtual const unsigned char* netmask_b() const { return mNetmask; }

      public:
         inline bool operator==(const IPV6& x) const
         {
            return equal( x.mAddress, mAddress )
                && equal( x.mNetmask, mNetmask );
         }

         inline bool operator!=(const IPV6& x) const
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

