#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<getopt.h>
#include"file.h"


int openFILE(int argc, char* argv[],char* input,char* output){
    int op;
    if(argc < 2){
        printf("ENTRADA INVALIDA!\n");
    }

    while((op = getopt(argc, argv, "i:o:")) != -1){ //lê os comandos e usa o "-i" como arquvio de entrada e o "-o" como arquivo de saida
        switch (op) {
            case 'i':
                strcpy(input, optarg);
                break;
            case 'o':
                strcpy(output, optarg);
                break;
            default:
                fprintf(stderr, "ENTRADA INVALIDA!: `%c'\n", optopt);//se não foi informado -i ou -o, mostra mensagem de erro e sai
                return -1; 
                break;
        }
    }
    return 0;
}

void readFILE(char *input) {
    FILE *fp = fopen(input, "r");

    fscanf(fp, "%d %f %f \n", &num_pontos, &ponto_ancora_a.x, &ponto_ancora_b.x);
    ponto_ancora_a.y = 0;
    ponto_ancora_b.y=0;
    if((num_pontos >1000000) || ponto_ancora_b.x <= ponto_ancora_a.x || ponto_ancora_b.x >10000 || ponto_ancora_a.x < 0) {//testa se os valores estão dentro do limite
        printf("ERRO: entrada do usuário não corresponde aos requisitos do programa!\n");
        exit(0);
    }

    pontos = (Ponto *)malloc(num_pontos * sizeof(Ponto));

    for(int i = 0; i < num_pontos; i++)
        fscanf(fp, "%f %f \n", &(pontos[i].x), &(pontos[i]).y);
    
    fclose(fp);
}