#include <stdlib.h>
#include "String_Input.h"

#define LIST_SIZE 128
#define BUFFER_SIZE 256

char **SplitStr(char *str_OriginStr, int **SubString_Length, int *ListLength){
    /*Array size control*/
    int int_SubStrSize = BUFFER_SIZE, int_ListSize = LIST_SIZE;
    /*Read words*/
    char **SubString_List = malloc(sizeof(char *) * int_ListSize);
    int **SubString_Length = malloc(sizeof(int *) * int_ListSize);
    char *SubString = malloc(sizeof(char) * int_SubStrSize);
    char *ch_Code = str_OriginStr;
    /*Index*/
    int int_ListIndex = 0, int_SubStrIndex = 0;
    do{
        if(*ch_Code != ' '){
            SubString[int_SubStrIndex++] = *ch_Code;
        }
        else{
            /*Add end char*/
            SubString[int_SubStrIndex] = '\0';
            SubString_Length[int_ListIndex] = int_SubStrIndex;
            /*Reset substring*/
            int_SubStrIndex = 0;
            int_SubStrSize = BUFFER_SIZE;
            /*Add to substring list*/
            SubString_List[int_ListIndex++] = SubString;
            /*Resize substring list*/
            if(int_ListIndex >= int_ListSize){
                int_ListSize += LIST_SIZE;
                SubString_List = realloc(SubString_List, sizeof(char *) * int_ListSize);
                SubString_Length = relloc(SubString_Length, sizeof(int *) * int_ListSize);
            }
        }
        
        /*Resize substring*/
        if(int_SubStrIndex >= int_SubStrSize){
            int_SubStrSize += BUFFER_SIZE;
            SubString = realloc(SubString, sizeof(char) * int_SubStrSize);
        }
        ch_Code++;
    }
    while(*ch_Code != '\0');
    *ListLength = int_ListIndex;
    SubString_List = relloc(SubString_List, sizeof(char *) * int_ListIndex);    
    SubString_Length = relloc(SubString_Length, sizeof(int *) * int_ListIndex);
    return SubString_List;
}