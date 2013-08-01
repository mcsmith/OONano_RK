/**
**    Declaration of the Kernel class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#ifndef Kernel_hpp
#define Kernel_hpp

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
               class Kernel;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Kernel::Kernel
   {
   public:

   static const int8_t error;
   static const int8_t ok;

   protected:

   Kernel();
   void initializePorts();

   private:

   uint32_t signalReservationBitmap;   /// Bit map of CPU signal reservations (0 = available, 1 = reserved)

   int8_t   acquireSignalReservation();                // was nrk_signal_create()
   uint32_t createSignalBitmask(uint8_t signal);       // was SIG(x)
   int8_t   releaseSignalReservation(uint8_t signal);  // was nrk_signal_delete()
   };

#endif
