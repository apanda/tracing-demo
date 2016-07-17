STRIP=
CFLAGS+=-O3 -fno-omit-frame-pointer -g3 -I. -ldl -llttng-ust
.PHONY: clean all

all: probes

probes: probe-app.c lttng-tp.h
	${CC} ${CFLAGS} -o probes probe-app.c
clean:
	rm -f probes
