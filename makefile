ifeq ($(OS),Windows_NT)
	RM = del /Q obj\*.o out\*
	LIBS=-lglfw3dll -lglew32 -lopengl32 -lglut
else
	ifeq ($(shell uname), Linux)
		RM = rm -f obj/*.o out/*
		LIBS=-lglfw -lGLEW -lGL -lglut
	endif
endif

EXECUTABLE=out/game
OBJ_DIR=obj/
SRC_DIR=src/
MKDIRS=$(shell mkdir obj/ out/)

CFLAGS=-c -Wall -std=c++11 -static-libgcc -static-libstdc++
SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp \
	$(SRC_DIR)LoadTexture.cpp $(SRC_DIR)Block.cpp $(SRC_DIR)Vec2.cpp \
	$(SRC_DIR)CircleBlock.cpp $(SRC_DIR)Vec3.cpp
OBJECTS=$(OBJ_DIR)Main.o $(OBJ_DIR)Player.o $(OBJ_DIR)Bullet.o \
	$(OBJ_DIR)LoadTexture.o $(OBJ_DIR)Block.o $(OBJ_DIR)Vec2.o \
	$(OBJ_DIR)CircleBlock.o $(OBJ_DIR)Vec3.o

all: $(MKDIRS) $(EXECUTABLE) run

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	$(RM)

run:
	out/game
