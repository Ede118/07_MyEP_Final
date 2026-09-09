#include "motion.h"

bool Motion_PlanLinear(
    const system_t *system,
    motion_block_t *motion_block,
    float target_x_mm,
    float target_y_mm,
    float speed_mm_s
)
{
    if ((system == NULL) || (motion_block == NULL))
    {
        return false;
    }

    if (system->state != SYS_READY)
    {
        return false;
    }

    if ((target_x_mm < 0.0f) ||
        (target_y_mm < 0.0f) ||
        (target_x_mm > CNC_MAX_X_MM) ||
        (target_y_mm > CNC_MAX_Y_MM) ||
        (speed_mm_s <= 0.0f) ||
        (speed_mm_s > CNC_MAX_SPEED_MM_S))
    {
        return false;
    }

    int32_t target_x_steps;
    int32_t target_y_steps;

    int32_t delta_x;
    int32_t delta_y;

    target_x_steps = (int32_t)(target_x_mm * system->movement[AXIS_X].steps_per_mm);

    target_y_steps = (int32_t)(target_y_mm * system->movement[AXIS_Y].steps_per_mm);

    /* Guardar posición objetivo */
    motion_block->target_position_steps[AXIS_X] = target_x_steps;
    motion_block->target_position_steps[AXIS_Y] = target_y_steps;


    /* Diferencias con signo */
    delta_x = target_x_steps - system->movement[AXIS_X].position_steps;
    delta_y = target_y_steps - system->movement[AXIS_Y].position_steps;

	uint64_t L;
	L = sqrt((delta_x * delta_x) + (delta_y * delta_y));

    /* Eje X */
    if (delta_x >= 0)
    {
        motion_block->direction[AXIS_X] = DIRECTION_POSITIVE;
        motion_block->delta_steps[AXIS_X] = (uint32_t)delta_x;
    }
    else
    {
        motion_block->direction[AXIS_X] = DIRECTION_NEGATIVE;
        motion_block->delta_steps[AXIS_X] = (uint32_t)(-delta_x);
    }


    /* Eje Y */
    if (delta_y >= 0)
    {
        motion_block->direction[AXIS_Y] = DIRECTION_POSITIVE;
        motion_block->delta_steps[AXIS_Y] = (uint32_t)delta_y;
    }
    else
    {
        motion_block->direction[AXIS_Y] = DIRECTION_NEGATIVE;
        motion_block->delta_steps[AXIS_Y] = (uint32_t)(-delta_y);
    }


    /* Cantidad de eventos para Bresenham */
    if (motion_block->delta_steps[AXIS_X] > motion_block->delta_steps[AXIS_Y])
    {
        motion_block->step_count = motion_block->delta_steps[AXIS_X];
    }
    else
    {
        motion_block->step_count = motion_block->delta_steps[AXIS_Y];
    }

    motion_block->target_speed_mm_s = speed_mm_s;



    return true;
}