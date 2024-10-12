
#ifndef _TASK_SCHEDULE_H_
#define _TASK_SCHEDULE_H_

enum task_id {
    TASK_SHELL = 0,
    TASK_LED,
    TASK_LVGL,
    TASK_MAX
};

// 任务最大数量
#define TASKS_COUNT (TASK_MAX)

// 任务的开关
enum e_task_switch
{
    TASK_OFF,   // 任务关闭
    TASK_ON,    // 任务开启
};

// 任务的状态
enum e_task_state
{
    TASK_WAIT,  // 等待状态
    TASK_READY, // 就绪状态
};

//任务控制块
struct task_tcb
{
    enum e_task_switch onoff;   // 任务的开关
    enum e_task_state state;    // 任务的状态
    unsigned int start_time;    // 任务的开始时间
    unsigned int run_time;      // 任务运行时间
    unsigned int exec_cycle;    // 任务的执行周期
    void (*callback)(void);     // 任务的回调函数
};

void task_init(void);
void TaskPoll(void);
void TaskSchedule(void);
void task_control(enum task_id id, enum e_task_switch flag);

#endif
