#include <stdio.h>
#include <string.h>
#define MAX 50
char produto[10][50];
float valor[10];
int quant[10];
int escolha;
int i;
void cad();
void mostrar();
void editar();
void deletar();
int main(){
    cad();

do
{
    printf("\nO que quer fazer agora?\n");
    printf("[1] Cadastrar outro produto\n");
    printf("[2] Ver produtos cadastrados\n");
    printf("[3] Editar um produto \n");
    printf("[4] Deletar um produto\n");
    printf("[5] Sair\n");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        cad();
        break;
    case 2:
        mostrar();
        break;
    case 3:
        editar();
        break;
    case 4:
        deletar();
        break;
    case 5:
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n|-=-=-=-=-=-=OBRIGADO :)=-=-=-=-=-=-|\n");
        printf("\n-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;
        break;

    default:
    printf("Valor inválido!");
        break;
    }
} while (escolha != 5);

return 0;
}
static int linha;
void cad(){
  //i = 0;
  //char caractere;
    do
    {
        printf("Digite o nome do produto (Utilize_Underline_Como_Espaço): ");
        scanf("%s", produto[linha]);
        //gets(produto[linha]);
        //fgets(produto[linha],MAX,stdin);
        //fflush(stdin);
         /*do
        {
            caractere = getchar();
            produto[linha][i] = caractere;
            i++;
        } while (caractere != '\n');
        */
        printf("\nDigite o valor do produto (R$): ");
        scanf("%f", &valor[linha]);
        printf("\nDigite a quantidade que será comprada: ");
        scanf("%d", &quant[linha]);
        printf("Quer adicionar outro produto? (1 para sim e 0 para não) ");
        scanf("%d", &escolha);
        linha++;
    } while (escolha == 1);
    
}

void mostrar(){
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n|-=-=-=-=-=-=-=PRODUTOS=-=-=-=-=-=-=-|\n");
        printf("\n-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        for (i = 0; i <= 10; i++)
        {
            if (produto[i][0] == ' ' || strlen(produto[i]) == 0)
            {
                i = 11;
            }else{
                printf("\n+---------------------+\n");
                printf("|%s (%dx): R$ %.2f|", produto[i], quant[i], valor[i]);
                printf("\n+---------------------+\n");
            }
            
            
        }
        
}

void editar(){
    for (i = 0; i <= 10; i++)
    {
        if (produto[i][0] == ' ' || strlen(produto[i]) == 0)
        {
            i = 11;
        }
        else
        {
            printf("\n+-------[%d]----------+\n", i);
            printf("|%s (%dx): R$ %.2f|", produto[i], quant[i], valor[i]);
            printf("\n+---------------------+\n");
            printf("Quer editar este produto? (1 para sim | 0 para não) ");
            scanf("%d", &escolha);
            if (escolha == 1)
            {
                printf("Digite o nome do produto (Utilize_Underline_Como_Espaço): ");
                scanf("%s", produto[i]);
                printf("\nDigite o valor do produto (R$): ");
                scanf("%f", &valor[i]);
                printf("\nDigite a quantidade que será comprada: ");
                scanf("%d", &quant[i]);
                i = 11;
            }
        }
    }
}

void deletar(){
    //printf("Escolha o **Número** do produto a ser deletado");
    for (i = 0; i <= 10; i++)
    {
        if (produto[i][0] == ' ' || strlen(produto[i]) == 0)
        {
            i = 11;
        }
        else
        {
            printf("\n+-------[%d]----------+\n",i);
            printf("|%s (%dx): R$ %.2f|", produto[i], quant[i], valor[i]);
            printf("\n+---------------------+\n");
            printf("Quer deletar este produto? (1 para sim | 0 para não) ");
            scanf("%d", &escolha);
            if(escolha == 1){
                strcpy(produto[i], produto[i + 1]);    
                produto[i + 1][0] = ' ';
                quant [i+1] = 0;
                valor [i+1] = 0;
                linha = i+1;
                i = 11;
            }
            

        }
    }
}

