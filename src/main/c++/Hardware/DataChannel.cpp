/**
**    Definition of the DataChannel class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#include "DataChannel.hpp"

using edu::cmu::sv::OONano_RK::Hardware::DataChannel;

const uint8_t DataChannel::input  = 0;
const uint8_t DataChannel::output = 1;

DataChannel::DataChannel(const    uint8_t  dataDirection,
                         volatile uint8_t* dataDirectionRegister,
                         volatile uint8_t* dataRegister,
                         const    bool     normalLogic,
                         const    uint8_t  pin):  dataDirection(dataDirection & output), // data direction should never exceed 1
                                                  dataDirectionRegister(dataDirectionRegister),
                                                  dataRegister(dataRegister),
                                                  normalLogic(normalLogic),
                                                  pin(pin),
                                                  shiftCount(pin & 0x07), // pin should never exceed 7
                                                  pinBitmap(1 << shiftCount)
   {
   if (dataDirection == output)
      {
      *dataDirectionRegister |= pinBitmap;  // configure for output
      }
   }

bool DataChannel::isOn() const
   {
   return normalLogic ^ !((*dataRegister & pinBitmap) >> shiftCount);
   }

void DataChannel::setOn(const bool on)
   {
   //    Set the pin high if exactly one of the following is true:
   //    - the channel uses normal logic (e.g. microcontroller's pin is the LED's voltage source)
   //    - the requested state is off

	if (normalLogic ^ !on)
      {
      *dataRegister |= pinBitmap;
      }
   else
      {
      *dataRegister &= ~pinBitmap;
      }
   }
/*
bool DataChannel::get() const
   {
   return (*dataRegister & pinBitmap) >> shiftCount;
   }

void DataChannel::set(const bool on)
   {
   if (on)
   	{
   	*dataRegister
   	}
   }
*/
