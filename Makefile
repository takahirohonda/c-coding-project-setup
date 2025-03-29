hello:
	echo "hello"

compile: test.c
	gcc test.c -o build/test

run:
	./build/test
