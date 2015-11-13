#include <stdio.h>
#include <stdlib.h>

#define PATH_PASSWD "/etc/passwd"                                               //percorso file passwd;
#define MAX_STRLEN 30                                                           //lunghezza massima per nome;

int main(int argc, char** argv) {
    FILE* passwd;                                                               //puntatore a file passwd;
    char name[MAX_STRLEN];                                                      //stringa contenente i nomi;
    char trash[100];                                                            //conterrà le informazioni non necessarie al compito;
    int uid;                                                                    //conterrà l'uid dell'utente corrente;
    
    if(!(passwd = fopen(PATH_PASSWD,"r")))                                      //controllo apertura file passwd;
        exit(1);                                                                // ERROR N°1 || failed to open passwd;
    
    printf("Ecco la lista di utenti umani:\n\n");
    
    do{
        fscanf(passwd,"%[^:]:x:%d:%[^\n]\n", name, &uid, trash);                //estrazione dati da singola riga di passwd;
        if(uid >= 1000 && uid<=9999)                                            //range di UID possibili per utenti umani;
            printf("%s\n",name);                                                //stampa nome utente;
    }while(!(feof(passwd)));                                                    //controllo fine file;

    return (EXIT_SUCCESS);
}

