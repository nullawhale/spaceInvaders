RM = del
EXECUTABLE=out\game.exe
LIBS=-lglew32 -lfreeglut -lopengl32
OBJ_CLEAN=obj\*.o

CC=g++
CFLAGS=-c -Wall -std=c++11
STATIC=-static-libgcc -static-libstdc++
OBJ_DIR=obj/
SRC_DIR=src/
SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)DrawBresLine.cpp \
	$(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp $(SRC_DIR)Asteroid.cpp \
	$(SRC_DIR)LoadTexture.cpp
OBJECTS=$(SOURCES:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LIBS) $(STATIC)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp src/*.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ_CLEAN) $(EXECUTABLE)