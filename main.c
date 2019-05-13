#include "header.h"


int main(){
    fflush(stdin);
    menu();
    return 0;
}
void menu(){
    int numero_users,escolha;
    char login_char;
    Luser lista_users;
    Luser user_login;
    Llocais listalocais = (Llocais)malloc(sizeof(LocaisNo));

    /*LE FICHEIROS*/
    listalocais = le_locais(); /*CRIAR UMA LISTA LIGADA COM TODOS OS LOCAIS*/
    lista_users = le_users(listalocais,&numero_users); /*CRIAR UMA LISTA COM TODOS OS USUARIOS*/

    escreve_titulo();
    printf("\n\n\n\t\t\t\t\t\t\t BEM VINDO AO PLANEAMENTO DE VIAGENS \n");
    do{
    login_char = '0';
    printf("\t\t\t\tLogin - (insira l)                                                    Registo - (insira r)\n\n");
    printf("\t\t\t>>>");
    fflush(stdin);
    scanf("%c",&login_char);

    while (login_char != 'r' && login_char != 'l' && login_char != 'L' && login_char != 'R'){
        printf("\t\t\tINVALIDO\n");
        fflush(stdin);
        printf("\t\t\t>>>");
        scanf("%c",&login_char);
    }


    if(login_char=='r' || login_char == 'R'){
        /*user_login = registo(lista_users);*/
    }


    else if (login_char=='l' || login_char == 'L'){
        printf("\n\n");
        user_login = login(lista_users);
    }
    }while(!user_login);

    while (escolha!=6){

    system("@cls||clear\n");
    escreve_titulo();

    printf("\n\n   USER: %s\t\tLOCAL PREF 1: %s\t\tLOCAL PREF 2: %s\t\tLOCAL PREF 3: %s\tHOT: %s  \n\n\t\t\t\t\t\t\t                MENU \n\n\n\n",user_login->nome,printa_local_menu(user_login->local1),printa_local_menu(user_login->local2),printa_local_menu(user_login->local3),printa_hot_menu(user_login->hot));
    printf("\t\t\t\tListagem de Locais e Pontos de Interesse (Ordem Alfabetica) ------------------> (insira 1)\n\n\n\n");
    printf("\t\t\t\tDefinir ou Alterar Preferencias ----------------------------------------------> (insira 2) \n\n\n\n");
    printf("\t\t\t\tOrdenar os Destinos por Popularidade -----------------------------------------> (insira 3)  \n\n\n\n");
    printf("\t\t\t\tGerar uma viagem -------------------------------------------------------------> (insira 4)\n\n\n\n");
    printf("\t\t\t\tDefinicoes de conta ----------------------------------------------------------> (insira 5)\n\n\n\n");
    printf("\t\t\t\tSair -------------------------------------------------------------------------> (insira 6)\n\n\n\n");
    do{
        fflush(stdin);
        scan_int_prot(&escolha);

    }while(!(escolha>0 && escolha<=6));

    if (escolha == 1){
        listalocais = sort_locais_alfabetica(listalocais);
        mostra_locais_e_pdis(listalocais,1);
        printf("\n\n\n");
        system("Pause");
    }

    if (escolha == 2){
        listalocais = sort_locais_alfabetica(listalocais);
        menu_altera_prefs(user_login,listalocais);
        printf("\n\n");
        system("Pause");
    }

    if (escolha==3){
        listalocais = sort_locais_pop(listalocais);
        mostra_locais_e_pdis(listalocais,0);
        printf("\n\n");
        system("Pause");
    }
    if(escolha==4){
        listalocais = sort_locais_pop(listalocais);
        gera_viagem(listalocais,user_login);
        printf("\n\n");
        system("Pause");
    }

    }

      /*  case 2:
            break;

        case 3:

            break;

        case 4:
            break;

        case 5:
            escreve_titulo();
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
    printf("%s %s %d %d %d %s \n",lista_users[1].nome,lista_users[1].morada,lista_users[1].ano,lista_users[1].mes,lista_users[1].dia,lista_users[1].numero);
    */

    escreve_users(lista_users,numero_users);
    mostra_locais_e_pdis(listalocais,1);
    system("Pause");
}


