#include "Matrix.h"

Matrix::Matrix(unsigned int r, unsigned int c){
  if (r > 0 && c > 0){
    this->rows = r;
    this->rows = c;
    elements = new float[][];
  } else {
    //Maybe not this, kind of destructive
    free(this);
  }
}

float * Matrix::getElement(unsigned int r, unsigned int c){
  if (validRow(r) && validCol(c)){
    unsigned int mod = 0;
    mod += r * cols;
    mod += c;
    return (elements + mod);
  }
  return NULL;
}

void Matrix::setElement(unsigned int r, unsigned int c, float val){
  if (validRow(r) && validCol(c)){
    unsigned int mod = 0;
    mod += r * cols;
    mod += c;
    *(elements + mod) = val;
  }
}
