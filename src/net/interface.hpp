
#include <net/ipv4.hpp>
#include <net/ipv6.hpp>

#include <string>
#include <map>
#include <memory>

#pragma once

namespace network
{

   class Interface
   {
      public:
         using Name = std::string;
         using Map  = std::map<Name, std::shared_ptr<Interface>>;

      public:
         Interface( const Name& aName, const IPV4& aIpV4, const IPV6& aIpV6 )
            : mName( aName )
            , mIpV4( aIpV4 )
            , mIpV6( aIpV6 )
         {}

      public:
         inline bool operator==(const Interface& x) const
         {
            return x.mName == mName
                && x.mIpV4 == mIpV4
                && x.mIpV6 == mIpV6;
         }

         inline bool operator!=(const Interface& x) const
         {
            return x.mName != mName
                || x.mIpV4 != mIpV4
                || x.mIpV6 != mIpV6;
         }

      private:
         const Name mName;
         const IPV4 mIpV4;
         const IPV6 mIpV6;
   };
}

