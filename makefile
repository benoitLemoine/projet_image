CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic
PBIN = ./bin
PSRC = ./src
PINC = ./include

OBJECT = $(PSRC)/moments.o

#All

.PHONY : all
all : $(OBJECT)

#Executable files

#Object files

$(PSRC)/moments.o : $(PSRC)/moments.c $(PINC)/image.h
	$(CC) $< -c $(CFLAGS) -o $@

#Remove

.PHONY : clean
clean :
	-rm  $(PSRC)/*.o
	-rm  $(PSRC)/*~

.PHONY : distclean
distclean : clean
	-rm $(PBIN)/*
