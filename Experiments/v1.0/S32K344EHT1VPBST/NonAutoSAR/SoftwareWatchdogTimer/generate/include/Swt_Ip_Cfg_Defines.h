/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P01_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SWT_IP_CFG_DEFINES_H
#define SWT_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Swt
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SWT_IP_CFG_DEFINES_VENDOR_ID                    43
#define SWT_IP_CFG_DEFINES_MODULE_ID                    102
#define SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define SWT_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define SWT_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Wdg header file are of the same Autosar version */
    #if ((SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Swt_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief  Enable available Swt instances on platform
*/
#define SWT_IP_ENABLE_INSTANCE0 (STD_ON)

/**
* @brief  This variable will indicate if the Wdg Development Error Detect feature is activated
*/
#define SWT_IP_DEV_ERROR_DETECT (STD_OFF)

/**
* @brief  This variable will indicate if the Wdg Disable Allowed feature is activated
*/
#define SWT_IP_DEINIT (STD_ON)

/**
* @brief  Define indicating for which Swt instances the Clear Reset Request feature is supported
*/
#define SWT_IP_CLEAR_RESET_REQUEST (STD_OFF)

/**
* @brief  This variable will indicate if the ISR for SWT instances is used
*/
#define SWT_IP_ISR0_USED (STD_ON)

/**
* @brief  Define a certain timeout method from OsIf will be used in the driver
*/
#define SWT_IP_TIMEOUT_METHOD     (OSIF_COUNTER_DUMMY)
#define SWT_IP_OSIF_TIMEOUT_VAL     (30000)
/**
* @brief  This variable will indicate RAM/ROM execution
*/
#define WDG_RAM (0U)
/**
* @brief  This constant specifies the minimum value that will be set in the SWT timeout register
*/
#define SWT_MIN_VALUE_TIMEOUT_U32 ((uint32)0x3) 
/**
* @brief This constant define value of SWT_IP_RRR_SUPPORT
*/
/**
* @brief This constant define value of SWT_IP_DISCOUNTINUOUS_INSTANCE_IDS
*/
#define SWT_IP_DISCOUNTINUOUS_INSTANCE_IDS  (STD_OFF) 
/**
* @brief  Support for running in stop mode
*/
#define SWT_IP_HAS_STOP_MODE  (1U) 
/**
* @brief  Define pointer type to access SWT register
*/
#define Swt_Ip_Type  SWT_Type
/**
* @brief  The number of Swt instance
*/
#define SWT_INSTANCE_NUM  (SWT_INSTANCE_COUNT) 
/**
* @brief  Support for clear reset request
*/
#define SWT_IP_HAS_CLEAR_RESET  (1U) 
/**
* @brief  Support for Self Reset
*/
#define SWT_IP_RRR_SUPPORT  (0x00000003UL) 
/**
* @brief  The key values to clear Soft Lock bit
*/
#define SWT_IP_UNLOCK_VALUE1_U16  (0xC520U) 
#define SWT_IP_UNLOCK_VALUE2_U16  (0xD928U) 
/**
* @brief  The key values used for resetting the SWT counter in Fixed Service Sequence Mode
*/
#define SWT_IP_FIXED_SERVICE_VALUE1_U16  (0xA602U) 
#define SWT_IP_FIXED_SERVICE_VALUE2_U16  (0xB480U) 
/**
* @brief  The reset value of the control register
*/
#define SWT_IP_CR_RESET_VALUE_U32  (0xFF00010AU) 
/**
* @brief  The reset value of the timeout register
*/
#define SWT_IP_TO_RESET_VALUE_U32  (0x00000320U) 
/**
* @brief  The reset value of the window register
*/
#define SWT_IP_WN_RESET_VALUE_U32  (0x00000000U) 
/**
* @brief  The reset value of the service key register
*/
#define SWT_IP_SK_RESET_VALUE_U16  (0x0000U) 
/**
* @brief  Sets the master access protection field
*/
#define SWT_IP_MAP_MASK_U32  (0xFF000000U) 
#define SWT_IP_MAP_SHIFT  (24U) 

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SWT_IP_CFG_DEFINES_H */

