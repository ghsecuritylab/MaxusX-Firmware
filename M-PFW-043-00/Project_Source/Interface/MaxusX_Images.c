/*
 * Commander_Images.c
 *
 *  Created on: Jun 24, 2015
 *      Author: JacoOlivier
 */

#include "MaxusX_Images.h"
/****************************************************************/
/**
 * @brief
 * @param
 *   This parameter can be one of following parameters:
 *     @arg
 * @retval None
 */
/****************************************************************/
/***********************************************/
//Local Variables
//Global Variables
uint8_t Flash_Disk_ImageCount = 0;
uint8_t Image_Buf[IMAGE_BUFFER_SIZE];

#define DMA_MAX_SIZE 0xFF

//images configuration stored in ROM
const image_t image[Number_Of_Images + 1] =
{
		//               size		X		    Y		 address		index

		{ 	      0    ,    0      ,    0  ,         0     ,       0 	},		//dummy data, there is no index 0

		{   IMG_01_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_01_Addr , 	IMG_BUTTON_UP  },
		{   IMG_02_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_02_Addr , 	IMG_BUTTON_DOWN },
		{   IMG_03_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_03_Addr , 	IMG_BUTTON_LEFT  },
		{   IMG_04_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_04_Addr , 	IMG_BUTTON_RIGHT  },
		{   IMG_05_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_05_Addr , 	IMG_BUTTON_ENTER  },
		{   IMG_06_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_06_Addr , 	IMG_BUTTON_OK  },
		{   IMG_07_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_07_Addr , 	IMG_BUTTON_FAIL },
		{   IMG_08_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_08_Addr , 	IMG_BUTTON_SETTING  },
		{   IMG_09_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_09_Addr , 	IMG_BUTTON_SHAFT },
		{   IMG_10_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_10_Addr , 	IMG_BUTTON_WORK },
		{   IMG_11_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_11_Addr , 	IMG_BUTTON_STOP  },
		{   IMG_12_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_12_Addr , 	IMG_BUTTON_SIREN  },
		{   IMG_13_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_13_Addr , 	IMG_BUTTON_LOCO_LEFT },
		{   IMG_14_Size,   BUTTON_SIZE_X     ,   BUTTON_SIZE_Y ,   IMG_14_Addr , 	IMG_BUTTON_GAURD_RIGHT },
		{   IMG_15_Size,   SM_LOGO_SIZE_X     ,   SM_LOGO_SIZE_Y ,   IMG_15_Addr , 	IMG_SM_LOGO  },
		{   IMG_16_Size,   LG_LOGO_SIZE_X     ,   LG_LOGO_SIZE_Y ,   IMG_16_Addr , 	IMG_LG_LOGO },
		{   IMG_17_Size,   LOCO_HOPPERS_SIZE_X     ,   LOCO_HOPPERS_SIZE_Y ,   IMG_17_Addr , 	IMG_LOCO_HOPPERS_GAURD_CROSS  },
		{   IMG_18_Size,   LOCO_HOPPERS_SIZE_X     ,   LOCO_HOPPERS_SIZE_Y ,   IMG_18_Addr , 	IMG_LOCO_HOPPERS },
		{   IMG_19_Size,   LOCO_HOPPERS_SIZE_X     ,   LOCO_HOPPERS_SIZE_Y ,   IMG_19_Addr , 	IMG_LOCO_HOPPERS_LOCO  },
		{   IMG_20_Size,   LOCO_HOPPERS_SIZE_X     ,   LOCO_HOPPERS_SIZE_Y ,   IMG_20_Addr , 	IMG_LOCO_HOPPERS_GAURD },
		{   IMG_21_Size,   LARGE_X     ,   LARGE_Y ,   IMG_21_Addr , 	IMG_LOCO_HOPPER_LEFT },
		{   IMG_22_Size,   LARGE_X     ,   LARGE_Y ,   IMG_22_Addr , 	IMG_GAURD_HOPPER_RIGHT },
		{   IMG_23_Size,   LARGE_X     ,   LARGE_Y ,   IMG_23_Addr , 	IMG_PEDESTRIAN_LG },
		{   IMG_24_Size,   LARGE_X     ,   LARGE_Y ,   IMG_24_Addr , 	IMG_GAURD_RIGHT_RED },
		{   IMG_25_Size,   LARGE_X     ,   LARGE_Y ,   IMG_25_Addr , 	IMG_LOCO_LEFT_RED },
		{   IMG_26_Size,   LARGE_X     ,   LARGE_Y ,   IMG_26_Addr , 	IMG_TRAFFIC_RED },
		{   IMG_27_Size,   LARGE_X     ,   LARGE_Y ,   IMG_27_Addr , 	IMG_TRAFFIC_YELLOW },
		{   IMG_28_Size,   LARGE_X     ,   LARGE_Y ,   IMG_28_Addr , 	IMG_TTM },
		{   IMG_29_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_29_Addr , 	IMG_SMILEY_BLUE },
		{   IMG_30_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_30_Addr , 	IMG_SMILEY_RED },
		{   IMG_31_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_31_Addr , 	IMG_SMILEY_GREEN },
		{   IMG_32_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_32_Addr , 	IMG_SMILEY_YELLOW },
		{   IMG_33_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_33_Addr , 	IMG_SMILEY_WHITE },
		{   IMG_34_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_34_Addr , 	IMG_SMILEY_AMBER },
		{   IMG_35_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_35_Addr , 	IMG_SMILEY_PURPLE },
		{   IMG_36_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_36_Addr , 	IMG_SMILEY_SAD_RED },
		{   IMG_37_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_37_Addr , 	IMG_SMILEY_STRAIGHT_YELLOW },
		{   IMG_38_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_38_Addr , 	IMG_DOOR_OPEN },
		{   IMG_39_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_39_Addr , 	IMG_TORTOISE },
		{   IMG_40_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_40_Addr , 	IMG_HARE },
		{   IMG_41_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_41_Addr , 	IMG_PEDESTRIAN_SM },
		{   IMG_42_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_42_Addr , 	IMG_ARROW_LEFT_RED },
		{   IMG_43_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_43_Addr , 	IMG_ARROW_LEFT_YELLOW },
		{   IMG_44_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_44_Addr , 	IMG_ARROW_LEFT_GREEN },
		{   IMG_45_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_45_Addr , 	IMG_WARMING },
		{   IMG_46_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_46_Addr , 	IMG_NO_SIGNAL },
		{   IMG_47_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_47_Addr , 	IMG_LOCO_LEFT_YELLOW },
		{   IMG_48_Size,   MEDIUM_X     ,   MEDIUM_Y ,   IMG_48_Addr , 	IMG_LOCO_RIGHT_YELLOW },
		{   IMG_49_Size,   SMALL_X     ,   SMALL_Y ,   IMG_49_Addr , 	IMG_BATTERY_FULL_WHITE },
		{   IMG_50_Size,   SMALL_X     ,   SMALL_Y ,   IMG_50_Addr , 	IMG_SIGNAL_YELLOW },
		{   IMG_51_Size,   SMALL_X     ,   SMALL_Y ,   IMG_51_Addr , 	IMG_SIGNAL_BLUE },
		{   IMG_52_Size,   SMALL_X     ,   SMALL_Y ,   IMG_52_Addr , 	IMG_SIGNAL_WHITE },


};

/**
 * @brief			Fetches image from flash, and puts it in
 * @param x
 * @param y
 * @param index
 */
void DisplayImage(uint16_t x, uint16_t y, uint16_t index)
{

	uint32_t size = image[index].size;
	uint32_t address = image[index].address;
	uint32_t count = 0;

	///////////////////////////
	//LCD_flip_for_BMP();
	///////////////////////////
	//	LCD_SetDisplayArea(x, x + image[index].X_size-1, y, y + image[index].Y_size -1);
	//	LCD_WriteCommand(CMD_WR_MEMSTART);

	if (size > (DMA_MAX_SIZE * 2))
	{
		do
		{
			NOR_DMAImageTransfer(address, DMA_MAX_SIZE * 2, count);
			size -= (DMA_MAX_SIZE * 2);
			address += (DMA_MAX_SIZE * 2); // halfword = 2 bytes
			count++;
		} while (size > (DMA_MAX_SIZE * 2));
	}
	//framebuf2 = (u16*) (test);
	NOR_DMAImageTransfer(address, size, count);
	//NOR_DMAImageTransfer(address, (size));

	///////////////////////////
	//SetOrientation(DISP_ORIENTATION);
	///////////////////////////
}


