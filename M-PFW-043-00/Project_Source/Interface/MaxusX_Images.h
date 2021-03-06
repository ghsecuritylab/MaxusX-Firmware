/*Commander100_Images.h*/

#ifndef MAXUSX_IMAGES_H_
#define MAXUSX_IMAGES_H_
//Includes
#include "Global_Variables.h"



typedef struct
{
	__IO uint16_t LCD_COMMAND;
	__IO uint16_t LCD_DATA;
} LCDFSMC_TypeDef;

///* Note: LCD /CS is NE3 - Bank 3 of NOR/SRAM Bank 1~4 */
//#define FSA506_LCD_BASE         ((uint32_t)(0x64000000))
//#define LCD                		((LCDFSMC_TypeDef *) FSA506_LCD_BASE)

//Defines
//amount of images used by the system
#define Number_Of_Images 				52

//Image positions
#define BUTTON_SIZE_X					120
#define BUTTON_SIZE_Y					150
#define SM_LOGO_SIZE_X					400
#define SM_LOGO_SIZE_Y					200

#define LG_LOGO_SIZE_X					1024
#define LG_LOGO_SIZE_Y					600

#define LOCO_HOPPERS_SIZE_X				700
#define LOCO_HOPPERS_SIZE_Y				220

#define LARGE_X						300
#define LARGE_Y						320

#define MEDIUM_X					110
#define MEDIUM_Y					110

#define SMALL_X						30
#define SMALL_Y						40



#define	BUTTON_TOTAL_SIZE				(BUTTON_SIZE_Y*BUTTON_SIZE_X*2) + 224
#define	SM_LOGO_TOTAL_SIZE				(SM_LOGO_SIZE_Y*SM_LOGO_SIZE_X*2) + 256
#define	LG_LOGO_TOTAL_SIZE				(LG_LOGO_SIZE_X*LG_LOGO_SIZE_Y*2) + 256
#define	LOCO_TOTAL_SIZE					(LOCO_HOPPERS_SIZE_X*LOCO_HOPPERS_SIZE_Y*2) + 224
#define	LARGE_TOTAL_SIZE				(LARGE_X*LARGE_Y*2) + 224
#define	MEDIUM_TOTAL_SIZE				(MEDIUM_X*MEDIUM_Y*2) + 128
#define	SMALL_TOTAL_SIZE				(SMALL_X*SMALL_Y*2) + 96

//buffer size
#define IMAGE_BUFFER_SIZE    			256


//Images
#define IMG_BUTTON_UP					1
#define IMG_BUTTON_DOWN					2
#define IMG_BUTTON_LEFT					3
#define IMG_BUTTON_RIGHT				4
#define IMG_BUTTON_ENTER				5
#define IMG_BUTTON_OK					6
#define IMG_BUTTON_FAIL					7
#define IMG_BUTTON_SETTING				8
#define IMG_BUTTON_SHAFT				9
#define IMG_BUTTON_WORK					10
#define IMG_BUTTON_STOP					11
#define IMG_BUTTON_SIREN				12
#define IMG_BUTTON_LOCO_LEFT			13
#define IMG_BUTTON_GAURD_RIGHT			14
#define IMG_SM_LOGO						15
#define IMG_LG_LOGO						16
#define IMG_LOCO_HOPPERS_GAURD_CROSS	17
#define IMG_LOCO_HOPPERS				18
#define IMG_LOCO_HOPPERS_LOCO			19
#define IMG_LOCO_HOPPERS_GAURD			20
#define IMG_LOCO_HOPPER_LEFT			21
#define IMG_GAURD_HOPPER_RIGHT			22
#define IMG_PEDESTRIAN_LG				23
#define IMG_GAURD_RIGHT_RED				24
#define IMG_LOCO_LEFT_RED				25
#define IMG_TRAFFIC_RED					26
#define IMG_TRAFFIC_YELLOW				27
#define IMG_TTM							28
#define IMG_SMILEY_BLUE					29
#define IMG_SMILEY_RED					30
#define IMG_SMILEY_GREEN				31
#define IMG_SMILEY_YELLOW				32
#define IMG_SMILEY_WHITE				33
#define IMG_SMILEY_AMBER				34
#define IMG_SMILEY_PURPLE				35
#define IMG_SMILEY_SAD_RED				36
#define IMG_SMILEY_STRAIGHT_YELLOW		37
#define IMG_DOOR_OPEN					38
#define IMG_TORTOISE					39
#define IMG_HARE						40
#define IMG_PEDESTRIAN_SM				41
#define IMG_ARROW_LEFT_RED				42
#define IMG_ARROW_LEFT_YELLOW			43
#define IMG_ARROW_LEFT_GREEN			44
#define IMG_WARMING						45
#define IMG_NO_SIGNAL					46
#define IMG_LOCO_LEFT_YELLOW			47
#define IMG_LOCO_RIGHT_YELLOW			48
#define IMG_BATTERY_FULL_WHITE			49
#define IMG_SIGNAL_YELLOW				50
#define IMG_SIGNAL_BLUE					51
#define IMG_SIGNAL_WHITE 				52



