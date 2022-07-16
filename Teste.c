#include <stdio.h>
#include <string.h>

int main() {
    char c;
    int u = 0;
    char user[100];
    char name[100];
    char cadastro[100];

    printf("Ja tem o seu Usuario cadastrado? [S/N]: ");
    scanf("%s", &cadastro);
    while ((c = getchar()) != '\n' && c != EOF){}

    if (strcmp(cadastro, "S") == 0 || strcmp(cadastro, "s") == 0) {
        FILE *f1 = fopen("usuarios.txt", "r");
        if (f1 == NULL) {
            fopen("usuarios.txt", "w");
            fclose(f1);
            FILE *f1 = fopen("usuarios.txt", "r");}
    
        printf("Coloque o seu usuario: ");
        scanf("%s", &user);
        while ((c = getchar()) != '\n' && c != EOF){}

        while (fgets(name, 100, f1) != NULL){
            if (strchr(name, '\n') != NULL) {name[strlen(name) - 1] = 0;}
        
            if (strcmp(name, user) == 0) {u++; break;}
        }

        if (u == 1) 
        {printf("Seja bem vindo %s!\a", name);} 
        else if (u == 0) 
        {printf("Usuario %s nao identificado.", user);}

        fclose(f1);
    
    } else if (strcmp(cadastro, "N") == 0 || strcmp(cadastro, "n") == 0) {
        printf("Coloque o Usuario: ");
        scanf("%s", &user);
        while ((c = getchar()) != '\n' && c != EOF){}

        FILE *f1 = fopen("usuarios.txt", "r");
        if (f1 == NULL) {
            fopen("usuarios.txt", "w");
            fclose(f1);
            FILE *f1 = fopen("usuarios.txt", "r");}

        while (fgets(name, 100, f1) != NULL){
            if (strchr(name, '\n') != NULL) {name[strlen(name) - 1] = 0;}
        
            if (strcmp(name, user) == 0) {u++; break;}}

        if (u == 1) 
        {puts("Este usuario ja existe.");} 
        else if (u == 0)
        {FILE *f1 = fopen("usuarios.txt", "a");
        if (f1 == NULL) {
            fopen("usuarios.txt", "w");
            fclose(f1);
            FILE *f1 = fopen("usuarios.txt", "a");}

        fprintf(f1, "%s\n", user);
        puts("Usuario adicionado.\a");}
    }
}