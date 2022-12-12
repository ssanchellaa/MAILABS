#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h> //��� ������� tolower(c)

//��������� �������- ��� ����������� ��������, ��������� �� 1 �������
#define VOWELS ( 1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

//�������, ������� ����� ��������� ��������� �� �����, ������� ����������
unsigned int char_to_set(char c)
{
    c = tolower(c); //tolower �� ��������� ������� �����,������� ����������(��� ������ ���������)
    if (c < 'a' || c > 'z') {
        return 0;//���� �� �����-���������� ������ ���������
    }else {
        return 1u << (c - 'a');
    }
}

void unit_test(){

    assert(char_to_set('7')== 0);
    assert(char_to_set('a')== 1);
    assert(char_to_set('b')== 2);
    assert(char_to_set('A')== 1);
    assert(char_to_set(' ')== 0);
}

int main(void)
{
    //unit_test();
    char bukv;
    int cnt = 0;
    int c;//������, ������� �����������
    unsigned int letters_set= 0;//����� ��������� ���� ������������� ����

    while ((c = getchar())!= EOF){//��������� ������
        if (c == ' ' || c == ',' || c == '.' || c == '\t' || c== '\n'){
            letters_set = 0;// ����� �����������
        }else if (VOWELS != (char_to_set(c) | VOWELS)){//���� ������ | ��������� = !������� =>  ������- ��� ���������
            if (letters_set == (letters_set | char_to_set(c))){// ���� letters ��� �������� ������� | ���� ������ = letters => ����� ��������� ��� �����������
                cnt++;// ����������� ���������� ������������� ���������
            }else{// ���� ��������� �� �����������
                letters_set = letters_set | char_to_set(c);// � letters_set ����������� ��� ���������
            }
        }
    }

    if (cnt > 0){
        printf("Yes, there is a word in which consonants are repeated\n");
    }else{
        printf("No, there are no words in which consonants are repeated\n");
    }
    return 0;
}
