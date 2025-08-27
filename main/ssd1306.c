#include "ssd1306.h"

#include "esp_log.h"

#include "driver/gpio.h"
#include "driver/i2c.h"
#include "freertos/task.h"

#include "config.h"

void register_display()
{
    i2c_config_t i2c_config = {
        .mode       = I2C_MODE_MASTER,
        .scl_io_num = GPIO_DISPLAY_SCL,
        .sda_io_num = GPIO_DISPLAY_SDA,

        .scl_pullup_en = GPIO_PULLDOWN_ENABLE,
        .sda_pullup_en = GPIO_PULLDOWN_ENABLE,

        .master.clk_speed = 1000000};

    i2c_param_config(I2C_NUM_0, &i2c_config);
    i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

    ssd1306_init();
}

void ssd1306_init()
{
    esp_err_t err;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);

    i2c_master_write_byte(cmd, (DISPLAY_I2C_ADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, 0x00, true); // control byte stream
    i2c_master_write_byte(cmd, 0xAF, true); // display ON

    i2c_master_stop(cmd);

    if (err == ESP_OK)
        ESP_LOGI(TAG, "Display configured successfully.");
    else
        ESP_LOGE(TAG, "Display configuration failed. Code: 0x%.2X", err);

    i2c_cmd_link_delete(cmd);
}
