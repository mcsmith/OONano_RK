/**
**    Definition of the FireFly3 class.
**
**    Created: 2013-06-05
**    Author:  mcsmith
*/

#include <avr/interrupt.h>
#include <util/delay.h>
#include "FireFly3.hpp"

using edu::cmu::sv::OONano_RK::Hardware::FireFly3;
using edu::cmu::sv::OONano_RK::Hardware::LightEmittingDiode;
using edu::cmu::sv::OONano_RK::Hardware::UniversalAsynchronousReceiverTransmitter;

const uint8_t FireFly3::red    = 1;
const uint8_t FireFly3::green  = 2;
const uint8_t FireFly3::orange = 3;
const uint8_t FireFly3::blue   = 4;
/*
void debugByBlinkingx(const uint16_t value)
   {
   uint32_t count = value * 2;

   DDRD |= (1 << DDD7);
   while (count--)
      {
      PORTD ^= ~(1 << DDD7);
      _delay_ms(500);
      }
   }
*/
void delay(const uint8_t milliseconds)
   {
   _delay_ms(milliseconds);
   }

FireFly3::FireFly3():
   atmega128rfa1(Atmega128rfa1()),
   led1(LightEmittingDiode(&DDRD, &PORTD, false, PD4)),
   led2(LightEmittingDiode(&DDRD, &PORTD, false, PD5)),
   led3(LightEmittingDiode(&DDRD, &PORTD, false, PD6)),
   led4(LightEmittingDiode(&DDRD, &PORTD, false, PD7)),
   spiBus(SerialPeripheralInterfaceBus(&DDRB, &PORTB, PB3, &DDRB, &PORTB, PB2, &DDRB, &PORTB, PB1, &DDRB, &PORTB, PB0, false)),
   uart0(UniversalAsynchronousReceiverTransmitter(115200, &UBRR0H, &UBRR0L, true, &UCSR0A, &UCSR0B, &UCSR0C, &UDR0,
                                                  UniversalAsynchronousReceiverTransmitter::asynchronousDoubleSpeedMode, U2X0,
                                                  UniversalAsynchronousReceiverTransmitter::optionNoParity | UniversalAsynchronousReceiverTransmitter::option8DataBits | UniversalAsynchronousReceiverTransmitter::option1StopBit,
                                                  RXC0, RXCIE0, &DDRE, &PORTE, RXEN0, PE0, TXC0, TXCIE0, &DDRE, &PORTE, TXEN0, PE1)) //,
// uart1(UniversalAsynchronousReceiverTransmitter(&DDRD, &PORTD, PD2, &DDRD, &PORTD, PD3))
   {
   led1.setOn(true);
   delay(100);
   led2.setOn(true);
   delay(100);
   led3.setOn(true);
   delay(100);
   led4.setOn(true);
   delay(100);
   led1.setOn(false);
   delay(100);
   led2.setOn(false);
   delay(100);
   led3.setOn(false);
   delay(100);
   led4.setOn(false);
   }

/**
**    Gets a reference to the FireFly3 singleton.
*/
/*
FireFly3& FireFly3::getInstance()
	{
	return fireFly3;
	}
*/

/**
**    Get a reference to a LightEmittingDiode object based on its color.
*/

LightEmittingDiode* FireFly3::getLightEmittingDiode(const uint8_t color)
   {
   return color == red    ? &led1 :
          color == green  ? &led2 :
          color == orange ? &led3 : &led4;
   }
/*
void FireFly3::initializeUart(const uint16_t baudRate)
   {
// initializeUart0(baudRate);
   }

  nrk_led_clr (0);
  nrk_led_clr (1);
  nrk_led_clr (2);
  nrk_led_clr (3);

int8_t nrk_gpio_set(uint8_t pin)
{
        if (pin == NRK_INVALID_PIN_VAL) return -1;
        switch (pin & 0x07) {
                case NRK_PORTA:
                        PORTA |= BM((pin & 0xF8) >> 3); break;
                case NRK_PORTB:
                        PORTB |= BM((pin & 0xF8) >> 3); break;
                case NRK_PORTC:
                        PORTC |= BM((pin & 0xF8) >> 3); break;
                case NRK_PORTD:
                        PORTD |= BM((pin & 0xF8) >> 3); break;
                case NRK_PORTE:
                        PORTE |= BM((pin & 0xF8) >> 3); break;
                case NRK_PORTF:
                        PORTF |= BM((pin & 0xF8) >> 3); break;
                default: return -1;
        }
        return 1;
}

int8_t nrk_gpio_clr(uint8_t pin)
{
        if (pin == NRK_INVALID_PIN_VAL) return -1;
        switch (pin & 0x07) {
                case NRK_PORTA:
                        do { PORTA &= ~BM((pin & 0xF8) >> 3); } while(0); break;
                case NRK_PORTB:
                        do { PORTB &= ~BM((pin & 0xF8) >> 3); } while(0); break;
                case NRK_PORTC:
                        do { PORTC &= ~BM((pin & 0xF8) >> 3); } while(0); break;
                case NRK_PORTD:
                        do { PORTD &= ~BM((pin & 0xF8) >> 3); } while(0); break;
                case NRK_PORTE:
                        do { PORTE &= ~BM((pin & 0xF8) >> 3); } while(0); break;
                case NRK_PORTF:
                        do { PORTF &= ~BM((pin & 0xF8) >> 3); } while(0); break;
                default: return -1;
        }
        return 1;
}

int8_t nrk_gpio_get(uint8_t pin)
{
    if (pin == NRK_INVALID_PIN_VAL) return -1;
        switch (pin & 0x07) {
                case NRK_PORTA:
                        return !!(PINA & BM((pin & 0xF8) >> 3));
                case NRK_PORTB:
                        return !!(PINB & BM((pin & 0xF8) >> 3));
                case NRK_PORTC:
                        return !!(PINC & BM((pin & 0xF8) >> 3));
                case NRK_PORTD:
                        return !!(PIND & BM((pin & 0xF8) >> 3));
                case NRK_PORTE:
                        return !!(PINE & BM((pin & 0xF8) >> 3));
                case NRK_PORTF:
                        return !!(PINF & BM((pin & 0xF8) >> 3));
                default: return -1;
        }
        return 1;
}

int8_t nrk_led_clr( int led )
{
if(led==0) { nrk_gpio_set(NRK_LED_0); return 1; }
if(led==1) { nrk_gpio_set(NRK_LED_1); return 1; }
if(led==2) { nrk_gpio_set(NRK_LED_2); return 1; }
if(led==3) { nrk_gpio_set(NRK_LED_3); return 1; }
return -1;
}

int8_t nrk_led_set( int led )
{
if(led==0) { nrk_gpio_clr(NRK_LED_0); return 1; }
if(led==1) { nrk_gpio_clr(NRK_LED_1); return 1; }
if(led==2) { nrk_gpio_clr(NRK_LED_2); return 1; }
if(led==3) { nrk_gpio_clr(NRK_LED_3); return 1; }
return -1;
}
*/
