#ifndef PINOUT_H
#define PINOUT_H

#define POTENTIOMETER_PIN A1
#define PWM_PIN 3

/* 
The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.

The base frequency for pins 5 and 6 is 62500 Hz.

The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64, 256, and 1024.

The divisors available on pins 3 and 11 are: 1, 8, 32, 64, 128, 256, and 1024.

PWM frequencies are tied together in pairs of pins. If one in a pair is changed, the other is also changed to match.

Pins 5 and 6 are paired on timer0.

Pins 9 and 10 are paired on timer1.

Pins 3 and 11 are paired on timer2.
 */

#endif