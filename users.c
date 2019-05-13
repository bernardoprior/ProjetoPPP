#include "header.h"



/*User* le_users(Llocais locais,int* n){
    User* lista;
    int i,k;
    char temp[HUGE_SIZE], local1[SIZE],local2[SIZE],local3[SIZE],pdi[HUGE_SIZE];
    FILE* f;
    f = fopen("pessoas.txt","r");
    fflush(stdin);
    fgets(temp,sizeof(temp),f);
    sscanf(temp,"%d\n",n);
    lista = (User*)malloc((*n+1)*sizeof(User));
    for (i = 0; i<*n; i++){
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%d|%d|%d|%[^|]|\n",lista[i].nome,lista[i].morada,&(lista[i].ano),&(lista[i].mes),&(lista[i].dia),lista[i].numero);
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%[^|]|\n",local1,local2,local3);
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%d\n",&(lista[i].npref));
        lista[i].pref = NULL;
        for(k=0;k<lista[i].npref;k++){
            fflush(stdin);
            fgets(temp,sizeof(temp),f);
            sscanf(temp,"%[^|]|\n",pdi);
            lista[i].pref = le_pdi_pref(lista[i].pref,pdi,locais);
            printf("%s",lista[i].pref->pdi->nome);
        }
        lista[i].local1 = procura_lista(locais,local1);
        lista[i].local2 = procura_lista(locais,local2);
        lista[i].local3 = procura_lista(locais,local3);
        if (lista[i].local1 != NULL)
            adiciona_pop(lista[i].local1);
        if (lista[i].local2 != NULL)
            adiciona_pop(lista[i].local2);        if (lista[i].local3 != NULL)
            adiciona_pop(lista[i].local3);
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|\n",pdi);
        lista[i].hot = procura_pdi(locais,pdi);
        if(lista[i].hot != NULL)
            lista[i].hot->n_hot++;
        fflush(stdin);
    }
    fclose(f);
    return lista;
}*/

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
    Luser novouser,lista;
    f = fopen("pessoas.txt","r");
    fflush(stdin);
    fgets(temp,sizeof(temp),f);
    sscanf(temp,"%d\n",n);
    printf("%d",*n);
    for(i = 0;i<*n;i++){
        novouser = (Luser)malloc(sizeof(User));
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%d|%d|%d|%[^|]|\n",novouser->nome,novouser->morada,&(novouser->ano),&(novouser->mes),&(novouser->dia),novouser->numero);
        printf("%s\n",novouser->numero);
        fflush(stdin);
        fgets(temp,sizeof(temp),f);
        sscanf(temp,"%[^|]|%[^|]|%[^|]|\n",local1,local2,local3);
        novouser->local1 = procura_lista(locais,local1);
        novouser->local2 = procura_lista(locais,local2);
        novouser->local3 = procura_lista(locais,local3);
        printf("%s\n",novouser->local1->nome);
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
            printf("hot:%s\n",temp);
        lista = insere_user(novouser,lista);
    }
    return lista;
}

void printausers(Luser lista){
    Luser temp = lista;
    int i;
    while(temp){

            printf("\n-----\n");
        printa_pdi_pref(temp->pref,&i,0);
        temp = temp->next;
    }
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
        printf("%d",strcmp(username,temp->nome)==0);
        if (strcmp(username,temp->nome)==0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void escreve_users(Luser lista,int n){
    FILE *f;
    int i;
    Lpref temp;
    f = fopen("pessoas.txt","w");
    fprintf(f,"%d\n",users_validos(lista,n));
    for(i=0;i<n;i++){
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
    }
    fclose(f);
}

int users_validos(User* lista,int n){
    int i,contador=0;
    for(i=0;i<n;i++){
        if (lista[i].ano != -1)
            contador++;
    }
    return contador;
}


/*User* registo(User* lista_users,int* numero_users){
    User* user_login;

    fflush(stdin);
    printf("\t\t\tInsira o nome de utilizador: \n\t\t\t>>>");
    fflush(stdin);
    scanf(" %[^\n]s",lista_users[*numero_users].nome);
    while(user_existe(lista_users[*numero_users].nome,lista_users,*numero_users)!=NULL){
        printf("\t\t\tUSERNAME JA UTILIZADO\n\t\t\t>>>");
        scanf(" %[^\n]s",lista_users[*numero_users].nome);
    }
    printf("\t\t\tInsira a morada: \n\t\t\t>>>");
    fflush(stdin);
    scanf(" %[^\n]s",lista_users[*numero_users].morada);
    printf("\t\t\tInsira o ano em que nasceu: \n\t\t\t>>>");
    fflush(stdin);
    scanf("%d",&lista_users[*numero_users].ano);
    printf("\t\t\tInsira o mes do ano em que nasceu: \n\t\t\t>>>");
    scanf("%d",&lista_users[*numero_users].mes);
    printf("\t\t\tInsira o dia do mes do ano em que nasceu: \n\t\t\t>>>");
    scanf("%d",&lista_users[*numero_users].dia);
    printf("\t\t\tInsira o seu numero de telefone: \n\t\t\t>>>");
    scanf("%s",lista_users[*numero_users].numero);
    user_login = lista_users+*numero_users;
    user_login->local1=NULL;
    user_login->local2=NULL;
    user_login->local3=NULL;
    user_login->npref = 0;
    user_login->hot = NULL;
    (*numero_users)++;
    return user_login;
}*/


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


