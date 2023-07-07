CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra -std=c++11
INCLUDES = -IHeader
SRCDIR = Source

C_SOURCES = $(wildcard $(SRCDIR)/*.c)
C_OBJECTS = $(patsubst $(SRCDIR)/%.c,%.o,$(C_SOURCES))
CXX_SOURCES = $(wildcard $(SRCDIR)/*.cpp)
CXX_OBJECTS = $(patsubst $(SRCDIR)/%.cpp,%.o,$(CXX_SOURCES))
EXECUTABLE = main

.INTERMEDIATE: $(C_OBJECTS) $(CXX_OBJECTS)

.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): $(C_OBJECTS) $(CXX_OBJECTS)
	$(CXX) $(CFLAGS) $(C_OBJECTS) $(CXX_OBJECTS) -o $(EXECUTABLE)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(EXECUTABLE)
	@./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(C_OBJECTS) $(CXX_OBJECTS)
