#include <stdio.h>

typedef struct {
    int denom,numer;
}fracao ;
int mdc(fracao a) {
    int denom = a.denom, numer = a.numer,aux_menor,mdc = 1;
    aux_menor = denom;

    if (denom > numer){
        aux_menor = numer;
    }
        
    
    for (int i = aux_menor;i >= 1;i-- ) {
        if (numer % i == 0 && denom % i == 0){
            mdc = i;
            break;
        }     
    }     
    return mdc;

}

fracao simplifique(fracao a,int mdc) {
    int numer = a.numer,denom = a.denom,num_novo,denom_novo;fracao simplificada;
    num_novo = numer / mdc;
    denom_novo = denom / mdc;
    simplificada.numer = num_novo;
    simplificada.denom = denom_novo;

    return simplificada;
}

double para_real(fracao a) {
    int num = a.numer,denom = a.denom;
    return (double)num/denom;
}

fracao some (fracao a,fracao b) {
    int num1 = a.numer,denom1 = a.denom,num2 = b.numer,denom2 = b.denom,num_novo,denom_novo;fracao somada;
    if (denom1 == denom2) {
        denom_novo = denom1;
        num_novo = num1 + num2;

    }
    else {
        num_novo = (num1*denom2) + (num2*denom1);
        denom_novo = denom1 * denom2;
    }
    somada.numer = num_novo;
    somada.denom = denom_novo;

    return somada;
}




int main() {
    fracao a {10,5};fracao b{4,5},soma;
    soma = some(a,b);
    

    return 0;
}