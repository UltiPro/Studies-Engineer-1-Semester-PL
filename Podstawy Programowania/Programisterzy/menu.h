void wypisz_listewyborow()  //Funkcja rozpoczynajaca gre. W zaleznosci od wyboru uzytkownika przejdziemy do innej funkcji gry
{
    int wybor;
    printf("1. ZAGRAJ \n");
    printf("2. RANKING \n");
    printf("3. DODAJ WLASNE PYTANIE \n");
    printf("4. AUTORZY \n");
    printf("5. WYJSCIE \n\n");
    wybor=getch();
    switch(wybor)
    {
        case 49:
        {
            graj();     //rozpoczyna gre
            break;
        }
        case 50:
        {
            ranking();      //wyswietla ranking
            break;
        }
        case 51:
        {
            dodaj_pytania();        //wyswietla okno dodania pytania
            break;
        }
        case 52:
        {
            autorzy();      //wyswietla informacje o autorach
            break;
        }
        case 53:
        {
            zakoncz(1);     //wlacza menu konca gry
            break;
        }
        default:        //w przypadku nieprawid³owego znaku trafiemy fo funkcji glownej
        {
            for(int i=3;i>0;i--)
            {
                czysc();
                printf("Podano nie prawidlowa wartosc! Program odswiezy sie za: %d \n",i);
                sleep(1);
            }
            czysc();
            main();
            break;
        }
    }
}

