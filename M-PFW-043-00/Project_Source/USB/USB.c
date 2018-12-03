/*
 * USB.c
 *
 *  Created on: Jun 24, 2015
 *      Author: JacoOlivier
 */

#include "USB.h"
#include "ff_gen_drv.h"
#include "usbh_diskio.h"
#include "fatfs.h"
#include "ff.h"
#include <stdio.h>
#include <stdint.h>
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
extern ApplicationTypeDef Appli_state;
extern NOR_HandleTypeDef S29GL01GS;
extern USBH_HandleTypeDef hUsbHostFS;
//extern Parameter Temp_Params[Parameters_Size];

//Test Variables
//short int F_WriteFile = 0;
//short int F_ReadList = 0;
//short int F_ReadFile = 0;


/****************************************************************/
/*This is the main state machine for the FlexiDisplay USB
 */
/****************************************************************/
void Main_USB_Handler(void)
{

}



/****************************************************************/
//USB Core functions -- these are automatically entered by the
//USB controller
/****************************************************************/

/****************************************************************/
//this always runs for any USB_OTG at system startup
/****************************************************************/
void USB_Core_Init(void)
{
	//display on lcd
	//	OutTextXY(LCD_Setup_Text_X, Line4_y_Position, LCD_USB_Message_1);

#ifdef USB_Debug
	USART_SendString(COM_PC,"USB OTG Initialised\n\r");
#endif
}


/****************************************************************/
//display device attached, clear device disconnected
/****************************************************************/
void USB_Core_New_Device(void)
{
	//display on lcd
	//	OutTextXY(LCD_Setup_Text_X, Line5_y_Position, LCD_USB_Message_3);

#ifdef USB_Debug
	USART_SendString(COM_PC,"USB Device detected\n\r");
#endif
}

/****************************************************************/
//Some error occurred, not sure yest what this is??
/****************************************************************/
void USB_Core_Unrecovered_Error(void)
{
#ifdef USB_Debug
	USART_SendString(COM_PC,"USB OTG non-recovered error\n\r");
#endif
}

/****************************************************************/
//Called when the flash disc is disconnected
/****************************************************************/
void USB_Core_Disconnected(void)
{
	//	//display on lcd
	//	OutTextXY(LCD_Setup_Text_X, Line5_y_Position, LCD_USB_Message_2);
	//	//clear other lines
	//	OutTextXY(LCD_Setup_Text_X, Line6_y_Position, Clear_Line);
	//	OutTextXY(LCD_Setup_Text_X, Line7_y_Position, Clear_Line);
	//	OutTextXY(LCD_Setup_Text_X, Line8_y_Position, Clear_Line);
	//	OutTextXY(LCD_Setup_Text_X, Line9_y_Position, Clear_Line);
	//	OutTextXY(LCD_Setup_Text_X, Line10_y_Position, Clear_Line);
	//	OutTextXY(LCD_Setup_Text_X, Line11_y_Position, Clear_Line);


	//allow reset of error flag
	//USB_Flags.Force_Disc_Remove = false;

#ifdef USB_Debug
	USART_SendString(COM_PC,"USB Device disconnected\n\r");
#endif
}

/****************************************************************/
//Not sure when this is called
/****************************************************************/
void USB_Core_Reset(void)
{

}

/****************************************************************/
//Called when new device is in and enumeration is done.
/****************************************************************/
void USB_Core_Enum_Done(void)
{
	//display on lcd
	//	OutTextXY(LCD_Setup_Text_X, Line6_y_Position, LCD_USB_Message_8);
#ifdef USB_Debug
	USART_SendString(COM_PC,"USB Device Enumeration Complete\n\r");
#endif
}

/****************************************************************/
//Called for unsupported devices
/****************************************************************/
void USB_Core_Unsupported_Device(void)
{

#ifdef USB_Debug
	USART_SendString(COM_PC,"USB ERROR - Device NOT Supported\n\r");
#endif

}

