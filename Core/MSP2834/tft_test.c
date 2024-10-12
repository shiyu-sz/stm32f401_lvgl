
#include <stdio.h>
#include "ili9341.h"
#include "common.h"
#include "ili9341_gui.h"
#include "touch.h"

void lcd_test()
{
	delay_ms(1000);	
	//绘制固定栏up
	LCD_Clear(WHITE);
	LCD_Fill(0,0,lcddev.width,20,BLUE);
	//绘制固定栏down
	LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
	POINT_COLOR=WHITE;
	Gui_StrCenter(0,2,WHITE,BLUE,"test app",16,1);//居中显示
	Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.lcdwiki.com",16,1);//居中显示
	Gui_StrCenter(0,30,RED,BLUE,"1234",16,1);//居中显示
	Gui_StrCenter(0,60,RED,BLUE,"abcde",16,1);//居中显示	
	Gui_StrCenter(0,90,BRED,BLUE,"2.8\" IPS ILI9341 240X320",16,1);//居中显示
	Gui_StrCenter(0,120,BLUE,BLUE,"xiaoFeng@QDtech 2023-05-20",16,1);//居中显示
	delay_ms(2000);	
}

void Touch_Button_Test(void)
{  
	LCD_Clear(WHITE);
	LCD_Fill(0,0,lcddev.width,20,BLUE);
	LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
	POINT_COLOR=WHITE;
	Gui_StrCenter(0,2,WHITE,BLUE,"touch test 1",16,1);
	Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.lcdwiki.com",16,1);
		
	POINT_COLOR = BLACK;
	LCD_DrawRectangle(lcddev.width/2-50, 35, lcddev.width/2+50, 85);
	POINT_COLOR = RED;
	LCD_DrawFillRectangle(lcddev.width/2-49, 36, lcddev.width/2-1, 84);
	POINT_COLOR = BLUE;
	LCD_DrawFillRectangle(lcddev.width/2, 36, lcddev.width/2+49, 84);
	POINT_COLOR = WHITE;
	LCD_ShowString(lcddev.width/2-32,52,16,"ON",1);	
	POINT_COLOR = GRAY;
	LCD_FillRoundRectangle(lcddev.width/2-110, 115, lcddev.width/2+110, 134,10);
	POINT_COLOR = BRED;
	LCD_FillRoundRectangle(lcddev.width/2-110, 115, lcddev.width/2+10, 134,10);
	gui_circle(lcddev.width/2, 125,DARKBLUE,10, 1);
	//POINT_COLOR = BLACK;
	//BACK_COLOR=WHITE;
	//LCD_ShowString(lcddev.width/2-125,152,16,"0",1);
	//LCD_ShowString(lcddev.width/2+115,152,16,"100",1);
	POINT_COLOR = RED;
	LCD_ShowNum(lcddev.width/2-12,95,50,3,16);
	POINT_COLOR = BLACK;
	LCD_DrawRoundRectangle(lcddev.width/2-30, 180, lcddev.width/2+30, 210,8); 
	POINT_COLOR = LGRAYBLUE;
	LCD_FillRoundRectangle(lcddev.width/2-29, 181, lcddev.width/2+29, 208,7);
	POINT_COLOR = MAGENTA;
	LCD_ShowString(lcddev.width/2-15,187,16,"EXIT",1);
	Show_Str(lcddev.width/2-47,155,RED,WHITE,"EXIT",16,1);
	while(1)
	{
		tp_dev.scan();
		if((tp_dev.sta)&(1<<0))	//判断是否有点触摸�?????
		{
			if((tp_dev.y[0]>35)&&(tp_dev.y[0]<85))
			{
				if((tp_dev.x[0]>(lcddev.width/2-50))&&(tp_dev.x[0]<(lcddev.width/2-1)))
				{
						POINT_COLOR = RED;
						LCD_DrawFillRectangle(lcddev.width/2-49, 36, lcddev.width/2-1, 84);
						POINT_COLOR = BLUE;
						LCD_DrawFillRectangle(lcddev.width/2, 36, lcddev.width/2+49, 84);
						POINT_COLOR = WHITE;
						LCD_ShowString(lcddev.width/2-32,52,16,"ON",1);	
				}
				if((tp_dev.x[0]>(lcddev.width/2))&&(tp_dev.x[0]<(lcddev.width/2+50)))
				{
						POINT_COLOR = BLUE;
						LCD_DrawFillRectangle(lcddev.width/2-49, 36, lcddev.width/2-1, 84);
						POINT_COLOR = RED;
						LCD_DrawFillRectangle(lcddev.width/2, 36, lcddev.width/2+49, 84);
						POINT_COLOR = WHITE;
						LCD_ShowString(lcddev.width/2+13,52,16,"OFF",1);	
				}
			}	
			if((tp_dev.x[0]>=(lcddev.width/2-100))&&(tp_dev.x[0]<=(lcddev.width/2+100))&&(tp_dev.y[0]>115)&&(tp_dev.y[0]<134))
			{
					POINT_COLOR = GRAY;
					LCD_FillRoundRectangle(tp_dev.x[0]-10, 115, lcddev.width/2+110, 134,10);
					POINT_COLOR = BRED;
					LCD_FillRoundRectangle(lcddev.width/2-110, 115, tp_dev.x[0]+10, 134,10);
					gui_circle(tp_dev.x[0], 125,DARKBLUE,10, 1);
					POINT_COLOR = RED;
					LCD_ShowNum(lcddev.width/2-12,95,(tp_dev.x[0]-(lcddev.width/2-100))/2,3,16);
			}
			if((tp_dev.x[0]>=(lcddev.width/2-30))&&(tp_dev.x[0]<=(lcddev.width/2+30))&&(tp_dev.y[0]>180)&&(tp_dev.y[0]<210))
			{
					POINT_COLOR = WHITE;
					LCD_DrawRoundRectangle(lcddev.width/2-30, 180, lcddev.width/2+30, 210,8); 
					POINT_COLOR = LBBLUE;
					LCD_FillRoundRectangle(lcddev.width/2-29, 181, lcddev.width/2+29, 208,7);
					POINT_COLOR = LIGHTGREEN;
					LCD_ShowString(lcddev.width/2-15,187,16,"EXIT",1);
					tp_dev.x[0]=0xFFFF;
					break;
			}
		}
	} 
}

