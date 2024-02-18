SRC := hello.c
TARGET = hello
OBJS := $(SRC:.c=.o)
CROSS_COMPILE := 

all:
	$(CROSS_COMPILE)gcc -g -Wall  -c -o $(OBJS) $(SRC)
	$(CROSS_COMPILE)gcc -g -Wall -I/ $(OBJS) -o $(TARGET)

clean:
	-rm -f *.o $(TARGET) *.elf *.map
