#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char* nome;
    int idade;
    char* cargo;
}User;

int main()
{
    int i = 0;
    User users[2];
    users[0].nome = "Bernardo";
    users[1].nome = "210";
    for (i = 0;i<2;i++){
        printf("%s\n",(users+i)->nome);

    }
    return 0;
}
