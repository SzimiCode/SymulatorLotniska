#include "head.h"


int main()
{
    setlocale(LC_CTYPE, "Polish"); // Jezyk polski


    int numer;
    int numer2;
    string zgoda;
    

    Samolot sam1(1, "Boeing", 747, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam1);
    Samolot sam2(2, "Airbus", 320, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam2);
    Samolot sam3(3, "Boeing", 777, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam3);
    Samolot sam4(4, "Airbus", 320, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam4);
    Samolot sam5(5, "Boeing", 747, "ziemia", "brak", "brak", "niesprawny");
    samoloty.push_back(sam5);
    Samolot sam6(6, "Airbus", 380, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam6);
    Samolot sam7(7, "Airbus", 320, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam7);
    Samolot sam8(8, "Sukhoi", 100, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam8);
    Samolot sam9(9, "Sukhoi", 100, "ziemia", "brak", "brak", "sprawny");
    samoloty.push_back(sam9);
    Samolot sam10(10, "Boeing", 777, "powietrze", "brak", "brak", "sprawny");
    samoloty.push_back(sam10);
    Samolot sam11(11, "Airbus", 380, "powietrze", "brak", "brak", "sprawny");
    samoloty.push_back(sam11);
    Samolot sam12(12, "Boeing", 787, "powietrze", "brak", "brak", "sprawny");
    samoloty.push_back(sam12);
    Samolot sam13(13, "Airbus", 350, "powietrze", "brak", "brak", "sprawny");
    samoloty.push_back(sam13);
    Samolot sam14(14, "Boeing", 747, "powietrze", "brak", "brak", "sprawny");
    samoloty.push_back(sam14);
    Samolot sam15(15, "Boeing", 777, "powietrze", "brak", "brak", "sprawny");
    samoloty.push_back(sam15);

    generowanie_lotow(); //Funkcja generuje 15 Lotów z miejscem docelowym Brak i miejscem przylotu brak, dodaje je do wektora loty

    ifstream samolot1("Samolot1.txt");
    ifstream samolot2("Samolot2.txt");
    ifstream samolot3("Samolot3.txt");
    ifstream samolot4("Samolot4.txt");
    ifstream samolot5("Samolot5.txt");
    ifstream samolot6("Samolot6.txt");
    ifstream samolot7("Samolot7.txt");
    ifstream samolot8("Samolot8.txt");
    ifstream samolot9("Samolot9.txt");
    ifstream samolot10("Samolot10.txt");
    ifstream samolot11("Samolot11.txt");
    ifstream samolot12("Samolot12.txt");
    ifstream samolot13("Samolot13.txt");
    ifstream samolot14("Samolot14.txt");
    ifstream samolot15("Samolot15.txt");

    wczytsamolot(samolot1, 0);
    wczytsamolot(samolot2, 1);
    wczytsamolot(samolot3, 2);
    wczytsamolot(samolot4, 3);
    wczytsamolot(samolot5, 4);
    wczytsamolot(samolot6, 5);
    wczytsamolot(samolot7, 6);
    wczytsamolot(samolot8, 7);
    wczytsamolot(samolot9, 8);
    wczytsamolot(samolot10, 9);
    wczytsamolot(samolot11, 10);
    wczytsamolot(samolot12, 11);
    wczytsamolot(samolot13, 12);
    wczytsamolot(samolot14, 13);
    wczytsamolot(samolot15, 14);

    /*odczytajsamolot(planes[1]);*/
   
    Animacjaprzylot();
       
    Rysujczlowiek1();
    cout << endl << endl;
    cout << "Witaj w symulatorze lotniska!" << endl;
    cout << "Dzisiaj czeka cię pracowity dzień na naszym lotnisku." << endl;
    czyszczenie_konsoli();

    Rysujczlowiek2();

    cout << endl << endl;
    cout << "A tak prezentuja sie zasady panujące na lotnisku:" << endl;
    czyszczenie_konsoli();

    Rysujlotnisko();
    Lotnisko lotnisko1;
    cout << endl;
    WyswietlInfoLotnisko(lotnisko1);
    czyszczenie_konsoli();



    cout << "Kliknij m aby wyświetlić listę dostępnych maszyn." << endl;
    wyswietl_menu();
    czyszczenie_konsoli();

    Rysujczlowiek1();
    cout << "Najpierw zapoznam cię z możliwości jakie oferuje nasze lotnisko." << endl;
    czyszczenie_konsoli();

    cout << "Kliknij m aby wyświetlić listę dostępnych maszyn." << endl;
    wyswietl_menu();
    cout << endl;
    cout << "Obecnie na lotnisku znajduje się 9 maszyn" << endl;
    czyszczenie_konsoli();

    Rysujczlowiek1();
    cout << "Spróbujmy wysłać dowolny samolot na ziemi w powietrze." << endl;
    while(true) {
    cout << "Podaj numer maszyny którą chcesz wysłać w powietrze: " << endl;
    cin >> numer;
    if (!sprawdzenie_czy_samolot2(numer))  continue;
    if (!sprawdzenie_czy_samolotjest(samoloty[numer - 1])) {
        cout << "Samolot musi być na ziemi. Podaj inny numer." << endl;
    }
    else break;
    } 
    odlot(samoloty[numer - 1], loty[numer - 1]); // Funkcja która wylatuje samolot, podaje się godziny oraz miejsca wylotu
    czyszczenie_konsoli();

    cout << "Kliknij m aby wyświetlić listę dostępnych maszyn." << endl;
    wyswietl_menu();
    cout << "Znakomicie! Jak widzisz samolot numer " << numer << " właśnie opuścił nasze lotnisko. " << endl;
    czyszczenie_konsoli();

    Rysujczlowiek1();
    cout << "Teraz spróbujmy sprowadzić na ziemię dowolny samolot." << endl;
    while (true) {
        cout << "Podaj numer maszyny która powinna wylądować: " << endl;
        cin >> numer2;
        if (!sprawdzenie_czy_samolot2(numer2))  continue;
        if (!sprawdzenie_czy_samolotjest2(samoloty[numer2 - 1])) {
            cout << "Samolot musi być w powietrzu. Podaj inny numer." << endl;
        }
        else break;
    }
    przylot(samoloty[numer2 - 1], loty[numer2 - 1]); // Funkcja która przylatuje samolot, podaje się godziny oraz miejsca wylotu 
    czyszczenie_konsoli();

    cout << "Kliknij m aby wyświetlić listę dostępnych maszyn." << endl;
    wyswietl_menu();
    cout << "Znakomicie! Jak widzisz samolot numer " << numer2 << " właśnie wylądował na naszym lotnisku. " << endl;
    czyszczenie_konsoli();

    Rysujczlowiek1();
    cout << "Teraz zatwierdź listę pasażerów dla dowolnego loty. Podaj numer samolotu, którego chcesz wyświetlić" << endl; // tu nw jak to zrobić
    int numer3;
    cin >> numer3;
    odczytajsamolot(planes[numer3-1]);
    czyszczenie_konsoli();

    Rysujczlowiek2();
    cout << "O nie! Kłopoty! Załoga samolotu zgłasza problem i prosi o awaryjne lądowanie na twoim lotnisku. Czy wyrażasz zgodę? " << endl;
    cin >> zgoda;
    if (zgoda == "tak") {
        awaria();
    }
    else if (zgoda == "TAK") {
        awaria();
    }
    else if (zgoda == "Tak") {
        awaria();
    }
    czyszczenie_konsoli();
    cout << "Kliknij m aby wyświetlić listę dostępnych maszyn." << endl;
    wyswietl_menu();
    czyszczenie_konsoli();
    bool exitProgram = false;
    do {
        main_menu();
        //czysczenie_konsoli2();
    } while (!exitProgram);
    
    return 0;
}