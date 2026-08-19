#include "Int_Key.h"

Key_Type Int_Key_Scan()
{
    if (READ_KEY1 == GPIO_PIN_RESET || READ_KEY2 == GPIO_PIN_RESET || READ_KEY3 == GPIO_PIN_SET || READ_KEY4 == GPIO_PIN_SET) {
        HAL_Delay(10);
        if (READ_KEY1 == GPIO_PIN_RESET) {
            while (READ_KEY1 == GPIO_PIN_RESET);
            return KEY1;//按键1和2是上拉，空闲时是高电平
        } else if (READ_KEY2 == GPIO_PIN_RESET) {
            while (READ_KEY2 == GPIO_PIN_RESET);
            return KEY2;
        } else if (READ_KEY3 == GPIO_PIN_SET) {
            while (READ_KEY3 == GPIO_PIN_SET);
            return KEY3;//按键3和4是下拉，空闲时是低电平
        } else if (READ_KEY4 == GPIO_PIN_SET) {
            while (READ_KEY4 == GPIO_PIN_SET);
            return KEY4;
        }
    }
    return KEY_NONE;
}
