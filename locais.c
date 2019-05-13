#include "header.h"


Lpref le_pdi_pref(Lpref lista, char* pdi,Llocais locais){
    Lpref temp,ant=NULL;
    Lpref novo;
    temp = lista;
    while(temp){
        ant = temp;
        temp = temp->next;
    }
    novo = (Lpref)malloc(sizeof(Pref));
    novo->pdi = procura_pdi(locais,pdi);
    novo->pdi->pop++;
    novo->next = NULL;

    if (!ant)
        return novo;
    else
        ant->next = novo;
    return lista;
}

Llocais le_locais (void){
    Llocais lista_todos = NULL;
    Llocais local,temp;
    Lpdi pdi;
    Lpdi lista_pdi = NULL;
    char temporario[SIZE_LINHA];
    int numero,i,k;
    FILE* f;
    temp = NULL;
    f = fopen("fichTxt.txt","r");
    for(i=0; i<16; i++){
        fflush(stdin);
        local = (Llocais)malloc(sizeof(LocaisNo));
        local->next = NULL;
        local->pop = 0;
        while(temp){
            temp = temp->next;
        }
        lista_pdi = NULL;
        fflush(stdin);
        fscanf(f,"%d %s\n",&numero,local->nome);
        for (k=0;k<numero;k++){
            pdi = (Lpdi)malloc(sizeof(Pdi));
            pdi->next = NULL;
            pdi->pop = 0;
            pdi->n_hot = 0;
            pdi->local = local;
            fflush(stdin);
            fgets(temporario,sizeof(temporario),f);
            sscanf(temporario,"%[^\n]s",pdi->nome);
            fflush(stdin);
            fgets(temporario,sizeof(temporario),f);
            sscanf(temporario,"%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]s",pdi->data.ini_h,pdi->data.ini_m,pdi->data.fim_h,pdi->data.fim_m,pdi->descricao);
            lista_pdi = (Lpdi)insere_pdi(pdi,lista_pdi);
        }
        local->pdis = lista_pdi;
        lista_todos = insere_local(local, lista_todos);

    }
    return lista_todos;
}


void printaListaLocais(Llocais lista){
    Llocais temp;
    int contador = 0,len,i,k;
    temp = lista;
    printf("\n\n\n");
    while(temp){
        for(k=0;k<2;k++){
            len = strlen(temp->nome);
            printf("\t\t\t\t  %2.0d. %s",contador+1,temp->nome,temp->pop);
            for(i=0;i+len<30;i++)
                printf(" ");
            temp = temp->next;
            contador++;
        }
            printf("\n\n");
    }
    printf("\n\n");
}


void printaListaPdi(Lpdi lista_pdi){
    Lpdi temp;
    int contador = 1,i=0;
    system("@cls||clear\n");
    escreve_titulo();
    printf("\n\n\n\t\t\t\t\t\t\t               PDIS DE: %s \n\n\n\n",lista_pdi->local->nome);
    temp = lista_pdi;
    while(temp){
        printf("\t\t%d.   %s ",contador,temp->nome);
        for(i=0;i+strlen(temp->nome)<40;i++)
            printf(" ");
        printf("POPULARIDADE:%2d HOT:%2d",temp->pop,temp->n_hot);
        printf("\t\tHORARIO: %s:%s - %s:%s",temp->data.ini_h,temp->data.ini_m,temp->data.fim_h,temp->data.fim_m);
        printf("\t\tDESCRICAO: %s\n\n",temp->descricao);
        temp = temp->next;
        contador++;
    }
    printf("\n\n");
}


Lpdi insere_pdi(Lpdi pdi,Lpdi lista_pdi){
    Lpdi temp,ant = NULL;
    temp = lista_pdi;
    while(temp){
        ant = temp;
        temp = temp->next;
    }
    if(!ant){
        lista_pdi = pdi;
    }
    else{
        ant->next = pdi;
    }
    return lista_pdi;
}


