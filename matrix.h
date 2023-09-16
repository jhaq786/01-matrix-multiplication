#ifndef H_MATRIX_MULTIPLY
#define H_MATRIX_MULTIPLY

#include <istream>
#include <vector>

class matrix
{
public:
    matrix(unsigned int rows = 0, unsigned int cols = 0);
    void resize(unsigned int rows, unsigned int cols);
    void load(std::istream &is);
    void print(int colWidth) const;

    const int &at(unsigned int row, unsigned int col) const
    {
        return mat[row][col];
    }
    int &at(unsigned int row, unsigned int col)
    {
        return mat[row][col];
    }

    matrix operator*(const matrix &) const;

    unsigned int getRows() const { return rows; }
    unsigned int getCols() const { return cols; }

private:
    unsigned int rows; // Declare 'rows' and 'cols' as member variables
    unsigned int cols;
    std::vector<std::vector<int>> mat;
};

#endif
