all: stats2

stats2: stats2.cpp
	g++ -o stats2 stats2.cpp -Wall -std=c++11

clean:
	rm -f stats2
