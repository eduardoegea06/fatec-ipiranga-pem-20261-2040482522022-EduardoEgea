#include <stdio.h>

int main() {

    int idProduto[10];
    int total = 0;
    int opcao;
    int id;
    int i;

    do {

        printf("\n1 - Inclusao\n");
        printf("2 - Consulta\n");
        printf("3 - Alteracao\n");
        printf("4 - Exclusao\n");
        printf("5 - Listar todos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {

            if(total < 10){
                printf("Digite o id do produto: ");
                scanf("%d", &idProduto[total]);
                total++;
            } else {
                printf("Lista cheia\n");
            }

        }

        else if(opcao == 2) {

            printf("Digite o id para consultar: ");
            scanf("%d", &id);

            for(i = 0; i < total; i++){
                if(idProduto[i] == id){
                    printf("Encontrado na posicao %d\n", i);
                }
            }

        }

        else if(opcao == 3) {

            printf("Digite o id para alterar: ");
            scanf("%d", &id);

            for(i = 0; i < total; i++){
                if(idProduto[i] == id){
                    printf("Digite o novo id: ");
                    scanf("%d", &idProduto[i]);
                }
            }

        }

        else if(opcao == 4) {

            printf("Digite o id para excluir: ");
            scanf("%d", &id);

            for(i = 0; i < total; i++){
                if(idProduto[i] == id){
                    for(int j = i; j < total-1; j++){
                        idProduto[j] = idProduto[j+1];
                    }
                    total--;
                    printf("Produto excluido\n");
                    break;
                }
            }

        }

        else if(opcao == 5) {

            printf("Lista de produtos:\n");
            for(i = 0; i < total; i++){
                printf("%d\n", idProduto[i]);
            }

        }

    } while(opcao != 0);

    return 0;
}
