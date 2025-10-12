//
//   Cria vários processos filhos em sequência usando fork(). O número de processos depende 
//   do argumento passado. Cada processo imprime seu próprio PID, o do pai e do último 
//   filho criado.
//
//  Created by Paulo Roberto Oliveira Valim on 23/03/17.
//  Copyright © 2017 Paulo Roberto Oliveira Valim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t childpid;  
    int i, n;
    if (argc != 2) {  // verifica se foi passado exatamente 1 parâmetro na execução do programa
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);  // converte o parâmetro passado (string) em inteiro
    for (i = 0; i < n; i++)
        if ((childpid = fork()) <= 0) 
            break;
    while(wait(NULL) > 0) ; // o processo pai espera todos os filhos terminarem
    printf("i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
            i, (long)getpid(), (long)getppid(), (long)childpid);
    return 0;
}
