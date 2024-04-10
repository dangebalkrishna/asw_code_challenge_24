#include "i2c.h"

#include <stdint.h>
#include <stdio.h>

status_t i2c_read(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer)
{
    printf(
        "read [%d] bytes from bus [%d] for register [%d]\n",
        length,
        bus_address,
        register_address);

    /* Setting the output to some arbitrary value */
    for (size_t i = 0; i < length; ++i) {
        buffer[i] = 0xff;
    }

    return STATUS_OK;
}

status_t i2c_write(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer)
{
    printf(
        "write [%d] bytes to bus [%d] for register [%d]\n\t",
        length,
        bus_address,
        register_address);

    for (size_t i = 0; i < length; ++i) {
        printf("%p", buffer);
    }
    printf("\n");
    return STATUS_OK;
}

// Simulated variable
static uint8_t sensor_address = 0x1E; // Example sensor address

status_t i2c_init(void) {
    // Initialize I2C communication here
    printf("I2C initialized\n");
    return STATUS_OK;
}

status_t i2c_enable_interrupt_pin(void) {
    // Address of the control register for interrupt configuration
    uint8_t control_reg_address = 0x22; // CTRL_REG3 address

    // Value to enable interrupt in CTRL_REG3
    uint8_t interrupt_enable_value = 0x04; // Enable the interrupt pin (bit 2)

    // Write the interrupt enable value to the control register
    uint8_t buffer[2] = {control_reg_address, interrupt_enable_value};

    // Write the value to the control register
    if (i2c_write(sensor_address, buffer, 2) != STATUS_OK) {
        return STATUS_ERROR; // Error writing to control register
    }

    return STATUS_OK;
}
status_t i2c_read_axis_data(uint8_t axis, int16_t *output_data) {
    // Simulated data reading
    if (axis == 'X') {
        *output_data = 100; // Simulated X-axis data
    } else if (axis == 'Y') {
        *output_data = 200; // Simulated Y-axis data
    } else if (axis == 'Z') {
        *output_data = 300; // Simulated Z-axis data
    } else {
        return STATUS_ERROR; // Invalid axis
    }
    return STATUS_OK;
}

