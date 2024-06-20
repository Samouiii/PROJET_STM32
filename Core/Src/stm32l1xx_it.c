/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l1xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32l1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "max7219_Yncrea2.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern ADC_HandleTypeDef hadc;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;
/* USER CODE BEGIN EV */
uint16_t currentSensor;
bool debounce_flag;

float Temperature;
char index_temperature[11] = {'T','E','N','P','E','R','A','T','U','R','E'};
float alarmTemperature = -1.0;
char index_alarm_temperature[17] = {'A','L','A','R','N',' ','T','E','N','P','E','R','A','T','U','R','E'};

float Humidity;
char index_humidity[11] = {'H','U','N','I','D','I','T','4'};
float alarmHumidity = -1.0;
char index_alarm_humidity[14] = {'A','L','A','R','N',' ','H','U','N','I','D','I','T','4'};

float Pressure;
char index_pressure[11] = {'P','R','E','S','S','U','R','E'};

char set_success[11] = {'S','E','T',' ','S','U','C','C','E','S','S'};
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32L1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles ADC global interrupt.
  */
void ADC1_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_IRQn 0 */

  /* USER CODE END ADC1_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc);
  /* USER CODE BEGIN ADC1_IRQn 1 */

  /* USER CODE END ADC1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(BTN4_Pin);
  HAL_GPIO_EXTI_IRQHandler(BTN3_Pin);
  HAL_GPIO_EXTI_IRQHandler(DOUBLE_TAP_Pin);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles SPI1 global interrupt.
  */
