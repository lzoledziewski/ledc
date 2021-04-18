/** Concept: Manage Table with commands and their handling **/
#ifndef UNIT_TEST
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#endif

#include "dali_structures.h"


#define AUTO_STR
const char *cmd_ids[] =
{
    #include "dali_def.h"
};
#undef AUTO_STR


eDaliEntry DT0Lut[]=
{
#define AUTO_LUT_102
#include "dali_def.h"
#undef AUTO_LUT_102
};

eDaliEntry DT6Lut[]=
{
#define AUTO_LUT_207
#include "dali_def.h"
#undef AUTO_LUT_207
};

eDaliEntry DT8Lut[]=
{
#define AUTO_LUT_209
#include "dali_def.h"
#undef AUTO_LUT_209
};

eDaliEntry SpecialLut[]=
{
    #define AUTO_LUT_SPECIAL
    #include "dali_def.h"
    #undef AUTO_LUT_SPECIAL
};

void vDaliTask( void * pvParameters )
{
    unsigned char shutdown = 0;
    // register for command events

    //process events


    while (!shutdown)
    {
        #ifndef UNIT_TEST
        xQueueReceive(0,0,portTICK_PERIOD_MS * 100); 
        #endif
        /*process message - can be one of:
            - dali msg
                -  parse, process
            - control cmd
                -   react
            - timer???
        */   
    }
}
    
void parse_msg(uint16_t msg, eAddressMode *addr_mode, eDaliCmd *cmd_id, uint8_t *addr, uint8_t *data)
{
    *addr_mode = e_RESERVED;
    *addr = 0;
    *cmd_id = CMD_DUMMY;
    *data = 0u;
    /*determine CMD ID, addr mode & data*/
    if (((1 << 15) & msg) == 0)
    {
        *addr_mode = e_SHORT_ADDR;
        *addr = msg >> 9;
    }
    else if ((0x6000 & msg) == 0x0)
    {
        *addr_mode = e_GROUP_ADDR;
        *addr = (msg >> 9) & 0xF;
    }
    else if ((0x6200 & msg) == 0x6200)
    {
        *addr_mode = e_BROADCAST;
    }
    else if ((0x6000 & msg) == 0x6000)
    {
        *addr_mode = e_BROADCAST_UNADDR;
    }

    if (*addr_mode != e_RESERVED)
    {
        if ((1 << 8) & msg)
        {
            *cmd_id = msg & 0xFF;
        }
        else
        {
            *cmd_id = CMD_DAPC;
            *data = msg & 0xFF;
        }
    }
    /*Can be special or reserved*/
    else if ((msg >> 8) < 0xCC)
    {
        *addr_mode = e_SPECIAL;
        *data = msg & 0xFF;
    }

    /*next step is to provide data to each device
        those addressed should receive all data
        those not addressed should be notified to clear flags (App extension / Twice flag)*/

}
