### Basic funcionality of makefile:
### $(BINARY) depends on $(OBJS) to be build/linked
### make looks for a rule to build $(OBJS)
### @ (as a prefix to a cli command): suppress cli output; use make -n to debug commands

### label used libraries so the respective -l flags (eg. -lraylib)
LIBRARIES 			:= raylib
WIN_LIBRARIES 		:= $(LIBRARIES) opengl32 gdi32 winmm
ifdef TERMUX_VERSION
LIBRARIES 			+= #log
else
LIBRARIES 			+= gtest benchmark 
endif

### set compile flags
# -MMD			provides dependency information (header files) for make in .d files
# -pg			ADD FOR gprof analysis TO BOTH COMPILE AND LINK COMMAND!!

CXX_FLAGS 			:= -std=c++2a -pthread #`pkg-config --cflags $(LIBRARIES)`
debug: CXX_FLAGS 	+= -g -ggdb -Wall -Wextra -Wshadow -Werror -Wpedantic -pedantic-errors -MMD -O0 #-fsanitize=address 

### set the projects label, used for the binary (eg. main.exe, root .cpp file needs same name)
BINARY 				:= main

### automatically added flags to make command
MAKEFLAGS 			:= 

#######################################
### set the used compiler to g++ or clang++
CXX 				:= g++ 
WIN_CXX 			:= /bin/x86_64-w64-mingw32-g++ 

### set the binary file extension
BINARY_EXT 			:= exe
WIN_BINARY_EXT 		:= windows.exe

### set the used file extension for c-files, usually either .c or .cpp
SRC_EXT 			:= cpp
### set the used file extension for object files, usually .o
OBJ_EXT 			:= o
WIN_OBJ_EXT 		:= win.o
### set the used file extension for dependency files, usually .d (header/source connection)
DEP_EXT 			:= d
WIN_DEP_EXT 		:= win.d

### set the respective folders from structure
### set VPATH as std dir to look for compile targets
VPATH 				:= $(shell find . -type d) 
### here go all source files (with the $(SRC_EXT) extension)
SRC_DIR 			:= ./src
SRC_DIRS 			:= $(shell find $(SRC_DIR) -type d) 
### here go local include files
LOC_INC_DIR 		:= ./include
### here go external include files
EXT_INC_DIR 		:= ./include/external
### here go local library files
LOC_LIB_DIR 		:= ./lib
### here the object files will be outputted
OBJ_DIR 			:= ./build
### here the binary file will be outputted
BIN_DIR 			:= ./bin
### define folder for test files
TEST_DIR 			:= ./test
### define folder for web content to export
WEB_DIR 			:= ./web

### set the locations of header files
SYS_INC_DIR 		:= /usr/local/include /usr/include 
WIN_SYS_INC_DIR 	:= /usr/x86_64-w64-mingw32/include 
ifdef TERMUX_VERSION
	SYS_INC_DIR := $(PREFIX)/usr/include 
endif
EXT_INC_DIRS 		:= $(shell find $(EXT_INC_DIR) -type d) 
LOC_INC_DIRS 		:= $(shell find $(LOC_INC_DIR) -type d) 

### set the locations of all possible libraries used
SYS_LIB_DIR 		:= /usr/local/lib /usr/lib 
WIN_SYS_LIB_DIR 	:= /usr/x86_64-w64-mingw32/lib 
ifdef TERMUX_VERSION
	SYS_LIB_DIR := $(PREFIX)/usr/lib 
endif
LOC_LIB_DIRS 		:= $(shell find $(LOC_LIB_DIR) -type d) 

### set raylib and emscripten directory as needed
RAYLIB_DIR 			:= /usr/lib/raylib
WIN_RAYLIB_DIR 		:= /usr/x86_64-w64-mingw32/lib/raylib/src
ifdef TERMUX_VERSION
RAYLIB_DIR 			:= $(PREFIX)/lib/raylib
endif

### set linker flags
LD_FLAGS 			:= #-fsanitize=address

#######################
### DONT EDIT BELOW ###
#######################

