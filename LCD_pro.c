/*

 * LCD_pro.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Rehab Khaled
 */

#include <util/delay.h>
#include "../LIB/BIT_Utils.h"
#include "../LIB/STD_Types.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/DIO/DIO_prv.h"
#include "../MCAL/DIO/DIO_cfg.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
u8 step_BIT_TRANSLET=0;

void LCD_voidInit(void)
{
	DIO_vidInit();


	_delay_ms(30);

	LCD_voidWriteCommand (0x20);
	LCD_voidWriteCommand (0x20);
	LCD_voidWriteCommand (0x80);
	_delay_ms(1);
	LCD_voidWriteCommand (0x00);
	LCD_voidWriteCommand (0xF0);
	_delay_ms(1);
	LCD_voidWriteCommand (0x00);
	LCD_voidWriteCommand (0xF0);
	_delay_ms(1);
	LCD_voidWriteCommand (0x00);
	LCD_voidWriteCommand (0xF0);
	_delay_ms(1);

	step_BIT_TRANSLET=1;


}




void LCD_voidWriteCommand(u8 copy_u8Command)
{
    switch (LCD_u8_DATA_LENGTH_MODE)
    {
    case LCD_u8_4_BIT_MODE :

    	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3,DIO_u8_LOW );


    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(copy_u8Command,DIO_u8_PIN4));
 	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(copy_u8Command,DIO_u8_PIN5));
 	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(copy_u8Command,DIO_u8_PIN6));
 	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(copy_u8Command,DIO_u8_PIN7));

 	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_HIGH );
 	_delay_ms(1);
 	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_LOW );
 	_delay_ms(1);

if (step_BIT_TRANSLET)
{
 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(copy_u8Command,DIO_u8_PIN0));
 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(copy_u8Command,DIO_u8_PIN1));
 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(copy_u8Command,DIO_u8_PIN2));
 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(copy_u8Command,DIO_u8_PIN3));



    	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_HIGH );
 		_delay_ms(1);
 		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_LOW );
 		_delay_ms(1);
}

 		break;

    case    LCD_u8_8_BIT_MODE :



    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(copy_u8Command,DIO_u8_PIN0));
    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(copy_u8Command,DIO_u8_PIN1));
     DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(copy_u8Command,DIO_u8_PIN2));
      DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(copy_u8Command,DIO_u8_PIN3));


     DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(copy_u8Command,DIO_u8_PIN4));
    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(copy_u8Command,DIO_u8_PIN5));
    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(copy_u8Command,DIO_u8_PIN6));
    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(copy_u8Command,DIO_u8_PIN7));

    DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_HIGH );
    _delay_ms(1);
    DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_LOW );
    _delay_ms(1);



    break;
       		}


}
void LCD_voidWriteData(u8 copy_u8data)
{
	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3,DIO_u8_HIGH );

	    DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0,GET_BIT (copy_u8data,DIO_u8_PIN4));
	 	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(copy_u8data,DIO_u8_PIN5));
	 	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(copy_u8data,DIO_u8_PIN6));
	 	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(copy_u8data,DIO_u8_PIN7));

	 	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_HIGH );
	 	_delay_ms(1);
	 	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_LOW );
	 	_delay_ms(1);


	 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(copy_u8data,DIO_u8_PIN0));
	 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(copy_u8data,DIO_u8_PIN1));
	 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(copy_u8data,DIO_u8_PIN2));
	 		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(copy_u8data,DIO_u8_PIN3));



	    	DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_HIGH );
	 		_delay_ms(1);
	 		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2,DIO_u8_LOW );
	 		_delay_ms(1);


}

void LCD_voidWriteString(u8 * copy_str)
{
	while(*(copy_str)!=0)
	{
		LCD_voidWriteData(*copy_str);
		copy_str++; // make the pointer points to the next character
	}
}

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col)
{
u8 Address;
Address=((copy_u8Row *0x40)+copy_u8Col);
Address=(SET_BIT(Address, DIO_u8_PIN7)	);
LCD_voidWriteCommand(Address);
}

;
void LCD_voidClear(void)
{
	LCD_voidWriteCommand(0x01);
}

LCD_voidWriteNumber( u32 Copy_u8num )
{
	u8 str[10]={0},i=0 ,j;
			if(Copy_u8num==0)
			{
				LCD_voidWriteData('0');
				return;
			}
			if(Copy_u8num<0)
			{
				Copy_u8num=Copy_u8num*(-1);
				LCD_voidWriteData('-');
			}

			while(Copy_u8num!=0)
			{
				str[i]=Copy_u8num%10 +'0';
				Copy_u8num=Copy_u8num/10;
				i++;

			}

			for (j=i;j>0;j--)
			{
				LCD_voidWriteData(str[j-1]);
			}

}
void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum )
{
	u8 Address;
	// 8 lacation in CGRAM
	if(copy_u8ByteNum<8)
	{
		// in 1location have 8address itold you do to lacation you need
		Address=copy_u8ByteNum*8;
		//from instruction to set CGRAM ADD
		Address=SET_BIT(Address,DIO_u8_PIN6) ;
		LCD_voidWriteCommand(Address);

		//To move in all location on add pattern //array
			for (u8 Index=0;Index <=7 ;Index ++)
			{
				LCD_voidWriteData(copy_u8data[Index]);
			}

	}


	LCD_voidWriteCommand(0x02);  // from data sheet to return home
}

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum )
{

	LCD_voidWriteData(copy_u8ByteNum);
}
