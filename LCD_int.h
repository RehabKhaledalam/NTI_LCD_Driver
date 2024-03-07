/*

 * LCD_int.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Rehab Khaled
 */

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_


void LCD_voidInit(void);
void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);



void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);

void LCD_voidWriteNumber( u32 Copy_u8num );


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;


#endif /* HAL_LCD_INT_H_ */
