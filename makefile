CXX = clang++

CXXFLAGS       = -g -std=c++11 -Wall -Wextra -pedantic 

TARGETS = cashier

all: $(TARGETS)

clean:
	rm -f $(TARGETS)
	rm -rf *.o

cashier: cashier.cpp menu.o sandwich.o
	$(CXX) $(CXXFLAGS) -o cashier $^

menu.o: menu.cpp menu.hpp
	$(CXX) $(CXXFLAGS) -c menu.cpp

sandwich.o: sandwich.cpp sandwich.hpp
	$(CXX) $(CXXFLAGS) -c sandwich.cpp