void mostra_locais_e_pdis(Llocais lista,int alfabetica){
    int /*i=1,*/aux=1/*,escolha,*/,n_local;
    Llocais temp = lista;
    system("@cls||clear\n");
    escreve_titulo();
    if(!alfabetica)
        printf("\n\n\n\t\t\t\t\t\t          LOCAIS(ORDEM DECRESCENTE DE POPULARIDADE)");
    else
        printf("\n\n\n\t\t\t\t\t\t\t     LOCAIS(ORDEM ALFABETICA)");
    printaListaLocais(lista);
    protege_escolhas(&n_local,20);

    temp = lista;
    while(aux!=n_local){
        temp = temp->next;
        aux++;
    }


    /*
    while(temp){
        printf("\t\t\t%d.   %s POPULARIDADE:%d\n\n",i,temp->nome,temp->pop);
        temp = temp->next;
        i++;
    }
    fflush(stdin);
    scan_int_prot(&escolha);
    while(!(escolha>=1 && escolha<i)){
        fflush(stdin);
        scan_int_prot(&escolha);
    }

    aux = 1;
    temp = lista;
    while(aux!=escolha){
        temp = temp->next;
        aux++;
    }*/
    printaListaPdi(temp->pdis);

}

void menu_altera_prefs(User* user,Llocais locais){
    int opcao;
    system("@cls||clear\n");
    escreve_titulo();
    printf("\n\n\n\t\t\t\t\t\t\t                MENU \n\n\n\n");
    printf("\t\t\t\tDefinir ou Alterar Locais Preferidos -----------------------------------------> (insira 1)\n\n\n\n");
    printf("\t\t\t\tDefinir ou Alterar PDIS Preferidos -------------------------------------------> (insira 2) \n\n\n\n");
    printf("\t\t\t\tDefinir ou Alterar PDI hot ---------------------------------------------------> (insira 3)  \n\n\n\n");

    fflush(stdin);
    scan_int_prot(&opcao);
    while(opcao!=1 && opcao!=2 && opcao!=3){
        fflush(stdin);
        scan_int_prot(&opcao);
    }

    if (opcao == 1){
        system("@cls||clear\n");
        escreve_titulo();
        menu_altera_locais(user,locais);

    }
    if (opcao == 2){
        system("@cls||clear\n");
        escreve_titulo();
        menu_altera_pdis(user,locais);
    }
    if (opcao == 3){
        system("@cls||clear\n");
        escreve_titulo();
        menu_altera_hot(user,locais);
    }
}

void menu_altera_locais(User* user,Llocais locais){
    int opcao,opcao2;
    if(user->local1 != NULL)
        printf("\n\n\n\t\t\t\t\tLocal Preferido 1: %s\n\n",user->local1->nome);
    else
        printf("\n\n\n\t\t\t\t\tLocal Preferido 1: Nao definido\n\n");
    if(user->local2 != NULL)
        printf("\t\t\t\t\tLocal Preferido 2: %s\n\n",user->local2->nome);
    else
        printf("\t\t\t\t\tLocal Preferido 2: Nao definido\n\n");
    if(user->local3 != NULL)
        printf("\t\t\t\t\tLocal Preferido 3: %s\n\n\n",user->local3->nome);
    else
        printf("\t\t\t\t\tLocal Preferido 3: Nao definido\n\n\n");
    printf("\t\t\tALTERAR LOCAL:\n");
    fflush(stdin);
    scan_int_prot(&opcao);
    while(opcao!=1 && opcao!=2 && opcao!=3){
        fflush(stdin);
        scan_int_prot(&opcao);
    }
    system("@cls||clear\n");
    escreve_titulo();
    printaListaLocais(locais);
    protege_escolhas(&opcao2,20);

    if (opcao==1 && modifica_local_pref(user,opcao2,locais)!=NULL){
        if(user->local1 != NULL)
            user->local1->pop--;
        printf("\n\n\t\t\t%s ---> ",user->local1->nome);
        user->local1=modifica_local_pref(user,opcao2,locais);
        printf("%s -ALTERADO COM SUCESSO\n\n",user->local1->nome);
        user->local1->pop++;
    }
    else if (opcao==2 && modifica_local_pref(user,opcao2,locais)!=NULL){
        if(user->local2 != NULL)
            user->local2->pop--;
        printf("\n\n\t\t\t%s ---> ",user->local2->nome);
        user->local2=modifica_local_pref(user,opcao2,locais);
        printf("%s -ALTERADO COM SUCESSO\n\n",user->local2->nome);
        user->local2->pop++;
    }
    else if (opcao==3 && modifica_local_pref(user,opcao2,locais)!=NULL)
    {
        if(user->local3 != NULL)
            user->local3->pop--;
        printf("\n\n\t\t\t%s ---> ",user->local3->nome);
        user->local3=modifica_local_pref(user,opcao2,locais);
        printf("%s -ALTERADO COM SUCESSO\n\n",user->local3->nome);
        user->local3->pop++;
    }
    else{
        printf("\n\n\t\t\tLOCAL REPETIDO\n");
    }
}

