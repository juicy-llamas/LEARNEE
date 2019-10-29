
OBJ = build/Matrix.o build/Quick_Maths.o
BINARY = liblearnee.so

default: install

build/Matrix.o:
	$(CXX) -Wall -Werror -fPIC -o build/Matrix.o -c src/Matrix_Not_Vectorized.cpp

build/Quick_Maths.o:
	$(CXX) -Wall -Werror -fPIC -o build/Quick_Maths.o -c src/Quick_Maths.cpp

link: $(OBJ)
	$(CXX) -Wall -Werror -shared -fPIC -o bin/$(BINARY) $(OBJ)

install: link
	cp bin/$(BINARY) /usr/lib
	mkdir -p /usr/include/learnee
	cp src/include/* /usr/include/learnee
	ldconfig

clean:
	$(RM) build/*
	$(RM) bin/*

uninstall:
	$(RM) /usr/lib/$(BINARY)
	$(RM) -r /usr/include/learnee
	ldconfig

