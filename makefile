CC=g++
CFLAGS=-c -Wall
LIBS=-lglew32 -lfreeglut -lopengl32
STATIC=-static-libgcc -static-libstdc++
OBJ_DIR=obj/
SRC_DIR=src/
SOURCES=$(SRC_DIR)Main.cpp $(SRC_DIR)DrawBresenhamLine.cpp \
	$(SRC_DIR)Player.cpp $(SRC_DIR)Bullet.cpp $(SRC_DIR)Asteroid.cpp
OBJECTS=$(SOURCES:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
EXECUTABLE=out\game
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	RM = rm -rf
else
	RM = del
endif

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LIBS) $(STATIC)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) obj\*.o $(EXECUTABLE)