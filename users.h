typedef struct {
     char nome[50];
     char morada[50];
     char numero[50];
     int dia;
     int mes;
     int ano;
}User;

int users_conta(void){
    char c;
    int contador = 0;
    FILE *f = fopen("pessoas.txt","r");
    for (;fscanf(f,"%c",&c) != EOF;){
        if(c=='\n')
            contador++;
    }
    fclose(f);
    return contador;
}

int users_lista(User* lista,int n){
    int i;
    char temp[100];
    FILE* f;
    f = fopen("pessoas.txt","r");
    for (i = 0; i<n; i++){
        fgets(temp,sizeof(temp),f);
        printf("%s",temp);
        sscanf(temp,"%[^|]|%[^|]|%d|%d|%d|%[^|]|",lista[i].nome,lista[i].morada,&(lista[i].ano),&(lista[i].mes),&(lista[i].dia),lista[i].numero);

    }
    fclose(f);
    return 0;
}



User* user_existe(char* username, User* lista, int n){
    int i;
    for (i = 0; i<n;i++){
        if (strcmp(username,(lista+i)->nome)==0){
            return (lista+i);
        }
    }
    return NULL;
}

void escreve_users(User* lista,int n){
    FILE *f;
    int i;
    f = fopen("pessoas.txt","w");
    for(i=0;i<n;i++){
        if (lista[i].ano != -1)
            fprintf(f,"%s|%s|%d|%d|%d|%s|\n",lista[i].nome,lista[i].morada,lista[i].ano,lista[i].mes,lista[i].dia,lista[i].numero);
    }
    fclose(f);
}


