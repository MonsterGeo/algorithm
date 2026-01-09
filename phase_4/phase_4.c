
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
矩阵乘法（暴力计算）
伪代码：
SQUARE_MATRIX_MULTIPLY(A, B)

n  = A.rows
define C is n x n martix
for i  = 1 to n
    for j = 1 to n
        c_ij = 0
        for k = 1 to n
            c_ij = c_ij+a_ik*b_kj
return C

*/

#define MAX_SIZE 8
void squre_matrix(int A[][MAX_SIZE],int B[][MAX_SIZE],int C[][MAX_SIZE],int size)
{
    for(int i = 0; i< size; i++)
    {
        for(int j = 0; j< size ;j++)
        {
            //C[i][j] = 0;
            for(int k = 0; k < size;k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

//简单的分治算法
 

//首先需要矩阵加法



#define MAX_SIZE 8  // 定义矩阵最大规模（需为2的幂，可按需调整）

// 递归矩阵乘法：通过原矩阵坐标定位子块
void square_matrix_multiply_recursive(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE],
                                      int a_row, int a_col, int b_row, int b_col, int c_row, int c_col, int n) {
    if (n == 1) {
        // 单个元素相乘
        C[c_row][c_col] += A[a_row][a_col] * B[b_row][b_col];
        printf("\r\n");
        return;
    }

    int half = n / 2;

    // C11 = A11*B11 + A12*B21
    square_matrix_multiply_recursive(A, B, C, a_row, a_col, b_row, b_col, c_row, c_col, half);
    square_matrix_multiply_recursive(A, B, C, a_row, a_col+half, b_row+half, b_col, c_row, c_col, half);

    // C12 = A11*B12 + A12*B22
    square_matrix_multiply_recursive(A, B, C, a_row, a_col, b_row, b_col+half, c_row, c_col+half, half);
    square_matrix_multiply_recursive(A, B, C, a_row, a_col+half, b_row+half, b_col+half, c_row, c_col+half, half);

    // C21 = A21*B11 + A22*B21
    square_matrix_multiply_recursive(A, B, C, a_row+half, a_col, b_row, b_col, c_row+half, c_col, half);
    square_matrix_multiply_recursive(A, B, C, a_row+half, a_col+half, b_row+half, b_col, c_row+half, c_col, half);

    // C22 = A21*B12 + A22*B22
    square_matrix_multiply_recursive(A, B, C, a_row+half, a_col, b_row, b_col+half, c_row+half, c_col+half, half);
    square_matrix_multiply_recursive(A, B, C, a_row+half, a_col+half, b_row+half, b_col+half, c_row+half, c_col+half, half);
}

// 初始化矩阵（随机数填充）

// 打印矩阵
void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;  // 矩阵规模（需≤MAX_SIZE且为2的幂）
    int A[MAX_SIZE][MAX_SIZE] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int B[MAX_SIZE][MAX_SIZE] = {{13,14,15,16},{9,10,11,12},{5,6,7,8},{1,2,3,4}};
    int C[MAX_SIZE][MAX_SIZE] = {0};  // 结果矩阵初始化为0
    int D[MAX_SIZE][MAX_SIZE] = {0};

    // 执行递归矩阵乘法
    square_matrix_multiply_recursive(A, B, C, 0, 0, 0, 0, 0, 0, n);
    printf("\n矩阵C = A×B：\n");
    print_matrix(C, n);
    printf("\r\n");
    squre_matrix(A,B,D,n);
    print_matrix(D,n);
    return 0;
}