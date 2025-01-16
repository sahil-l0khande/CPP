# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = -lcurl -pthread

# Project structure
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and target
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = build/order_exec_mgmt

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	@echo "Linking target $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)

# Run the program
run: all
	@echo "Running $(TARGET)..."
	./$(TARGET)

.PHONY: all clean run

