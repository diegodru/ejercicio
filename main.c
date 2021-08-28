#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct emp{
  unsigned short numero;
  char nombre[10];
  unsigned short meses_trabajo;
  char directivo;
};

void imprimir(struct emp e, int (*prima)(struct emp)){
    if(prima(e) && e.numero)
      printf("Numero: %i  Nombre: %s Numero de meses: %i directivo: %c\n", e.numero, e.nombre, e.meses_trabajo, e.directivo);
}

int P1(struct emp e){ if (e.meses_trabajo >= 12 && e.directivo == '+'){ 
  printf("Prima: %s ", __FUNCTION__); return 1; }  return 0;};
int P2(struct emp e){ if (e.meses_trabajo >= 12 && e.directivo == '-'){ 
  printf("Prima: %s ", __FUNCTION__); return 1; }  return 0;};
int P3(struct emp e){ if (e.meses_trabajo < 12 && e.directivo == '+'){ 
  printf("Prima: %s ", __FUNCTION__); return 1; }  return 0;};
int P4(struct emp e){ if (e.meses_trabajo < 12 && e.directivo == '-'){ 
  printf("Prima: %s ", __FUNCTION__); return 1; }  return 0;};

int main(int argc, char *argv[]){
  if(argc < 2)
    exit(1);
  FILE *file = fopen(argv[1], "r");
  struct emp e;
  size_t buffer_size = 18;
  char *buffer = malloc(buffer_size);
  while(getline(&buffer, &buffer_size, file) != EOF){
    char *tok = strtok(buffer, ",");
    e.numero = atoi(tok);
    tok = strtok(NULL, ",");
    strncpy(e.nombre, tok, strlen(tok));
    tok = strtok(NULL, ",");
    e.meses_trabajo = atoi(tok);
    tok = strtok(NULL, ",");
    e.directivo = *tok;
    imprimir(e, P1);
    imprimir(e, P2);
    imprimir(e, P3);
    imprimir(e, P4);
  }
  fclose(file);
}
