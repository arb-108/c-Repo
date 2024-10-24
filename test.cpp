#include <iostream>
#include <stdexcept>
#include <iomanip> 
using namespace std;
class Matrix {
private:
    int* data;      
    int rows;       
    int cols;       

    
    int index(int i, int j) const {
        return i * cols + j;
    }

public:
   
    Matrix(int r, int c, int initial = 0) : rows(r), cols(c) {
        if (rows < 0 || cols < 0) {
            cout<<"Number of rows and columns must be non-negative.";
        }
        if (rows == 0 || cols == 0) {
            data = NULL;
        } else {
            data = new int[rows * cols];
            for (int i = 0; i < rows * cols; ++i) {
                data[i] = initial;
            }
        }
    }

    
    ~Matrix() {
        delete[] data;
        data = NULL;
    }

    
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        if (rows == 0 || cols == 0) {
            data = NULL;
        } else {
            data = new int[rows * cols];
            for (int i = 0; i < rows * cols; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    
    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this; 
        }

        
        delete[] data;

        
        rows = other.rows;
        cols = other.cols;

        
        if (rows == 0 || cols == 0) {
           data = NULL;
        } else {
            data = new int[rows * cols];
            for (int i = 0; i < rows * cols; ++i) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    
    int get(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout<<"get: Indices are out of bounds.";
        }
        return data[index(i, j)];
    }

    
    void set(int i, int j, int v) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout<<"set: Indices are out of bounds.";
        }
        data[index(i, j)] = v;
    }

    
    void print() const {
        if (rows == 0 || cols == 0) {
            cout << "Empty Matrix\n";
            return;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << setw(5) << data[index(i, j)] << " ";
            }
            cout << "\n";
        }
    }

    
    void transpose() {
        if (rows == 0 || cols == 0) {
           
            return;
        }
        int* transposed = new int[cols * rows];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed[j * rows + i] = data[index(i, j)];
            }
        }
        delete[] data;
        data = transposed;
        swap(rows, cols);
    }

    
    void printSubMatrix(int r1, int r2, int c1, int c2) const {
        
        if (r1 < 0 || r2 >= rows || c1 < 0 || c2 >= cols || r1 > r2 || c1 > c2) {
            cout<<"Invalid submatrix indices.";
        }

        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                cout <<  data[index(i, j)] << " ";
            }
            cout << "\n";
        }
    }

    
    void makeEmpty(int n) {
        if (n <= 0) {
            
            return;
        }
        int limitRows = (n > rows) ? rows : n;
        int limitCols = (n > cols) ? cols : n;

        for (int i = 0; i < limitRows; ++i) {
            for (int j = 0; j < limitCols; ++j) {
                data[index(i, j)] = 0;
            }
        }
    }

    
    void add(const Matrix& first, const Matrix& second) {
        if (first.rows != second.rows || first.cols != second.cols) {
            cout<<"Matrices dimensions do not match.";
        }

       
        if (rows != first.rows || cols != first.cols) {
            delete[] data;
            rows = first.rows;
            cols = first.cols;
            if (rows == 0 || cols == 0) {
               // data = nullptr;
            } else {
                data = new int[rows * cols];
            }
        }

        
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = first.data[i] + second.data[i];
        }
    }

    
    int getRows() const {
        return rows;
    }

    
    int getCols() const {
        return cols;
    }
};


int main() {
    
    cout << "3x3 matrix:\n";
        Matrix A(3, 3, 5);
        A.print();

        cout << "\nSet(1,1) to 10:\n";
        A.set(1, 1, 10);
        A.print();

        cout << "\ngrt element at (1,1): " << A.get(1, 1) << "\n";

        cout << "\nTransposing the matrix:\n";
        A.transpose();
        A.print();

        cout << "\nCreating another 3x3 matrix initialized to 2:\n";
        Matrix B(3, 3, 2);
        B.print();

        cout << "\nAdding Matrix A and  B to C:\n";
        Matrix C(0, 0); 
        C.add(A, B);
        C.print();

        cout << "\nPrinting a submatrix of C from rows 0-1 and columns 0-1:\n";
        C.printSubMatrix(0, 1, 0, 1);

        cout << "\nMaking the first 2 rows and columns of C empty (set to zero):\n";
        C.makeEmpty(2);
        C.print();

        cout << "\nAttempting to access an out-of-bounds element:\n";
        cout << A.get(5, 5);
        
        cout << "\nCreating a matrix with zero rows and columns:\n";
        Matrix D(0, 0);
        D.print();

        cout << "\nTransposing a non-square matrix (2x3):\n";
        Matrix E(2, 3, 1);
        E.set(0, 2, 5);
        E.print();
        E.transpose();
        E.print();

        cout << "\nAdding matrices with mismatched dimensions:\n";
        Matrix F(2, 2, 3);
        Matrix G(3, 3, 4);
        Matrix H(0, 0);
        H.add(F, G);
        cout << "\nCreating a 2x2 matrix initialized to 7:\n";
        Matrix I(2, 2, 7);
        I.print();

        cout << "\nMaking the first 5 rows and columns empty (should limit to 2):\n";
        I.makeEmpty(5);
        I.print();
    return 0;
}
