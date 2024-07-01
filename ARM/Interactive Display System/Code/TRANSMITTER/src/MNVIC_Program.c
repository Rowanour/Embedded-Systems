

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/* MCAL */

#include "../include/MNVIC_Config.h"
#include "../include/MNVIC_Private.h"
#include "../include/MNVIC_Interface.h"

static MNVIC_Group_t sglobal_NVIC_Group_t_Mode;

void MNVIC_voidEnablePeripheralInterrupt(u8 copy_u8Peripheral)
{
	SET_BIT(NVIC->ISER[copy_u8Peripheral/BITS_IN_REGISTER],(copy_u8Peripheral%BITS_IN_REGISTER));

}
void MNVIC_voidDisablePeripheralInterrupt(u8 copy_u8Peripheral)
{
	SET_BIT(NVIC->ICER[copy_u8Peripheral/BITS_IN_REGISTER],(copy_u8Peripheral%BITS_IN_REGISTER));

}
void MNVIC_voidSetPeripheralInterruptPending(u8 copy_u8Peripheral)
{
	SET_BIT(NVIC->ISPR[copy_u8Peripheral/BITS_IN_REGISTER],(copy_u8Peripheral%BITS_IN_REGISTER));
}
void MNVIC_voidClearPeripheralInterruptPending(u8 copy_u8Peripheral)
{
	SET_BIT(NVIC->ICPR[copy_u8Peripheral/BITS_IN_REGISTER],(copy_u8Peripheral%BITS_IN_REGISTER));

}
void MNVIC_voidGetInterruptState(u8 copy_u8Peripheral , u8 *p_Read)
{
   *p_Read = GET_BIT(NVIC->IABR[copy_u8Peripheral/BITS_IN_REGISTER],(copy_u8Peripheral%BITS_IN_REGISTER));
}
void MNVIC_voidSetInetrruptGroupMode(MNVIC_Group_t MNVIC_Group_t_Mode)
{
	sglobal_NVIC_Group_t_Mode = MNVIC_Group_t_Mode;
	SCB_AIRCR = (SCB_AIRCR_VECT_KEY | MNVIC_Group_t_Mode << AICIR_PRIGROUP_B0);

}
void MNVIC_voidSetInterruptPriority(u8 copy_u8Peripheral ,u8 copy_u8GroupNumber ,u8 copy_u8Sub)
{
  switch(sglobal_NVIC_Group_t_Mode){
  case Groups16_NoSub:
	  NVIC ->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 4);
	  break;
  case Groups8_Sub2:
	  NVIC ->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 5 | copy_u8Sub << 4);
	  break;
  case Groups4_Sub4:
	  NVIC ->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 6 | copy_u8Sub << 4);
	  break;
  case Groups2_Sub8:
	  NVIC ->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 7 | copy_u8Sub << 4);
	  break;
  case NoGroups_Sub16:
	  NVIC ->IPR[copy_u8Peripheral] = (copy_u8Sub << 4);
	  break;
  default:
	  break;
  }
}

