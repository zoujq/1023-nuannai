#include "BS84B08A-3.h"
#include <pio.h>
#include <touch.h>

uint	touch1_time_data(void);
uint	touch2_time_data(void);
uint	touch3_time_data(void);
uint	touch4_time_data(void);
uint	touch5_time_data(void);
uint	touch6_time_data(void);
uint	touch7_time_data(void);
uint	touch8_time_data(void);
void	touch_set(void);
void	touch_process(void);
extern	uchar WTH_1LinePWM(unsigned char cnt);
extern	void	_delay(uint	t);
extern	void data_init(void);
void	touch(void);
void	touch_process()
{


}
