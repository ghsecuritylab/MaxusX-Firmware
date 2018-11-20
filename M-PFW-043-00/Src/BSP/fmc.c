/**
  ******************************************************************************
  * File Name          : FMC.c
  * Description        : This file provides code for the configuration
  *                      of the FMC peripheral.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "fmc.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

NOR_HandleTypeDef hnor1;
 SRAM_HandleTypeDef hsram2;

/* FMC initialization function */
void MX_FMC_Init(void)
{
  FMC_NORSRAM_TimingTypeDef Timing;

  /** Perform the NOR1 memory initialization sequence
  */
//  hnor1.Instance = FMC_NORSRAM_DEVICE;
//  hnor1.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
//  /* hnor1.Init */
//  hnor1.Init.NSBank = FMC_NORSRAM_BANK1;
//  hnor1.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
//  hnor1.Init.MemoryType = FMC_MEMORY_TYPE_NOR;
//  hnor1.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
//  hnor1.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
//  hnor1.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
//  hnor1.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
//  hnor1.Init.WriteOperation = FMC_WRITE_OPERATION_DISABLE;
//  hnor1.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
//  hnor1.Init.ExtendedMode = FMC_EXTENDED_MODE_ENABLE;
//  hnor1.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
//  hnor1.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
// // hnor1.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
// // hnor1.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
////  hnor1.Init.PageSize = FMC_PAGE_SIZE_NONE;
//  /* Timing */
//  Timing.AddressSetupTime = 1;
//  Timing.AddressHoldTime = 1;
//  Timing.DataSetupTime = 20;
//  Timing.BusTurnAroundDuration = 1;
//  Timing.CLKDivision = 2;
//  Timing.DataLatency = 1;
//  Timing.AccessMode = FMC_ACCESS_MODE_B;
  /* ExtTiming *

  if (HAL_NOR_Init(&hnor1, &Timing, NULL) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

//  /** Perform the SRAM2 memory initialization sequence
//  */
//  hsram2.Instance = FMC_NORSRAM_DEVICE;
//  hsram2.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
//  /* hsram2.Init */
//  hsram2.Init.NSBank = FMC_NORSRAM_BANK2;
//  hsram2.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
//  hsram2.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
//  hsram2.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
//  hsram2.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
//  hsram2.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
//  hsram2.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
//  hsram2.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;;
//  hsram2.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
//  hsram2.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
//  hsram2.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
//  hsram2.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
////  hsram2.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
////  hsram2.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
////  hsram2.Init.PageSize = FMC_PAGE_SIZE_NONE;
//  /* Timing */
//  Timing.AddressSetupTime = 2;
//  Timing.AddressHoldTime = 1;
//  Timing.DataSetupTime = 2;
//  Timing.BusTurnAroundDuration = 1;
//  Timing.CLKDivision = 2;
//  Timing.DataLatency = 1;
//  Timing.AccessMode = FMC_ACCESS_MODE_B;
//  /* ExtTiming */
//
//  if (HAL_SRAM_Init(&hsram2, &Timing, NULL) != HAL_OK)
//  {
//    _Error_Handler(__FILE__, __LINE__);
//  }

}

static uint32_t FMC_Initialized = 0;

