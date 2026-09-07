#ifndef GCODE_H
#define GCODE_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    GCODE_NONE,
    GCODE_G0,
    GCODE_G1,
    GCODE_G90,
    GCODE_G91,
    GCODE_M2,
    GCODE_M3,
    GCODE_M4,
    GCODE_M5
} gcode_command_t;

typedef struct
{
    gcode_command_t command;

    float x;
    float y;
    float feed;
    uint8_t power;

    bool has_x;
    bool has_y;
    bool has_feed;
    bool has_power;

} gcode_t;

bool GCode_Parse(
    const char *line,
    gcode_t *gcode
);

#endif // GCODE_H