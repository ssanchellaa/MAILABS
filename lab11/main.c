#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int all_number(char c)
{
    return (c>= '0' && c<='9');
}

int less_number(char c, char num_arr)
{
    return (c>= '0' && c<='9' && c< num_arr);
}

int more_number(char c, char num_arr)
{
    return (c>= '0' && c<='9' && c> num_arr);
}

int equal_number(char c, char num_arr)
{
    return (c>= '0' && c<='9' && c== num_arr);
}

int gap(char c)
{
    return (c==' ' || c== '\t' || c==',' || c== '\n');
}

int bukv(char c)
{
    return (!(all_number(c))&& !(gap(c)));
}

int main(void)
{
    printf("%d\n", INT_MAX);
    int int_max = INT_MAX;

    int i= 0;
    int tarr[10] = {0};
    int arr[10] = {};

    while (int_max != 0)
    {
        tarr[i] = int_max % 10;// ������� ������� �� ��� ����=> ��� ���� ������������ � �������� ������� � tarr
        ++i;
        int_max /= 10;
    }
    for (; i!= 0; --i)
    {
        arr[10 -i] = tarr[i-1]; // ������� ��� ���� � arr
    }
    printf("Input: ");

    int state = 1;
    int k;
    char symbol;
    char all[20] = " "; //��� ����� ��������� ��� �����
    int top = 0;//top - ��� ������ ������� all
    while ((symbol = getchar()) != EOF){
        switch (state) {
            case 1:
                if (less_number(symbol,arr[0])){
                    top = 0;
                    memset (all, ' ', 20-1);
                    all[top] = symbol;
                    ++top;
                    state = 2;
                }else if (equal_number(symbol, arr[0])){
                    top = 0;
                    memset (all, ' ', 20-1);
                    all[top] = symbol;
                    ++top;
                    state = 222;
                }else if (more_number(symbol, arr[0])){
                    top = 0;
                    memset (all, ' ', 20-1);
                    all[top] = symbol;
                    ++top;
                    state = 22;
                }else if (gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    top = 0;
                    memset (all, ' ', 20-1);
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }

                break;
            case 0:
                if (gap(symbol)){
                    printf("%s\n", all);
                    state= 1;

                }else{
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 2:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 3;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 222:
                if (less_number(symbol,arr[1])){
                    all[top] = symbol;
                    ++top;
                    state = 3;
                }else if (equal_number(symbol, arr[1])){
                    all[top] = symbol;
                    ++top;
                    state = 333;
                }else if (more_number(symbol, arr[1])){
                    all[top] = symbol;
                    ++top;
                    state = 33;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 22:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 33;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 3:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 4;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 333:
                if (less_number(symbol,arr[2])){
                    all[top] = symbol;
                    ++top;
                    state = 4;
                }else if (equal_number(symbol, arr[2])){
                    all[top] = symbol;
                    ++top;
                    state = 444;
                }else if (more_number(symbol, arr[2])){
                    all[top] = symbol;
                    ++top;
                    state = 44;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 33:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 44;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 4:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 5;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 444:
                if (less_number(symbol,arr[3])){
                    all[top] = symbol;
                    ++top;
                    state = 5;
                }else if (equal_number(symbol, arr[3])){
                    all[top] = symbol;
                    ++top;
                    state = 555;
                }else if (more_number(symbol, arr[3])){
                    all[top] = symbol;
                    ++top;
                    state = 55;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 44:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 55;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 5:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 6;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 555:
                if (less_number(symbol,arr[4])){
                    all[top] = symbol;
                    ++top;
                    state = 6;
                }else if (equal_number(symbol, arr[4])){
                    all[top] = symbol;
                    ++top;
                    state = 666;
                }else if (more_number(symbol, arr[4])){
                    all[top] = symbol;
                    ++top;
                    state = 66;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 55:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 66;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 6:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 7;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 666:
                if (less_number(symbol,arr[5])){
                    all[top] = symbol;
                    ++top;
                    state = 7;
                }else if (equal_number(symbol, arr[5])){
                    all[top] = symbol;
                    ++top;
                    state = 777;
                }else if (more_number(symbol, arr[5])){
                    all[top] = symbol;
                    ++top;
                    state = 77;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 66:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 77;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 7:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 8;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 777:
                if (less_number(symbol,arr[6])){
                    all[top] = symbol;
                    ++top;
                    state = 8;
                }else if (equal_number(symbol, arr[6])){
                    all[top] = symbol;
                    ++top;
                    state = 888;
                }else if (more_number(symbol, arr[6])){
                    all[top] = symbol;
                    ++top;
                    state = 88;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 77:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 88;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 8:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 9;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 888:
                if (less_number(symbol,arr[7])){
                    all[top] = symbol;
                    ++top;
                    state = 9;
                }else if (equal_number(symbol, arr[7])){
                    all[top] = symbol;
                    ++top;
                    state = 999;
                }else if (more_number(symbol, arr[7])){
                    all[top] = symbol;
                    ++top;
                    state = 99;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 88:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 99;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 9:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 10;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 999:
                if (less_number(symbol, arr[8])){
                    all[top] = symbol;
                    ++top;
                    state = 10;
                }else if (equal_number(symbol, arr[8])){
                    all[top] = symbol;
                    ++top;
                    state = 101010;
                }else if (more_number(symbol, arr[8])){
                    all[top] = symbol;
                    ++top;
                    state = 1010;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 99:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 1010;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 10:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 11;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 101010:
                if (less_number(symbol,arr[9])){
                    all[top] = symbol;
                    ++top;
                    state = 11;
                }else if (equal_number(symbol, arr[9])){
                    all[top] = symbol;
                    ++top;
                    state = 111111;
                }else if (more_number(symbol, arr[9])){
                    all[top] = symbol;
                    ++top;
                    state = 12;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 1010:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 12;
                }else if(gap(symbol)){
                    state = 1;
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 11:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 12; // � 12 ��������� ����� > max_int
                }else if(gap(symbol)){
                    //top = top_old;
                    state = 1; // ������ ��� ����� max_int => ��������� � ���������� �����

                }else if (bukv(symbol)){
                    //top = top_old;
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;
            case 111111:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 12; // � 12 ��������� ����� > max_int
                }else if(gap(symbol)){
                    state = 1; // � 13 ��������� ����� ������ ��� ����� max_int
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

            case 12:
                if (all_number(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 12; // � 12 ��������� ����� > max_int
                }else if(gap(symbol)){
                    printf("%s\n", all);
                    state = 1;// ����� ��������� �������, ��������� � 1 ���������, ����� ��������� ��������� �����
                }else if (bukv(symbol)){
                    all[top] = symbol;
                    ++top;
                    state = 0;
                }
                break;

        }
    }
    return 0;
}
