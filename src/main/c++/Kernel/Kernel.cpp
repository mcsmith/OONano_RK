/**
**    Definition of the Kernel class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#include <stdio.h>
#include "Kernel.hpp"

using edu::cmu::sv::OONano_RK::Kernel::Kernel;

const int8_t Kernel::error = -1;
const int8_t Kernel::ok    = 1;

Kernel::Kernel():  signalReservationBitmap(0)
   {
   while (1)
      printf("Kernel::<init>\n");
   }

int8_t Kernel::acquireSignalReservation()
   {
   uint8_t signal = 0;

   for (signal = 0; signal < 32; signal++)
      {
      const uint32_t signalBitmask = createSignalBitmask(signal);

      if (!(signalReservationBitmap & signalBitmask))
         {
         signalReservationBitmap |= signalBitmask;
         return signal;
         }
      }
   return error;
   }

inline uint32_t Kernel::createSignalBitmask(uint8_t signal)
   {
   return 1 << signal;
   }

int8_t Kernel::releaseSignalReservation(uint8_t signal)
   {
   const uint32_t signalBitmask = createSignalBitmask(signal);

   if ((signalReservationBitmap & signalBitmask) == 0)
      {
      return error;
      }
   // TODO:  More stuff goes here...
   return ok;
   }
