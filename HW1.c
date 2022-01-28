#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

    FILE *fp;
    int number;
    int i;
    
    fp = fopen(argv[argc-1], "r");
    printf("Opening File...\n");
    
    int count[argc];
    memset(count, 0, sizeof(count));
    char *word = malloc(sizeof(char));

    if (fp == NULL)
		exit(EXIT_FAILURE);

    while(fscanf(fp,"%s",word) >0){
        for(i=0;i<argc;i++){
            if (strcmp(argv[i], word) == 0){
                count[i] += 1;
            }
        }
    }

    for (i=1;i<argc-1;i++){
        printf("%s:   %d\n", argv[i], count[i]);
    }
    
    free(word);
    fclose(fp);
    return 0;
}