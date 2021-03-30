run:classify.o menu.o start.o 
	g++ classify.o menu.o start.o -o run
classify.o:classify.cpp
	g++ -c classify.cpp
menu.o:menu.cpp
	g++ -c menu.cpp
start.o:start.cpp
	g++ -c start.cpp
clean:
	rm start.o menu.o classify.o