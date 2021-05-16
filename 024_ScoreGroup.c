#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "024_ScoreGroup.h"

typedef struct Student_Score {
    int StuID;
    Score *ScoreInfo;
    int TotalScore;
    int AvgScore;
} Student;

G_Group getScore(G_Group x) {
    return x;
}

int main() {
    /*How many class*/
    int M, StuNum;
    scanf("%d", &M);
    
    /*Scoring method*/
    char **Method = malloc(sizeof(char *) * M);
    for (int Run = 0; Run < M; Run++) {
        Method[Run] = malloc(sizeof(char) * 4);        
        scanf("%s", Method[Run]);
    }
    /*How many students*/
    scanf("%d", &StuNum);

    Student *StuList = malloc(sizeof(Student) * StuNum);
    for (int Run = 0; Run < StuNum; Run++) {
        scanf("%d", &StuList[Run].StuID);
        StuList[Run].ScoreInfo = malloc(sizeof(Score) * M);\
        StuList[Run].TotalScore = 0;
        for (int Inside = 0; Inside < M; Inside++) {
            if (strcmp(Method[Inside], "G") == 0) {
                scanf("%s", &StuList[Run].ScoreInfo[Inside]);
                if (strcmp(StuList[Run].ScoreInfo[Inside].str, "A+") == 0) {
                    StuList[Run].TotalScore += getScore(A1);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "A") == 0) {
                    StuList[Run].TotalScore += getScore(A);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "A-") == 0) {
                    StuList[Run].TotalScore += getScore(A0);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "B+") == 0) {
                    StuList[Run].TotalScore += getScore(B1);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "B") == 0) {
                    StuList[Run].TotalScore += getScore(B);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "B-") == 0) {
                    StuList[Run].TotalScore += getScore(B0);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "C+") == 0) {
                    StuList[Run].TotalScore += getScore(C1);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "C") == 0) {
                    StuList[Run].TotalScore += getScore(C);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "C-") == 0) {
                    StuList[Run].TotalScore += getScore(C0);
                }
                else {
                    StuList[Run].TotalScore += getScore(F);
                }
            }
            else if (strcmp(Method[Inside], "GPA") == 0) {
                scanf("%lf", &StuList[Run].ScoreInfo[Inside]);
                if (StuList[Run].ScoreInfo[Inside].GPA == 4.3) {
                    StuList[Run].TotalScore += getScore(A1);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 4.0) {
                    StuList[Run].TotalScore += getScore(A);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 3.7) {
                    StuList[Run].TotalScore += getScore(A0);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 3.3) {
                    StuList[Run].TotalScore += getScore(B1);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 3.0) {
                    StuList[Run].TotalScore += getScore(B);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 2.7) {
                    StuList[Run].TotalScore += getScore(B0);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 2.3) {
                    StuList[Run].TotalScore += getScore(C1);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 2.0) {
                    StuList[Run].TotalScore += getScore(C);
                }
                else if (StuList[Run].ScoreInfo[Inside].GPA == 1.7) {
                    StuList[Run].TotalScore += getScore(C0);
                }
                else {
                    StuList[Run].TotalScore += getScore(F);
                }
            }
            else if (strcmp(Method[Inside], "S") == 0) {
                scanf("%s", &StuList[Run].ScoreInfo[Inside]);
                if (strcmp(StuList[Run].ScoreInfo[Inside].str, "90-100") == 0) {
                    StuList[Run].TotalScore += getScore(A1);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "85-89") == 0) {
                    StuList[Run].TotalScore += getScore(A);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "80-84") == 0) {
                    StuList[Run].TotalScore += getScore(A0);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "77-79") == 0) {
                    StuList[Run].TotalScore += getScore(B1);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "73-76") == 0) {
                    StuList[Run].TotalScore += getScore(B);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "70-72") == 0) {
                    StuList[Run].TotalScore += getScore(B0);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "67-69") == 0) {
                    StuList[Run].TotalScore += getScore(C1);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "63-66") == 0) {
                    StuList[Run].TotalScore += getScore(C);
                }
                else if (strcmp(StuList[Run].ScoreInfo[Inside].str, "60-62") == 0) {
                    StuList[Run].TotalScore += getScore(C0);
                }
                else {
                    StuList[Run].TotalScore += getScore(F);
                }
            }
        }
        StuList[Run].AvgScore = round((double)StuList[Run].TotalScore / (double)M);
    }

    for (int Outside = 0; Outside < StuNum; Outside++) {
        for (int Inside = 0; Inside < StuNum; Inside++) {
            if (Outside == Inside) {
                continue;
            }
            if (StuList[Outside].AvgScore > StuList[Inside].AvgScore) {
                Student Buffer = StuList[Inside];
                StuList[Inside] = StuList[Outside];
                StuList[Outside] = Buffer;
            }
        }
    }
    
    for (int Run = 0; Run < 3; Run++) {
        printf("%d\n%d\n", StuList[Run].StuID, StuList[Run].AvgScore);
    }

    /*Release RAM space*/
    for (int Run = 0; Run < StuNum; Run++) {
        free(StuList[Run].ScoreInfo);
    }
    free(StuList);
    for (int Run = 0; Run < M; Run++) {
        free(Method[Run]);
    }
    free(Method);
    return 0;
}