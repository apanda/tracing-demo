STRIP=
CFLAGS+=-O3 -fno-omit-frame-pointer -g3
.PHONY: clean all

all: probes

probes: probe-app.c
	${CC} ${CFLAGS} -o probes probe-app.c
clean:
	rm -f probes
