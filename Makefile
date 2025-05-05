# Compiler
CXX = gcc
CXXFLAGS = -Wall

# Directories
BUILD_DIR = build

# SAP project
SAP_SRC_DIR = sap_src
SAP_INC_DIR = sap_include
SAP_SRCS = $(wildcard $(SAP_SRC_DIR)/*.c)
SAP_OBJS = $(patsubst $(SAP_SRC_DIR)/%.c, $(BUILD_DIR)/sap_%.o, $(SAP_SRCS))
SAP_TARGET = $(BUILD_DIR)/sap_compiler.exe

# KY project
KY_SRC_DIR = ky_src
KY_INC_DIR = ky_include
KY_SRCS = $(wildcard $(KY_SRC_DIR)/*.c)
KY_OBJS = $(patsubst $(KY_SRC_DIR)/%.c, $(BUILD_DIR)/ky_%.o, $(KY_SRCS))
KY_TARGET = $(BUILD_DIR)/ky_compiler.exe

# Default target builds both
all: sap ky

# SAP build rules
sap: $(SAP_TARGET)

$(SAP_TARGET): $(SAP_OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(SAP_OBJS) -o $@

$(BUILD_DIR)/sap_%.o: $(SAP_SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(SAP_INC_DIR) -c $< -o $@

# KY build rules
ky: $(KY_TARGET)

$(KY_TARGET): $(KY_OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(KY_OBJS) -o $@

$(BUILD_DIR)/ky_%.o: $(KY_SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(KY_INC_DIR) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR)
