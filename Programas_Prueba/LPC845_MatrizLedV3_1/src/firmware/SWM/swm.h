/*
 * swm.h
 *
 *  Created on: 25 sep. 2023
 *      Author: Gabriel Soccodato
 */

#ifndef FIRMWARE_SWM_H_
#define FIRMWARE_SWM_H_

/*! @brief SWM port_pin number */
typedef enum _swm_port_pin_type_t
{
    kSWM_PortPin_P0_0 = 0U,   /*!< port_pin number P0_0. */
    kSWM_PortPin_P0_1 = 1U,   /*!< port_pin number P0_1. */
    kSWM_PortPin_P0_2 = 2U,   /*!< port_pin number P0_2. */
    kSWM_PortPin_P0_3 = 3U,   /*!< port_pin number P0_3. */
    kSWM_PortPin_P0_4 = 4U,   /*!< port_pin number P0_4. */
    kSWM_PortPin_P0_5 = 5U,   /*!< port_pin number P0_5. */
    kSWM_PortPin_P0_6 = 6U,   /*!< port_pin number P0_6. */
    kSWM_PortPin_P0_7 = 7U,   /*!< port_pin number P0_7. */
    kSWM_PortPin_P0_8 = 8U,   /*!< port_pin number P0_8. */
    kSWM_PortPin_P0_9 = 9U,   /*!< port_pin number P0_9. */
    kSWM_PortPin_P0_10 = 10U, /*!< port_pin number P0_10. */
    kSWM_PortPin_P0_11 = 11U, /*!< port_pin number P0_11. */
    kSWM_PortPin_P0_12 = 12U, /*!< port_pin number P0_12. */
    kSWM_PortPin_P0_13 = 13U, /*!< port_pin number P0_13. */
    kSWM_PortPin_P0_14 = 14U, /*!< port_pin number P0_14. */
    kSWM_PortPin_P0_15 = 15U, /*!< port_pin number P0_15. */
    kSWM_PortPin_P0_16 = 16U, /*!< port_pin number P0_16. */
    kSWM_PortPin_P0_17 = 17U, /*!< port_pin number P0_17. */
    kSWM_PortPin_P0_18 = 18U, /*!< port_pin number P0_18. */
    kSWM_PortPin_P0_19 = 19U, /*!< port_pin number P0_19. */
    kSWM_PortPin_P0_20 = 20U, /*!< port_pin number P0_20. */
    kSWM_PortPin_P0_21 = 21U, /*!< port_pin number P0_21. */
    kSWM_PortPin_P0_22 = 22U, /*!< port_pin number P0_22. */
    kSWM_PortPin_P0_23 = 23U, /*!< port_pin number P0_23. */
    kSWM_PortPin_P0_24 = 24U, /*!< port_pin number P0_24. */
    kSWM_PortPin_P0_25 = 25U, /*!< port_pin number P0_25. */
    kSWM_PortPin_P0_26 = 26U, /*!< port_pin number P0_26. */
    kSWM_PortPin_P0_27 = 27U, /*!< port_pin number P0_27. */
    kSWM_PortPin_P0_28 = 28U, /*!< port_pin number P0_28. */
    kSWM_PortPin_P0_29 = 29U, /*!< port_pin number P0_29. */
    kSWM_PortPin_P0_30 = 30U, /*!< port_pin number P0_30. */
    kSWM_PortPin_P0_31 = 31U, /*!< port_pin number P0_31. */

    kSWM_PortPin_P1_0 = 32U,  /*!< port_pin number P1_0. */
    kSWM_PortPin_P1_1 = 33U,  /*!< port_pin number P1_1. */
    kSWM_PortPin_P1_2 = 34U,  /*!< port_pin number P1_2. */
    kSWM_PortPin_P1_3 = 35U,  /*!< port_pin number P1_3. */
    kSWM_PortPin_P1_4 = 36U,  /*!< port_pin number P1_4. */
    kSWM_PortPin_P1_5 = 37U,  /*!< port_pin number P1_5. */
    kSWM_PortPin_P1_6 = 38U,  /*!< port_pin number P1_6. */
    kSWM_PortPin_P1_7 = 39U,  /*!< port_pin number P1_7. */
    kSWM_PortPin_P1_8 = 40U,  /*!< port_pin number P1_8. */
    kSWM_PortPin_P1_9 = 41U,  /*!< port_pin number P1_9. */
    kSWM_PortPin_P1_10 = 42U, /*!< port_pin number P1_10. */
    kSWM_PortPin_P1_11 = 43U, /*!< port_pin number P1_11. */
    kSWM_PortPin_P1_12 = 44U, /*!< port_pin number P1_12. */
    kSWM_PortPin_P1_13 = 45U, /*!< port_pin number P1_13. */
    kSWM_PortPin_P1_14 = 46U, /*!< port_pin number P1_14. */
    kSWM_PortPin_P1_15 = 47U, /*!< port_pin number P1_15. */
    kSWM_PortPin_P1_16 = 48U, /*!< port_pin number P1_16. */
    kSWM_PortPin_P1_17 = 49U, /*!< port_pin number P1_17. */
    kSWM_PortPin_P1_18 = 50U, /*!< port_pin number P1_18. */
    kSWM_PortPin_P1_19 = 51U, /*!< port_pin number P1_19. */
    kSWM_PortPin_P1_20 = 52U, /*!< port_pin number P1_20. */
    kSWM_PortPin_P1_21 = 53U, /*!< port_pin number P1_21. */
    kSWM_PortPin_Reset = 0xffU /*!< port_pin reset number. */
} swm_port_pin_type_t;

