
                #include    "USER_PROGRAM.H"
                #include	"io_init.h"
                #include	"pio.h"
                #include	"main.h"
              

extern	void	init_all();
extern	void	display(void);
void    clr_work_flag();
void	lcd_no();
void	sw_pre();
void	work();
extern	void	temp_pre(void);         
//==============================================
//**********************************************
//==============================================
#pragma vector  Interrupt_Extemal        @ 0x04
void Interrupt_Extemal()
{
_nop();	
	
}

#pragma vector timer_int @ 0x0c
void timer_int()
{
	_tf=0;//125us
    time_disp_2ms++;
    time_125us++;   
//hummer_flag=1;
	if(hummer_flag)
	{
		m_buz=0;
		buz=~buz;
	//	_acerl=0;//set an0 is ad
	//	_adcr0=0;//set an0 is ad		
	//	hummer_off_time=10;//100ms
	}
	else
	{
		buz=1;
	}
/*	if(kong==0)
	{
		if(kong_status_flag==0)
		{
			kong_status_flag=1;
			if(kong_50hz<200)kong_50hz++;
		}
	}
	else
	{
		kong_status_flag=0;
	}*/
/*	m_zero=1;
	if(zero==0)
	{
		if(zero_status_flag==0)
		{
			zero_status_flag=1;
			if(zero_status_times<200)zero_status_times++;
		}
		ac_off_100ms=0;
	}
	else
	{
		zero_status_flag=0;
		
	}*/
 	if(time_disp_2ms>=4)
 	{
 		time_disp_2ms=0;
 		display_flag=1;
 		display_step++;
 		if(display_step>=12)
 		{
 			display_step=0;
 		}

	
		
		led_com_1=1;
		led_com_2=1;
		led_com_3=1;
		led_com_4=1;
	//	m_led_com=1;
	
		led_a=0;
		led_b=0;
		led_c=0;
		led_d=0;
		led_e=0;
		led_f=0;
		led_g=0; 	
		led_dp=0;	
	 	if(display_step==1)
		{	
			
			if(display_temp1&0x01)
			led_com_1=0;
			if(display_temp2&0x01)
			led_com_2=0;
			if(display_temp3&0x01)
			led_com_3=0;
			if(display_temp4&0x01)
			led_com_4=0;
			led_a=1;
			
		}
		if(display_step==2)
		{	
			if(display_temp1&0x02)
			led_com_1=0;
			if(display_temp2&0x02)
			led_com_2=0;
			if(display_temp3&0x02)
			led_com_3=0;
			if(display_temp4&0x02)
			led_com_4=0;

			led_b=1;
		}
		if(display_step==3)
		{	
			if(display_temp1&0x04)
			led_com_1=0;
			if(display_temp2&0x04)
			led_com_2=0;
			if(display_temp3&0x04)
			led_com_3=0;
			if(display_temp4&0x04)
			led_com_4=0;
			led_c=1;
		}
		if(display_step==4)
		{	
			if(display_temp1&0x08)
			led_com_1=0;
			if(display_temp2&0x08)
			led_com_2=0;
			if(display_temp3&0x08)
			led_com_3=0;
			if(display_temp4&0x08)
			led_com_4=0;
			led_d=1;
		}
		if(display_step==5)
		{	
			if(display_temp1&0x10)
			led_com_1=0;
			if(display_temp2&0x10)
			led_com_2=0;
			if(display_temp3&0x10)
			led_com_3=0;
			if(display_temp4&0x10)
			led_com_4=0;
			led_e=1;
		}
		if(display_step==6)
		{	
			if(display_temp1&0x20)
			led_com_1=0;
			if(display_temp2&0x20)
			led_com_2=0;
			if(display_temp3&0x20)
			led_com_3=0;
			if(display_temp4&0x20)
			led_com_4=0;
			led_f=1;
		}
		if(display_step==7)
		{	
			if(display_temp1&0x40)
			led_com_1=0;
			if(display_temp2&0x40)
			led_com_2=0;
			if(display_temp3&0x40)
			led_com_3=0;
			if(display_temp4&0x40)
			led_com_4=0;
			led_g=1;
		}
		if(display_step==8)
		{
			if(disp_off_flag==0)
			{
				if(disp_dp_flag)
				{
					led_com_3=0;
					led_com_2=0;
				}
	
				if(work_mode==3)//恒温
				{
					led_com_1=0;
					if((set_delay>0)&&(time_500ms_flag==0))
					{
						led_com_4=1;
					}
					else
					led_com_4=0;
				}
				if(time_500ms_flag==0)
				{
					if((kong_flag==0)||(set_delay>0))//温控断开
					{
						led_com_1=1;
					}
				}
				if(init_time>0)
				{
					led_com_3=0;
					led_com_2=0;
					led_com_1=0;
					led_com_4=0;
				}
				if(disp_all_flag)
				{
					led_com_1=0;//恒温
					led_com_4=0;
	
				}
			}
		//	if((on_off_flag==1)&&(work_mode==0))led_com_4=1;//of
			led_dp=1;
		}
		if(display_step==9)
		{

		}
		if(display_step==10)
		{


		}
 	}
    if(time_125us >=80) //10ms
    {
        time_125us      =0;
        time_10ms++; 
        time_1s++; 
        if(hummer_off_time>0)hummer_off_time--;
        
        ac_off_100ms++;
       	if(ac_have_flag)
		{
			if(ac_off_100ms>=10)//100ms
			{
				hummer_delay=10;
			}
		}
        time_300ms++;
        time_250ms++;
        if(time_250ms>=25)
        {
        	time_250ms=0;
        	if(hummer_times>0)
        	{
        		if(hummer_error_1_time>2)
        		hummer_delay=5;
        		
        		if(hummer_error_1_time>0)hummer_error_1_time--;
        		else
        		{
        			hummer_times--;
        			hummer_error_1_time=4;
        		}
        	}
        	else
        	{
        		hummer_error_1_time=4;
        	}
        	if(hummer_times_1>0)
        	{
        		if(hummer_error_time==0)
        		{
        			hummer_times_1--;
        			hummer_error_time=10;
        		}
        		
        		if(hummer_error_time>=7)
        		{
        			if(hummer_times_1>0)
        			hummer_delay=5;
        		}
        		if(hummer_error_time>0)
        		{
        			hummer_error_time--;
        		}
        	}
        	else
        	{
        		hummer_error_time=10;
        	}
        }
        if(hummer_delay>0)
        {
        //	if(_eocb==0)
            hummer_flag=1;
            hummer_delay--;
        }
        else
        {
            hummer_flag=0;
        }
//        if(init_motor_delay>0)init_motor_delay--;
        
    }
    if(time_10ms >=10)//100ms
    {
        time_10ms=0;
//		if(test_init_time>0)test_init_time--;
        if(work_mode>0)
        {if(set_delay>0)set_delay--;}
        if(init_time>0)
        {
        	init_time--;
        }

    }
    
    if(time_300ms>=30)//0.3s
    {
    	time_300ms=0;
    } 
    
    if(time_1s>=50)//0.5s  //50
    {
        time_1s   =0;
                
        if(time_500ms_flag)time_500ms_flag=0;
        else  time_500ms_flag=1; 
        time_1min++;
//        if(heat_100_10s>0)heat_100_10s--;  
        if(time_1min>=120)//1min 120
        {
        	time_1min=0;
	       	error_time++;
        }
        time_1s_flag=~time_1s_flag;
        if(time_1s_flag)
        {
        	zero_err_delay_25s++;
        	error_kong_1min++;
        	heat_turn_time++;
        	if(disp_ad_data<=35)//进入间断加热
        	{
        		heat_turn_flag=1;
        	}
        	else
        	{
        		heat_turn_flag=0;
        	}
        	if(disp_ad_data>=26)//温度低 31
        	{
        		hummer_times_1=0;
        		kong_flag=1;
        		error_kong_1min=0;
        	}
        	else
        	{

        	//	if(zero_err_delay_25s>=25)
        	//	{
        	//		zero_err_delay_25s=25;
        		if(disp_ad_data<=25)//27
        		{
	        		if(work_flag)
	        		{
	        			if(kong_flag)
	        			{
	        				hummer_times_1=3;
	        			}
	        			if(error_kong_1min>=60)
	        			{
	        				if(on_off_flag)
	        				{
	        					on_off_flag=0;
	        					work_flag=0;
	        					hummer_times_1=1;
	        				}
	        				
	        			}
	        		}
	        		kong_flag=0;
        		}
	        	
        	}
 /*       	
        	if(zero_status_times<30)//无过零
        	{
        		hummer_times_1=0;
        		kong_flag=1;
        		error_kong_1min=0;
        	}
        	else
        	{
	        	if((kong_50hz>30))
	        	{
	        		hummer_times_1=0;
	        		kong_flag=1;
	        		error_kong_1min=0;
	        		ac_have_flag=1;
	        		zero_err_delay_25s=0;
	        	}
	        	else
	        	{
	        		if(zero_err_delay_25s>=25)
	        		{
	        			zero_err_delay_25s=25;
		        		if(work_flag)
		        		{
		        			if(kong_flag)
		        			{
		        				hummer_times_1=3;
		        			}
		        			if(error_kong_1min>=300)
		        			{
		        				if(on_off_flag)
		        				{
		        					on_off_flag=0;
		        					work_flag=0;
		        					hummer_times_1=1;
		        				}
		        				
		        			}
		        		}
		        		kong_flag=0;
	        		}
	        	}
        	}*/
        	zero_status_times=0;
        	kong_50hz=0;
        	heat_jian_time++;
        	if(on_off_flag)
			{
				work_off_delay++;
				if(set_delay==0)
				{
					if(kong_flag)
					{
						if(sub_second_flag)
						{
							work_run_second--;
							if(work_run_second>=60)
							{
								work_run_second=59;
		        				if(work_run_time>0)work_run_time--;
		        				if(work_2_run_time<21)
		        				work_2_run_time++;
							}
							work_time_1min++;
						}
					}
					if(work_time_1min>=60)//改60
					{
						work_time_1min=0;

					}
       		 		heat_gao_time++;
       		 		if(work_run_first_time>0)work_run_first_time--;
       		 	
				}
			}
        }
		if(heat_gao_time>=180)//15min
		{
			heat_gao_time=180;
		}        
    }     	  
	
}
//==============================================
//**********************************************
//==============================================
void USER_PROGRAM_INITIAL()
{
	uchar	i;
	_ctrl=0b00010000;//内部	16mhz	
	_papu=0b00000000;
	_pbpu=0;
	_pdpu=0;
//timer	
	_tmr=6;//70
	_tmrc=0b00010011;//0
	_te=1;
//ad
//	_acerl=0b00000000;//set an an2is ad
//	_adcr0=0b00000000;//set an2 is ad
//	_adcr1=0b00000100;//osc/16		
//intc1
	_intc1=0b0000000;
	_tbe=0;//关时基中断
//touch
//	_tkm0c0=0b00000000;//
//	_tkm0c1=0b00000000;//
//	_tkm1c0=0b00000000;//
//	_tkm1c1=0b00000000;//		
//intc0
	_intc0=0b00000000;
	_emi=0;//,总中断打开
	_inte=0;//外总中断打开
	_integ=0b00000000;//
	_ints1=0;_ints0=1;//下降沿中断
//wdt
	_wdtc=0b01010111;//wdt 开
	_te=1;//开定时中断
//io
	m_heat=0;

	heat=0;

	

	set_temp_data_1=40;
//		set_temp_data_2=40;
	temp_data=25;
//	save_data_1=0xaa;
//	save_data_2=0xaa;
	
	set_time_save_1=3;
	set_time_save_3=8;
	set_temp_data_1=37;

	hummer_delay=40;
	hummer_flag=1;
	init_time=10;//1s

	kong_flag=1;
	hummer_off_time=20;//100ms
	error_data=0;
	adc_end_flag=0;

	hummer_times_1=0;
	kong_flag=1;
	
//	test_init_time=20;//2s	
}

