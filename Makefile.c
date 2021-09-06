#
TARGET	= $(COMP_TARGET)
APOBJS	= $(TARGET).o

TMAXLIBD= $(TMAXDIR)/lib64

TMAXLIBS= -lcli 
CFLAGS	= -O -I$(TMAXDIR)

#
.SUFFIXES : .c

.c.o: 
	$(CC) $(CFLAGS) -c $<

#
# client compile
#

$(TARGET): $(APOBJS)
	$(CC) $(CFLAGS) -L$(TMAXLIBD) -o $(TARGET) $(APOBJS) $(TMAXLIBS) 

#
clean:
	-rm -f *.o core $(TARGET)
