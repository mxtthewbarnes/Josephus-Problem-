CXX = g++
CXXFLAGS = -g -Wall -std=c++14

all: TestListMyJosephus TestVectorMyJosephus

TestListMyJosephus: ListMyJosephus.o TestListMyJosephus.o Destination.o
	$(CXX) $(CXXFLAGS) ListMyJosephus.o TestListMyJosephus.o Destination.o -o TestListMyJosephus

TestVectorMyJosephus: VectorMyJosephus.o TestVectorMyJosephus.o Destination.o
	$(CXX) $(CXXFLAGS) VectorMyJosephus.o TestVectorMyJosephus.o Destination.o -o TestVectorMyJosephus

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f TestListMyJosephus TestVectorMyJosephus *.o