#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Przyjaciel {
    int idPrzyjaciela = 0;
    int idUzytkownika = 0;
    string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "";
};

struct Uzytkownik {
    int idUzytkownika = 0;
    string login = "", haslo = "";
};

int nadajIdPrzyjacielowi() {

    string czescLini = "";
    char znak = '|';
    int liczbaZnakow = 0;
    int idPobraneZplikuTXT = 0;
    int idNowoNadane = 0;
    fstream plikKsiazki;

    plikKsiazki.open("ksiazkaAdresowa.txt", ios::in);

    if (plikKsiazki.good() == false) {
        cout << "Nie istnieje plik ksiazki adresowej." << endl;
    } else {
        while( getline(plikKsiazki, czescLini, znak)) {

            switch(liczbaZnakow) {
            case 0:
                idPobraneZplikuTXT = atoi(czescLini.c_str());
                break;
            }
            if (liczbaZnakow == 6) {

                idNowoNadane = idPobraneZplikuTXT + 1;
                liczbaZnakow = 0;

            } else {

                liczbaZnakow++;
            }

        }
    }

    plikKsiazki.close();

    return idNowoNadane;

}

void dodajPrzyjaciela(vector <Przyjaciel> &przyjaciele, int idUzytkownika) {

    Przyjaciel nowyPrzyjaciel;
    string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "";
    fstream plikKsiazki;

    //Pobranie danych nowego przyjaciela

    system("cls");

    cout << "Dodawanie danych Przyjaciela" << endl << endl;

    cout << "Podaj imie przyjaciela: ";
    cin.sync();
    getline(cin, imie);

    cout << "Podaj nazwisko przyjaciela: ";
    cin.sync();
    getline(cin, nazwisko);

    cout << "Podaj numer telefonu przyjaciela: ";
    cin.sync();
    getline(cin, nrTelefonu);

    cout << "Podaj email przyjaciela: ";
    cin.sync();
    getline(cin, email);

    cout << "Podaj adres przyjaciela: ";
    cin.sync();
    getline(cin, adres);


    //Nadanie id przyjacielowi
    int idPrzyjaciela = nadajIdPrzyjacielowi();

    cout << "Id przyjaciela: " << idPrzyjaciela << endl;
    cout << "funkcja nadania id: " << nadajIdPrzyjacielowi()<<endl;
    system("pause");

    //Dodanie przyjaciela do wektora przyjaciol

    nowyPrzyjaciel.idPrzyjaciela = idPrzyjaciela;

    nowyPrzyjaciel.idUzytkownika = idUzytkownika;

    nowyPrzyjaciel.imie = imie;

    nowyPrzyjaciel.nazwisko = nazwisko;

    nowyPrzyjaciel.nrTelefonu = nrTelefonu;

    nowyPrzyjaciel.email = email;

    nowyPrzyjaciel.adres = adres;

    przyjaciele.push_back(nowyPrzyjaciel);

    // Dodanie danych przyjaciela do pliku .txt

    plikKsiazki.open("ksiazkaAdresowa.txt", ios::out | ios::app);

    plikKsiazki << idPrzyjaciela << "|" << idUzytkownika << "|" << imie << "|" << nazwisko << "|" << nrTelefonu << "|"
                << email << "|" << adres << "|" << endl;

    plikKsiazki.close();
}

