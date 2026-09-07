#ifndef MOTION_H
#define MOTION_H

#include "cnc.h"

typedef struct
{
    int32_t target_position_steps[CNC_LINEAR_AXIS_COUNT];

    uint32_t delta_steps[CNC_LINEAR_AXIS_COUNT];

    int8_t direction[CNC_LINEAR_AXIS_COUNT];

    uint32_t step_count;

    float path_length_mm;
    float target_speed_mm_s;
    float acceleration_mm_s2;
} motion_block_t;

bool Motion_PlanLinear(
    const system_t *system,
    float target_x_mm,
    float target_y_mm,
    float speed_mm_s,
    motion_block_t *motion_block
);


#endif // MOTION_H