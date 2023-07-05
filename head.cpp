#include "head.h"

///////////Vectory////////////
vector<Samolot> samoloty;
vector<Lot>loty;
vector<Samolot>powietrze;
vector<string> samolot1wektor;
vector<string> samolot2wektor;
vector<vector<string>>planes;

///////////Konstuktory/////////
Lotnisko::Lotnisko(string aa, int bb, int cc, int dd) {
    nazwa_lotniska = aa;
    pojemnosc_lotniska = bb;
    pasy_startowe = cc;
    ilosc_pasazerow = dd;
}

Pasazer::Pasazer(string im, string na) {
    imie = im;
    nazwisko = na;
}

Samolot::Samolot(int n, string x, int a, string bb, string c, string d, string e) {
    nr = n;
    nazwa_samolotu = x;
    rozmiar = a;
    status = bb;
    czas_startu = c;
    czas_ladowania = d;
    stan = e;
}

Lot::Lot(string a, string b) {
    miejsce_startu = a;
    miejsce_ladowania = b;
}

//////////Dekonstruktory/////////
Lotnisko::~Lotnisko() {}
Pasazer::~Pasazer() {}
Samolot::~Samolot() {}
Lot::~Lot() {}

////////Wyswietlanie////////
void WyswietlInfoSamolot(Samolot A) {
    cout << A.getInfoSamolotu(); //Pobiera Info Samolotu
}
void WyswietlInfo(Pasazer A) {
    cout << "Jego imie to: " << A.imie << endl;
    cout << "Jego nazwisko to: " << A.nazwisko << endl;
}
void WyswietlInfoLotnisko(Lotnisko A) {
    cout << "Znajdujemy siê na lotnisku " << A.nazwa_lotniska << "." << endl;
    cout << "Nasze lotnisko mo¿e pomieœciæ " << A.pojemnosc_lotniska << " samolotów oraz " << A.ilosc_pasazerow << " pasa¿erów." << endl;;
    cout << "Masz do dyspozycji " << A.pasy_startowe << " pasy startowe." << endl;
}
void WyswietlInfoLot2(Lot A) {
    if (A.miejsce_startu.empty()) {
        cout << "Lot: brak" << endl;
    }
    else {
        cout << "| Miejsce startu |" << A.miejsce_startu << "| miejsce ladowania |" << A.miejsce_ladowania << "|" << endl;
    }
}
void WyswietlInfoSamoloty(const vector<Samolot>& samoloty, const vector<Lot>& loty) { //Pobiera wektory samoloty i loty a póŸniej wyœwietla ich informacje
    cout << "Samoloty:" << endl;
    for (int i = 0; i < samoloty.size(); i++) {
        WyswietlInfoSamolot(samoloty[i]);
        if (i < loty.size()) {
            WyswietlInfoLot2(loty[i]);
        }
        else {
            cout << "Lot: brak" << endl;
        }
        cout << endl;
    }
}
////////Latanie/////////

