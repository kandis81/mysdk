
#include <ctime>

#pragma once

namespace library
{
   class TimeStamp
   {
      public:
         bool newer( std::time_t sec );
   };
}

