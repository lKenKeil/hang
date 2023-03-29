#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col, i, j;
    int num_nonzero;
    int** matrix, ** transpose;

    // 1. 행과 열의 크기, 0이 아닌 항의 숫자 입력
    printf("행렬의 행 및 열 수 입력: ");
    scanf("%d %d", &row, &col);
    printf("행렬에 0이 아닌 원소의 수를 입력: ");
    scanf("%d", &num_nonzero);

    // 2. 0이 아닌 항의 숫자만큼 행, 열, 값의 쌍을 차례대로 입력
    matrix = (int**)malloc(row * sizeof(int*));
    for (i = 0; i < row; i++) {
        matrix[i] = (int*)calloc(col, sizeof(int));
    }

    for (i = 0; i < num_nonzero; i++) {
        int r, c, value;
        printf("요소의 행, 열 및 값 입력 %d: ", i + 1);
        scanf("%d %d %d", &r, &c, &value);
        matrix[r - 1][c - 1] = value;
    }

    // 3. 입력 받은 행렬의 전치 행렬을 계산하여 출력
    transpose = (int**)malloc(col * sizeof(int*));
    for (i = 0; i < col; i++) {
        transpose[i] = (int*)calloc(row, sizeof(int));
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("행렬은 다음과 같다: \n");
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // 4. 할당된 동적 메모리 해제
    for (i = 0; i < row; i++) {
        free(matrix[i]);
    }
    for (i = 0; i < col; i++) {
        free(transpose[i]);
    }
    free(matrix);
    free(transpose);

    return 0;
}
