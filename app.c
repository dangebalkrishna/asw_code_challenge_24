#include "i2c.h"
#include <stdio.h>

int main() {
    i2c_init();

    uint8_t full_scale;
    i2c_get_full_scale(&full_scale);
    printf("Current full-scale configuration: %d\n", full_scale);

    uint8_t current_output_data_rate;
    i2c_get_output_data_rate(&current_output_data_rate);
    printf("Current output data rate: %d\n", current_output_data_rate);

    // Set a new output data rate
    uint8_t new_output_data_rate = 2; // Example new output data rate
    i2c_set_output_data_rate(new_output_data_rate);
    printf("New output data rate set: %d\n", new_output_data_rate);

    i2c_enable_interrupt_pin();
    i2c_disable_interrupt_pin();

    int16_t x_data, y_data, z_data;
    i2c_read_axis_data('X', &x_data);
    i2c_read_axis_data('Y', &y_data);
    i2c_read_axis_data('Z', &z_data);

    printf("X-axis data: %d\n", x_data);
    printf("Y-axis data: %d\n", y_data);
    printf("Z-axis data: %d\n", z_data);

    return 0;
}
