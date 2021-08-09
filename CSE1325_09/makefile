CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o donut.o java.o product.o store.o main_window.o *.h
	${CXX} ${CXXFLAGS} -o main main.o donut.o java.o product.o store.o main_window.o ${GTKFLAGS}
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp ${GTKFLAGS}
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp
main_window.o: main_window.cpp *.h
	${CXX} ${CXXFLAGS} -c main_window.cpp ${GTKFLAGS}
clean:
	-rm -f *.gch *.o main