void menu_altera_pdis(User* user,Llocais locais){
    int n_escolhas,opcao,opcao_alterar;
    Lpref pdi_para_alterar = NULL,pdi_para_apagar = NULL;
    Lpdi novo_pdi;
    printf("\n\n\n\t\t\t\t\t\t\t                MENU \n\n\n\n");
    printf("\t\t\t\tAlterar ou adicionar um PDI --------------------------------------------------> (insira 1)\n\n\n\n");
    printf("\t\t\t\tApagar um PDI ----------------------------------------------------------------> (insira 2) \n\n\n\n");
    protege_escolhas(&opcao_alterar,2);


    if (opcao_alterar==1){
        system("@cls||clear\n");
        escreve_titulo();
        printa_pdi_pref(user->pref,&n_escolhas,1);
        printf("\t\t\tOPCAO:\n");
        protege_escolhas(&opcao,n_escolhas);

        if (opcao == n_escolhas)
            pdi_para_alterar = NULL;
        else{
            pdi_para_alterar = percore_pdi_pref(user->pref,opcao);
        }
        system("@cls||clear\n");
        escreve_titulo();
        printf("\n\n\t\t\t\t\t\t\t\t\tESCOLHA O LOCAL DO PDI");
        novo_pdi = listagem_pdi_alterar(locais,user->pref);
        if (novo_pdi){
            if(pdi_para_alterar != NULL){
                printf("\n\n\t\t\t%s ---> %s -ALTERADO COM SUCESSO\n\n",pdi_para_alterar->pdi->nome,novo_pdi->nome);
                pdi_para_alterar->pdi = novo_pdi;
                pdi_para_alterar->pdi->pop--;
            }
            else{
                user->pref = insere_pdi_pref(user->pref,novo_pdi);
                user->npref++;
                printf("\n\n\t\t\t%s -ADICIONADO COM SUCESSO\n\n",novo_pdi->nome);
            }
            novo_pdi->pop++;
        }
        else
            printf("\n\n\t\t\tPDI REPETIDO\n\n");
    }
    if (opcao_alterar==2){
        system("@cls||clear\n");
        escreve_titulo();
        printf("\n\n");
        if (user->npref == 0)
            printf("\n\n\t\t\tERROR 404: NAO HA PDIS PARA REMOVER\n\n");
        else{
            printa_pdi_pref(user->pref,&n_escolhas,0);
            printf("\n\n");
            printf("\t\t\tOPCAO:\n");
            protege_escolhas(&opcao,n_escolhas);
            pdi_para_apagar = percore_pdi_pref(user->pref,opcao);
            printf("\n\n\t\t\t%s -REMOVIDO\n\n",pdi_para_apagar->pdi->nome);
            user->pref = apaga_pdi_pref(user,user->pref,pdi_para_apagar);
        }
    }
}

Lpdi listagem_pdi_alterar(Llocais locais,Lpref pdis_prefs){
    int n_local,n_pdi,aux = 1,limite;
    Llocais temp;
    Lpdi novo_pdi;

    printaListaLocais(locais);
    protege_escolhas(&n_local,20);
    temp = locais;
    while(aux!=n_local){
        temp = temp->next;
        aux++;
    }
    printaListaPdi(temp->pdis);
    limite = conta_pdis(temp->pdis);
    protege_escolhas(&n_pdi,limite);


    novo_pdi = percore_pdi(temp->pdis,n_pdi);
    if (verifica_pdi_repetido(novo_pdi,pdis_prefs) && pdis_prefs!=NULL)
        return NULL;
    return novo_pdi;

}

void menu_altera_hot(User* user,Llocais locais){
    int escolha;
    printf("\n\n\t\t\tPDI HOT DEFINIDO: %s\n\n",printa_hot_menu(user->hot));
    printf("\t\t\t\t\t\t\t                MENU \n\n\n\n");
    printf("\t\t\t\tAlterar ou definir PDI HOT ---------------------------------------------------> (insira 1)\n\n\n\n");
    printf("\t\t\t\tApagar PDI HOT ---------------------------------------------------------------> (insira 2) \n\n\n\n");
    protege_escolhas(&escolha,2);
    if(escolha==1){
        if (user->hot!=NULL)
            user->hot->n_hot--;
        system("@cls||clear\n");
        escreve_titulo();
        user->hot =listagem_pdi_alterar(locais,NULL);
        user->hot->n_hot++;
        printf("\n\n\t\t\t PDI HOT ALTERADO");
    }
    if (escolha==2){
        if(user->hot==NULL)
            printf("\n\n\t\t\t PDI HOT NAO DEFINIDO");
        else{
            printf("\n\n\t\t\t PDI HOT APAGADO");
            user->hot->n_hot--;
            user->hot = NULL;
        }
    }
}

