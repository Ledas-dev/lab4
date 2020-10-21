
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

void DFS(int i, int n);
int M1[10][10], visited[10] = {0};

int main(){
  srand(time(NULL));
  int i = 0, j;
  float k = 0;
  int n = rand()%10 + 3;
  printf("Введем матрицу:\n");
  for(i = 0;i<n;i++){
    for(j = 0;j<i+1;j++){
      k = rand()%2;
      if(i != j){
        M1[i][j] = k;
        M1[j][i] = k;
      }else{
        M1[i][j] = 0;
      }
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      printf("%d ",M1[i][j] );
    }
    printf("\n");
  }
  printf("\n");
    DFS(0, n);
}
void DFS(int i, int n){
  int j;
  printf("%d  ", i);
  visited[i] = 1;
  for(j=0; j<n;j++){
    if(visited[j]==0 && M1[i][j] == 1){
      DFS(j,n);
    }
  }
}
