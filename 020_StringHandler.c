#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String_Input.h"
#define LIST_SIZE 512
void AddOutput(char **, char *, char *, int);
void ReplaceOutput(char **, char *, char *, int);
void StrFrequency(char **, int);
void Sort(String *, int);

int main(){
    /*Get input strings*/
    String str_Article, str_WordA, str_WordB;
    str_Article.Content = InputStr(&str_Article.Length);
    str_WordA.Content = InputStr(&str_WordA.Length);
    str_WordB.Content = InputStr(&str_WordB.Length);
    /*Split original string*/
    int *SubLength;
    int ListLength;
    char **SubString = SplitStr(str_Article.Content, SubLength, &ListLength);
    ReplaceOutput(SubString, str_WordA.Content, str_WordB.Content, ListLength);
    AddOutput(SubString, str_WordA.Content, str_WordB.Content, ListLength);
    ReplaceOutput(SubString, str_WordA.Content, "", ListLength);
    StrFrequency(SubString, ListLength);

    /*Release memory*/
    for(int Run = 0; Run < ListLength; Run++){
        free(SubString[Run]);
    }
    free(SubString);
    free(str_Article.Content);
    free(str_WordA.Content);
    free(str_WordB.Content);
    return 0;
}

void Sort(String *WordTimes, int Limit){
    for(int Outside = 0; Outside < Limit; Outside++){
        for(int Inside = 0; Inside < Limit; Inside++){
            if(WordTimes[Inside].Length < WordTimes[Outside].Length){
                String Change = WordTimes[Outside];
                WordTimes[Outside] = WordTimes[Inside];
                WordTimes[Inside] = Change;
            }
            else if(WordTimes[Inside].Length == WordTimes[Outside].Length){
                if(strcmp(WordTimes[Inside].Content, WordTimes[Outside].Content) > 0){
                    String Change = WordTimes[Outside];
                    WordTimes[Outside] = WordTimes[Inside];
                    WordTimes[Inside] = Change;
                }
            }
        }
    }
}

void StrFrequency(char **SubString, int Length){
    int WordType = LIST_SIZE;
    int Limit = 0;
    String *WordTimes = malloc(sizeof(String) * WordType);
    for(int Run = 0; Run < Length; Run++){
        int Inside;
        for(Inside = 0; Inside < Limit; Inside++){
            if(strcmp(SubString[Run], WordTimes[Inside].Content) == 0){
                WordTimes[Inside].Length++;
                break;
            }
        }
        if(Limit > Inside && strcmp(SubString[Run], WordTimes[Inside].Content) == 0){
            continue;
        }
        WordTimes[Limit].Content = SubString[Run];
        WordTimes[Limit++].Length = 1;
    }
    Sort(WordTimes, Limit);
    for(int Run = 0; Run < Limit; Run++){
        printf("%s : %d\n", WordTimes[Run].Content, WordTimes[Run].Length);
    }
    free(WordTimes);
}

void ReplaceOutput(char **SubString, char *WordA, char *WordB, int Length){
    for(int Run = 0; Run < Length; Run++){
        if(strcmp(SubString[Run], WordA) == 0){
            printf("%s", WordB);
        }
        else{
            printf("%s", SubString[Run]);
        }
        if(Run < Length - 1 && (strcmp(WordB, "") != 0 || strcmp(SubString[Run], WordA) != 0)){
            printf(" ");
        }
    }
    printf("\n");
    return;
}

void AddOutput(char **SubString, char *WordA, char *WordB, int Length){
    for(int Run = 0; Run < Length; Run++){
        if(strcmp(SubString[Run], WordA) == 0){
            printf("%s %s", WordB, SubString[Run]);
        }
        else{
            printf("%s", SubString[Run]);
        }
        if(Run < Length - 1){
            printf(" ");
        }
    }
    printf("\n");
    return;
}