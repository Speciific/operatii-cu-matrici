#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float** alocaref(int lin, int col) {
    float** d;
    d = (float**)malloc(lin * sizeof(float*));
    for (int i = 0; i < lin; i++)
        d[i] = (float*)malloc(col * sizeof(float));
    return d;
}

float* alocare_memorief(int dim) {
    float* v;

    if ((v = (float*)malloc(dim * sizeof(float))) == NULL) {
        printf("\nMemorie insuficienta!");
        exit(0);
    }
    return v;
}

void citire(float** A, int l, int c) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++) {
            printf("A[%d][%d]=", i, j);
            scanf_s("%g", &A[i][j]);
        }
}

void afisare(float** A, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            printf("%g ", A[i][j]);
        printf("\n");
    }
}

void suma(float** A, float** B, float** C, int l, int c, int opt) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            if (opt == 1)
                C[i][j] = A[i][j] + B[i][j];
            else if (opt == 2)
                C[i][j] = A[i][j] - B[i][j];

    afisare(C, l, c);
}

void produs(float** A, float** B, float** C, int l, int c) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++) {
            C[i][j] = 0;
            for (int x = 0; x < l; x++)
                C[i][j] += A[i][x] * B[x][j];
        }
    afisare(C, l, c);
}

void min_max(float** A, int l, int c) {
    float min, max;
    min = A[0][0];
    max = A[0][0];

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++) {
            if (min > A[i][j])
                min = A[i][j];
            if (max < A[i][j])
                max = A[i][j];
        }

    printf("\nMinimul matricei este: %g\n", min);
    printf("Maximul matricei este: %g\n", max);
}

void urma(float** a, int l, int c) {
    float sum = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            if (i == j)
                sum += a[i][j];

    printf("\nUrma matricei este: %g", sum);
}

void produs_scalar(float** A, int l, int c, int scalar) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            A[i][j] = scalar * A[i][j];

    printf("\nNoua matrice este:\n\n");
    afisare(A, l, c);
}

void ridicarea_la_putere(float** A, int l, int c, int putere) {

    if (putere == 0) {
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                A[i][j] = (i == j);

        printf("\n"); afisare(A, l, c);
    }
    else if (putere == 1) {
        printf("\n"); afisare(A, l, c);
    }
    else {
        float** B, ** C;
        B = alocaref(l, c); C = alocaref(l, c);

        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                B[i][j] = A[i][j];

        for (int k = 1; k < putere; k++) {
            for (int i = 0; i < l; i++)
                for (int j = 0; j < c; j++) {
                    C[i][j] = 0;
                    for (int x = 0; x < l; x++)
                        C[i][j] += B[i][x] * A[x][j];
                }

            for (int i = 0; i < l; i++)
                for (int j = 0; j < c; j++)
                    B[i][j] = C[i][j];
        }
        printf("\n"); afisare(C, l, c);
    }
}

void afisare_vector(int dim, float* v) {
    printf("\nSpirala matricei este este:\n\n");
    for (int i = 0; i < dim; i++) {
        printf("%g ", *v);
        v++;
    }
}

int spirala(float** a, int l, int c, float* v) {

    int k = 0;
    int vi1 = 0, vj1 = 0, vi2 = 0, vj2 = c - 1, vi3 = l - 1, vj3 = c - 1, vi4 = l - 1, vj4 = 0;

    while (1) {

        if (c == 1) {
            for (int i = 0; i < l; i++) {
                v[k] = a[i][0];
                k++;
                if (k == l) return 0;
            }
        }

        for (int j = vj1; j <= vj2; j++) {
            v[k] = a[vi1][j];
            k++;
            if (k == l * c) return 0;
        }

        for (int i = vi2 + 1; i <= vi3; i++) {
            v[k] = a[i][vj2];
            k++;
            if (k == l * c) return 0;
        }

        for (int j = vj3 - 1; j >= vj4; j--) {
            v[k] = a[vi3][j];
            k++;
            if (k == l * c) return 0;
        }

        for (int i = vi4 - 1; i > vi1; i--) {
            v[k] = a[i][vj4];
            k++;
            if (k == l * c) return 0;
        }

        vi1++; vj1++;
        vi2++; vj2--;
        vi3--; vj3--;
        vi4--; vj4++;
    }

}

void transpusa(float** A, int l, int c) {

    float** tr;

    if (l >= c) {
        tr = alocaref(l, l);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
                if (i != j)
                    tr[i][j] = A[j][i];
                else
                    tr[i][j] = A[i][j];
        afisare(tr, c, l);
    }
    else {
        tr = alocaref(c, c);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                if (i != j)
                    tr[j][i] = A[i][j];
                else
                    tr[i][j] = A[i][j];
        afisare(tr, c, l);
    }

}

void submatrice(long int n, long int lin, long int col, float** a, float** b) {

    int i, j, c = -1, l = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != lin && j != col) {
                c++;
                if (c == n - 1) {
                    c = 0;
                    l++;
                }
                b[l][c] = a[i][j];
            }
}

float det(float** a, long int n) {

    long int i;
    float s = 0;
    float** b;

    b = alocaref(n, n);

    if (n == 1)
        s = a[0][0];

    if (n == 2) {
        s = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else {
        for (i = 0; i < n; i++) {
            submatrice(n, 0, i, a, b);
            s += a[0][i] * pow(-1, i + 2) * det(b, n - 1);
        }
    }
    return s;
}

void pscalar2(float** A, int n, float scalar) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = scalar * A[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%g ", A[i][j]);
        printf("\n");
    }
}

void inversa(float** a, int n) {

    float rez;
    float** tr, ** b;
    float** adj;

    rez = det(a, n);
    tr = alocaref(n, n);
    b = alocaref(n, n);
    adj = alocaref(n, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                tr[i][j] = a[j][i];
            else
                tr[i][j] = a[i][j];

    if (rez == 0)
        printf("\nMatricea nu este inversabila.\n");
    if (n == 2) {
        int l = 1, c = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = pow(-1, i + j) * tr[l][c];
                c--;
            }
            l--; c = 1;
        }
    }
    else if (n == 3) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                submatrice(n, i, j, tr, b);
                adj[i][j] = pow(-1, i + j) * det(b, n - 1);
            }
    }

    if (rez != 0) {
        printf("\nMatricea inversa este:\n");
        pscalar2(adj, n, 1 / rez);
    }

}

void simetria(float** a, int l, int c) {

    float** tr;

    if (l >= c) {
        tr = alocaref(l, l);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
                if (i != j)
                    tr[i][j] = a[j][i];
                else
                    tr[i][j] = a[i][j];
    }
    else {
        tr = alocaref(c, c);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                if (i != j)
                    tr[j][i] = a[i][j];
                else
                    tr[i][j] = a[i][j];
    }

    int ok = 0;

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] != tr[i][j])
                ok = 1;

    if (ok == 0)
        printf("\nMatricea este simetrica.\n");
    else if (ok == 1)
        printf("\nMatricea nu este simetrica.\n");
}
