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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Swt_Ip_PBcfg.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_PBCFG_VENDOR_ID_C                     43
#define SWT_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define SWT_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define SWT_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define SWT_IP_PBCFG_SW_MAJOR_VERSION_C              3
#define SWT_IP_PBCFG_SW_MINOR_VERSION_C              0
#define SWT_IP_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Swt_Ip_PBcfg header file are of the same vendor */
#if (SWT_IP_PBCFG_VENDOR_ID_C != SWT_IP_VENDOR_ID_PBCFG)
#error "Swt_Ip_PBcfg.c and Swt_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Swt_Ip_PBcfg header file are of the same Autosar version */
#if ((SWT_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != SWT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG   ) || \
     (SWT_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != SWT_IP_AR_RELEASE_MINOR_VERSION_PBCFG   ) || \
     (SWT_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != SWT_IP_AR_RELEASE_REVISION_VERSION_PBCFG))
#error "AutoSar Version Numbers of Swt_Ip_PBcfg.c and Swt_Ip_PBcfg.h are different"
#endif

/* Check if current file and Swt_Ip_PBcfg header file are of the same software version */
#if ((SWT_IP_PBCFG_SW_MAJOR_VERSION_C != SWT_IP_SW_MAJOR_VERSION_PBCFG) || \
     (SWT_IP_PBCFG_SW_MINOR_VERSION_C != SWT_IP_SW_MINOR_VERSION_PBCFG) || \
     (SWT_IP_PBCFG_SW_PATCH_VERSION_C != SWT_IP_SW_PATCH_VERSION_PBCFG))
#error "Software Version Numbers of Swt_Ip_PBcfg.c and Swt_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"


const Swt_Ip_ConfigType Swt_Ip_Cfg0 = 
{
    (uint8)           SWT_IP_ALL_MAP_DISABLE | SWT_IP_MAP0_ENABLE | SWT_IP_MAP1_ENABLE | SWT_IP_MAP2_ENABLE | SWT_IP_MAP3_ENABLE | SWT_IP_MAP4_ENABLE | SWT_IP_MAP5_ENABLE | SWT_IP_MAP6_ENABLE | SWT_IP_MAP7_ENABLE, /* u8MapEnBitmask */
    (boolean)         FALSE,        /* bEnResetOnInvalidAccess */
    #if (defined(SWT_IP_HAS_STOP_MODE) && (SWT_IP_HAS_STOP_MODE == 1U))
    (boolean)         FALSE,        /* bEnRunInStopMode */
    #endif
    (boolean)         FALSE,        /* bEnRunInDebugMode */
    (boolean)         FALSE,        /* bEnWindow */
    (boolean)         FALSE,        /* bEnInterrupt */
    (Swt_Ip_ServiceModeType)         FALSE,        /* eServiceMode */
    (uint32)          0xfa00,    /* u32TimeoutValue */
    (uint32)          0x0,        /* u32WindowValue */
    (uint32)          0x0,        /* u16InitialKey */
    (Swt_Ip_LockType) SWT_IP_UNLOCK, /* lockConfig */
    NULL_PTR        /* pfSwtCallback */
};


#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