void odlot(Samolot& B, Lot& A) { //funckja odlot bierze przez referencje obiekt Samolot i odpowiadaj¹cy obiekt Lot, odpowiada za odlot
    TAKEOFF(B); 
    if (!czyMoznaStartowac(B)) { 
        cout << "Nie mo¿na wystartowaæ samolotem." << endl;
        return;
    }
    miejsce_przylotu(A);
    Animacjaodlot();
}
void przylot(Samolot& B, Lot& A) { ////funckja przylot bierze przez referencje obiekt Samolot i odpowiadaj¹cy obiekt Lot, odpowiada za przylot
    ARRIVAL(B);
    if (!czyMoznaLadowac(B)) {
        cout << "Nie mo¿na wystartowaæ samolotem." << endl;
        return;
    }
    miejsce_odlotu(A);
    Animacjaprzylot();
}
void TAKEOFF(Samolot& B) {
    do {
        cout << "Podaj godzine startu samolotu: " << endl; //u¿ytknownik podaje godzine startu samolotu, dopóki nie poda w prawid³owym formacie
        cin >> B.czas_ladowania; // nastêpnie zmieniamy w naszym samolocie godzine
    } while (!czas(B.czas_ladowania));

        if (czyMoznaStartowac(B)==true) {
            do {
                cout << "Podaj godzine przylotu samolotu: " << endl; //to samo z godzin¹ przylotu
                cin >> B.czas_startu;
                B.status = "powietrze";
            } while (!czas(B.czas_startu));
        }
        else return;
}
void ARRIVAL(Samolot& B) {
    do {
        cout << "Podaj godzine startu samolotu:" << endl;
        cin>>B.czas_startu;
    } while (!czas(B.czas_startu));

    if (czyMoznaLadowac(B)==true) {
        do {
            cout << "Podaj godzine przylotu samolotu." << endl;
            cin >> B.czas_startu;
            B.status = "ziemia";
        } while (!czas(B.czas_startu));

    }
    else return;
}
void miejsce_przylotu(Lot& A) { //zmiana miejsca przylotu i odlotu
    cout << "Podaj miejsce docelowe lotu: " << endl;
    cin >> A.miejsce_ladowania;
    A.miejsce_startu = "Miletown";
}
void miejsce_odlotu(Lot& A) {
    cout << "Podaj miejsce z którego leci samolot: " << endl;
    cin >> A.miejsce_startu;
    A.miejsce_ladowania = "Miletown";
}
/////SPRAWDZENIA/////
bool sprawdzenie_czy_samolot2(int numer) { //funkcje sprawdzaj¹ce, czy dane samoloty maj¹ takie parametry
    return numer >= 1 and numer <= samoloty.size();
}
bool sprawdzenie_czy_samolotjest(Samolot& B) {
    return B.status == "ziemia";
}
bool sprawdzenie_czy_samolotjest2(Samolot& B) {
    return B.status == "powietrze";
}
bool sprawdzenie_stanu(Samolot& B) {
    return B.stan == "sprawny";
}
bool sprawdzenie_wolnych(Samolot& B) { //sprawdzamy iloœæ samolotów , które s¹ na ziemii.
    int ilosc = 0;
    for (int i = 0; i < samoloty.size(); i++) {
        if (samoloty[i].status == "ziemia") {
            ilosc++;
        }
    }
    cout << "Iloœæ samolotów na lotnisko to: " << ilosc << endl;
    if (ilosc < 10) return true;
    else return false;
}

