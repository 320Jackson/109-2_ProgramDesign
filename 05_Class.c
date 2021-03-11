#include<stdio.h>
#include<stdlib.h>

typedef struct Course Course;
struct Course{
    int ClassNum;
    int Hrs;
    int *TimeTable;
};

void Conflict(Course *);
int TableJudge(Course, Course);

int main(){
    Course Lesson[3];
    for(int Run = 0; Run < 3; Run++){
        scanf("%d", &Lesson[Run].ClassNum);
        scanf("%d", &Lesson[Run].Hrs);

        Lesson[Run].TimeTable = (int *)malloc(sizeof(int) * Lesson[Run].Hrs);
        for(int Inside = 0; Inside < Lesson[Run].Hrs; Inside++){
            scanf("%d", &Lesson[Run].TimeTable[Inside]);
        }
    }

    Conflict(Lesson);
    return 0;
}

void Conflict(Course *Lesson){
    for(int Outside = 0; Outside < 2; Outside++){
        for(int Inside = Outside + 1; Inside < 3; Inside++){
            int Flag = TableJudge(Lesson[Outside], Lesson[Inside]);
            if(Flag == 1){
                return;
            }
        }
    }
}

int TableJudge(Course First, Course Second){
    for(int Outside = 0; Outside < First.Hrs; Outside++){
        for(int Inside = 0; Inside < Second.Hrs; Inside++){
            if(First.TimeTable[Outside] == Second.TimeTable[Inside]){
                printf("%d and %d conflict on %d", First.ClassNum, Second.ClassNum, First.TimeTable[Outside]);
                return 1;
            }
        }
    }
    return 0;
}