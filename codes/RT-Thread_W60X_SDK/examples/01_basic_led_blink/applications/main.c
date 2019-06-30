/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-02-13     tyx          first implementation
 */

#include <rtthread.h>
#include <rtdevice.h>

/* using BLUE LED in RGB */
#define LED_PIN     (23)
#define LED1_PIN    (19)
#define LED2_PIN    (20)
#define LED3_PIN    (21)
#define LED4_PIN    (22)

int main(void)
{
    unsigned int count = 1;
    /* set LED pin mode to output */
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED2_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED3_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED4_PIN, PIN_MODE_OUTPUT);
	
    while (count > 0)
    {
        /* led on */
        rt_pin_write(LED_PIN, PIN_LOW);
		rt_pin_write(LED1_PIN, PIN_LOW);
		rt_pin_write(LED2_PIN, PIN_LOW);
		rt_pin_write(LED3_PIN, PIN_LOW);
		rt_pin_write(LED4_PIN, PIN_LOW);
        rt_kprintf("led on, count: %d\n", count);
        rt_thread_mdelay(1000);

        /* led off */
        rt_pin_write(LED_PIN, PIN_HIGH);
		rt_pin_write(LED1_PIN, PIN_LOW);
		rt_pin_write(LED2_PIN, PIN_LOW);
		rt_pin_write(LED3_PIN, PIN_LOW);
		rt_pin_write(LED4_PIN, PIN_LOW);
        rt_kprintf("led off\n");
        rt_thread_mdelay(1000);

        count++;
    }

    return 0;
}