//defines for images size
// 1 pixel = 2 bytes
#define IMG_01_Size			BUTTON_TOTAL_SIZE
#define IMG_02_Size			BUTTON_TOTAL_SIZE
#define IMG_03_Size			BUTTON_TOTAL_SIZE
#define IMG_04_Size			BUTTON_TOTAL_SIZE
#define IMG_05_Size			BUTTON_TOTAL_SIZE
#define IMG_06_Size			BUTTON_TOTAL_SIZE
#define IMG_07_Size			BUTTON_TOTAL_SIZE
#define IMG_08_Size			BUTTON_TOTAL_SIZE
#define IMG_09_Size			BUTTON_TOTAL_SIZE
#define IMG_10_Size			BUTTON_TOTAL_SIZE
#define IMG_11_Size			BUTTON_TOTAL_SIZE
#define IMG_12_Size			BUTTON_TOTAL_SIZE
#define IMG_13_Size			BUTTON_TOTAL_SIZE
#define IMG_14_Size			BUTTON_TOTAL_SIZE
#define IMG_15_Size			SM_LOGO_TOTAL_SIZE
#define IMG_16_Size			LG_LOGO_TOTAL_SIZE
#define IMG_17_Size			LOCO_TOTAL_SIZE
#define IMG_18_Size			LOCO_TOTAL_SIZE
#define IMG_19_Size			LOCO_TOTAL_SIZE
#define IMG_20_Size			LOCO_TOTAL_SIZE

#define IMG_21_Size			LARGE_TOTAL_SIZE
#define IMG_22_Size			LARGE_TOTAL_SIZE
#define IMG_23_Size			LARGE_TOTAL_SIZE
#define IMG_24_Size			LARGE_TOTAL_SIZE
#define IMG_25_Size			LARGE_TOTAL_SIZE
#define IMG_26_Size			LARGE_TOTAL_SIZE
#define IMG_27_Size			LARGE_TOTAL_SIZE
#define IMG_28_Size			LARGE_TOTAL_SIZE
#define IMG_29_Size			MEDIUM_TOTAL_SIZE
#define IMG_30_Size			MEDIUM_TOTAL_SIZE
#define IMG_31_Size			MEDIUM_TOTAL_SIZE
#define IMG_32_Size			MEDIUM_TOTAL_SIZE
#define IMG_33_Size			MEDIUM_TOTAL_SIZE
#define IMG_34_Size			MEDIUM_TOTAL_SIZE
#define IMG_35_Size			MEDIUM_TOTAL_SIZE
#define IMG_36_Size			MEDIUM_TOTAL_SIZE

#define IMG_37_Size			MEDIUM_TOTAL_SIZE
#define IMG_38_Size			MEDIUM_TOTAL_SIZE
#define IMG_39_Size			MEDIUM_TOTAL_SIZE
#define IMG_40_Size			MEDIUM_TOTAL_SIZE
#define IMG_41_Size			MEDIUM_TOTAL_SIZE
#define IMG_42_Size			MEDIUM_TOTAL_SIZE
#define IMG_43_Size			MEDIUM_TOTAL_SIZE
#define IMG_44_Size			MEDIUM_TOTAL_SIZE
#define IMG_45_Size			MEDIUM_TOTAL_SIZE
#define IMG_46_Size			MEDIUM_TOTAL_SIZE
#define IMG_47_Size			MEDIUM_TOTAL_SIZE
#define IMG_48_Size			MEDIUM_TOTAL_SIZE
#define IMG_49_Size			SMALL_TOTAL_SIZE
#define IMG_50_Size			SMALL_TOTAL_SIZE
#define IMG_51_Size			SMALL_TOTAL_SIZE

#define IMG_52_Size		SMALL_TOTAL_SIZE



