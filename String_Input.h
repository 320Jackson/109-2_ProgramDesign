typedef struct String String;
struct String{
    char *Content;
    int Length;
};
char *InputStr(int *);
char **SplitStr(char *);