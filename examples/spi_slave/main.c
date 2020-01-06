/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \page spi_slave SPI Slave Example
 *
 * \section Purpose
 *
 * This example uses Serial Peripheral Interface (SPI) in slave mode to
 * communicate to another interface (SPI) in master mode.
 *
 * \section Requirements
 *
 * This package can be used with SAMA5D2-XULT and SAMA5D4-XULT.
 *
 * Requirements when running on SAMA5D2-XULT:
 * We need to connect the SPI pins on the board before running the example.
 * - <b>  SPI0 IOSET1 (MASTER)             - SPI1 IOSET3 (SLAVE)</b>
 * - SPI0_NPCS2 (EXP_PA19 on J9 pin 1)  - SPI1_NPCS0 (EXP/XPRO_PD28 on J20 pin 3)
 * - SPI0_MOSI  (EXP_PA15 on J17 pin 5) - SPI1_MOSI  (EXP/XPRO_PD26 on J20 pin 4)
 * - SPI0_MISO  (EXP_PA16 on J8 pin 1)  - SPI1_MISO  (EXP/XPRO_PD27 on J20 pin 5)
 * - SPI0_SPCK  (EXP_PA14 on J17 pin 4) - SPI1_SPCK  (EXP/XPRO_PD25 on J20 pin 6)
 *
 * Requirements when running on SAMA5D3-EK (REV. E):
 * We need to connect the SPI pins on the board before running the example.
 * - <b>  SPI0 (MASTER)                        - SPI1 (SLAVE)</b>
 * - SPI0_MISO (PD10 on J3 pin 22) - SPI1_MISO  (PC22 on J2 pin 18)
 * - SPI0_MOSI (PD11 on J3 pin 24) - SPI1_MOSI  (PC23 on J2 pin 20)
 * - SPI0_SPCK (PD12 on J3 pin 26) - SPI1_SPCK  (PC24 on J2 pin 22)
 * - SPI0_NPCS2(PD15 on J3 pin 32) - SPI1_NPCS0 (PC25 on J2 pin 24)
 * Also remember to mount the following resisters: R6, R50, and R51.
 *
 * Requirements when running on SAMA5D4-XULT:
 * We need to connect the SPI pins on the board before running the example.
 * - <b>  SPI1 (MASTER)                          - SPI2 (SLAVE)</b>
 * - SPI1_NPCS3 (EXP/XPRO_PB27 on J15 pin 4)  - SPI2_NPCS0 (EXP/XPRO_PD17 on J19 pin 3)
 * - SPI1_MOSI  (EXP/XPRO_PB19 on J17 pin 4)  - SPI2_MOSI  (EXP/XPRO_PD13 on J19 pin 5)
 * - SPI1_MISO  (EXP/XPRO_PB18 on J17 pin 5)  - SPI2_MISO  (EXP/XPRO_PD11 on J15 pin 30)
 * - SPI1_SPCK  (EXP/XPRO_PB20 on J17 pin 6)  - SPI2_SPCK  (EXP/XPRO_PD15 on J15 pin 8)
 *
 * Requirements when running on SAMA5D4-EK:
 * We need to connect the SPI pins on the board before running the example.
 * - <b>  SPI1 (MASTER)                        - SPI2 (SLAVE)</b>
 * - SPI1_NPCS2(LCD_SPI1_CS2 on J10 pin 34) - SPI2_NPCS0 (XPRO_PD17 on J11 XPRO pin 14)
 * - SPI1_MOSI (LCD_SPI1_SI  on J10 pin 32) - SPI2_MOSI  (XPRO_PD13 on J11 XPRO pin 16)
 * - SPI1_MISO (LCD_SPI1_SO  on J10 pin 31) - SPI2_MISO  (XPRO_PD11 on J11 XPRO pin 17)
 * - SPI1_SPCK (LCD_SPI1_CLK on J10 pin 33) - SPI2_SPCK  (XPRO_PD15 on J11 XPRO pin 18)
 *
 * Requirements when running on SAM9XX5-EK:
 * We need to connect the SPI pins on the board before running the example.
 * - <b>  SPI0 (MASTER)                        - SPI1 (SLAVE)</b>
 * - SPI0_MISO (PA11 on J1 pin 27) - SPI1_MISO (PA21 on J1 pin 16)
 * - SPI0_MOSI (PA12 on J1 pin 29) - SPI1_MOSI (PA22 on J1 pin 18)
 * - SPI0_SPCK (PA13 on J1 pin 31) - SPI1_SPCK (PA23 on J1 pin 20)
 * - SPI0_NPCS1 (PA7 on J1 pin 19) - SPI1_NPCS0 (PA8 on J1 pin 21)
 *
 * Requirements when running on SAM9X60-EK:
 * We need to connect the SPI pins on the board before running the example.
 * - <b>  SPI0 (MASTER)                        - SPI1 (SLAVE)</b>
 * - SPI0_MISO (PA11 on J15 pin 5)  - SPI1_MISO (PA01 on J15 pin 12)
 * - SPI0_MOSI (PA12 on J15 pin 6)  - SPI1_MOSI (PA00 on J15 pin 11)
 * - SPI0_SPCK (PA13 on J15 pin 4)  - SPI1_SPCK (PA04 on J17 pin 15)
 * - SPI0_NPCS0 (PA14 on J15 pin 3) - SPI1_NPCS1 (PA03 on J17 pin 13)
 *
 * \section Descriptions
 *
 * This example shows control of the SPI slave, how to configure and
 * transfer data with SPI slave. By default, example runs in SPI slave mode,
 * waiting for SPI slave & DBGU input.
 *
 * The code can be roughly broken down as follows:
 * <ul>
 * <li> 's' will start SPI transfer test
 * <ol>
 * <li>Configure SPI as master, setup SPI clock.
 * </ol>
 * <li>Setup SPI clock for slave.
 * </ul>
 *
 * \section Usage
 *
 * -# Compile the application and connect the DBGU port of the evaluation board
 *    to the computer.
 * -# Open and configure a terminal application on PC
 *    (e.g. HyperTerminal on Microsoft Windows) with these settings:
 *   - 115200 bauds
 *   - 8 bits of data
 *   - No parity
 *   - 1 stop bit
 *   - No flow control
 * -# Download the program inside the evaluation board and run it. Please refer to
 *    <a href="http://www.atmel.com/dyn/resources/prod_documents/6421B.pdf">
 *    SAM-BA User Guide</a>, the
 *    <a href="http://www.atmel.com/dyn/resources/prod_documents/doc6310.pdf">
 *    GNU-Based Software Development</a> application note or to the
 *    <a href="ftp://ftp.iar.se/WWWfiles/arm/Guides/EWARM_UserGuide.ENU.pdf">
 *    IAR EWARM User Guide</a>, depending on your chosen solution.
 * -# Upon startup, the application will output the following line on the DBGU:
 *    \code
 *     -- SPI Slave Example  xxx --
 *     -- SAMxxxxx-xx
 *     -- Compiled: xxx xx xxxx xx:xx:xx --
 *    \endcode
 * -# The following traces detail operations on the SPI slave example, displaying success
 *    or error messages depending on the results of the commands.
 *
 * \section References
 * - spi_slave/main.c
 * - spi.c
 */

