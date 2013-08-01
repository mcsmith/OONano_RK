/**
**    Declaration of the FireFly3 class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#ifndef FireFly3_hpp
#define FireFly3_hpp

#include "Atmega128rfa1.hpp"
#include "LightEmittingDiode.hpp"
#include "SerialPeripheralInterfaceBus.hpp"
#include "UniversalAsynchronousReceiverTransmitter.hpp"

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
               class FireFly3;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Hardware::FireFly3//:  public CircuitBoard
   {
   public:

	// LED colors

   static const uint8_t red;
   static const uint8_t green;
   static const uint8_t orange;
   static const uint8_t blue;

   FireFly3();
// static FireFly3& getInstance();
   LightEmittingDiode* getLightEmittingDiode(const uint8_t color);

   private:

// static FireFly3           fireFly3;
          Atmega128rfa1                            atmega128rfa1;
          LightEmittingDiode                       led1; // red
          LightEmittingDiode                       led2; // green
          LightEmittingDiode                       led3; // orange
          LightEmittingDiode                       led4; // blue
          SerialPeripheralInterfaceBus             spiBus;
          UniversalAsynchronousReceiverTransmitter uart0;
       // UniversalAsynchronousReceiverTransmitter uart1;

   // Port A pins

   static const uint8_t       voltageRegulatorEN = 5; // VREG_EN // TODO:  What does EN stand for?
   static const uint8_t       resetN             = 6; // RESET_N // TODO:  What does N stand for?
   };

#endif