void wczytajOsobyZPliku(vector <Przyjaciel> &przyjaciele, int idUzytkownika) {

    Przyjaciel nowyPrzyjaciel;
    fstream plikKsiazki;
    string czescLini = "";
    char znak = '|';
    int liczbaZnakow = 0;

    plikKsiazki.open("ksiazkaAdresowa.txt", ios::in);

    if (plikKsiazki.good() == false) {
        cout << "Nie istnieje plik ksiazki adresowej." << endl;
    } else {
        while( getline(plikKsiazki, czescLini, znak)) {

            switch(liczbaZnakow) {
            case 0:
                nowyPrzyjaciel.idPrzyjaciela = atoi(czescLini.c_str());
                break;
            case 1:
                nowyPrzyjaciel.idUzytkownika = atoi(czescLini.c_str());
                break;
            case 2:
                nowyPrzyjaciel.imie = czescLini;
                break;
            case 3:
                nowyPrzyjaciel.nazwisko = czescLini;
                break;
            case 4:
                nowyPrzyjaciel.nrTelefonu = czescLini;
                break;
            case 5:
                nowyPrzyjaciel.email = czescLini;
                break;
            case 6:
                nowyPrzyjaciel.adres = czescLini;
                break;
            }

            if (liczbaZnakow == 6) {

                if (idUzytkownika == nowyPrzyjaciel.idUzytkownika) {

                    przyjaciele.push_back(nowyPrzyjaciel);

                }
                liczbaZnakow = 0;

            } else {

                liczbaZnakow++;
            }
        }
    }
    plikKsiazki.close();
}

void wypiszDane (vector <Przyjaciel> przyjaciele, int nrPozycjiPrzyjacielaWVektorze) {
    cout << "IdPrzyjaciela: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].idPrzyjaciela << endl;
    cout << "IdUzytkownika: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].idUzytkownika << endl;
    cout << "Imie: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].imie << endl;
    cout << "Nazwisko: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].nazwisko << endl;
    cout << "Numer telefonu: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].nrTelefonu << endl;
    cout << "Email: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].email << endl;
    cout << "Adres: " << przyjaciele[nrPozycjiPrzyjacielaWVektorze].adres << endl;
}

void wypiszDaneWszystkichPrzyjaciol(vector <Przyjaciel> przyjaciele) {
    for ( int i = 0; i < przyjaciele.size(); i++ ) {
        wypiszDane(przyjaciele, i);
    }
}

void wypiszDaneWszystkichPrzyjaciolOPodanymImieniu(vector <Przyjaciel> przyjaciele, string SzukaneImie) {
    int CzyJestTakieImie=0;
    for ( int i = 0; i < przyjaciele.size(); i++ ) {
        if (przyjaciele[i].imie == SzukaneImie) {
            wypiszDane(przyjaciele, i);
            CzyJestTakieImie++;
        }
    }
    if (CzyJestTakieImie == 0) {
        cout << "Nie zostaly wprowadzone dane przyjaciela o takim imieniu." << endl;
    }
}

void wypiszDaneWszystkichPrzyjaciolOPodanymNazwisku(vector <Przyjaciel> przyjaciele, string SzukaneNazwisko) {
    int CzyJestTakieNazwisko=0;
    for ( int i = 0; i < przyjaciele.size(); i++ ) {
        if (przyjaciele[i].nazwisko == SzukaneNazwisko) {
            wypiszDane(przyjaciele, i);
            CzyJestTakieNazwisko++;
        }
    }
    if (CzyJestTakieNazwisko == 0) {
        cout << "Nie zostaly wprowadzone dane przyjaciela o takim nazwisku." << endl;
    }
}

