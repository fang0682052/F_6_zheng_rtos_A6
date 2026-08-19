#ifndef __INT_KEY_H__
#define __INT_KEY_H__
#include "gpio.h"
#define READ_KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define READ_KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)
#define READ_KEY3 HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin)
#define READ_KEY4 HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin)

typedef enum {
    KEY1,
    KEY2,
    KEY3,
    KEY4,
    KEY_NONE
} Key_Type;

Key_Type Int_Key_Scan(void);

#endif /* __INT_KEY_H__ */
