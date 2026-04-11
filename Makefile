CC       = gcc
INC	 = inc
CFLAGS   = -Wall -Wextra -Werror -I$(INC)
SRC_DIRS = src debug initialize_arguments memory_management parse_flags parse_from_arguments_passed print print_color print_formatting read_dir recursion run sort strings
OBJ_DIR  = build
TARGET   = ft_ls

# 2. File Discovery
# Find all .c files in the specified directories

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# 3. Path Mapping
# Mirror the src paths into the obj folder: src/main.c -> obj/src/main.o
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# 4. Rules
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS)  -o $@
	@echo "Built $(TARGET) successfully."

# Compile source files to object files
# The mkdir -p $(dir $@) creates the subfolders inside obj/ automatically

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< -> $@"

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean

