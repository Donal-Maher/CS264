#include "Matrix.h"
#include <iostream>
using namespace MatrixSpace;
/* *
* Constructor for an m x n matrix.
* Initialises each element as a 0
* @param m is the number of rows
* @param n is the number of columns
*/
Matrix::Matrix(unsigned int m, unsigned int n) {
    this->rowCount = m;
    this->colCount = n;
    this->vals = new int*[m];
    for(int i = 0; i<m; i++) {
        int* row = new int[n];
        for(int j = 0; j<n; j++) {
            row[j] = 0;
        }
        this->vals[i] = row;
    }
}
/* *
* Constructor for a new matrix as a deep copy 
* of the input matrix mat
* @param mat is another matrix
*/
Matrix::Matrix(const Matrix & mat){
    this->rowCount = mat.rowCount;
    this->colCount = mat.colCount;
    this->vals = new int*[this->rowCount];
    for(int i= 0; i < this->rowCount; i++) {
        int* row = new int[this->colCount];
        for(int j = 0; j<this->colCount; j++) {
            row[j] = mat.vals[i][j];
        }
        this->vals[i] = row;
    }
}
/* *
* Constructor for an m x n matrix.
* Initialises each element with the corresponding value from the input array
* @param m is the number of rows
* @param n is the number of columns
* @param array is a pointer to a pointer to an integer, representing a 2D array of ints
*/
Matrix::Matrix(int ** array , unsigned int m , unsigned int n){
    this->rowCount = m;
    this->colCount = n;
    this->vals = new int*[m];
    for(int i = 0; i<m; i++) {
        int* row = new int[n];
        for(int j = 0; j<n; j++) {
            row[j] = array[i][j];
        }
        this->vals[i] = row;
    }
}
/* *
* Gets the number of rows in the matrix
* @return value of rowCount
*/
unsigned int Matrix::rows() const {
    return this->rowCount;
}
/* *
* Gets the number of columns in the matrix
* @return value of colCount
*/
unsigned int Matrix::columns() const {
    return this->colCount;
}
/* *
* Checks if the values i and j are within the matrix bounds.
* Gets the value of the matrix in the ith row and jth column.
* @param non unsigned int i is the index for the row
* @param non unsigned int j is the index for the column
* @return if i and j are in the matrix return the corresponding value, else returns -1
*/
int Matrix::get(unsigned int i, unsigned int j) const {
    if(i >= this->rowCount || j>= this->colCount) {
        cout<<endl<<"Index out of bounds"<<endl;
        return -1;
    }
    return this->vals[i][j];
}
/* *
* Checks if the values i and j are within the matrix bounds.
* Sets the ith row and jth column of the matrix to the input value
* @param An unsigned int i is the index for the row
* @param An unsigned int j is the index for the column
* @param An int to be inserted into the matrix
*/
void Matrix::set(unsigned i, unsigned j, int value) {
    if(i >= this->rowCount || j>= this->colCount) {
        cout<<"Index out of bounds"<<endl;
    } else {
        this->vals[i][j] = value;
    }
}
/* *
* Checks if the two matrices are the same dimensions.
* Performs matrix addition between the two matrices, where each element 
* of the left matrix is added to the corresponding element of the right
* matrix.
* @param mat is the right matrix
* @return A matrix sum if the two matrices are the same size, otherwise an empty matrix
*/
Matrix Matrix::operator +(const Matrix & mat){
    if(this->rowCount != mat.rowCount || this->colCount != mat.colCount) {
        cout<<"Matrices are not compatible for addition"<<endl;
        return Matrix(0,0);
    }
    Matrix sum = Matrix(mat);
    for(int i = 0; i<sum.rowCount; i++) {
        for(int j= 0; j<sum.colCount; j++) {
            sum.vals[i][j] += this->vals[i][j];
        }
    }
    return sum;
}
/* *
* Checks if the two matrices are the same dimensions.
* Performs matrix subtraction between the two matrices, where each element 
* of the right matrix is subtracted to the corresponding element of the left
* matrix.
* @param mat is the right matrix
* @return A matrix sum if the two matrices are the same size, otherwise an empty matrix
*/
Matrix Matrix::operator -(const Matrix & mat){
    if(this->rowCount != mat.rowCount || this->colCount != mat.colCount) {
        cout<<"Matrices are not compatible for subtraction"<<endl;
        return Matrix(0,0);
    }
    Matrix sum = Matrix(mat.rowCount,mat.colCount);
    for(int i = 0; i<sum.rowCount; i++) {
        for(int j= 0; j<sum.colCount; j++) {
            sum.vals[i][j] = this->vals[i][j] - mat.vals[i][j];
        }
    }
    return sum;
}
/* *
* Checks if the number of columns in the left matrix is equal to the 
* number of rows in the right matrix.
* Creates a matrix with the number of rows of the left matrix and the 
* number of columns of the right matrix.
* Performs matrix multiplication by calculation dot product of rows in left product
* with columns of right matrix.
* @param mat is the right matrix
* @return A matrix product if the two matrices are compatible, otherwise an empty matrix
*/
Matrix Matrix::operator *(const Matrix & mat){
    if(this->colCount != mat.rowCount) {
        cout<<"Matrices are not compatible for multiplication";
        return Matrix(0,0);
    }
    Matrix product = Matrix(this->rowCount, mat.colCount);
    for(int i = 0; i<product.rowCount; i++) {
        for(int j= 0; j<product.colCount; j++) {
            int prod = 0;
            for(int k=0; k<this->colCount; k++) {
                prod += this->vals[i][k] * mat.vals[k][j];
            }
            product.vals[i][j] = prod;
        }
    }
    return product;
}
/* *
* Creates a new matrix transpose that is the transpose of
* the current matrix, where the values of the rows and 
* columns are swapped.
* @return The transpose matrix
*/
Matrix Matrix:: operator ~() const {
    Matrix transpose = Matrix(this->colCount, this->rowCount);
    for(int i = 0; i<transpose.rowCount; i++) {
        for(int j=0; j<transpose.colCount; j++) {
            transpose.vals[i][j] = this->vals[j][i];
        }
    }
    return transpose;
}
/* *
* check if two matrices are the same : two matrices are the same
* if they both contain the same element at the same location in
* each matrix .
* @param mat is another matrix
* @return true if both are the same , otherwise false .
*/
bool Matrix:: operator == (const Matrix & mat) {
    if(this->rowCount != mat.rowCount || this->colCount != mat.colCount) {
        return false;
    }
    for(int i = 0; i<mat.rowCount; i++) {
        for(int j= 0; j<mat.colCount; j++) {
            if(mat.vals[i][j] != this->vals[i][j]) return false;
        }
    }
    return true;
}
/* *
* Creates a string of the matrix values, where the elements in the 
* same row are seperated by a space, and the rows are seperated by
* a newline character.
* @return The string of matrix values.
*/
string Matrix::toStr(){
	string str="";
	if (this->vals==NULL) return "";
	for (int i=0;i<this->rowCount;i++) {
        for(int j=0; j<this->colCount; j++) {
            str.append(to_string(this->vals[i][j])).append(" ");
        }
		str.append("\n");
    }
	return str;
}
/* *
* Deletes the matrix, first deletes each row, and then
* deletes the array pointing to the rows
*/
Matrix::~Matrix() { 
    if(this->vals == NULL) return;
    for(int i = 0; i<this->rowCount; i++) {
        delete[] this->vals[i];
    }
    delete[] this->vals;
}