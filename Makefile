CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla -MMD -g
EXEC = sorcery
OBJECTS = main.o card.o player.o no_ability_minion.o air_elemental.o earth_elemental.o board.o  ascii_graphics.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

