/**
**    UniversalAsynchronousReceiverTransmitter.hpp
**
**    Created:  2013-07-12
**    Author:   mcsmith
*/

#ifndef UniversalAsynchronousReceiverTransmitter_hpp
#define UniversalAsynchronousReceiverTransmitter_hpp

#include <stdio.h>
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
               class UniversalAsynchronousReceiverTransmitter;
               }
            }
         }
      }
   };

class edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter
   {
   public:
/*
   static const uint16_t baudRate2400;     // 832
   static const uint16_t baudRate4800;     // 416
   static const uint16_t baudRate9600;     // 207
   static const uint16_t baudRate14400;    // 138
   static const uint16_t baudRate19200;    // 103
   static const uint16_t baudRate28800;    // 68
   static const uint16_t baudRate38400;    // 51
   static const uint16_t baudRate57600;    // 34
   static const uint16_t baudRate115200;   // 16
   static const uint16_t baudRate230400;   // 8
   static const uint16_t baudRate250000;   // 4
   static const uint16_t baudRate500000;   // 2
// static const uint16_t baudRate1000000;  // 
*/
   // Communication options
   static const uint16_t option1StopBit;   // 0x0000
   static const uint16_t option2StopBits;  // 0x0008
   static const uint16_t optionNoParity;   // 0x0000
   static const uint16_t optionEvenParity; // 0x0020
   static const uint16_t optionOddParity;  // 0x0030
   static const uint16_t option5DataBits;  // 0x0000
   static const uint16_t option6DataBits;  // 0x0002
   static const uint16_t option7DataBits;  // 0x0004
   static const uint16_t option8DataBits;  // 0x0006
   static const uint16_t option9DataBits;  // 0x0406
   // Operating modes
   static const uint8_t asynchronousNormalMode;
   static const uint8_t asynchronousDoubleSpeedMode;
   static const uint8_t synchronousMasterMode;
   static UniversalAsynchronousReceiverTransmitter* consoleUart;

   UniversalAsynchronousReceiverTransmitter(const    uint32_t baudRate,
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
                                            const    uint8_t  transmitterPin);

   private:

   volatile uint8_t*    baudRateRegisterHighByte;
   volatile uint8_t*    baudRateRegisterLowByte;
   volatile uint8_t*    controlAndStatusRegisterA;
   volatile uint8_t*    controlAndStatusRegisterB;
   volatile uint8_t*    controlAndStatusRegisterC;
   volatile uint8_t*    dataRegister;
   const    uint8_t     enableBitmap;
   const    uint8_t     receiveCompleteBitmap; // 1 << RXC0 et al
   const    uint8_t     receiveCompleteInterruptEnableBitmap; // 1 << RXCIE0 et al
            DataChannel receiver;
   const    uint8_t     transmitCompleteBitmap; // 1 << TXC et al
   const    uint8_t     transmitCompleteInterruptEnableBitmap; // 1 << TXCIE0 et al
            DataChannel transmitter;

   static uint16_t computeUartBaudRateRegisterValue(const uint32_t baudRate,
                                                    const uint8_t  operatingMode);
   inline void enableReceiveCompleteInterrupt(const bool enable);
   inline void enableTransmitCompleteInterrupt(const bool enable);
   inline uint8_t receive();
   inline void setReceiveComplete(const bool complete);
   inline void setTransmitComplete(const bool complete);
   inline void transmit(const uint8_t data);
   inline uint8_t waitAndReceive();
   inline void waitAndTransmit(const uint8_t data);
   inline void waitForReceive();
   inline void waitForTransmit();
/* int getc(FILE* file);
   static int getcWrapper(FILE* file);
   int putc(char data, FILE* file);
   static int putcWrapper(char data, FILE* file); */
   void setEnable(const bool enable);
   };

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::enableReceiveCompleteInterrupt(const bool enable)
   {
	if (enable)
	   {
	   *controlAndStatusRegisterB |= receiveCompleteInterruptEnableBitmap;
	   }
	else
	   {
	   *controlAndStatusRegisterB &= ~receiveCompleteInterruptEnableBitmap;
	   }
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::enableTransmitCompleteInterrupt(const bool enable)
   {
	if (enable)
	   {
	   *controlAndStatusRegisterB |= transmitCompleteInterruptEnableBitmap;
	   }
	else
	   {
	   *controlAndStatusRegisterB &= ~transmitCompleteInterruptEnableBitmap;
	   }
   }

uint8_t edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::receive()
   {
   return *dataRegister;
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::setReceiveComplete(const bool complete)
   {
   if (complete)
      {
   	*controlAndStatusRegisterA &= ~receiveCompleteBitmap;
      }
   else
      {
      *controlAndStatusRegisterA |= receiveCompleteBitmap;
      }
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::setTransmitComplete(const bool complete)
   {
   if (complete)
      {
   	*controlAndStatusRegisterA &= ~transmitCompleteBitmap;
      }
   else
      {
      *controlAndStatusRegisterA |= transmitCompleteBitmap;
      }
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::transmit(const uint8_t data)
   {
   *dataRegister = data;
   }

uint8_t edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::waitAndReceive()
   {
   waitForReceive();
   return receive();
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::waitAndTransmit(const uint8_t data)
   {
   waitForTransmit();
   transmit(data);
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::waitForReceive()
   {
   while (!(*controlAndStatusRegisterA & receiveCompleteBitmap))
      {
      // Keep calm and carry on.
   	}
   setReceiveComplete(true);
   }

void edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter::waitForTransmit()
   {
   while (!(*controlAndStatusRegisterA & transmitCompleteBitmap))
      {
      // Keep calm and carry on.
   	}
   setTransmitComplete(true);
// clearTransmitInterrupt();
   }

#endif

// #define CLEAR_UART0_TX_INT()        do { UCSR0A &= ~BM(UDRE0); } while (0)
// #define DISABLE_UART0_TX_INT()      do { UCSR0B &= ~BM(UDRIE0); } while (0)
// #define ENABLE_UART0_TX_INT()       do { UCSR0B |= BM(UDRIE0); } while (0)
// #define SET_UART0_TX_INT()          do { UCSR0A |= BM(UDRE0); } while (0)
// #define UART0_WAIT()                do { while (!(UCSR0A & BM(UDRE0))); CLEAR_UART0_TX_INT(); } while (0)
// #define UART0_WAIT_AND_SEND(x)      do { UART0_WAIT(); UART0_SEND(x); } while (0)

// setReceiveComplete(true)			// #define CLEAR_UART0_RX_INT()        do { UCSR0A &= ~BM(RXC0); } while (0)
// enableReceiveCompleteInterrupt   // #define DISABLE_UART0_RX_INT()      do { UCSR0B &= ~BM(RXCIE0); } while (0)
                                    // #define ENABLE_UART0_RX_INT()       do { UCSR0B |= BM(RXCIE0); } while (0)
// receive()               			// #define UART0_RECEIVE(x)            do { (x) = UDR0; } while (0)
// transmit()              			// #define UART0_SEND(x)               do { UDR0 = (x); } while (0)
// waitAndReceive()        			// #define UART0_WAIT_AND_RECEIVE(x)   do { /*UDR1 = 0;*/ UART0_WAIT_RX(); UART0_RECEIVE(x); } while (0)
// waitForReceive()        			// #define UART0_WAIT_RX()             do { while (!(UCSR0A & BM(RXC0))); CLEAR_UART0_RX_INT(); } while (0)
