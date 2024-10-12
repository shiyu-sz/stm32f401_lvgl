/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "task_schedule.h"
#include "cm_backtrace.h"
#include "nr_micro_shell.h"
#include "lcd.h"
#include "common.h"
#include "gui.h"
#include "touch.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
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
	delay_ms(1000);	
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
		if((tp_dev.sta)&(1<<0))//判断是否有点触摸�??
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
 	uint16_t lastpos[2];		//�??后一次的数据 

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
		//for(t=0;t<CTP_MAX_TOUCH;t++)//�??�??5点触�??
		//{
			if((tp_dev.sta)&(1<<0))//判断是否有点触摸�??
			{
				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)//在LCD范围�??
				{
					if(lastpos[0]==0XFFFF)
					{
						lastpos[0] = tp_dev.x[0];
						lastpos[1] = tp_dev.y[0];
					}
					if(tp_dev.x[0]>(lcddev.width-32)&&tp_dev.y[0]<18)
					{
							//if(j>1) //防止点击�??次，多次清屏
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
		return;
	}
//	LED_Init();
	Touch_Button_Test();
	Touch_Pen_Test();
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  shell_init();
  printf("app start!");
  cm_backtrace_init("CmBacktrace", "V1.0.0", "V1.0.0");
  HAL_UARTEx_ReceiveToIdle_IT(&huart1, shell_uart_buff, SHELL_BUFF_SIZE);
  LCD_Init();	   //液晶屏初始化
  task_init();

  lcd_test();
  touch_test();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    TaskSchedule();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
