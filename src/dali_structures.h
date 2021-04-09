#ifndef DALI_STRUCTURES_H
#define DALI_STRUCTURES_H


#define DALI_CMD_SPECIAL_OFFSET 256u
#define DALI_CMD_APP_EXT_OFFSET 224u

typedef enum
{
    e_SHORT_ADDR,
    e_GROUP_ADDR,
    e_BROADCAST_UNADDR,
    e_BROADCAST,
    e_SPECIAL,
    e_RESERVED
} eAddressMode;


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