static void HAL_FMC_MspInit(void){

		GPIO_InitTypeDef gpio_init_structure;

		/* Enable FMC clock */
		__HAL_RCC_FMC_CLK_ENABLE();

		/* Enable GPIOs clock */
		__HAL_RCC_GPIOD_CLK_ENABLE();
		__HAL_RCC_GPIOE_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();
		__HAL_RCC_GPIOG_CLK_ENABLE();

		/*
		   +-------------------+--------------------+------------------+------------------+
		   | PD0  <-> FMC_D2    | PD2  <-> FMC_NBL0  | PF0 <-> FMC_A0  | PG0 <-> FMC_A10  |
		   | PD1  <-> FMC_D3    | PD3  <-> FMC_NBL1  | PF1 <-> FMC_A1  | PG1 <-> FMC_A11  |
		   | PD4  <-> FMC_NOE   | PE2  <-> FMC_A23   | PF2 <-> FMC_A2  | PG2 <-> FMC_A12  |
		   | PD5  <-> FMC_NWE   | PE3  <-> FMC_A19   | PF3 <-> FMC_A3  | PG3 <-> FMC_A13  |
		   | PD8  <-> FMC_D13   | PE4  <-> FMC_A20   | PF4 <-> FMC_A4  | PG4 <-> FMC_A14  |
		   | PD9  <-> FMC_D14   | PE5  <-> FMC_A21   | PF5 <-> FMC_A5  | PG5 <-> FMC_A15  |
		   | PD10 <-> FMC_D15   | PE6  <-> FMC_A22   | PF12 <-> FMC_A6 | PC8 <-> FMC_NE2  |
		   | PD11 <-> FMC_A16   | PE7  <-> FMC_D4    | PF13 <-> FMC_A7 | PG13 <-> FMC_A24 |
		   | PD12 <-> FMC_A17   | PE8  <-> FMC_D5    | PF14 <-> FMC_A8 | PG14 <-> FMC_A25 |
		   | PD13 <-> FMC_A18   | PE9  <-> FMC_D6    | PF15 <-> FMC_A9 |------------------+
		   | PD14 <-> FMC_D0    | PE10 <-> FMC_D7    |------------------+
		   | PD15 <-> FMC_D1    | PE11 <-> FMC_D8    |
		   | PD6  <-> FMC_NWAIT | PE12 <-> FMC_D9    |
		   | PD7  <-> FMC_NE1   | PE13 <-> FMC_D10   |
		                        | PE14 <-> FMC_D11   |
		                        | PE15 <-> FMC_D12   |
		   +---------------------                    +--------------------+
		 */

		gpio_init_structure.Mode      = GPIO_MODE_OUTPUT_PP;
				gpio_init_structure.Pull      = GPIO_NOPULL;
				gpio_init_structure.Speed     = GPIO_SPEED_FREQ_HIGH;
		gpio_init_structure.Pin = GPIO_PIN_2 | GPIO_PIN_3 ;
		HAL_GPIO_Init(GPIOD, &gpio_init_structure);


		/* Common GPIO configuration */
		gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
		gpio_init_structure.Pull      = GPIO_NOPULL;
		gpio_init_structure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
		gpio_init_structure.Alternate = GPIO_AF12_FMC;

		/* GPIOD configuration */
		gpio_init_structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 |\
				GPIO_PIN_5 | GPIO_PIN_8 | GPIO_PIN_9 |\
				GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
		HAL_GPIO_Init(GPIOD, &gpio_init_structure);

		gpio_init_structure.Pin   = GPIO_PIN_4 ;
		gpio_init_structure.Pull      = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOD, &gpio_init_structure);
		/* GPIOE configuration */
		gpio_init_structure.Pin   = GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | \
				GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |\
				GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
		HAL_GPIO_Init(GPIOE, &gpio_init_structure);

		/* GPIOF configuration */
		gpio_init_structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 |\
				GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
		HAL_GPIO_Init(GPIOF, &gpio_init_structure);

		/* GPIOG configuration */
		gpio_init_structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 |\
				GPIO_PIN_5 | GPIO_PIN_13| GPIO_PIN_14;
		HAL_GPIO_Init(GPIOG, &gpio_init_structure);

		/* Pulled High GPIO configuration */
		gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
		gpio_init_structure.Pull      = GPIO_NOPULL;
		gpio_init_structure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
		gpio_init_structure.Alternate = GPIO_AF12_FMC;

		/* NE1 and NWAIT configuration */
		gpio_init_structure.Pin   = GPIO_PIN_6 | GPIO_PIN_7;
		HAL_GPIO_Init(GPIOD, &gpio_init_structure);

		/* NE2 configuration */

		gpio_init_structure.Pin = GPIO_PIN_8;
		gpio_init_structure.Mode = GPIO_MODE_AF_PP;
		gpio_init_structure.Pull = GPIO_NOPULL;
		gpio_init_structure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		gpio_init_structure.Alternate = GPIO_AF9_FMC;

		HAL_GPIO_Init(GPIOC, &gpio_init_structure);
		//
		/* USER CODE BEGIN FMC_MspInit 0 */

		/* USER CODE END FMC_MspInit 0 */



