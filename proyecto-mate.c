#include <stdio.h>

#define SIZE 5

void gaussJordan(float matrix[SIZE][SIZE + 1]) {
    int i, j, k; // Declarar todas las variables fuera de los bucles
    float diagElement, factor;

    for (i = 0; i < SIZE; i++) {
        // Escalamiento
        diagElement = matrix[i][i];
        for (j = 0; j < SIZE + 1; j++) {
            matrix[i][j] /= diagElement;
        }

        // Eliminación hacia arriba y hacia abajo
        for (k = 0; k < SIZE; k++) {
            if (k != i) {
                factor = matrix[k][i];
                for (j = 0; j < SIZE + 1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

void printMatrix(float matrix[SIZE][SIZE + 1]) {
    int i, j; // Declarar variables fuera del bucle
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE + 1; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matrix[SIZE][SIZE + 1];
    int i, j; // Declarar variables fuera del bucle

    printf("Ingrese la matriz aumentada del sistema 5x5:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE + 1; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("\nMatriz aumentada inicial:\n");
    printMatrix(matrix);

    gaussJordan(matrix);

    printf("\nMatriz reducida:\n");
    printMatrix(matrix);

    printf("\nSoluciones:\n");
    for (i = 0; i < SIZE; i++) {
        printf("x%d = %.3f\n", i + 1, matrix[i][SIZE]);
    }

    return 0;
}

