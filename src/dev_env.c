#include "freertos/FreeRTOS.h"
#include "esp_log.h"

void wifi_app_main(void);
void http_app_main(void *ignore);
void udplog_start(void);
int dev_main()
{
    /*Start Wifi*/
 	wifi_app_main();
    http_app_main("ignore");
    /*Allow OTA*/
    udplog_start();
    ESP_LOGI("DEV env",__DATE__ "\n");


    /*Start Wifi Serial*/
    /*Launch Dali stuff*/
    return 0;
}