/****************************************************************/
//Entered once USB device speed is detected
/****************************************************************/
void USB_Core_Speed_Detected(uint8_t DeviceSpeed)
{
	if(DeviceSpeed == HPRT0_PRTSPD_HIGH_SPEED)
	{
		//display on lcd
		//		OutTextXY(LCD_Setup_Text_X, Line6_y_Position, LCD_USB_Message_4);
#ifdef USB_Debug
		USART_SendString(COM_PC,"USB High Speed Device\n\r");
#endif
	}
	else if(DeviceSpeed == HPRT0_PRTSPD_FULL_SPEED)
	{
		//display on lcd
		//		OutTextXY(LCD_Setup_Text_X, Line6_y_Position, LCD_USB_Message_5);
#ifdef USB_Debug
		USART_SendString(COM_PC,"USB Full Speed Device\n\r");
#endif
	}
	else if(DeviceSpeed == HPRT0_PRTSPD_LOW_SPEED)
	{
		//display on lcd
		//	OutTextXY(LCD_Setup_Text_X, Line6_y_Position, LCD_USB_Message_6);
#ifdef USB_Debug
		USART_SendString(COM_PC,"USB Low Speed Device\n\r");
#endif
	}
	else
	{
		//display on lcd
		//	OutTextXY(LCD_Setup_Text_X, Line6_y_Position, LCD_USB_Message_7);
#ifdef USB_Debug
		USART_SendString(COM_PC,"ERROR - Speed Detect Error\n\r");
#endif
	}
}


/****************************************************************/
//Fat Init error
/****************************************************************/
void USB_Core_FAT_Error(void)
{
	;//display on lcd
	//OutTextXY(LCD_Setup_Text_X, Line7_y_Position, LCD_USB_Message_10);

#ifdef USB_Debug
	USART_SendString(COM_PC,"USB ERROR - Cannot Init FAT FS\n\r");
#endif
}

/****************************************************************/
//Fat Init error, disk protected
/****************************************************************/
void USB_Core_FAT_Disk_Protected(void)
{
	//display on lcd
	//OutTextXY(LCD_Setup_Text_X, Line7_y_Position, LCD_USB_Message_11);

#ifdef USB_Debug
	USART_SendString(COM_PC,"USB ERROR - Disk Write Protected\n\r");
#endif
}



/****************************************************************/
//This function is called if the disc is in, all is started.
//Function will now check what type of USB read is required
//and call the correct function from here.
/****************************************************************/
void USB_User_File_Reader(void)
{



}


/****************************************************************/
//This function is called to check if there are the required images
//on the disc
/****************************************************************/
void USB_User_File_Explorer(void)
{
	//Now check what type of file scan is required.


	/*UPDATE IMAGES*/
//	if(USB_Flags.Image_Update_Requested)
//	{

		TIM3_Stop();
		TIM4_Stop();


		//Link the latest attached USB device
		FATFS_LinkDriver(&USBH_Driver, Images_Dir);

		//check images, if count is OK, allow update, else show message and stop
		if(Explore_Disk_Images(Images_Dir))
		{
			Update_Images_Now();
			USB_Flags.Force_Disc_Remove = true;
			USB_Flags.Image_Update_Requested = false;

			//Unlink the USB device associated with the latest used directory
			FATFS_UnLinkDriver(Images_Dir);

			TextToScreen_SML(0, 255, "Press any button to restart and continue.", LCD_COLOR_WHITE, LCD_COLOR_BLACK);

			IO_App_Read_Inputs();

			while((!Input_Flags.Button_1) && (!Input_Flags.Button_2)&& (!Input_Flags.Button_3)&& (!Input_Flags.Button_4))
			{
				IO_App_Read_Inputs();
			}


			TIM3_Start();
			TIM4_Start();

		}
		else
		{
			USB_Flags.Image_Update_Requested = false;
			TIM3_Start();
			TIM4_Start();

			USB_Flags.Force_Disc_Remove = true;
		}
}



/****************************************************************/
//This function is called when data must be written to the Flash
//Disk, check which function to call from here
/****************************************************************/
void USB_User_File_Writer(void)
{
	//Datalog Requested
	if(USB_Flags.DataLog_Requested == true)
	{
		USB_Flags.DataLog_Requested = false;

		//todo
		//		if (check_if_block_ready())
		//		{
		//			check_and_move_block_ready();
		//		}
		//		datalog_req_move_block();
		//
		//		//this function will get datalog and store on USB flash disk
		//		User_DataLog_Extraction_USB();
	}

}

void App_USB_SM(void)
{
	if(Appli_state == APPLICATION_READY)
	{
		USB_Flags.USB_OK = true;
		USB_User_File_Explorer();
	}
	else
		USB_Flags.USB_OK = false;
}
