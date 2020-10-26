#ifndef _display_H_
#define _display_H_

//unsigned long __ROM  

const	unsigned	char	display_table[33]=
{0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
0x7c,//b
0x00,//no
0x73,//p
0x04,0x06,0x07,0x27,0x37,0x3f,
0x10,0x30,0x31,0x33,0x37,0x3f,
0x5c,//31
0x5d,//32
};

#pragma rambank0

bit	disp_all_flag;
bit	disp_off_flag;

bit	disp_dp_flag;
uchar	display_1_data;
uchar	display_2_data;
uchar	display_3_data;
uchar	display_4_data;
uchar	display_temp3;
uchar	display_temp4;
uchar	sw_temp;


bit	sw_h_status_flag;

extern	uchar	sw_data;
extern	uchar	display_step;
extern	uchar	sw_long_time;
extern	bit	on_off_flag;
extern	uchar	work_time;
extern	bit	work_flag;
extern	bit	time_500ms_flag;
extern	bit	time_200ms_flag;
extern	uchar	disp_59;
extern	bit	error_flag;
extern	bit	get_h_flag;
extern	bit	time_1s_flag;
extern	uchar	zero_1s;
extern	uchar	error_data;
extern	bit	set_temp_time_flag;
extern	uchar	set_temp_data_1;

extern	uchar	display_temp1;
extern	uchar	display_temp2;

extern	uchar	work_mode;
extern	uchar	work_off_5min;
extern	uchar	set_delay;
extern	uchar	work_run_time;
extern	uchar	work_run_second;
extern	bit		led1_flag;
extern	bit		led2_flag;
extern	bit		led3_flag;


#endif