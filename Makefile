# $@(target, left of :) \
	$< (first prerequesite, first right of :) \
	$^ (all prerequesites, all right of :) 
# $(TARGET) depends on $(OBJ_FILES) to be build/linked; make looks for a rule to bulid $(OBJ_FILES)

CXX := g++ #g++ or clang++

TARGET := main
TARGET_EXT := exe

LIBRARIES := raylib
SRC_EXT := cpp

#SRC_DIR := ./src
BIN_DIR := ./bin
INC_DIR := /usr/include ./include $(wildcard ./include/*/)
LIB_DIR := /usr/lib 
OBJ_DIR := ./build

MAKEFLAGS := -j4
C_FLAGS := `pkg-config --cflags $(LIBRARIES)`\
-g -Wall #-Wextra -ggdb -MMD -MP -O3 -std=c++17
LD_FLAG := $(LIBRARIES)

INC_FLAGS := $(addprefix -I,$(INC_DIR))
LIB_FLAGS := $(addprefix -L,$(LIB_DIR))
LD_FLAGS := $(addprefix -l,$(LD_FLAG)) $(shell pkg-config --libs $(LIBRARIES))

SRC_FILES := $(wildcard */*.$(SRC_EXT))
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.$(SRC_EXT)=.o))

.PHONY: all clean build run

all: clean build run

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

build: $(BIN_DIR)/$(TARGET).$(TARGET_EXT)

# compile command
$(OBJ_DIR)/%.o: %.$(SRC_EXT)
	mkdir -p $(@D)
	$(CXX) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@
	$(info --- DEBUG:START --- "pkg-config --cflags [...]" command adds: $(shell pkg-config --cflags $(LIBRARIES)) --- DEBUG:END)

# link command
$(BIN_DIR)/$(TARGET).$(TARGET_EXT): $(OBJ_FILES)
	mkdir -p $(@D)
	$(CXX) -o $@ $^ $(LIB_FLAGS) $(LD_FLAGS) $(INC_FLAGS)
	$(info --- DEBUG:START --- "pkg-config --libs [...]" command adds: $(shell pkg-config --libs $(LIBRARIES)) --- DEBUG:END)

run: build
	$(BIN_DIR)/$(TARGET).$(TARGET_EXT)
