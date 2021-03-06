#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct emp{
  unsigned short numero;
  char nombre[10];
  unsigned short meses_trabajo;
  char directivo;
};

void imprimir(struct emp e, const char *prima){
      printf("Prima: %s Numero: %i  Nombre: %s Numero de meses: %i directivo: %c\n", prima, e.numero, e.nombre, e.meses_trabajo, e.directivo);
}

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
    if(!e.numero)
      continue;
    if(e.directivo == '+'){
      if(e.meses_trabajo > 11)
        imprimir(e, "P1");
      else
        imprimir(e, "P3");
    }else{
      if(e.meses_trabajo > 11)
        imprimir(e, "P2");
      else
        imprimir(e, "P4");
    }
  }
  fclose(file);
}
