void mat_free(matrix_t *m){
    for(int i=0; i<m->rows; ++i){
        free(m->mat[i]);
    }
    free(m->mat);
    fre(m);
}