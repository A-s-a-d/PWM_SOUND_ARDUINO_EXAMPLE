#include <Arduino.h>
#include "TIMER_MILLIS.h"
#include "TIMER_MICROS.h"



// Define the pins
#define POTENTIOMETER_PIN A1
#define PWM_PIN 10

void  read_potentiometer();
Timer_Millis timer(500, read_potentiometer);
uint16_t potValue = 0;



// Variables
float frequency = 0;
float sineValue = 0;
float phaseIncrement = 0;
float phase = 0;
void frequency_callback();
Timer_Micros timer2(32, frequency_callback);


void setup() {

  // Set the Timer 1 to 31.2kHz
  timer.begin();
  timer2.begin();
  TCCR1B = ((TCCR1B & B11111000) | B00000001);
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  timer.update();
  timer2.update();
}

void frequency_callback(){
     sineValue = sin(phase);
    phase += phaseIncrement;

    // Wrap the phase to avoid overflow
    if (phase >= 2 * PI) {
      phase -= 2 * PI;
    }

    // Scale the sine value (-1 to 1) to the PWM range (0 to 255)
    int pwmValue = (sineValue + 1) * 127.5; // Scale sine wave to 0-255

    // Output the PWM signal
    analogWrite(PWM_PIN, pwmValue);
}

void read_potentiometer(){
  potValue = analogRead(POTENTIOMETER_PIN);
  frequency = potValue*10;
  phaseIncrement = 2 * PI * frequency / 31250;

}