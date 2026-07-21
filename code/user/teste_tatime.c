#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  printf("--- TESTE DA CHAMADA DE SISTEMA tatime() ---\n");
  printf("Buscando tempo de turnaround inicial...\n");
  
  int t1 = tatime();
  printf("Tempo retornado por tatime(): %d ticks\n", t1);
  
  if (t1 < 0 || t1 > 1000000) {
    printf("ALERTA: O valor %d e extremamente alto!\n", t1);
    printf("Isso indica UNDERFLOW (p->final e 0 enquanto o processo roda).\n");
  } else {
    printf("Sucesso: Tempo retornado e razoavel.\n");
  }
  
  printf("Fazendo pausa de 10 ticks...\n");
  pause(10);
  
  int t2 = tatime();
  printf("Tempo retornado por tatime() apos pausa: %d ticks\n", t2);
  printf("Diferenca medida: %d ticks\n", t2 - t1);
  
  exit(0);
}
