### Basic funcionality of makefile:
### $(TARGET) depends on $(OBJS) to be build/linked
### make looks for a rule to build $(OBJS)
### @ (as a prefix to a cli command): suppress cli output; use make -n to debug commands

### option for termux platform  make: "make OS=termux"
OS := linux

### set the used compiler to g++ or clang++
CXX := g++ 

### set the projects name, used for the targeted cpp file (eg. main.cpp) and the binary (eg. main.exe)
TARGET := main

### set the binary file extension
TARGET_EXT := exe

### name used libraries so the respective -l flags (eg. -lraylib)
LIBRARIES := raylib

### set the used file extension for c-files, usually either .c or .cpp
SRC_EXT := cpp
### set the used file extension for object files, usually .o
OBJ_EXT := o
### set the used file extension for dependency files, usually .d (header/source connection)
DEP_EXT := d

### set the respective folders from structure
### set VPATH as std dir to look for compile targets
VPATH := $(shell find . -type d) 
### here go all source files (with the $(SRC_EXT) extension)
SRC_DIR := ./src
SRC_DIRS := $(shell find $(SRC_DIR) -type d) 
### here go local include files
LOC_INC_DIR := ./include
### here go local library files
LOC_LIB_DIR := ./lib
### here the object files will be outputted
OBJ_DIR := ./build
### here the binary file will be outputted
BIN_DIR := ./bin
### define folder for test files
TEST_DIR := ./test
### define folder for web content to export
WEB_DIR := ./web
### set the locations of header files
SYS_INC_DIR := /usr/local/include /usr/include 
ifeq ($(OS),termux)
	SYS_INC_DIR := $(PREFIX)/usr/include 
endif
LOC_INC_DIRS := $(shell find $(LOC_INC_DIR) -type d) 

### set the locations of all possible libraries used
SYS_LIB_DIR := /usr/local/lib /usr/lib 
ifeq ($(OS),termux)
	SYS_LIB_DIR := $(PREFIX)/usr/lib 
endif
LOC_LIB_DIRS := $(shell find $(LOC_LIB_DIR) -type d) 

### set raylib and emscripten directory as needed
RAYLIB_DIR := /usr/lib/raylib
ifeq ($(OS),termux)
	RAYLIB_DIR := $(PREFIX)/lib/raylib
endif
### automatically added flags to make command
MAKEFLAGS := 

### set compile flags
# `pkg-config --cflags $(LIBRARIES)`: 	add the compile flags for the provided libraries with external program
# -g:			??? not sure, use symbols from executable in debug output?
# -O2:			performance optimization, -OS for size
# -W(all/extra): 		enable warnings
# -std=c++17:	force c++ standard
# -MMD			provides dependency information (header files) for make in .d files
CXX_FLAGS := `pkg-config --cflags $(LIBRARIES)` -g -Wall -Wextra -MMD -O0 #-Wpedantic 

#######################
### DONT EDIT BELOW ###
#######################

### make linker flags by prefixing every provided library with -l (should work for most libraries due to convention); probably pkg-config makes duplicates...
LD_LIBS := $(addprefix -l,$(LIBRARIES)) $(shell pkg-config --libs $(LIBRARIES))

### make library flags by prefixing every provided path with -L; this might take a while for the first time, but will NOT be repeated every time
SYS_LIB_FLAGS := $(addprefix -L,$(SYS_LIB_DIR))
LOC_LIB_FLAGS := $(addprefix -L,$(LOC_LIB_DIRS))
LIB_FLAGS := $(SYS_LIB_FLAGS) $(LOC_LIB_FLAGS)

### make include flags by prefixing every provided path with -I
SYS_INC_FLAGS := $(addprefix -I,$(SYS_INC_DIR))
LOC_INC_FLAGS := $(addprefix -I,$(LOC_INC_DIRS))
INC_FLAGS := $(SYS_INC_FLAGS) $(LOC_INC_FLAGS)

### list all source files found in source file directory;
SRCS := $(shell find $(SRC_DIR) -type f)
SRC_NAMES := $(shell find $(SRC_DIRS) -type f -printf "%f\n")
### strip file extensions to get a list of sourcefile names
SRC_NAMES := $(patsubst %.$(SRC_EXT),%,$(SRC_NAMES))

### make list of object files need for linker command by changing ending of all source files to .o;
### (patsubst pattern,replacement, target)
### IMPORTANT for linker prerequesite, so they are found as compile rule
OBJS := $(patsubst %,$(OBJ_DIR)/%.$(OBJ_EXT),$(SRC_NAMES))
### make list of dependency files
DEPS := $(patsubst $(OBJ_DIR)/%.$(OBJ_EXT),$(OBJ_DIR)/%.$(DEP_EXT),$(OBJS))

### Non-file (.phony)targets (or rules)
.PHONY: all build web clean rebuild deploy run test

### default rule by convention
all: build test 

### rule for native build process with binary as prerequisite
build: $(BIN_DIR)/$(TARGET).$(TARGET_EXT)

# linker command
### MAKE binary file FROM object files
$(BIN_DIR)/$(TARGET).$(TARGET_EXT): $(OBJS)
### make folder for binary file
	@mkdir -p $(BIN_DIR)
### $@ (target, left of ":")
### $^ (all prerequesites, all right of ":")
	@$(CXX) -o $@ $^ $(LIB_FLAGS) $(LD_LIBS) 
#$(INC_FLAGS)

# compiler command
### MAKE object files FROM source files; "%" pattern-matches (need pair of)
$(OBJ_DIR)/%.$(OBJ_EXT): %.$(SRC_EXT)
### copy source structure for object file directory
	@mkdir -p $(OBJ_DIR)
### $< (first prerequesite, first right of ":")
### $@ (target, left of ":")
	@$(CXX) -o $@ -c $< $(CXX_FLAGS) $(INC_FLAGS)

### rule for test process
test: build_test
	$(TEST_DIR)/test.$(TARGET_EXT)

build_test: $(TEST_DIR)/test.$(TARGET_EXT)
$(TEST_DIR)/test.$(TARGET_EXT): test.$(OBJ_EXT)
	@$(CXX) -o $@ $^ $(LIB_FLAGS) $(LD_LIBS)

$(OBJ_DIR)/test.$(OBJ_EXT): test.$(SRC_EXT)
	@$(CXX) -o $@ -c $< $(CXX_FLAGS) $(INC_FLAGS)

### rule for web build process
web:
	@emcc -o index.html $(SRCS) -Os -Wall $(RAYLIB_DIR)/libraylib.a $(LOC_INC_FLAGS) -I$(RAYLIB_DIR) -L$(RAYLIB_DIR) -s USE_GLFW=3 -s ASYNCIFY --shell-file $(RAYLIB_DIR)/minshell.html -DPLATFORM_WEB
	@mkdir -p $(WEB_DIR)
	@emcc -o web/game.html $(SRCS) -Os -Wall $(RAYLIB_DIR)/libraylib.a $(LOC_INC_FLAGS) -I$(RAYLIB_DIR) -L$(RAYLIB_DIR) -s USE_GLFW=3 -s ASYNCIFY --shell-file $(RAYLIB_DIR)/minshell.html -DPLATFORM_WEB

### clear dynamically created directories
clean:
	@rm -rf $(OBJ_DIR) $(WEB_DIR)

### clean dynamically created directories before building fresh
rebuild: clean 
	@$(MAKE)

deploy: rebuild 
	@$(MAKE) web

### run binary file after building
run: build
	$(BIN_DIR)/$(TARGET).$(TARGET_EXT)

### "-" surpresses error for initial missing .d files
-include $(DEPS)
