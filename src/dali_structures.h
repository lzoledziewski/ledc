#ifndef DALI_H
#define DALI_H

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



#endif //DALI_H