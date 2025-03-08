#ifndef TIMER_MICROS_H
#define TIMER_MICROS_H

#include <Arduino.h>

class Timer_Micros
{
private:
    unsigned long startMicros; // some global variables available anywhere in the program
    unsigned long currentMicros;
    unsigned long period; // the value is a number of milliseconds
    void (*callback_function)(void);

public:

/**
 * @brief Construct a new timer millis object
 * @param time_us time in micro seconds
 * @param callback callback void function
 */
    Timer_Micros(uint32_t time_us, void (*callback)(void));
   
    void begin();
    void update();
};

#endif