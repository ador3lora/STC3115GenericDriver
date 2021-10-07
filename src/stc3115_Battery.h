/**
 * *****************************************************************************
 * @file	stc3115_Battery.h
 *
 * *****************************************************************************
 */

/* Define to prevent recursive inclusion */
#ifndef __Battery_H
#define __Battery_H

/*----------------------------------------------------------------------------*/
/* INTERNAL PARAMETERS -------------------------------------------------------*/
/* TO BE ADJUSTED ACCORDING TO BATTERY AND APPLCICATION CHARACTERISTICS ------*/
/*----------------------------------------------------------------------------*/

/* Battery parameters define -------------------------------------------------*/

#define BATT_CAPACITY	2950	/*!< Battery nominal capacity in mAh */
#define BATT_RINT		346		/*!< Internal battery impedance in mOhms, 0 if unknown */

#define OCV_OFFSET_TAB	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }	/*!< OCVTAB: (Open Circuit Voltage curve,
																			 * ie when the battery is relaxed (no charge or discharge) */

/* Application parameters define ---------------------------------------------*/

#define VMODE		MIXED_MODE	/*!< Running mode constant, VM_MODE or MIXED_MODE */
#define ALM_EN		1			/*!< Alarm enable constant, set at 1 to enable */
#define ALM_SOC		10			/*!< SOC alarm in % */
#define ALM_VBAT	3600		/*!< Voltage alarm in mV */
#define RSENSE		50			/*!< Sense resistor (soldered on the board) in mOhms */

#define APP_EOC_CURRENT		75		/*!< End charge current in mA */
#define APP_CUTOFF_VOLTAGE	3000	/*!< Application cut-off voltage in mV */

#endif	/* __Battery_H */