bool czas(const string& time) { //Sprawdzany czy u¿ytkownik poda³ w odpowiednim formacie
    if (time.length() != 5) {
        return false;
    }

    if (time[2] != ':') {
        return false;
    }

    int hours = stoi(time.substr(0, 2)); //konwertuje stringa na int
    int minutes = stoi(time.substr(3, 2));

    if (hours < 0 || hours > 23) {
        return false;
    }

    if (minutes < 0 || minutes > 59) {
        return false;
    }

    return true;
}
bool czyMoznaStartowac(Samolot& B) { //Sprawdzamy pas startowy do startu, czy dany samolot ma tak¹ sam¹ godzinê z jakimkolwiek innym samolotem oprócz siebie samego
    for (int i = 0; i < samoloty.size(); i++) {
        if (B.czas_ladowania == samoloty[i].czas_ladowania and &B != &samoloty[i]) {
            B.czas_ladowania = "brak";
                return false;
        }
    }  
    return true;
}
bool czyMoznaLadowac(Samolot& B){ // to samo  tylko ¿e z l¹dowaniem
    for (int i = 0; i < samoloty.size(); i++) {
        if (B.czas_startu == samoloty[i].czas_startu and &B != &samoloty[i]) {
            B.czas_startu = "brak";
            return false;
        }
    }
    return true;
}
////////////////// Przydatne Funckje /////////////////////
void czyszczenie_konsoli() {
    int klawisz;
    do {
        cout << "Wciœnij enter, ¿eby przejœæ dalej." << endl;
        klawisz = _getch();
        if (klawisz == 13) { //sprawdzamy czy u¿ytkownik klikn¹³ enter, czyœcimy wtedy konsole
            system("cls");
        }
        else {
            cout << "Kliknij enter" << endl;
        }
    } while (klawisz != 13);
    

}
void wyswietl_menu() {
    int klawisz;
    klawisz = _getch();
    if (klawisz == 109) {
        menu();
    }
}
void menu() {
    WyswietlInfoSamoloty(samoloty, loty);
}
void reset() {
    wyswietl_menu();
    czyszczenie_konsoli();
}
void awaria() {
    Samolot sam16(16, "Boeing", 777, "ziemia", "brak", "brak", "uszkodzony");
    Lot lot16("brak", "brak");
    loty.push_back(lot16);
    samoloty.push_back(sam16);
    cout << "Gratulacje" << endl;
    napraw(samoloty.back()); // przekazujemy ostatni elemnent wektora
}
void napraw(Samolot& B) {
    cout << "Czy chcesz naprawiæ samolot?" << endl;
    string zgoda;
    cin >> zgoda;
    if (zgoda == "tak" || zgoda == "TAK" || zgoda == "Tak") {
        B.stan = "naprawiony";
    }

}
void generowanie_lotow() { //generujemy obiekty lot1, lot2 i tak dalej, z domyœlnymi parametrami brak i brak, dodajemy do wektora loty
    for (int i = 1; i <= 15; i++) {
        string numerLotu = "lot" + to_string(i);
        Lot lot("brak", "brak");
        loty.push_back(lot);
    }
}
//////PlikiTekstowe////////
void wczytsamolot(ifstream& samolot, int i) { // wczytujemy do wektora wektorów planes, naszych pasa¿erów z plików
    if (samolot.is_open()) {
        string linia;
        while (getline(samolot, linia)) {
            if (i >= planes.size()) {
                planes.resize(i + 1);
            }
            planes.at(i).push_back(linia);
        }
        samolot.close();
    }
    else {
        cout << "Nie udalo siê otworzyæ pliku." << endl;
    }
}
void odczytajsamolot(vector<string>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}
void odczytajsamolot2(vector<string>& a) {
    cout << "Czy zgadzasz siê na przyjêcie listy pasa¿erów?" << endl;
    string zgoda;
    cin >> zgoda;
    if (zgoda == "tak" || zgoda == "TAK" || zgoda == "Tak") {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << endl;
        }
    }
    
}
/////////////MENU//////////////
void wybor(int a) { //Menu, mamy do wybór parê opcji, switchem wybieramy któr¹ z nich, ka¿da ma swoje zabezpieczenie
    int numer;
    switch (a) {
    case 1:
            while (true) {
                cout << "Podaj numer maszyny któr¹ chcesz wys³aæ w powietrze: " << endl;
                cin >> numer;
                if (!sprawdzenie_czy_samolot2(numer))  continue;
                if (!sprawdzenie_czy_samolotjest(samoloty[numer - 1])) {
                    cout << "Samolot musi byæ na ziemi. Podaj inny numer." << endl;
                }
                if (!sprawdzenie_stanu(samoloty[numer - 1])) {
                    cout << "Samolot musi byæ sprawny. Podaj inny numer" << endl;
                    continue;
                }
                else break;
            }
        odlot(samoloty[numer - 1], loty[numer - 1]);
        break;
    case 2:
        while (true) {
            cout << "Podaj numer maszyny która powinna wyl¹dowaæ: " << endl;
            cin >> numer;
            if (!sprawdzenie_czy_samolot2(numer))  continue;
            if (!sprawdzenie_czy_samolotjest2(samoloty[numer - 1])) {
                cout << "Samolot musi byæ w powietrzu. Podaj inny numer." << endl;
                continue;
            } 
            if (!sprawdzenie_wolnych(samoloty[numer - 1])) {
                cout << "Zbyt du¿o samolotów jest na lotnisku , nie mo¿na wyl¹dowaæ. Spróbuj gdzie indziej" << endl;
                return;
            }
            else break;
        }
        przylot(samoloty[numer - 1], loty[numer - 1]);
        break;
    case 3:
        do{
        cout << "Podaj numer samolotu, którego listê pasa¿erów chcesz sprawdziæ: " << endl;
        cin >> numer;
        } while (sprawdzenie_czy_samolot2(numer) == false);
        odczytajsamolot(planes[numer - 1]);
        break;
    case 4:
        do {
        cout << "Podaj numer samolotu którego chcesz naprawiæ : " << endl;
        cin >> numer;
        } while (sprawdzenie_czy_samolot2(numer) == false);
        napraw(samoloty[numer - 1]);
        break;
    case 5:
        menu();
        break;
    case 6:
        exit(0);
        break;
    default:
        system("cls");  // Czyszczenie konsoli w przypadku nieprawid³owego wyboru
        cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
        cin.clear();  // Wyczyszczenie 
        while (cin.get() != '\n')
            continue;

        break;
    }
}
void main_menu() {
    int opcjamenu;
    cout << "=============================== MENU ============================ " << endl;
    cout << "Wpisz numer opcji, któr¹ chcesz wykonaæ: " << endl;
    cout << "1. Odlot Samolotem " << endl;
    cout << "2. Przylot Samoloten " << endl;
    cout << "3. Zatwierdz listê pasa¿erów " << endl;
    cout << "4. Napraw Samolot " << endl;
    cout << "5. Wyœwietl info o Samolotach " << endl;
    cout << "6. Wyjœcie z Symulatora " << endl;
    cout << "================================================================= " << endl;
    cin >> opcjamenu;
    wybor(opcjamenu);
}
////RYSUNKI/////
void Rysujsamolotp3() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n             *********                                                                                    ";
    cout << "\n              *       *                                                                                   ";
    cout << "\n               *       *                                                                                  ";
    cout << "\n             ***        ******************************************************************                ";
    cout << "\n              *                                                                         *****             ";
    cout << "\n               *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                 *                                                                                *       ";
    cout << "\n                  *                                                                               *       ";
    cout << "\n                   ******       ****************                    ******************************        ";
    cout << "\n                       *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n                      *       *              *                 *                                          ";
    cout << "\n                     *********              *                *                                            ";
    cout << "\n                                           *               *                                              ";
    cout << "\n                                          *              *                                                ";
    cout << "\n                                         *             *                                                  ";
    cout << "\n                                        **************                                                    ";
}
void Rysujsamolotp1() {
    cout << "\n   *********                                                                                    ";
    cout << "\n    *       *                                                                                   ";
    cout << "\n     *       *                                                                                  ";
    cout << "\n   ***        ******************************************************************                ";
    cout << "\n    *                                                                         *****             ";
    cout << "\n     *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n      *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n       *                                                                                *       ";
    cout << "\n        *                                                                               *       ";
    cout << "\n         ******       ****************                    ******************************        ";
    cout << "\n             *       *              *                   *                                       ";
    cout << "\n            *       *              *                 *                                          ";
    cout << "\n           *********              *                *                                            ";
    cout << "\n                                 *               *                                              ";
    cout << "\n                                *              *                                                ";
    cout << "\n                               *             *                                                  ";
    cout << "\n                              **************                                                    ";
}
void Rysujsamolotp2() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n      *********                                                                                    ";
    cout << "\n       *       *                                                                                   ";
    cout << "\n        *       *                                                                                  ";
    cout << "\n      ***        ******************************************************************                ";
    cout << "\n       *                                                                         *****             ";
    cout << "\n        *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n         *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n          *                                                                                *       ";
    cout << "\n           *                                                                               *       ";
    cout << "\n            ******       ****************                    ******************************        ";
    cout << "\n                *       *              *                   *                                       ";
    cout << "\n               *       *              *                 *                                          ";
    cout << "\n              *********              *                *                                            ";
    cout << "\n                                    *               *                                              ";
    cout << "\n                                   *              *                                                ";
    cout << "\n                                  *             *                                                  ";
    cout << "\n                                 **************                                                    ";
}
void Rysujsamolotp4() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                 *********                                                                                    ";
    cout << "\n                  *       *                                                                                   ";
    cout << "\n                   *       *                                                                                  ";
    cout << "\n                 ***        ******************************************************************                ";
    cout << "\n                  *                                                                         *****             ";
    cout << "\n                   *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                    *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                     *                                                                                *       ";
    cout << "\n                      *                                                                               *       ";
    cout << "\n                       ******       ****************                    ******************************        ";
    cout << "\n                           *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n                          *       *              *                 *                                          ";
    cout << "\n                         *********              *                *                                            ";
    cout << "\n                                               *               *                                              ";
    cout << "\n                                              *              *                                                ";
    cout << "\n                                             *             *                                                  ";
    cout << "\n                                            **************                                                    ";
}
void Rysujsamolotp5() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                      *********                                                                                    ";
    cout << "\n                       *       *                                                                                   ";
    cout << "\n                        *       *                                                                                  ";
    cout << "\n                      ***        ******************************************************************                ";
    cout << "\n                       *                                                                         *****             ";
    cout << "\n                        *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                         *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                          *                                                                                *       ";
    cout << "\n                           *                                                                               *       ";
    cout << "\n                            ******       ****************                    ******************************        ";
    cout << "\n                                *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n                               *       *              *                 *                                          ";
    cout << "\n                              *********              *                *                                            ";
    cout << "\n                                                    *               *                                              ";
    cout << "\n                                                   *              *                                                ";
    cout << "\n                                                  *             *                                                  ";
    cout << "\n                                                 **************                                                    ";
}
void Rysujsamolotp6() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                           *********                                                                                    ";
    cout << "\n                            *       *                                                                                   ";
    cout << "\n                             *       *                                                                                  ";
    cout << "\n                           ***        ******************************************************************                ";
    cout << "\n                            *                                                                         *****             ";
    cout << "\n                             *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                              *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                               *                                                                                *       ";
    cout << "\n                                *                                                                               *       ";
    cout << "\n                                 ******       ****************                    ******************************        ";
    cout << "\n                                     *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n                                    *       *              *                 *                                          ";
    cout << "\n                                   *********              *                *                                            ";
    cout << "\n                                                         *               *                                              ";
    cout << "\n                                                        *              *                                                ";
    cout << "\n                                                       *             *                                                  ";
    cout << "\n                                                      **************                                                    ";
}

