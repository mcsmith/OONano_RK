/**
**    Declaration of the Atmega128rfa1 class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#ifndef Atmega128rfa1_hpp
#define Atmega128rfa1_hpp

#include <avr/io.h>
#include "Microcontroller.hpp"

namespace edu
   {
   namespace cmu
      {
      namespace sv
         {
         namespace OONano_RK
            {
            namespace Hardware
               {
               class Atmega128rfa1;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Hardware::Atmega128rfa1:  public Microcontroller
   {
   public:

   static const uint8_t spiMasterOutSlaveIn;
   static const uint8_t spiSerialClock;
   static const uint8_t spiSlaveSelect;

   Atmega128rfa1();
   };

#endif
