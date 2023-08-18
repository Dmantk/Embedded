CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra -std=c++14
GTESTFLAGS = -lgtest -lgtest_main -pthread

INCLUDES = -IHeader
SRCDIR = Source
TESTDIR = Test

C_SOURCES = $(wildcard $(SRCDIR)/*.c)
C_OBJECTS = $(patsubst $(SRCDIR)/%.c,%.o,$(C_SOURCES))
CXX_SOURCES = $(wildcard $(SRCDIR)/*.cpp)
CXX_OBJECTS = $(patsubst $(SRCDIR)/%.cpp,%.o,$(CXX_SOURCES))
CXX_TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
CXX_TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp,%.o,$(CXX_TEST_SOURCES))

EXECUTABLE = mainrun
EXECUTABLE_TEST = maintest

.INTERMEDIATE: $(C_OBJECTS) $(CXX_OBJECTS) $(CXX_TEST_OBJECTS)
.PHONY: all clean run test

all: $(EXECUTABLE) $(EXECUTABLE_TEST)

$(EXECUTABLE): $(C_OBJECTS) $(CXX_OBJECTS)
	$(CXX) $(CFLAGS) $(C_OBJECTS) $(CXX_OBJECTS) -o $(EXECUTABLE)
$(EXECUTABLE_TEST): $(C_OBJECTS) $(CXX_OBJECTS) $(CXX_TEST_OBJECTS)
	$(CXX) $(CFLAGS) $(C_OBJECTS) $(CXX_OBJECTS) $(CXX_TEST_OBJECTS) $(GTESTFLAGS) -o $(EXECUTABLE_TEST) 

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(EXECUTABLE)
	@./$(EXECUTABLE)
test: $(EXECUTABLE_TEST)
	@./$(EXECUTABLE_TEST)

clean:
	rm -f $(EXECUTABLE) $(C_OBJECTS) $(CXX_OBJECTS) $(EXECUTABLE_TEST) $(CXX_TEST_OBJECTS)