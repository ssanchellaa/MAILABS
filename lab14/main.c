#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int t = 0;
    scanf("%d", &n);// размер матрицы
    int arr[n][n];//массив элементов матрицы
    /*for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            scanf("%d", &arr[i][j]);//вводим элементы в матрицу
        }
    }*/
    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            arr[i][j] = j+1 +t*n;
        }
        ++t;
    }


    int p = 1;//разность строк
    int i, j;
    while (p < n ){//(идем по нижнему треугольнику)
        i = n-1;
        j = n-p;//мен€ютс€ столбцы
        while (i< n && j< n){//идем по диагонали вправо
            printf("%d ", arr[i][j]);
            --i;//диагональ стремитс€ с левого нижнего к правому верхнему углу
            ++j;
        }
        ++p;//увеличиваем разность нужного столбца от n
    }
    while ( p> 0){//начина€ с p=n и p по убыванию
        i = p-1;
        j = 0;
        while (i < n && i >= 0 && j< n){
            printf("%d ", arr[i][j]);
            --i;
            ++j;
        }
        --p;
    }
    printf("\n");

    return 0;
}
