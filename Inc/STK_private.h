/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  25 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct {
	volatile u32 CTRL   ;
	volatile u32 LOAD   ;
	volatile u32 VAL  ;
	volatile u32 CALIB ;

} STK_t;

#define STK ((volatile STK_t *)(0xE000E010))


#define     STK_SRC_AHB            0
#define     STK_SRC_AHB_8          1

#define     STK_ONEC               0
#define     STK_PERIODIC           1




// Control Register (CTRL)
#define STK_CTRL_ENABLE         0  
#define STK_CTRL_TICKINT        1  
#define STK_CTRL_CLKSEL         2  
#define STK_CTRL_COUNTFLAG      16 

// Load Register (LOAD)
#define STK_LOAD_MASK           0xFFFFFF  

#endif
