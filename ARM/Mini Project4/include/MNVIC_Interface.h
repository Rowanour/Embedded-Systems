/*
 * MNVIC_Interface.h
 *
 *  Created on: Feb 4, 2024
 *      Author: r0wan
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

typedef enum
{
	Groups16_NoSub  =3,
	Groups8_Sub2      ,
	Groups4_Sub4      ,
	Groups2_Sub8      ,
	NoGroups_Sub16

}MNVIC_Group_t;

void MNVIC_voidEnablePeripheralInterrupt(u8 copy_u8Peripheral);
void MNVIC_voidDisablePeripheralInterrupt(u8 copy_u8Peripheral);

void MNVIC_voidSetPeripheralInterruptPending(u8 copy_u8Peripheral);
void MNVIC_voidClearPeripheralInterruptPending(u8 copy_u8Peripheral);

void MNVIC_voidGetInterruptState(u8 copy_u8Peripheral , u8 *p_Read);

void MNVIC_voidSetInetrruptGroupMode(MNVIC_Group_t MNVIC_Group_t_Mode);

void MNVIC_voidSetInterruptPriority(u8 copy_u8Peripheral ,u8 copy_u8GroupNumber ,u8 copy_u8Sub);

#endif /* MNVIC_INTERFACE_H_ */
