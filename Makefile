CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC_FILES = *.c
HEADER_FILES = *.h
TARGET = hsh

.PHONY: all
all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)

.PHONY: lint
lint:
	@betty $(SRC_FILES) $(HEADER_FILES)

.PHONY: clean
clean:
	$(RM) $(TARGET)