OBJ = build/Math_Functions.o build/Machine_Learning.o
BINARY = liblearnee.so

default: install

build/Machine_Learning.o:
	$(CXX) -Wall -fPIC -o build/Machine_Learning.o -c src/Machine_Learning.cpp

build/Math_Functions.o:
	$(CXX) -Wall -fPIC -o build/Math_Functions.o -c src/Math_Functions.cpp

link: $(OBJ)
	$(CXX) -shared -o bin/$(BINARY) $(OBJ)

install: link
	cp bin/$(BINARY) /usr/lib/$(BINARY)
	cp src/Machine_Learning.hpp /usr/include/Machine_Learning.hpp
	ldconfig

clean:
	$(RM) build/*
	$(RM) bin/*

uninstall:
	$(RM) /usr/lib/$(BINARY)
	ldconfig

