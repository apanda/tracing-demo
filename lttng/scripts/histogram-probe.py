#!/usr/bin/env python3
from collections import defaultdict
import babeltrace
import sys
import os
import colorama
from colorama import Fore, Back, Style

def add_trace_directories(directory, trace_collection):
    """ Add subdirectories to babeltrace trace collection"""
    for dirname, dirnames, filenames in os.walk(directory):
        if 'metadata' in filenames:
            if trace_collection.add_trace(dirname, "ctf") is None:
                raise Exception("Could not add directory %s"%dirname)

def timeline(trace_collection):
    hist = defaultdict(lambda: 0)
    prev = None
    for ev in trace_collection.events_timestamps(trace_collection.timestamp_begin, trace_collection.timestamp_end):
        if ev.name.startswith("probe:"):
            # print(Fore.RED + "%d %s %s"%(ev.cycles, ev.name, ev['file_name']))
            prev = ev.name
        elif ev.name == "syscall_entry_write":
            if prev:
                hist[prev] += 1
            prev = None
        else:
            prev = None
    for k in sorted(hist.items(), key=lambda kv: kv[1]):
        print("%s %d"%(k[0], k[1]))

def main(args):
    # Create a trace collection
    trace_collection = babeltrace.TraceCollection()
    for arg in args:
        add_trace_directories(arg, trace_collection)
    timeline(trace_collection)

if __name__=="__main__":
    main(sys.argv[1:])
