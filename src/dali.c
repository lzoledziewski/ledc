/** Concept: Manage Table with commands and their handling **/
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

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

void vDaliTask( void * pvParameters )
{
    bool shutdown = false;
    // register for command events

    //process events

    eDaliCmd cmd;
    while (!shutdown)
    {
        xQueueReceive(0,0,portTICK_PERIOD_MS * 100); 
        /*process message - can be one of:
            - dali msg
                -  parse, process
            - control cmd
                -   react
            - timer???
        */   
    }

    int array[8] = 
    {
        [1]=3,
        [2]=12
    };

    cmd = CMD_Y_COORDINATE_STEP_UP;

    eDaliEntry daliEntry = DT8Lut[cmd - 224];
    assert(daliEntry == ARR_Y_COORDINATE_STEP_UP);

}