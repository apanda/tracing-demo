STRIP=
CFLAGS+=-O3 -fno-omit-frame-pointer -g3 
CFLAGS_PROBE=${CFLAGS}
CFLAGS_PROBE+=-I. -ldl -llttng-ust
.PHONY: clean all

all: probe-bench noprobe-bench

probe-bench: probe.c lttng-tp.h
	${CC} ${CFLAGS_PROBE} -o probe-bench probe.c
noprobe-bench: no-probe.c
	${CC} ${CFLAGS} -o noprobe-bench no-probe.c
clean:
	rm -f probe-bench noprobe-bench