//==============================================
//**********************************************
//==============================================
void USER_PROGRAM()
{
    GET_KEY_BITMAP();

  if(DATA_BUF[0]==0x01)
  {
  	DATA_BUF[0]=0;
  	sw_data=1;
  }
  if(DATA_BUF[0]==0x02)
  {
  	sw_data=2;
  	DATA_BUF[0]=0;
  }  
  if(DATA_BUF[0]==0x04)
  {
  	sw_data=3;
  	DATA_BUF[0]=0;
  }
  if(DATA_BUF[0]==0x08)
  {
  	sw_data=4;
  	DATA_BUF[0]=0;
  }
 /* if(DATA_BUF[0]==0x00)  
  {
  	sw_delay_times=0;
  }*/
       _clrwdt();  

        if(display_flag)
        {        
           display_flag=0;
           if((display_step>10)&&(display_step<12))
           {
           	   display();
           }
           if((hummer_off_time==0)&&(init_time==0))
		   temp_pre(); 
		   if(init_time>0)error_data=0;
        }
 
       sw_pre();       
        work(); 
        
	

}

void	sw_pre()
{
	uchar	i;
	bit	add_sub_flag;
	add_sub_flag=0;
//	if(sw_pre_flag)
//	{
//		sw_pre_flag=0;
		if(sw_data==5)
		{
			sw5_flag=1;
		}
		if(sw_data==4)//开关
		{
			if(sw1_flag==0)
			{
				sw1_flag=1;
				work_time_1min=0;
				on_off_flag=~on_off_flag;
				if(on_off_flag)
				{
					set_delay=40;
					error_kong_1min=0;
					work_flag=0;
					work_mode=0;
					work_run_time=set_time_save_1;
				}
				time_500ms_flag=1;
				time_500ms=0;
				hummer_delay=30;
				work_run_second=0;
//				test_init_time=0;
				error_data=0;
			}
				
		}
		else	if(sw_data==3)//功能
		{
			if(sw4_flag==0)
			{
				sw4_flag=1;
				if(on_off_flag)
				{
					
					if(set_delay>0)
					{
						set_delay=40;
						hummer_delay=10;
						work_flag=0;
						work_mode++;
						if(work_mode>3)
						{
							work_mode=1;
						}
						if(work_mode==1)
						{
							work_run_time=set_time_save_1;
							work_run_second=save_time_second_1;
						}
						if(work_mode==2)
						{
							work_run_time=set_time_save_3;
							work_run_second=save_time_second_3;
						}
					//	work_run_second=0;
					}
					if(work_flag==1)
					{
						work_flag=0;
						set_delay=40;
						hummer_delay=10;
					}
				}
			}
		}
		else	if(sw_data==1)//+
		{
//			if(test_init_time>0)sw3_flag=1;
			if(work_mode>0)
			{
				if(sw3_flag==0)
				{
					sw3_flag=1;
					add_sub_flag=1;	
					if(work_flag)
					{
						hummer_times=2;
						time_250ms=250;
						hummer_delay=0;
					}									
				}
				else
				{
					sw_delay_times++;
					if(sw_delay_times>250)
					{
						sw_delay_times=180;
						add_sub_flag=1;
					}
					time_500ms_flag=1;
					time_1s=0;
				}
			}
			if(add_sub_flag)
			{
				
				if((work_flag==0)&&(work_mode>0))
				{
					if(sw_delay_times<80)
						hummer_delay=10;
					work_time_1min=0;
					if(work_mode==3)
					{
						if(set_temp_data_1<45)
						set_temp_data_1+=1;
						else
						set_temp_data_1+=5;
						if(set_temp_data_1>85)
						set_temp_data_1=35;
						set_delay=40;
					//	time_500ms_flag=1;
						work_off_5min=0;
					}
					else
					{
						work_run_second+=30;
						if(work_run_second>=60)
						{
							work_run_second=0;
							work_run_time++;
							if(work_run_time>16)
							work_run_time=1;
						}
						else	if(work_run_second>30)
						{
							work_run_second=30;
						}
						if((work_run_time==0)&&(work_run_second>0))
						{
							work_run_time=1;work_run_second=0;
						}	
						if((work_run_time>=16)&&(work_run_second>0))
						{
							work_run_time=1;work_run_second=0;
						}						
						if(work_mode==1)
						{
							set_time_save_1=work_run_time;
							save_time_second_1=work_run_second;
						}
						else
						{
							set_time_save_3=work_run_time;
							save_time_second_3=work_run_second;
						}
						
						set_delay=40;
						time_1s=0;
						time_500ms_flag=1;
						work_off_5min=0;					
					}
				}
	
			}
		}
		else	if(sw_data==2)//-
		{
			if(work_mode>0)
			{
				if(sw4_flag==0)
				{
					sw4_flag=1;
					add_sub_flag=1;
					if(work_flag)
					{
						hummer_times=2;
						time_250ms=250;
						hummer_delay=0;
					}					
				}
				else
				{
					sw_delay_times++;
					if(sw_delay_times>250)
					{
						sw_delay_times=180;
						add_sub_flag=1;
					}
				}
			}
			
			if(add_sub_flag)
			{

				if((work_flag==0)&&(work_mode>0))
				{
					if(sw_delay_times<80)
						hummer_delay=10;
					work_time_1min=0;
					if(work_mode==3)
					{
						if(set_temp_data_1<=45)
						set_temp_data_1-=1;
						else
						set_temp_data_1-=5;
						if(set_temp_data_1<35)
						set_temp_data_1=85;
						work_off_5min=0;
					}
					else
					{
						if((work_run_second==0)||(work_run_second==30))
						{
							work_run_second-=30;
						}
						else	if(work_run_second>30)
						{
							work_run_second=30;
						}
						else
						{
							work_run_second=0;
						}
						if(work_run_second>=60)
						{
							work_run_second=30;
							work_run_time--;
						//	if(work_run_time==0)
						//	work_run_time=16;
						}
						if((work_run_time==0))
						{
							work_run_time=16;work_run_second=0;
						}
						if(work_mode==1)
						{
							set_time_save_1=work_run_time;
							save_time_second_1=work_run_second;
						}
						else
						{
							set_time_save_3=work_run_time;
							save_time_second_3=work_run_second;
						}
						work_off_5min=0;					
					}
					set_delay=40;
					time_1s=0;
					time_500ms_flag=1;
				}
				
			}			
		}
		if(sw_data==0)
		{
			sw1_flag=0;sw2_flag=0;sw3_flag=0;sw4_flag=0;sw5_flag=0;
			sw_delay_times=0;	
		}
		
		sw_data=0;

//	}

}

