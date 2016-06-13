
//行列積を求めるプログラムを書いて、行列のサイズNと実行時間の関係を調べてみよう

//仕様：
//プログラムの入力はサイズN
//N×Nの行列AとBを用意する（行列の中身は適当でOK）
//C=ABを計算する（この部分の実行時間を測定する）
//Nと実行時間の関係をグラフにする（計算量との関係は？）

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL); //経過時間
  return tv.tv_sec + tv.tv_usec * 1e-6; //tv_sec:１秒以上の部分　tv_usec:１秒未満の部分
}

int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("usage: %s N\n", argv[0]);
    return -1;
  }
    

  int n = atoi(argv[1]); //atoi 文字列を数値に変換
  double* a = (double*)malloc(n * n * sizeof(double)); // Matrix A
  double* b = (double*)malloc(n * n * sizeof(double)); // Matrix B
  double* c = (double*)malloc(n * n * sizeof(double)); // Matrix C

    
  // Initialize the matrices to some values.
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i * n + j] = i * n + j; //A[i][j]
      b[i * n + j] = j * n + i; //B[i][j]
      c[i * n + j] = 0; //C[i][j]
    }
  }

  double begin = get_time();


  //行列積の計算
  double term;
 

  for(int s=0; s<n; s++){
  for (int t=0; t<n; t++){
  term=0;
  for(int k=0; k<n; k++){
  term = a[s * n + k]* b[k * n + t] + term;

  }
  c[s * n + t] = term;

  }
  }
    
  double end = get_time();
  printf("time: %.6lf sec\n", end - begin);

  // Print C for debugging. Comment out the print before measuring the execution time.
  double sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sum += c[i * n + j];
       printf("c[%d][%d]=%lf\n", i, j, c[i * n + j]);
    }
  }
  // Print out the sum of all values in C.
  // This should be 450 for N=3, 3680 for N=4, and 18250 for N=5.
  printf("sum: %.6lf\n", sum);

  free(a);
  free(b);
  free(c);
  return 0;
}