// define image addresses
#define IMG_01_Addr			NOR_BLOCK_0
#define IMG_02_Addr			(IMG_01_Addr			+      	 IMG_01_Size)
#define IMG_03_Addr			(IMG_02_Addr			+      	 IMG_02_Size)
#define IMG_04_Addr			(IMG_03_Addr			+      	 IMG_03_Size)
#define IMG_05_Addr			(IMG_04_Addr			+      	 IMG_04_Size)
#define IMG_06_Addr			(IMG_05_Addr			+      	 IMG_05_Size)
#define IMG_07_Addr			(IMG_06_Addr			+      	 IMG_06_Size)
#define IMG_08_Addr			(IMG_07_Addr			+      	 IMG_07_Size)
#define IMG_09_Addr			(IMG_08_Addr			+      	 IMG_08_Size)
#define IMG_10_Addr			(IMG_09_Addr			+      	 IMG_09_Size)
#define IMG_11_Addr			(IMG_10_Addr			+      	 IMG_10_Size)
#define IMG_12_Addr			(IMG_11_Addr			+      	 IMG_11_Size)
#define IMG_13_Addr			(IMG_12_Addr			+      	 IMG_12_Size)
#define IMG_14_Addr			(IMG_13_Addr			+      	 IMG_13_Size)
#define IMG_15_Addr			(IMG_14_Addr			+      	 IMG_14_Size)
#define IMG_16_Addr			(IMG_15_Addr			+      	 IMG_15_Size)
#define IMG_17_Addr			(IMG_16_Addr			+      	 IMG_16_Size)
#define IMG_18_Addr			(IMG_17_Addr			+      	 IMG_17_Size)
#define IMG_19_Addr			(IMG_18_Addr			+      	 IMG_18_Size)
#define IMG_20_Addr			(IMG_19_Addr			+      	 IMG_19_Size)
#define IMG_21_Addr			(IMG_20_Addr			+      	 IMG_20_Size)
#define IMG_22_Addr			(IMG_21_Addr			+      	 IMG_21_Size)
#define IMG_23_Addr			(IMG_22_Addr			+      	 IMG_22_Size)
#define IMG_24_Addr			(IMG_23_Addr			+      	 IMG_23_Size)
#define IMG_25_Addr			(IMG_24_Addr			+      	 IMG_24_Size)
#define IMG_26_Addr			(IMG_25_Addr			+      	 IMG_25_Size)
#define IMG_27_Addr			(IMG_26_Addr			+      	 IMG_26_Size)
#define IMG_28_Addr			(IMG_27_Addr			+      	 IMG_27_Size)
#define IMG_29_Addr			(IMG_28_Addr			+      	 IMG_28_Size)
#define IMG_30_Addr			(IMG_29_Addr			+      	 IMG_29_Size)
#define IMG_31_Addr			(IMG_30_Addr			+      	 IMG_30_Size)
#define IMG_32_Addr			(IMG_31_Addr			+      	 IMG_31_Size)
#define IMG_33_Addr			(IMG_32_Addr			+      	 IMG_32_Size)
#define IMG_34_Addr			(IMG_33_Addr			+      	 IMG_33_Size)
#define IMG_35_Addr			(IMG_34_Addr			+      	 IMG_34_Size)
#define IMG_36_Addr			(IMG_35_Addr			+      	 IMG_35_Size)
#define IMG_37_Addr			(IMG_36_Addr			+      	 IMG_36_Size)
#define IMG_38_Addr			(IMG_37_Addr			+      	 IMG_37_Size)
#define IMG_39_Addr			(IMG_38_Addr			+      	 IMG_38_Size)
#define IMG_40_Addr			(IMG_39_Addr			+      	 IMG_39_Size)
#define IMG_41_Addr			(IMG_40_Addr			+      	 IMG_40_Size)
#define IMG_42_Addr			(IMG_41_Addr			+      	 IMG_41_Size)
#define IMG_43_Addr			(IMG_42_Addr			+      	 IMG_42_Size)
#define IMG_44_Addr			(IMG_43_Addr			+      	 IMG_43_Size)
#define IMG_45_Addr			(IMG_44_Addr			+      	 IMG_44_Size)
#define IMG_46_Addr			(IMG_45_Addr			+      	 IMG_45_Size)
#define IMG_47_Addr			(IMG_46_Addr			+      	 IMG_46_Size)
#define IMG_48_Addr			(IMG_47_Addr			+      	 IMG_47_Size)
#define IMG_49_Addr			(IMG_48_Addr			+      	 IMG_48_Size)
#define IMG_50_Addr			(IMG_49_Addr			+      	 IMG_49_Size)
#define IMG_51_Addr			(IMG_50_Addr			+      	 IMG_50_Size)
#define IMG_52_Addr			(IMG_51_Addr			+      	 IMG_51_Size)


//variables made public
typedef struct {
	uint32_t size;
	uint16_t X_size;
	uint16_t Y_size;
	uint32_t address;
	uint8_t  index;
} image_t;

extern uint8_t Flash_Disk_ImageCount;
extern uint8_t Image_Buf[IMAGE_BUFFER_SIZE];
extern const image_t image[Number_Of_Images + 1];


//Functions made public
void DisplayImage(uint16_t x, uint16_t y, uint16_t index);
void Display_all(void);
void DMA_Configuration(uint32_t SRAM_BufferAddress, uint32_t NOR_ReadAddr, uint32_t size);
//void NOR_DMAImageTransfer(uint32_t ReadAddr, uint32_t size);
void NOR_DMAImageTransfer(uint32_t ReadAddr, uint32_t size,uint32_t count);


#endif /* MAXUSX_IMAGES_H_ */
