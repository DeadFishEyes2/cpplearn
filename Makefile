# Compiler and flags
CXX = g++
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = .

# This finds all subdirectories within 'include' and adds them as -I paths
# It ignores hidden directories and the directory itself (.)
INCLUDE_PATHS = $(shell find $(INC_DIR) -type d -not -path '*/.*')
INC_FLAGS = $(addprefix -I,$(INCLUDE_PATHS))

CXXFLAGS = -Wall -Wextra -std=c++17 -O2 $(INC_FLAGS)
LDFLAGS = -lm

# Target executable
TARGET = $(BIN_DIR)/main

# Source files
SRCS = main.cpp $(shell find $(SRC_DIR) -name '*.cpp')
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "Linked: $(TARGET)"

# Rule for object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Cleaned build artifacts."

.PHONY: all clean