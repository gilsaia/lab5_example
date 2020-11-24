.PHONY: all clean main run test debug
all: run
main.tab.cc: main.y
	bison -o main.tab.cc -v main.y
lex.yy.cc: main.l
	flex -o lex.yy.cc main.l
main: lex.yy.cc main.tab.cc
	g++ $(shell ls *.cpp *.cc) -o main.out
run: main
	./main.out
test:main
	for file in $(basename $(shell find test/*.c)); \
	do \
		./main.out <$$file.c >$$file.res; \
	done
clean:
	rm -f *.output *.yy.* *.tab.* *.out test/*.res