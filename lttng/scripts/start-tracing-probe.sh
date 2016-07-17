#!/bin/bash
set -x
set -e
lttng create --output=$HOME/demo-trace-probe
lttng track -k --pid=`pidof probes`
lttng track -u --pid=`pidof probes`
lttng enable-event --kernel --syscall write
lttng enable-event --kernel --syscall unlink
lttng enable-event -u "probe:*"
lttng add-context -k -t pid -t procname
lttng add-context -u -t procname
lttng start
sleep 30
lttng stop
lttng destroy
