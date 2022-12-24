#include "funkcje_kol_ratunkowych.h"

#define max_znakow 100
#define ile_pytan 13

void graj()
{
    srand(time(NULL));
    int wynik=0,ile=0,nr=0,tabela_nr_pytan[ile_pytan]={0,0,0,0,0,0,0,0,0,0,0,0,0},kolo1=1,kolo2=1,kolo3=1;
    char znak,pytanie[max_znakow],odpA[max_znakow],odpB[max_znakow],odpC[max_znakow],odpD[max_znakow],popodp[2];
    FILE *plik=fopen("pytania","r");
    if(plik==NULL)
    {
        czysc();
        printf("Nie udalo sie otworzyc listy pytan do odczytu! Powrot do menu!"); sleep(3);
        czysc();
        main();
    }
    while(!feof(plik))      //licza pytania z pliku
    {
        znak=getc(plik);
        if(znak=='\n') ++ile;
    }
    fclose(plik);
    for(int i=0;i<ile_pytan;i++)        //z puli pytan wybiera 13 losowych numerow pytan
    {                       //do gry potrzeba 12 pytan trzynaste uzywane jest w przypadku kola zmiany pytania
        nr=rand()%(ile/6)+1;
        while(czy_bylo_to_pytanie(nr,tabela_nr_pytan))      //sprawdza czy numer nie zostal wylosowany wczesniej
        {
            nr=rand()%(ile/6)+1;
        }
        tabela_nr_pytan[i]=nr;
    }
    for(int i=0;i<ile_pytan;i++)        //petla wyswietla kolejne pytania, zmienna i oznacza numer pytania
    {
        czysc();
        printf("Pytanie nr %d\n",i+1);
        pasek();
        plik=fopen("pytania","r");      //otwiera plik z pula pytan
        if(plik==NULL)      //w przypadku bledu wyswietla komunikat i powraca do funkcji glownej
        {
            czysc();
            printf("Nie udalo sie otworzyc listy pytan do odczytu! Powrot do menu!"); sleep(3);
            czysc();
            main();
        }
        for(int j=0;j<(tabela_nr_pytan[i]*6)-6;j++)     //w tej petli opuszczamy w pliku kolejne wirsze
        {                                               //do momentu gdy trafimy na numer pytania zawarty
            znak=getc(plik);                            //pod i-tym indeksem w tabeli "tabela_nr_pytan"
            while(znak!='\n')
            {
                znak=getc(plik);
            }
        }
        fscanf(plik,"%[^\n]",pytanie); przesun_o_jedna_linie(znak,plik);    //pobiera z pliku tresc pytanie,mozliwych opd i [poprawnej
        fscanf(plik,"%[^\n]",odpA); przesun_o_jedna_linie(znak,plik);
        fscanf(plik,"%[^\n]",odpB); przesun_o_jedna_linie(znak,plik);
        fscanf(plik,"%[^\n]",odpC); przesun_o_jedna_linie(znak,plik);
        fscanf(plik,"%[^\n]",odpD); przesun_o_jedna_linie(znak,plik);
        fscanf(plik,"%[^\n]",popodp); przesun_o_jedna_linie(znak,plik);
        fclose(plik);   //zamyka plik
        printf("%s\n",pytanie);     //wyswietla kolejno pytanie, odp i pop
        printf("A. %s\n",odpA);
        printf("B. %s\n",odpB);
        printf("C. %s\n",odpC);
        printf("D. %s\n",odpD);
        pasek();
        if(kolo1==1||kolo2==1||kolo3==1)    //wyswietla dostepne kola ratunkowe
        {
            printf("Dostepne kola ratunkowe to: \n");
            if(kolo1==1) printf("1. 50 na 50 \n");
            if(kolo2==1) printf("2. Zamiana pytania \n");
            if(kolo3==1) printf("3. Telefon do przyjaciela \n");
        }
        else
        {
            printf("Brak dostepnych kol ratunkowych.\n");   //W przypadku zuzycia wszystkich kol wyswietla komunikat
        }
        pasek();
        printf("Twoj wybor: "); znak=getchar(); getchar();      //pobiera odpowiedz uzytkownika
        while(!(znak>=49&&znak<=51)&&!(znak>=65&&znak<=68)&&!(znak>=97&&znak<=100)) //dopuki wybrano znak spoza a-d,A-D,1-3 wyswietla komunikat i prosi o kolejna probe
        {
            printf("Wybrano odpowiedz z poza zakresu! Prosze sprobowac ponownie! Twoj wybor: ");
            znak=getchar(); getchar();
        }
        if((znak>=97)&&(znak<=100)) //jesli uzytkownik wpisal mala litera a-d program zmiania ja na wielka A-D
        {
            znak=znak-32;
        }
        printf("\n");
        if(znak>=49&&znak<=51)      //jesli wybral 1-3 to:
        {
            if(znak==49)    //jesli jest dostepne, wypokuje sie funkcja piedziesiat_na_piedziesiat
            {
                if(kolo1==1)
                {
                    znak=piedziesiat_na_piedziesiat(i+1,pytanie,odpA,odpB,odpC,odpD,popodp,znak);
                    kolo1=0;        //nastepnie kolo zeruje sie - stad wiadomo ze bylo juz wykorzystane
                }
                else
                {
                    brak_dostepnego_kola(); //jesli kolo bylo juz wykorzystane program przechodzi do funkcji
                    i--;        //nastepnie cofa pytanie, dzieki czemu wyswietli sie jeszcze raz
                    continue;
                }
            }
            if(znak==50)
            {
                if(kolo2==1)    //jesli kolo zmiany pytania jest dostepne:
                {
                    for(int i=3;i>0;i--)
                    {
                        czysc();
                        printf("Wybrano kolo ratunkowe zamiana pytania! Pytanie zostanie wylosowane za %d...",i);
                        sleep(1);
                    }
                    tabela_nr_pytan[i]=tabela_nr_pytan[ile_pytan-1];   //numer pytania zmiania sie na numer pod ostatnia pozycja w tabeli "tabela_nr_pytan"
                    kolo2=0;
                    i--;        //dzieki temu wyswietli sie dodatkowe pytanie
                    continue;
                }
                else
                {
                    brak_dostepnego_kola();
                    i--;
                    continue;
                }

            }
            if(znak==51)    //wyswietla sie funkca telefonu do przyjaciela
            {
                if(kolo3==1)
                {
                    telefon_do_przyjaciela(pytanie,odpA,odpB,odpC,odpD,popodp);
                    kolo3=0;
                    i--;
                    continue;
                }
                else
                {
                    brak_dostepnego_kola();
                    i--;    //ponownie wyswietla sie to samo pytanie
                    continue;
                }
            }
        }
        if(popodp[0]==znak) //jesli odp jest poprawna to w zaleznosci od poziomu gry gracz osiaga pewna kwote
        {
            if(i==0) wynik=500;
            else if(i==3) wynik=5000;
            else if(i==7) wynik=75000;
            else if(i==8) wynik=125000;
            else wynik*=2;
            printf("Prawidlowa odpowiedz! Twoj akutalny wynik to: %d \n",wynik);
            if(i==1)
            {
                pasek();
                printf("$$$ Gratulacje! Osiagnoles gwarantowany prog!                                                    $$$\n$$$ Od tego momentu w przypadku przegranej nie wychodzisz z pustymi rekami!                      $$$\n");
                pasek();
            }
            if(i==6)
            {
                pasek();
                printf("$$$ Gratulacje! Osiagnoles kolejny gwarantowany prog!                                            $$$\n");
                pasek();
            }
            printf("Kontynuowac? (Wcisnij dowolny klawisz)");
            getch();
            if(wynik==1000000)
            {
                koniec(wynik);
                break;
            }
        }
        else
        {
            printf("Niestety nie byla to prawidlowa odpowiedz, poprawna to %s.\n",popodp);
            printf("Wcisnij dowolny klawisz aby kontynuowac..."); getch();
            koniec(wynik);
            break;
        }
    }
}
 //funkcja oznajmia wygrana glownej nagrody, gwarantowanej kwoty lub przegranej nastepnie za pomoca funkcji sprawdz_czy
 // sprawdza czy wynik moze trafic do rankingu
