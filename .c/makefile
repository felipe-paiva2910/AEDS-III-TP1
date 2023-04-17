CC=gcc
IDIR=../includes
CFLAGS=-I$(IDIR)

ODIR=obj
LIBS=-lm
DEPS= pontos.h file.h

_DEPS = pontos.h file.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pontos.o file.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run:
	./tp1 -i input.txt -o output.txt