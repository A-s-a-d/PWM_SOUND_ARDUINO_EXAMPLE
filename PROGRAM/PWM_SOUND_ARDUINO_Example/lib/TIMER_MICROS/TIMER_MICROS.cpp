#include "TIMER_MICROS.h"

/**
 * @brief Construct a new timer millis object
 * @param time_us time in micro seconds
 * @param callback callback void function
 */
Timer_Micros::Timer_Micros(uint32_t time_us, void (*callback)(void))
{
    period = time_us;
    callback_function = callback;
}

void Timer_Micros::begin()
{
    startMicros = micros();; // initial start time
}

void Timer_Micros::update()
{
    // Serial.print("here");

    if (micros(); - startMicros >= period) // test whether the period has elapsed
    {
        startMicros = micros(); // IMPORTANT to save the start time of the current LED state.
        callback_function();
    }
}