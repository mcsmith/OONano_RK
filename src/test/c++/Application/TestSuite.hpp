/**
**    Declaration of the TestSuite class.
**
**    Created: 2013-06-04
**    Author:  mcsmith
*/

#ifndef TestSuite_hpp
#define TestSuite_hpp

#include "../../../main/c++/Hardware/FireFly3.hpp"
#include "../../../main/c++/Hardware/LightEmittingDiode.hpp"
#include "../../../main/c++/Kernel/Kernel.hpp"

namespace edu
   {
   namespace cmu
      {
      namespace sv
         {
         namespace OONano_RK
            {
            namespace Application
               {
               class TestSuite;
               }
            }
         }
      }
   };

using edu::cmu::sv::OONano_RK::Hardware::FireFly3;
using edu::cmu::sv::OONano_RK::Hardware::LightEmittingDiode;

class edu::cmu::sv::OONano_RK::Application::TestSuite:  public Kernel::Kernel
   {
   public:

   TestSuite(LightEmittingDiode* blueLed,
             LightEmittingDiode* greenLed,
             LightEmittingDiode* orangeLed,
             LightEmittingDiode* redLed);
   void testLeds();

   private:

   LightEmittingDiode* blueLed;
   LightEmittingDiode* greenLed;
   LightEmittingDiode* orangeLed;
   LightEmittingDiode* redLed;

   void delay(const uint8_t milliseconds);
   };

#endif
