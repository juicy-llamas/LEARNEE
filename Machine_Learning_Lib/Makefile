
OBJ = build/Matrix.o build/Quick_Maths.o
BINARY = liblearnee.so

default: install

build/Matrix.o:
	$(CXX) -Wall -fPIC -o build/Matrix.o -c src/Matrix_Not_Vectorized.cpp

build/Quick_Maths.o:
	$(CXX) -Wall -fPIC -o build/Quick_Maths.o -c src/Quick_Maths.cpp

link: $(OBJ)
	$(CXX) -shared -o bin/$(BINARY) $(OBJ)

install: link
	cp bin/$(BINARY) /usr/lib/$(BINARY)
	#cp src/include/* /usr/include/
	ldconfig

clean:
	$(RM) build/*
	$(RM) bin/*

uninstall:
	$(RM) /usr/lib/$(BINARY)
	ldconfig

