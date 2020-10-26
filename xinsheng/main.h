#ifndef _main_H_
#define _main_H_


/*****************************************/
const unsigned char CoilTab[]={0x3F,0x06,0x5B,
0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,
0x5E,0x79,0x71,0x73,0x00,

};


#pragma rambank0
//uchar	save_data_1;
//hummer
bit	sw11_flag;
bit	hummer_flag;
bit	fre_1_flag;
//uchar	zero_add_times;
uchar	hummer_delay;
//display
uchar	time_disp_2ms;
bit	display_flag;
bit	time_1s_flag;
//work
bit	on_off_flag;
uchar	error_data;
//uchar	display_turn;
//uchar	disp_turn_step;
bit	temp_100_flag;//100度
//uchar	power_step;
bit	power_flag;
uchar	hummer_times;
//uchar	ding_time;
bit		temp_flag;
bit		set_flag;
uchar	set_time_delay;
bit	time_flag;
uchar	bao_temp_data;
bit	bao_flag;
//uchar	temp_same;
//uchar	temp_same_time;
uchar	on_bao_set_temp;
bit		on_bao_set_flag;
//temp
uchar	temp_data;
//time
uchar	time_500ms;
uchar	time_2ms;
bit	display_500ms_flag;
uchar	time_10ms;
//uchar	time_200ms;
bit	hummer_1_flag;
uchar	time_1min;
uchar	time_100ms;
//uchar	time_2s;
bit	time_2s_flag;
//uchar	add_water_temp_data;
//sw
bit	sw1_flag;
bit   sw2_flag;
bit   sw3_flag;
bit   sw4_flag;
bit	sw5_flag;
bit		sw22_flag;
//bit   led_r_flag;
bit		led_g_flag;
bit	led_b_flag;
uchar	sw_data;
//uchar	sw_add_time;
//uchar	sw_data_same;
//uchar	sw_data_times;
//
//uchar	hummer_time_delay;

//uchar	error_data_times;
uchar	init_time;
uchar	sw_long_time;

//
bit	dis_temp_flag;
bit	dis_time_flag;
bit	dis_power_flag;
bit	dis_led_flag;

bit	zero_status_flag;
uchar	zero_status_times;

//zero
//uchar	after_zero_count;
bit	pin_pre_status;
//uchar	zero_delay_out;
//uchar	zero_delay_set;
uchar	work_mode;

bit	out_1_flag;
bit	heat_flag;
bit	heat_100_flag;




bit	power_onoff_flag;
//uchar	temp_time_100_add;
//uchar	temp_99_times;
//uchar    display_1;
uchar	hummer_off_time;


uchar	display_1;
uchar	display_2;

		
uchar	work_step;
uchar	time_125us;
uchar	time_1s;
uchar	temp_8;
//uchar	init_motor_delay;
bit	clr_disp_flag;
bit	work_flag;
bit	dian_flag;
bit	out_flag;
bit	time_500ms_flag;
bit	init_flag;
bit	sw_pre_flag;
bit	heat_bao_flag;
bit	work_lu_flag;

//uchar	work_start_3s;
//uchar	zero_all_data;
uchar	set_delay;
uchar	set_temp_data_1;
uchar	set_temp_data_1_save;
//uchar	set_temp_data_2;
uchar	time_300ms;
uchar	error_time;
uchar	time_1min;
uchar	heat_gao_time;
uchar	work_off_5min;
uchar	sw_delay_times;
uchar	work_run_time;
uchar	work_run_second;
uchar	work_2_run_time;
//uchar	save_data_2;

uchar	display_temp1;
uchar	display_temp2;
bit		pro_mode_flag;//选择是车用，还是民用
extern	uchar	temp_save_data;
extern	bit	touch_time_500ms_flag;
uchar	display_step;
uchar	work_time_1min;
uchar	time_250ms;
uchar	hummer_times_1;
uchar	hummer_error_time;
uchar	hummer_error_1_time;
bit	heat_jian_start_flag;

uchar	heat_jian_time;

uchar	set_time_save_1;
uchar	set_time_save_3;

bit		led1_flag;
bit		led2_flag;
bit		led3_flag;

bit	touch_long_flag;
uchar	work_run_step;
uint	work_run_first_time;
bit	kong_status_flag;
uchar	kong_50hz;
bit	kong_flag;
uchar	error_4_time_3min;
uint	error_kong_1min;
bit	ac_have_flag;

uchar	ac_off_100ms;

uchar	zero_err_delay_25s;
//uchar	test_init_time;
extern	bit	disp_dp_flag;
uchar	disp_ad_data;
uint	work_off_delay;
bit	heat_turn_flag;
uchar	heat_turn_time;

bit	sub_second_flag;
uchar	save_time_second_1;
uchar	save_time_second_3;
#endif

/*
const	unsigned	int	temp_table[112]={
 
127,
133,
140,
147,
154,
161,
169,
176,
184,
193,
201,
211,
222,
233,
245,
258,
271,
284,
297,
310,
322,
333,
344,
355,
367,
379,
393,
408,
423,
440,
459,
479,
501,
522,
539,
555,
570,
585,
606,
633,
653,
682,
705,
729,
753,
778,
804,
830,
856,
883,
907,
938,
965,
993,
1020,
1047,
1073,
1099,
1125,
1149,
1207,
1238,
1269,
1301,
1332,
1363,
1395,
1427,
1459,
1491,
1523,
1556,
1588,
1621,
1653,
1684,
1719,
1754,
1789,
1824,
1859,
1893,
1928,
1962,
1996,
2030,
2063,
2096,
2129,
2161,
2194,
2227,
2259,
2293,
2326,
2360,
2390,
2420,
2450,
2479,
2509,
2538,
2566,
2595,
2623,
2652,
2680,
2708,
2735,
2762,
2789,	 
2815
};
*/

const	uchar	power_center[11]=
{
0,
55,// 100w  1  108=21
48,// 200w  1  108=21
43,// 300w  2  90=31
38,// 400w  3  85=32
33,// 500w  4 80=34
28,// 600w 5 75=35
21,// 700w 6
9,// 800w 7
};

