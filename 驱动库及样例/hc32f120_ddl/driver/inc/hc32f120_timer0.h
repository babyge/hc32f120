/**
 *******************************************************************************
 * @file  hc32f120_timer0.h
 * @brief Head file for TIMER0 module.
 *
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-27       Wangmin         First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2016, Huada Semiconductor Co., Ltd. All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co., Ltd. ("HDSC").
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 *
 * This software contains source code for use with HDSC
 * components. This software is licensed by HDSC to be adapted only
 * for use in systems utilizing HDSC components. HDSC shall not be
 * responsible for misuse or illegal use of this software for devices not
 * supported herein. HDSC is providing this software "AS IS" and will
 * not be responsible for issues arising from incorrect user implementation
 * of the software.
 *
 * Disclaimer:
 * HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACCOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 *******************************************************************************
 */
#ifndef __HC32F120_TIMER0_H__
#define __HC32F120_TIMER0_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_common.h"
#include "ddl_config.h"

/**
 * @addtogroup HC32F120_DDL_Driver
 * @{
 */

/**
 * @addtogroup TIMER0
 * @{
 */

#if (DDL_TIMER0_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup TIMER0_Global_Types TIMER0 Global Types
 * @{
 */

/**
 * @brief Timer0 base counter function init structrue definition
 */
typedef struct
{
    uint32_t       u32ClockDivision;  /*!< specifies the TIMER0 clock division,
                                         and this parameter can be a value of
                                         @ref TIMER0_Clock_Division_define */

    uint32_t       u32ClockMode;      /*!< specifies the TIMER0 clock mode,
                                         asynchronous or synchronous
                                         @ref TIMER0_Clock_Mode_define */

    uint32_t       u32ClockSource;    /*!< specifies the TIMER0 clock source,
                                         and this parameter can be a value of
                                         @ref TIMER0_Clock_Source_define*/

    uint32_t       u32Tmr0Fun;        /*!< specifies the TIMER0 function,
                                         asynchronous or synchronous
                                         @ref TIMER0_Clock_Mode_define */

    uint32_t       u32HwTrigFunc;     /*!< specifies the TIMER0 compare
                                         function hardware trigger function, and
                                         this parameter can be a value of @ref
                                         TIMER0_HardwareTrigger_Func_define */

    uint16_t       u16CmpValue;       /*!< specifies the TIMER0 counter value
                                         This value can be set 0-0xFFFF */
}stc_tim0_init_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup TIMER0_Global_Macros TIMER0 Global Macros
 * @{
 */

/** @defgroup TIMER0_Clock_Division_define TIMER0 clock division define
 * @{
 */
#define TIMER0_CLK_DIV1     (uint32_t)((uint32_t)0<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV2     (uint32_t)((uint32_t)1<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV4     (uint32_t)((uint32_t)2<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV8     (uint32_t)((uint32_t)3<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV16    (uint32_t)((uint32_t)4<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV32    (uint32_t)((uint32_t)5<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV64    (uint32_t)((uint32_t)6<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV128   (uint32_t)((uint32_t)7<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV256   (uint32_t)((uint32_t)8<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV512   (uint32_t)((uint32_t)9<<TMR0_BCONR_CKDIVA_POS)
#define TIMER0_CLK_DIV1024  (uint32_t)((uint32_t)10<<TMR0_BCONR_CKDIVA_POS)

/**
 * @}
 */

/** @defgroup TIMER0_Clock_Source_define TIMER0 clock source define
 * @{
 */
#define TIMER0_CLK_SRC_HCLK         (uint32_t)0x00000000
#define TIMER0_CLK_SRC_INTHWTRIG    TMR0_BCONR_SYNCLKA
#define TIMER0_CLK_SRC_LRC          (uint32_t)0x00000000
#define TIMER0_CLK_SRC_XTAL32       TMR0_BCONR_ASYNCLKA
/**
 * @}
 */

/** @defgroup TIMER0_Clock_Mode_define TIMER0 clock mode define
 * @{
 */
#define TIMER0_CLK_SYNC             (uint32_t)0x00000000
#define TIMER0_CLK_ASYNC            TMR0_BCONR_SYNSA
/**
 * @}
 */

/** @defgroup TIMER0_Function_define TIMER0 Function define
 * @{
 */
#define TIMER0_FUNC_CMP             (uint32_t)0x00000000
#define TIMER0_FUNC_CAPTURE         (TMR0_BCONR_CAPMDA | TMR0_BCONR_HICPA)
/**
 * @}
 */

/** @defgroup TIMER0_HardwareTrigger_Func_define TIMER0 hardware trigger function define
 * @{
 */
#define TIMER0_BT_HWTRG_FUNC_START  TMR0_BCONR_HSTAA
#define TIMER0_BT_HWTRG_FUNC_CLEAR  TMR0_BCONR_HCLEA
#define TIMER0_BT_HWTRG_FUNC_STOP   TMR0_BCONR_HSTPA
#define TIMER0_BT_HWTRG_FUNC_NONE   (uint32_t)0x00000000

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup TIMER0_Global_Functions
 * @{
 */

en_result_t TIMER0_StructInit(stc_tim0_init_t* pstcInitStruct);
en_result_t TIMER0_Init(const stc_tim0_init_t* pstcBaseInit);
void TIMER0_DeInit(void);

void TIMER0_Cmd(en_functional_state_t enCmd);
void TIMER0_IntCmd(en_functional_state_t enCmd);

en_flag_status_t TIMER0_GetFlag(void);
void TIMER0_ClearFlag(void);
uint16_t TIMER0_GetCntReg(void);
void TIMER0_WriteCntReg(uint16_t u16Cnt);
uint16_t TIMER0_GetCmpReg(void);
void TIMER0_WriteCmpReg(uint16_t u16Cnt);

void TIMER0_SetTriggerSrc(en_event_src_t enEvent);

/**
 * @}
 */

#endif /* DDL_TIMER0_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32F120_TIMER0_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
