# Compiler
CXX = gcc
CXXFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and Object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Output executable
TARGET = $(BUILD_DIR)/main.exe

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)