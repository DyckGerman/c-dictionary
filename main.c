#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    printf("Hello, World!\n");

    char filename[] = "test.txt";

    FILE *fp;
    fp = fopen(filename, "r");
    char somecoolthing[20];
    char somecoolthing2[20];
    int a = 0;
    fscanf(fp,"%s%d%s",somecoolthing, a, somecoolthing2);


    if (fp == NULL) {
        exit(1);
    }
    char symlol;
    char result[100];

    while (symlol != EOF) {
        char * word  = malloc(50);
        word[0] = '\0';
        char * definition = malloc(200);
        char * nextChar = malloc (1);
        * nextChar = fgetc(fp);

        strcat(word, nextChar);

        while (* nextChar != '-') {
            strcat(word, nextChar);
            * nextChar = fgetc(fp);
        }

        * nextChar = fgetc(fp);

        while (* nextChar != '\n') {
            strcat(definition, nextChar);
            * nextChar = fgetc(fp);
        }
    }

    while (symlol != ":")
    fgets(result,100,fp);


    return 0;
}