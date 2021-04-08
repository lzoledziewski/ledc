/** Concept: Manage Table with commands and their handling **/
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"


#define AUTO_ENUM
typedef enum
{ 
#include "dali_def.h"
} eDaliCmd;
#undef AUTO_ENUM

#define AUTO_STR
const char *cmds_102[] =
{
    #include "dali_def.h"
};
#undef AUTO_STR

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
    
    cmd = CMD_DAPC;

}