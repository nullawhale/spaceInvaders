UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	RM = rm -rf
	EXECUTABLE=out/game
	LIBS=-lGLEW -lglut -lGL
	OBJ_CLEAN=obj/*.o
else
	RM = del
	EXECUTABLE=out\game.exe
	LIBS=-lglew32 -lfreeglut -lopengl32
	OBJ_CLEAN=obj\*.o
endif
CC=g++
CFLAGS=-c -Wall
STATIC=-static-libgcc -static-libstdc++
OBJ_DIR=obj/
SRC_DIR=src/
SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)DrawBresLine.cpp \
	$(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp $(SRC_DIR)Asteroid.cpp
OBJECTS=$(SOURCES:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LIBS) $(STATIC)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ_CLEAN) $(EXECUTABLE)
