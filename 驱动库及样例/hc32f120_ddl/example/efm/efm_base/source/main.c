/**
 *******************************************************************************
 * @file  efm/efm_base/source/main.c
 * @brief Main program of EFM for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-05-7        chengy          First version
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

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ddl.h"

/**
 * @addtogroup HC32F120_DDL_Examples
 * @{
 */

/**
 * @addtogroup EFM_Base
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/


/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/* LED0 Port/Pin definition */
#define LED_PORT        GPIO_PORT_2
#define LED0_PORT       GPIO_PORT_2
#define LED0_PIN        GPIO_PIN_5

/* LED1 Port/Pin definition */
#define LED1_PORT       GPIO_PORT_2
#define LED1_PIN        GPIO_PIN_6

/* LED0~1 definition */
#define LED0_ON()       GPIO_ResetPins(LED0_PORT, LED0_PIN)
#define LED0_OFF()      GPIO_SetPins(LED0_PORT, LED0_PIN)

#define LED1_ON()       GPIO_ResetPins(LED1_PORT, LED1_PIN)
#define LED1_OFF()      GPIO_SetPins(LED1_PORT, LED1_PIN)

#define LED_ON()        GPIO_ResetPins(LED_PORT, LED0_PIN | LED1_PIN)
#define LED_OFF()       GPIO_SetPins(LED_PORT, LED0_PIN | LED1_PIN)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  Led Init
 * @param  None
 * @retval None
 */
void Led_Init(void)
{
    stc_gpio_init_t stcGpioInit;

    /* LED initialize */
    GPIO_StructInit(&stcGpioInit);
    GPIO_Init(LED_PORT, (LED0_PIN | LED1_PIN), &stcGpioInit);

    LED_OFF();
    GPIO_OE(LED_PORT, (LED0_PIN | LED1_PIN), Enable);
}

/**
 * @brief  Main function of EFM project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_efm_cfg_t stcEfmCfg;

    uint8_t u8Data = 0x5A;
    uint16_t u16Data = 0xA5A5;
    uint32_t u32Data = 0xAA5555AA;
    uint32_t u32Addr;

    /* Led Init */
    Led_Init();
    LED1_ON();

    /* Unlock EFM. */
    EFM_Unlock();
    /* EFM default config. */
    EFM_StrucInit(&stcEfmCfg);
    EFM_Config(&stcEfmCfg);

    /* Enable flash. */
    EFM_Cmd(Enable);

    /* Wait flash ready. */
    while(Set != EFM_GetFlagStatus(EFM_FLAG_RDY));
    /* Erase sector 10. */
    EFM_SectorErase(EFM_SECTOR10_ADRR);

    u32Addr = EFM_SECTOR10_ADRR;

    /* program byte */
    if(Ok != EFM_ProgramByte(u32Addr, u8Data))
    {
        LED0_ON();
        LED1_OFF();
    }

    u32Addr += 2;

    /* program half word */
    if(Ok != EFM_ProgramHalfWord(u32Addr, u16Data))
    {
        LED0_ON();
        LED1_OFF();
    }

    u32Addr += 2;

    /* program word */
    if(Ok != EFM_ProgramWord(u32Addr, u32Data))
    {
        LED0_ON();
        LED1_OFF();
    }

    /* Lock EFM. */
    EFM_Lock();

    while(1);
}

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
