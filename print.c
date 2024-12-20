

void print_key(int k[K][K]) {
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
        if (i > 0 && j == 0) printf("\n");
        switch (k[i][j]) {
            case 0 : rgb(255,255,255);printf("O ");break;
            case 1 : rgb(255,255,255);printf("| ");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }
    }
    printf("\n");
}
void print_calc(int k[K][X]) {
    for (int i = 0; i < K; i++) for (int j = 0; j < X; j++) {
        if (i > 0 && j == 0) printf("\n");
        switch (k[i][j]) {
            case 0 : rgb(255,255,255);printf("O");break;
            case 1 : rgb(255,255,255);printf("|");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }
    }
    printf("\n");
    printf("\n");
}

void print_v(int* v, int L) {
    for (int i = 0; i < L; i++) {
        if (i %X == 0 && i > 0) printf(" ");
        switch (v[i]) {
            case 0 : rgb(255,255,255);printf("O");break;
            case 1 : rgb(255,255,255);printf("|");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }
        

    }
}
void print_bit(int b) {
        switch (b) {
            case 0 : rgb(255,255,255);printf("O");break;
            case 1 : rgb(255,255,255);printf("|");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }
        printf("\n");
}