/**
 * \file
 *
 * This file contains all the specific code for the spi slave example.
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "board.h"
#include "chip.h"
#include "trace.h"
#include "compiler.h"

#include "gpio/pio.h"
#include "spi/spid.h"

#include "peripherals/bus.h"

#include "serial/console.h"
#include "mm/cache.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "uif_object.h"
#include "uif_xc3s50an.h"
/*----------------------------------------------------------------------------
 *        Local definitions
 *----------------------------------------------------------------------------*/

#define DMA_TRANS_SIZE 32

#if defined(CONFIG_BOARD_SAMA5D2_XPLAINED)
	#include "config_sama5d2-xplained.h"
#elif defined(CONFIG_BOARD_SAMA5D27_SOM1_EK)
	#include "config_sama5d27-som1-ek.h"
#elif defined(CONFIG_BOARD_SAMA5D3_EK)
	#include "config_sama5d3-ek.h"
#elif defined(CONFIG_BOARD_SAMA5D4_EK)
	#include "config_sama5d4-ek.h"
#elif defined(CONFIG_BOARD_SAMA5D4_XPLAINED)
	#include "config_sama5d4-xplained.h"
#elif defined(CONFIG_BOARD_SAM9G15_EK)
	#include "config_sam9xx5-ek.h"
#elif defined(CONFIG_BOARD_SAM9G25_EK)
	#include "config_sam9xx5-ek.h"
