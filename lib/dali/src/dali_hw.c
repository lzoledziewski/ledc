#include "freertos/FreeRTOS.h"
#include "driver/rmt.h"



void dalihw_start(void)
{
    rmt_config_t rmt_config = {0};
    rmt_config.channel = RMT_CHANNEL_0;
    rmt_config.rmt_mode = RMT_MODE_RX;
    rmt_config.gpio_num = 0;
    //Single TE is 416.67us, with RMT running off APB clock single tick can be between 0,125us to 31.875 us.
    //with 0,125us there's 3333 ticks for single te - rmt_item can store ~10 TEs 
    //    which should be enough to detect errors (Manchester forces max 2 TE of same level signal)

    rmt_config.clk_div = 1; 
}