#include "unity.h"
#include "stdint.h"
#include "dali.h"
//#include "dali.c"

void test_luts()
{
    eDaliCmd cmd;
    cmd = CMD_Y_COORDINATE_STEP_UP;

    eDaliEntry daliEntry = DT8Lut[cmd - 224];
    TEST_ASSERT_EQUAL(daliEntry, ARR_Y_COORDINATE_STEP_UP);

    cmd = 229u; /*RESERVED*/
    daliEntry = DT6Lut[cmd - 224];
    TEST_ASSERT_EQUAL(daliEntry, ARR_DUMMY);
}

void test_msgs()
{
    uint16_t msg = 0x2301; /*msg 1 sent to 0x11 SA*/
    eAddressMode addr_mode;
    eDaliCmd cmd;
    uint8_t addr;
    uint8_t data;

    parse_msg(msg, &addr_mode, &cmd, &addr, &data);
    TEST_ASSERT_EQUAL(e_SHORT_ADDR, addr_mode);
    TEST_ASSERT_EQUAL(0x11, addr );
    TEST_ASSERT_EQUAL(0x1, cmd );

}

int main (int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_luts);
    RUN_TEST(test_msgs);

    UNITY_END();

    return 0;
}