#elif defined(CONFIG_BOARD_SAM9G35_EK)
	#include "config_sam9xx5-ek.h"
#elif defined(CONFIG_BOARD_SAM9X25_EK)
	#include "config_sam9xx5-ek.h"
#elif defined(CONFIG_BOARD_SAM9X35_EK)
	#include "config_sam9xx5-ek.h"
#elif defined(CONFIG_BOARD_SAM9X60_EK)
	#include "config_sam9x60-ek.h"
#else
	#error Unsupported board!
#endif


/*----------------------------------------------------------------------------
 *        Local struct for FPGA 
 *----------------------------------------------------------------------------*/
//note: if need to extend new path,
#pragma pack(1)
typedef struct _fpga_command_backup
{
  	uint8_t t_revs0;      			//248-255
  	uint8_t t_revs1;      			//240-247
  	uint8_t t_revs2;      			//232-239
  	uint8_t t_revs3;      			//224-231
  	uint8_t t_revs4;      			//216-223
  	uint8_t t_revs5;      			//208-215
  	uint8_t t_revs6;      			//200-207
        uint8_t t_revs7; 			//192-199
	uint8_t t_revs8; 			//184-191
	

	uint8_t t6 : 1;				//176
	uint8_t t7 : 1; 			//177
	uint8_t t8 : 1;				//178
	uint8_t t9 : 1;				//179
	uint8_t t10 : 1;			//180
	uint8_t t_revs9             : 1;	//181
	uint8_t t_revs10            : 1;	//182
	uint8_t t_revs11            : 1;	//183
    
/*------------------------------------------*/
	
	uint8_t dir_revers10        : 1;	//168
	uint8_t dir_revers11        : 1;	//169
 	uint8_t t0 : 1;    			//170
	uint8_t t1 : 1;				//171
	uint8_t t2 : 1;  			//172 
	uint8_t t3 : 1;				//173
	uint8_t t4 : 1;				//174
	uint8_t t5 : 1;				//175

	uint8_t dir_revers9;			//160-167

	uint8_t dir_port3_ssc3      : 1;	//67--152
	uint8_t dir_revers2         : 1;
	uint8_t dir_revers3         : 1;
	uint8_t dir_revers4         : 1;	
	uint8_t dir_revers5         : 1;
	uint8_t dir_revers6	    : 1;
	uint8_t dir_revers7         : 1;
	uint8_t dir_revers8	    : 1;	//74--159

	uint8_t dir_port2_fm36      : 1;	//59--144
	uint8_t dir_port2_port3     : 1;	//60--145
	uint8_t dir_port2_ssc2      : 1;	//61--146
	uint8_t dir_port2_ssc3      : 1;	//62--147
	uint8_t dir_port3_ssc0      : 1;	//63--148
	uint8_t dir_port3_ssc1      : 1;	//64--149
	uint8_t dir_port3_fm36      : 1;	//65--150
	uint8_t dir_port3_ssc2      : 1;	//66--151

	uint8_t dir_codec3_ssc1     : 1;	//51--136
	uint8_t dir_codec3_fm36     : 1;	//52--137
	uint8_t dir_codec3_port2    : 1;	//53--138
	uint8_t dir_codec3_port3    : 1;	//54--139
	uint8_t dir_codec3_ssc2     : 1;	//55--140
	uint8_t dir_codec3_ssc3     : 1;	//56--141
	uint8_t dir_port2_ssc0      : 1;	//57--142
	uint8_t dir_port2_ssc1      : 1;	//58--143


	uint8_t dir_codec2_ssc1     : 1;	//43--128
	uint8_t dir_codec2_fm36     : 1;	//44--129
	uint8_t dir_codec2_codec3   : 1;	//45--130
	uint8_t dir_codec2_port2    : 1;	//46--131
	uint8_t dir_codec2_port3    : 1;	//47--132
	uint8_t dir_codec2_ssc2     : 1;	//48--133
	uint8_t dir_codec2_ssc3     : 1;	//49--134
	uint8_t dir_codec3_ssc0     : 1;	//50--135


	uint8_t dir_port0_ssc3     : 1;		//35--120
	uint8_t dir_port1_codec2   : 1;		//36--121
	uint8_t dir_port1_codec3   : 1;		//37--122
	uint8_t dir_port1_port2    : 1;		//38--123
	uint8_t dir_port1_port3    : 1;		//39--124
	uint8_t dir_port1_ssc2     : 1;		//40--125
	uint8_t dir_port1_ssc3     : 1;		//41--126
	uint8_t dir_codec2_ssc0    : 1;		//42--127


	uint8_t dir_codec1_port3   : 1;		//27--112
	uint8_t dir_codec1_ssc2    : 1;		//28--113
	uint8_t dir_codec1_ssc3	   : 1;		//29--114
	uint8_t dir_port0_codec2   : 1;		//30--115
	uint8_t dir_port0_codec3   : 1;		//31--116
	uint8_t dir_port0_port2    : 1;		//32--117
	uint8_t dir_port0_port3    : 1;		//33--118
	uint8_t dir_port0_ssc2     : 1;		//34--119


	uint8_t dir_codec0_codec3   : 1;	//19--104
	uint8_t dir_codec0_port2    : 1;	//20--105
	uint8_t dir_codec0_port3    : 1;	//21--106
	uint8_t dir_codec0_ssc2     : 1;	//22--107
	uint8_t dir_codec0_ssc3	    : 1;	//23--108
	uint8_t dir_codec1_codec2   : 1;	//24--109
	uint8_t dir_codec1_codec3   : 1;	//25--110
	uint8_t dir_codec1_port2    : 1;	//26--111

	uint8_t dir_port0_port1    : 1;		//96
	uint8_t dir_port0_ssc0     : 1;		//97
	uint8_t dir_port0_ssc1     : 1;		//98
	uint8_t dir_port0_fm36     : 1;		//99
	uint8_t dir_port1_ssc0     : 1;  	//100
    	uint8_t dir_port1_ssc1     : 1;  	//101
    	uint8_t dir_port1_fm36     : 1;		//102
	uint8_t dir_codec0_codec2  : 1; 	//103       

	uint8_t dir_codec0_port1   : 1;		//88
	uint8_t dir_codec0_codec1  : 1;		//89
	uint8_t dir_codec0_ssc1    : 1;		//90
	uint8_t dir_codec1_port0   : 1;		//91
	uint8_t dir_codec1_port1   : 1;		//92
	uint8_t dir_codec1_ssc0    : 1; 	//93 
	uint8_t dir_codec1_ssc1    : 1;		//94
	uint8_t dir_codec1_fm36    : 1;		//95


	uint8_t oe_revers5	   : 1;		//80
	uint8_t oe_revers6	   : 1;		//81
	uint8_t oe_revers7	   : 1;		//82
	uint8_t oe_revers8	   : 1;		//83
	uint8_t oe_revers9	   : 1;		//84
    	uint8_t dir_codec0_port0   : 1; 	//85	
	uint8_t dir_codec0_fm36    : 1;		//86
	uint8_t dir_codec0_ssc0    : 1;		//87

	uint8_t oe_revers4;			//72-79
/*----------------------------------------------------*/
	uint8_t oe_port3_ssc1      : 1;		//64
	uint8_t oe_port3_fm36      : 1;		//65
	uint8_t oe_port3_ssc2      : 1;		//66
	uint8_t oe_port3_ssc3      : 1;		//67
	uint8_t oe_revers0	   : 1;		//68
	uint8_t oe_revers1	   : 1;		//69
	uint8_t oe_revers2	   : 1;		//70
	uint8_t oe_revers3	   : 1;		//71

	uint8_t oe_codec3_ssc3     : 1;		//56
	uint8_t oe_port2_ssc0      : 1;		//57
	uint8_t oe_port2_ssc1      : 1;		//58
	uint8_t oe_port2_fm36      : 1;		//59
	uint8_t oe_port2_port3     : 1;		//60
	uint8_t oe_port2_ssc2      : 1;		//61
	uint8_t oe_port2_ssc3      : 1;		//62
	uint8_t oe_port3_ssc0      : 1;		//63

	uint8_t oe_codec2_ssc2     : 1;		//48
	uint8_t oe_codec2_ssc3     : 1;		//49
	uint8_t oe_codec3_ssc0     : 1;		//50
	uint8_t oe_codec3_ssc1     : 1;		//51
	uint8_t oe_codec3_fm36     : 1;		//52
	uint8_t oe_codec3_port2    : 1;		//53
	uint8_t oe_codec3_port3    : 1;		//54
	uint8_t oe_codec3_ssc2     : 1;		//55


	uint8_t oe_port1_ssc2      : 1;		//40
	uint8_t oe_port1_ssc3      : 1;		//41
	uint8_t oe_codec2_ssc0     : 1;		//42
	uint8_t oe_codec2_ssc1     : 1;		//43
	uint8_t oe_codec2_fm36     : 1;		//44
	uint8_t oe_codec2_codec3   : 1;		//45
	uint8_t oe_codec2_port2    : 1;		//46
	uint8_t oe_codec2_port3    : 1;		//47

	uint8_t oe_port0_port2     : 1;		//32
	uint8_t oe_port0_port3     : 1;		//33
	uint8_t oe_port0_ssc2      : 1;		//34
	uint8_t oe_port0_ssc3      : 1;		//35
	uint8_t oe_port1_codec2	   : 1;		//36
	uint8_t oe_port1_codec3	   : 1;		//37
	uint8_t oe_port1_port2     : 1;		//38
	uint8_t oe_port1_port3     : 1;		//39

	uint8_t oe_codec1_codec2   : 1;		//24
	uint8_t oe_codec1_codec3   : 1;		//25
	uint8_t oe_codec1_port2    : 1;		//26
	uint8_t oe_codec1_port3    : 1;		//27
	uint8_t oe_codec1_ssc2 	   : 1;		//28
	uint8_t oe_codec1_ssc3	   : 1;		//29
	uint8_t oe_port0_codec2    : 1;		//30
	uint8_t oe_port0_codec3    : 1;		//31


    	uint8_t oe_port1_ssc1      : 1;  	//16
    	uint8_t oe_port1_fm36      : 1;		//17
	uint8_t oe_codec0_codec2   : 1;		//18
	uint8_t oe_codec0_codec3   : 1;		//19
	uint8_t oe_codec0_port2    : 1;		//20
	uint8_t oe_codec0_port3    : 1;		//21
	uint8_t oe_codec0_ssc2 	   : 1;		//22
	uint8_t oe_codec0_ssc3	   : 1;		//23

    uint8_t oe_codec1_ssc0 : 1;
    uint8_t oe_codec1_ssc1 : 1;
    uint8_t oe_codec1_fm36 : 1;
    uint8_t oe_port0_port1 : 1;
    uint8_t oe_port0_ssc0  : 1;
    uint8_t oe_port0_ssc1  : 1;
    uint8_t oe_port0_fm36  : 1;
    uint8_t oe_port1_ssc0  : 1;

    uint8_t oe_codec0_port0  : 1; // LSB
    uint8_t oe_codec0_fm36   : 1;
    uint8_t oe_codec0_ssc0   : 1;
    uint8_t oe_codec0_port1  : 1;
    uint8_t oe_codec0_codec1 : 1;
    uint8_t oe_codec0_ssc1   : 1;
    uint8_t oe_codec1_port0  : 1;
    uint8_t oe_codec1_port1  : 1;

} FPGA_COMMAND_BK;
#pragma pack()

