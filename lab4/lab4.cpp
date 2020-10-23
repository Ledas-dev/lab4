
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

void DFS(int p, int n);
int **M1, *visited;

int main(){
  srand(time(NULL));
  int p;
  float k = 0;
  int n;
  printf("Размер матрицы:\n");
  scanf("%d", &n);
  M1 = (int **)malloc(n*sizeof(int));
  for(int i = 0; i<n;i++){
    M1[i] = (int *)malloc(n*sizeof(int));
  }
  visited = (int *)malloc(n*sizeof(int));
  for(int i = 0; i<n;i++){
    visited[i] = 0;
  }
  printf("Введем матрицу:\n");
  for(int i = 0;i<n;i++){
    for(int j = 0;j<i+1;j++){
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

  for(int i = 0;i<1;i++){
  printf("Выберете вершину с которойъ начанете обход:");
  scanf("%d", &p);
    if(p<=n){
      printf("\nВы проходите");

    }else{
      printf("Выберете новую координату\n");
      i--;
    }
  }
  printf("\n");
    DFS(p, n);
}
void DFS(int p, int n){
  int j;
  printf("%d  ", p);
  visited[p] = 1;
  for(j=0; j<n;j++){
    if(visited[j]==0 && M1[p][j] == 1){
      DFS(j,n);
    }
  }
}