Llocais insere_local(Llocais local, Llocais lista_local){
    Llocais temp,ant = NULL;
    temp = lista_local;
    while(temp){
        ant = temp;
        temp = temp->next;
    }
    if(!ant){
        lista_local = local;
    }
    else{
        ant->next = local;
    }
    return lista_local;
}



Llocais procura_lista(Llocais lista,char* nome){
    Llocais temp = lista;
    while(temp){
        if (!strcmp(temp->nome,nome)){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void adiciona_pop(Llocais local){
    (local->pop)++;
}

Lpdi procura_pdi(Llocais lista,char* nome){
    Llocais temp = lista;
    Lpdi aux;
    while (temp){
        aux = temp->pdis;
        while(aux){
            if(!strcmp(aux->nome,nome))
                return aux;
            aux = aux->next;
        }
        temp = temp->next;
    }
    return NULL;
}

Llocais modifica_local_pref(User* user, int n, Llocais lista){
    Llocais temp;
    int i;
    temp = lista;
    for(i=0;i<n-1;i++)
        temp = temp->next;
    if (verifica_local_repetido(user,temp))
        return NULL;
    return temp;
}

void printa_pdi_pref(Lpref lista,int*n,int adicionar){
    int contador=0;
    Lpref temp;
    temp = lista;
    printf("\n\n\n");
    while (temp){
        printf("\t\t\t\t%d : %s\n", contador+1,temp->pdi->nome);
        temp = temp->next;
        contador++;
    }
    if(adicionar){
        printf("\t\t\t\t%d : Adicionar\n\n\n",contador+1);
        *n = contador+1;
    }
}

Lpref percore_pdi_pref(Lpref lista, int n){
    Lpref temp;
    int i;
    temp = lista;
    for(i=0;i<n-1;i++)
        temp = temp->next;
    return temp;
}

int verifica_pdi_em_pref(Lpref lista,Lpdi pdi){
    Lpref temp = lista;
    while(temp){
        if (temp->pdi==pdi)
            return 1;
        temp=temp->next;
    }
    return 0;
}

Lpdi percore_pdi(Lpdi lista,int n){
    Lpdi temp;
    int i;
    temp = lista;
    for(i=0;i<n-1;i++)
        temp = temp->next;
    return temp;
}

int conta_pdis(Lpdi lista){
    int contador = 0;
    Lpdi temp;
    temp = lista;
    while(temp){
        contador++;
        temp = temp->next;
    }
    return contador;
}

int verifica_pdi_repetido(Lpdi novo,Lpref lista){
    Lpref temp;
    temp = lista;
    while(temp){
        if (temp->pdi==novo)
            return 1;
        temp=temp->next;
    }
    return 0;
}

int verifica_local_repetido(User* user,Llocais novo){
    if(user->local1==novo || user->local2==novo || user->local3==novo)
        return 1;
    return 0;
}

Lpref insere_pdi_pref(Lpref lista, Lpdi pdi){
    Lpref temp,ant=NULL;
    Lpref novo;
    temp = lista;
    while(temp){
        ant = temp;
        temp = temp->next;
    }
    novo = (Lpref)malloc(sizeof(Pref));
    novo->pdi = pdi;
    novo->next = NULL;

    if (!ant)
        return novo;
    else
        ant->next = novo;
    return lista;
}

Lpref apaga_pdi_pref(User* user,Lpref lista, Lpref apagar){
    Lpref temp=NULL,ant=NULL,next;
    temp = lista;
    if(temp->next==NULL){
        user->npref--;
        apagar->pdi->pop--;
        free(temp);
        return NULL;
    }
    if(lista==apagar){
        user->npref--;
        apagar->pdi->pop--;
        next = lista->next;
        free(temp);
        return next;
    }
    while(temp){
        if(temp==apagar){
            user->npref--;
            apagar->pdi->pop--;
            ant->next = temp->next;
            free(temp);
            return lista;
        }
        ant = temp;
        temp = temp->next;
    }
    return NULL;
}



Llocais sort_locais_pop(Llocais lista){
    int i,flag;
    Llocais temp,ant,next;
    temp = lista;
    if(lista==NULL)
        return NULL;

    /*ORGANIZA OS PDIS 1º*/
    while(temp){
        temp->pdis = sort_pdi_pop(temp->pdis,conta_pdis(temp->pdis));
        temp=temp->next;
    }

    temp = lista;
    for(i=0;i<20;i++){
        flag = 0;
        temp = lista;
        next = temp->next;
        ant = NULL;
        while(next){
            if (temp->pop<next->pop){
                flag = 1;
                if(!ant){
                    temp->next = next->next;
                    next->next = temp;
                    lista = next;
                }
                else{
                    ant->next = next;
                    temp->next = next->next;
                    next->next = temp;
                }
                ant = next;
                next = temp->next;
            }
            else{
                ant = temp;
                temp = temp->next;
                next = next->next;
            }
        }
        if (flag==0)
            return lista;
    }
    return lista;
}


Llocais sort_locais_alfabetica(Llocais lista){
    int i,flag;
    Llocais temp,ant,next;
    int comparacao;
    temp = lista;
    if(lista==NULL)
        return NULL;

    /*ORGANIZA OS PDIS 1º*/
    while(temp){
        temp->pdis = sort_pdi_alfabetica(temp->pdis,conta_pdis(temp->pdis));
        temp=temp->next;
    }

    temp = lista;

    for(i=0;i<20;i++){
        flag = 0;
        temp = lista;
        next = temp->next;
        ant = NULL;
        while(next){
            comparacao = strcmp(temp->nome,next->nome);
            if (comparacao>0){
                flag = 1;
                if(!ant){
                    temp->next = next->next;
                    next->next = temp;
                    lista = next;
                }
                else{
                    ant->next = next;
                    temp->next = next->next;
                    next->next = temp;
                }
                ant = next;
                next = temp->next;
            }
            else{
                ant = temp;
                temp = temp->next;
                next = next->next;
            }
        }
        if (flag==0)/*OTIMIZA TEMPO, SE HÁ ALGUMA VEZ QUE NADA SE ALTERA ESCUSA DE REPETIR*/
            return lista;
    }
    return lista;
}

Lpdi sort_pdi_pop(Lpdi lista,int n){
    int i,flag;
    Lpdi temp,ant,next;
    if(lista==NULL)
        return NULL;
    for(i=0;i<n;i++){
        flag = 0;
        temp = lista;
        next = temp->next;
        ant = NULL;
        while(next){
            if (temp->pop<next->pop){
                flag = 1;
                if(!ant){
                    temp->next = next->next;
                    next->next = temp;
                    lista = next;
                }
                else{
                    ant->next = next;
                    temp->next = next->next;
                    next->next = temp;
                }
                ant = next;
                next = temp->next;
            }
            else{
                ant = temp;
                temp = temp->next;
                next = next->next;
            }
        }
        if (flag==0)
            return lista;
    }
    return lista;
}

Lpdi sort_pdi_alfabetica(Lpdi lista,int n){
    int i,flag;
    Lpdi temp,ant,next;
    int comparacao;
    temp = lista;
    if(lista==NULL)
        return NULL;

    for(i=0;i<20;i++){
        flag = 0;
        temp = lista;
        next = temp->next;
        ant = NULL;
        while(next){
            comparacao = strcmp(temp->nome,next->nome);
            if (comparacao>0){
                flag = 1;
                if(!ant){
                    temp->next = next->next;
                    next->next = temp;
                    lista = next;
                }
                else{
                    ant->next = next;
                    temp->next = next->next;
                    next->next = temp;
                }
                ant = next;
                next = temp->next;
            }
            else{
                ant = temp;
                temp = temp->next;
                next = next->next;
            }
        }
        if (flag==0)/*OTIMIZA TEMPO, SE HÁ ALGUMA VEZ QUE NADA SE ALTERA ESCUSA DE REPETIR*/
            return lista;
    }
    return lista;
}

int verifica_hot_em_local(Lpdi hot, Llocais local){
    Lpdi temp = local->pdis;
    while(temp){
        if(hot == temp)
            return 1;
        temp = temp->next;
    }
    return 0;

}
