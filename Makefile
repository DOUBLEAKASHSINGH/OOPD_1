test:
# question 1
	g++ -c tax.cpp
	g++ -g -o debug1 tax.o
	g++ -O3 -o optimized1 tax.o

# question 2
	g++ -c tax2.cpp
	g++ -g -o debug2 tax2.o
	g++ -O3 -o optimized2 tax2.o