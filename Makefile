OBJECTS= ./build/buffer.o ./build/vector.o ./build/compiler.o ./build/compile_process.o ./build/lexer.o ./build/lexer_process.o
INCLUDES= -I ./include
OBJECT_FLAGS= -g -c

all: ${OBJECTS}
	gcc ${INCLUDES} main.c ${OBJECTS} -g -o ./main

./build/compiler.o: ./src/compiler.c
	gcc ${INCLUDES} ./src/compiler.c -o ./build/compiler.o ${OBJECT_FLAGS}

./build/compile_process.o: ./src/compile_process.c
	gcc ${INCLUDES} ./src/compile_process.c -o ./build/compile_process.o ${OBJECT_FLAGS}

./build/lexer.o: ./src/lexer.c
	gcc ${INCLUDES} ./src/lexer.c -o ./build/lexer.o ${OBJECT_FLAGS}

./build/lexer_process.o: ./src/lexer_process.c
	gcc ${INCLUDES} ./src/lexer_process.c -o ./build/lexer_process.o ${OBJECT_FLAGS}

./build/buffer.o: ./src/util/buffer.c
	gcc ${INCLUDES} ./src/util/buffer.c -o ./build/buffer.o ${OBJECT_FLAGS}

./build/vector.o: ./src/util/vector.c
	gcc ${INCLUDES} ./src/util/vector.c -o ./build/vector.o ${OBJECT_FLAGS}

clean:
	del .\build\*.o
	del main.exe
