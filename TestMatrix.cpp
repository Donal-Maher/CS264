#include <iostream>
#include "Matrix.h"
using namespace MatrixSpace;
int main() {
    cout<<"----m x n constructor test cases----"<<endl;
    // Test cases for m x n matrix filled with 0s
    Matrix m1(1,1);
    cout<<"1 x 1 matrix"<<endl<< m1.toStr()<<endl;
    Matrix m2(3,5);
    cout<<"3 x 5 matrix" << endl << m2.toStr()<<endl; 
    

    cout<<"----Copy constructor test case----"<<endl;
    //Test case for copy function
    Matrix mCopy(m2);
    cout<<"m2: " << endl << m2.toStr() << endl;
    cout<<"mCopy: " << endl << mCopy.toStr() << endl;
    mCopy.set(0,0,7);
    cout<<"set first element of mCopy = 7" << endl;
    cout<<"m2: " << endl << m2.toStr() << endl;
    cout<<"mCopy: " << endl << mCopy.toStr() << endl;

    cout<<"----Array constructor test case----"<<endl;
    //Test case for m x n matric using data from array
    int m = 3;
    int n = 2;
    int** array1 = new int*[m];
    for(int i = 0; i<m; i++) {
        array1[i] = new int[n];
    }
    int count = 1;
    for(int i = 0; i<m; i++) {
        for(int j =0; j<n; j++) {
            array1[i][j] = count++;
        }
    }
    Matrix m3(array1, m, n);
    cout<<"m3:" << endl << m3.toStr()<<endl;

    cout<<"----Row count test case----"<<endl;
    //Test case for row count getter
    cout<<"m3 rows: "<<m3.rows()<<endl;

    cout<<"----Column count test case----"<<endl;
    //Test case for column count getter
    cout<<"m3 columns: "<<m3.columns()<<endl;

    cout<<"----Get test cases----"<<endl;
    //Test case for getting value of specific element
    cout<<"m3 val in 0, 0: "<<m3.get(0,0)<<endl;
    cout<<"m3 val in 1, 1: "<<m3.get(1,1)<<endl;
    cout<<"m3 val in 2, 1: "<<m3.get(2,1)<<endl;
    cout<<"m3 val in 5, 5: "<<m3.get(5,5)<<endl;

    cout<<"----Set test cases----"<<endl;
    //Test case for setting value of specific element
    cout<<"setting 0, 0 in m3 = 0" << endl;
    m3.set(0,0,0);
    cout<<"setting 2, 1 in m3 = -54" << endl;
    m3.set(2,1, -54);
    cout<<"setting 0, 10 in m3 = 9" << endl;
    m3.set(0,10, 9);    
    cout<<endl<<"m3: " << endl << m3.toStr() << endl;

    //Test cases for matrix operation -
    cout<<"----Addition test cases----"<<endl;
    //Test case 1 incompatible matrices
    cout<<endl<<"m1: " << endl << m1.toStr();
    cout<<"m3: " << endl << m3.toStr();
    cout<<"m1 + m3: "<<endl;
    Matrix sum1 = m1 + m3;
    cout<< sum1.toStr() << endl;
    //Test case 2 compatible matrices
    Matrix m4(3,2);
    for(int i = 0; i<3;i++) {
        for(int j = 0; j<2; j++) {
            m4.set(i,j,2);
        }
    }
    cout<<endl<<"m3: " << endl << m3.toStr();
    cout<<"m4: " << endl << m4.toStr();
    cout<<"m3 + m4: "<<endl;
    Matrix sum2 = m3 + m4;
    cout<<sum2.toStr()<<endl;
    //Test case 3 1 x 1 matrices
    Matrix m5(1,1);
    m5.set(0,0,6);
    cout<<endl<<"m1: " << endl << m1.toStr();
    cout<<"m5: " << endl << m5.toStr();
    cout<<"m1 + m5: "<<endl;
    Matrix sum3 = m1 + m5;
    cout<<sum3.toStr()<<endl;
    
    //Test cases for matrix operation -
    cout<<"----Subtraction test cases----"<<endl;
    //Test case 1
    cout<<endl<<"m3: " << endl << m3.toStr();
    cout<<"m4: " << endl << m4.toStr();
    cout<<"m3 - m4: "<<endl;
    Matrix subtract1 = m3 - m4;
    cout<<subtract1.toStr()<<endl;
    //Test case 2 m3 - m3
    cout<<"m3: " << endl << m3.toStr();
    cout<<"m3 - m3: "<<endl;
    Matrix subtract2 = m3 - m3;
    cout<<subtract2.toStr()<<endl;

    //Test cases for matrix operation *
    cout<<"----Multiplication test cases----"<<endl;
    //Test case 1
    Matrix m6(1,3);
    for(int i = 0; i<m6.columns(); i++) {
        m6.set(0,i,3);
    }
    cout<<endl<<"m6: " << endl << m6.toStr();
    cout<<"m3: " << endl << m3.toStr();
    cout<<"m6 * m3: "<<endl;
    Matrix product1 = m6 * m3;
    cout<<product1.toStr();
    //Test case 2
    cout<<endl<<"m3: " << endl << m3.toStr();
    cout<<"m6: " << endl << m6.toStr();
    cout<<"m3 * m6: "<<endl;
    Matrix product2 = m3 * m6;
    cout<<product2.toStr()<<endl;
    //Test case 3
    Matrix m7(2,4);
    count = 2;
    for(int i = 0; i< m7.rows(); i++) {
        for(int j = 0; j<m7.columns(); j++) {
            count = count*2;
            m7.set(i,j,count);
        }
    }
    cout<<endl<<"m3: " << endl << m3.toStr();
    cout<<"m7: " << endl << m7.toStr();
    cout<<"m3 * m7: "<<endl;
    Matrix product3 = m3 * m7;
    cout<<product3.toStr();

    //Test cases for matrix operation ~
    cout<<"----Transpose test cases----"<<endl;
    //Test case 1
    Matrix m3T = ~m3;
    cout<<"m3:" << endl << m3.toStr();
    cout<<"~m3:" << endl << m3T.toStr() <<endl;
    //Test case 2
    Matrix m6T = ~m6;
    cout<<"m6:" << endl << m6.toStr();
    cout<<"~m6:" << endl << m6T.toStr()<<endl;

     //Test cases for matrix operation ==
    cout<<"----== test cases----"<<endl;
    //Test case 1 (not equal)
    cout<<"m6:" << endl << m6.toStr();
    cout<<"~m6:" << endl << m6T.toStr();
    bool b = m6 == m3T;
    cout<<"m6 == ~m6: " << b << endl; 
    b = m3 == m6;
    //Test case 2 (equal)
    Matrix m8(2,2);
    m8.set(0,0,9);
    m8.set(1,1,27);
    cout<<endl<<"m8:" << endl << m8.toStr();
    Matrix m9(2,2);
    m9.set(0,0,9);
    m9.set(1,1,27);
    cout<<"m9:" << endl << m9.toStr();
    b = m8 == m9;
    cout<<"m8 == m9: " << b << endl;   
    //Test case 3
    cout<<endl<<"m4:" << endl << m4.toStr();
    b= m4 == m4;
    cout<<"m4 == m4: " << b << endl;
    //Delete array
    for(int i = 0; i< m; i++) {
        delete [] array1[i];
    }
    delete[] array1;
}