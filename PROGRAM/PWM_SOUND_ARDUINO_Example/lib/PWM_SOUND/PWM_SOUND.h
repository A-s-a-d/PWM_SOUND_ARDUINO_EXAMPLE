#ifndef PWN_SOUND_H
#define PWN_SOUND_H

#include "Arduino.h"

class Pwm_Sound
{
private:
    uint16_t _sampling_frequency;
    uint16_t _sampling_resolution;
    uint16_t _duty_cycle;
    uint8_t _pwm_pin;

public:
    Pwm_Sound(uint8_t Pwm_Pin, uint16_t sampling_frequency, uint16_t sampling_resolution);
    void begin();
    void update(uint16_t duty_cycle);
    void generate(uint16_t generated_frequency);
    uint16_t calculate_duty_cycle(uint16_t generated_frequency);

};





#endif