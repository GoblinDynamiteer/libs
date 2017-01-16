TARGET = libtest
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
CC = gcc
CFLAGS = -g -Wall
SUBT = test
SUBL = lib


libgeo:
	$(CC) $(SUBT)/libgeo_test.c $(SUBL)/libgeo.c -o $(TARGET) $(LIBS)
	
libinput:
	$(CC) $(SUBT)/libinput_test.c $(SUBL)/libinput.c -o $(TARGET) $(LIBS)

clean:
	-rm -f *.o
	-rm -f $(TARGET).*
	
run:
	.\$(TARGET)