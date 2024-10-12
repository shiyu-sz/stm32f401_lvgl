
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "usart.h"
#include <stdio.h>
#include "spi.h"
#include "nr_micro_shell.h"

/** 获取系统信息
 *  gss_sys_info
 */
void gss_sys_info(char argc, char *argv)
{
    printf("app version : %s\r\n", "1.0");
}

/** crash测试
 *  gss_crash_test
 */
void gss_crash_test(char argc, char *argv)
{
    volatile int * SCB_CCR = (volatile int *) 0xE000ED14; // SCB->CCR
    int x, y, z;

    *SCB_CCR |= (1 << 4); /* bit4: DIV_0_TRP. */

    x = 10;
    y = 0;
    z = x / y;
    printf("z:%d\n", z);
}

const static_cmd_st static_cmd[] =
{
    {"gss_sys_info", gss_sys_info},
    {"gss_crash_test", gss_crash_test},
    {"\0", NULL}
};