void zapiszZmianyWpliku (vector <Przyjaciel> &przyjaciele, int id) {

    Przyjaciel Przyjaciel;

    fstream plikKsiazki;
    fstream nowyPlikKsiazki;

    string czescLini = "";
    char znak = '|';
    int liczbaZnakow = 0;

    plikKsiazki.open("ksiazkaAdresowa.txt", ios::in);
    nowyPlikKsiazki.open("TymczasowaKsiazkaAdresowa.txt", ios::out | ios::trunc);

    while (getline(plikKsiazki, czescLini, znak)) {

        switch(liczbaZnakow) {
        case 0:
            Przyjaciel.idPrzyjaciela = atoi(czescLini.c_str());
            break;
        case 1:
            Przyjaciel.idUzytkownika = atoi(czescLini.c_str());
            break;
        case 2:
            Przyjaciel.imie = czescLini;
            break;
        case 3:
            Przyjaciel.nazwisko = czescLini;
            break;
        case 4:
            Przyjaciel.nrTelefonu = czescLini;
            break;
        case 5:
            Przyjaciel.email = czescLini;
            break;
        case 6:
            Przyjaciel.adres = czescLini;
            break;
        }

        if ( liczbaZnakow == 6 ) {

            liczbaZnakow = 0;

            if(Przyjaciel.idPrzyjaciela == id) {

                int nrPozycjiWVektorze = 0;
                bool czyPrzyjacielIstnieje = false;

                for (int i = 0; i < przyjaciele.size(); i++) {
                    if (id == przyjaciele[i].idPrzyjaciela) {
                        nrPozycjiWVektorze = i;
                        czyPrzyjacielIstnieje = true;
                    }
                }

                if (czyPrzyjacielIstnieje == true) {
                    nowyPlikKsiazki << przyjaciele[nrPozycjiWVektorze].idPrzyjaciela << "|"
                                    << przyjaciele[nrPozycjiWVektorze].idUzytkownika << "|"
                                    << przyjaciele[nrPozycjiWVektorze].imie << "|"
                                    << przyjaciele[nrPozycjiWVektorze].nazwisko << "|"
                                    << przyjaciele[nrPozycjiWVektorze].nrTelefonu << "|"
                                    << przyjaciele[nrPozycjiWVektorze].email << "|"
                                    << przyjaciele[nrPozycjiWVektorze].adres << "|" << endl;
                } else {
                    cout << "Dane usuniete";
                }

            } else {

                nowyPlikKsiazki << Przyjaciel.idPrzyjaciela << "|"
                                << Przyjaciel.idUzytkownika << "|"
                                << Przyjaciel.imie << "|"
                                << Przyjaciel.nazwisko << "|"
                                << Przyjaciel.nrTelefonu << "|"
                                << Przyjaciel.email << "|"
                                << Przyjaciel.adres << "|" << endl;

            }
        } else {

            liczbaZnakow++;
        }

    }

    plikKsiazki.close();
    nowyPlikKsiazki.close();

    //Usuniecie niezmienionej ksiazki
    if( remove( "ksiazkaAdresowa.txt" ) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );

    //Zmiana nazwy tymczasowej ksiazki na glowna ksiazke
    int result;
    char oldname[] ="TymczasowaKsiazkaAdresowa.txt";
    char newname[] ="ksiazkaAdresowa.txt";
    result= rename( oldname, newname );
    if ( result == 0 )
        puts ( "File successfully renamed" );
    else
        perror( "Error renaming file" );
}

void zapiszZmianyWplikuUzytkownikow (vector <Uzytkownik> &uzytkownicy) {

    fstream plikKsiazki;

    plikKsiazki.open("UzytkownicyKsiazkiAdresowej.txt", ios::out | ios::trunc);

    for ( int nrPozycjiWVektorze = 0; nrPozycjiWVektorze < uzytkownicy.size(); nrPozycjiWVektorze++ ) {

        plikKsiazki << uzytkownicy[nrPozycjiWVektorze].idUzytkownika << "|"
                    << uzytkownicy[nrPozycjiWVektorze].login << "|"
                    << uzytkownicy[nrPozycjiWVektorze].haslo << "|";
    };

    plikKsiazki.close();
}

