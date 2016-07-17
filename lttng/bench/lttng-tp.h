#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER benchmark

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "lttng-tp.h"

#if !defined(LTTNG_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define LTTNG_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    benchmark,
    probe,
    TP_ARGS(
        void
    ),
    TP_FIELDS(
    )
)

#endif /* _TP_H */

#include <lttng/tracepoint-event.h>