/*! @brief SWM movable selection */
typedef enum _swm_select_movable_t
{
    kSWM_USART0_TXD = 0U,  /*!< Movable function as USART0_TXD. */
    kSWM_USART0_RXD = 1U,  /*!< Movable function as USART0_RXD. */
    kSWM_USART0_RTS = 2U,  /*!< Movable function as USART0_RTS. */
    kSWM_USART0_CTS = 3U,  /*!< Movable function as USART0_CTS. */
    kSWM_USART0_SCLK = 4U, /*!< Movable function as USART0_SCLK. */

    kSWM_USART1_TXD = 5U,  /*!< Movable function as USART1_TXD. */
    kSWM_USART1_RXD = 6U,  /*!< Movable function as USART1_RXD. */
    kSWM_USART1_RTS = 7U,  /*!< Movable function as USART1_RTS. */
    kSWM_USART1_CTS = 8U,  /*!< Movable function as USART1_CTS. */
    kSWM_USART1_SCLK = 9U, /*!< Movable function as USART1_SCLK. */

    kSWM_USART2_TXD = 10U,  /*!< Movable function as USART2_TXD. */
    kSWM_USART2_RXD = 11U,  /*!< Movable function as USART2_RXD. */
    kSWM_USART2_RTS = 12U,  /*!< Movable function as USART2_RTS. */
    kSWM_USART2_CTS = 13U,  /*!< Movable function as USART2_CTS. */
    kSWM_USART2_SCLK = 14U, /*!< Movable function as USART2_SCLK. */

    kSWM_SPI0_SCK = 15U,   /*!< Movable function as SPI0_SCK. */
    kSWM_SPI0_MOSI = 16U,  /*!< Movable function as SPI0_MOSI. */
    kSWM_SPI0_MISO = 17U,  /*!< Movable function as SPI0_MISO. */
    kSWM_SPI0_SSEL0 = 18U, /*!< Movable function as SPI0_SSEL0. */
    kSWM_SPI0_SSEL1 = 19U, /*!< Movable function as SPI0_SSEL1. */
    kSWM_SPI0_SSEL2 = 20U, /*!< Movable function as SPI0_SSEL2. */
    kSWM_SPI0_SSEL3 = 21U, /*!< Movable function as SPI0_SSEL3. */

    kSWM_SPI1_SCK = 22U,   /*!< Movable function as SPI1_SCK. */
    kSWM_SPI1_MOSI = 23U,  /*!< Movable function as SPI1_MOSI. */
    kSWM_SPI1_MISO = 24U,  /*!< Movable function as SPI1_MISO. */
    kSWM_SPI1_SSEL0 = 25U, /*!< Movable function as SPI1_SSEL0. */
    kSWM_SPI1_SSEL1 = 26U, /*!< Movable function as SPI1_SSEL1. */

    kSWM_SCT_PIN0 = 27U, /*!< Movable function as SCT_PIN0. */
    kSWM_SCT_PIN1 = 28U, /*!< Movable function as SCT_PIN1. */
    kSWM_SCT_PIN2 = 29U, /*!< Movable function as SCT_PIN2. */
    kSWM_SCT_PIN3 = 30U, /*!< Movable function as SCT_PIN3. */
    kSWM_SCT_OUT0 = 31U, /*!< Movable function as SCT_OUT0. */
    kSWM_SCT_OUT1 = 32U, /*!< Movable function as SCT_OUT1. */
    kSWM_SCT_OUT2 = 33U, /*!< Movable function as SCT_OUT2. */
    kSWM_SCT_OUT3 = 34U, /*!< Movable function as SCT_OUT3. */
    kSWM_SCT_OUT4 = 35U, /*!< Movable function as SCT_OUT4. */
    kSWM_SCT_OUT5 = 36U, /*!< Movable function as SCT_OUT5. */
    kSWM_SCT_OUT6 = 37U, /*!< Movable function as SCT_OUT6. */

    kSWM_I2C1_SDA = 38U, /*!< Movable function as I2C1_SDA. */
    kSWM_I2C1_SCL = 39U, /*!< Movable function as I2C1_SCL. */
    kSWM_I2C2_SDA = 40U, /*!< Movable function as I2C2_SDA. */
    kSWM_I2C2_SCL = 41U, /*!< Movable function as I2C2_SCL. */
    kSWM_I2C3_SDA = 42U, /*!< Movable function as I2C3_SDA. */
    kSWM_I2C3_SCL = 43U, /*!< Movable function as I2C3_SCL. */

    kSWM_ACMP_OUT = 44U,      /*!< Movable function as ACMP_OUT. */
    kSWM_CLKOUT = 45U,        /*!< Movable function as CLKOUT. */
    kSWM_GPIO_INT_BMAT = 46U, /*!< Movable function as GPIO_INT_BMAT. */

    kSWM_USART3_TXD = 47U,  /*!< Movable function as USART3_TXD. */
    kSWM_USART3_RXD = 48U,  /*!< Movable function as USART3_RXD. */
    kSWM_USART3_SCLK = 49U, /*!< Movable function as USART3_SCLK. */
    kSWM_USART4_TXD = 50U,  /*!< Movable function as USART4_TXD. */
    kSWM_USART4_RXD = 51U,  /*!< Movable function as USART4_RXD. */
    kSWM_USART4_SCLK = 52U, /*!< Movable function as USART4_SCLK. */
    kSWM_T0_MAT_CHN0 = 53U, /*!< Movable function as Timer Match Channel 0. */
    kSWM_T0_MAT_CHN1 = 54U, /*!< Movable function as Timer Match Channel 1. */
    kSWM_T0_MAT_CHN2 = 55U, /*!< Movable function as Timer Match Channel 2. */
    kSWM_T0_MAT_CHN3 = 56U, /*!< Movable function as Timer Match Channel 3. */
    kSWM_T0_CAP_CHN0 = 57U, /*!< Movable function as Timer Capture Channel 0. */
    kSWM_T0_CAP_CHN1 = 58U, /*!< Movable function as Timer Capture Channel 1. */
    kSWM_T0_CAP_CHN2 = 59U, /*!< Movable function as Timer Capture Channel 2. */

    kSWM_MOVABLE_NUM_FUNCS = 60U, /*!< Movable function number. */
} swm_select_movable_t;

