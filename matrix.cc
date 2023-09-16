#include "matrix.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <istream>
#include <string>

// This is like creating a special container for numbers.
matrix::matrix(unsigned int rows, unsigned int cols) {
    resize(rows, cols); // We prepare the container with rows and columns.
}

// This is like changing the size of the container.
void matrix::resize(unsigned int rows, unsigned int cols) {
    // We make the container the right size and fill it with zeros.
    mat.resize(rows, std::vector<int>(cols, 0));
    this->rows = rows; // We remember how many rows it has.
    this->cols = cols; // We remember how many columns it has.
}

// This is like putting numbers into our container from a list.
void matrix::load(std::istream &is) {
    is >> rows >> cols; // We read how many rows and columns there are.
    resize(rows, cols); // We make sure our container matches the size.

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            is >> mat[i][j]; // We put each number into our container.
        }
    }
}

// This is like showing our container nicely on paper.
void matrix::print(int colWidth) const {
    int maxElementWidth = 1;

    // We find the biggest number in our container.
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            int element = mat[i][j];
            int elementWidth = std::to_string(element).length();
            if (elementWidth > maxElementWidth) {
                maxElementWidth = elementWidth;
            }
        }
    }
    // We start drawing the container on paper.
    std::cout << "Matrix " << rows << " x " << cols << ":\n";
    std::cout << std::string(2 + cols * (colWidth + 1), '-') << "\n";

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            // We write each number neatly inside a box.
            std::cout << "|" << std::setw(colWidth) << mat[i][j] << " ";
        }
        std::cout << "|\n"; // We finish each row.
    }
    std::cout << std::string(2 + cols * (colWidth + 1), '-') << "\n"; // We finish drawing.
}

// This is like multiplying two containers of numbers.
matrix matrix::operator*(const matrix& other) const {
    if (cols != other.rows) {
        // If the containers can't be multiplied, we show an error.
        std::cerr << "Matrix dimensions are not compatible for multiplication." << std::endl;
        exit(1); // We stop the program (you can handle this differently).
    }

    // We create a new container to hold the result.
    matrix result(rows, other.cols);

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < other.cols; ++j) {
            for (unsigned int k = 0; k < cols; ++k) {
                // We do some math to fill the new container.
                result.mat[i][j] += mat[i][k] * other.mat[k][j];
            }
        }
    }

    return result; // We give back the new container with the result.
}

