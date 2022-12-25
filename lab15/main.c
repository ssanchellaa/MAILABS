#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

int Min_el(int i, int min){
    if (i < min){
        min = i;
        }
    return min;
}

void unit_test(){
    assert(Min_el(1,2)==1);
    assert(Min_el(100,2)==2);
}


int main()
{
    unit_test();
    int n;
    scanf("%d", &n);// размер матрицы
    int arr[n][n];//массив элементов матрицы
    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            scanf("%d", &arr[i][j]);//вводим элементы в матрицу
        }
    }
    printf("Initial matrix:\n");
    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            printf("%d ", arr[i][j]);//выводим матрицу
        }
        printf("\n");
    }

    int min = INT_MAX;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            if (arr[i][j] == Min_el(arr[i][j], min)){
                    min = arr[i][j];
            }
        }
    }

    int new_i;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            if (arr[i][j] == min){
                    new_i = i;
                    for (int j = 0; j < n; ++j){
                        arr[new_i][j] = NULL;
                    }
            }
        }
    }
    printf("\n");
    printf("Result:\n");
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (arr[i][j] != NULL){
                printf("%d ", arr[i][j]);
            }
            else{
                break;
            }
        }
    printf("\n");
    }

    return 0;
}
