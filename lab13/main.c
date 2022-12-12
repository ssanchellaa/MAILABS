#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h> //дл€ функции tolower(c)

//множество гласных- это объединение множеств, состо€щих из 1 гласной
#define VOWELS ( 1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

//функци€, котора€ будет создавать множество из буквы, котора€ встретитс€
unsigned int char_to_set(char c)
{
    c = tolower(c); //tolower не учитывает регистр буквы,котора€ встретитс€(все делает маленькми)
    if (c < 'a' || c > 'z') {
        return 0;//если не буква-возвращаем пустое множество
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
    int c;//символ, который встречаетс€
    unsigned int letters_set= 0;//будет множество всех встречающихс€ букв

    while ((c = getchar())!= EOF){//считываем символ
        if (c == ' ' || c == ',' || c == '.' || c == '\t' || c== '\n'){
            letters_set = 0;// слово закончилось
        }else if (VOWELS != (char_to_set(c) | VOWELS)){//если символ | согласные = !гласные =>  символ- это согласна€
            if (letters_set == (letters_set | char_to_set(c))){// если letters где хран€тс€ гласные | этот символ = letters => така€ согласна€ уже встречалась
                cnt++;// увеличиваем количества повтор€ющихс€ согласных
            }else{// если согласна€ не встречалась
                letters_set = letters_set | char_to_set(c);// к letters_set добавл€етс€ эта согласна€
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
