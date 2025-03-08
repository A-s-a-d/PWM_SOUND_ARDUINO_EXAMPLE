#include "PWM_SOUND.h"

Pwm_Sound::Pwm_Sound(uint8_t Pwm_Pin, uint16_t sampling_frequency, uint16_t sampling_resolution)
{
    _sampling_frequency = sampling_frequency;
    _sampling_resolution = sampling_resolution;
    _duty_cycle = 0;
    _pwm_pin = Pwm_Pin;
}

void Pwm_Sound::begin()
{
    // Set PWM pin as output
    pinMode(3, OUTPUT);
    
}