void usunDanePrzyjaciela(vector <Przyjaciel> &przyjaciele) {

    const char znakPotwierdzenia = 't';
    char znakWczytany;
    int id, nrPozycjiWVektorze = 0;
    bool czySaDaneDlaDanegoId = false;

    cout << "Podaj numer id przyjaciela, ktorego dane chcesz usunac:";
    cin >> id;

    for (int i = 0; i < przyjaciele.size(); i++) {
        if (id == przyjaciele[i].idPrzyjaciela) {
            czySaDaneDlaDanegoId = true;
            nrPozycjiWVektorze = i;
        }
    }

    if ( czySaDaneDlaDanegoId == true) {
        cout << endl << "Dane ktore chcesz usunac:" << endl;
        wypiszDane(przyjaciele, nrPozycjiWVektorze);

        cout << endl << "Jesli na pewno chcesz usunac dane tego przyjaciela wcisnij klawisz 't' i potwierdz wybor enterem." << endl;
        cout << "Jesli nie chcesz usunac danych tego przyjaciela wcisnij dowolny klawisz inny niz 't'." << endl;
        cin >> znakWczytany;

        if (znakWczytany == znakPotwierdzenia) {

            przyjaciele.erase(przyjaciele.begin()+ nrPozycjiWVektorze);

            zapiszZmianyWpliku(przyjaciele, id);

        } else {

            cout << "Dane przyjaciela nie zostaly usuniete." << endl;
        }
    } else {
        cout << "Nie ma danych dla podanego numeru id." << endl;
    }
}

void edytujDanePrzyjaciela(vector <Przyjaciel> &przyjaciele) {

    int id, nrPozycjiWVektorze = 0;
    bool czySaDaneDlaDanegoId = false;

    cout << "Podaj numer id przyjaciela, ktorego dane chcesz edutowac:";
    cin >> id;

    for (int i = 0; i < przyjaciele.size(); i++) {
        if (id == przyjaciele[i].idPrzyjaciela) {
            czySaDaneDlaDanegoId = true;
            nrPozycjiWVektorze = i;
        }
    }

    if ( czySaDaneDlaDanegoId == true) {
        cout << endl << "Dane ktore chcesz edytowac:" << endl;
        wypiszDane(przyjaciele, nrPozycjiWVektorze);
        system("pause");

        char opcja;
        bool wyjdz = false;

        while(wyjdz == false) {
            system("cls");

            cout << "Wybierz co zmienic" << endl << endl;
            cout << "1. Imie." << endl;
            cout << "2. Nazwisko." << endl;
            cout << "3. Numer telefonu." << endl;
            cout << "4. Email." << endl;
            cout << "5. Adres." << endl;
            cout << "6. Powrot do menu glownego." << endl;
            cin >> opcja;

            string zmiana = "";

            switch(opcja) {
            case '1': {
                system("cls");
                cout << "Podaj nowe imie:";
                cin.sync();
                getline(cin, zmiana);
                przyjaciele[nrPozycjiWVektorze].imie = zmiana;
                zapiszZmianyWpliku(przyjaciele, id);
                system("pause");
            }
            break;
            case '2': {
                system("cls");
                cout << "Podaj nowe nazwisko:";
                cin.sync();
                getline(cin, zmiana);
                przyjaciele[nrPozycjiWVektorze].nazwisko = zmiana;
                zapiszZmianyWpliku(przyjaciele, id);
                system("pause");
            }
            break;
            case '3': {
                system("cls");
                cout << "Podaj nowy numer telefonu:";
                cin.sync();
                getline(cin, zmiana);
                przyjaciele[nrPozycjiWVektorze].nrTelefonu = zmiana;
                zapiszZmianyWpliku(przyjaciele, id);
                system("pause");
            }
            break;
            case '4': {
                system("cls");
                cout << "Podaj nowy email:";
                cin.sync();
                getline(cin, zmiana);
                przyjaciele[nrPozycjiWVektorze].email = zmiana;
                zapiszZmianyWpliku(przyjaciele, id);
                system("pause");
            }
            break;
            case '5': {
                system("cls");
                cout << "Podaj nowy adres:";
                cin.sync();
                getline(cin, zmiana);
                przyjaciele[nrPozycjiWVektorze].adres = zmiana;
                zapiszZmianyWpliku(przyjaciele, id);
                system("pause");
            }
            break;
            case '6': {
                wyjdz = true;
            }
            break;
            default: {
                cout << "Nie ma takiej opcji" << endl;
                system("pause");
            }
            break;
            }
        }
    }
}

