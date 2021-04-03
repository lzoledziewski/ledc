#include "driver/rmt.h"
void app_main() {
    esp_err_t esp_err;
    rmt_config_t config = RMT_DEFAULT_CONFIG_RX(0,0);
    esp_err = rmt_config(&config);
    assert(esp_err == ESP_OK);
}