//	GPIO_InitTypeDef gpio_init_structure;
//
//	/* Enable FMC clock */
//	__HAL_RCC_FMC_CLK_ENABLE();
//
//	/* Enable GPIOs clock */
//	__HAL_RCC_GPIOD_CLK_ENABLE();
//	__HAL_RCC_GPIOE_CLK_ENABLE();
//	__HAL_RCC_GPIOF_CLK_ENABLE();
//	__HAL_RCC_GPIOG_CLK_ENABLE();
//
//	/*
//	   +-------------------+--------------------+------------------+------------------+
//	   | PD0  <-> FMC_D2    | PD2  <-> FMC_NBL0  | PF0 <-> FMC_A0  | PG0 <-> FMC_A10  |
//	   | PD1  <-> FMC_D3    | PD3  <-> FMC_NBL1  | PF1 <-> FMC_A1  | PG1 <-> FMC_A11  |
//	   | PD4  <-> FMC_NOE   | PE2  <-> FMC_A23   | PF2 <-> FMC_A2  | PG2 <-> FMC_A12  |
//	   | PD5  <-> FMC_NWE   | PE3  <-> FMC_A19   | PF3 <-> FMC_A3  | PG3 <-> FMC_A13  |
//	   | PD8  <-> FMC_D13   | PE4  <-> FMC_A20   | PF4 <-> FMC_A4  | PG4 <-> FMC_A14  |
//	   | PD9  <-> FMC_D14   | PE5  <-> FMC_A21   | PF5 <-> FMC_A5  | PG5 <-> FMC_A15  |
//	   | PD10 <-> FMC_D15   | PE6  <-> FMC_A22   | PF12 <-> FMC_A6 | PG9 <-> FMC_NE2  |
//	   | PD11 <-> FMC_A16   | PE7  <-> FMC_D4    | PF13 <-> FMC_A7 | PG13 <-> FMC_A24 |
//	   | PD12 <-> FMC_A17   | PE8  <-> FMC_D5    | PF14 <-> FMC_A8 | PG14 <-> FMC_A25 |
//	   | PD13 <-> FMC_A18   | PE9  <-> FMC_D6    | PF15 <-> FMC_A9 |------------------+
//	   | PD14 <-> FMC_D0    | PE10 <-> FMC_D7    |------------------+
//	   | PD15 <-> FMC_D1    | PE11 <-> FMC_D8    |
//	   | PD6  <-> FMC_NWAIT | PE12 <-> FMC_D9    |
//	   | PD7  <-> FMC_NE1   | PE13 <-> FMC_D10   |
//	                        | PE14 <-> FMC_D11   |
//	                        | PE15 <-> FMC_D12   |
//	   +---------------------                    +--------------------+
//	 */
//
//	/* Common GPIO configuration */
//	gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
//	gpio_init_structure.Pull      = GPIO_PULLDOWN;
//	gpio_init_structure.Speed     = GPIO_SPEED_FREQ_HIGH;
//	gpio_init_structure.Alternate = GPIO_AF12_FMC;
//
//	/* GPIOD configuration */
//	gpio_init_structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 |\
//			GPIO_PIN_5 | GPIO_PIN_8 | GPIO_PIN_9 |
//			GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
//	HAL_GPIO_Init(GPIOD, &gpio_init_structure);
//
//	/* GPIOE configuration */
//	gpio_init_structure.Pin   = GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | \
//			GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |\
//			GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
//	HAL_GPIO_Init(GPIOE, &gpio_init_structure);
//
//	/* GPIOF configuration */
//	gpio_init_structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 |\
//			GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
//	HAL_GPIO_Init(GPIOF, &gpio_init_structure);
//
//	/* GPIOG configuration */
//	gpio_init_structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 |\
//			GPIO_PIN_5 | GPIO_PIN_13| GPIO_PIN_14;
//	HAL_GPIO_Init(GPIOG, &gpio_init_structure);
//
//	/* Pulled High GPIO configuration */
//	gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
//	gpio_init_structure.Pull      = GPIO_NOPULL;
//	gpio_init_structure.Speed     = GPIO_SPEED_FREQ_HIGH;
//	gpio_init_structure.Alternate = GPIO_AF12_FMC;
//
//	/* NE1 and NWAIT configuration */
//	gpio_init_structure.Pin   = GPIO_PIN_6 | GPIO_PIN_7;
//	HAL_GPIO_Init(GPIOD, &gpio_init_structure);
//
//	/* NE2 configuration */
//	gpio_init_structure.Pin   = GPIO_PIN_8;
//	HAL_GPIO_Init(GPIOC, &gpio_init_structure);

