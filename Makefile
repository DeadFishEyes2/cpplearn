# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
DEBUGFLAGS = -g -DDEBUG
LDFLAGS = 

# Directories
SRC_DIR = .
MATRIX_DIR = Matrix
GAUSS_DIR = NumericalMethods/Gauss
METHODS_DIR = NumericalMethods
OBJ_DIR = obj
BIN_DIR = .

# Target executable
TARGET = $(BIN_DIR)/main

# Source files
SRCS = main.cpp \
       $(MATRIX_DIR)/Matrix.cpp \
       $(MATRIX_DIR)/Sq_Matrix.cpp \
       $(GAUSS_DIR)/gauss.cpp

# Object files
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug build
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Clean complete"

# Remove only object files
clean-obj:
	rm -rf $(OBJ_DIR)
	@echo "Object files removed"

# Rebuild from scratch
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Print variables for debugging makefile
print-%:
	@echo $* = $($*)

# Help target
help:
	@echo "Available targets:"
	@echo "  all (default) - Build the project"
	@echo "  debug         - Build with debug flags"
	@echo "  clean         - Remove all build artifacts"
	@echo "  clean-obj     - Remove only object files"
	@echo "  rebuild       - Clean and rebuild"
	@echo "  run           - Build and run the program"
	@echo "  help          - Show this help message"

.PHONY: all debug clean clean-obj rebuild run help print-%