/*----------------------------------------------------------------------------
 *        Local variables
 *----------------------------------------------------------------------------*/
#pragma pack(1)
/** data buffer for SPI master's receive */
CACHE_ALIGNED static uint8_t spi_buffer_master_tx[DMA_TRANS_SIZE];
#pragma pack()

#pragma pack(1)
/** data buffer for SPI master's receive */
CACHE_ALIGNED static uint8_t spi_buffer_master_tx_protocol[4]={0x01,0x0,0x0,0xff};
#pragma pack()

/** data buffer for SPI slave's transfer */
CACHE_ALIGNED static uint8_t spi_buffer_slave_rx[DMA_TRANS_SIZE];

/** Pio pins for SPI slave */
static const struct _pin pins_spi_slave[] = SPI_SLAVE_PINS;
	const struct _bus_iface iface_bus1 = {
		.type = BUS_TYPE_SPI,
		.spi = {
			.hw = BOARD_SPI_BUS1,
		},
		.transfer_mode = BOARD_SPI_BUS1_MODE,
	};

/** descriptor for SPI master */
static const struct _bus_dev_cfg spi_master_dev = {
	.bus = SPI_MASTER_BUS,
	.spi_dev = {
		.chip_select = SPI_MASTER_CS,
		.bitrate = SPI_MASTER_BITRATE,
		.delay = {
			.bs = 0,
			.bct = 0,
		},
		.spi_mode = SPID_MODE_1,
	},
};