void SPI1_IRQHandler(void)
{
  /* USER CODE BEGIN SPI1_IRQn 0 */

  /* USER CODE END SPI1_IRQn 0 */
  HAL_SPI_IRQHandler(&hspi1);
  /* USER CODE BEGIN SPI1_IRQn 1 */

  /* USER CODE END SPI1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(BTN1_Pin);
  HAL_GPIO_EXTI_IRQHandler(BTN2_Pin);
  HAL_GPIO_EXTI_IRQHandler(B1_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt.
  */
void TIM6_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_IRQn 0 */

  /* USER CODE END TIM6_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_IRQn 1 */

  /* USER CODE END TIM6_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim == &htim6){
		updateVariableSensor();
		displayVariableSensor();
		checkVariableSensor();
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	if(GPIO_Pin != currentSensor){
		HAL_TIM_Base_Stop_IT(&htim6);
		currentSensor = GPIO_Pin;
		switch(GPIO_Pin){
			case BTN1_Pin:
				printf("TEMPERATURE\r\n");
				displayIndex(index_temperature);
				break;
			case BTN2_Pin:
				printf("HUMIDITY\r\n");
				displayIndex(index_humidity);
				break;
			case BTN3_Pin:
				printf("ALARM_TEMPERATURE\r\n");
				displayIndex(index_alarm_temperature);
				break;
			case BTN4_Pin:
				printf("ALARM HUMIDITY\r\n");
				displayIndex(index_alarm_humidity);
				break;
			default:
				printf("PIN INCONNUE \r\n");
		}
		HAL_TIM_Base_Start_IT(&htim6);
		return;
	}
}

void updateVariableSensor(){
	IKS01A3_ENV_SENSOR_GetValue(IKS01A3_HTS221_0, ENV_TEMPERATURE, &Temperature);
	IKS01A3_ENV_SENSOR_GetValue(IKS01A3_HTS221_0, ENV_HUMIDITY, &Humidity);
	// IKS01A3_ENV_SENSOR_GetValue(IKS01A3_LPS22HH_0, ENV_PRESSURE, &Pressure);
}

void displayVariableSensor(){
	switch(currentSensor){
		case BTN1_Pin:
			displayTemperature();
			break;
		case BTN2_Pin:
			displayHumidity();
			break;
		case BTN3_Pin:
			displayAlarmTemperature();
			break;
		case BTN4_Pin:
			displayAlarmHumidity();
			break;
	}
}

void checkVariableSensor(){
	bool state_alarm_temperature= false;
	bool state_alarm_humidity= false;

	if(Humidity > alarmHumidity && alarmHumidity !=-1.0){
		printf("ALARM TEMPERATURE ON\r\n");
		HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
		HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
		state_alarm_temperature = true;
	}
	else {
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, 0);
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 0);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, 0);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, 0);
	}

	if(Temperature > alarmTemperature && alarmTemperature !=-1){
		printf("ALARM HUMIDITY ON\r\n");
		HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
		HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
		HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
		HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);
		state_alarm_humidity = true;
	}
	else {
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 0);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, 0);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, 0);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, 0);
	}

	(state_alarm_temperature || state_alarm_humidity) ? HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2) : HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
}

void displayTemperature(){
	char temp_Temperature[5];
	snprintf(temp_Temperature, sizeof(temp_Temperature), "%.2f", Temperature);
	printf("Temperature : %s \r\n",temp_Temperature);

	MAX7219_DisplayChar(1, temp_Temperature[0]);
	MAX7219_DisplayChar(2, temp_Temperature[1]);
	(temp_Temperature[2] == '.') ? MAX7219_DisplayChar(3, ' ') : MAX7219_DisplayChar(3, temp_Temperature[2]);
	MAX7219_DisplayChar(4, temp_Temperature[3]);
}

void displayHumidity(){
	char temp_Humidity[5];
	snprintf(temp_Humidity, sizeof(temp_Humidity), "%.2f", Humidity);
	printf("Humidity : %s \r\n",temp_Humidity);

	MAX7219_DisplayChar(1, temp_Humidity[0]);
	MAX7219_DisplayChar(2, temp_Humidity[1]);
	(temp_Humidity[2] == '.') ? MAX7219_DisplayChar(3, ' ') : MAX7219_DisplayChar(3, temp_Humidity[2]);
	MAX7219_DisplayChar(4, temp_Humidity[3]);
}

void displayPressure(){
	char temp_Pressure[5];
	snprintf(temp_Pressure, sizeof(temp_Pressure), "%.2f", Pressure);
	printf("Pressure : %s \r\n",temp_Pressure);

	MAX7219_DisplayChar(1, temp_Pressure[0]);
	MAX7219_DisplayChar(2, temp_Pressure[1]);
	MAX7219_DisplayChar(3, temp_Pressure[2]);
	MAX7219_DisplayChar(4, temp_Pressure[3]);
}

void displayAlarmTemperature(){
	HAL_ADC_Start_IT(&hadc);
	HAL_ADC_PollForConversion(&hadc, 1);
	alarmTemperature = (float) HAL_ADC_GetValue(&hadc) /100;
	HAL_ADC_Stop_IT(&hadc);

	char temp_alarmTemperature[5];
	snprintf(temp_alarmTemperature, sizeof(temp_alarmTemperature), "%.2f", alarmTemperature);
	printf("analogValuePotentiometer : %s\r\n",temp_alarmTemperature);
	MAX7219_DisplayChar(1, temp_alarmTemperature[0]);
	MAX7219_DisplayChar(2, temp_alarmTemperature[1]);
	MAX7219_DisplayChar(3, ' ');
	MAX7219_DisplayChar(4, temp_alarmTemperature[3]);
}

void displayAlarmHumidity(){
	HAL_ADC_Start_IT(&hadc);
	HAL_ADC_PollForConversion(&hadc, 1);
	alarmHumidity = (float) HAL_ADC_GetValue(&hadc) /40.95;
	HAL_ADC_Stop_IT(&hadc);

	char temp_alarmHumidity[5];
	snprintf(temp_alarmHumidity, sizeof(temp_alarmHumidity), "%.2f", alarmHumidity);
	printf("analogValuePotentiometer : %s\r\n",temp_alarmHumidity);
	MAX7219_DisplayChar(1, temp_alarmHumidity[0]);
	MAX7219_DisplayChar(2, temp_alarmHumidity[1]);
	(temp_alarmHumidity[2] == '.') ? MAX7219_DisplayChar(3, ' ') : MAX7219_DisplayChar(3, temp_alarmHumidity[2]);
	MAX7219_DisplayChar(4, temp_alarmHumidity[3]);
}

void displayIndex(char *message){
	char first_character;
	char second_character;
	char third_character;
	char fourth_character;
	for(int i =0 ; i < strlen(message)+4 ; i++ ){
		(i < 0 ) || (i > strlen(message)-1) ? (fourth_character = ' ') : (fourth_character = message[i]);
		(i-1 < 0 ) || (i-1 > strlen(message)-1) ? (third_character = ' ') : (third_character = message[i-1]);
		(i-2 < 0 ) || (i-2 > strlen(message)-1) ? (second_character = ' ') : (second_character = message[i-2]);
		(i-3 < 0 ) || (i-3 > strlen(message)-1) ? (first_character = ' ') : (first_character = message[i-3]);
		MAX7219_DisplayChar(1, first_character);
		MAX7219_DisplayChar(2, second_character);
		MAX7219_DisplayChar(3, third_character);
		MAX7219_DisplayChar(4, fourth_character);
		HAL_Delay(100);
	}
}

/* USER CODE END 1 */
