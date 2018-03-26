CFLAGS= -Wall -std=c++11 
SFML_HEADER_PATH= SFML-2.4/include
SFML_LIBRARY_PATH= SFML-2.4/lib
SFML_LINKER_STRING= -L$(SFML_LIBRARY_PATH) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: analog-clock

analog-clock: clock-window.o clock-hand.o clock.o main.o
	$(CXX) $(CFLAGS) main.o clock.o clock-hand.o clock-window.o -o bin/analog-clock $(SFML_LINKER_STRING)

clock.o: src/clock.cpp src/clock.hpp
	$(CXX) $(CFLAGS) -c src/clock.cpp

clock-hand.o: src/clock-hand.cpp src/clock-hand.hpp
	$(CXX) $(CFLAGS) -c src/clock-hand.cpp

clock-window.o: src/clock-window.cpp src/clock-window.hpp
	$(CXX) $(CFLAGS) -c src/clock-window.cpp

main.o: src/main.cpp
	$(CXX) $(CFLAGS) -c src/main.cpp -I$(SFML_HEADER_PATH)

clean:
	rm -f *.o /bin/analog-clock 
