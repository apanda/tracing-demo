STRIP=
CFLAGS+=-O3 -fno-omit-frame-pointer -g3
.PHONY: clean all

all: probes

probes: probe-app.c probes.h
	${CC} ${CFLAGS} -o probes probe-app.c
probes.h: 
	dtrace -h -s probes.d
clean:
	rm -f probes.h probes
