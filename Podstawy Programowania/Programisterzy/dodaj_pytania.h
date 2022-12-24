#define max_dlug 100

void dodaj_pytania()
{
    czysc();
    char komunikat1[max_dlug]="1. Maksymalna dlugosc pytania jak i odpowiedzi moze zawierac 100 znakow. \n",
    komunikat2[max_dlug]="2. Poprawna odpowiedz powinna zawierac tylko i wylacznie literke odpowiedzi ktora jest prawidlowa.\n",
    komunikat3[max_dlug]="3. Kazde pytanie jak i odpowiedzi POTWIERDZ ENTEREM\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i==0||i==4)
            {
                if(j==99) printf("-\n");        //Na ekranie wyœwietla siê linia z³o¿ona z "-"
                else printf("-");               //Nastepnie komunikaty (instrukcja), na koniec znów linia.
            }
            else
            {
                if(i==1) printf("%s",komunikat1);
                if(i==2) printf("%s",komunikat2);
                if(i==3) printf("%s",komunikat3);
                break;
            }
        }
    }
    char pomocnicza[max_dlug];      //zmienna pomocnicza pod ktora wpisujemy kolejno pytanie, odpowiedzi A-D oraz poprawna odpowiedz
    printf("Podaj tresc pytania: "); fgets(pomocnicza,max_dlug,stdin);      //Pobieramy pytanie o dlugosci max_dlug(100) znakow ze standardowego wejscia
    char pytanie[strlen(pomocnicza)];                    //zmienna o d³ugosci podanego pytania, pod która zapiszemy za moment tresc pytania
    przypisz(pytanie,pomocnicza,strlen(pomocnicza)+1);
    printf("Podaj odpowiedz A: "); fgets(pomocnicza,max_dlug,stdin);   //Analogicznie postepujemy pobierajac odpowiedzi A,B,C,D
    char odpA[strlen(pomocnicza)];
    przypisz(odpA,pomocnicza,strlen(pomocnicza)+1);
    printf("Podaj odpowiedz B: "); fgets(pomocnicza,max_dlug,stdin);
    char odpB[strlen(pomocnicza)];
    przypisz(odpB,pomocnicza,strlen(pomocnicza)+1);
    printf("Podaj odpowiedz C: "); fgets(pomocnicza,max_dlug,stdin);
    char odpC[strlen(pomocnicza)];
    przypisz(odpC,pomocnicza,strlen(pomocnicza)+1);
    printf("Podaj odpowiedz D: "); fgets(pomocnicza,max_dlug,stdin);
    char odpD[strlen(pomocnicza)];
    przypisz(odpD,pomocnicza,strlen(pomocnicza)+1);
    printf("Podaj poprawna odpowiedz : "); fgets(pomocnicza,max_dlug,stdin);    //do 'pomocnicza' pobieramy znak poprawnej odpowiedzi
    while((!((pomocnicza[0]>=65)&&(pomocnicza[0]<=68)))&&!((pomocnicza[0]>=97)&&(pomocnicza[0]<=100)))
    {
        printf("Nieprawidlowa odpowiedz! Odpowiedz powinna byc literkami a lub b lub c lub d! Wprowadz poprawna odpowiedz: "); fgets(pomocnicza,max_dlug,stdin);
    }
    if((pomocnicza[0]>=97)&&(pomocnicza[0]<=100))       //jezeli "pomocnicza"  to a-d zamieniamy j¹ na wielk¹ litere
    {
        pomocnicza[0]=pomocnicza[0]-32;
    }
    char popodp[strlen(pomocnicza)];    //zmienna znaku poprawnej odpowiedzi
    przypisz(popodp,pomocnicza,strlen(pomocnicza)+1);       //znak zapisany pod "pomocnicza" zapisujemy pod zmienn¹ "popodp"
    FILE *plik=fopen("pytania","a");        //otwieramy plik w którym s¹ pytania i odpowiedzi w trybie dopisywania
    if(plik==NULL)
    {
        czysc();
        printf("Nie udalo sie otworzyc listy pytan do dopisywania! Powrot do menu!"); sleep(3);
        czysc();
        main();
    }
    fprintf(plik,"%s",pytanie);     //do pliku dopisujemy kolejnoo pytanie, mo¿liwe odpowiedzi i poprawna odp
    fprintf(plik,"%s",odpA);
    fprintf(plik,"%s",odpB);
    fprintf(plik,"%s",odpC);
    fprintf(plik,"%s",odpD);
    fprintf(plik,"%s",popodp);
    fclose(plik);
    menu_dodaj_pytania();       //funkcja kieruje nas do nastepnej - menu dodawania pytania
}

void menu_dodaj_pytania()
{
    int wybor;
    czysc();
    printf("Pytanie wraz z odpowiedziami zostalo zapisane.\n");
    printf("1. Dodaj kolejne pytanie\n");
    printf("2. Powrot do menu\n");
    printf("3. Wylacz program\n");
    wybor=getch();      //pobieramy wybor uzytkownika
    switch(wybor)
    {
        case 49:
        {
            dodaj_pytania();
            break;
        }
        case 50:
        {
            czysc();
            main();
            break;
        }
        case 51:
        {
            zakoncz(2);
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
            menu_dodaj_pytania();       //ponownie otwieramy menu dodawania pytania
            break;
        }
    }
}

void przypisz(char *napis1,char *napis2,int dl)     //funkcja
{
    for(int i=0;i<dl;i++)
    {
        napis1[i]=napis2[i];
    }
}
