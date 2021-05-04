typedef struct BigNum BigNum;

struct BigNum{
    char *Content;
    int Length;
};

//BigNum BigNum_Addition(BigNum, BigNum);
BigNum BigNum_Subtraction(BigNum, BigNum, int);
char BigNum_Pretreatment(BigNum *, BigNum *, int *);
char BigNum_Comparison(BigNum *, BigNum *);
void Complement(char *, int *);
void ZeroFix(char *, int *);
void ArrayFix(char *, int *);