static struct _spi_desc spi_slave_dev = {
	.addr = SPI_SLAVE_ADDR,
	.chip_select = 0,
	.transfer_mode = BUS_TRANSFER_MODE_DMA,
};


enum action_state {
                    INVALID = -1,
                    INPUTPOS,
                    INPUTBIT,
                    SENDDATA,
                    IDLE
} ACTION_S;

FPGA_COMMAND cmd;

//human interface
static uint8_t key;
static int position=0,bit=0;   //the bit position in the map of FPGA registers;
static int oe=0,dir=0;         //the clock path control 
enum action_state current_state;
/*----------------------------------------------------------------------------
 *        Local functions
 *----------------------------------------------------------------------------*/

/**
 * \brief Displays the user menu.
 */
static void _display_menu(void)
{
	printf("\r\nMenu :\r\n");
	printf("------\r\n");

	printf("  h: Display menu \r\n");
        printf("  p: Set position\r\n");
        printf("  b: Set bit offset\r\n");
        printf("  t: Perform SPI transfer start\r\n");
        printf("  r: Reset selected bit to 0.\r\n");
        printf("  o: Select oe bit.\r\n");
        printf("  d: Select dir bit.\r\n");
        printf("  g: Flip the clock path control.\r\n");
}

static int _spi_slave_transfer_callback(void* arg, void* arg2)
{
	printf("Slave transfer complete\r\n");
	return 0;
}

