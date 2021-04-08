
#ifdef AUTO_ENUM
#define NONE_ID(label, id) CMD_##label = id,
#define ADDR_ID(label, id) CMD_##label = (((id-1)/2) + 176),
#define DAPC_ID(label, id) CMD_##label = id,
#define SCENE_ID(label, id) CMD_##label##_S1 = id,\
                    CMD_##label##_S2 = id + 1,\
                    CMD_##label##_S3 = id + 2,\
                    CMD_##label##_S4 = id + 3,\
                    CMD_##label##_S5 = id + 4,\
                    CMD_##label##_S6 = id + 5,\
                    CMD_##label##_S7 = id + 6,\
                    CMD_##label##_S8 = id + 7,\
                    CMD_##label##_S9 = id + 8,\
                    CMD_##label##_S10 = id + 9,\
                    CMD_##label##_S11 = id + 10,\
                    CMD_##label##_S12 = id + 11,\
                    CMD_##label##_S13 = id + 12,\
                    CMD_##label##_S14 = id + 13,\
                    CMD_##label##_S15 = id + 14,\
                    CMD_##label##_S16 = id + 15,
#define GROUP_ID(label, id) CMD_##label##_G1 = id,\
                    CMD_##label##_G2 = id + 1,\
                    CMD_##label##_G3 = id + 2,\
                    CMD_##label##_G4 = id + 3,\
                    CMD_##label##_G5 = id + 4,\
                    CMD_##label##_G6 = id + 5,\
                    CMD_##label##_G7 = id + 6,\
                    CMD_##label##_G8 = id + 7,\
                    CMD_##label##_G9 = id + 8,\
                    CMD_##label##_G10 = id + 9,\
                    CMD_##label##_G11 = id + 10,\
                    CMD_##label##_G12 = id + 11,\
                    CMD_##label##_G13 = id + 12,\
                    CMD_##label##_G14 = id + 13,\
                    CMD_##label##_G15 = id + 14,\
                    CMD_##label##_G16 = id + 15,
#define DALI_AUTO_DEF(a,b,c,d,e) c(a,b)
#endif

#ifdef AUTO_STR
#define DALI_AUTO_DEF(a,b,c,d,e) #a,
#endif

#ifdef AUTO_ARR_ENUM
#define DALI_AUTO_DEF(id, id_num, addr_type, dt, flags) ARR_##id,
#endif


