#ifndef LASER_H
#define LASER_H

#include "cnc.h"

typedef struct
{
    bool enabled;
    uint8_t power; // 0 a 255
} laser_t;

void Laser_SetEnable(
    laser_t *laser,
    bool enable
);

void Laser_SetPower(
    laser_t *laser,
    uint8_t power
);


#endif // LASER_H