/**
 * \brief Start SPI slave transfer and SPI master receive.
 */

static void _spi_transfer()
{
	int err;
	int i;
	struct _buffer master_buf = {
#if 1
		.data = spi_buffer_master_tx,
		.size = DMA_TRANS_SIZE,
#else
                .data = spi_buffer_master_tx_protocol,
                .size = sizeof(spi_buffer_master_tx_protocol),
#endif
		.attr = BUS_BUF_ATTR_TX | BUS_SPI_BUF_ATTR_RELEASE_CS,
	};
        
	//struct _buffer slave_buf = {
	//	.data = spi_buffer_slave_rx,
	//	.size = DMA_TRANS_SIZE,
	//	.attr = BUS_BUF_ATTR_RX,
	//};
	//struct _callback _cb = {
	//	.method = _spi_slave_transfer_callback,
	//	.arg = 0,
	//};

        
	for (i = 0; i < DMA_TRANS_SIZE; i++)
        {
//            if (( i >= 10 ) && ( i <= 21  ))
		spi_buffer_master_tx[i] = 0x0;
//            else
//                spi_buffer_master_tx[i] = 0; 
        }
        spi_buffer_master_tx[20] = 0x01;
        spi_buffer_master_tx[18] = 0x01;
//        spi_buffer_master_tx[11] = 0xe0;
	memset(spi_buffer_slave_rx, 0, DMA_TRANS_SIZE);

	bus_start_transaction(spi_master_dev.bus);

	//printf("Slave receiving...\r\n");
	//err = spid_transfer(&spi_slave_dev, &slave_buf, 1, &_cb);
	//if (err < 0) {
	//	trace_error("SPI: SLAVE: transfer failed.\r\n");
	//	return;
	//}

	printf("Master sending...\r\n");
	bus_transfer(spi_master_dev.bus, spi_master_dev.spi_dev.chip_select, &master_buf, 1, NULL);
        bus_wait_transfer(spi_master_dev.bus);
	bus_stop_transaction(spi_master_dev.bus);
	//spid_wait_transfer(&spi_slave_dev);

	//if (memcmp(spi_buffer_master_tx, spi_buffer_slave_rx, DMA_TRANS_SIZE)) {
	//	trace_error("SPI: received data does not match!\r\n");
	//	return;
	//}

	//printf("Received data matched.\r\n");
}