void SWM_SetMovablePinSelect(swm_select_movable_t, swm_port_pin_type_t);

#define		PIN_ASSIGN			(( volatile uint32_t*)	0x4000C000)

#define		PA_U0_TXD			0
#define		PA_U0_RXD			1
#define		PA_U0_RTS			2
#define		PA_U0_CTS			3
#define		PA_U0_SCLK			4
#define		PA_U1_TXD			5
#define		PA_U1_RXD			6
#define		PA_U1_RTS			7
#define		PA_U1_CTS			8
#define		PA_U1_SCLK			8
#define		PA_U2_TXD			10
#define		PA_U2_RXD			11
#define		PA_U2_RTS			12
#define		PA_U2_CTS			13
#define		PA_U2_SCLK			14
#define		PA_SPI0_SCK			15
#define		PA_SPI0_MOSI		16
#define		PA_SPI0_MISO		17
#define		PA_SPI0_SSEL0		18
#define		PA_SPI0_SSEL1		19
#define		PA_SPI0_SSEL2		20
#define		PA_SPI0_SSEL3		21
#define		PA_SPI1_SCK			22
#define		PA_SPI1_MOSI		23
#define		PA_SPI1_MISO		24
#define		PA_SPI1_SSEL0		25
#define		PA_SPI1_SSEL1		26
#define		PA_SCT_PIN0			27
#define		PA_SCT_PIN1			28
#define		PA_SCT_PIN2			29
#define		PA_SCT_PIN3			30
#define		PA_SCT_OUT0			31
#define		PA_SCT_OUT1			32
#define		PA_SCT_OUT2			33
#define		PA_SCT_OUT3			34
#define		PA_SCT_OUT4			35
#define		PA_SCT_OUT5			36
#define		PA_SCT_OUT6			37
#define		PA_I2C1_SDA			38
#define		PA_I2C1_SCL			39
#define		PA_I2C2_SDA			40
#define		PA_I2C2_SCL			41
#define		PA_I2C3_SDA			42
#define		PA_I2C3_SCL			43
#define		PA_ACMP_O			44
#define		PA_CLKOUT			45
#define		PA_GPIO_INT_BMAT	46
#define		PA_U3_TXD			47
#define		PA_U3_RXD			48
#define		PA_U3_SCLK			49
#define		PA_U4_TXD			50
#define		PA_U4_RXD			51
#define		PA_U4_SCLK			52
#define		PA_T0_MAT0			53
#define		PA_T0_MAT1			54
#define		PA_T0_MAT2			55
#define		PA_T0_MAT3			56
#define		PA_T0_CAP0			57
#define		PA_T0_CAP1			58
#define		PA_T0_CAP2			59

