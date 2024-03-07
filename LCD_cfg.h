/*

 * LCD_cfg.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Rehab Khaled
 */

#ifndef HAL_LCD_CFG_H_
#define HAL_LCD_CFG_H_




/* choose from DIO Control Pin from DIO driver */

#define LCD_u8_RS_PORT				DIO_u8_PORTA
#define LCD_u8_RS_PIN				DIO_u8_PIN3

#define LCD_u8_E_PORT				DIO_u8_PORTA
#define LCD_u8_E_PIN				DIO_u8_PIN2



/* choose from DIO Control Pin from DIO driver */

#define LCD_u8_Data_Port         DIO_u8_PORTB




/* OPTIONS :
 * 		LCD_u8_8_BIT_MODE
 * 		LCD_u8_4_BIT_MODE
 */
#define LCD_u8_8_BIT_MODE           0
#define LCD_u8_4_BIT_MODE           1

#define LCD_u8_DATA_LENGTH_MODE		LCD_u8_4_BIT_MODE


#endif /* HAL_LCD_CFG_H_ */