### make linker flags by prefixing every provided library with -l (should work for most libraries due to convention); probably pkg-config makes duplicates...
LD_LIBS 			:= $(addprefix -l,$(LIBRARIES)) #$(shell pkg-config --libs $(LIBRARIES))
WIN_LD_LIBS 			:= $(addprefix -l,$(WIN_LIBRARIES)) #$(shell pkg-config --libs $(WIN_LIBRARIES))

### make library flags by prefixing every provided path with -L; this might take a while for the first time, but will NOT be repeated every time
SYS_LIB_FLAGS 		:= $(addprefix -L,$(SYS_LIB_DIR))
WIN_SYS_LIB_FLAGS 	:= $(addprefix -L,$(WIN_SYS_LIB_DIR))
LOC_LIB_FLAGS 		:= $(addprefix -L,$(LOC_LIB_DIRS))

LIB_FLAGS 			:= $(SYS_LIB_FLAGS) $(LOC_LIB_FLAGS)
WIN_LIB_FLAGS 			:= $(WIN_SYS_LIB_FLAGS) $(LOC_LIB_FLAGS)

### make include flags by prefixing every provided path with -I
SYS_INC_FLAGS 		:= $(addprefix -I,$(SYS_INC_DIR))
WIN_SYS_INC_FLAGS	:= $(addprefix -I,$(WIN_SYS_INC_DIR))
LOC_INC_FLAGS 		:= $(addprefix -I,$(LOC_INC_DIRS))
EXT_INC_FLAGS 		:= $(addprefix -isystem,$(EXT_INC_DIRS))

INC_FLAGS 			:= $(SYS_INC_FLAGS) $(EXT_INC_FLAGS) $(LOC_INC_FLAGS)
WIN_INC_FLAGS 		:= $(WIN_SYS_INC_FLAGS) $(EXT_INC_FLAGS) $(LOC_INC_FLAGS)

### list all source files found in source file directory;
SRCS 				:= $(shell find $(SRC_DIR) -type f)
SRC_NAMES 			:= $(shell find $(SRC_DIRS) -type f -printf "%f\n")
### strip file extensions to get a list of sourcefile labels
SRC_NAMES 			:= $(patsubst %.$(SRC_EXT),%,$(SRC_NAMES))

### make list of object files need for linker command by changing ending of all source files to .o;
### (patsubst pattern,replacement,target)
### IMPORTANT for linker dependency, so they are found as compile rule
OBJS 				:= $(patsubst %,$(OBJ_DIR)/%.$(OBJ_EXT),$(SRC_NAMES))
WIN_OBJS 			:= $(patsubst %,$(OBJ_DIR)/%.$(WIN_OBJ_EXT),$(SRC_NAMES))
TEST_OBJS 			:= $(TEST_DIR)/test.$(OBJ_EXT) $(patsubst ./build/$(BINARY).o,,$(OBJS))
BM_OBJS 			:= $(TEST_DIR)/benchmark.$(OBJ_EXT) $(patsubst ./build/$(BINARY).o,,$(OBJS))
### make list of dependency files
DEPS 				:= $(patsubst $(OBJ_DIR)/%.$(OBJ_EXT),$(OBJ_DIR)/%.$(DEP_EXT),$(OBJS))
WIN_DEPS 			:= $(patsubst $(OBJ_DIR)/%.$(WIN_OBJ_EXT),$(OBJ_DIR)/%.$(WIN_DEP_EXT),$(WIN_OBJS))

### Non-file (.phony)targets (or rules)
.PHONY: all debug release web windows build rebuild run clean
ifndef TERMUX_VERSION
.PHONY: bear test benchmark
endif


### default rule by convention
all: debug 
ifndef TERMUX_VERSION
all: test
endif


bear: 
	bear -- make rebuild


debug: build


### exclude main object file to avoid multiple definitions of main
test: $(TEST_DIR)/test.$(BINARY_EXT)
	$(TEST_DIR)/test.$(BINARY_EXT)


benchmark: CXX_FLAGS += -O3 -DNDEBUG
benchmark: $(TEST_DIR)/benchmark.$(BINARY_EXT)
	$(TEST_DIR)/benchmark.$(BINARY_EXT)