void koniec(int wynik)
{
    int wybor;
    czysc();
    if(wynik==1000000)
    {
        printf("Gratulacje wygrales Programisterow! Zgarniasz 1,000,000 PESOS MEKSYKANSKICH! \n\n");
    }
    else if(wynik<1000000&&wynik>=40000)
    {
        printf("Niestety przegrales! Zgarniasz jedynie 40,000 PESOS MEKSYKANSKICH! \n\n");
    }
    else if(wynik<40000&&wynik>=1000)
    {
        printf("Niestety przegrales! Zgarniasz jedynie 1,000 PESOS MEKSYKANSKICH! \n\n");
    }
    else
    {
        printf("Niestety przegrales! Nic nie zyskujesz! \n\n");
    }
    if(sprawdz_czy(wynik))
    {
       printf("Czy chcesz zapisac swoj wynik? \n");
        printf("1. Tak \n");
        printf("2. Nie \n");
        wybor=getch();
        switch(wybor)       //jezeli wynik kwalifikuje sie do rankingu gracz ma taka mozliwosc
        {
            case 49:
            {
                zapisz_wynik(wynik);        //wyswietla menu zapisu wyniku do rankingu
                break;
            }
            case 50:
            {
                powrot();       //wyswietla menu powrotu do funkcji glownej lub zakonczenia programu
                break;
            }
            default:        //w przypadkuy niewllasciwej odswieza funkcje konca
            {
                for(int i=3;i>0;i--)
                {
                    czysc();
                    printf("Podano nie prawidlowa wartosc! Program odswiezy sie za: %d \n",i);
                    sleep(1);
                }
                czysc();
                koniec(wynik);
                break;
            }
        }
    }
    powrot();       //jezeli wynik niekwalifikuje sie do rankingu program wyswietla menu powrotu do main badz zakonczenia programu
}

