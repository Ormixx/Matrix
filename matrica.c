#include<stdio.h>
#include<stdlib.h>

typedef struct matrix {
    int rows;
    int cols;
    double **mat;
} matrix_t;
#define SCN_MAT "lf"
#define PRN_MAT "f"

matrix_t *mat_new(int r, int c){
    matrix_t *m = malloc (sizeof (struct matrix));
    m->rows = r;
    m->cols = c;
    m->mat = malloc(r*sizeof(*m->mat));
    for(int i=0;i < r;++i)
        m->mat[i] = calloc(c, sizeof(**m->mat));
    return m;
}

matrix_t *mat_multiply(matrix_t *m1, matrix_t *m2){
    if(m1->cols != m2->rows){
        printf("Cannot multiply matrices. Invalid dimensions.\n");
        return NULL;
    }

    matrix_t *result = mat_new(m1->rows, m2->cols);

    for(int i = 0; i < m1->rows; i++){
        for(int j = 0; j < m2->cols; j++){
            for(int k = 0; k < m1->cols; k++){
                result->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];
            }
        }
    }

    return result;
}