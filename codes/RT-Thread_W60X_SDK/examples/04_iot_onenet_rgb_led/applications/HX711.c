/*
  Copyright (c) 2009 Dave Gamble

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

/* HX711 */

#include <rtthread.h>
#include <rtdevice.h>
#include "bsp.h"

int HX711_init(void)
{
	rt_pin_mode(PIN_HX711_SCK, PIN_MODE_OUTPUT);
	rt_pin_mode(PIN_HX711_DT, PIN_MODE_INPUT_PULLUP);
}

unsigned int HX711_read(void)
{
	unsigned int count;
	unsigned char i;
	
	while (rt_pin_read(PIN_HX711_DT));
	for (i=0; i<24; i++)
	{
		rt_pin_write(PIN_HX711_SCK, PIN_HIGH);
		count = count<<1;
		rt_pin_write(PIN_HX711_SCK, PIN_LOW);
		if (rt_pin_read(PIN_HX711_DT))
		{
			count++;
		}
	}
	rt_pin_write(PIN_HX711_SCK, PIN_HIGH);
	count = count^0x800000;
	rt_pin_write(PIN_HX711_SCK, PIN_LOW);
	
	return count;
}


