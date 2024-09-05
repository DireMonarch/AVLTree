cc_directives := -std=c++20

all: build/test

build/test: src/main.cc src/AVLTree.h src/AVLTreeNode.h
	g++ ${cc_directives} src/main.cc -o build/test

run: all
	build/test

clean:
	rm build/test

lint:
# Requires cpplint to be installed
# 	See: https://github.com/cpplint/cpplint
	cpplint src/main.cc src/MapEntry.h src/AVLTreeNode.h src/AVLTree.h