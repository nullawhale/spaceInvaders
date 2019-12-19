CFLAGS = -c -Wall -std=c++17

ifeq ($(OS),Windows_NT)
	RM = del /Q obj\*.o out\*
	CFLAGS += -static-libgcc -static-libstdc++
	LIBS=-lglfw3dll -lglew32 -lopengl32 -lglut
else ifeq ($(shell uname),Darwin)
	RM = rm -f obj/* out/*
	LIBS = -lglfw -framework GLUT -framework OpenGL -framework Cocoa
else ifeq ($(shell uname), Linux)
	RM = rm -f obj/*.o out/*
	CFLAGS += -static-libgcc -static-libstdc++
	LIBS=-lglfw -lGLEW -lGL -lglut
endif

EXECUTABLE=out/game
OBJ_DIR=obj/
SRC_DIR=src/
MKDIRS=$(shell mkdir -p obj/ out/)

SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp \
	$(SRC_DIR)LoadTexture.cpp $(SRC_DIR)Block.cpp \
	$(SRC_DIR)CircleBlock.cpp $(SRC_DIR)World.cpp
OBJECTS=$(OBJ_DIR)Main.o $(OBJ_DIR)Player.o $(OBJ_DIR)Bullet.o \
	$(OBJ_DIR)LoadTexture.o $(OBJ_DIR)Block.o \
	$(OBJ_DIR)CircleBlock.o $(OBJ_DIR)World.o

all: $(MKDIRS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	$(RM)

run:
	out/game
