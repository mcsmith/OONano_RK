/**
**    Definition of the TestSuite class.
**
**    Created: 2013-06-04
**    Author:  mcsmith
*/

//#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TestSuite.hpp"

using edu::cmu::sv::OONano_RK::Application::TestSuite;
using edu::cmu::sv::OONano_RK::Hardware::FireFly3;

TestSuite::TestSuite(LightEmittingDiode* blueLed,
                     LightEmittingDiode* greenLed,
                     LightEmittingDiode* orangeLed,
                     LightEmittingDiode* redLed):  blueLed(blueLed),
                                                   greenLed(greenLed),
                                                   orangeLed(orangeLed),
                                                   redLed(redLed)
   {
   }

void TestSuite::delay(const uint8_t milliseconds)
   {
   _delay_ms(milliseconds);
   }

void TestSuite::testLeds()
   {
   redLed->setOn(true);
   delay(100);
   greenLed->setOn(true);
   delay(100);
   orangeLed->setOn(true);
   delay(100);
   blueLed->setOn(true);
   delay(100);
   redLed->setOn(false);
   delay(100);
   greenLed->setOn(false);
   delay(100);
   orangeLed->setOn(false);
   delay(100);
   blueLed->setOn(false);
   }

int main()
   {
   FireFly3  fireFly3;
   TestSuite testSuite(fireFly3.getLightEmittingDiode(FireFly3::blue),
                       fireFly3.getLightEmittingDiode(FireFly3::green),
                       fireFly3.getLightEmittingDiode(FireFly3::orange),
                       fireFly3.getLightEmittingDiode(FireFly3::red));

   testSuite.testLeds();
   }
