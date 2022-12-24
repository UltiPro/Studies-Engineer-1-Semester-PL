int  piedziesiat_na_piedziesiat(int nr,char pytanie[100],char odpA[100],char odpB[100],char odpC[100], char odpD[100], char popodp[2],char znak)
{
    czysc();
    printf("Wybrano kolo ratunkowe 50 na 50!\n");
    pasek();
    printf("Pytanie nr %d\n",nr);
    pasek();
    printf("%s\n",pytanie);
    int nr1=0,nr2=0;        //s¹ to odpowiedzi które odrzucimy w kole 50 na 50
    nr1=rand()%4+65;        //losujemy numer1 w zakresie 65-68 odpowiadaj¹ce w kodzie ASCI A-D
    while(nr1==popodp[0]) nr1=rand()%4+65;      //losujemy dopóki numer1 pokrywa siê z poprawn¹ odpowiedzi¹
    nr2=rand()%4+65;
    while(nr2==popodp[0]||nr2==nr1) nr2=rand()%4+65;        //losujemy nr2 tak aby nie pokty³ siê z odpowiedzi¹ poprawn¹ ani z nr1
    if(popodp[0]==65||(nr1!=65&&nr2!=65)) printf("A. %s\n",odpA); //na ekram wypisujemy te odpowiedzi które: s¹ odpowiedzi¹ poprawn¹ lub nie si¹ nr1 i nr2 - czyli odpowiedziami wykluczonymi
    if(popodp[0]==66||(nr1!=66&&nr2!=66)) printf("B. %s\n",odpB);
    if(popodp[0]==67||(nr1!=67&&nr2!=67)) printf("C. %s\n",odpC);
    if(popodp[0]==68||(nr1!=68&&nr2!=68)) printf("D. %s\n",odpD);
    pasek();
    printf("Twoj wybor: "); znak=getchar(); getchar();      //Gracz wprowadza swoj¹ odpowiedz
    while((!(znak>=65&&znak<=68)&&!(znak>=97&&znak<=100))||((znak==nr1||znak==nr2)||(znak==nr1+32||znak==nr2+32)))
    {
        printf("Wybrano odpowiedz z poza zakresu! Prosze sprobowac ponownie! Twoj wybor: ");
        znak=getchar(); getchar();
    }
    if((znak>=97)&&(znak<=100)) //97-100 to w kodzie ASCII a-D odejmujemy 32 aby uzyskaæ wielkie znaki A-D
    {
        znak=znak-32;
    }
    printf("\n");
    return znak;        //funkcja zwraca znak czyli odpowiedz wybran¹ przez gracza
}
// W naszej grze przyjaciel nie jest nie omylny. Mamy 50% szans ¿e dobrze nam podpowie. Zalezy to od zmiennej nr_losowy
void telefon_do_przyjaciela(char pytanie[100],char odpA[100],char odpB[100],char odpC[100], char odpD[100], char popodp[2])
{
    printf("Za 3 sekundy polaczymy sie z twoim przyjacielem... \n");
    sleep(3);
    czysc();
    int nr_losowy;          //od niej zale¿y czy podpowiedz bêdzie trafna czy b³êdna
    char tresc_odp[100];    //odpowiedz przyjaciela
    nr_losowy=rand()%2;     //
    if(nr_losowy==0)
    {
        int nr=rand()%4+65;
        while(nr==popodp[0]) nr=rand()%4+65;        //w przypadku gdzy nr_losowy=0 - losujemy odpowiedz ró¿n¹ od poprawnej w kodzie ASCII
        if(nr==65) strcpy(tresc_odp,odpA);
        if(nr==66) strcpy(tresc_odp,odpB);
        if(nr==67) strcpy(tresc_odp,odpC);
        if(nr==68) strcpy(tresc_odp,odpD);
    }
    else
    {
        if(popodp[0]==65) strcpy(tresc_odp,odpA);   //w przypadku gdzy nr_losowy=1 - za tresc_odp podstawiamy poprawn¹ odpowiedz
        if(popodp[0]==66) strcpy(tresc_odp,odpB);
        if(popodp[0]==67) strcpy(tresc_odp,odpC);
        if(popodp[0]==68) strcpy(tresc_odp,odpD);
    }
    printf("Wybrano kolo ratunkowe telefon do przyjaciela. Pamietaj ze masz 35 sekund.\n");
    for(int i=0;i<113;i++)
    {
        printf("-");
        if(i==112) printf("\n");
    }
    sleep(3);                                           //na ekranie wyswietla sie rozmowa z przyjacielem w której pada jego odpowiedz
    printf("TY:        | Czesc Kamil!\n"); sleep(1);     //polaczenie trwa 45 sekund
    printf("PRZYJACIEL:| Czesc!\n"); sleep(1);
    printf("TY:        | Sluchaj mam takie pytanie: %s\n",pytanie); sleep(3);
    printf("TY:        | Mozliwe odpowiedzi to:\n"); sleep(1);
    printf("TY:        | A. %s\n",odpA); sleep(1);
    printf("TY:        | B. %s\n",odpB); sleep(1);
    printf("TY:        | C. %s\n",odpC); sleep(1);
    printf("TY:        | D. %s\n",odpD); sleep(1);
    printf("TY:        | Ktora odpowiedz wedlug ciebie jest prawidlowa?\n"); sleep(3);
    printf("PRZYJACIEL:| Rzeczywiscie padlo na trudne pytanie. Waham sie miedzy dwiema odpowiedziami.\n"); sleep(3);
    printf("PRZYJACIEL:| Jednak wydaje mi sie, ze poprawna odpowiedz brzmi: %s\n",tresc_odp); sleep(3);
    printf("PRZYJACIEL:| Trzymamy za Ciebie kciuki! Powodzenia!\n"); sleep(3);
    for(int i=0;i<113;i++)
    {
        printf("-");
        if(i==112) printf("\n\n");
    }
    sleep(8);
    for(int i=5;i>0;i--)
    {
        printf("Rozmowa zakonczy sie za %d\n",i);
        sleep(1);
    }
}