### rule for release build process with binary as prerequisite
release: CXX_FLAGS += -O2
release: build web #windows 

### rule for native build process with binary as prerequisite
build: $(BIN_DIR)/$(BINARY).$(BINARY_EXT) 

ifndef TERMUX_VERSION
build: $(TEST_DIR)/test.$(BINARY_EXT) $(TEST_DIR)/benchmark.$(BINARY_EXT)
endif

# === LINKER COMMANDS ===
### MAKE binary file FROM object files
$(BIN_DIR)/$(BINARY).$(BINARY_EXT): $(OBJS)
### $@ (target, left of ":")
### $^ (all dependencies, all right of ":")
	$(CXX) -o $@ $^ $(LD_FLAGS) $(LIB_FLAGS) $(LD_LIBS) 

### LINK TEST
$(TEST_DIR)/test.$(BINARY_EXT): $(TEST_OBJS)
	$(CXX) -o $@ $^ $(LD_FLAGS) $(LIB_FLAGS) $(LD_LIBS)

### LINK BENCHMARK
$(TEST_DIR)/benchmark.$(BINARY_EXT): $(BM_OBJS)
	$(CXX) -o $@ $^ $(LD_FLAGS) $(LIB_FLAGS) $(LD_LIBS)


# === COMPILER COMMANDS ===
### MAKE object files FROM source files; "%" pattern-matches (need pair of)
$(OBJ_DIR)/%.$(OBJ_EXT): %.$(SRC_EXT)
### $< (first dependency, first right of ":")
### $@ (target, left of ":")
	$(CXX) -o $@ -c $< $(CXX_FLAGS) $(INC_FLAGS)

### COMPILE TEST 
$(TEST_DIR)/test.$(OBJ_EXT): test.$(SRC_EXT)
	$(CXX) -o $@ -c $< $(CXX_FLAGS) $(INC_FLAGS)

### COMPILE BENCHMARK 
$(TEST_DIR)/benchmark.$(OBJ_EXT): benchmark.$(SRC_EXT)
	$(CXX) -o $@ -c $< $(CXX_FLAGS) $(INC_FLAGS)


### rule for web build process
web:
	emcc -o index.html $(SRCS) -Os -Wall $(RAYLIB_DIR)/src/libraylib.a $(LOC_INC_FLAGS) -I$(RAYLIB_DIR)/src -L$(RAYLIB_DIR) -s USE_GLFW=3 -s ASYNCIFY --shell-file $(RAYLIB_DIR)/src/minshell.html -DPLATFORM_WEB
	emcc -o web/game.html $(SRCS) -Os -Wall $(RAYLIB_DIR)/src/libraylib.a $(LOC_INC_FLAGS) -I$(RAYLIB_DIR)/src -L$(RAYLIB_DIR) -s USE_GLFW=3 -s ASYNCIFY --shell-file $(RAYLIB_DIR)/src/minshell.html -DPLATFORM_WEB

### rule for windows build process
windows: $(BIN_DIR)/$(BINARY).$(WIN_BINARY_EXT) 

$(BIN_DIR)/$(BINARY).$(WIN_BINARY_EXT): $(WIN_OBJS)
	$(WIN_CXX) -o $@ $^ $(WIN_LD_FLAGS) $(WIN_LIB_FLAGS) -L$(WIN_RAYLIB_DIR) $(WIN_LD_LIBS) -static -static-libgcc -static-libstdc++

$(OBJ_DIR)/%.$(WIN_OBJ_EXT): %.$(SRC_EXT)
	$(WIN_CXX) -o $@ -c $< $(CXX_FLAGS) $(WIN_INC_FLAGS) -I$(RAYLIB_DIR)


### clear dynamically created directories
clean:
	rm -rf $(shell find . -type f -wholename "*.$(DEP_EXT)") $(shell find . -type f -wholename "*.$(OBJ_EXT)") $(shell find . -type f -wholename "*.$(BINARY_EXT)") 


### clean dynamically created directories before building fresh
rebuild: clean build


### run binary file after building
run: build
	$(BIN_DIR)/$(BINARY).$(BINARY_EXT)


### "-" surpresses error for initial missing .d files
-include $(DEPS)
