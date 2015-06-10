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

#ifndef _PMC_H_
#define _PMC_H_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include <stdint.h>

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Get the configured frequency of the master clock
 * \return master clock frequency in Hz
 */
extern uint32_t pmc_get_master_clock(void);

/**
 * \brief Get the configured frequency of the slow clock
 * \return slow clock frequency in Hz
 */
extern uint32_t pmc_get_slow_clock(void);

/**
 * \brief Get the configured frequency of the main clock
 * \return main clock frequency in Hz
 */
extern uint32_t pmc_get_main_clock(void);

/**
 * \brief Get the configured frequency of the PLLA clock
 * \return PLLA clock frequency in Hz
 */
extern uint32_t pmc_get_plla_clock(void);

/**
 * \brief Get the configured frequency of the processor clock
 * \return processor clock frequency in Hz
 */
extern uint32_t pmc_get_processor_clock(void);

/**
 * \brief Select external 32K crystal.
 */
extern void pmc_select_external_crystal(void);

/**
 * \brief Select internal 32K crystal.
 */
extern void pmc_select_internal_crystal(void);

/**
 * \brief Select external 12M OSC.
 */
extern void pmc_select_external_osc(void);

/**
 * \brief Select internal 12M OSC.
 */
extern void pmc_select_internal_osc(void);

/**
 * \brief Switch PMC from MCK to PLL clock.
 */
extern void pmc_switch_mck_to_pll(void);

/**
 * \brief Switch PMC from MCK to main clock.
 */
extern void pmc_switch_mck_to_main(void);

/**
 * \brief Switch PMC from MCK to slow clock.
 */
extern void pmc_switch_mck_to_slck(void);

/**
 * \brief Configure PLL Register.
 * \param pll pll value.
 * \param cpcr cpcr value.
 */
extern void pmc_set_plla(uint32_t pll, uint32_t cpcr);

/**
 * \brief Configure MCK Prescaler.
 * \param prescaler prescaler value.
 */
extern void pmc_set_mck_prescaler(uint32_t prescaler);

/**
 * \brief Configure MCK Divider.
 * \param divider divider value.
 */
extern void pmc_set_mck_divider(uint32_t divider);

/**
 * \brief Configure MCK PLLA divider.
 * \param divider PLL divider value.
 */
extern void pmc_set_mck_plla_div(uint32_t divider);

/**
 * \brief Disable PLLA Register.
 */
extern void pmc_disable_plla(void);

/**
 * \brief Enables the clock of a peripheral. The peripheral ID is used
 * to identify which peripheral is targeted.
 *
 * \param id  Peripheral ID (ID_xxx).
 */
extern void pmc_enable_peripheral(uint32_t id);

/**
 * \brief Disables the clock of a peripheral. The peripheral ID is used
 * to identify which peripheral is targeted.
 *
 * \param id  Peripheral ID (ID_xxx).
 */
extern void pmc_disable_peripheral(uint32_t id);

/**
 * \brief Get Peripheral Status for the given peripheral ID.
 *
 * \param id  Peripheral ID (ID_xxx).
 */
extern uint32_t pmc_is_peripheral_enabled(uint32_t id);

/**
 * \brief Get current frequency clock for the given peripheral ID.
 *
 * \param id  Peripheral ID (ID_xxx).
 */
extern uint32_t pmc_get_peripheral_clock(uint32_t id);

/**
 * \brief Disable clocks for all peripherals
 */
extern void pmc_disable_all_peripherals(void);

/**
 * \brief Configure programmable clock 0 (PCK0) with the given master clock
 * source and clock prescaler
 * \param clock_source clock source selection (one of the PMC_PCK_CSS_xxx_CLK
 * constants)
 * \param prescaler prescaler
 */
extern void pmc_configure_pck0(uint32_t clock_source, uint32_t prescaler);

/**
 * \brief Enable programmable clock 0 (PCK0)
 */
extern void pmc_enable_pck0(void);

/**
 * \brief Disable programmable clock 0 (PCK0)
 */
extern void pmc_disable_pck0(void);

/**
 * \brief Get the frequency of the programmable clock 0 (PCK0)
 * \return PCK0 frequency in Hz
 */
extern uint32_t pmc_get_pck0_clock(void);

/**
 * \brief Configure programmable clock 1 (PCK1) with the given master clock
 * source and clock prescaler
 * \param clock_source Clock source selection (one of the PMC_PCK_CSS_xxx_CLK
 * constants)
 * \param prescaler Prescaler value
 */
extern void pmc_configure_pck1(uint32_t clock_source, uint32_t prescaler);

/**
 * \brief Enable programmable clock 1 (PCK1)
 */
extern void pmc_enable_pck1(void);

/**
 * \brief Disable programmable clock 1 (PCK1)
 */
extern void pmc_disable_pck1(void);

/**
 * \brief Get the frequency of the programmable clock 1 (PCK1)
 * \return PCK1 Frequency in Hz
 */
extern uint32_t pmc_get_pck1_clock(void);

/**
 * \brief Configure programmable clock 2 (PCK2) with the given master clock
 * source and clock prescaler
 * \param clock_source Clock source selection (one of the PMC_PCK_CSS_xxx_CLK
 * constants)
 * \param prescaler Prescaler value
 */
extern void pmc_configure_pck2(uint32_t clock_source, uint32_t prescaler);

/**
 * \brief Enable programmable clock 2 (PCK2)
 */
extern void pmc_enable_pck2(void);

/**
 * \brief Disable programmable clock 2 (PCK2)
 */
extern void pmc_disable_pck2(void);

/**
 * \brief Get the frequency of the programmable clock 2 (PCK2)
 * \return PCK2 Frequency in Hz
 */
extern uint32_t pmc_get_pck2_clock(void);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef _PMC_H_ */
