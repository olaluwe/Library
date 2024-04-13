# Compiler and Linker
CXX := g++

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INCLUDE_DIR := include

# Targets
EXECUTABLE := library

# Files and flags
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CPPFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -g  # Include the header directory and enable all warnings and debugging symbols
LDFLAGS := 

# The first rule is the one executed when no parameters are fed to the Makefile
all: directories $(BIN_DIR)/$(EXECUTABLE)

# Rule to create directories
directories:
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

# Link the executable
$(BIN_DIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile the source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | directories
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Clean rule for cleaning up the project
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean directories