void wczytajDaneUzytkownikowZPliku(vector <Uzytkownik> &uzytkownicy) {

    Uzytkownik nowyUzytkownik;
    fstream plikKsiazki;
    string czescLini = "";
    char znak = '|';
    int liczbaZnakow = 0;

    plikKsiazki.open("UzytkownicyKsiazkiAdresowej.txt", ios::in);

    if (plikKsiazki.good() == false) {
        cout << "Nie istnieje plik ksiazki adresowej." << endl;
    } else {
        while( getline(plikKsiazki, czescLini, znak)) {

            switch(liczbaZnakow) {
            case 0:
                nowyUzytkownik.idUzytkownika = atoi(czescLini.c_str());
                break;
            case 1:
                nowyUzytkownik.login = czescLini;
                break;
            case 2:
                nowyUzytkownik.haslo = czescLini;
                break;
            }

            if (liczbaZnakow == 2) {

                uzytkownicy.push_back(nowyUzytkownik);

                liczbaZnakow = 0;

            } else {

                liczbaZnakow++;
            }
        }
    }
    plikKsiazki.close();
}

void dodajUzytkownika(vector <Uzytkownik> &uzytkownicy) {

    Uzytkownik nowyUzytkownik;
    string login = "", haslo = "";
    fstream plikKsiazki;

    //Pobranie danych nowego uzytkownika

    system("cls");

    cout << "Podaj login: ";
    cin.sync();
    getline(cin, login);

    cout << "Podaj haslo: ";
    cin.sync();
    getline(cin, haslo);

    //Nadanie identyfikatora uzytkownikowi

    int id;
    if (uzytkownicy.size() == 0) {
        id = 1;
    } else {
        int ostatniaPozycja = uzytkownicy.size()-1;
        id = uzytkownicy[ostatniaPozycja].idUzytkownika;
        id++;
    }
    //Dodanie przyjaciela do wektora przyjaciol

    nowyUzytkownik.idUzytkownika = id;

    nowyUzytkownik.login = login;

    nowyUzytkownik.haslo = haslo;

    uzytkownicy.push_back(nowyUzytkownik);

    // Dodanie danych przyjaciela do pliku .txt

    plikKsiazki.open("UzytkownicyKsiazkiAdresowej.txt", ios::out | ios::app);

    plikKsiazki << id << "|" << login << "|" << haslo << "|" << endl;

    plikKsiazki.close();
}

int ZnajdzIdDlaDanegoLoginu(vector <Uzytkownik> &uzytkownicy, string SzukanyLogin) {
    int CzyJestTakiLogin=0;
    int id = 0;
    for ( int i = 0; i < uzytkownicy.size(); i++ ) {
        if (uzytkownicy[i].login == SzukanyLogin) {
            id = uzytkownicy[i].idUzytkownika;
            CzyJestTakiLogin++;
        }
    }
    if (CzyJestTakiLogin == 0) {
        cout << "Nie ma takiego loginu w spisie uzytkownikow." << endl;
    }
    return id;
}

string ZnajdzHasloDlaDanegoLoginu(vector <Uzytkownik> &uzytkownicy, string SzukanyLogin) {
    int CzyJestTakiLogin=0;
    string haslo = "";
    for ( int i = 0; i < uzytkownicy.size(); i++ ) {
        if (uzytkownicy[i].login == SzukanyLogin) {
            haslo = uzytkownicy[i].haslo;
            CzyJestTakiLogin++;
        }
    }
    if (CzyJestTakiLogin == 0) {
        cout << "Nie ma takiego loginu w spisie uzytkownikow." << endl;
    }
    return haslo;
}

