TARGET = bin/BlackJack.out
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

run: clean default
	./$(TARGET)

default: $(TARGET)

clean:
	rm -r -f obj/
	rm -r -f bin/
	mkdir -p obj
	mkdir -p bin

$(TARGET): $(OBJ)
	gcc -g -o $@ $?

obj/%.o : src/%.c
	gcc -g -c $< -o $@ -Iinclude


