#ifndef MATRIX_H
#define MATRIX_H
#include <string>
using namespace std;
namespace MatrixSpace
{
      class Matrix
      {
      private:
            int **vals;
            unsigned int rowCount;
            unsigned int colCount;

      public:
            Matrix(unsigned int m, unsigned int n);
            Matrix(const Matrix &mat);
            Matrix(int **array, unsigned int m, unsigned int n);
            unsigned int rows() const;
            unsigned int columns() const;
            int get(unsigned i, unsigned j) const;
            void set(unsigned i, unsigned j, int value);
            Matrix operator+(const Matrix &mat);
            Matrix operator-(const Matrix &mat);
            Matrix operator*(const Matrix &mat);
            Matrix operator~() const;
            bool operator==(const Matrix &mat);
            string toStr();
            ~Matrix();
      };
}
#endif