void	work()
{
	uchar	temp_8,i;
	uint	temp_16;
	m_buz=0;
	m_heat=0; 
	
/*	
	set_temp_data_1=set_temp_data_1_save;
	set_temp_data_1_save=set_temp_data_1;
	
	temp_16=set_temp_data_1;
	
	temp_16=temp_16-32;
	temp_16=temp_16*5;
	temp_16=temp_16/9;
	set_temp_data_1=temp_16;*/
//	m_kong=1;
//	h_zero=1;
	if(error_data>0)
	{
		heat=0;
		return;
	}
	if(on_off_flag)
	{
		if(work_mode==0)
		{
			if(work_off_delay>=300)//5min
			{
				work_off_delay=0;
				on_off_flag=0;
			}
		}
		else
		{
			work_off_delay=0;
		}
		if(set_delay==0)
		{
			if(work_mode>0)
			{
				if(work_flag==0)
				{
					work_flag=1;
					hummer_delay=30;
					time_1min=0;
					time_1s_flag=0;
					/*
					if((work_run_second>0)&&(work_run_second<=30))
					work_run_second=30;
					else
					work_run_second=0;*/
				}
			}
			else
			{
				work_flag=0;	
			}
			if(work_mode==0)
			{
				heat_flag=0;
			}
			else
			{
				work_off_5min=0;
			}
			if((work_mode==1)||(work_mode==2))
			{
				heat_flag=1;
				if((work_run_time==0)&&(work_run_second==0))
				{
				//	hummer_delay=20;
					work_mode=0;
					hummer_times=2;
					time_250ms=0;
					on_off_flag=0;
				}
			}
			if(work_mode==3)
			{
				if(work_run_step==0)
				{
					work_run_step=1;
					temp_8=0;
					if(set_temp_data_1>=temp_data)
					{
						temp_8=set_temp_data_1-temp_data;
					}
					temp_8/=5;//5
				//	work_run_first_time=temp_8*16;//16
					for(i=0;i<7;i++)
					work_run_first_time+=temp_8;//5
				/*	work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5
					work_run_first_time+=temp_8;//5*/
					if(temp_data>=(set_temp_data_1+3))
					{
						work_run_step=2;
						work_run_first_time=0;
					}
				}
				if(work_run_step==1)
				{
					heat_flag=1;
					if(work_run_first_time==0)
					{
						work_run_step=0;
						if(temp_data>=set_temp_data_1)
						{
							work_run_first_time=0;
							work_run_step=2;
						}
					}
					work_2_run_time=0;
				}
				if(work_run_step==2)
				{
					
				//	if(work_2_run_time<=10)
				//	{
					temp_8=1;
					if(set_temp_data_1>=70)
						temp_8=5;
				//	}
				/*	else	if(work_2_run_time<=15)
					{
						temp_8=2;
					}
					else
					{
						temp_8=0;
					}*/
					if(temp_data<=(set_temp_data_1+temp_8))
					{
						if(work_run_first_time==0)
						work_run_first_time=10;
					}					
					
					if(work_run_first_time>0)
					heat_flag=1;
					else
					heat_flag=0;
					
				}
		/*		if(temp_data>=set_temp_data_1)
				{
					heat_flag=0;
					heat_jian_time=0;
					heat_jian_start_flag=0;
				}
				else	if(temp_data<=(set_temp_data_1-3))
				{
					heat_flag=1;
					heat_jian_start_flag=1;
					if(temp_data>=(set_temp_data_1-7))
					{
						if(heat_jian_time<=5)
						heat_flag=1;
						else	if(heat_jian_time<=25)
						heat_flag=0;
						else
						heat_jian_time=0;	
					}	
					else
					{
						heat_jian_time=25;
					}				
				}
				else	if(heat_jian_start_flag)
				{
					if(temp_data>=(set_temp_data_1-7))
					{
						if(heat_jian_time<=5)
						heat_flag=1;
						else	if(heat_jian_time<=25)
						heat_flag=0;
						else
						heat_jian_time=0;	
					}	
					else
					{
						heat_jian_time=25;
					}	
				}*/

			}
			sub_second_flag=1;
		}
		else
		{
			sub_second_flag=0;
			heat_gao_time=0;
			work_time_1min=0;
			work_flag=0;
			heat_flag=0;
			work_run_step=0;
			work_run_first_time=0;
			work_2_run_time=0;
		}
		if(kong_flag==0)//温控断开
		{
			if(error_4_time_3min>=180)//3min
			{
				error_4_time_3min=0;
				on_off_flag=0;
				heat=0;
			}
		}
		else
		{
			error_4_time_3min=0;
		}
	}
	else
	{
		heat_gao_time=0;
		heat_flag=0;
		work_flag=0;
		work_off_delay=0;
	}
	if(heat_flag)
	{
		if(kong_flag)
		{
			if(heat_turn_flag)//温度高，间断加热
			{
				if(heat_turn_time<=11)
				heat=0;
				else	if(heat_turn_time<=22)
				heat=1;
				else
				heat_turn_time=1;
			}
			else
			{
				heat_turn_time=1;
				heat=1;
			}
		}
		else
		heat=0;
	}
	else
	{
		heat=0;
	}	
	
	if(hummer_delay>0)
	{
		hummer_off_time=10;//100ms
	}	
//	if(test_init_time>0)
//	{
//		if(sw5_flag)
//		heat=1;
//	}
}



