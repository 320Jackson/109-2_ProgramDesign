#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String_Input.h"

typedef struct Point Point;
struct Point{
    int x, y;
};

int Expression(String str_Expression, int StartIndex, Point StartPoint, int Width, int **Picture){
    Point EndPoint = {StartPoint.x + Width, StartPoint.y + Width}; /*Get end location*/
    int Run, Count = 0;
    for(Run = StartIndex; Run < str_Expression.Length; Run++){
        if(Count == 4){
            break;
        }
        if(str_Expression.Content[Run] == '1'){
            /*Black block*/
            for(int y = StartPoint.y; y < EndPoint.y; y++){
                for(int x = StartPoint.x; x < EndPoint.x; x++){
                    Picture[y][x] = 1;
                }
            }
        }
        else if(str_Expression.Content[Run] == '2'){
            /*Both block*/
            Run = Expression(str_Expression, Run + 1, StartPoint, Width / 2, Picture) - 1;
        }

        /*Change start point*/
        if(Count % 2 == 0){
            StartPoint.x += Width;
        }
        else{
            StartPoint.x -= Width;
            StartPoint.y += Width;
            EndPoint.y = StartPoint.y + Width;
        }
        EndPoint.x = StartPoint.x + Width;
        Count++;
    }
    return Run;
}

int main(void){
    /*Input information*/
    String str_DF; /*DF-expression string*/
    int int_picWidth; /*Picture Width*/
    str_DF.Content = InputStr(&str_DF.Length);
    scanf("%d", &int_picWidth);

    /*Initialization picture information array*/
    int **Picture = malloc(sizeof(int *) * int_picWidth);
    for(int Run = 0; Run < int_picWidth; Run++){
        Picture[Run] = malloc(sizeof(int) * int_picWidth);
    }
    
    /*All white*/
    if(strcmp(str_DF.Content, "0") == 0){
        printf("all white\n");
    }
    else{
        Point InitPoint = {0, 0};
        Expression(str_DF, 0, InitPoint, int_picWidth, Picture);
    }
    
    /*Release RAM space*/
    free(str_DF.Content);
    for(int Outside = 0; Outside < int_picWidth; Outside++){
        for(int Inside = 0; Inside < int_picWidth; Inside++){
            if(Picture[Outside][Inside] == 1){
                printf("%d,%d\n", Outside, Inside);
            }
        }
        free(Picture[Outside]);
    }
    free(Picture);
    return 0;
}