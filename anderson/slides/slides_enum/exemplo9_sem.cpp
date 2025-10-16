#include <stdio.h>

struct aluno {
    float p1, p2, po;
    int faltas,dias_letivos;
};

int obter_situacao_aluno (struct aluno a) {
    int ver, dias = a.dias_letivos;
    float media_aproveitamento,p1 = a.p1, p2 = a.p2;
    double porc;
    porc = ((double)a.faltas / dias) *100 ;
    ver = 0;// aprovado


   if (porc >= 25)
   ver = 2;//reprovado por falta
    else {
        if (p1 < p2 && p1 < a.po)
        media_aproveitamento = (p2  + a.po)/2;
        else if (p2 < p1 && p2 < a.po)
        media_aproveitamento = (p1 + a.po)/2;
        else
        media_aproveitamento = (p1 + p2) / 2;
    
    if (media_aproveitamento < 6 )
        ver = 1; // reprovado
    }
    return ver;  
};
int main() {
    struct aluno a[3];
    int dias ,ver ;
    
    for (int i= 0;i < 3;i++){
        a[i].dias_letivos = 100;
        printf("Informe as notas p1,p2,po do aluno %d :\n",i + 1);
        scanf("%f%f%f%*c",&a[i].p1,&a[i].p2,&a[i].po);
        printf("Informe o numero de faltas do aluno %d :\n",i + 1);
        scanf("%d%*c",&a[i].faltas);
        ver = obter_situacao_aluno(a[i]);
        if (ver == 0)
            printf("Aprovado\n");
        else if (ver == 1)
            printf("Reprovado por nota\n");
        else if (ver == 2)
            printf("Reprovado por falta\n");

    };

    return 0;
}

