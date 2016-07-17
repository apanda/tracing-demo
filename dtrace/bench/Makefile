STRIP=
CFLAGS+=-O3 -fno-omit-frame-pointer -g3
.PHONY: clean all

all: probes noprobes

noprobes: no-probe.c
	${CC} ${CFLAGS} -o noprobes no-probe.c

probes: probe.c probes.h
	${CC} ${CFLAGS} -o probes probe.c
probes.h: 
	dtrace -h -s probes.d
clean:
	rm -f probes.h probes noprobes
