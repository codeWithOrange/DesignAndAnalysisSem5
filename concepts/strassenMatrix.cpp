#include<iostream> 
#include<vector>
using namespace std;
using Matrix = vector<vector<int>>;
Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix subtractMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

Matrix normalMultiplication(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }

        }
    }
    return C;
}

Matrix strassen(const Matrix& A, const Matrix& B) {

    int n = A.size();

    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    Matrix A11(k, vector<int>(k));
    Matrix A12(k, vector<int>(k));
    Matrix A21(k, vector<int>(k));
    Matrix A22(k, vector<int>(k));

    Matrix B11(k, vector<int>(k));
    Matrix B12(k, vector<int>(k));
    Matrix B21(k, vector<int>(k));
    Matrix B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    Matrix M1 = strassen(
        addMatrix(A11, A22),
        addMatrix(B11, B22)
    );

    Matrix M2 = strassen(
        addMatrix(A21, A22),
        B11
    );

    Matrix M3 = strassen(
        A11,
        subtractMatrix(B12, B22)
    );

    Matrix M4 = strassen(
        A22,
        subtractMatrix(B21, B11)
    );

    Matrix M5 = strassen(
        addMatrix(A11, A12),
        B22
    );

    Matrix M6 = strassen(
        subtractMatrix(A21, A11),
        addMatrix(B11, B12)
    );

    Matrix M7 = strassen(
        subtractMatrix(A12, A22),
        addMatrix(B21, B22)
    );

    Matrix C11 = addMatrix(
        subtractMatrix(
            addMatrix(M1, M4),
            M5
        ),
        M7
    );

    Matrix C12 = addMatrix(M3, M5);

    Matrix C21 = addMatrix(M2, M4);

    Matrix C22 = addMatrix(
        subtractMatrix(
            addMatrix(M1, M3),
            M2
        ),
        M6
    );

    Matrix C(n, vector<int>(n));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];

        }
    }

    return C;
}
void printMatrix(const Matrix&A){
    int n=A.size(); 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<" "; 
        }
        cout<<endl; 
    }
}

int main(){
    Matrix A={
    {1,2,3},
    {2,3,4},
    {4,3,4}
    }; 
    Matrix B={
    {2,3},
    {4,5},
    {3,3}
    }; 

    Matrix result=strassen(A,B); 
    printMatrix(result); 
   

    Matrix  result1=normalMultiplication(A,B); 
    printMatrix(result1); 
    

    return 0; 
}
