#include "TIMER_MILLIS.h"

/**
 * @brief Construct a new timer millis object
 * @param time_ms time in milliseconds
 * @param callback callback void function
 */
Timer_Millis::Timer_Millis(uint32_t time_ms, void (*callback)(void))
{
    period = time_ms;
    callback_function = callback;
}

void Timer_Millis::begin()
{
    startMillis = millis(); // initial start time
}

void Timer_Millis::update()
{
    // Serial.print("here");

    if (millis() - startMillis >= period) // test whether the period has elapsed
    {
        startMillis = millis(); // IMPORTANT to save the start time of the current LED state.
        callback_function();
    }
}