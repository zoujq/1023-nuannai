#include <BS84B08A-3.h>
#include	"io_init.h"
#include	"pio.h"
#include	"temp.h"

void	temp_pre(void);
void	temp_pre(void)
{
//---------------------温度处理-------------

	unsigned	char	i,k;
	uchar	adc_data;

	extern	uchar	error_data;
	extern	uchar	temp_data;
//	extern	bit	hummer_flag;
	uchar	temp_temp_data;
	_clrwdt1();
	_clrwdt2();

	if(adc_end_flag==0)
	{
	//	_papu=0x01;
		_pdpu=0;
		m_temp_io=1;		
		_adcr1=0b00000100;//osc/16
		_acerl=0b00000010;//set an an1 is ad
		_adcr0=0b00000001;//set an1 is ad
		
		_adrh=0;
		_adrl=0;	
		_start=0;
		_start=1;
		_start=0;//start ad change
		
		while(_eocb)
		{
			_clrwdt();
		//	if(hummer_flag==1)
		//	{
		//		return;
		//	}
		}

		adc_data=_adrh;
	//	adc_data<<=4;
	//	i=_adrl;
	//	i>>=4;
	//	adc_data+=i;
		
		adc_data_end+=adc_data;
		adc_8_times++;
		if(adc_8_times>=32)/*adc_8_times>=8*/
		{
			adc_8_times=0;
			temp_temp_data=adc_data_end/32;	
			adc_data_end=0;
			adc_end_flag=1;
		}
	}	
	if(adc_end_flag)//处理温度值
	{		
		adc_end_flag=0;
		disp_ad_data=temp_temp_data;
		for(i=0;i<105;i++)
		{
			if(temp_temp_data>=temp_table_all[i])
			{
				if(i>1)
				{
					if(i<temp_data)
					{
						if(temp_temp_data>=(temp_table_all[i]-2))
						temp_data=i;
					}
					else
					{
						k=i-temp_data;
						if((temp_temp_data<=(temp_table_all[i]+2))||k>=2)
						temp_data=i;
					}
				}
				else
				temp_data=i;
				break;
			}
		}
		if(i>=100)
		{
			temp_data=100;
		}
		if(temp_temp_data<=6)//20
		{
			error_data=1;
		}
		if(temp_temp_data>=250)
		{
			error_data=2;
		}
		
		if(temp_temp_data<=16)//干烧 160度
		{
			if(error_data==0)
			{
			//	hummer_times_1=4;
			//	error_data=3;
			}
		}
	//	temp_data+=2;
		if(temp_data>80)
		{
			i=0;
			if(temp_data>temp_save_data)
			i=temp_data-temp_save_data;
			if(i>0)
			{
				temp_save_data=temp_data;
				heat_gao_time=0;
			}	
		}
		else
		{
			temp_save_data=temp_data;
			heat_gao_time=0;
		}
	/*	temp_temp_data=temp_data;
		temp_temp_data=temp_temp_data*9;
		temp_temp_data=temp_temp_data/5;
		temp_data=temp_temp_data+32;*/
		
		adc_data_end=0;
		
		/*
		for(i=0;i<9;i++)
		{
			adc_data_end+=temp_data;
		}
		temp_data=0;
		
		while(1)
		{
			if(adc_data_end>=5)
			{
				temp_data++;
				adc_data_end-=5;
				_clrwdt();
			}
			else
			{
				break;
			}
		}
		temp_data+=32;*/
		adc_data_end=0;
	//	error_data=0;
	}	
}

