1.

g++ -c matrix.cc -o matrix.o
g++ main.cc matrix.o -o matmul


************************
2.

./matmul matrix01.dat matrix02.dat 6 &> mymatrix6.out
OR if using command on a windows system
matmul matrix01.dat matrix02.dat 6 > mymatrix6.out

************************

3.
diff matrix.refout-6 mymatrix6.out
