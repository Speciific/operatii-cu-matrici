#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Biblio.h"

int main() {

    printf("1. Suma a doua matrici.\n2. Scaderea a doua matrici.\n3. Minimul si maximul a unei matrice.\n4. Urma unei matrici.\n5. Inmultirea unei matrici cu un numar.\n6. Spirala unei matrici.\n7. Inmultirea a doua matrici.\n8. Ridicarea la putere a unei matrice.\n9. Transpusa unei matrici.\n10. Determinantul unei matrici.\n11. Inversa unei matrici.\n12. Simetria unei matrici.\nAlegeti ce optiune doriti sa efectuati: ");
    int optiune;
    scanf_s("%d", &optiune);

    while(optiune < 1 || optiune > 12){
        printf("Reintroduceti numarul optiunii dorite: ");
        scanf_s("%d", &optiune);
    }

    if((optiune > 3 || optiune < 12) && optiune != 7){
        float** A;
        int lA, cA;
        printf("Linii A: "); scanf_s("%d", &lA);
        printf("Coloane A: "); scanf_s("%d", &cA);
        A = alocaref(lA, cA);
        printf("\nIntroduceti elementele pentru matricea A:\n\n"); citire(A, lA, cA);
        printf("\nMatricea A este:\n\n"); afisare(A, lA, cA);
        if (optiune == 3) {
            min_max(A, lA, cA);
        }
        else if (optiune == 4) {
            urma(A, lA, cA);
        }
        else if (optiune == 5) {
            printf("\nIntroduceti numarul: ");
            int scalar; scanf_s("%d", &scalar);
            produs_scalar(A, lA, cA, scalar);
        }
        else if (optiune == 6) {
            float* v; v = NULL; v = alocare_memorief(lA * cA);
            spirala(A, lA, cA, v);
            afisare_vector(lA * cA, v);
            free(v);
        }
        else if (optiune == 8) {
            if (cA == lA) {
                int putere;
                printf("\nIntroduceti puterea la care va fi ridicata matricea: "); scanf_s("%d", &putere);
                ridicarea_la_putere(A, lA, cA, putere); 
            }
            else
                printf("\nRidicarea la putere nu se poate realiza.");
        }
        else if (optiune == 9) {
            printf("\nTranspusa matricei este:\n\n");
            transpusa(A, lA, cA);
        }
        else if (optiune == 10) {
            if (lA == cA)
                printf("\nDeterminantul matrici este: %g", det(A, lA));
            else
                printf("\nDeterminantul nu se poate calcula.");
        }
        else if (optiune == 11) {
            if (lA == cA)
                inversa(A, lA);
            else
                printf("\nMatricea nu are inversa.");
        }
        else if (optiune == 12) {
            if (lA == cA) 
                simetria(A, lA, cA);
            else
                printf("\nMatricea nu poate fi simetrica\n");
        }
        for (int i = 0; i < lA; i++)
            free(A[i]);
        free(A);
    }
    else if (optiune == 1 || optiune == 2 || optiune == 7) {
        float** A, ** B, ** C;
        int lA, cA, lB, cB;
        printf("Linii A: "); scanf_s("%d", &lA);
        printf("Coloane A: "); scanf_s("%d", &cA);
        printf("Linii B: "); scanf_s("%d", &lB);
        printf("Coloane B: "); scanf_s("%d", &cB);
        A = alocaref(lA, cA); B = alocaref(lB, cB); C = alocaref(lA, cA);
        printf("\nIntroduceti elementele pentru matricea A:\n\n"); citire(A, lA, cA); printf("\nIntroduceti elementele pentru matricea B:\n\n"); citire(B, lB, cB);
        printf("\nMatricea A este:\n\n"); afisare(A, lA, cA); printf("\nMatricea B este:\n\n"); afisare(B, lB, cB);
        if (optiune == 1) {
            if (lA == lB && cA == cB) {
                printf("\nSuma celor 2 matrici este:\n\n");
                suma(A, B, C, lA, cA, optiune);  
            }
            else
                printf("\nAdunarea celor doua matrici nu se poate realiza.");
        }
        else if (optiune == 2) {
            if (lA == lB && cA == cB) {
                printf("\nScaderea celor 2 matrici este:\n\n");
                suma(A, B, C, lA, cA, optiune);  
            }
            else
                printf("\nScaderea celor doua matrici nu se poate realiza.");
        }
        else if (optiune == 7) {
            if (cA == lB) {
                printf("\nInmultirea celor 2 matrici este:\n\n");
                produs(A, B, C, lA, cA); 
            }
            else
                printf("\nInmultirea celor doua matrici nu se poate realiza.");
        }
        for (int i = 0; i < lA; i++) {
            free(A[i]);
            free(C[i]);
        }
        for (int i = 0; i < lB; i++)
            free(B[i]);
        free(A); free(B); free(C);
    }
    _getch(); return 0;
}
