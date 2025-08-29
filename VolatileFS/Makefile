CC = gcc
CFLAGS = -Wall -Wextra -IInc -DDEBUG
SRC = Src/fs.c Src/main.c
OBJ = $(SRC:.c=.o)
TARGET = volatilefs

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
