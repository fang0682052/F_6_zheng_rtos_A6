#include "FreeRTOS_demo1.h"





typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} LED_Config_t;

LED_Config_t led1_config = {LED1_GPIO_Port, LED1_Pin};
LED_Config_t led2_config = {LED2_GPIO_Port, LED2_Pin};

// void Task1(void * arg)
// {
//   while (1)
//   {
//     Int_LED_Toggle(LED1_GPIO_Port, LED1_Pin);
//    // vTaskDelay(500); // 延时500ms
//    HAL_Delay(300);
//   }
// }

// 任务函数
void LED_Task(void * arg)
{
    LED_Config_t *config = (LED_Config_t *)arg;
    while(1)
    {
        Int_LED_Toggle(config->port, config->pin);
        vTaskDelay(500);
    }
}



void FreeRTOS_Start(void)
{
  // 创建任务
  
// xTaskCreate(Task1, "Task1", 128, NULL, 1, NULL);
  // 同一个函数，创建两次任务，传入不同引脚
xTaskCreate(LED_Task, "LED1", 512, &led1_config, 2, NULL);
xTaskCreate(LED_Task, "LED2", 512, &led2_config, 2, NULL);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    //最后一行的代码肯定是 启动调度器
vTaskStartScheduler();  
//这个函数是FreeRTOS的调度器，它会根据任务的优先级来调度任务运行，这个里面也启动了空闲任务和定时器任务，空闲任务和定时器任务的优先级是最低的，所以在没有其他任务运行的时候，它们才会运行。  
}