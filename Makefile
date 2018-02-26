

all:
	g++  -g   cs202.cpp  -o cs202
	g++  -g   cs163.cpp  -o cs163
	g++  -g   cs162.cpp  -o cs162

clean:
	rm cs202
	rm cs163
	rm cs162


clear:
	rm -f cs202.cpp
	rm -f cs163.cpp
	rm -f cs162.cpp