void Rysujsamoloto1() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n   *********                                                                                    ";
    cout << "\n    *       *                                                                                   ";
    cout << "\n     *       *                                                                                  ";
    cout << "\n   ***        ******************************************************************                ";
    cout << "\n    *                                                                         *****             ";
    cout << "\n     *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n      *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n       *                                                                                *       ";
    cout << "\n        *                                                                               *       ";
    cout << "\n         ******       ****************                    ******************************        ";
    cout << "\n             *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n            *       *              *                 *                                          ";
    cout << "\n           *********              *                *                                            ";
    cout << "\n                                 *               *                                              ";
    cout << "\n                                *              *                                                ";
    cout << "\n                               *             *                                                  ";
    cout << "\n                              **************                                                    ";
}
void Rysujsamoloto2() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n      *********                                                                                    ";
    cout << "\n       *       *                                                                                   ";
    cout << "\n        *       *                                                                                  ";
    cout << "\n      ***        ******************************************************************                ";
    cout << "\n       *                                                                         *****             ";
    cout << "\n        *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n         *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n          *                                                                                *       ";
    cout << "\n           *                                                                               *       ";
    cout << "\n            ******       ****************                    ******************************        ";
    cout << "\n                *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n               *       *              *                 *                                          ";
    cout << "\n              *********              *                *                                            ";
    cout << "\n                                    *               *                                              ";
    cout << "\n                                   *              *                                                ";
    cout << "\n                                  *             *                                                  ";
    cout << "\n                                 **************                                                    ";
}
void Rysujsamoloto3() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n             *********                                                                                    ";
    cout << "\n              *       *                                                                                   ";
    cout << "\n               *       *                                                                                  ";
    cout << "\n             ***        ******************************************************************                ";
    cout << "\n              *                                                                         *****             ";
    cout << "\n               *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                 *                                                                                *       ";
    cout << "\n                  *                                                                               *       ";
    cout << "\n                   ******       ****************                    ******************************        ";
    cout << "\n                       *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n                      *       *              *                 *                                          ";
    cout << "\n                     *********              *                *                                            ";
    cout << "\n                                           *               *                                              ";
    cout << "\n                                          *              *                                                ";
    cout << "\n                                         *             *                                                  ";
    cout << "\n                                        **************                                                    ";
}
void Rysujsamoloto4() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                 *********                                                                                    ";
    cout << "\n                  *       *                                                                                   ";
    cout << "\n                   *       *                                                                                  ";
    cout << "\n                 ***        ******************************************************************                ";
    cout << "\n                  *                                                                         *****             ";
    cout << "\n                   *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                    *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                     *                                                                                *       ";
    cout << "\n                      *                                                                               *       ";
    cout << "\n                       ******       ****************                    ******************************        ";
    cout << "\n                           *       *      OOO     *                   *    OOO          OOO                   ";
    cout << "\n                          *       *              *                 *                                          ";
    cout << "\n                         *********              *                *                                            ";
    cout << "\n                                               *               *                                              ";
    cout << "\n                                              *              *                                                ";
    cout << "\n                                             *             *                                                  ";
    cout << "\n                                            **************                                                    ";
}
void Rysujsamoloto5() {
    cout << "\n                                                                                                   ";
    cout << "\n                                                                                                   ";
    cout << "\n                      *********                                                                                    ";
    cout << "\n                       *       *                                                                                   ";
    cout << "\n                        *       *                                                                                  ";
    cout << "\n                      ***        ******************************************************************                ";
    cout << "\n                       *                                                                         *****             ";
    cout << "\n                        *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                         *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                          *                                                                                *       ";
    cout << "\n                           *                                                                               *       ";
    cout << "\n                            ******       ****************                    ******************************        ";
    cout << "\n                                *       *              *                   *                                       ";
    cout << "\n                               *       *              *                 *                                          ";
    cout << "\n                              *********              *                *                                            ";
    cout << "\n                                                    *               *                                              ";
    cout << "\n                                                   *              *                                                ";
    cout << "\n                                                  *             *                                                  ";
    cout << "\n                                                 **************                                                    ";
}
void Rysujsamoloto6() {
    cout << "\n                           *********                                                                                    ";
    cout << "\n                            *       *                                                                                   ";
    cout << "\n                             *       *                                                                                  ";
    cout << "\n                           ***        ******************************************************************                ";
    cout << "\n                            *                                                                         *****             ";
    cout << "\n                             *                 ****     ****     ****     ****     ****     ****      ********          ";
    cout << "\n                              *                 ****     ****     ****     ****     ****     ****      *********        ";
    cout << "\n                               *                                                                                *       ";
    cout << "\n                                *                                                                               *       ";
    cout << "\n                                 ******       ****************                    ******************************        ";
    cout << "\n                                     *       *              *                   *                                       ";
    cout << "\n                                    *       *              *                 *                                          ";
    cout << "\n                                   *********              *                *                                            ";
    cout << "\n                                                         *               *                                              ";
    cout << "\n                                                        *              *                                                ";
    cout << "\n                                                       *             *                                                  ";
    cout << "\n                                                      **************                                                    ";
}


    void Rysujczlowiek1() {
        cout << "                                         _______________________                                            " << endl;
        cout << "                                        /========================\\                                          " << endl;
        cout << "                                       |=========================|                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |     -o-         -o-     |                                          " << endl;
        cout << "                                       |            ^            |                                          " << endl;
        cout << "                                       |           / \\           |                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |         \\_____/         |                                          " << endl;
        cout << "                                        \\_______________________/                                           " << endl;
        cout << "                                       /|||||||||||||||||||||||||\\                                         " << endl;
        cout << "                                      /|||||||||||||||||||||||||||\\                                        " << endl;
        cout << "                                     /|||||||||||||||||||||||||||||\\                                       " << endl;
        cout << "                                    /|||||||||||||||||||||||||||||||\\                                      " << endl;
    }
    void Rysujczlowiek2() {
        cout << "                                         _______________________                                            " << endl;
        cout << "                                        /========================\\                                          " << endl;
        cout << "                                       |=========================|                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |                         |                                          " << endl;
        cout << "                                       |     -o-         -o-     |                                          " << endl;
        cout << "                                       |            ^            |                                          " << endl;
        cout << "                                       |           / \\           |                                          " << endl;
        cout << "                                       |                         |       /                                  " << endl;
        cout << "                                       |         \(_____)         |      /                                    " << endl;
        cout << "                                        \\_______________________/      /                                     " << endl;
        cout << "                                       /|||||||||||||||||||||||||\\    /                                     " << endl;
        cout << "                                      /|||||||||||||||||||||||||||\\  /                                     " << endl;
        cout << "                                     /|||||||||||||||||||||||||||||\\/                                       " << endl;
        cout << "                                    /|||||||||||||||||||||||||||||||\\                                      " << endl;
    }
    void Rysujlotnisko() {
        cout << "                                                                                             +              " << endl;
        cout << "                                                                                             +              " << endl;
        cout << "                                                                                        _____+____          " << endl;
        cout << "                                                                                       /          \\        " << endl;
        cout << "                                                                                       |OOOOOOOOOO|         " << endl;
        cout << "                                                                                       \\__________/          " << endl;
        cout << "                                                                                        |        |          " << endl;
        cout << "                                                                                        |        |          " << endl;
        cout << "             +                   +             +                +                       |        |          " << endl;
        cout << " ____________+___________________+_____________+________________+___________            |        |          " << endl;
        cout << "[  ||  ]                             [  ||  ]                        [  ||  ]           |        |          " << endl;
        cout << "[      ]        AIR PORT             [      ]        AIR PORT        [      ]           |        |          " << endl;
        cout << "[  ||  ]_____________________________[  ||  ]________________________[      ]           |        |          " << endl;
        cout << "[      ]                             [      ]                        [  ||  ]           |        |          " << endl;
        cout << "[  ||  ]_____________________________[  ||  ]________________________[      ]           |        |          " << endl;
        cout << "[      ]                             [      ]                        [  ||  ]           |        |          " << endl;
        cout << "[__[]__]_____________________________[__[]__]________________________[__[]__]  i_____i  |___[]___|  i_____i " << endl;

    }
   ////ANIMACJE///
    void Animacjaprzylot() {
        Rysujsamolotp1();
        cout << endl << endl;
        Sleep(700);
        system("cls");

        Rysujsamolotp2();
        cout << endl << endl;
        Sleep(700);
        system("cls");

        Rysujsamolotp3();
        cout << endl << endl;
        Sleep(700);
        system("cls");

        Rysujsamolotp4();
        cout << endl << endl;
        Sleep(1000);
        system("cls");

        Rysujsamolotp5();
        cout << endl << endl;
        Sleep(1000);
        system("cls");

        Rysujsamolotp6();
        cout << endl << endl;
        Sleep(1000);
        system("cls");
    }
    void Animacjaodlot() {
        Rysujsamoloto1();
        cout << endl << endl;
        Sleep(700);
        system("cls");

        Rysujsamoloto2();
        cout << endl << endl;
        Sleep(700);
        system("cls");

        Rysujsamoloto3();
        cout << endl << endl;
        Sleep(700);
        system("cls");

        Rysujsamoloto4();
        cout << endl << endl;
        Sleep(1000);
        system("cls");

        Rysujsamoloto5();
        cout << endl << endl;
        Sleep(1000);
        system("cls");

        Rysujsamoloto6();
        cout << endl << endl;
        Sleep(1000);
        system("cls");
    }