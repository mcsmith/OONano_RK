/**
**    Definition of the AtMega128Rfa1 class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#include <avr/io.h>
#include "Atmega128rfa1.hpp"

using edu::cmu::sv::OONano_RK::Hardware::Atmega128rfa1;

const uint8_t Atmega128rfa1::spiMasterOutSlaveIn = 2;
const uint8_t Atmega128rfa1::spiSerialClock      = 1;
const uint8_t Atmega128rfa1::spiSlaveSelect      = 0;

Atmega128rfa1::Atmega128rfa1():  Microcontroller()
   {
   PORTD = 0; // Set all pins low on port D
   }
