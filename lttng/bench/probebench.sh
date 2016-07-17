#!/bin/bash
#set -x
set -e
taskset -c 5 ./probe-bench &
PID=$! # Record PID here
lttng create --output=$HOME/probe-bench
lttng track -u --pid=$PID
lttng enable-event -u "benchmark:*"
lttng start
echo "Waiting"
wait $PID
lttng stop
lttng destroy
