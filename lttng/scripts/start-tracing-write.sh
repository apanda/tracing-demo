#!/bin/bash
set -x
set -e
lttng create --output=$HOME/demo-trace
lttng enable-event --kernel --syscall write
lttng add-context -k -t pid -t procname
lttng start
sleep 15
lttng stop
lttng destroy
