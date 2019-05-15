#include "header.h"



/*Luser le_users(Llocais locais, int* n){
    Luser lista;
    Luser newuser;
    int i,k;
    char temp[HUGE_SIZE], local1[SIZE],local2[SIZE],local3[SIZE],pdi[HUGE_SIZE];

    FILE* f;
    f = fopen("pessoas.txt","r");
    fflush(stdin);
    fgets(temp,sizeof(temp),f);
    sscanf(temp,"%d\n",n);
    printf("%d",*n);
    for (i = 0; i<*n; i++){
        printf("%d\n",*n);
        printf("aaa");
        newuser = (Luser)malloc(sizeof(User));
        newuser->next = NULL;
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        printf("%s",temp);
        sscanf(temp,"%[^|]|%[^|]|%d|%d|%d|%[^|]|\n",newuser->nome,newuser->morada,&(newuser->ano),&(newuser->mes),&(newuser->dia),newuser->numero);
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%[^|]|\n",local1,local2,local3);
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%d\n",&(newuser->npref));
        newuser->pref = NULL;
        for(k=0;k<newuser->npref;k++){
            fflush(stdin);
            fgets(temp,sizeof(temp),f);
            sscanf(temp,"%[^|]|\n",pdi);
            newuser->pref = le_pdi_pref(newuser->pref,pdi,locais);
        }
        newuser->local1 = procura_lista(locais,local1);
        newuser->local2 = procura_lista(locais,local2);
        newuser->local3 = procura_lista(locais,local3);
        if (newuser->local1 != NULL)
            adiciona_pop(newuser->local1);
        if (newuser->local2 != NULL)
            adiciona_pop(newuser->local2);        if (newuser->local3 != NULL)
            adiciona_pop(newuser->local3);

        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|\n",pdi);
        newuser->hot = procura_pdi(locais,pdi);
        if(newuser->hot != NULL)
            newuser->hot->n_hot++;
        fflush(stdin);
        lista = insere_user(newuser,lista);
        printf("%s",newuser->nome);
    }
    fclose(f);
    return lista;

}*/

Luser le_users(Llocais locais, int* n){
    int i,k;
    FILE* f;
    char temp[HUGE_SIZE],local1[SIZE],local2[SIZE],local3[SIZE],pdi[SIZE];
    Luser novouser = NULL,lista = NULL;
    f = fopen("pessoas.txt","r");
    fflush(stdin);
    fgets(temp,sizeof(temp),f);
    sscanf(temp,"%d\n",n);
    for(i = 0;i<*n;i++){
        novouser = (Luser)malloc(sizeof(User));
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%d|%d|%d|%[^|]|\n",novouser->nome,novouser->morada,&(novouser->ano),&(novouser->mes),&(novouser->dia),novouser->numero);

        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%[^|]|\n",local1,local2,local3);
        novouser->local1 = procura_lista(locais,local1);
        novouser->local2 = procura_lista(locais,local2);
        novouser->local3 = procura_lista(locais,local3);
        if (novouser->local1 != NULL)
            adiciona_pop(novouser->local1);
        if (novouser->local2 != NULL)
            adiciona_pop(novouser->local2);        if (novouser->local3 != NULL)
            adiciona_pop(novouser->local3);

        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%d\n",&(novouser->npref));
        for(k=0;k<(novouser->npref);k++){
            fflush(stdin);
            fgets(temp,sizeof(temp),f);
            sscanf(temp,"%[^|]|\n",pdi);
            novouser->pref = le_pdi_pref(novouser->pref,pdi,locais);
        }
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|\n",pdi);

        novouser->hot = procura_pdi(locais,pdi);
        if(novouser->hot != NULL)
            novouser->hot->n_hot++;

        lista = insere_user(novouser,lista);
    }
    return lista;
}


Luser insere_user(Luser newuser, Luser lista){
    Luser ant = NULL;
    Luser temp = lista;
    while(temp){
        ant = temp;
        temp = temp->next;
    }
    if(ant == NULL)
        lista = newuser;
    else{
        ant->next = newuser;
    }
    return lista;

}