static void _spi_transfer_bit( int position , int bit, int val )
{
	int err;
	int i;
        
        assert( position <= 31 );
        assert( bit <= 7 );
        
	struct _buffer master_buf = {
		.data = spi_buffer_master_tx,
		.size = DMA_TRANS_SIZE,
		.attr = BUS_BUF_ATTR_TX | BUS_SPI_BUF_ATTR_RELEASE_CS,
	};
               
	for (i = 0; i < DMA_TRANS_SIZE; i++)
        {
		spi_buffer_master_tx[i] = 0x0;
        }
        printf("Bit value is %d...\r\n",val);

        if( val == 1 )
            spi_buffer_master_tx[position] = ( 1 << bit );
        else
            spi_buffer_master_tx[position] &= ~( 1 << bit );
        printf("BYTE = 0x%x...\r\n",spi_buffer_master_tx[position]);
	memset(spi_buffer_slave_rx, 0, DMA_TRANS_SIZE);

	bus_start_transaction(spi_master_dev.bus);

	printf("Master sending...\r\n");
	bus_transfer(spi_master_dev.bus, spi_master_dev.spi_dev.chip_select, &master_buf, 1, NULL);
        bus_wait_transfer(spi_master_dev.bus);
	bus_stop_transaction(spi_master_dev.bus);
}

static void _spi_transfer_array( )
{
	int err;
	int i;
        
       
	struct _buffer master_buf = {
		.data = spi_buffer_master_tx,
		.size = DMA_TRANS_SIZE,
		.attr = BUS_BUF_ATTR_TX | BUS_SPI_BUF_ATTR_RELEASE_CS,
	};
               

	bus_start_transaction(spi_master_dev.bus);

	printf("Master sending...\r\n");
	bus_transfer(spi_master_dev.bus, spi_master_dev.spi_dev.chip_select, &master_buf, 1, NULL);
        bus_wait_transfer(spi_master_dev.bus);
	bus_stop_transaction(spi_master_dev.bus);
}

static void _spi_transfer_fpga_cmd( FPGA_COMMAND* cmd )
{
	int err;
	int i;
        
       
	struct _buffer master_buf = {
		.data = (uint8_t *)cmd,
		.size = sizeof( FPGA_COMMAND ),
		.attr = BUS_BUF_ATTR_TX | BUS_SPI_BUF_ATTR_RELEASE_CS,
	};
               

	bus_start_transaction(spi_master_dev.bus);

	printf("Master sending...\r\n");
	bus_transfer(spi_master_dev.bus, spi_master_dev.spi_dev.chip_select, &master_buf, 1, NULL);
        bus_wait_transfer(spi_master_dev.bus);
	bus_stop_transaction(spi_master_dev.bus);
}

static void _spi_transfer_reset(  )
{
	int err;
	int i;
	struct _buffer master_buf = {
		.data = spi_buffer_master_tx,
		.size = DMA_TRANS_SIZE,
		.attr = BUS_BUF_ATTR_TX | BUS_SPI_BUF_ATTR_RELEASE_CS,
	};
        
	//struct _buffer slave_buf = {
	//	.data = spi_buffer_slave_rx,
	//	.size = DMA_TRANS_SIZE,
	//	.attr = BUS_BUF_ATTR_RX,
	//};
	//struct _callback _cb = {
	//	.method = _spi_slave_transfer_callback,
	//	.arg = 0,
	//};

        
	for (i = 0; i < DMA_TRANS_SIZE; i++)
		spi_buffer_master_tx[i] = 0x0;
        //spi_buffer_master_tx[3] = (1 << bit );
        //spi_buffer_master_tx[3] = 0xff;
	memset(spi_buffer_slave_rx, 0, DMA_TRANS_SIZE);

	bus_start_transaction(spi_master_dev.bus);

	//printf("Slave receiving...\r\n");
	//err = spid_transfer(&spi_slave_dev, &slave_buf, 1, &_cb);
	//if (err < 0) {
	//	trace_error("SPI: SLAVE: transfer failed.\r\n");
	//	return;
	//}

	printf("buffer Clean...\r\n");
	bus_transfer(spi_master_dev.bus, spi_master_dev.spi_dev.chip_select, &master_buf, 1, NULL);
        bus_wait_transfer(spi_master_dev.bus);
	bus_stop_transaction(spi_master_dev.bus);
	//spid_wait_transfer(&spi_slave_dev);

	//if (memcmp(spi_buffer_master_tx, spi_buffer_slave_rx, DMA_TRANS_SIZE)) {
	//	trace_error("SPI: received data does not match!\r\n");
	//	return;
	//}

	//printf("Received data matched.\r\n");
}