bool sprawdzLoginIHaslo (vector <Uzytkownik> &uzytkownicy, string sprawdzaneLogin) {
    bool czyHasloJestPoprawne = false;
    string haslo = "";
    for(int i=1; i<=3; i++) {
        cout << "Proba "<< i << " na 3" << endl;
        cout << "Podaj haslo: ";
        cin >> haslo;

        if (haslo == ZnajdzHasloDlaDanegoLoginu(uzytkownicy, sprawdzaneLogin)) {
            return true;
        } else {
            cout << "Podany login lub haslo jest nieprawidlowe." << endl;
            cout << "Prosze sprobowac ponownie.\n" << endl;
        }
    }
    return czyHasloJestPoprawne;
}

void wypiszDaneUzytkownika (vector <Uzytkownik> uzytkownicy, int nrPozycjiUzytkownikaWVektorze) {
    cout << "Id: " << uzytkownicy[nrPozycjiUzytkownikaWVektorze].idUzytkownika << endl;
    cout << "Login: " << uzytkownicy[nrPozycjiUzytkownikaWVektorze].login << endl;
    cout << "Haslo: " << uzytkownicy[nrPozycjiUzytkownikaWVektorze].haslo << endl;
}

void wypiszDaneWszystkichUzytkownikow(vector <Uzytkownik> uzytkownicy) {
    for ( int i = 0; i < uzytkownicy.size(); i++ ) {
        wypiszDaneUzytkownika(uzytkownicy, i);
    }
}

void zmianaHaslaUzytkownika(vector <Uzytkownik> &uzytkownicy) {

    string login = "";
    int id, nrPozycjiWVektorze = 0;
    bool czySaDaneDlaDanegoLoginu = false;

    cout << "Podaj login:";
    cin >> login;

    if (sprawdzLoginIHaslo(uzytkownicy, login) == true) {
        string zmiana = "";

        cout << "Podaj nowe haslo:";
        cin.sync();
        getline(cin, zmiana);
        uzytkownicy[nrPozycjiWVektorze].haslo = zmiana;
        zapiszZmianyWplikuUzytkownikow(uzytkownicy);
        cout << "Haslo zostalo zmienione" << endl;
        system("pause");
    } else {
        cout << "Nie istnieje uzytkownik o danym loginie"<< endl;
    }

}

int zwrocIdZalogowanegoUzytkownika(vector <Uzytkownik> uzytkownicy, string SzukanyLogin) {
    int CzyJestTakiLogin=0;
    for ( int i = 0; i < uzytkownicy.size(); i++ ) {
        if (uzytkownicy[i].login == SzukanyLogin) {
            return uzytkownicy[i].idUzytkownika;
            CzyJestTakiLogin++;
        }
    }
    if (CzyJestTakiLogin == 0) {
        cout << "Nie ma takiego loginu w spisie uzytkownikow." << endl;
    }
}

