#include <stdio.h>
#include <stdlib.h>

#define PATH_PASSWD "/etc/passwd"
#define MAX_STRLEN 30

int main(int argc, char** argv) {
    FILE* passwd;
    char name[MAX_STRLEN];
    char trash[100];
    int uid;
    
    if(!(passwd = fopen(PATH_PASSWD,"r")))
        exit(1);
    
    printf("Ecco la lista di utenti umani:\n\n");
    
    do{
        fscanf(passwd,"%[^:]:x:%d:%[^\n]\n", name, &uid, trash);
        if(uid >= 1000 && uid!=65534)
            printf("%s\n",name);
    }while(!(feof(passwd)));

    return (EXIT_SUCCESS);
}

