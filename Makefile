CC := gcc
CXX := g++

BIN_DIR := bin
SRC_DIR := src
INC_DIR := src
OBJ_DIR := obj

BINS := $(BIN_DIR)/walkabout
SRCS_C := $(shell find $(SRC_DIR) -type f -iname "*.c")
SRCS_CPP := $(shell find $(SRC_DIR) -type f -iname "*.cpp")
INCS := $(shell find $(INC_DIR) -type f -iname "*.h")
OBJS_C := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_C))
OBJS_CPP := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_CPP))

CFLAGS := -Wall -Wextra -Werror \
	`pkg-config --cflags bullet` \
	`pkg-config --cflags freetype2`
IFLAGS := -I$(INC_DIR)/
LDFLAGS := \
	-lpthread \
	`pkg-config --libs glew` \
	`pkg-config --libs bullet` \
	`pkg-config --libs glfw3` \
	`pkg-config --libs freetype2` \
	`pkg-config --libs assimp`


all: $(BINS)

$(BINS): $(OBJS_C) $(OBJS_CPP) | $(BIN_DIR)/
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR)/
	$(CC) $(IFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS) | $(OBJ_DIR)/
	$(CXX) $(IFLAGS) $(CFLAGS) -std=c++11 -c -o $@ $<

$(BIN_DIR)/ $(OBJ_DIR)/:
	mkdir -p $@

.PHONY: all clean distclean

clean:
	rm -f $(BINS) $(OBJS_C) $(OBJS_CPP)

distclean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)