//  /* USER CODE BEGIN FMC_MspInit 0 */
//
//  /* USER CODE END FMC_MspInit 0 */
//  GPIO_InitTypeDef GPIO_InitStruct;
//  if (FMC_Initialized) {
//    return;
//  }
//  FMC_Initialized = 1;
//  /* Peripheral clock enable */
//  __HAL_RCC_FMC_CLK_ENABLE();
//
//  /** FMC GPIO Configuration

//  PE2   ------> FMC_A23
//  PE3   ------> FMC_A19
//  PE4   ------> FMC_A20
//  PE5   ------> FMC_A21
//  PE6   ------> FMC_A22
//  PF0   ------> FMC_A0
//  PF1   ------> FMC_A1
//  PF2   ------> FMC_A2
//  PF3   ------> FMC_A3
//  PF4   ------> FMC_A4
//  PF5   ------> FMC_A5
//  PF12   ------> FMC_A6
//  PF13   ------> FMC_A7
//  PF14   ------> FMC_A8
//  PF15   ------> FMC_A9
//  PG0   ------> FMC_A10
//  PG1   ------> FMC_A11
//  PE7   ------> FMC_D4
//  PE8   ------> FMC_D5
//  PE9   ------> FMC_D6
//  PE10   ------> FMC_D7
//  PE11   ------> FMC_D8
//  PE12   ------> FMC_D9
//  PE13   ------> FMC_D10
//  PE14   ------> FMC_D11
//  PE15   ------> FMC_D12
//  PD8   ------> FMC_D13
//  PD9   ------> FMC_D14
//  PD10   ------> FMC_D15
//  PD11   ------> FMC_A16
//  PD12   ------> FMC_A17
//  PD13   ------> FMC_A18
//  PD14   ------> FMC_D0
//  PD15   ------> FMC_D1
//  PG2   ------> FMC_A12
//  PG3   ------> FMC_A13
//  PG4   ------> FMC_A14
//  PG5   ------> FMC_A15
//  PC8   ------> FMC_NE2
//  PD0   ------> FMC_D2
//  PD1   ------> FMC_D3
//  PD4   ------> FMC_NOE
//  PD5   ------> FMC_NWE
//  PD6   ------> FMC_NWAIT
//  PD7   ------> FMC_NE1
//  PG13   ------> FMC_A24
//  PG14   ------> FMC_A25
//  PB7   ------> FMC_NL
//
//    PD2   ------> BLN0
//   PD3   ------> BLN1
//  */
//
//   /* GPIO_InitStruct */
//  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
//                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
//                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
//                          |GPIO_PIN_14|GPIO_PIN_15;
//  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
//
//  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
//
//  /* GPIO_InitStruct */
//  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
//                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_12|GPIO_PIN_13
//                          |GPIO_PIN_14|GPIO_PIN_15;
//  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
//
//  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
//
//  /* GPIO_InitStruct */
//  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
//                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_13|GPIO_PIN_14;
//  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
//
//  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
//
//  /* GPIO_InitStruct */
//  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
//                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
//                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3||GPIO_PIN_4|GPIO_PIN_5
//                          |GPIO_PIN_6|GPIO_PIN_7;
//  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
//
//  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
//
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
//
//  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
//
//  /* GPIO_InitStruct */
//  GPIO_InitStruct.Pin = GPIO_PIN_8;
//  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF9_FMC;
//
//  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//
//  /* GPIO_InitStruct */
//  GPIO_InitStruct.Pin = GPIO_PIN_7;
//  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
//
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN FMC_MspInit 1 */
//
//  /* USER CODE END FMC_MspInit 1 */
}

void HAL_NOR_MspInit(NOR_HandleTypeDef* norHandle){
  /* USER CODE BEGIN NOR_MspInit 0 */

  /* USER CODE END NOR_MspInit 0 */
  HAL_FMC_MspInit();
  /* USER CODE BEGIN NOR_MspInit 1 */

  /* USER CODE END NOR_MspInit 1 */
}

