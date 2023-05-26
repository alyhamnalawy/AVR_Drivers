///*
// * Calculator.c
// *
// *  Created on: Mar 28, 2023
// *      Author: Ali Ehab
// */
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD/LCD_interface.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../HAL/KeyPad/KeyPad_interface.h"
//#include <util/delay.h>
//
//void main(void)
//{
//	u8 num1,num2,operation,result,op2,val,flag=1;
//	KPD_voidinit();
//	LCD_voidinit();
//	while(1)
//	{
//		do
//		{
//			val=KPD_u8GetPressedKey();
//		}while(val==255);
//		LCD_voidSendData(val);
////		do
////		{
////			num2=KPD_u8GetPressedKey();
////		}while(num2==255);
////		LCD_voidSendData(num2);
////		do
////		{
////			operation=KPD_u8GetPressedKey();
////		}while(operation==255);
////		LCD_voidSendData(operation);
////		num1-=48;
////		num2-=48;
//		    switch(val){
//		        case '+':
//		            //result = num1 + num2;
//		        	operation='+';
//		        	flag=2;
//		            break;
//
//		        case '-':
//		            //result = num1 - num2;
//		        	operation='-';
//		        	flag=2;
//		            break;
//
//		        case '*':
//		            //result = num1 * num2;
//		        	operation='*';
//		        	flag=2;
//		            break;
//
//		        case '/':
////		            if(num2 == 0) {
////		            	LCD_voidSendString("Cannot divide by zero");
////		            } else {
////		                result = num1 / num2;
////		            }
//		        	operation='/';
//		        	flag=2;
//		            break;
//		        case '=':
//		        	switch(operation)
//		        	{
//		        	case '+':result=num1+num2; break;
//		        	case '-':result=num1-num2; break;
//		        	case '*':result=num1*num2; break;
//		        	case '/':if(num2 == 0) {
//		        		            	LCD_voidSendString("Cannot divide by zero");
//		        		            } else {
//		        		                result = num1 / num2;
//		        		            }
//		        	break;
//		        	LCD_voidSendData(result);
//		        	}
//
//		        default:
//		        	//LCD_voidSendString("Invalid operator");
//		        	if (flag==1)
//		        	{
//		        		num1=val-48;
//		        	}
//		        	else
//		        	{
//		        		num2=val-48;
//		        		flag=1;
//		        	}
//		        	break;
//		    }
//
//	}
//}
