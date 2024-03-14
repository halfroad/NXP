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
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SWT_IP_CFG_H
#define SWT_IP_CFG_H

/**
*   @file
*
*   @addtogroup SWT_ip_config SWT IPL Configuration
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
#include "Swt_Ip_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_VENDOR_ID_CFG_H                     43
#define SWT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H      4
#define SWT_IP_AR_RELEASE_MINOR_VERSION_CFG_H      7
#define SWT_IP_AR_RELEASE_REVISION_VERSION_CFG_H   0
#define SWT_IP_SW_MAJOR_VERSION_CFG_H              3
#define SWT_IP_SW_MINOR_VERSION_CFG_H              0
#define SWT_IP_SW_PATCH_VERSION_CFG_H              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SWT_IP_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Swt_Ip_Cfg.h and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and Swt_Ip_PBcfg.h file are of the same vendor */
#if (SWT_IP_VENDOR_ID_CFG_H != SWT_IP_VENDOR_ID_PBCFG)
    #error "Swt_Ip_Cfg.h and Swt_Ip_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and Swt_Ip_PBcfg.h file are of the same Autosar version */
#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H != SWT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_CFG_H != SWT_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != SWT_IP_AR_RELEASE_REVISION_VERSION_PBCFG))
    #error "AutoSar Version Numbers of Swt_Ip_Cfg.h and Swt_Ip_PBcfg.h are different"
#endif

/* Check if current file and Swt_Ip_PBcfg.h file are of the same software version */
#if ((SWT_IP_SW_MAJOR_VERSION_CFG_H != SWT_IP_SW_MAJOR_VERSION_PBCFG) || \
     (SWT_IP_SW_MINOR_VERSION_CFG_H != SWT_IP_SW_MINOR_VERSION_PBCFG) || \
     (SWT_IP_SW_PATCH_VERSION_CFG_H != SWT_IP_SW_PATCH_VERSION_PBCFG))
    #error "Software Version Numbers of Swt_Ip_Cfg.h and Swt_Ip_PBcfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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

#endif /* SWT_IP_CFG_H */


