#pragma once

#include <string>
#include <iostream>
#include <conio.h>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include<windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits>


using namespace std;
////////KLASY///////////////
class Samolot;

class Lotnisko {
private:
    string nazwa_lotniska;
    int pojemnosc_lotniska;
    int pasy_startowe;
    int ilosc_pasazerow;

public:
    Lotnisko(string aa = "Miletown", int bb = 10, int cc = 2, int dd = 1500);

    friend void WyswietlInfoLotnisko(Lotnisko A);
    virtual ~Lotnisko();
};

class Pasazer {
private:
    string imie;
    string nazwisko;
public:
    Pasazer(string im, string na);
    friend void WyswietlInfo(Pasazer A);

    virtual ~Pasazer();
};
class Samolot {
private:
    int nr;
    string nazwa_samolotu;
    int rozmiar;
    string status;
    string czas_startu;
    string czas_ladowania;
    string stan;
public:
    //GETTER///
    string getInfoSamolotu() const {
        string info = "ID |" + to_string(nr) + "| Model |" + nazwa_samolotu + "| Numer |" + to_string(rozmiar) + "| Status |" + status + "| Odlot |" + czas_ladowania + "| Przylot |" + czas_startu + "|\n Stan maszyny |" + stan;
        return info;
    }
    // //KONSTRUKTORY/////
    Samolot(int, string, int, string, string, string, string);
    Samolot() {};
    //////FUNKCJE ZAPRZYJAZNIONE/////
    friend void WyswietlInfoSamolot(Samolot A);
    friend void TAKEOFF(Samolot& B);
    friend void ARRIVAL(Samolot& B);
    friend void napraw(Samolot& B);
    friend bool sprawdzenie_czy_samolotjest(Samolot& B);
    friend bool sprawdzenie_czy_samolotjest2(Samolot& B);
    friend bool sprawdzenie_stanu(Samolot& B);
    friend bool sprawdzenie_wolnych(Samolot& B);
    friend bool czyMoznaLadowac(Samolot& B);
    friend bool czyMoznaStartowac(Samolot& B);
    virtual ~Samolot();
};

class Lot : public Samolot {
private:
    string miejsce_startu;
    string miejsce_ladowania;

public:
    Lot(string, string);
    friend void przylot(Samolot& B, Lot& A);
    friend void odlot(Samolot& B, Lot& A);
    friend void miejsce_przylotu(Lot& A);
    friend void miejsce_odlotu(Lot& A);
    friend void WyswietlInfoLot2(Lot A);
    virtual ~Lot();

};
///////Funckje//////////
void wyswietl_menu();
void menu();
void czyszczenie_konsoli();
void awaria();
void WyswietlInfoSamoloty(const vector<Samolot>& samoloty, const vector<Lot>& loty);
void odczytajsamolot(vector<string>& a);
void generowanie_lotow();
bool czas(const string& time);
bool sprawdzenie_czy_samolot2(int B);
//////Zmienne Globalne///////////
extern vector<Samolot> samoloty;
extern vector<Samolot> powietrze;
extern vector<vector<string>>planes;
extern vector<Lot>loty;
//////////Samoloty/////////
extern vector<string> samolot1wektor;
extern vector<string> samolot2wektor;
/////Pliki Tekstowe//////
void wczytsamolot(ifstream& samolot, int i);
/////MENU////////
void main_menu();
/// ////RYSOWANIE///////
void Rysujsamolotp3();
void Rysujsamolotp1();
void Rysujsamolotp2();
void Rysujsamolotp4();
void Rysujsamolotp5();
void Rysujsamolotp6();

void Rysujsamoloto3();
void Rysujsamoloto1();
void Rysujsamoloto2();
void Rysujsamoloto4();
void Rysujsamoloto5();
void Rysujsamoloto6();
void Animacjaprzylot();
void Animacjaodlot();
void Rysujczlowiek1();
void Rysujczlowiek2();

void Rysujlotnisko();
