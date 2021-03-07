.PHONY: all build rebuild clean run 

all: build

build:
	./build.sh

rebuild: clean build

clean: 
	rm -rf build

run: all
	./build/bin/bostardecks 