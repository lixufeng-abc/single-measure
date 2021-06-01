/**********************************
ϵͳ�δ�ʱ������ÿ������֮֡���ж���ʱ
**********************************/

#include "SysTick.h"
#include "misc.h"


static u8  fac_ns=0;							//ns��ʱ������			   

//��ʼ���ӳٺ���
//SYSTICK��ʱ�ӹ̶�ΪAHBʱ��
//SYSCLK:ϵͳʱ��Ƶ��
void SysTick_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK); 
	fac_ns=SystemCoreClock/84000000;						//��Լ12ns   
}								    
 
 
//��ʱnus
//nusΪҪ��ʱ��us��.		    								   
void delay_ns(u32 nns)
{		
	u32 temp;	    	 
	SysTick->LOAD=nns*fac_ns; 					//ʱ�����	  		 
	SysTick->VAL=0x00;        					//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����	  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;      					 //��ռ�����	 
}


/****************
�����ѯ��ʱ������8Ϊһ��SPIͨ������96ns
****************/
//void SysTick_Delay_Us( __IO uint32_t ns)
//{
// uint32_t i;
// SysTick_Config(2);		// 12ns

// for (i=0; i<ns; i++) 
//	{
// // ����������ֵ��С��0 ��ʱ��CRTL �Ĵ�����λ16 ����1
// while ( !((SysTick->CTRL)&(1<<16)) );
//  }
// // �ر�SysTick ��ʱ��
// SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
//}

/********************* end file *******************************/

