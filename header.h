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
typedef struct dist* Ldist;


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
    float n_hot;
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

typedef struct dist{
    Llocais local1;
    Llocais local2;
    int distancia;
    Ldist next;
} Dist;





/*USERS*/
Luser le_users(Llocais locais, int* n);
int conta_users(Luser lista);
Luser user_existe(char* username, Luser lista);
void escreve_users(Luser lista,int n);
Luser registo(Luser lista, Luser* user_login);
Luser login(Luser lista_users);
int users_validos(Luser lista);
Luser insere_user(Luser newuser, Luser lista);
double user_contagem_avaliacao(Luser lista,Llocais local1, Llocais local2, Llocais local3);



/*LOCAIS*/
Lpdi insere_pdi(Lpdi pdi,Lpdi lista_pdi);
Ldist insere_dist(Ldist lista, Ldist novo);
Llocais insere_local(Llocais local, Llocais lista_local);
void printaListaLocais(Llocais lista);
void printaListaPdi(Lpdi lista_pdi);
Llocais le_locais (void);
Ldist le_distancias(Llocais locais);
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
double conta_pdis_pop_total(Luser users);
int data_valida(int dia,int mes,int ano);

/*MAIN*/
void scan_int_prot (int* num);
void menu_altera_prefs(Luser user,Llocais locais);
void menu_altera_locais(Luser user,Llocais locais);
void menu_altera_pdis(Luser user,Llocais locais);
Lpdi listagem_pdi_alterar(Llocais locais,Lpref pdis_prefs);
void print_locais_e_pdis(Llocais lista);
void protege_escolhas(int* opcao,int n);
void mostra_locais_e_pdis(Llocais lista,int alfabetica);
void menu_altera_hot(Luser user,Llocais locais);
char* printa_local_menu(Llocais local);
char* printa_hot_menu(Lpdi pdi);
void mostra_locais_ordenados_pop(Llocais lista);
void gera_viagem(Llocais locais,Luser user,Luser lista, Ldist dist);
void gera_pdis(Llocais local, User* user,double* total_pdi_pop_inc,double* numero_hots);
void escreve_titulo();
void menu();
void free_listas(Llocais locais, Luser users);
void menu_conta(Luser user);
int procura_distancias(Llocais local1,Llocais local2, Ldist dist);
