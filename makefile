EXECUTABLE=out/game
LIBS=-lGLEW -lglut -lGL
OBJ_DIR=obj/
SRC_DIR=src/

CFLAGS=-c -Wall -std=c++11
SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)DrawBresLine.cpp \
	$(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp $(SRC_DIR)Asteroid.cpp \
	$(SRC_DIR)LoadTexture.cpp
OBJECTS=$(OBJ_DIR)Main.o $(OBJ_DIR)DrawBresLine.o \
	$(OBJ_DIR)Player.o $(OBJ_DIR)Bullet.o $(OBJ_DIR)Asteroid.o \
	$(OBJ_DIR)LoadTexture.o
MKDIRS=$(shell mkdir -p obj out)

all: $(MKDIRS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ_DIR)*.o