#if defined(AUTO_LUT_102) || defined (AUTO_LUT_207) || defined (AUTO_LUT_209)
#define NONE_ID(id, offset) [CMD_##id + offset] = ARR_##id,
#define ADDR_ID(id, offset) [CMD_##id + offset] = ARR_##id,
#define DAPC_ID(id, offset) /*DAPC is special case without real DALI identifier here*/
#define SCENE_ID(id, offset) [CMD_##id##_S1 + offset] = ARR_##id,\
                    [CMD_##id##_S2 + offset] = ARR_##id,\
                    [CMD_##id##_S3 + offset] = ARR_##id,\
                    [CMD_##id##_S4 + offset] = ARR_##id,\
                    [CMD_##id##_S5 + offset] = ARR_##id,\
                    [CMD_##id##_S6 + offset] = ARR_##id,\
                    [CMD_##id##_S7 + offset] = ARR_##id,\
                    [CMD_##id##_S8 + offset] = ARR_##id,\
                    [CMD_##id##_S9 + offset] = ARR_##id,\
                    [CMD_##id##_S10 + offset] = ARR_##id,\
                    [CMD_##id##_S11 + offset] = ARR_##id,\
                    [CMD_##id##_S12 + offset] = ARR_##id,\
                    [CMD_##id##_S13 + offset] = ARR_##id,\
                    [CMD_##id##_S14 + offset] = ARR_##id,\
                    [CMD_##id##_S15 + offset] = ARR_##id,\
                    [CMD_##id##_S16 + offset] = ARR_##id,
#define GROUP_ID(id, offset) [CMD_##id##_G1 + offset] = ARR_##id,\
                    [CMD_##id##_G2 + offset] = ARR_##id,\
                    [CMD_##id##_G3 + offset] = ARR_##id,\
                    [CMD_##id##_G4 + offset] = ARR_##id,\
                    [CMD_##id##_G5 + offset] = ARR_##id,\
                    [CMD_##id##_G6 + offset] = ARR_##id,\
                    [CMD_##id##_G7 + offset] = ARR_##id,\
                    [CMD_##id##_G8 + offset] = ARR_##id,\
                    [CMD_##id##_G9 + offset] = ARR_##id,\
                    [CMD_##id##_G10 + offset] = ARR_##id,\
                    [CMD_##id##_G11 + offset] = ARR_##id,\
                    [CMD_##id##_G12 + offset] = ARR_##id,\
                    [CMD_##id##_G13 + offset] = ARR_##id,\
                    [CMD_##id##_G14 + offset] = ARR_##id,\
                    [CMD_##id##_G15 + offset] = ARR_##id,\
                    [CMD_##id##_G16 + offset] = ARR_##id,
#ifdef AUTO_LUT_102
#define IEC_102(id_, addr_type) addr_type(id_, 0)
#define IEC_207(id_, addr_type)
#define IEC_209(id_, addr_type)
#endif 

#ifdef AUTO_LUT_207
#define IEC_102(id_, addr_type) 
#define IEC_207(id_, addr_type) addr_type(id_, -224)
#define IEC_209(id_, addr_type)
#endif 

#ifdef AUTO_LUT_209
#define IEC_102(id_, addr_type) 
#define IEC_207(id_, addr_type)
#define IEC_209(id_, addr_type) addr_type(id_, -224)
#endif 

#define DALI_AUTO_DEF(id, id_num, addr_type, dt, flags) dt(id,addr_type)
#endif


/*Idea:
LUTs: DALI ID to idx in table
CMDS are contained in one big array 
PROs: easier to generate data

Steps:
Generate ENUMS With ID's as in DALI - DONE
Generate regular C ENUMS without values for whole table
create ARRAYs using only ENUMS for each of 102,207,209
E_ARR_DALI LUT_102[]=
{
    [CMD_OFF] = ARR_OFF,
    .....
}

*/

#ifdef DALI_AUTO_DEF
/** definitions and customizations of DALI CMDs**/
/**                          ID,                                    ID_NUM,          **/

DALI_AUTO_DEF( DUMMY,                               0u,         DAPC_ID,        IEC_102,    0) /*Marker for not implemented / available commands*/
DALI_AUTO_DEF( DAPC,                                0u,         DAPC_ID,        IEC_102,    0)
DALI_AUTO_DEF( OFF,                                 0u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( UP,                                  1u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( DOWN,                                2u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( STEP_UP,                             3u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( STEP_DOWN,                           4u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( RECALL_MAX_LEVEL,                    5u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( RECALL_MIN_LEVEL,                    6u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( STEP_DOWN_AND_OFF,                   7u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( ON_AND_STEP_UP,                      8u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( ENABLE_DAPC_SEQUENCE,                9u,         NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( GO_TO_LAST_ACTIVE_LEVEL,             10u,        NONE_ID,        IEC_102,    0)
DALI_AUTO_DEF( GO_TO_SCENE,                         16u,        SCENE_ID,       IEC_102,    0)
DALI_AUTO_DEF( RESET,                               32u,        NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( STORE_ACTUAL_LEVEL_IN_DTR0,          33u,        NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SAVE_PERSISTENT_VARIABLES,           34u,        NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_OPERATING_MODE,                  0x23u,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( RESET_MEMORY_BANK,                   0x24u,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( IDENTIFY_DEVICE,                     0x25u,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_MAX_LEVEL,                       0x2Au,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_MIN_LEVEL,                       0x2Bu,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_SYSTEM_FAILURE_LEVEL,            0x2Cu,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_POWER_ON_LEVEL,                  0x2Du,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_FADE_TIME,                       0x2Eu,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_FADE_RATE,                       0x2Fu,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_EXTENDED_FADE_TIME,              0x30u,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_SCENE,                           0x40u,      SCENE_ID,       IEC_102,    F_TWICE)
DALI_AUTO_DEF( REMOVE_FROM_SCENE,                   0x50u,      SCENE_ID,       IEC_102,    F_TWICE)
DALI_AUTO_DEF( ADD_TO_GROUP,                        0x60u,      GROUP_ID,       IEC_102,    F_TWICE)
DALI_AUTO_DEF( REMOVE_FROM_GROUP,                   0x70u,      GROUP_ID,       IEC_102,    F_TWICE)
DALI_AUTO_DEF( SET_SHORT_ADDRESS,                   0x80u,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( ENABLE_WRITE_MEMORY,                 0x81u,      NONE_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( QUERY_STATUS,                        0x90u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_CONTROL_GEAR_PRESENT,          0x91u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_LAMP_FAILURE,                  0x92u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_LAMP_POWER_ON,                 0x93u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_LIMIT_ERROR,                   0x94u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_RESET_STATE,                   0x95u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_MISSING_SHORT_ADDRESS,         0x96u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_VERSION_NUMBER,                0x97u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_CONTENT_DTR0,                  0x98u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_DEVICE_TYPE,                   0x99u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_PHYSICAL_MINIMUM,              0x9Au,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_POWER_FAILURE,                 0x9Bu,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_CONTENT_DTR1,                  0x9Cu,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_CONTENT_DTR2,                  0x9Du,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_OPERATING_MODE,                0x9Eu,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_LIGHT_SOURCE_TYPE,             0x9Fu,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_ACTUAL_LEVEL,                  0xA0u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_MAX_LEVEL,                     0xA1u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_MIN_LEVEL,                     0xA2u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_POWER_ON_LEVEL,                0xA3u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_SYSTEM_FAILURE_LEVEL,          0xA4u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_FADE_TIME_FADE_RATE,           0xA5u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_MANUFACTURER_SPECIFIC_MODE,    0xA6u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_NEXT_DEVICE_TYPE,              0xA7u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_EXTENDED_FADE_TIME,            0xA8u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_CONTROL_GEAR_FAILURE,          0xAAu,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_SCENE_LEVEL,                   0xB0u,      SCENE_ID,       IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_GROUPS_0_7,                    0xC0u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_GROUP_8_15,                    0xC1u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_RANDOM_ADDRESS_H,              0xC2u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_RANDOM_ADDRESS_M,              0xC3u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_RANDOM_ADDRESS_L,              0xC4u,      NONE_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( READ_MEMORY_LOCATION,                0xC5u,      NONE_ID,        IEC_102,    F_ANSWER)

DALI_AUTO_DEF( QUERY_EXTENDED_VERSION_NUMBER,       0xFFu,      NONE_ID,        IEC_102,    F_ANSWER)

DALI_AUTO_DEF( TERMINATE,                           0xA1,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( DTR0,                                0xA3,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( INITIALISE,                          0xA5,       ADDR_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( RANDOMISE,                           0xA7,       ADDR_ID,        IEC_102,    F_TWICE)
DALI_AUTO_DEF( COMPARE,                             0xA9,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( WITHDRAW,                            0xAB,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( PING,                                0xAD,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( SEARCHADDRH,                         0xB1,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( SEARCHADDRM,                         0xB3,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( SEARCHADDRL,                         0xB5,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( PROGRAM_SHORT_ADDRESS,               0xB7,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( VERIFY_SHORT_ADDRESS,                0xB9,       ADDR_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( QUERY_SHORT_ADDRESS,                 0xBB,       ADDR_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( ENABLE_DEVICE_TYPE,                  0xC1,       ADDR_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( DTR1,                                0xC3,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( DTR2,                                0xC5,       ADDR_ID,        IEC_102,    0)
DALI_AUTO_DEF( WRITE_MEMORY_LOCATION,               0xC7,       ADDR_ID,        IEC_102,    F_ANSWER)
DALI_AUTO_DEF( WRITE_MEMORY_LOCATION_NO_LOCATION,   0xC9,       ADDR_ID,        IEC_102,    0)



DALI_AUTO_DEF( REFERENCE_SYSTEM_POWER,              224u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( ENABLE_CURRENT_PROTECTOR,            225u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( DISABLE_CURRENT_PROTECTOR,           226u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( SELECT_DIMMING_CURVE,                227u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( STORE_DTR_AS_FAST_FADE_TIME,         228u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_GEAR_TYPE,                     237u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_DIMMING_CURVE,                 238u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_POSSIBLE_OPERATING_MODES,      239u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_FEATURES,                      240u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_FAILURE_STATUS,                241u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_SHORT_CIRCUIT,                 242u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_OPEN_CIRCUIT,                  243u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_LOAD_DECREASE,                 244u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_LOAD_INCREASE,                 245u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_CURRENT_PROTECTOR_ACTIVE,      246u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_THERMAL_SHUT_DOWN,             247u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_THERMAL_OVERLOAD,              248u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_REFERENCE_RUNNING,             249u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_REFERENCE_MEASUREMENT_FAILED,  250u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_CURRENT_PROTECTOR_ENABLED,     251u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_OPERATING_MODE_DT6,            252u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_FAST_FADE_TIME,                253u,       NONE_ID,        IEC_207,    0)
DALI_AUTO_DEF( QUERY_MIN_FAST_FADE_TIME,            254u,       NONE_ID,        IEC_207,    0)


DALI_AUTO_DEF( SET_TEMPORARY_X_COORDINATE,          224u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( SET_TEMPORARY_Y_COORDINATE,          225u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( ACTIVATE,                            226u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( X_COORDINATE_STEP_UP,                227u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( X_COORDINATE_STEP_DOWN,              228u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( Y_COORDINATE_STEP_UP,                229u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( Y_COORDINATE_STEP_DOWN,              230u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( SET_TEMPORARY_COLOUR_TEMPERATURE_TC, 231u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( COLOUR_TEMPERATURE_TC_STEP_COOLER,   232u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( COLOUR_TEMPERATURE_TC_STEP_WARMER,   233u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( SET_TEMPORARY_PRIMARY_N_DIMLEVEL,    234u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( SET_TEMPORARY_RGB_DIM_LEVEL,         235u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( SET_TEMPORARY_WAF_DIM_LEVEL,         236u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( SET_TEMPORARY_RGBWAF_CONTROL,        237u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( COPY_REPORT_TO_TEMPORARY,            239u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( STORE_TY_PRIMARY_N,                  240u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( STORY_XY_COORDINATE_PRIMARY_N,       241u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( STORE_COLOUR_TEMPERATURE_TC_LIMIT,   242u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( STORE_GEAR_FEATURES_STATUS,          243u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( ASSIGN_COLOUR_TO_LINKED_CHANNEL,     245u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( START_AUTO_CALIBRATION,              246u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( QUERY_GEAR_FEATURES_STATUS,          247u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( QUERY_COLOR_STATUS,                  248u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( QUERY_COLOR_TYPE_FEATURES,           249u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( QUERY_COLOR_VALUE,                   250u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( QUERY_RGBWAF_CONTROL,                251u,       NONE_ID,        IEC_209,    0)
DALI_AUTO_DEF( QUERY_ASSIGNED_COLOUR,               252u,       NONE_ID,        IEC_209,    0)

#ifdef DALI_AUTO_DEF
    #undef DALI_AUTO_DEF
#endif
#ifdef NONE_ID
    #undef NONE_ID
#endif
#ifdef ADDR_ID
    #undef ADDR_ID
#endif
#ifdef DAPC_ID
    #undef DAPC_ID
#endif
#ifdef GROUP_ID
    #undef GROUP_ID
#endif
#ifdef SCENE_ID
    #undef SCENE_ID
#endif
#ifdef IEC_102
    #undef IEC_102
#endif
#ifdef IEC_207
    #undef IEC_207
#endif
#ifdef IEC_209
    #undef IEC_209
#endif

#endif