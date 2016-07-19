STRIP=
CFLAGS+=-O3 -fno-omit-frame-pointer -g3
.PHONY: clean all

all: slowpoke

slowpoke: slowpoke.c
	${CC} ${CFLAGS} -o slowpoke slowpoke.c
clean:
	rm -f slowpoke
