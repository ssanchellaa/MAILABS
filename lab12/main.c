#include <stdio.h>
#include <assert.h>


int dv(int a){
    if (a == 0){
        printf("0000");
        return 0000;
    }
    if (a == 1){
        printf("0001");
        return 0001;
    }
    if (a == 2){
        printf("0010");
        return 0010;
    }
    if (a == 3){
        printf("0011");
        return 0011;
    }
    if (a == 4){
        printf("0100");
        return 0100;
    }
    if (a == 5){
        printf("0101");
        return 0101;
    }
    if (a == 6){
        printf("0110");
        return 0110;
    }
    if (a == 7){
        printf("0111");
        return 0111;
    }
    if (a == 8){
        printf("1000");
        return 1000;
    }
    if (a == 9){
        printf("1001");
        return 1001;
    }
}

void unit_test(){
    assert(dv(2)==0010);
    assert(dv(1)==0001);
    assert(dv(7)==0111);
}

int main()
{
    int num,k,i,cnt;// num � k- ���� �����, cnt-����� ���� � �����
    int *arr;
    int *tarr;

    scanf("%d",&num);

    k = num;
    cnt = 0;

    while(k != 0)       //���� ����� ����� ���������� ���� � �����
    {
        k = k / 10;
        cnt++;//����� ���� � �����
    }

    arr = (int*)malloc(cnt * sizeof(int));
    tarr = (int*)malloc(cnt * sizeof(int));


    for(i=0;i<cnt;i++)
    {
        arr[i] = num%10;      //����� ��������� ����� � �����

        num = num / 10;         //�������� ��� ����� � �����
    }

    for (i = 0; i<cnt; ++i){
        tarr[i] = arr[cnt-1-i];// � ����� ������ ������� ������ arr, �� ��� � ���������� �������
    }
    /*for (i = 0;i<m; ++i){
        printf("%d", tarr[i]);// ������� �� ��� ������ tarr
    }
    printf("\n");*/

    for (i = 0; i<cnt; ++i){

        dv(tarr[i]);

    }

    return 0;
}
