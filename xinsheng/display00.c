#include "BS84B08A-3.h"
#include	"io_init.h"
#include	"pio.h"
#include	"display.h"

void	display(void);
void	clr_display(void);
void	display_bit(void);
void	disp_pre_1(void);





void	display(void)
{

	bit	disp_t_flag;
	



	uchar	i;
	_clrwdt();
	


		
	if(work_mode==0)
	{
		if(work_off_5min>=5)
		{
			work_off_5min=0;
			on_off_flag=0;
		}
	}
	else
	{

			
		if(work_mode==3)//温度
		{
			sw_temp=set_temp_data_1;
			if(sw_temp>=100)
			{
				display_2_data=1;
				sw_temp-=100;
			}
			else
			{
				display_2_data=0;
			}
			display_3_data=sw_temp/10;
			display_4_data=sw_temp%10;
			display_1_data=_no;
			if(display_2_data==0)
			{
				display_2_data=_no;
				if(display_3_data==0)
				{
					display_3_data=_no;
				}
			}
		//	display_4_data=0x0f;
			disp_dp_flag=0;
		}
		else
		{
			sw_temp=work_run_time;
			if(work_run_time>=10)
			{
				sw_temp=work_run_time-10;
				display_1_data=1;
			}
			else
			{
				display_1_data=_no;
			}
			display_2_data=sw_temp;
	
			display_3_data=work_run_second/10;
			display_4_data=work_run_second%10;
			
			disp_dp_flag=time_500ms_flag;
		}

		if(time_500ms_flag==0)
		{

		//	display_4_data=0x0f;
			disp_dp_flag=0;			
			
			if((kong_flag==0)||(set_delay>0))//温控断开
			{
				display_1_data=_no;
				display_2_data=_no;
				display_3_data=_no;
				display_4_data=_no;

			}
//
/*			sw_temp=temp_data;
			if(sw_temp>=100)
			{
				display_2_data=1;
				sw_temp-=100;
			}
			else
			{
				display_2_data=0;
			}*/
			
/*			i=temp_data/100;
			display_2_data=i;
			i=temp_data%100;
			display_3_data=i/10;
			display_4_data=i%10;
			
/*
			i=disp_ad_data/100;
			display_2_data=i;
			i=disp_ad_data%100;
			display_3_data=i/10;
			display_4_data=i%10;
			
			*/		
			/*	
			display_1_data=_no;
			if(display_2_data==0)
			{
				display_2_data=_no;
				if(display_3_data==0)
				{
					display_3_data=_no;
				}
			}		
			*/
			
		}

	}
	
	
	if(init_time==0)
	{
		if(error_data>0)
		{
			display_1_data=_no;
			display_2_data=0x0e;
			display_3_data=error_data;
			display_4_data=_no;
			disp_dp_flag=0;
		}
	}
	clr_display();
	_clrwdt();

	//display_temp1=display_table[display_1_data];
	display_temp1=0;	
	if(display_1_data!=_no)display_temp1|=0b00110000;
	if(work_mode==1)display_temp1|=0b00000001;//快速加热
	if(work_mode==3)
	{
		display_temp1|=0b10000000;//恒温
	//	display_temp1|=0b01000000;
	}
	if(work_mode==2)
	{
		display_temp1|=0b00001000;//消毒
	}
	if(time_500ms_flag==0)
	{
		if((kong_flag==0)||(set_delay>0))//温控断开
		{
			display_temp1=0;
		}
	}
	display_temp2=display_table[display_2_data];
	display_temp3=display_table[display_3_data];
	display_temp4=display_table[display_4_data];
	disp_all_flag=0;disp_off_flag=0;
	if(init_time>0)
	{
		disp_all_flag=1;
	}
	else	if((on_off_flag)&&(work_mode==0))
	{
		if(time_500ms_flag)
		{
			disp_all_flag=1;
		}	
		else
		{
			disp_off_flag=1;
		}
	}
	else	if(on_off_flag==0)
	{
		disp_off_flag=1;
	}
	if(disp_all_flag)
	{
		display_temp1=0xff;display_temp2=0xff;display_temp3=0xff;display_temp4=0xff;
		disp_dp_flag=1;	
	}
	if(disp_off_flag)
	{
		display_temp1=0;display_temp2=0;display_temp3=0;display_temp4=0;
		disp_dp_flag=0;
	}
	clr_display();
	_clrwdt();
				
//------------------------------------	
}

void	clr_display(void)
{	
//	hummer_delay=10;
	m_led_com_1=0;
	m_led_com_2=0;
	m_led_com_3=0;
	m_led_com_4=0;
	m_led_a=0;
	m_led_b=0;
	m_led_c=0;
	m_led_d=0;
	m_led_e=0;
	m_led_f=0;
	m_led_g=0;
	m_led_dp=0;
	
	led_com_1=1;
	led_com_2=1;
	led_com_3=1;
	led_com_4=1;

	led_a=0;
	led_b=0;
	led_c=0;
	led_d=0;
	led_e=0;
	led_f=0;
	led_g=0;
	led_dp=0;
}

