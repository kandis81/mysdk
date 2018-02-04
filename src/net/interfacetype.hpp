
#include <string>

#pragma once

namespace network
{
   class InterfaceType
   {
      public:
         virtual ~InterfaceType() = default;

      public:
         virtual const std::string& address_s()   const = 0;
         virtual const unsigned char* address_b() const = 0;

         virtual const std::string& netmask_s()   const = 0;
         virtual const unsigned char* netmask_b() const = 0;
   };
}
