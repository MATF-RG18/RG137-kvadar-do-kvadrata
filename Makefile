PROGRAM    = kvadar_do_kvadrata
CC	   = gcc
#CFLAGS     = -Wall 
GLFLAGS     = -lSOIL -lglut -lGLU -lGL -lm

$(PROGRAM): main.c SOIL.h
	$(CC) -o $(PROGRAM) main.c $(GLFLAGS)	

.PHONY: clean 

clean: 
	-rm *.o $(PROGRAM) *core
