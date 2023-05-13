#include <stdio.h>

void tarjeta(int fvict[], int svict[], int fpts[], int spts[], int juez);
void victoria(int fpts[], int spts[], int fvict[], int svict[]);

void main()
{
    int fvict[3] = {0, 0, 0};
    int svict[3] = {0, 0, 0};
    int fpts[3] = {0, 0, 0};
    int spts[3] = {0, 0, 0};
    int i, band, totalf, totals;
    for(i = 0; i < 3; i++)
    {
        printf("\n\nJuez %d\n", i+1);
        tarjeta(fvict, svict, fpts, spts, i);
    }
    printf("Puntajes finales:\n Floyd Maywheater Jr: %d, %d, %d\n Saul Canelo Alvarez: %d, %d, %d\n", fpts[0], fpts[1], fpts[2], spts[0], spts[1], spts[2]);
    printf("Rounds ganados:\n Floyd Maywheater Jr: %d, %d, %d\n Saul Canelo Alvarez: %d, %d, %d\n", fvict[0], fvict[1], fvict[2], svict[0], svict[1], svict[2]);
    victoria(fpts, spts, fvict, svict);
}
void tarjeta(int fvict[], int svict[], int fpts[], int spts[], int juez)
{
    int i, ganador, lona;
    for(i = 1; i <= 12; i++)
    {
        do
        {
            printf("Indique ganador del Round %d. (0: Floyd Maywheater Jr, 1: Saul Canelo Alvarez)\n", i);
            scanf("%d", &ganador);
        }while((ganador < 0)||(ganador > 1));
        if(ganador == 0)
        {
            fvict[juez] = fvict[juez] + 1;
            fpts[juez] = fpts[juez] + 10;
            do
            {
                printf("Indique si Canelo toco la lona en el round. (0: No, 1: Si)\n");
                scanf("%d", &lona);
            }while((lona < 0)||(lona > 1));
            if(lona == 0)
            {
                spts[juez] = spts[juez] + 9;
            }
            else
            {
                spts[juez] = spts[juez] + 7;
            }
        }
        else
        {
            svict[juez] = svict[juez] + 1;
            spts[juez] = spts[juez] + 10;
            do
            {
                printf("Indique si Maywheater toco la lona en el round. (0: No, 1: Si)\n");
                scanf("%d", &lona);
            }while((lona < 0)||(lona > 1));
            if(lona == 0)
            {
                fpts[juez] = fpts[juez] + 9;
            }
            else
            {
                fpts[juez] = fpts[juez] + 7;
            }
        }
    }
}
void victoria(int fpts[], int spts[], int fvict[], int svict[])
{
    float bolsa = 100000;
    int fpromediov = (fvict[0] + fvict[1] + fvict[2]) / 3;
    int spromediov = (svict[0] + svict[1] + svict[2]) / 3;
    int ftotal = fpts[0] + fpts[1] + fpts[2];
    int stotal = spts[0] + spts[1] + spts[2];
    if((fpts[0] > spts[0])&&(fpts[1] > spts[1])&&(fpts[2] > spts[2]))
    {
        printf("El ganador es Floyd Maywheater Jr.\n Tipo de Victoria: Unanime (UD)\n");
        printf("Dinero para Maywheater: %f\nDinero para Canelo: %f", bolsa + (fpromediov * (bolsa * 0.1)), bolsa * 0.4);
    }
    else
    {
        if((fpts[0] < spts[0])&&(fpts[1] < spts[1])&&(fpts[2] < spts[2]))
        {
            printf("El ganador es Saul Canelo Alvarez.\n Tipo de Victoria: Unanime (UD)\n");
            printf("Dinero para Canelo: %f\nDinero para Maywheater: %f", bolsa + (spromediov * (bolsa * 0.1)), bolsa * 0.4);
        }
        else
        {
            if((fpts[0] > spts[0])&&(fpts[1] > spts[1])&&(fpts[2] < spts[2])||(fpts[0] > spts[0])&&(fpts[1] < spts[1])&&(fpts[2] > spts[2])||(fpts[0] < spts[0])&&(fpts[1] > spts[1])&&(fpts[2] > spts[2]))
            {
                printf("El ganador es Floyd Maywheater Jr.\n Tipo de Victoria: Dividida (SD)\n");
                printf("Dinero para Maywheater: %f\nDinero para Canelo: %f", bolsa + (fpromediov * (bolsa * 0.05)), bolsa * 0.4);
            }
            else
            {
                if(((fpts[0] < spts[0])&&(fpts[1] < spts[1])&&(fpts[2] > spts[2]))||((fpts[0] < spts[0])&&(fpts[1] > spts[1])&&(fpts[2] < spts[2]))||((fpts[0] > spts[0])&&(fpts[1] < spts[1])&&(fpts[2] < spts[2])))
                {
                        printf("El ganador es Saul Canelo Alvarez.\n Tipo de Victoria: Dividida (SD)\n");
                        printf("Dinero para Canelo: %f\nDinero para Maywheater: %f", bolsa + (spromediov * (bolsa * 0.05)), bolsa * 0.4);
                }
                else
                {
                    if(((fpts[0] > spts[0])&&(fpts[1] > spts[1])&&(fpts[2] == spts[2]))||((fpts[0] > spts[0])&&(fpts[1] == spts[1])&&(fpts[2] > spts[2]))||((fpts[0] == spts[0])&&(fpts[1] > spts[1])&&(fpts[2] > spts[2])))
                    {
                        printf("El ganador es Floyd Maywheater Jr.\n Tipo de Victoria: Mayoria (MD)\n");
                        printf("Dinero para Maywheater: %f\nDinero para Canelo: %f", bolsa + (fpromediov * (bolsa * 0.15)), bolsa * 0.4);
                    }
                    else
                    {
                        if(((fpts[0] < spts[0])&&(fpts[1] < spts[1])&&(fpts[2] == spts[2]))||((fpts[0] < spts[0])&&(fpts[1] == spts[1])&&(fpts[2] < spts[2]))||((fpts[0] == spts[0])&&(fpts[1] < spts[1])&&(fpts[2] < spts[2])))
                        {
                        printf("El ganador es Saul Canelo Alvarez.\n Tipo de Victoria: Mayoria (MD)\n");
                        printf("Dinero para Canelo: %f\nDinero para Maywheater: %f", bolsa + (spromediov * (bolsa * 0.15)), bolsa * 0.4);
                        }
                        else
                        {
                            if(ftotal > stotal)
                            {
                                printf("El ganador es Floyd Maywheater Jr.\n Tipo de Victoria: Normal\n");
                                printf("Dinero para Maywheater: %f\nDinero para Canelo: %f", bolsa, bolsa * 0.4);
                            }
                            else
                            {
                                if(ftotal < stotal)
                                {
                                    printf("El ganador es Saul Canelo Alvarez.\n Tipo de Victoria: Normal\n");
                                    printf("Dinero para Canelo: %f\nDinero para Maywheater: %f", bolsa, bolsa * 0.4);
                                }
                                else
                                {
                                    printf("No hay ganador. Ha habido un empate\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}