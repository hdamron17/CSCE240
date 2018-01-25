/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

void mat_assign(int** mat, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      mat[i][j] = rand() % 100 + 1;
    }
  }
}

void mat_print(int** mat, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

int main(int argc, char** argv) {
  // seed random number gen with a const literal 123
  srand(123);

  // create two const ints for kRows and columns of matrix
  const int kRows = 6, kCols = 5;

  // create int matrix and assign each element a random [1, 100]
  int** mat = new int*[kRows];
  for (int i = 0; i < kRows; ++i)
    mat[i] = new int[kCols];
  mat_assign(mat, kRows, kCols);

  // print int matrix
  cout << "Matrix:" << endl;
  mat_print(mat, kRows, kCols);
  for (int i = 0; i < kRows; ++i)
    delete [] mat[i];
  delete [] mat;

  // reseed random number gen with 123
  // create dynamic int matrix twice as large
  // and assign each element a random [1, 100]
  srand(123);
  int** double_mat = new int*[2*kRows];
  for (int i = 0; i < 2*kRows; ++i)
    double_mat[i] = new int[2*kCols];
  mat_assign(double_mat, 2*kRows, 2*kCols);

  // print matrix
  cout << "Doubled matrix:" << endl;
  mat_print(double_mat, 2*kRows, 2*kCols);
  for (int i = 0; i < 2*kRows; ++i)
    delete [] double_mat[i];
  delete [] double_mat;

  return 0;
}
