#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col, i, j;
    int num_nonzero;
    int** matrix, ** transpose;

    // 1. ��� ���� ũ��, 0�� �ƴ� ���� ���� �Է�
    printf("����� �� �� �� �� �Է�: ");
    scanf("%d %d", &row, &col);
    printf("��Ŀ� 0�� �ƴ� ������ ���� �Է�: ");
    scanf("%d", &num_nonzero);

    // 2. 0�� �ƴ� ���� ���ڸ�ŭ ��, ��, ���� ���� ���ʴ�� �Է�
    matrix = (int**)malloc(row * sizeof(int*));
    for (i = 0; i < row; i++) {
        matrix[i] = (int*)calloc(col, sizeof(int));
    }

    for (i = 0; i < num_nonzero; i++) {
        int r, c, value;
        printf("����� ��, �� �� �� �Է� %d: ", i + 1);
        scanf("%d %d %d", &r, &c, &value);
        matrix[r - 1][c - 1] = value;
    }

    // 3. �Է� ���� ����� ��ġ ����� ����Ͽ� ���
    transpose = (int**)malloc(col * sizeof(int*));
    for (i = 0; i < col; i++) {
        transpose[i] = (int*)calloc(row, sizeof(int));
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("����� ������ ����: \n");
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // 4. �Ҵ�� ���� �޸� ����
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
