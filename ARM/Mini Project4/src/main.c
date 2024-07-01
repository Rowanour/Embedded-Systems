
/************ LIB **************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

			/* MCAL */
#include "../include/MRCC_Interface.h"
#include "../include/MSTK_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MDMA_Interface.h"

void dmaCallback();

int main(void){
	u32 srcArray[1000];
	u32 destArray[1000];

	u32 tempArray1[1000];
	u32 tempArray2[1000];

	for(u16 i = 0 ; i < 1000 ; i++){
		srcArray[i] = 2;
		tempArray1[i] = 7;
	}

	MRCC_voidInit();
	MSTK_voidInit();

	MRCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_GPIOA); // Enable GPIOA clock
	MRCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_DMA2);  // Enable DMA2 clock

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN0, GPIO_PUSH_PULL, GPIO_HIGH_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN1, GPIO_PUSH_PULL, GPIO_HIGH_SPEED);

	MNVIC_voidEnablePeripheralInterrupt(DMA_Stream0);   // Enable DMA Stream0 interrupt

	DMA2_Init();

	DMA2_SetStreamConfigration(0,0,tempArray1,tempArray2,2,1000);

	DMA2_SetCallBack(0,dmaCallback);

	DMA2_enableStream(0);

	for(u16 i = 0 ; i < 1000 ; i++){
		destArray[i] = srcArray[i];
	}

	MSTK_voidDelayms(1000);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);

}

void dmaCallback(void){
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH);
	MSTK_voidDelayms(1000);
}
