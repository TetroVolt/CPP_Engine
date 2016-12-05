#ifndef MATRIX_H
#define MATRIX_H

#include "SDL.h"

class Matrix {
private:
  float ** elements;
  unsigned int rows, cols;
public:
  Matrix(unsigned int r, unsigned int c);
  int getRows(){ return rows; }
  int getCols(){ return cols; }
  bool validRow(unsigned int r){ return r < rows; }
  bool validCol(unsigned int c){ return c < cols; }

  float * getElement(unsigned int r, unsigned int c);
  void setElement(unsigned int r, unsigned int c, float val);
};

#endif