#define		PE_ACMP_I1			0
#define		PE_ACMP_I2			1
#define		PE_ACMP_I3			2
#define		PE_ACMP_I4			3
#define		PE_ACMP_I5			4
#define		PE_SWCLK			5
#define		PE_SWDIO			6
#define		PE_XTALIN			7
#define		PE_XTALOUT			8
#define		PE_RESETN			9
#define		PE_CLKIN			10
#define		PE_VDDCMP			11
#define		PE_I2C0_SDA			12
#define		PE_I2C0_SCL			13
#define		PE_ADC_0			14
#define		PE_ADC_1			15
#define		PE_ADC_2			16
#define		PE_ADC_3			17
#define		PE_ADC_4			18
#define		PE_ADC_5			19
#define		PE_ADC_6			20
#define		PE_ADC_7			21
#define		PE_ADC_8			22
#define		PE_ADC_9			23
#define		PE_ADC_10			24
#define		PE_ADC_11			25
#define		PE_DACOUT0			26
#define		PE_DACOUT1			27
#define		PE_CAPT_X0			28
#define		PE_CAPT_X1			29
#define		PE_CAPT_X2			30
#define		PE_CAPT_X3			31

#define		PE_CAPT_X4			32
#define		PE_CAPT_X5			33
#define		PE_CAPT_X6			34
#define		PE_CAPT_X7			35
#define		PE_CAPT_X8			35
#define		PE_CAPT_YL			36
#define		PE_CAPT_YH			37

#define		PINENABLE			( ( volatile uint32_t*)	0x4000C1C0)

void PINASSIGN_Config( uint8_t pin_movible , uint8_t port , uint8_t pin );
void PINENABLE_Config( uint8_t pin_config , uint8_t enable );

#endif /* FIRMWARE_SWM_H_ */
