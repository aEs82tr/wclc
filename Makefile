all: fsize wclc

fsize: fsize.c
	cc -o f fsize.c
wclc: wclc.c
	cc -o wc wclc.c
	cc -o lc wclc.c
	cc -o ec wclc.c
clean:
	rm wc lc f ec