Luser user_existe(char* username, Luser lista){
    Luser temp;
    temp = lista;
    while(temp){
        if (strcmp(username,temp->nome)==0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void escreve_users(Luser lista,int n){
    FILE *f;
    Lpref temp;
    Luser aux = lista;

    f = fopen("pessoas.txt","w");
    fprintf(f,"%d\n",users_validos(lista));
    while(aux){
        if (aux->ano != -1){
            fprintf(f,"%s|%s|%d|%d|%d|%s|\n",aux->nome,aux->morada,aux->ano,aux->mes,aux->dia,aux->numero);
            fprintf(f,"%s|%s|%s|\n",aux->local1->nome,aux->local2->nome,aux->local3->nome);
            fprintf(f,"%d\n",aux->npref);
            temp = aux->pref;
            while(temp){
        printf("bate");
                fprintf(f,"%s|\n", temp->pdi->nome);
                temp = temp->next;
            }
            fprintf(f,"%s|\n", aux->hot->nome);
        }
        aux = aux->next;
    }
    /*for(i=0;i<n;i++){
        if (lista[i].ano != -1){
            fprintf(f,"%s|%s|%d|%d|%d|%s|\n",lista[i].nome,lista[i].morada,lista[i].ano,lista[i].mes,lista[i].dia,lista[i].numero);
            fprintf(f,"%s|%s|%s|\n",lista[i].local1->nome,lista[i].local2->nome,lista[i].local3->nome);
            fprintf(f,"%d\n",lista[i].npref);
            temp = lista[i].pref;
            while(temp){
                fprintf(f,"%s|\n", temp->pdi->nome);
                temp = temp->next;
            }
            fprintf(f,"%s|\n", lista[i].hot->nome);
        }
    }*/
    fclose(f);
}

int users_validos(Luser lista){
    int contador=0;
    Luser temp = lista;
    while(temp){
        if(temp->ano != -1)
            contador++;
        temp = temp->next;
    }
    return contador;
}


Luser registo(Luser lista,Luser* user_login){
    Luser user;
    user = (Luser)malloc(sizeof(User));
    fflush(stdin);
    printf("\t\t\tInsira o nome de utilizador: \n\t\t\t>>>");
    fflush(stdin);
    scanf(" %[^\n]s",user->nome);
    while(user_existe(user->nome,lista)!=NULL){
        printf("\t\t\tUSERNAME JA UTILIZADO\n\t\t\t>>>");
        scanf(" %[^\n]s",user->nome);
    }
    printf("\t\t\tInsira a morada: \n\t\t\t>>>");
    fflush(stdin);
    scanf(" %[^\n]s",user->morada);
    do{
        fflush(stdin);
        printf("\t\t\tInsira o ano em que nasceu:\n");
        scan_int_prot(&(user->ano));
        printf("\t\t\tInsira o mes do ano em que nasceu:\n");
        scan_int_prot(&(user->mes));
        printf("\t\t\tInsira o dia do mes do ano em que nasceu:\n");
        scan_int_prot(&(user->dia));
        if(data_valida(user->dia,user->mes,user->ano)==0)
            printf("\n\t\t\t--->DATA INVALIDA\n");
    }while(data_valida(user->dia,user->mes,user->ano)==0);

    do{
        printf("\t\t\tInsira o seu numero de telefone:\n\t\t\t>>>");
        scanf("%s",user->numero);
        if(strlen(user->numero)!=9)
            printf("\n\t\t\t--->NUMERO INVALIDO\n");
    }while(strlen(user->numero)!=9);

    user->local1=NULL;
    user->local2=NULL;
    user->local3=NULL;
    user->npref = 0;
    user->pref = NULL;
    user->hot = NULL;
    user->next = NULL;
    lista = insere_user(user,lista);
    *user_login = user;
    return lista;
}


Luser login(Luser lista_users){
    char username[SIZE];
    Luser user_login;
    printf("\t\t\tInsira o nome de utilizador: \n\t\t\t>>>");
    fflush(stdin);
    scanf(" %[^\n]s",username);
    user_login = user_existe(username, lista_users);
    if(user_login != NULL)
        printf("LOGIN BEM SUCEDIDO\n");
    else
        printf("\t\t\tNOME NAO ENCONTRADO, POR FAVOR REGISTE-SE\n\n");
    /*printf("%s",user_login->nome);
    printf("%s\n",user_login->local1->nome);
    printf("%s",user_login->local2->nome);*/
    return user_login;
}
int conta_users(Luser lista){
    Luser temp = lista;
    int conta = 0;
    while(temp){
        conta++;
        temp = temp->next;
    }
    return conta;
}

double user_contagem_avaliacao(Luser lista,Llocais local1, Llocais local2, Llocais local3){
    Luser temp;
    int contador = 0,n_users = 0;;
    temp = lista;
    while(temp){
        if (temp->local1 == local1 || temp->local1 == local2 || temp->local1 == local3)
            contador++;
        else if (temp->local2 == local1 || temp->local2 == local2 || temp->local2 == local3)
            contador++;
        else if (temp->local3 == local1 || temp->local3 == local2 || temp->local3 == local3)
            contador++;
        temp = temp->next;
        n_users++;
    }
    return contador/conta_users(lista)*100;
}


int data_valida(int dia,int mes,int ano){
    if (dia>31 || ano<=0 || mes > 12 || mes<1 || dia<1)
        return 0;
    else{
        if (mes==2 || mes==4 || mes==6 || mes==9 || mes==11 ){
            if (mes==2){
                if ((ano & 3) == 0 && ((ano % 25) != 0 || (ano & 15) == 0)){
                    if(dia>29)
                        return 0;
                }
                else{
                    if(dia>28)
                        return 0;
                }
            }
            if(dia>30)
                return 0;
        }
    }
    return 1;
}

