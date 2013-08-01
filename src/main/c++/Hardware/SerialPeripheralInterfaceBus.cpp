/**
**    SerialPeripheralInterfaceBus.cpp
**
**    Created:  2013-07-12
**    Author:   mcsmith
*/

#include "SerialPeripheralInterfaceBus.hpp"

using edu::cmu::sv::OONano_RK::Hardware::SerialPeripheralInterfaceBus;

SerialPeripheralInterfaceBus::SerialPeripheralInterfaceBus(volatile uint8_t* inputDataDirectionRegister,
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
                                                           const    bool     slaveSelectPullup):  input(DataChannel(DataChannel::input,
                                                                                                                    inputDataDirectionRegister,
                                                                                                                    inputDataRegister,
                                                                                                                    inputPin,
                                                                                                                    true)),
                                                                                                  output(DataChannel(DataChannel::output,
                                                                                                                     outputDataDirectionRegister,
                                                                                                                     outputDataRegister,
                                                                                                                     outputPin,
                                                                                                                     true)),
                                                                                                  serialClock(DataChannel(DataChannel::output,
                                                                                                                          serialClockDataDirectionRegister,
                                                                                                                          serialClockDataRegister,
                                                                                                                          serialClockPin,
                                                                                                                          true)),
                                                                                                  slaveSelect(DataChannel(slaveSelectPullup ? DataChannel::output : DataChannel::input,
                                                                                                                          slaveSelectDataDirectionRegister,
                                                                                                                          slaveSelectDataRegister,
                                                                                                                          slaveSelectPin,
                                                                                                                          true))
   {
   }
