/*
Jafar Haq
z1980233
CSCI 340 - PE1 Data Struct Algorithm Analysis
Assignment 1 matrix-multiplication
9/4

*/

#include "matrix.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ifstream safeopen(const string &fname)
{
    ifstream f;
    try {
        f.open(fname, std::ifstream::in);
    } catch (const std::ios_base::failure &e) {
        cerr << e.code().message() << endl;
        exit(1);
    }
    return f;
}

int main(int argc, char **argv)
{
    ifstream is1;
    ifstream is2;
    int col_width;

    if (argc != 4) {
        cerr << "Usage: matmul file1 file2 colwidth" << endl;
        exit(1);
    }

    is1 = safeopen(argv[1]);
    is2 = safeopen(argv[2]);

    istringstream iss(argv[3]);
    iss >> col_width;

    matrix a;
    matrix b;
    matrix c;

    a.load(is1);
    b.load(is2);

    c = a * b;

    cout << "\nMatrix1: ";
    a.print(col_width);
    cout << "\nMatrix2: ";
    b.print(col_width);
    cout << "\nMatrix3: ";
    c.print(col_width);
    cout << endl;

    return 0;
}
