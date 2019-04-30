#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_LINHA 300

#include "users.h"


void titulo(){
   FILE *f;
   char linha [SIZE_LINHA];
   f= fopen("titulo.txt","r");
   while(fgets(linha,sizeof(linha),f)!= NULL){
       printf("%s",linha);
     }
     fclose(f);
}


int main(){
    int numero_users = users_conta(),flag = 0,escolha;
    char login,username[20];
    User* lista_users = malloc((numero_users+1) * sizeof(User));
    User* user_login = malloc(sizeof(User));
    users_lista(lista_users, numero_users);
    titulo();
    printf("\n\n\n\t\t\t\t\t\t\t BEM VINDO AO PLANEAMENTO DE VIAGENS \n\n\n\n");
    printf("\t\t\t\tLogin - (insira l)                                                    Registo - (insira r)\n\n\n\n\n");
    scanf("%c",&login);

    while (login != 'r' && login != 'l'){
        printf("\t\t\tINVALIDO\n");
        fflush(stdin);
        scanf("%c",&login);
    }


    if(login=='r'){
        fflush(stdin);
        printf("\t\t\tInsira o nome de utilizador: \n\t\t\t>>>");
        fflush(stdin);
        scanf(" %[^\n]s",lista_users[numero_users].nome);
        while(user_existe(lista_users[numero_users].nome,lista_users,numero_users)){
            printf("\t\t\tUSERNAME JA UTILIZADO\n\t\t\t>>>");
            scanf(" %[^\n]s",lista_users[numero_users].nome);
        }
        printf("\t\t\tInsira a morada: \n\t\t\t>>>");
        fflush(stdin);
        scanf(" %[^\n]s",lista_users[numero_users].morada);
        printf("\t\t\tInsira o ano em que nasceu: \n\t\t\t>>>");
        fflush(stdin);
        scanf("%d",&lista_users[numero_users].ano);
        printf("\t\t\tInsira o mes do ano em que nasceu: \n\t\t\t>>>");
        scanf("%d",&lista_users[numero_users].mes);
        printf("\t\t\tInsira o dia do mes do ano em que nasceu: \n\t\t\t>>>");
        scanf("%d",&lista_users[numero_users].dia);
        printf("\t\t\tInsira o seu numero de telefone: \n\t\t\t>>>");
        scanf("%s",lista_users[numero_users].numero);
        user_login = lista_users+numero_users;
        numero_users++;
    }


    else if (login=='l'){

        while(flag == 0){
            printf("\t\t\tInsira o nome de utilizador: \n\t\t\t>>>");
            fflush(stdin);
            scanf(" %[^\n]s",username);
            user_login = user_existe(username, lista_users,numero_users);
            if(user_login != NULL){
                flag = 1;
                printf("LOGIN BEM SUCEDIDO\n");
            }
            if (flag == 0)
                printf("NOME NAO ENCONTRADO, POR FAVOR REGISTE-SE\n");
        }
    }

    system("@cls||clear\n");

    titulo();
    printf("\n\n\n\t\t\t\t\t\t\t                MENU \n\n\n\n");
    printf("\t\t\t\tListagem de Locais e Pontos de Interesse -------------------------------------> (insira 1)\n\n\n\n");
    printf("\t\t\t\tDefinir ou Alterar Preferencias ----------------------------------------------> (insira 2) \n\n\n\n");
    printf("\t\t\t\tOrdenar os Destinos por Popularidade -----------------------------------------> (insira 3)  \n\n\n\n");
    printf("\t\t\t\tGerar uma viagem -------------------------------------------------------------> (insira 4)\n\n\n\n");
    printf("\t\t\t\tDefinicoes de conta ----------------------------------------------------------> (insira 5)\n\n\n\n");
    scanf("%d",&escolha);

    switch(escolha){
        case 1:
            printf("abc");
            break;

        case 2:
            break;

        case 3:

            break;

        case 4:
            break;

        case 5:
            titulo();
            printf("\n\n\n\t\t\t\tUsername:  %s", user_login->nome);
            printf("\n\n\n\t\t\t\tMorada:  %s", user_login->morada);
            printf("\n\n\n\t\t\t\tData de nascimento:  %d-%d-%d", user_login->dia,user_login->mes,user_login->ano);
            printf("\n\n\n\t\t\t\t\t\t\t                MENU \n\n\n\n");
            printf("\t\t\t\tAlterar morada ---------------------------------------------------------------> (insira 1)\n\n\n\n");
            printf("\t\t\t\tAlterar data de nascimento ---------------------------------------------------> (insira 2) \n\n\n\n");
            printf("\t\t\t\tAlterar numero de telemovel --------------------------------------------------> (insira 3)  \n\n\n\n");
            printf("\t\t\t\tEliminar conta ---------------------------------------------------------------> (insira 4)\n\n\n\n");
            printf("ESCOLHA: ");
            scanf("%d",&escolha);
            switch(escolha){
            case 1:
                printf("\t\t\tInsira a nova morada: \n\t\t\t>>>");
                fflush(stdin);
                scanf(" %[^\n]s",user_login->morada);
                break;

            case 2:
                printf("\t\t\tInsira o ano em que nasceu: \n\t\t\t>>>");
                fflush(stdin);
                scanf("%d",&user_login->ano);
                printf("\t\t\tInsira o mes do ano em que nasceu: \n\t\t\t>>>");
                scanf("%d",&user_login->mes);
                printf("\t\t\tInsira o dia do mes do ano em que nasceu: \n\t\t\t>>>");
                scanf("%d",&user_login->dia);
                break;

            case 3:
                printf("\t\t\tInsira o seu numero de telefone: \n\t\t\t>>>");
                scanf("%s",user_login->numero);
                break;
            case 4:
                user_login->ano = -1;
                printf("Conta eliminada");
            }


    }
    /*printf("%s %s %d %d %d %s \n",lista_users[1].nome,lista_users[1].morada,lista_users[1].ano,lista_users[1].mes,lista_users[1].dia,lista_users[1].numero);
    */
    escreve_users(lista_users,numero_users);
    return 0;
}

