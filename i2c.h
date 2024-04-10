#ifndef I2C_HEADER_H
#define I2C_HEADER_H

#include <stdint.h>

typedef enum {
    STATUS_OK,
    STATUS_ERROR
} status_t;

status_t i2c_init(void);
status_t i2c_enable_interrupt_pin(void);
status_t i2c_disable_interrupt_pin(void);
status_t i2c_get_full_scale(uint8_t *full_scale);
status_t i2c_get_output_data_rate(uint8_t *output_data_rate);
status_t i2c_set_output_data_rate(uint8_t new_output_data_rate);
status_t i2c_read_axis_data(uint8_t axis, int16_t *output_data);

status_t i2c_read(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer);

status_t i2c_write(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer);

#endif
