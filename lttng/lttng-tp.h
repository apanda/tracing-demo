#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER probe

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "lttng-tp.h"

#if !defined(LTTNG_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define LTTNG_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    probe,
    unlink_file,
    TP_ARGS(
        const char*, file_name
    ),
    TP_FIELDS(
        ctf_string(file_name, file_name)
    )
)

TRACEPOINT_EVENT(
    probe,
    create_and_write_big,
    TP_ARGS(
        const char*, file_name
    ),
    TP_FIELDS(
        ctf_string(file_name, file_name)
    )
)

TRACEPOINT_EVENT(
    probe,
    create_and_write_small,
    TP_ARGS(
        const char*, file_name
    ),
    TP_FIELDS(
        ctf_string(file_name, file_name)
    )
)
#endif /* _TP_H */

#include <lttng/tracepoint-event.h>
