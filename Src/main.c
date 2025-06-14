//Where is the led connected?
//Port:  A
//Pin:   5

#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE	        (PERIPH_BASE + AHB1PERIPH_OFFSET) // 0x40020000

#define GPIOA_OFFSET			(0x0000UL)
#define GPIOB_OFFSET            (0x0400UL)
#define GPIOC_OFFSET            (0x0800UL)
#define GPIOD_OFFSET            (0x0C00UL)

#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET) // 0x40020000
#define GPIOB_BASE              (AHB1PERIPH_BASE + GPIOB_OFFSET) // 0x40020400
#define GPIOC_BASE              (AHB1PERIPH_BASE + GPIOC_OFFSET) // 0x40020800
#define GPIOD_BASE              (AHB1PERIPH_BASE + GPIOD_OFFSET) // 0x40020C00

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)//0x40023800


#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R            (*(volatile unsigned int *)(RCC_BASE +  AHB1EN_R_OFFSET)) //0x40023830

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))  //0x40020000
#define GPIOB_MODE_R            (*(volatile unsigned int *)(GPIOB_BASE + MODE_R_OFFSET))
#define GPIOC_MODE_R			(*(volatile unsigned int *)(GPIOC_BASE + MODE_R_OFFSET))
#define GPIOD_MODE_R			(*(volatile unsigned int *)(GPIOD_BASE + MODE_R_OFFSET))


#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET)) //0x40021400
#define GPIOB_OD_R              (*(volatile unsigned int *)(GPIOB_BASE + OD_R_OFFSET))
#define GPIOC_OD_R				(*(volatile unsigned int *)(GPIOC_BASE + OD_R_OFFSET))
#define GPIOD_OD_R				(*(volatile unsigned int *)(GPIOD_BASE + OD_R_OFFSET))
     /*ALL the PORT clock ENABLE*/
#define GPIOAEN				   (1U<<0) //   0b 0000 0000 0000 0000 0000 0000 0000 0001  Enable port A clock
#define GPIOBEN                (1U<<1)       // Enable port B clock
#define GPIOCEN                (1U<<2)       // Enable port C clock
#define GPIODEN                (1U<<3)       // Enable port D clock

#define PIN5				   (1U<<5)
#define LED_PIN_A5			   (PIN5)
#define PIN10                  (1U<<10)
#define LED_PIN_A10			   (PIN10)
#define PIN8  				   (1U<<8)
#define LED_PIN_B8     		   (PIN8)
#define PIN8  				   (1U<<8)
#define LED_PIN_C8     		   (PIN8)
#define PIN2  				   (1U<<2)
#define LED_PIN_D2     		   (PIN2)

int main(void)
{
	/*1. Enable clock access to GPIOA*/
	RCC_AHB1EN_R  |=  GPIOAEN; //0x40023831
	RCC_AHB1EN_R  |=  GPIOBEN;
	RCC_AHB1EN_R  |=  GPIOCEN;
	RCC_AHB1EN_R  |=  GPIODEN;

	/*2.Set PA5 as output pin*/
	GPIOA_MODE_R  |= (1U<<10);  // Set bit 10 to 1
	GPIOA_MODE_R  &=~(1U<<11);  //  Set bit 11 to 0
	/*2.Set PA10 as output pin*/
	GPIOA_MODE_R  |= (1U<<20);  // set bit 20 to 1
    GPIOA_MODE_R  &=~(1U<<21);  // set bit 21 to 0

    /*2.Set PB8 as output pin*/
    GPIOB_MODE_R  |= (1U<<16);  // set bit 16 to 1
    GPIOB_MODE_R  &=~(1U<<17);  // set bit 17 to 0

    /*2.Set PC8 as output pin*/
   	GPIOC_MODE_R  |= (1U<<16);  // set bit 16 to 1
    GPIOC_MODE_R  &=~(1U<<17);  // set bit 17 to 0

    /*2.Set PD2 as output pin*/
   	GPIOD_MODE_R  |= (1U<<4);  // set bit 4 to 1
    GPIOD_MODE_R  &=~(1U<<5);  // set bit 5 to 0

    while(1)
	{
		/*3.Set PA5 high*/
		//GPIOA_OD_R |= LED_PIN;

		/*4:Experiment 2 : toggle PA5*/
		GPIOA_OD_R |= LED_PIN_A5;
		GPIOA_OD_R |= LED_PIN_A10;
	    GPIOB_OD_R |= LED_PIN_B8;
		GPIOC_OD_R |= LED_PIN_C8;
		GPIOD_OD_R |= LED_PIN_D2;
		//for(int i=0;i<100000;i++){}

	}
}



