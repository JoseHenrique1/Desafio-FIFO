#include <stdio.h>

void fifo_substituicao_paginas(int paginas[], int quantidade_paginas, int quantidade_molduras) {
    int molduras[quantidade_molduras]; 
    int falhas_pagina = 0;  
    int indice_moldura = 0;  
    int i, j, presente;

    for (i = 0; i < quantidade_molduras; i++) {
        molduras[i] = -1;
    }

    
    for (i = 0; i < quantidade_paginas; i++) {
        presente = 0; 

        
        for (j = 0; j < quantidade_molduras; j++) {
            if (molduras[j] == paginas[i]) {
                presente = 1;
                break;
            }
        }

        
        if (!presente) {
            molduras[indice_moldura] = paginas[i];  
            indice_moldura = (indice_moldura + 1) % quantidade_molduras; 
            falhas_pagina++;
        }
    }

    
    printf("\nTotal de falhas de página: %d\n", falhas_pagina);
    printf("Estado final da memória: [");
    for (i = 0; i < quantidade_molduras; i++) {
        if (molduras[i] != -1) {
            printf("%d", molduras[i]);
        } else {
            printf("_");
        }
        if (i < quantidade_molduras - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int paginas1[] = {1, 3, 0, 3, 5, 6, 3, 1, 6, 1, 2};
    int quantidade_paginas1 = sizeof(paginas1) / sizeof(paginas1[0]);
    int molduras1 = 3;
    printf("Exemplo 1:\n");
    fifo_substituicao_paginas(paginas1, quantidade_paginas1, molduras1);


    int paginas2[] = {5, 6, 7, 8, 5, 6, 8, 9, 7, 6};
    int quantidade_paginas2 = sizeof(paginas2) / sizeof(paginas2[0]);
    int molduras2 = 4;
    printf("\nExemplo 2:\n");
    fifo_substituicao_paginas(paginas2, quantidade_paginas2, molduras2);


    int paginas3[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int quantidade_paginas3 = sizeof(paginas3) / sizeof(paginas3[0]);
    int molduras3 = 3;
    printf("Exemplo 3:\n");
    fifo_substituicao_paginas(paginas3, quantidade_paginas3, molduras3);


    int paginas4[] = {9, 3, 4, 2, 5, 6, 4, 9, 7, 1, 3};
    int quantidade_paginas4 = sizeof(paginas4) / sizeof(paginas4[0]);
    int molduras4 = 4;
    printf("\nExemplo 4:\n");
    fifo_substituicao_paginas(paginas4, quantidade_paginas4, molduras4);


    int paginas5[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int quantidade_paginas5 = sizeof(paginas5) / sizeof(paginas5[0]);
    int molduras5 = 3;
    printf("Exemplo 5:\n");
    fifo_substituicao_paginas(paginas5, quantidade_paginas5, molduras5);


    int paginas6[] = {8, 5, 7, 5, 4, 6, 8, 6, 1, 4, 8, 7};
    int quantidade_paginas6 = sizeof(paginas6) / sizeof(paginas6[0]);
    int molduras6 = 2;
    printf("\nExemplo 6:\n");
    fifo_substituicao_paginas(paginas6, quantidade_paginas6, molduras6);

    return 0;
}
