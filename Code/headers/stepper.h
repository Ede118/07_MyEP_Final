#ifndef STEPPER_H
#define STEPPER_H

#include "cnc.h"
#include "motion.h"

typedef enum
{
    STEPPER_IDLE,
    STEPPER_RUNNING,
    STEPPER_ERROR
} stepper_state_t;

typedef struct
{
    stepper_state_t state;

    motion_block_t block;

    uint32_t event_count;

    int32_t error[CNC_LINEAR_AXIS_COUNT];

} stepper_t;


/* Inicialización */
void Stepper_Init(stepper_t *stepper);

/* Habilitación de los drivers */
void Stepper_Enable(void);
void Stepper_Disable(void);

/* Ejecución de un bloque */
bool Stepper_Start(
    stepper_t *stepper,
    const motion_block_t *block
);

void Stepper_Stop(stepper_t *stepper);

/* Llamada desde la interrupción del timer */
void Stepper_TimerISR(stepper_t *stepper);

/* Consulta de estado */
bool Stepper_IsBusy(const stepper_t *stepper);

#endif // STEPPER_H