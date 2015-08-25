////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Watchdog Timer (WDT) management.
////////////////////////////////////////////////////////////////////////////////

#ifndef WDT_H_
#define WDT_H_

// *****************************************************************************
// ************************** System Include Files *****************************
// *****************************************************************************

#include <xc.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// *****************************************************************************
// ************************** User Include Files *******************************
// *****************************************************************************

// *****************************************************************************
// ************************** Defines ******************************************
// *****************************************************************************

// *****************************************************************************
// ************************** Declarations *************************************
// *****************************************************************************

// *****************************************************************************
// ************************** Function Prototypes ******************************
// *****************************************************************************

////////////////////////////////////////////////////////////////////////////////
/// @brief  Service the WDT - kick the watchdog.
////////////////////////////////////////////////////////////////////////////////
void WDTService ( void );

////////////////////////////////////////////////////////////////////////////////
/// @brief  Enable the WDT.
///
/// @note   Enabling of the watchdog timer causes a reset of the counter value.
////////////////////////////////////////////////////////////////////////////////
void WDTEnable ( void );

////////////////////////////////////////////////////////////////////////////////
/// @brief  Disable the WDT.
////////////////////////////////////////////////////////////////////////////////
void WDTDisable ( void );

#endif  // WDT_H_