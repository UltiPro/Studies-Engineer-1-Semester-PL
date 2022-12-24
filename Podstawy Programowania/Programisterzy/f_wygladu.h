#define SK 100
#define WK 5
#define LOGO 15

void wypisz_logo()      //funkcja wypisuje logo: tabela o wymiarach 100 x 5 z³o¿on¹ z "*", wewn¹trz której widnieje nazwa gry
{
    char logo[LOGO]="PROGRAMISTERZY";
    for(int i=0;i<WK;i++)
    {
        for(int j=0;j<SK;j++)
        {
            if(i==0||i==WK-1)
            {
                if(j!=SK-1) printf("*");
                else printf("*\n");
            }
            else if(i==(WK/2)&&((j>=SK/2-(LOGO/2-1))&&(j<=SK/2+(LOGO/2))))
            {
                printf("%c",logo[j-(SK/2-(LOGO/2-1))]);
            }
            else
            {
                if(j==0) printf("*");
                else if(j==SK-1) printf("*\n");
                else printf(" ");
            }
        }
    }
}

void czysc()       //funkcja czyœci ekran
{
    system("cls");
}

void pasek()        //funkcja wypisuje pasek o d³ugoœci 99 z³o¿ony z "-"
{
    for(int i=0;i<SK;i++)
    {
        printf("-");
        if(i==SK-1) printf("\n");
    }
}

