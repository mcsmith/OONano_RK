/**
**    Declaration of the DataChannel class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#ifndef DataChannel_hpp
#define DataChannel_hpp

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
               class DataChannel;
               }
            }
         }
      }
   };

/**
**    A DataChannel is a path through which one bit of data may pass at any
**    moment.  More sophisticated messages are possible using a time series
**    of bits on the channel.  A DataChannel may use either normal (i.e. a
**    logical one means "on") or inverse logic.
*/

class edu::cmu::sv::OONano_RK::Hardware::DataChannel
   {
   public:

   // Direction
   static const uint8_t input;
   static const uint8_t output;

   DataChannel(const    uint8_t  dataDirection,
               volatile uint8_t* dataDirectionRegister,
               volatile uint8_t* dataRegister,
               const    bool     normalLogic,
               const    uint8_t  pin);
   bool isOn() const;
   void setOn(const bool on);

// bool get() const;
// void set(const bool on);
// void toggle();

   protected:

   const    uint8_t  dataDirection; // needed?
   volatile uint8_t* dataDirectionRegister;
   volatile uint8_t* dataRegister;
   const    bool     normalLogic;
   const    uint8_t  pin; // needed?
   const    uint8_t  shiftCount;  // Must be declared prior to pinBitmap to allow initialization list to work correctly.
   const    uint8_t  pinBitmap;
   };

#endif
