#include <stdio.h>
#include <stdlib.h>
void imprime(int *n){
    int i,j,k,tot;
    tot = 0;
    char saida[3][3] = {' '};
    for(i=0;i<3;i++) //verificar onde é O e onde é X
        for(j=0;j<3;j++){
            if(n[tot]==1)
                saida[i][j] ='X';
            else if(n[tot]==-1)
                saida[i][j] ='O';
            tot++;
        }
    printf("\t %c | %c | %c \n", saida[0][0],saida[0][1],saida[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", saida[1][0],saida[1][1],saida[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n\n", saida[2][0],saida[2][1],saida[2][2]);
}
int vencedor(int *n){
    int i,j, jogo[3][3],k;
    k = 0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
          jogo[i][j] = n[k];
          k++;
    }
    k = 1;
    if((jogo[0][0]==1 && jogo[0][1]==1 && jogo[0][2]==1) || (jogo[1][0]==1 && jogo[1][1]==1 && jogo[1][2]==1) || (jogo[2][0]==1 && jogo[2][1]==1 && jogo[2][2]==1))
        return 2;
    else if((jogo[0][0]==1 && jogo[1][0]==1 && jogo[2][0]==1) || (jogo[0][1]==1 && jogo[1][1]==1 && jogo[2][1]==1) || (jogo[0][2]==1 && jogo[1][2]==1 && jogo[2][2]==1))
        return 2;
    else if((jogo[0][0]==1 && jogo[1][1]==1 && jogo[2][2]==1) || (jogo[0][2]==1 && jogo[1][1]==1 && jogo[2][0]==1))
        return 2;
    if((jogo[0][0]==-1 && jogo[0][1]==-1 && jogo[0][2]==-1) || (jogo[1][0]==-1 && jogo[1][1]==-1 && jogo[1][2]==-1) || (jogo[2][0]==-1 && jogo[2][1]==-1 && jogo[2][2]==-1))
        return 1;
    else if((jogo[0][0]==-1 && jogo[1][0]==-1 && jogo[2][0]==-1) || (jogo[0][1]==-1 && jogo[1][1]==-1 && jogo[2][1]==-1) || (jogo[0][2]==-1 && jogo[1][2]==-1 && jogo[2][2]==-1))
        return 1;
    else if((jogo[0][0]==-1 && jogo[1][1]==-1 && jogo[2][2]==-1) || (jogo[0][2]==-1 && jogo[1][1]==-1 && jogo[2][0]==-1))
        return 1;
    for(i=0;i<3;i++) //Caso dê velha
        for(j=0;j<3;j++){
            if(jogo[i][j]==0){
                k = 0;
                break;
            }
        }
    if(k==1)
        return 3;
    else
        return 0;
}
void opcoes(){
    char saida[3][3] = {'1','2','3','4','5','6','7','8','9'};
    printf("\t %c | %c | %c \n", saida[0][0],saida[0][1],saida[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", saida[1][0],saida[1][1],saida[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n\n", saida[2][0],saida[2][1],saida[2][2]);
}
int main(){
    char repeat = 's';
    while(1){
        int vitoria,tot,n,jogadas[9] = {0};
        char jogador1[20],jogador2[20];
        tot = 0;
        imprime(jogadas);
        while (1){
            opcoes();
            if (tot==0){
                printf("Insira o nome do jogador1: ");
                scanf("%s", jogador1);
                printf("Insira o nome do joagdor2: ");
                scanf("%s", jogador2);
            }
            printf("insira um valor: ");
            while(1){
                scanf("%d", &n);
                if(tot%2==0 && n<=9 && n>0 && jogadas[n-1]==0){
                    jogadas[n-1] = -1;
                    break;
                }
                else if(tot%2==1 && n<=9 && n>0 && jogadas[n-1]==0){
                    jogadas[n-1] = 1;
                    break;
                }
                else{
                    printf("JOGADA INVAlIDA\n");
                    printf("Escolha outro valor: ");
                }
            }
            system("cls");
            imprime(jogadas);
            if(vencedor(jogadas)!=0){
                vitoria = vencedor(jogadas);
                break;
            }
            tot++;
        }
        if (vitoria==1)
            printf("%s venceu, parabens!\n", jogador1);
        else if(vitoria==2)
            printf("%s venceu, parabens!\n", jogador2);
        else
            printf("Empate!\n");
        fflush(stdin);
        printf("Quer continuar?[S/N]");
        scanf("%c", &repeat);
        if(repeat=='n' || repeat=='N')
            break;
        system("cls");
        }
    system("pause");
    return 0;
}
