#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int NodeID; 
    int Day;
    int NextNum;
    int *NextList;
    char isWent;
} WorkNode;

int DFS_RunNode(WorkNode *List, int ID, int Destination) {
    WorkNode thisNode = List[ID];
    thisNode.isWent = 'y';
    if (ID == Destination) {
        return thisNode.Day;
    }
    else {
        int Buffer = 0, Step = 0;
        for(int Run = 0; Run < thisNode.NextNum; Run++) {
            if (List[thisNode.NextList[Run] - 1].isWent == 'n') {
                Buffer = thisNode.Day + DFS_RunNode(List, thisNode.NextList[Run] - 1, Destination);
            }
            if (Step < Buffer) {
                Step = Buffer;
            }
        }
        return Step;
    }
}

int main() {
    /*How many test data*/
    int Num;
    scanf("%d", &Num);

    for (int Run = 0; Run < Num; Run++) {
        /*How many work nodes*/
        int N;
        scanf("%d", &N);

        WorkNode *WorkList = malloc(sizeof(WorkNode) * N);
        for (int Inside = 0; Inside < N; Inside++) {
            /*Input work process time, beside node num*/
            WorkList[Inside].NodeID = Inside + 1;
            WorkList[Inside].isWent = 'n';
            scanf("%d%d", &WorkList[Inside].Day, &WorkList[Inside].NextNum);
            WorkList[Inside].NextList = malloc(sizeof(int) * WorkList[Inside].NextNum);
            for (int RunNext = 0; RunNext < WorkList[Inside].NextNum; RunNext++) {
                scanf("%d", &WorkList[Inside].NextList[RunNext]);
            }
        }
        
        printf("%d\n", DFS_RunNode(WorkList, 0, N - 1));

        /*Release RAM space*/
        for (int Inside = 0; Inside < N; Inside++) {
            free(WorkList[Inside].NextList);
        }
        free(WorkList);
    }

    return 0;
}