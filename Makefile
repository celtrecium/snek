CC=zcc +zx
CFLAGS=-Iinclude -O3 -clib=ansi -vn -lndos -create-app
SRC=src
OBJECTS=${SRC}/main.o ${SRC}/resources.o ${SRC}/point.o ${SRC}/scene.o ${SRC}/snake.o ${SRC}/utils.o ${SRC}/game.o ${SRC}/game_render.o

all: main.o resources.o point.o scene.o snake.o utils.o game.o game_render.o snake clean

main.o: ${SRC}/main.c
	${CC} ${CFLAGS} -c $^

resources.o: ${SRC}/resources.c
	${CC} ${CFLAGS} -c $^

point.o: ${SRC}/point.c
	${CC} ${CFLAGS} -c $^

scene.o: ${SRC}/scene.c
	${CC} ${CFLAGS} -c $^

snake.o: ${SRC}/snake.c
	${CC} ${CFLAGS} -c $^

utils.o: ${SRC}/utils.c
	${CC} ${CFLAGS} -c $^

game.o: ${SRC}/game.c
	${CC} ${CFLAGS} -c $^

game_render.o: ${SRC}/game_render.c
	${CC} ${CFLAGS} -c $^

snake: ${OBJECTS}
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -rf ${OBJECTS}
