#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int t = 0;
    scanf("%d", &n);// ������ �������
    int arr[n][n];//������ ��������� �������
    /*for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            scanf("%d", &arr[i][j]);//������ �������� � �������
        }
    }*/
    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j){
            arr[i][j] = j+1 +t*n;
        }
        ++t;
    }


    int p = 1;//�������� �����
    int i, j;
    while (p < n ){//(���� �� ������� ������������)
        i = n-1;
        j = n-p;//�������� �������
        while (i< n && j< n){//���� �� ��������� ������
            printf("%d ", arr[i][j]);
            --i;//��������� ��������� � ������ ������� � ������� �������� ����
            ++j;
        }
        ++p;//����������� �������� ������� ������� �� n
    }
    while ( p> 0){//������� � p=n � p �� ��������
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