/*----------------------------------------------------------------------------
 *        Global functions
 *----------------------------------------------------------------------------*/

/**
 *  \brief SPI slave Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */

int main(void)
{
        int k = 100000000;              //here delay sometimes for
        struct _bus_iface iface;
        int temp_dir_bit,temp_oe_bit,temp_dir_pos,temp_oe_pos;
        //FPGA_COMMAND cmd;

	/* Output example information */
	console_example_info("SPI Slave Example");
        printf("fpga command size = %d",sizeof( FPGA_COMMAND ));
        memset( (void *)&cmd, 0 , sizeof( FPGA_COMMAND ));
        
	pio_configure(pins_spi_slave, ARRAY_SIZE(pins_spi_slave));
        bus_configure(BUS(BUS_TYPE_SPI, 1), &iface_bus1);
#if 0
	// Configure SPI slave 
	spid_configure(&spi_slave_dev);
	spid_configure_master(&spi_slave_dev, false);
	spid_configure_cs(&spi_slave_dev, 0, 0, 0, 0, SPID_MODE_0);
#endif
        
	bus_configure_slave(spi_master_dev.bus, &spi_master_dev);

#if 1
	while (1) {
                _display_menu();
		key = console_get_char();
		switch (key) {
		case 'H':
		case 'h':
			_display_menu();
			break;
		case 'P':
		case 'p':
                        printf("\r\nPlease input pos(0-31) :\r\n");
                        console_get_integer( &position );
                        printf("\r\nYou has selected swith[position][bit]:[%d][%d]\r\n",position,bit);
                        printf("\r\nYou can entry b to select other bit\r\n");
                        current_state = INPUTBIT;
			break;
                case 'B':
                case 'b':
                        printf("\r\nPlease input bit(0-7) :\r\n");
                        console_get_integer( &bit );
                        printf("\r\nYou has selected swith[position][bit]:[%d][%d]\r\n",position,bit);
                        break;
                  
                case 'C':
                case 'c':                         
                        _spi_transfer_bit( position, bit,0 );
                        printf("\r\nPlease hit r key to Reset FPGA\r\n");
                        break;
                case 't':
                case 'T':
                        printf("\r\nsend data to FPGA[%d][%d]\r\n",position,bit);
                        _spi_transfer_bit( position, bit,1 );
                        printf("\r\nPlease hit r key to Reset FPGA\r\n");
                        break;
                case 'R':
                case 'r':
                        printf("\r\nReset FPGA Buffer\r\n");
                        _spi_transfer_reset();
                        break; 
                case 'O':
                case 'o':
                        printf("\r\nPlease select OE bit(0-84) :\r\n");
                        console_get_integer( &oe );
                        printf("\r\nYou has selected clock[dir][oe]:[%d][%d]\r\n",dir,oe);
                        break;
                case 'D':
                case 'd':
                        printf("\r\nPlease select DIR bit(0-84) :\r\n");
                        console_get_integer( &dir );
                        printf("\r\nYou has selected clock[dir][oe]:[%d][%d]\r\n",dir,oe);
                        break;
                case 'G':
                case 'g':                       
                        printf("\r\nFlip Clock path[dir][oe]:[%d][%d]\r\n",dir,oe);
                        temp_dir_bit = 7 -( ( dir + 85 ) % 8 );
                        temp_dir_pos = ( dir + 85 ) / 8;
                        temp_oe_bit = 7 -( ( oe  ) % 8 );
                        temp_oe_pos = ( oe  ) / 8;
                        
                        for ( int i = 0; i < DMA_TRANS_SIZE; i++)
                                spi_buffer_master_tx[i] = 0x0;
                        spi_buffer_master_tx[temp_dir_pos] = ( 1 << temp_dir_bit);
                        spi_buffer_master_tx[temp_oe_pos] &= ~( 1 << temp_oe_bit);                     
                        _spi_transfer_array( );
                        
                        break;
                case 'Z':
                case 'z':
                        set_i2s_clk_path( 0,&cmd,1, 0 );
                        
                        break;
                case 'V':
                case 'v':                        
		default:
                        _spi_transfer();
			break;
		}
	}

#else        
        while( 1 ) {
          
          k = 10000;
          while( k-- );
          
          //act8865_write_reg(&act8865, 0x64, 0x39);
          _spi_transfer();
          
          k = 10000;
          while( k-- );
        }
#endif          
}
