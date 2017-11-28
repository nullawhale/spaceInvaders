ifeq ($(OS),Windows_NT)
	RM = del /Q
	LIBS=-lglfw3dll -lglew32 -lopengl32
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		LIBS=-lglfw -lGLEW -lGL
	endif
endif

EXECUTABLE=out/game
OBJ_DIR=obj/
SRC_DIR=src/
MKDIRS=$(shell mkdir obj/ out/)

CFLAGS=-c -Wall -std=c++11 -static-libgcc -static-libstdc++
SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp \
	$(SRC_DIR)LoadTexture.cpp $(SRC_DIR)Gun.cpp $(SRC_DIR)Block.cpp
OBJECTS=$(OBJ_DIR)Main.o $(OBJ_DIR)Player.o $(OBJ_DIR)Bullet.o \
	$(OBJ_DIR)LoadTexture.o $(OBJ_DIR)Gun.o $(OBJ_DIR)Block.o

all: $(MKDIRS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	$(RM) obj\*.o out\*