int czy_bylo_to_pytanie(int nr,int tabela[ile_pytan])       //sprawdza czy numer (nr) znajduje sie w tabeli
{
    int t=0;
    for(int i=0;i<ile_pytan;i++)
    {
        if(tabela[i]==nr)
        {
            t=1;
            break;
        }
    }
    if(t==1) return true;
    else return false;
}

void przesun_o_jedna_linie(char znak,FILE *plik)        //funkcja przesuwa kursor do nastepnej lini
{
    znak=getc(plik);
    while(znak!='\n')
    {
        znak=getc(plik);
    }
}

void powrot()
{
    int wybor;
    czysc();
    printf("1. Powrot do menu \n");
    printf("2. Zakoncz program \n");
    wybor=getch();
    switch(wybor)       //w zaleznoœci od wyboru:
    {
        case 49:
        {
            czysc();
            main();     //trafiamy do main
            break;
        }
        case 50:
        {
            zakoncz(3);     //trafiamy do menu konca programu
            break;
        }
        default:
        {
            for(int i=3;i>0;i--)
            {
                czysc();
                printf("Podano nie prawidlowa wartosc! Program odswiezy sie za: %d \n",i);
                sleep(1);
            }
            czysc();
            powrot();       //odswieza siê funkcja powrot
            break;
        }
    }
}

void brak_dostepnego_kola()     //w przypadku gdy uzytkownik chce uzyc niedostepne kolo wyswietla sie komunikat
{
    for(int k=5;k>0;k--)
    {
        czysc();
        printf("Wybrano zuzyte kolo ratunkowe! Pytanie sie odswiezy za: %d",k);
        sleep(1);
    }
}
