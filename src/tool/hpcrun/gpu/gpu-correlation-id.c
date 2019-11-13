//******************************************************************************
// local includes
//******************************************************************************

#include <lib/prof-lean/stdatomic.h>

#include "gpu-correlation-id.h"



//******************************************************************************
// private data
//******************************************************************************

static atomic_long gpu_correlation_id_value = 
  ATOMIC_VAR_INIT(0x8000000000000001);



//******************************************************************************
// interface operations
//******************************************************************************

uint64_t 
gpu_correlation_id
(
 void
)
{
  uint64_t correlation_id = atomic_fetch_add(&gpu_correlation_id_value, 1);
  return correlation_id;
}
