CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic

PBIN = ./bin
PSRC = ./src
PINC = ./include
POBJ = ./object
PLIB = ./lib

OBJECT = $(POBJ)/testMoments.o $(POBJ)/moments.o

#All

.PHONY : all
all : $(PBIN)/testMoments

#Library

.PHONY : library
library : $(PLIB)/libimage.a

$(PLIB)/libimage.a : $(POBJ)/image.o
	ar crv $@ $^

#Executable files

$(PBIN)/testMoments : $(POBJ)/testMoments.o $(POBJ)/moments.o library
	$(CC) $(OBJECT)  $(PLIB)/libimage.a -o $@

#Object files

$(POBJ)/moments.o : $(PSRC)/moments.c $(PINC)/image.h $(PINC)/point.h
	$(CC) $< -c $(CFLAGS) -o $@

$(POBJ)/testMoments.o : $(PSRC)/testMoments.c $(PINC)/moments.h
	$(CC) $< -c $(CFLAGS) -o $@

$(POBJ)/image.o : $(PSRC)/image.c
	$(CC) $< -c $(CFLAGS) -o $@

#Remove

.PHONY : clean
clean :
	-rm  $(PSRC)/*.o
	-rm  $(PSRC)/*~
	-rm $(POBJ)/*.o	

.PHONY : distclean
distclean : clean
	-rm $(PBIN)/*
