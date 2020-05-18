CXX = g++
cpps = Simulator.cpp Instruction.cpp main.cpp
CFLAGS = -std=c++14 -o
all: main

main: $(cpps)
	$(CXX) $(CFLAGS) $@ $^

clean:
	rm main