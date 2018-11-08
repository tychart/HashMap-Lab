all:
	g++ -std=c++11 -o lab9 *.cpp

clean:
	rm -f out_file*.txt
	rm -f lab9
