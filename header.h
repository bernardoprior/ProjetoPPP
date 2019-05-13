#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_LINHA 300
#define SIZE 50
#define HUGE_SIZE 300


typedef struct pdi* Lpdi;
typedef struct locaisno* Llocais;
typedef struct pdipref* Lpref;
typedef struct user* Luser;


typedef struct user{
     char nome[SIZE];
     char morada[SIZE];
     char numero[SIZE];
     int dia;
     int mes;
     int ano;
     Lpdi hot;
     Llocais local1;
     Llocais local2;
     Llocais local3;
     int npref;
     Lpref pref;
     Luser next;

}User;


typedef struct data_pdi{
    char ini_h[3];
    char ini_m[3];
    char fim_h[3];
    char fim_m[3];
} Data;

typedef struct pdi{
    char nome[SIZE];
    char descricao[HUGE_SIZE];
    Data data;
    Lpdi next;
    int pop;
    Llocais local;
    int n_hot;
} Pdi;

typedef struct locaisno{
    char nome[SIZE];
    int pop;
    Lpdi pdis;
    Llocais next;
}LocaisNo;

typedef struct pdipref{
    Lpdi pdi;
    Lpref next;
} Pref;





/*USERS*/
Luser le_users(Llocais locais, int* n);
Luser user_existe(char* username, Luser lista);
void escreve_users(User* lista,int n);
User* registo(User* lista_users,int* numero_users);
Luser login(Luser lista_users);
int users_validos(User* lista,int n);
Luser insere_user(Luser newuser, Luser lista);



/*LOCAIS*/
Lpdi insere_pdi(Lpdi pdi,Lpdi lista_pdi);
Llocais insere_local(Llocais local, Llocais lista_local);
void printaListaLocais(Llocais lista);
void printaListaPdi(Lpdi lista_pdi);
Llocais le_locais (void);
Llocais procura_lista(Llocais lista,char* nome);
void adiciona_pop(Llocais local);
Lpdi procura_pdi(Llocais lista,char* nome);
Llocais modifica_local_pref(User* user, int n, Llocais lista);
Lpref le_pdi_pref(Lpref lista, char* pdi,Llocais locais);
void printa_pdi_pref(Lpref lista,int*n,int adicionar);
Lpref percore_pdi_pref(Lpref lista, int n);
int conta_pdis(Lpdi lista);
Lpdi percore_pdi(Lpdi lista,int n);
int verifica_pdi_repetido(Lpdi novo,Lpref lista);
int verifica_local_repetido(User* user,Llocais novo);
Lpref insere_pdi_pref(Lpref lista, Lpdi pdi);
Lpref apaga_pdi_pref(User* user,Lpref lista, Lpref apagar);
Llocais ordena_pop_locais_e_pdis(Llocais lista);
Llocais sort_locais_pop(Llocais lista);
Llocais sort_locais_alfabetica(Llocais lista);
Lpdi sort_pdi_pop(Lpdi lista,int n);
Lpdi sort_pdi_alfabetica(Lpdi lista,int n);
int verifica_pdi_em_pref(Lpref lista,Lpdi pdi);
int verifica_hot_em_local(Lpdi hot, Llocais local);
int verifica_repetido_viagem(Lpdi pdi1,Lpdi pdi2,Lpdi pdi3, Lpdi pdi);

/*MAIN*/
void scan_int_prot (int* num);
void menu_altera_prefs(User* user,Llocais locais);
void menu_altera_locais(User* user,Llocais locais);
void menu_altera_pdis(User* user,Llocais locais);
Lpdi listagem_pdi_alterar(Llocais locais,Lpref pdis_prefs);
void print_locais_e_pdis(Llocais lista);
void protege_escolhas(int* opcao,int n);
void mostra_locais_e_pdis(Llocais lista,int alfabetica);
void menu_altera_hot(User* user,Llocais locais);
char* printa_local_menu(Llocais local);
char* printa_hot_menu(Lpdi pdi);
void mostra_locais_ordenados_pop(Llocais lista);
void gera_viagem(Llocais locais,User* user);
void gera_pdis(Llocais local, User* user);
void escreve_titulo();
void menu();
