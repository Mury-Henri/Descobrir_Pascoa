#include <stdio.h>

int main()
{
    int ano, pascoa, pascoa_mes;
    int G, C, X, Z, E, D, N;
    int bissexto = 0;
    //Cálculos nececessários

    scanf ("%d", &ano);

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) //Checa se é bissexto 0_o
    {
        bissexto = 1;
    }

    G = (ano % 19) + 1; //Número Áureo

    C = (ano / 100) + 1; //Século

    X = (3*C) / 4 - 12; //Fator de Correção 1

    Z = (8*C + 5) / 25 - 5; //Fator de Correção 2

    E = (11*G + 20 + Z - X) % 30; //Epacta

    D = (5*ano) / 4 - (X + 10); //Domingo de Páscoa

    if (E == 24 || (E == 25 && G > 11))
    {
        E += 1;
    }

    N = (44 - E);

    if ( N < 21 ) //Lua Cheia (Condição) +_-
    {
        N += 30;
    }

    N += 7 - (D + N) % 7;

    if (N > 31) //Dia e Mês da Páscoa :)
    {
        pascoa = (N - 31);
        pascoa_mes = 4;
        printf ("A Páscoa será no dia %02d/%02d\n", pascoa, pascoa_mes); 

    }
    else
    {
        pascoa = N;
        pascoa_mes = 3;
        printf ("A Páscoa será no dia %02d/%02d\n", pascoa, pascoa_mes);
    }

    int mes [12] = { 31, bissexto ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  };
    //Armazena os dias possiveis e verifica caso fevereiro seja bissexto

    int dia = 0;

    while (!(pascoa == 1 && pascoa_mes == 1)) //Calcula o dia da semana do dia 1º de Janeiro do ano dado
    {
        dia--;

        if (dia < 0) //Olha se o dia da semana é domingo
        {
            dia = 6;
        }

        pascoa--;
        if (pascoa == 0) //Checa se o dia da páscoa é o primeiro do mês
        {
            pascoa_mes--;
            pascoa = mes[pascoa_mes - 1];
        }
        
    }

    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    // Armazena os meses.

    printf ("Calendário do ano %d\n", ano);

    int i = dia;
    int m, d;
    int l, c;

    for (m = 0; m < 12; m++) //Gera o calendário do ano
    {
        int calen [6][7] = {{0}};
        int lin = 0, col = i;

        for (d = 1; d <= mes[m]; d++) //Forma o calendário do mês, checando tudo bonitinho :D
        {
            calen[lin][col] = d;
            col++;

            if (col == 7)

            {
                col = 0;
                lin++;
            }
        }

        printf ("|-----------------------------|\n");

        if (m == 2) //PAra consetar o "ç" de março
        {

        printf ("|%-30s|\n", meses[m]);

        }
        else
        {

        printf ("|%-29s|\n", meses[m]);

        }

        printf ("|-----------------------------|\n");
        
        printf ("| dom seg ter qua qui sex sab |\n"); // Mostra os dias no calendário

        for (l = 0; l < 6; l++) //Calendário do Mês
        {
            printf ("|");
            for (c = 0; c < 7; c++)
            {
                if (calen[l][c] == 0) //MOstra os dias do calendário
                {
                    printf ("  --");
                }
                else
                {
                    printf ("  %02d", calen[l][c]);
                }

            }

            printf (" |\n");
        }

        i = (i + mes[m]) % 7;

    }

    printf ("|-----------------------------|\n");

    return 0;

}

