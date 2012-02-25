CXX=g++
CXXFLAGS=-Iinc -g -Wall -lX11 -c

.phony: clean
.phone: all

madbirds: graphics.o xinfo.o maingraphics.o component.o score.o movable.o sling.o hittable.o bird.o block.o target.o terrain.o physics.o lvltextgen.o game.o application.o main.o 
	g++ -o madbirds -Iinc -lX11 -Wall graphics.o xinfo.o maingraphics.o component.o score.o movable.o sling.o hittable.o bird.o block.o target.o terrain.o physics.o lvltextgen.o main.o game.o application.o

main.o: application.o src/main.cc
	${CXX} ${CXXFLAGS} src/main.cc

graphics.o: src/graphics.cc inc/graphics.h
	${CXX} ${CXXFLAGS} src/graphics.cc

xinfo.o: src/xinfo.cc inc/xinfo.h
	${CXX} ${CXXFLAGS} src/xinfo.cc

maingraphics.o: graphics.o xinfo.o src/maingraphics.cc inc/maingraphics.h
	${CXX} ${CXXFLAGS} src/maingraphics.cc

component.o: graphics.o src/component.cc inc/component.h
	${CXX} ${CXXFLAGS} src/component.cc

score.o: component.o src/score.cc inc/score.h
	${CXX} ${CXXFLAGS} src/score.cc

movable.o: component.o src/movable.cc inc/movable.h
	${CXX} ${CXXFLAGS} src/movable.cc

sling.o: movable.o src/sling.cc inc/sling.h
	${CXX} ${CXXFLAGS} src/sling.cc

hittable.o: movable.o src/hittable.cc inc/hittable.h
	${CXX} ${CXXFLAGS} src/hittable.cc

bird.o: hittable.o src/bird.cc inc/bird.h
	${CXX} ${CXXFLAGS} src/bird.cc

block.o: hittable.o src/block.cc inc/block.h
	${CXX} ${CXXFLAGS} src/block.cc

target.o: hittable.o src/target.cc inc/target.h
	${CXX} ${CXXFLAGS} src/target.cc

terrain.o: hittable.o src/terrain.cc inc/terrain.h
	${CXX} ${CXXFLAGS} src/terrain.cc

physics.o: bird.o block.o target.o terrain.o src/physics.cc inc/physics.h
	${CXX} ${CXXFLAGS} src/physics.cc

lvltextgen.o: sling.o bird.o block.o target.o terrain.o src/lvltextgen.cc inc/lvltextgen.h
	${CXX} ${CXXFLAGS} src/lvltextgen.cc

game.o: graphics.o lvltextgen.o score.o sling.o bird.o block.o terrain.o target.o src/game.cc
	${CXX} ${CXXFLAGS} src/game.cc

application.o: game.o graphics.o xinfo.o src/application.cc
	${CXX} ${CXXFLAGS} src/application.cc

clean:
	rm *.o madbirds

