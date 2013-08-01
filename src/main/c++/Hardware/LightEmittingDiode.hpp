/**
**    Declaration of the LightEmittingDiode class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#ifndef LightEmittingDiode_hpp
#define LightEmittingDiode_hpp

#include "DataChannel.hpp"

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
               class LightEmittingDiode;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Hardware::LightEmittingDiode
   {
   public:

   LightEmittingDiode(volatile uint8_t* dataDirectionRegister,
                      volatile uint8_t* dataRegister,
                      const    bool     normalLogic,
                      const    uint8_t  pin);
   bool isOn() const;
   void setOn(const bool on);

   private:

   DataChannel dataChannel;
   };

#endif
