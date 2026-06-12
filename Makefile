.PHONY: main

main:
	clang main.c -o main && ./main
run:
	./main
clean:
	rm -f main
