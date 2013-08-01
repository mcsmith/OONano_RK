/**
**    Declaration of the Microcontroller class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#ifndef Microcontroller_hpp
#define Microcontroller_hpp

#include <stdint.h>

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
               class Microcontroller;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Hardware::Microcontroller
   {
   public:

   Microcontroller();
/*
   private:

   uint32_t createBitmask(uint8_t bitPosition);
*/
   };

#endif
