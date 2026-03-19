PROJECT_NAME = cpong
VERSION = 0.1.0

SRC_DIR = src
BUILD_DIR = build

CC = clang
CFLAGS = -Wall -Wextra -g -Iinclude -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib \
          -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET = $(BUILD_DIR)/$(PROJECT_NAME)

# Default
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run
run: all
	./$(TARGET)

# Clean
clean:
	rm -rf $(BUILD_DIR)

# Debug
debug: CFLAGS += -DDEBUG
debug: clean all

.PHONY: all clean run debug