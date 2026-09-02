#ifndef CNC_H
#define CNC_H

#include <stdint.h>
#include <stdbool.h>

/* Cantidad de ejes de movimiento continuo */
#define CNC_LINEAR_AXIS_COUNT  2U

typedef enum
{
    AXIS_X,
    AXIS_Y,
} axis_t;

typedef enum
{
    AXIS_Z_LOW,
    AXIS_Z_HIGH,
} z_state_t;

typedef enum 
{
    SYS_DISABLED,
    SYS_IDLE,
    SYS_HOMING,
    SYS_READY,
    SYS_RUN,
    SYS_ALARM
} system_state_t;

typedef struct
{
    float steps_per_mm;
    float max_speed_mm_s;
    float acceleration_mm_s2;
    int32_t position_steps;
} movement_t;


typedef struct
{
    system_state_t state;

    movement_t movement[CNC_LINEAR_AXIS_COUNT];

    axis_t axis;
    
    z_state_t z_state;

    bool homed;
    bool alarm;
    bool motion_finished;

} system_t;

#endif // CNC_H