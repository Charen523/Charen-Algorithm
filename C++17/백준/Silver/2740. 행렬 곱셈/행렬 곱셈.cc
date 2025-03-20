#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<int>> Matrix;

// 행렬 크기를 2의 거듭제곱으로 맞추기 위해 패딩
int nextPowerOf2(int n) {
    return pow(2, ceil(log2(n)));
}

// 행렬 덧셈
Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// 행렬 뺄셈
Matrix subMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen 행렬 곱셈
Matrix strassenMultiply(Matrix A, Matrix B) {
    int n = A.size();

    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    Matrix M1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenMultiply(addMatrix(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subMatrix(B12, B22));
    Matrix M4 = strassenMultiply(A22, subMatrix(B21, B11));
    Matrix M5 = strassenMultiply(addMatrix(A11, A12), B22);
    Matrix M6 = strassenMultiply(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenMultiply(subMatrix(A12, A22), addMatrix(B21, B22));

    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

// 패딩하여 크기를 2의 거듭제곱으로 맞추는 함수
Matrix padMatrix(const Matrix& A, int newSize) {
    int oldSize = A.size();
    Matrix newMatrix(newSize, vector<int>(newSize, 0));
    for (int i = 0; i < oldSize; ++i)
        for (int j = 0; j < A[i].size(); ++j)
            newMatrix[i][j] = A[i][j];
    return newMatrix;
}

int main() {
    int N, M, K;
    cin >> N >> M;
    Matrix A(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    cin >> M >> K;
    Matrix B(M, vector<int>(K));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j)
            cin >> B[i][j];

    // 패딩을 위한 크기 계산
    int maxSize = max(N, max(M, K));
    int newSize = nextPowerOf2(maxSize);

    // 패딩 적용
    Matrix A_padded = padMatrix(A, newSize);
    Matrix B_padded = padMatrix(B, newSize);

    // Strassen 알고리즘 수행
    Matrix C_padded = strassenMultiply(A_padded, B_padded);

    // 결과 출력 (패딩 제거)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cout << C_padded[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}