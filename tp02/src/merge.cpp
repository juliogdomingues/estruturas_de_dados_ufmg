#include "../include/merge.hpp"


int *merge(int *valuesL, int *valuesR, int nl, int nr) {
  int *result = (int *) malloc((nl+nr) * sizeof(int));
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < nl && j < nr) {
    if (valuesL[i] < valuesR[j]) {
      result[k] = valuesL[i];
      i++;
    } else {
      result[k] = valuesR[j];
      j++;
    }
    k++;
  }
    if (k < nl + nr) {
        for(; i < nl; i++) {
        result[k] = valuesL[i];
        k++;
        }
        for(; j < nr; j++) {
        result[k] = valuesR[j];
        k++;
        }
  }
  return result;
}
