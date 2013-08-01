/**
**    Declaration of the Time class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#ifndef Time_hpp
#define Time_hpp

#include <stdint.h>

namespace edu
   {
   namespace cmu
      {
      namespace sv
         {
         namespace OONano_RK
            {
            namespace Kernel
               {
               class Time;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Kernel::Time
   {
   public:

   static const uint32_t nanosecondsPerMicrosecond = 1000;
   static const uint32_t nanosecondsPerMillisecond = 1000000;
   static const uint32_t nanosecondsPerSecond      = 1000000000;

   Time(uint32_t seconds,
        uint32_t nanoseconds);

   private:

   uint32_t nanoseconds;
   uint32_t seconds;
   };

#endif
