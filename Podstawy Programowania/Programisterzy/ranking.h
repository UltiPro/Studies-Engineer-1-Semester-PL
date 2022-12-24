struct rank     // struktura dzieki której zapamietujemy dane do rankingu
{
    char nazwa[20]; //Pseudonim gracza
    int punkty;     //ilosc jego punktów
    int rok;        //rok miesiąc i dzieñ - data wpisu do rankingu
    int miesiac;
    int dzien;
} tablica_dziesieciu_wynikow[10];

void ranking()      //Wypisuje ranking 10 najlepszych graczy
{
    czysc();
    pobierz_ranking(tablica_dziesieciu_wynikow);
    pasek();
    printf("TOP 10 Najlepszych zawodnikow Programisterow!!! \n");
    pasek(); printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("%d. %s, wynik: %d, data: %d-%02d-%02d \n",i+1,tablica_dziesieciu_wynikow[i].nazwa,
        tablica_dziesieciu_wynikow[i].punkty,tablica_dziesieciu_wynikow[i].rok,tablica_dziesieciu_wynikow[i].miesiac
        ,tablica_dziesieciu_wynikow[i].dzien);
    }           //wypisuje dane z tablicy struktur, w której zawarte s¹ dane z pliku "ranking"
    printf("\n");
    printf("Aby powrocic do glownego menu wcisnij dowolny klawisz...");
    getch();
    czysc();
    main();         //po wybraniu dowolnego klawisza ekran siê czyœci poczym przechodzi do fnkcji main
}

void zapisz_wynik(int wynik)        //w przypadku gdy wynik gracza jest wiêkszy ni¿ ostatnia pozycja z rankingu - mo¿e siê dopisaæ do rankingu.
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    tablica_dziesieciu_wynikow[9].punkty=wynik;
    printf("\n");
    printf("Podaj swoj pseudonim: "); scanf("%s",&tablica_dziesieciu_wynikow[9].nazwa);
    tablica_dziesieciu_wynikow[9].rok=tm.tm_year + 1900;
    tablica_dziesieciu_wynikow[9].miesiac=tm.tm_mon+1;
    tablica_dziesieciu_wynikow[9].dzien=tm.tm_mday;
    struct rank pom;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(tablica_dziesieciu_wynikow[j].punkty<tablica_dziesieciu_wynikow[j+1].punkty)
            {
                pom.punkty=tablica_dziesieciu_wynikow[j].punkty;
                strcpy(pom.nazwa,tablica_dziesieciu_wynikow[j].nazwa);
                pom.rok=tablica_dziesieciu_wynikow[j].rok;
                pom.miesiac=tablica_dziesieciu_wynikow[j].miesiac;
                pom.dzien=tablica_dziesieciu_wynikow[j].dzien;

                tablica_dziesieciu_wynikow[j].punkty=tablica_dziesieciu_wynikow[j+1].punkty;
                strcpy(tablica_dziesieciu_wynikow[j].nazwa,tablica_dziesieciu_wynikow[j+1].nazwa);
                tablica_dziesieciu_wynikow[j].rok=tablica_dziesieciu_wynikow[j+1].rok;
                tablica_dziesieciu_wynikow[j].miesiac=tablica_dziesieciu_wynikow[j+1].miesiac;
                tablica_dziesieciu_wynikow[j].dzien=tablica_dziesieciu_wynikow[j+1].dzien;

                tablica_dziesieciu_wynikow[j+1].punkty=pom.punkty;
                strcpy(tablica_dziesieciu_wynikow[j+1].nazwa,pom.nazwa);
                tablica_dziesieciu_wynikow[j+1].rok=pom.rok;
                tablica_dziesieciu_wynikow[j+1].miesiac=pom.miesiac;
                tablica_dziesieciu_wynikow[j+1].dzien=pom.dzien;
            }
        }
    }
    FILE *plik=fopen("ranking","w");
    if(plik==NULL)
    {
        printf("Nie udalo sie otworzyc rankingu do zapisu! Powrot do menu!");
        main();
    }
    for(int i=0;i<10;i++)
    {
        fprintf(plik,"%s\n",tablica_dziesieciu_wynikow[i].nazwa);
        fprintf(plik,"%d\n",tablica_dziesieciu_wynikow[i].punkty);
        fprintf(plik,"%d ",tablica_dziesieciu_wynikow[i].rok);
        fprintf(plik,"%d ",tablica_dziesieciu_wynikow[i].miesiac);
        fprintf(plik,"%d\n",tablica_dziesieciu_wynikow[i].dzien);
    }
    fclose(plik);
}

int sprawdz_czy(int wynik)  //funkcja sprawdza czy wynik gracza jest wiêkszy ni¿ ostatnia pozycja w rankingu
{
    pobierz_ranking(tablica_dziesieciu_wynikow);
    if(wynik>tablica_dziesieciu_wynikow[9].punkty)
    {
        return true;
    }
    return false;
}

void pobierz_ranking(struct rank* tablica_dziesieciu_wynikow)       //pobieramy dane z pliku "ranking"  i uzupe³niamy nimi tablice struktur
{
    FILE *plik=fopen("ranking","r");
    char znak;
    if(plik==NULL)
    {
        czysc();
        printf("Nie udalo sie otworzyc rankingu do odczytu! Powrot do menu!"); sleep(3);
        czysc();
        main();
    }
    for(int i=0;i<10;i++)
    {
        fscanf(plik,"%s",tablica_dziesieciu_wynikow[i].nazwa); przesun_o_jedna_linie(znak,plik);
        fscanf(plik,"%d",&tablica_dziesieciu_wynikow[i].punkty); przesun_o_jedna_linie(znak,plik);
        fscanf(plik,"%d",&tablica_dziesieciu_wynikow[i].rok);
        fscanf(plik,"%d",&tablica_dziesieciu_wynikow[i].miesiac);
        fscanf(plik,"%d",&tablica_dziesieciu_wynikow[i].dzien); przesun_o_jedna_linie(znak,plik);
    }
    fclose(plik);
}
