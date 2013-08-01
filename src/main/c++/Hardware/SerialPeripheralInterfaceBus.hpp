/**
**    SerialPeripheralInterfaceBus.hpp
**
**    Created:  2013-07-12
**    Author:   mcsmith
*/

#ifndef SerialPeripheralInterfaceBus_hpp
#define SerialPeripheralInterfaceBus_hpp

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
               class SerialPeripheralInterfaceBus;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Hardware::SerialPeripheralInterfaceBus
   {
   public:

   SerialPeripheralInterfaceBus(volatile uint8_t* inputDataDirectionRegister,
                                volatile uint8_t* inputDataRegister,
                                const    uint8_t  inputPin,
                                volatile uint8_t* outputDataDirectionRegister,
                                volatile uint8_t* outputDataRegister,
                                const    uint8_t  outputPin,
                                volatile uint8_t* serialClockDataDirectionRegister,
                                volatile uint8_t* serialClockDataRegister,
                                const    uint8_t  serialClockPin,
                                volatile uint8_t* slaveSelectDataDirectionRegister,
                                volatile uint8_t* slaveSelectDataRegister,
                                const    uint8_t  slaveSelectPin,
                                const    bool     slaveSelectPullup);

   private:

   DataChannel input;
   DataChannel output;
   DataChannel serialClock;
   DataChannel slaveSelect;
   };

#endif
