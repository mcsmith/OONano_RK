/**
**    UniversalAsynchronousReceiverTransmitter.cpp
**
**    Created:  2013-07-12
**    Author:   mcsmith
*/

#include "UniversalAsynchronousReceiverTransmitter.hpp"
#include <stdio.h>

using edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter;

/*
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate2400   = 832;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate4800   = 416;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate9600   = 207;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate14400  = 138;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate19200  = 103;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate28800  = 68;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate38400  = 51;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate57600  = 34;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate115200 = 16;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate230400 = 8;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate250000 = 4;
const uint16_t UniversalAsynchronousReceiverTransmitter::baudRate500000 = 2;
// static const uint16_t baudRate1000000;  //
*/
// Communication options
const uint16_t UniversalAsynchronousReceiverTransmitter::option1StopBit   = 0x0000;
const uint16_t UniversalAsynchronousReceiverTransmitter::option2StopBits  = 0x0008;
const uint16_t UniversalAsynchronousReceiverTransmitter::optionNoParity   = 0x0000;
const uint16_t UniversalAsynchronousReceiverTransmitter::optionEvenParity = 0x0020;
const uint16_t UniversalAsynchronousReceiverTransmitter::optionOddParity  = 0x0030;
const uint16_t UniversalAsynchronousReceiverTransmitter::option5DataBits  = 0x0000;
const uint16_t UniversalAsynchronousReceiverTransmitter::option6DataBits  = 0x0002;
const uint16_t UniversalAsynchronousReceiverTransmitter::option7DataBits  = 0x0004;
const uint16_t UniversalAsynchronousReceiverTransmitter::option8DataBits  = 0x0006;
const uint16_t UniversalAsynchronousReceiverTransmitter::option9DataBits  = 0x0406;
// Operating modes
const uint8_t  UniversalAsynchronousReceiverTransmitter::asynchronousNormalMode      = 0;
const uint8_t  UniversalAsynchronousReceiverTransmitter::asynchronousDoubleSpeedMode = 1;
const uint8_t  UniversalAsynchronousReceiverTransmitter::synchronousMasterMode       = 2;

UniversalAsynchronousReceiverTransmitter* UniversalAsynchronousReceiverTransmitter::consoleUart = (UniversalAsynchronousReceiverTransmitter*) 0;

UniversalAsynchronousReceiverTransmitter::UniversalAsynchronousReceiverTransmitter(const    uint32_t baudRate,
                                                                                   volatile uint8_t* baudRateRegisterHighByte,
                                                                                   volatile uint8_t* baudRateRegisterLowByte,
                                                                                   const    bool     console,
                                                                                   volatile uint8_t* controlAndStatusRegisterA,
                                                                                   volatile uint8_t* controlAndStatusRegisterB,
                                                                                   volatile uint8_t* controlAndStatusRegisterC,
                                                                                   volatile uint8_t* dataRegister,
                                                                                   const    uint8_t  operatingMode,
                                                                                   const    uint8_t  operatingModeBit,
                                                                                   const    uint16_t options,
                                                                                   const    uint8_t  receiveComplete,
                                                                                   const    uint8_t  receiveCompleteInterruptEnable,
                                                                                   volatile uint8_t* receiverDataDirectionRegister,
                                                                                   volatile uint8_t* receiverDataRegister,
                                                                                   const    uint8_t  receiverEnableBit,
                                                                                   const    uint8_t  receiverPin,
                                                                                   const    uint8_t  transmitComplete,
                                                                                   const    uint8_t  transmitCompleteInterruptEnable,
                                                                                   volatile uint8_t* transmitterDataDirectionRegister,
                                                                                   volatile uint8_t* transmitterDataRegister,
                                                                                   const    uint8_t  transmitterEnableBit,
                                                                                   const    uint8_t  transmitterPin):
   baudRateRegisterHighByte(baudRateRegisterHighByte),
   baudRateRegisterLowByte(baudRateRegisterLowByte),
   controlAndStatusRegisterA(controlAndStatusRegisterA),
   controlAndStatusRegisterB(controlAndStatusRegisterB),
   controlAndStatusRegisterC(controlAndStatusRegisterC),
   dataRegister(dataRegister),
   enableBitmap((1 << receiverEnableBit) | (1 << transmitterEnableBit)),
   receiveCompleteBitmap((1 << receiveComplete)),
   receiveCompleteInterruptEnableBitmap((1 << receiveCompleteInterruptEnable)),
   receiver(DataChannel(DataChannel::input,
                        receiverDataDirectionRegister,
                        receiverDataRegister,
                        receiverPin,
                        true)),
   transmitCompleteBitmap((1 << transmitComplete)),
   transmitCompleteInterruptEnableBitmap((1 << transmitCompleteInterruptEnable)),
   transmitter(DataChannel(DataChannel::output,
                           transmitterDataDirectionRegister,
                           transmitterDataRegister,
                           transmitterPin,
                           true))
   {
	const uint16_t ubrrValue = computeUartBaudRateRegisterValue(baudRate,
	                                                            operatingMode);

   *baudRateRegisterHighByte = ubrrValue >> 8;
   *baudRateRegisterLowByte = ubrrValue;

   const uint8_t operatingModeBitmap = operatingMode << operatingModeBit;

   if (operatingMode == synchronousMasterMode)
      {
      *controlAndStatusRegisterA &= ~operatingModeBitmap;
      }
   else
      {
      *controlAndStatusRegisterA |= operatingModeBitmap;
      }
   *controlAndStatusRegisterB &= (1 << receiveCompleteInterruptEnable) &
   	                           (1 << transmitCompleteInterruptEnable);
   if (options > 0xff)
      {
      *controlAndStatusRegisterB |= 0x04;
      }
   else
      {
      *controlAndStatusRegisterB &= 0xfb;
      }
   *controlAndStatusRegisterC = options;
   if (console)
      {
   	consoleUart = this;
   	/*
   	stdin = fdevopen(&putcWrapper,
                       &getcWrapper);
      stdout = fdevopen(&putcWrapper,
                        &getcWrapper);
      */
      }
   }

/**
**    Computes the UART baud rate register value given the requested baud rate
**    and operating mode of the UART.
**
**    See chapter 23 of the ATmega128RFA1 data sheet for UART details.
*/

uint16_t UniversalAsynchronousReceiverTransmitter::computeUartBaudRateRegisterValue(const uint32_t baudRate,
                                                                                    const uint8_t  operatingMode)
   {
	//    The floating point operation will be slow (and large??), but it's only
	//    done at setup.

	const float operatingModeMultiplier = operatingMode == asynchronousNormalMode      ? 16 :
		                                   operatingMode == asynchronousDoubleSpeedMode ?  8 : 2;

   return (uint16_t) (16000000 / (operatingModeMultiplier * baudRate) - 0.5);
   }
/*
int UniversalAsynchronousReceiverTransmitter::getcWrapper(FILE* file)
   {
   return consoleUart == 0 ? -1 : consoleUart->getc(file);
   }

int UniversalAsynchronousReceiverTransmitter::putcWrapper(char data,
                                                          FILE* file)
   {
	return consoleUart == 0 ? -1 : consoleUart->putc(data, file);
   }
*/
/**
**    Enables or disables the UART.
*/

void UniversalAsynchronousReceiverTransmitter::setEnable(const bool enable)
   {
   if (enable)
      {
      *controlAndStatusRegisterB |= enableBitmap;
      }
   else
      {
      *controlAndStatusRegisterB &= ~enableBitmap;
      }
   }
