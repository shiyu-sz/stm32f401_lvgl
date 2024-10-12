
#include "task_schedule.h"
#include "gpio.h"
#include "usart.h"
#include "spi.h"
#include "lvgl_task.h"

//任务控制块
struct task_tcb task_list[TASKS_COUNT] =
{
//  开关        初始状态        开始时间 运行时间   间隔时间        回调函数
    {TASK_ON,   TASK_WAIT,      10,    0,        10,         task_shell},
    {TASK_ON,   TASK_WAIT,      20,    0,        500,       task_led},
    {TASK_ON,   TASK_WAIT,      20,    0,        5,       lvgl_task},
};

/**
 * @brief 任务初始化
 * 
 */
void task_init(void)
{
    unsigned int i = 0;
    for(i=0; i<TASKS_COUNT; i++) {
        task_list[i].run_time = task_list[i].start_time;
        task_list[i].state = TASK_WAIT;
    }
}

/**
 * @brief 任务轮询
 * 
 */
void TaskPoll(void)
{
    unsigned int i = 0;
    for (i=0; i<TASKS_COUNT; i++) 
    {
        if( task_list[i].onoff == TASK_ON )
        {
            if (task_list[i].run_time > 0) 
             {
                task_list[i].run_time --;
                if (task_list[i].run_time <= 0)
                {
                    task_list[i].run_time = task_list[i].exec_cycle;
                    task_list[i].state = TASK_READY;
                }
            }
        }
    }
}

/**
 * @brief 任务调度
 * 
 */
void TaskSchedule(void)
{
    unsigned int i;
    for (i=0; i<TASKS_COUNT; i++)
    {
        if (task_list[i].state == TASK_READY)
        {
            task_list[i].state = TASK_WAIT;
            task_list[i].callback();
        }
    }
}

// 打开或关闭任务
void task_control(enum task_id id, enum e_task_switch flag)
{
    task_list[id].onoff = flag;
    task_list[id].run_time = task_list[id].start_time;
}
