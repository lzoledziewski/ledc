#ifndef DALI_H
#define DALI_H


#include "dali_structures.h"


void parse_msg(uint16_t msg, eAddressMode *addr_mode,eDaliCmd *cmd_id, uint8_t *addr, uint8_t *data);

#endif