void Touch_Pen_Test(void)
{
//	u8 i=0,j=0;	 
 	uint16_t lastpos[2];		//�?????后一次的数据 

	LCD_Clear(WHITE);
	LCD_Fill(0,0,lcddev.width,20,BLUE);
	LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
	POINT_COLOR=WHITE;
	Gui_StrCenter(0,2,WHITE,BLUE,"touch test 2",16,1);
	Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.lcdwiki.com",16,1);
	
	LCD_ShowString(lcddev.width-32,2,16,"RST",1);//显示清屏区域
	POINT_COLOR=RED;//设置画笔蓝色 //清除
	while(1)
	{
		//j++;
		tp_dev.scan();
		//for(t=0;t<CTP_MAX_TOUCH;t++)//�?????�?????5点触�?????
		//{
			if((tp_dev.sta)&(1<<0))//判断是否有点触摸�?????
			{
				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)//在LCD范围�?????
				{
					if(lastpos[0]==0XFFFF)
					{
						lastpos[0] = tp_dev.x[0];
						lastpos[1] = tp_dev.y[0];
					}
					if(tp_dev.x[0]>(lcddev.width-32)&&tp_dev.y[0]<18)
					{
							//if(j>1) //防止点击�?????次，多次清屏
							//{
							//	continue;
							//}
							tp_dev.x[0]=0xFFFF;
							tp_dev.x[0]=0xFFFF;
							
							LCD_Clear(WHITE);
							LCD_Fill(0,0,lcddev.width,20,BLUE);
							LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
							POINT_COLOR=WHITE;
							Gui_StrCenter(0,2,WHITE,BLUE,"touch test ...",16,1);
							Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.lcdwiki.com",16,1);
							
						
							LCD_ShowString(lcddev.width-32,2,16,"RST",1);//显示清屏区域
							POINT_COLOR=RED;//设置画笔蓝色 //清除
					}
					else
					{
							LCD_DrawLine2(lastpos[0],lastpos[1],tp_dev.x[0],tp_dev.y[0],2,RED);//画线
					}
					lastpos[0]=tp_dev.x[0];
					lastpos[1]=tp_dev.y[0];
				}
			}else lastpos[0]=0XFFFF;
		//}
		
		//delay_ms(1);
		//i++;
		//if(i%30==0)LED0=!LED0;
		//if(j>4)
		//{
		//	j=0;
		//}
	}
}

void touch_test(void)
{
	if(tp_dev.init())
	{
		printf("tp init fail!\n");
		return;
	}
//	LED_Init();
	Touch_Button_Test();
	Touch_Pen_Test();
}
