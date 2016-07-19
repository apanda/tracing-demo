#!/usr/bin/env python3
from collections import defaultdict
import babeltrace
import sys
import os

def add_trace_directories(directory, trace_collection):
    """ Add subdirectories to babeltrace trace collection"""
    for dirname, dirnames, filenames in os.walk(directory):
        if 'metadata' in filenames:
            if trace_collection.add_trace(dirname, "ctf") is None:
                raise Exception("Could not add directory %s"%dirname)

def histogram(trace_collection):
    hist = defaultdict(lambda: 0)
    for ev in trace_collection.events:
        if ev.name == "syscall_entry_write":
            hist[(ev['pid'], ev['procname'])] += 1
    for k in sorted(hist.items(), key=lambda kv: kv[1]):
        (pid, procname) = k[0]
        print("%d %s %d"%(pid, procname, k[1]))

def main(args):
    # Create a trace collection
    trace_collection = babeltrace.TraceCollection()
    for arg in args:
        add_trace_directories(arg, trace_collection)
    histogram(trace_collection)

if __name__=="__main__":
    main(sys.argv[1:])
