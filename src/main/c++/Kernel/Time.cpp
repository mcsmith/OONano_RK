/**
**    Definition of the Time class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#include "Time.hpp"

using edu::cmu::sv::OONano_RK::Kernel::Time;

Time::Time(uint32_t seconds,
           uint32_t nanoseconds):  nanoseconds(nanoseconds),
                                   seconds(seconds)
   {
   }
