////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Version management.
////////////////////////////////////////////////////////////////////////////////

// *****************************************************************************
// ************************** System Include Files *****************************
// *****************************************************************************

// *****************************************************************************
// ************************** User Include Files *******************************
// *****************************************************************************

#include "ver.h"
#include "can.h"

// *****************************************************************************
// ************************** Defines ******************************************
// *****************************************************************************

/// Structure defining space for storage of a serial number.
///
/// @note The tool used for programming the serial number has a minimum flash
///       size (0x100) for preserving flash memory.  The serial number is spare
///       padded to this minimum required size to interface with the tool.
///
typedef struct
{
    uint32_t val;
    
    uint8_t spare[ 252 ];
    
} VER_SERIAL_NUM_S;

// *****************************************************************************
// ************************** Definitions **************************************
// *****************************************************************************

/// The node type - value of '1' identifies node as a Servo CAN Node.
static const uint8_t  node_type = 1;

static const uint8_t  rev_ver   = 1;    ///< Version revision number.
static const uint8_t  min_ver   = 1;    ///< Version minor number.
static const uint8_t  maj_ver   = 1;    ///< Version major number.

/// The serial number - set during initial programming.
///
/// @note The serial number is set to the starting address of Program
///       memory.
///
static const VER_SERIAL_NUM_S __attribute__((space(psv))) __at(0x200) serial_num;

// *****************************************************************************
// ************************** Function Prototypes ******************************
// *****************************************************************************

// *****************************************************************************
// ************************** Global Functions *********************************
// *****************************************************************************

void VerService ( void )
{
    // CAN message transmitted ever 50 software cycles (10ms * 50 = 500ms).
    static const uint16_t can_tx_period  = 50;
    static       uint16_t can_tx_timeout = 0;
    
    CAN_TX_NODE_VER_U version_msg;
    
    // timeout has elapsed since last CAN message transmission.
    can_tx_timeout++;
    if( can_tx_timeout >= can_tx_period )
    {
        // reset timeout
        can_tx_timeout = 0;
        
        // Construct the Version CAN message.
        version_msg.node_type  = node_type;
        version_msg.rev_ver    = rev_ver;
        version_msg.min_ver    = min_ver;
        version_msg.maj_ver    = maj_ver;
        version_msg.serial_num = serial_num.val;

        // Send the Version message.
        CANTxSet( CAN_TX_MSG_NODE_VER, version_msg.data_u16 );
    }
}

// *****************************************************************************
// ************************** Static Functions *********************************
// *****************************************************************************
