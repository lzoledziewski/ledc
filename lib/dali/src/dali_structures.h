#ifndef DALI_STRUCTURES_H
#define DALI_STRUCTURES_H


#define DALI_CMD_SPECIAL_OFFSET 256u
#define DALI_CMD_APP_EXT_OFFSET 224u


typedef struct 
{
    /* data */
}DT0_RAM_Vars;

typedef struct 
{
    /* data */
}DT6_RAM_Vars;

typedef struct 
{
    /* data */
}DT8_RAM_Vars;
typedef union
{
    DT6_RAM_Vars dt6;
    DT8_RAM_Vars dt8;
}RAM_App_ext;
typedef struct 
{
    DT0_RAM_Vars dt0;
    RAM_App_ext appext;
}RAM_Vars;


typedef enum
{
    e_SHORT_ADDR,
    e_GROUP_ADDR,
    e_BROADCAST_UNADDR,
    e_BROADCAST,
    e_SPECIAL,
    e_RESERVED
} eAddressMode;



typedef struct 
{
    void *controller; /*something to manage lights*/
    void *dali_data; /*pointer to DALI variables, might be index or sth*/
    void *callbacks;
}dali_device_t;
typedef struct
{
    dali_device_t devices[64];
}dali_ctx_t;


#define AUTO_ENUM
typedef enum
{ 
#include "dali_def.h"
} eDaliCmd;
#undef AUTO_ENUM

#define AUTO_ARR_ENUM

typedef enum
{ 
#include "dali_def.h"
} eDaliEntry;
#undef AUTO_ARR_ENUM





#endif //DALI_STRUCTURES_H