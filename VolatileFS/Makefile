CC = gcc
CFLAGS = -Wall -Wextra -IInc -DDEBUG
SRC = Src/fs.c Src/main.c
OBJ = $(SRC:.c=.o)
TARGET = volatilefs

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