void protege_escolhas(int* opcao,int n){
    fflush(stdin);
    scan_int_prot(opcao);
    while(*opcao>n || *opcao<1){
        fflush(stdin);
        scan_int_prot(opcao);
    }
}

char* printa_local_menu(Llocais local){
    if (local==NULL)
        return "POR DEFINIR";
    else
        return local->nome;
}

char* printa_hot_menu(Lpdi pdi){
    if (pdi==NULL)
        return "POR DEFINIR";
    return pdi->nome;
}



void scan_int_prot (int* num){
    char o;
    do{
        fflush(stdin);
        printf("\t\t\t>>>");
        scanf("%d%c",num,&o);
        if (o != '\n')
            printf("\t\t\tINSIRA UM INTEIRO\n");

    }while(o != '\n');
}

void escreve_titulo(){
   FILE *f;
   char linha [SIZE_LINHA];
   f= fopen("titulo.txt","r");
   while(fgets(linha,sizeof(linha),f)!= NULL){
       printf("\t    %s",linha);
     }
     fclose(f);
}

void gera_viagem(Llocais locais,User* user){
    system("@cls||clear\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t            VIAGEM\n");
    if(user->local1 == NULL || user->local2 == NULL || user->local3 == NULL)
        printf("\n\n\n\t\t\tFALTA DEFENIR UM DOS LOCAIS PREFERIDOS\n\n");
    else{

        printf("\t\t\t\t\t\t\t\t       %s------>%s------>%s\n\n\n",user->local1->nome,user->local2->nome,user->local3->nome);
        printf("\t\t\t-%s\n\n",user->local1);
        gera_pdis(user->local1,user);
        printf("\t\t\t-%s\n\n",user->local2);
        gera_pdis(user->local2,user);
        printf("\t\t\t-%s\n\n",user->local3);
        gera_pdis(user->local3,user);
    }
}

void gera_pdis(Llocais local, User* user){
    int contador = 0;
    Lpdi temp,pdi1=NULL,pdi2=NULL,pdi3=NULL;
    if(user->hot != NULL){
        if(verifica_hot_em_local(user->hot,local)){
            temp = user->hot;
            printf("\t\t\t\t%d. %s\n",contador+1,temp->nome);
            printf("\t\t\t\t\tHORARIO: %s:%s - %s:%s\n",temp->data.ini_h,temp->data.ini_m,temp->data.fim_h,temp->data.fim_m);
            printf("\t\t\t\t\tDESCRICAO: %s\n\n",temp->descricao);
            pdi1 = user->hot;
            contador++;
        }
    }
    if (user->npref != 0){
        temp = local->pdis;
        while(temp && contador<3){
            if(verifica_pdi_em_pref(user->pref,temp) == 1 && verifica_repetido_viagem(pdi1,pdi2,pdi3,temp) == 0){
                printf("\t\t\t\t%d. %s\n",contador+1,temp->nome);
                printf("\t\t\t\t\tHORARIO: %s:%s - %s:%s\n",temp->data.ini_h,temp->data.ini_m,temp->data.fim_h,temp->data.fim_m);
                printf("\t\t\t\t\tDESCRICAO: %s\n\n",temp->descricao);
                contador++;
                if(contador==1)
                    pdi1 = temp;
                if(contador==2)
                    pdi2 = temp;
                if(contador==3)
                    pdi3 = temp;

            }
            temp = temp->next;
        }
    }
    temp = local->pdis;
    while(contador<3){
        if(verifica_repetido_viagem(pdi1,pdi2,pdi3,temp) == 0){
            printf("\t\t\t\t%d. %s\n",contador+1,temp->nome);
            printf("\t\t\t\t\tHORARIO: %s:%s - %s:%s\n",temp->data.ini_h,temp->data.ini_m,temp->data.fim_h,temp->data.fim_m);
            printf("\t\t\t\t\tDESCRICAO: %s\n\n",temp->descricao);
            contador++;
            if(contador==1)
                pdi1 = temp;
            if(contador==2)
                pdi2 = temp;
            if(contador==3)
                pdi3 = temp;
        }
        temp = temp->next;
    }

}

int verifica_repetido_viagem(Lpdi pdi1,Lpdi pdi2,Lpdi pdi3, Lpdi pdi){
    if(pdi==pdi1 || pdi==pdi2 || pdi==pdi3)
        return 1;
    return 0;
}
