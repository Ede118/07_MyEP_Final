#ifndef HOMING_H
#define HOMING_H

#include "cnc.h"
#include "stepper.h"

typedef enum
{
    HOMING_IDLE,
    HOMING_SEEK,
    HOMING_PULL_OFF,
    HOMING_DONE,
    HOMING_ERROR
} homing_state_t;

typedef struct
{
    homing_state_t state;

    bool limit_x;
    bool limit_y;

} homing_t;


/* Inicialización */
void Homing_Init(homing_t *homing);

/* Comienza la secuencia */
bool Homing_Start(homing_t *homing);

/* Ejecuta la máquina de estados */
void Homing_Update(
    homing_t *homing,
    system_t *system,
    stepper_t *stepper
);

/* Aviso desde las ISR de fin de carrera */
void Homing_LimitTriggered(
    homing_t *homing,
    axis_id_t axis
);

bool Homing_IsFinished(const homing_t *homing);

#endif // HOMING_H