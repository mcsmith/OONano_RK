/**
**    Definition of the LightEmittingDiode class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#include "LightEmittingDiode.hpp"

using edu::cmu::sv::OONano_RK::Hardware::LightEmittingDiode;

LightEmittingDiode::LightEmittingDiode(volatile uint8_t* dataDirectionRegister,
                                       volatile uint8_t* dataRegister,
                                       const    bool     normalLogic,
                                       const    uint8_t  pin):  dataChannel(DataChannel::output,
                                                                            dataDirectionRegister,
                                                                            dataRegister,
                                                                            normalLogic,
                                                                            pin)
   {
	dataChannel.setOn(false);
   }

bool LightEmittingDiode::isOn() const
   {
   return dataChannel.isOn();
   }

void LightEmittingDiode::setOn(const bool on)
   {
   dataChannel.setOn(on);
   }
