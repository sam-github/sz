sz szcc: sz.c
	gcc -Wall -o sz sz.c
	g++ -Wall -o szcc sz.c
run: sz szcc
	./sz
	./szcc

