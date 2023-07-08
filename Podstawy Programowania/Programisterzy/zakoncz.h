void zakoncz(int podprogram) // wyswietla menu konca programu
{
    int wybor;
    czysc();
    printf("Czy na pewno chcesz zakonczyc program?\n");
    printf("1. TAK      ");
    printf("2. NIE    \n");
    wybor = getch();
    switch (wybor)
    {
    case 49:
    {
        exit(1);
        break;
    }
    case 50: // w zaleznosci od argumentu funkcji (int podprogram):
    {
        czysc();
        if (podprogram == 1)
            main(); // wyswietla funkcje glowna
        if (podprogram == 2)
            menu_dodaj_pytania(); // wyswietla okno dodawania pytan
        if (podprogram == 3)
            powrot(); // wyswietla
        break;
    }
    default:
    {
        for (int i = 3; i > 0; i--)
        {
            czysc();
            printf("Podano nie prawidlowa wartosc! Program odswiezy sie za: %d \n", i);
            sleep(1);
        }
        czysc();
        zakoncz(podprogram);
        break;
    }
    }
}