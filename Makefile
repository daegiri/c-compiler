OBJECTS= ./build/buffer.o ./build/vector.o ./build/compiler.o ./build/compile_process.o ./build/lexer.o ./build/lexer_process.o
INCLUDES= -I ./include

all: ${OBJECTS}
	gcc ${INCLUDES} main.c ${OBJECTS} -g -o ./main

./build/compiler.o: ./src/compiler.c
	gcc ${INCLUDES} ./src/compiler.c -o ./build/compiler.o -g -c

./build/compile_process.o: ./src/compile_process.c
	gcc ${INCLUDES} ./src/compile_process.c -o ./build/compile_process.o -g -c

./build/lexer.o: ./src/lexer.c
	gcc ${INCLUDES} ./src/lexer.c -o ./build/lexer.o -g -c

./build/lexer_process.o: ./src/lexer_process.c
	gcc ${INCLUDES} ./src/lexer_process.c -o ./build/lexer_process.o -g -c

./build/buffer.o: ./src/util/buffer.c
	gcc ${INCLUDES} ./src/util/buffer.c -o ./build/buffer.o -g -c

./build/vector.o: ./src/util/vector.c
	gcc ${INCLUDES} ./src/util/vector.c -o ./build/vector.o -g -c

clean:
	del .\build\*.o
	del main.exe
