LDFLAGS=-lwiringPi
SRC= test.cpp RCSwitch.cpp RcOok.cpp Sensor.cpp
OBJ= $(SRC:.cpp=.o)

all: test

%.o: %.cpp
	g++ -c $<

test: $(OBJ)
	g++ -o $@ $^ $(LDFLAGS) 

