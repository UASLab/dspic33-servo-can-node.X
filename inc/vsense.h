////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief VSENSE signal management.
////////////////////////////////////////////////////////////////////////////////

#ifndef VSENSE_H_
#define	VSENSE_H_

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
/// @brief  Calibration correction of VSENSE signals and annunciation on CAN.
////////////////////////////////////////////////////////////////////////////////
void VsenseService( void );

#endif	// VSENSE_H_