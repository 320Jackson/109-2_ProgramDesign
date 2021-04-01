#include<stdio.h>

struct Point{
    int x, y;
};
struct Fraction{
    int num, nump, denump;
};

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return GCD(b, a % b);
}

int LCM(int a, int b){
    int GCDNum;
    if(a < b){
        GCDNum = GCD(b, a);
    }
    else{
        GCDNum = GCD(a, b);
    }
    return (a * b) / GCDNum;
}

void Pretreatment(int *Nump, int *Denump){
    if(*Denump < 0){
        *Nump = -(*Nump);
        *Denump = -(*Denump);
    }
}

void Fraction_Handler(struct Fraction *m){
    /*Answer process*/
    char sign = ' ';
    if((*m).nump < 0){
        sign = '-';
        (*m).nump = -(*m).nump;
    }
    (*m).num = (*m).nump / (*m).denump;
    (*m).nump = (*m).nump % (*m).denump;
        
    /*Reduce fraction*/
    if((*m).nump > (*m).denump){
        int GCDNum = GCD((*m).nump, (*m).denump);
        (*m).nump /= GCDNum;
        (*m).denump /= GCDNum;
    }
    else{
        int GCDNum = GCD((*m).denump, (*m).nump);
        (*m).nump /= GCDNum;
        (*m).denump /= GCDNum;
    }
    if(sign == '-'){
        if((*m).num != 0){
            (*m).num = -(*m).num;
        }
        else{
            (*m).nump = -(*m).nump;
        }
    }
}

int main(void){
    struct Point p0, p1;
    scanf("%d,%d", &p0.x, &p0.y);
    scanf("%d,%d", &p1.x, &p1.y);
    
    struct Fraction m, b;
    /*Get slope*/
    m.nump = p1.y - p0.y;
    m.denump = p1.x - p0.x;
    Pretreatment(&m.nump, &m.denump);

    /*Get offset number*/
    b.nump = (p1.x * p0.y) - (p0.x * p1.y);
    b.denump = p1.x - p0.x;
    Pretreatment(&b.nump, &b.denump);
    Fraction_Handler(&m);
    Fraction_Handler(&b);
    
    /*Print answer*/
    printf("y=");
    if(m.num != 0 || m.nump != 0){
        if(m.nump == 0 && m.num == 1){
            printf("x");
        }
        else if(m.num != 0 && m.num == -1){
            printf("-x");
        }
        else if(m.nump == 0 && m.num != 0){
            printf("%dx", m.num);
        }
        else{
            if(m.num == 0){
                printf("%d/%dx", m.nump, m.denump);
            }
            else{
                printf("%d(%d/%d)x", m.num, m.nump, m.denump);
            }
        }
    }
    if(b.num != 0 || b.nump != 0){
        if(b.nump == 0 && b.num != 0){
            if(b.num > 0){
                printf("+%d", b.num);
            }
            else{
                printf("%d", b.num);
            }
        }
        else{
            if(b.num == 0){
                if(b.nump > 0){
                    printf("+%d/%d", b.nump, b.denump);
                }
                else{
                    printf("%d/%d", b.nump, b.denump);
                }
            }
            else{
                if(b.num > 0){
                    printf("+%d(%d/%d)", b.num, b.nump, b.denump);
                }
                else{
                    printf("%d(%d/%d)", b.num, b.nump, b.denump);
                }
            }
        }
    }
}