void HAL_SRAM_MspInit(SRAM_HandleTypeDef* sramHandle){
  /* USER CODE BEGIN SRAM_MspInit 0 */

  /* USER CODE END SRAM_MspInit 0 */
  HAL_FMC_MspInit();
  /* USER CODE BEGIN SRAM_MspInit 1 */

  /* USER CODE END SRAM_MspInit 1 */
}

static uint32_t FMC_DeInitialized = 0;

static void HAL_FMC_MspDeInit(void){
  /* USER CODE BEGIN FMC_MspDeInit 0 */

  /* USER CODE END FMC_MspDeInit 0 */
  if (FMC_DeInitialized) {
    return;
  }
  FMC_DeInitialized = 1;
  /* Peripheral clock enable */
  __HAL_RCC_FMC_CLK_DISABLE();
  
  /** FMC GPIO Configuration  
  PE2   ------> FMC_A23
  PE3   ------> FMC_A19
  PE4   ------> FMC_A20
  PE5   ------> FMC_A21
  PE6   ------> FMC_A22
  PF0   ------> FMC_A0
  PF1   ------> FMC_A1
  PF2   ------> FMC_A2
  PF3   ------> FMC_A3
  PF4   ------> FMC_A4
  PF5   ------> FMC_A5
  PF12   ------> FMC_A6
  PF13   ------> FMC_A7
  PF14   ------> FMC_A8
  PF15   ------> FMC_A9
  PG0   ------> FMC_A10
  PG1   ------> FMC_A11
  PE7   ------> FMC_D4
  PE8   ------> FMC_D5
  PE9   ------> FMC_D6
  PE10   ------> FMC_D7
  PE11   ------> FMC_D8
  PE12   ------> FMC_D9
  PE13   ------> FMC_D10
  PE14   ------> FMC_D11
  PE15   ------> FMC_D12
  PD8   ------> FMC_D13
  PD9   ------> FMC_D14
  PD10   ------> FMC_D15
  PD11   ------> FMC_A16
  PD12   ------> FMC_A17
  PD13   ------> FMC_A18
  PD14   ------> FMC_D0
  PD15   ------> FMC_D1
  PG2   ------> FMC_A12
  PG3   ------> FMC_A13
  PG4   ------> FMC_A14
  PG5   ------> FMC_A15
  PC8   ------> FMC_NE2
  PD0   ------> FMC_D2
  PD1   ------> FMC_D3
  PD4   ------> FMC_NOE
  PD5   ------> FMC_NWE
  PD6   ------> FMC_NWAIT
  PD7   ------> FMC_NE1
  PG13   ------> FMC_A24
  PG14   ------> FMC_A25
  PB7   ------> FMC_NL
  */

  HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOF, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOG, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_13|GPIO_PIN_14);

  HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7);

  HAL_GPIO_DeInit(GPIOC, GPIO_PIN_8);

  HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

  /* USER CODE BEGIN FMC_MspDeInit 1 */

  /* USER CODE END FMC_MspDeInit 1 */
}

void HAL_NOR_MspDeInit(NOR_HandleTypeDef* norHandle){
  /* USER CODE BEGIN NOR_MspDeInit 0 */

  /* USER CODE END NOR_MspDeInit 0 */
  HAL_FMC_MspDeInit();
  /* USER CODE BEGIN NOR_MspDeInit 1 */

  /* USER CODE END NOR_MspDeInit 1 */
}

void HAL_SRAM_MspDeInit(SRAM_HandleTypeDef* sramHandle){
  /* USER CODE BEGIN SRAM_MspDeInit 0 */

  /* USER CODE END SRAM_MspDeInit 0 */
  HAL_FMC_MspDeInit();
  /* USER CODE BEGIN SRAM_MspDeInit 1 */

  /* USER CODE END SRAM_MspDeInit 1 */
}
/**
  * @}
  */
/**
  * @brief  Writes an amount of data to the SDRAM memory in polling mode.
  * @param  uwStartAddress: Write start address
  * @param  pData: Pointer to data to be written
  * @param  uwDataSize: Size of written data from the memory
  * @retval SDRAM status
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/