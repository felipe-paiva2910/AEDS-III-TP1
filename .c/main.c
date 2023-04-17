#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
#include"file.h"


int main(int argc, char *argv[]){

    struct rusage time;
    struct timeval start,end;

    gettimeofday(&start,NULL);

    char* input = (char*)malloc(100*sizeof(char));
    char* output = (char*)malloc(100*sizeof(char));
    
    openFILE(argc,argv,input,output);
    readFILE(input);
    encontrar_maior_conjunto();

    FILE *fp = fopen(output,"a");
    fprintf(fp, "%d\n",maior_tamanho_conjunto);//escreve maior valor possível no arquivo saída
    fclose(fp);//fecha arquivo

    getrusage(RUSAGE_SELF,&time);
    gettimeofday(&end,NULL);

    
    printf("Resultado = %d\n\n",maior_tamanho_conjunto);
    printf("Tempo de Sistema = %lf\n",(double)1e-6*(time.ru_stime.tv_sec + time.ru_stime.tv_usec));
    printf("Tempo de Usuario = %lf\n",(double)1e-6*(time.ru_utime.tv_sec + time.ru_utime.tv_usec));
    printf("gettimeofday = %lf\n\n",(end.tv_sec-start.tv_sec)+ 1e-6 *(end.tv_usec-start.tv_usec));
    free(input);
    free(output);
    free(pontos);

    return 0;
}