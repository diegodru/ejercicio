#include <stdlib.h>
#include <stdio.h>

struct emp{
  unsigned short numero;
  char nombre[10];
  unsigned short meses_trabajo;
  char directivo;
};

void imprimir(struct emp e, int (*prima)(struct emp)){
    printf("Numero de empleado\t| Nombre\t| Meses de trabajo | directivo\n");
    if(prima(e))
      printf("%i\t| %s\t| %i\t| %c\n", e.numero, e.nombre, e.meses_trabajo, e.directivo);
}

int p1(struct emp e){ return (e.meses_trabajo >= 12 && e.directivo == '+'); };
int p2(struct emp e){ return (e.meses_trabajo >= 12 && e.directivo == '-'); };
int p3(struct emp e){ return (e.meses_trabajo < 12 && e.directivo == '+'); };
int p4(struct emp e){ return (e.meses_trabajo < 12 && e.directivo == '-'); };

int main(int argc, char *argv[]){
  if(argc < 2)
    exit(1);
  FILE *file = fopen(argv[1], "r");;
  while(1){
    struct emp e;
    size_t buffer_size = 18;
    char *buffer = malloc(buffer_size);
    getline(&buffer, &buffer_size, file);
  }
}
