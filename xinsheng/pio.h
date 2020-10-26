#ifndef _PIO_H_
#define _PIO_H_

//#define	h_zero	pin_08_h
//#define	m_zero	m_pin_08
//#define	zero	pin_08//

//#define	m_buz	m_pin_14
//#define	buz		pin_14

#define	m_buz	m_pin_07
#define	buz		pin_07

#define	m_temp_io	m_pin_12
#define	temp_io		pin_12

#define	m_heat	m_pin_08
#define	heat	pin_08

#define	m_led_com_1	m_pin_14
#define	led_com_1		pin_14

#define	m_led_com_2	m_pin_13
#define	led_com_2	pin_13

#define	m_led_com_3	m_pin_15
#define	led_com_3	pin_15

#define	m_led_com_4	m_pin_06
#define	led_com_4	pin_06//

#define	m_led_a	m_pin_16
#define	led_a	pin_16//

#define	m_led_b	m_pin_17
#define	led_b	pin_17//

#define	m_led_c	m_pin_18
#define	led_c	pin_18//

#define	m_led_d	m_pin_19
#define	led_d	pin_19//

#define	m_led_e	m_pin_20
#define	led_e	pin_20//

#define	m_led_f	m_pin_21
#define	led_f	pin_21//

#define	m_led_g	m_pin_23
#define	led_g	pin_23//

#define	m_led_dp	m_pin_05
#define	led_dp		pin_05//

//#define	h_kong	pin_06_h
//#define	m_kong	m_pin_06
//#define	kong	pin_06


#define		ERROR		1
#define		NO_ERROR	0

#define		on		0
#define		off	1
#define   ALLOFF    		0
#define		ALLON		0XFF
#define	_no	17
#define	_  17
#define	_u	22
#define	d_c	21
#define	_n	23
#define	_r	24
#define	_all	25
#define _p  0x10
#define	lcd_on	0
#define	lcd_off	1

#define	uchar	unsigned	char
#define	uint	unsigned	int
#define	ulong	unsigned	long




#define	sw_area_data	0x0040//按键灵敏度值设定//0x30
#define	sw_half_area_data	0x0020//0x20



#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10
#define BIT5  0x20
#define BIT6  0x40
#define BIT7  0x80

//***************************显示定义数码管LED灯相关宏设置************************************
#define SEGA	BIT0
#define SEGB	BIT1
#define SEGC	BIT2
#define SEGD	BIT3
#define SEGE	BIT4
#define SEGF	BIT5
#define SEGG   	BIT6
#define SEGH	BIT7

/*

#define SEGA	BIT7
#define SEGB	BIT5
#define SEGC	BIT3
#define SEGD	BIT1
#define SEGE	BIT0
#define SEGF	BIT6
#define SEGG    	BIT4
#define SEGH	BIT2
*/

#define NUM0    (SEGA|SEGB|SEGC|SEGD|SEGE|SEGF)
#define NUM1   	(SEGB|SEGC)
#define NUM2	(SEGA|SEGB|SEGD|SEGE|SEGG)
#define NUM3	(SEGA|SEGB|SEGC|SEGD|SEGG)
#define NUM4	(SEGB|SEGC|SEGF|SEGG)
#define NUM5	(SEGA|SEGC|SEGD|SEGF|SEGG)
#define NUM6	(SEGA|SEGC|SEGD|SEGE|SEGF|SEGG)
#define NUM7	(SEGA|SEGB|SEGC)
#define NUM8	(SEGA|SEGB|SEGC|SEGD|SEGE|SEGF|SEGG)
#define NUM9	(SEGA|SEGB|SEGC|SEGD|SEGF|SEGG)
#define NUMA	(SEGA|SEGB|SEGC|SEGE|SEGF|SEGG)
#define NUMB	(SEGC|SEGD|SEGE|SEGF|SEGG)
#define NUMC	(SEGA|SEGD|SEGE|SEGF)
#define NUMD	(SEGB|SEGC|SEGD|SEGE|SEGG)
#define NUME	(SEGA|SEGD|SEGE|SEGF|SEGG)
#define NUMF	(SEGA|SEGE|SEGF|SEGG)
#define NUMH	(SEGB|SEGC|SEGE|SEGF|SEGG)
#define NUMV	(SEGB|SEGC|SEGD|SEGE|SEGF)
#define NUM_	(SEGG)
#define NUMN	(SEGA|SEGB|SEGC|SEGE|SEGF)
#define NUM_C	(SEGA|SEGF|SEGG|SEGH)
#define NUM_U	(SEGC|SEGD|SEGE)
#define NUM_N	(SEGC|SEGE|SEGG)
#define NUM_R	(SEGE|SEGG)	
#define NUM_ALL	(SEGA|SEGB|SEGC|SEGD|SEGE|SEGF|SEGG|SEGH)

#pragma rambank0
extern	bit	init_flag;
extern	uchar	set_temp_data_1;
//extern	uchar	set_temp_data_2;
extern	uchar	temp_data;
extern	uchar	heat_gao_time;
extern	uchar	hummer_delay;
//extern	uchar	save_data_1;
//extern	uchar	save_data_2;
extern	uchar	zero_all_data;
extern	uchar	hummer_times_1;
extern	bit	save_flag;
extern	uchar	init_time;
extern	uchar	set_time_save_1;
extern	uchar	set_time_save_3;
extern	bit	kong_flag;
extern	bit	hummer_flag;
extern	uchar	hummer_off_time;
extern	uchar	error_data;
extern	bit	adc_end_flag;
//extern	uchar	test_init_time;
extern	uchar	display_step;

extern	uchar	display_temp3;
extern	uchar	display_temp4;
extern	uchar	disp_ad_data;

extern	bit	disp_all_flag;
extern	bit	disp_off_flag;
#endif
