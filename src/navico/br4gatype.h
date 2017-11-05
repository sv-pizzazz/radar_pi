
#ifdef INITIALIZE_RADAR

PLUGIN_BEGIN_NAMESPACE

// Note that the order of the ports is different on A and B. I guess someone
// in Navico just didn't realize this. Or it is just a bit of obfuscation.
static const NetworkAddress data4G_A(236, 6, 7, 8, 6678);
static const NetworkAddress report4G_A(236, 6, 7, 9, 6679);
static const NetworkAddress send4G_A(236, 6, 7, 10, 6680);

PLUGIN_END_NAMESPACE

#endif

#include "NavicoCommon.h"

DEFINE_RADAR(RT_4GA,                                      /* Type */
             wxT("Navico 4G A"),                          /* Name */
             NAVICO_SPOKES,                               /* Spokes */
             NAVICO_SPOKE_LEN,                            /* Spoke length (max) */
             NavicoControlsDialog(RT_4GA),                /* ControlsDialog class constructor */
             NavicoReceive(pi, ri, report4G_A, data4G_A), /* Receive class constructor */
             NavicoControl(send4G_A)                      /* Send/Control class constructor */
)