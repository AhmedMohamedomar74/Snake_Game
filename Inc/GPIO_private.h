/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  12 AUG 2020           */
/*Version  :  V01                   */
/************************************/


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H



#define GPIOA_BASE_ADDRESS 0X40010800
#define GPIOB_BASE_ADDRESS 0X40010C00
#define GPIOC_BASE_ADDRESS 0X40011000

/* REGISTERS ADDRESSES FOR PORT A */
#define GPIOA_CRL          *((u32*)(GPIOA_BASE_ADDRESS + 0X00))
#define GPIOA_CRH          *((u32*)(GPIOA_BASE_ADDRESS + 0X04))
#define GPIOA_IDR          *((u32*)(GPIOA_BASE_ADDRESS + 0X08))
#define GPIOA_ODR          *((u32*)(GPIOA_BASE_ADDRESS + 0X0C))
#define GPIOA_BSR          *((u32*)(GPIOA_BASE_ADDRESS + 0X10))
#define GPIOA_BRR          *((u32*)(GPIOA_BASE_ADDRESS + 0X14))
#define GPIOA_LCK          *((u32*)(GPIOA_BASE_ADDRESS + 0X18))

/* REGISTERS ADDRESSES FOR PORT B */
#define GPIOB_CRL          *((u32*)(GPIOB_BASE_ADDRESS + 0X00))
#define GPIOB_CRH          *((u32*)(GPIOB_BASE_ADDRESS + 0X04))
#define GPIOB_IDR          *((u32*)(GPIOB_BASE_ADDRESS + 0X08))
#define GPIOB_ODR          *((u32*)(GPIOB_BASE_ADDRESS + 0X0C))
#define GPIOB_BSR          *((u32*)(GPIOB_BASE_ADDRESS + 0X10))
#define GPIOB_BRR          *((u32*)(GPIOB_BASE_ADDRESS + 0X14))
#define GPIOB_LCK          *((u32*)(GPIOB_BASE_ADDRESS + 0X18))

/* REGISTERS ADDRESSES FOR PORT C */
#define GPIOC_CRL          *((u32*)(GPIOC_BASE_ADDRESS + 0X00))
#define GPIOC_CRH          *((u32*)(GPIOC_BASE_ADDRESS + 0X04))
#define GPIOC_IDR          *((u32*)(GPIOC_BASE_ADDRESS + 0X08))
#define GPIOC_ODR          *((u32*)(GPIOC_BASE_ADDRESS + 0X0C))
#define GPIOC_BSR          *((u32*)(GPIOC_BASE_ADDRESS + 0X10))
#define GPIOC_BRR          *((u32*)(GPIOC_BASE_ADDRESS + 0X14))
#define GPIOC_LCK          *((u32*)(GPIOC_BASE_ADDRESS + 0X18))




#endif
