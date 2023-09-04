#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPALAVRA 10
#define MAXINDICE 1000
#define MAXPAGINA 1000

typedef struct indentr {
    char palavra[MAXPALAVRA];
    int numpags;
    int pags[MAXPAGINA];
} indentr_t;

typedef struct indrem {
  indentr_t indice[MAXINDICE];
  int numpalavras;
} indrem_t;

int cmpindentr(const void *p1, const void *p2) {
  const indentr_t *i1 = (const indentr_t*) p1;
  const indentr_t *i2 = (const indentr_t*) p2;
  return strcmp(i1->palavra, i2->palavra);
}

int cmpint(const void *p1, const void *p2) {
  const int *i1 = (const int*) p1;
  const int *i2 = (const int*) p2;
  return (*i1 > *i2) - (*i1 < *i2);
}

void inicializaindice(indrem_t *meuind) {
  meuind->numpalavras = 0;
  for (int i = 0; i < MAXINDICE; i++) {
    meuind->indice[i].numpags = 0;
    meuind->indice[i].palavra[0] = '\0';
  }
}

int localizapalavra(indrem_t *meuind, char *palavra) {
  int esq = 0, dir = meuind->numpalavras - 1;
  while (esq <= dir) {
    int meio = esq + (dir - esq) / 2;
    int res = strcmp(meuind->indice[meio].palavra, palavra);
    if (res == 0)
      return meio;
    if (res < 0)
      esq = meio + 1;
    else
      dir = meio - 1;
  }
  return -1;
}

int inserepalavra(indrem_t *meuind, char *palavra, int pagina) {
  int pos = localizapalavra(meuind, palavra);
  if (pos == -1) {
    if (meuind->numpalavras == MAXINDICE) {
      printf("Índice cheio, incapaz de inserir mais palavras.\n");
      return -1;
    }

    pos = meuind->numpalavras++;
    strcpy(meuind->indice[pos].palavra, palavra);
    meuind->indice[pos].pags[0] = pagina;
    meuind->indice[pos].numpags = 1;

    qsort(meuind->indice, meuind->numpalavras, sizeof(indentr_t), cmpindentr);
  } else {
    if (meuind->indice[pos].numpags == MAXPAGINA) {
      printf("Máximo de páginas atingido para a palavra '%s'.\n", palavra);
      return pos;
    }

    for (int i = 0; i < meuind->indice[pos].numpags; i++) {
      if (meuind->indice[pos].pags[i] == pagina) return pos;
    }

    meuind->indice[pos].pags[meuind->indice[pos].numpags++] = pagina;
  }
  return pos;
}

void imprimeindice(indrem_t *meuind) {
  for (int i = 0; i < meuind->numpalavras; i++) {
    printf("%s:", meuind->indice[i].palavra);
    qsort(meuind->indice[i].pags, meuind->indice[i].numpags, sizeof(int), cmpint);
    for (int j = 0; j < meuind->indice[i].numpags; j++) {
      printf(" %d", meuind->indice[i].pags[j]);
    }
    printf("\n");
  }
}

int main() {
  char palavra[MAXPALAVRA];
  int pagina;
  indrem_t meuind;

  inicializaindice(&meuind);

  while (scanf("%9s %d", palavra, &pagina) == 2) {
    inserepalavra(&meuind, palavra, pagina);
  }

  imprimeindice(&meuind);
  return 0;
}
