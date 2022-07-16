#include <stdio.h>
#include <string.h>

int main() {
    char c;
    // ^ Vai limpar o buffer
    int u = 0;
    // ^ Dizer se o Usuario existe ou não
    char user[100];
    // ^ Usuario que você coloca
    char name[100];
    // ^ Usuario do arquivo
    char cadastro[100];
    // ^ Guarda a resposta da primeira pergunta

    printf("Ja tem o seu Usuario cadastrado? [S/N]: ");
    scanf("%s", &cadastro);
    // v Limpando o Buffer
    while ((c = getchar()) != '\n' && c != EOF){}

    if (strcmp(cadastro, "S") == 0 || strcmp(cadastro, "s") == 0) { // < Se a resposta for sim

        FILE *f1 = fopen("usuarios.txt", "r"); // < Vai tentar abrir o arquivo

        if (f1 == NULL) { // < Se o arquivo não existir ele irá criar um
            fopen("usuarios.txt", "w");
            fclose(f1);
            FILE *f1 = fopen("usuarios.txt", "r");}
    
        printf("Coloque o seu usuario: ");
        scanf("%s", &user);
        while ((c = getchar()) != '\n' && c != EOF){}

        while (fgets(name, 100, f1) != NULL){ // < Lê e armazena os Usuarios do arquivo no vetor [name]
            if (strchr(name, '\n') != NULL) {name[strlen(name) - 1] = 0;}
                                // ^ Se a uma quebra de linha[\n] na string, ela será retirada
            if (strcmp(name, user) == 0) {u++; break;}
                                // ^ Se for encontrado um Usuario igual, o vetor [u] será igual a [1]
        }
        
        // v Se [u] for igual a [1] quer dizer que o Usuario existe e foi identificado
        if (u == 1) 
        {printf("Seja bem vindo %s!\a", name);} 
        else if (u == 0) 
        {printf("Usuario %s nao identificado.", user);}

        fclose(f1); // < Fecha o arquivo de texto
    
    } else if (strcmp(cadastro, "N") == 0 || strcmp(cadastro, "n") == 0) { // < Se a resposta for não
        printf("Coloque o Usuario: "); // < Vai pedir o novo Usuario
        scanf("%s", &user);
        while ((c = getchar()) != '\n' && c != EOF){}

        FILE *f1 = fopen("usuarios.txt", "r"); // < Vai tentar abrir o arquivo
        if (f1 == NULL) {
            fopen("usuarios.txt", "w");
            fclose(f1);
            FILE *f1 = fopen("usuarios.txt", "r");}

        while (fgets(name, 100, f1) != NULL){ // < Vai tentar achar um Usuario igual
            if (strchr(name, '\n') != NULL) {name[strlen(name) - 1] = 0;}
        
            if (strcmp(name, user) == 0) {u++; break;}}

        if (u == 1)  // < Se encontrar
        {puts("Este usuario ja existe."); fclose(f1);}

        else if (u == 0) // < Se encontrar
        {fclose(f1); // v Vai reabrir o arquivo, agora para adicionar o novo Usuario
        FILE *f1 = fopen("usuarios.txt", "a");
        if (f1 == NULL) {
            fopen("usuarios.txt", "w");
            fclose(f1);
            FILE *f1 = fopen("usuarios.txt", "a");}

        fprintf(f1, "%s\n", user); // < Usuario foi adicionado
        puts("Usuario adicionado.\a");}
    }
}