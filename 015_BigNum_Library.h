typedef struct BigNum BigNum;

struct BigNum{
    char *Content;
    int Length;
    char Flag;
};

char *BigNum_Addition(BigNum, BigNum);
char *BigNum_Subtraction(BigNum, BigNum);
char BigNum_Pretreatment(BigNum *, BigNum *);
void ArrayFix(char *, int *);