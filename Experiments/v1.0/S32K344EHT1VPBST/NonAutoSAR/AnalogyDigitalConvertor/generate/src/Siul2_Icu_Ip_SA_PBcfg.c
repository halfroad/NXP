
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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
 *   @file          Siul2_Icu_Ip_PBCfg.c
 *   @implements    Icu_PBCfg.c_Artifact
 *   @version       3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup siul2_icu_ip SIUL2 IPL
 *   @{
 */
 


#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Std_Types.h"
#include "Siul2_Icu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_SA_PBCFG_VENDOR_ID_C                       43
#define SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define SIUL2_ICU_IP_SA_PBCFG_SW_MAJOR_VERSION_C                3
#define SIUL2_ICU_IP_SA_PBCFG_SW_MINOR_VERSION_C                0
#define SIUL2_ICU_IP_SA_PBCFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C  != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C  != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_SA_PBcfg.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_SA_PBCFG_VENDOR_ID_C != SIUL2_ICU_IP_TYPES_VENDOR_ID)
    #error "Siul2_Icu_Ip_SA_PBcfg.c and Siul2_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SA_PBCFG_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_SA_PBcfg.c and Siul2_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_SA_PBCFG_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SA_PBCFG_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SA_PBCFG_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip_SA_PBcfg.c and Siul2_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/
 
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"           
extern void KEY1_Pressed_IcuSignalNotification(void);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*
*  @brief    SIUL2 Channels Configuration
*/
const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_0_ChannelConfig_PB[1U] =
{
    /** @brief IcuSiul2_0_Channel_0 */
    {
        /** @brief Siul2 HW Module and Channel used by the Icu channel */
        13U,
        /** @brief Siul2 Digital Filter enable */
        (boolean)TRUE,
        /** @brief Siul2 Digital Filter value */
        0U,
        /** @brief Siul2 request type*/
        SIUL2_ICU_IRQ,
        /** @brief Siul2 Edge type*/
        SIUL2_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        NULL_PTR,
        /** @brief Notification function */
        &KEY1_Pressed_IcuSignalNotification,
          /** @brief Callback Param1*/
          13U
    }
};

/*
*  @brief    SIUL2 Instance Configuration
*/
const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_0_InstanceConfig_PB =
{
    /** @brief Interrupt Filter Clock Prescaler */
    (uint8)0U,
    /** @brief Interrupt Filter Clock Alternate Prescaler  */
    (uint8)0U
};

/*
*  @brief    SIUL2 Default IP Configuration
*/
const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_0_Config_PB =
{
    /** @brief Number of Siul2 channels in the Icu configuration */
    (uint8)1U,
    /** @brief The Siul2 instance configuration */
    &Siul2_Icu_Ip_0_InstanceConfig_PB,
    /** @brief Pointer to the array of Siul2 channel configurations */
    &Siul2_Icu_Ip_0_ChannelConfig_PB
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */
/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

