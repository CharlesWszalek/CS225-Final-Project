# Makefile for compiling main.cpp, Group.cpp, and Group.h
# File: Makefile
# Version: 1.0 name: Charles W 9/??/24 created
# 	   1.1 name: Brandon P 10/29/2024

# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall #-lGL -lGLU -lglfw

# Source files
SRCS := ai.cpp cards.cpp deck.cpp hand.cpp human.cpp main.cpp player.cpp table.cpp global.cpp
# Object files
OBJS := $(SRCS:.cpp=.o)
# Dependency files
DEPS := $(SRCS:.cpp=.d)
# Executable name
TARGET := TXhold

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation step for .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Generate dependency files
%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM -MT '$*.o $*.d' $< > $@

# Clean target
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

# Phony targets
.PHONY: all clean
