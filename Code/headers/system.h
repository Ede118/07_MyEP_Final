#ifndef SYSTEM_H
#define SYSTEM_H

#include "cnc.h"
#include "gcode.h"

void System_Init(
    system_t *system
);

void System_Update(
    system_t *system
);

bool System_ProcessGCode(
    system_t *system,
    const gcode_t *gcode
);

void System_SetState(
    system_t *system,
    system_state_t state
);

void System_TriggerAlarm(
    system_t *system
);

#endif // SYSTEM_H