#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void cpu_bound(int limit) {
  volatile int x = 0;
  for (int i = 0; i < limit; i++) {
    x += i * 37;
  }
  (void)x;
}

int main(int argc, char *argv[]) {
  printf("--- TESTE DE PREEMPCAO E ACUMULO DE QUANTUM ---\n");
  
  int pid = fork();
  if (pid < 0) {
    printf("Erro no fork\n");
    exit(1);
  }
  
  if (pid == 0) {
    // Processo filho
    printf("Filho [%d]: Iniciando carga mista (CPU + IO)...\n", getpid());
    
    for (int i = 0; i < 5; i++) {
      printf("Filho [%d]: Executando computacao rapida...\n", getpid());
      cpu_bound(5000000); // computacao curta
      
      printf("Filho [%d]: Cedendo CPU voluntariamente via pause(2)...\n", getpid());
      pause(2);
    }
    
    printf("Filho [%d]: Concluido.\n", getpid());
    exit(0);
  } else {
    // Pai
    int status;
    wait(&status);
    printf("Pai: Filho finalizou com status %d.\n", status);
    printf("Nota: Verifique os logs do console do xv6 para conferir se o processo\n");
    printf("sofreu preempcao por estouro de quantum mesmo chamando pause().\n");
  }
  
  exit(0);
}
