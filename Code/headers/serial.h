#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>
#include <stdbool.h>

#define SERIAL_RX_BUFFER_SIZE 128U

typedef struct
{
    uint8_t rx_buffer[SERIAL_RX_BUFFER_SIZE];

    volatile uint16_t head;
    volatile uint16_t tail;

} serial_t;

void Serial_Init(serial_t *serial);

bool Serial_ReadByte(
    serial_t *serial,
    uint8_t *byte
);

void Serial_SendByte(
    serial_t *serial,
    uint8_t byte
);

void Serial_SendBytes(
    serial_t *serial,
    const uint8_t *data,
    uint32_t length
);

#endif // SERIAL_H