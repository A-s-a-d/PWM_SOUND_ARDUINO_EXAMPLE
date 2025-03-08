#ifndef TIMER_MILLIS_H
#define TIMER_MILLIS_H

#include <Arduino.h>

class Timer_Millis
{
private:
    unsigned long startMillis; // some global variables available anywhere in the program
    unsigned long currentMillis;
    unsigned long period; // the value is a number of milliseconds
    void (*callback_function)(void);

public:

/**
 * @brief Construct a new timer millis object
 * @param time_ms time in milliseconds
 * @param callback callback void function
 */
    Timer_Millis(uint32_t time_ms, void (*callback)(void)); // time in milliseconds
   
    void begin();
    void update();
};

#endif