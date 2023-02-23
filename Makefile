OBJECTS= ./build/buffer.o ./build/vector.o ./build/compiler.o ./build/compile_process.o ./build/lexer.o ./build/lexer_process.o
INCLUDES= -I ./

all: ${OBJECTS}
	gcc main.c ${INCLUDES} ${OBJECTS} -g -o ./main

./build/compiler.o: ./compiler.c
	gcc ./compiler.c ${INCLUDES} -o ./build/compiler.o -g -c

./build/compile_process.o: ./compile_process.c
	gcc ./compile_process.c ${INCLUDES} -o ./build/compile_process.o -g -c

./build/lexer.o: ./lexer.c
	gcc ./lexer.c ${INCLUDES} -o ./build/lexer.o -g -c

./build/lexer_process.o: ./lexer_process.c
	gcc ./lexer_process.c ${INCLUDES} -o ./build/lexer_process.o -g -c

./build/buffer.o: ./util/buffer.c
	gcc ./util/buffer.c ${INCLUDES} -o ./build/buffer.o -g -c

./build/vector.o: ./util/vector.c
	gcc ./util/vector.c ${INCLUDES} -o ./build/vector.o -g -c

clean:
	del .\build\*.o
	del main.exe
