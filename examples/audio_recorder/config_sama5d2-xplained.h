#ifndef __CONFIG_SAMA5D2_XPLAINED_H__
#define __CONFIG_SAMA5D2_XPLAINED_H__

#include "audio/audio_device.h"

/** Audio play device instance*/
#define PIO_PD30B_PCK0       (1u << 30) /**< \brief Pmc signal: PCK0 */
#define PIN_PCK0 { PIO_GROUP_D, PIO_PD30B_PCK0, PIO_PERIPH_B, PIO_DEFAULT }
#define BOARD_WM8904_TWI_BUS      BUS(BUS_TYPE_I2C, 0)
#define BOARD_WM8904_SLAVE_ADDR   0x1a
#define BOARD_WM8904_INPUT_PATH   (WM8904_INPUT_PATH_IN2L | WM8904_INPUT_PATH_IN2R)
#define BOARD_WM8904_MCLK_PCK     0
#define BOARD_WM8904_MCLK_PCK_SRC PMC_PCK_CSS_SLOW_CLK
#define BOARD_WM8904_MCLK_PIN     PIN_PCK0

static struct codec_desc wm8904_codec = {
	/* codec control interface */
	.type = AUDIO_CODEC_WM8904,
	.wm8904 = {
		.twi = {
			.bus = BOARD_WM8904_TWI_BUS,
			.addr = BOARD_WM8904_SLAVE_ADDR,
		},
		.input_path = BOARD_WM8904_INPUT_PATH,
		.mclk_pck = BOARD_WM8904_MCLK_PCK,
		.mclk_pck_src = BOARD_WM8904_MCLK_PCK_SRC,
		.mclk_pin = BOARD_WM8904_MCLK_PIN,
	},
};

static struct _audio_desc audio_play_device = {
	.direction = AUDIO_DEVICE_PLAY,
	.type = AUDIO_DEVICE_CLASSD,
	.device = {
		.classd = {
			.addr = BOARD_CLASSD0_ADDR,
			.desc = {
				.transfer_mode = CLASSD_MODE_DMA,
				.sample_rate = 48000,
				.mode = BOARD_CLASSD0_MODE,
				.non_ovr = CLASSD_NONOVR_10NS,
				.mono = BOARD_CLASSD0_MONO,
				.mono_mode = BOARD_CLASSD0_MONO_MODE
			},
		},
	},
	.sample_rate = 48000,
	.num_channels = 1,
	.bits_per_sample = 16,
};

static struct _audio_desc audio_record_device_ssc0 = {
	.direction = AUDIO_DEVICE_RECORD,
	.type = AUDIO_DEVICE_SSC,
	.device = {
		.ssc = {
			.addr = SSC0,
			.desc = {
				.bit_rate = 0,
				/* Select RK pin as transmit and receive clock */
				.rx_cfg_cks_rk = true,
				.tx_cfg_cks_tk = false,
				.tx_start_selection = SSC_TCMR_START_TF_EDGE,
				.rx_start_selection = SSC_RCMR_START_RF_EDGE,
			},
			.codec = &wm8904_codec,
		},
	},
	.sample_rate = 48000,
	.num_channels = 1,
	.bits_per_sample = 16,
};

/** Audio recoder device instance*/
static struct _audio_desc audio_record_device = {
	.direction = AUDIO_DEVICE_RECORD,
	.type = AUDIO_DEVICE_PDMIC,
	.device = {
		.pdmic = {
			.addr = BOARD_PDMIC0_ADDR,
			.desc = {
				.dsp_osr = PDMIC_OVER_SAMPLING_RATIO_64,
				.dsp_hpfbyp = PDMIC_DSP_HIGH_PASS_FILTER_ON,
				.dsp_sinbyp = PDMIC_DSP_SINCC_PASS_FILTER_ON,
				/* while shift = 0 offset = 0
				 * dgain = 100 scale = 0, gain = 40(dB)
				 */
				.dsp_shift = 0,
				.dsp_offset = 0,
				.dsp_dgain = 100,
				.dsp_scale = 0,
			},
		},
	},
	.sample_rate = 48000,
	.num_channels = 1,
	.bits_per_sample = 16,
};


#endif