void wyswietlMenuKsiazkiAdresowejUzytkownika (vector <Przyjaciel> &przyjaciele, vector <Uzytkownik> &uzytkownicy, string login) {

    bool wyloguj = false;

    while (wyloguj == false) {
        char opcja;
        string wyrazenieDoZnalezieniaWKsiazce = "";

        system("cls");

        cout << "KSIAZKA ADRESOWA - Menu uzytkownika" << endl << endl;
        cout << "1. Dodaj dane przyjaciela." << endl;
        cout << "2. Znajdz dane przyjaciela." << endl;
        cout << "3. Wyswietl dane wszystkich przyjaciol." << endl;
        cout << "4. Usun dane przyjaciela." << endl;
        cout << "5. Edutuj dane przyjaciela." << endl;
        cout << "6. Zmien haslo." << endl;
        cout << "9. Wyloguj sie." << endl;
        cin >> opcja;

        switch(opcja) {
        case '1': {
            system("cls");
            dodajPrzyjaciela(przyjaciele, zwrocIdZalogowanegoUzytkownika(uzytkownicy, login));
            system("pause");
        }
        break;
        case '2': {
            system("cls");

            cout << "KSIAZKA ADRESOWA" << endl << endl;
            cout << "1. Szukaj wedlug imienia." << endl;
            cout << "2. Szukaj wedlug nazwiska." << endl;
            cin >> opcja;

            switch(opcja) {
            case '1': {
                system("cls");
                cout << "Uwaga! Wyszukiwanie bierze pod uwage wielkosc liter" << endl << endl;
                cout << "Podaj imie jakie chcesz wyszukac: ";
                cin.sync();
                getline(cin, wyrazenieDoZnalezieniaWKsiazce);

                wypiszDaneWszystkichPrzyjaciolOPodanymImieniu(przyjaciele, wyrazenieDoZnalezieniaWKsiazce);
                system("pause");
            }
            break;
            case '2': {
                system("cls");
                cout << "Uwaga! Wyszukiwanie bierze pod uwage wielkosc liter" << endl << endl;
                cout << "Podaj nazwisko jakie chcesz wyszukac: ";
                cin.sync();
                getline(cin, wyrazenieDoZnalezieniaWKsiazce);

                wypiszDaneWszystkichPrzyjaciolOPodanymNazwisku(przyjaciele, wyrazenieDoZnalezieniaWKsiazce);
                system("pause");
            }
            break;
            }
        }
        break;
        case '3': {
            system("cls");

            if (przyjaciele.size() == 0) {
                cout << "Nie masz jeszcze przyjaciol w ksiazce adresowej." << endl;
            } else {
                wypiszDaneWszystkichPrzyjaciol(przyjaciele);
            }
            system("pause");
        }
        break;
        case '4': {
            system("cls");
            usunDanePrzyjaciela(przyjaciele);
            system("pause");
        }
        break;
        case '5': {
            system("cls");
            edytujDanePrzyjaciela(przyjaciele);
        }
        break;
        break;
        case '6': {
            system("cls");
            zmianaHaslaUzytkownika(uzytkownicy);
        }
        break;
        case '9': {
            wyloguj = true;
        }
        break;
        default: {
            cout << "Nie ma takiej opcji" << endl;
            system("pause");
        }
        break;
        }
    }
}

int main() {

    vector <Uzytkownik> uzytkownicy;
    wczytajDaneUzytkownikowZPliku(uzytkownicy);

    while (1) {
        char opcja;

        system("cls");

        cout << "KSIAZKA ADRESOWA - panel logowania/rejestracji" << endl << endl;
        cout << "1. Logowanie." << endl;
        cout << "2. Rejestracja." << endl;
        cout << "9. Zamknij program." << endl;

        cin >> opcja;

        switch(opcja) {
        case '1': {
            string login = "";
            system("cls");
            cout << "LOGOWANIE" << endl;
            cout << "Podaj login:";
            cin.sync();
            getline(cin, login);
            if (sprawdzLoginIHaslo(uzytkownicy, login) == true) {

                vector <Przyjaciel> przyjaciele;
                wczytajOsobyZPliku(przyjaciele, ZnajdzIdDlaDanegoLoginu(uzytkownicy, login));
                wyswietlMenuKsiazkiAdresowejUzytkownika(przyjaciele, uzytkownicy, login);
            };
            system("pause");
        }
        break;
        case '2': {
            system("cls");
            cout << "REJESTRACJA" << endl;
            dodajUzytkownika(uzytkownicy);
            system("pause");
        }
        break;
        case '3': {
            system("cls");
            wypiszDaneWszystkichUzytkownikow(uzytkownicy);
            system("pause");
        }
        break;
        case '9': {
            exit(0);
        }
        break;
        default: {
            cout << "Nie ma takiej opcji" << endl;
            system("pause");
        }
        break;
        }
    }

    return 0;
}
