
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string imie,adres;
int sposob,menu,cena=0,stolik,godzina,ilosc_koszyka;
string danie_koszyka;
double wartoscKoszyka;
int ileporcji=0;
int cosjeszcze = 0;
int identificator;
int i,j,x = 0;

bool good();
bool is_open();

class chart {
    int id;
    string name;
    int price;
    int porcje;
public:
    void getChart();
    void putChart();
};

void chart::getChart() {
    id = identificator;
    name = danie_koszyka;
    price = wartoscKoszyka;
    porcje = ilosc_koszyka;
};
void chart::putChart() {
    cout <<
};

//menu glowne

void glowna()
{
    cout <<"1.MENU"<< endl<<"2.ZLOZ ZAMOWIENIE"<< endl<<"3.PODSUMOWANIE"<< endl<<"4.INFORMACJE O RESTAURACJI"<< endl<<"5.ZAKONCZ"<<endl<< "6.ZAKONCZ PROGRAM" << endl;
    cin >> menu;
}
void plikTXTmenu(){
    ifstream file;
    file.open("menu.txt");

    string line;
    while (file.good()){
        getline(file, line);

        cout << line << endl;
    }
    file.close();
    {
        /* code */
    }

}

void zlozZamowienie (){
    chart chart[10];

    cout << "PODAJ IMIE: "<<endl;
    cin >> imie;
    cout << "WITAJ: \"" << imie << "\"" << endl;
    cout <<"WYBIERZ RODZAJ ZAMOWIENIA"<< endl<<"1.DOSTAWA (KOSZT DOSTAWY 15 zl) || 2.NA MIEJSCU" << endl;
    cin>>sposob;

    // ZŁY RODZAJ DOSTAWY
    while(sposob<0||sposob>2)
    {
        cout <<"PODAJ POPRAWNY RODZAJ ZAMOWIENIA";
        cout <<"1.DOSTAWA (KOSZT DOSTAWY 15 zl) || 2.NA MIEJSCU" << endl;
        cin>>sposob;
    }
     if (sposob == 1){
         cout << "WYBRALES: DOSTAWA DO DOMU"<< endl;
         cena+=15;
         cout << "PODAJ ADRES DOSTAWY"<< endl;
         cin>>adres;
         cout<<"Przewidywany czas dostawy to: 1 godzina"<< endl;
         cin>>godzina;

            while(godzina<8||godzina>23){
               cout << "RESTAURACJA W TYCH GODZINACH JEST ZAMKNIETA"<< endl;
               cout << "PODAJ POPRAWNA GODZINE"<< endl;
               cin>>godzina;
           }
     } else if (sposob == 2){
         cout << "WYBRALES: NA MIEJSCU"<< endl;
         cout<<"PODAJ NR STOLIKA PRZY KTORYM SIEDISZ (1-12)"<< endl;
         cin>>stolik;

         while(stolik<1||stolik>12){
             cout << "ZLY NUMER STOLIKA"<< endl;
             cout << "PODAJ NR STOLIKA DO REZERWACJI OD 1 DO 12"<< endl;
             cin>>stolik;
         }
     }
    plikTXTmenu();
    ifstream inputfile("cennik1.txt");

    if (!inputfile.is_open())
        cout<<"Error opening file";

    string linemenu;
    int row = 28;
    int rowhalf = row/2;



    std::string TABtxt[row];
    std::string TABname[rowhalf];
    double TABprice[rowhalf];

    for (int r = 0; r < row; r++) {

        std::getline(inputfile, linemenu);
        TABtxt[r] = linemenu;

    }

    for(i=0,j=0 ; j<row ; i++,j+=2) {

        TABname[i]=TABtxt[j+1];

        double num;
        stringstream ss;
        ss << TABtxt[j];
        ss >> num;
        TABprice[i]= num;
    }

    inputfile.close();

    do {
        for(int z = 0; z<10; z++){
            chart[z].getChart();
        };

        cout << "WYBIERZ CO CHCESZ ZAMOWIC" << endl;
        cin >> x;
        cout << "WYBRANO: " << TABname[x] << " CENA " << TABprice[x] << " ZL" << endl;

        cout << "Wybierz czy chesz:" << endl;
        cout << "1. Zamawiać jeszcze \n 2. Zakończyć" << endl;
        wartoscKoszyka = TABprice[i];
        danie_koszyka = TABname[i];
        ilosc_koszyka=ileporcji;
    } while (cosjeszcze == 2);




    cout << "WYBRANO: " << TABname[i] << " CENA " << TABprice[i] << " ZL" << endl;

    cout << "ILE PORCJI WYBRANEGO DANIA CHCESZ ZAMOWIC" << endl;
    cin >> ileporcji;


    if (ileporcji == 1 ){
        cout << "WYBRALES " << ileporcji << " PORCJE TEGO DANIA O LACZNEJ CENIE: " << TABprice[i]*ileporcji << " ZL" << endl;
    } else if (ileporcji > 1){
        cout << "WYBRALES " << ileporcji << " PORCJi TEGO DANIA O LACZNEJ CENIE: " << TABprice[i]*ileporcji << " ZL" << endl;
    }

    wartoscKoszyka = TABprice[i];
    danie_koszyka = TABname[i];
    ilosc_koszyka=ileporcji;


}




void twojezamowienie()
{
    plikTXTmenu();

    ifstream inputfile("cennik1.txt");

    if (!inputfile.is_open())
        cout<<"Error opening file";

    /*
    int numberline;
    while (std::getline(inputfile, linemenu)){
    numberline++; }
    int row = numberline;
    */

    string linemenu;
    int row = 28;
    int rowhalf = row/2;
    int i,j;


    std::string TABtxt[row];
    std::string TABname[rowhalf];
    double TABprice[rowhalf];

    for (int r = 0; r < row; r++) {

        std::getline(inputfile, linemenu);
        TABtxt[r] = linemenu;

    }

    for(i=0,j=0 ; j<row ; i++,j+=2) {

        TABname[i]=TABtxt[j+1];

        double num;
        stringstream ss;
        ss << TABtxt[j];
        ss >> num;
        TABprice[i]= num;
    }


//    for (int r = 0; r < row; r++) {
//    cout << TABtxt[r];
//    cout<<endl;}
//
//    for (int a = 0; a < rowhalf; a++) {
//    cout << TABprice[a];
//    cout<<endl;}
//
//    for (int b = 0; b < rowhalf; b++) {
//    cout << TABname[b];
//    cout<<endl;}


    inputfile.close();

//    int ileporcji=0;


}

//void zamowienie()
//{
//
//               cout << "----DANE----"<< endl;
//               cout << "NAME:" << imie<<endl;
//               cout << "WYBRALES: DOSTAWA DO DOMU"<< endl;
////               cout <<"ZAMOWIONE NA GODZINE:"<<godzina<<endl;
//               cout <<"ZAMOWIONE NA ADRES:"<<adres<<endl;
//if (sposob==2){
//       cout << "WYBRALES: NA MIEJSCU"<< endl;
//       cout<<"PODAJ GODZINE REZERWACJI"<< endl;
//         cin>>godzina;
//           if(godzina<8||godzina>23){
//               while(godzina<8||godzina>23){
//                   cout << "RESTAURACJA W TYCH GODZINACH JEST ZAMKNIETA"<< endl;
//                   cout << "PODAJ POPRAWNA GODZINE"<< endl;
//                   cin>>godzina;
//               }
//           }
//           cout<<"PODAJ NR STOLIKA PRZY KTORYM SIEDISZ (1-12)"<< endl;
//         cin>>stolik;
//
//           if(stolik<1||stolik>12){
//
//           }
//
//               cout << "----DANE----"<< endl;
//               cout << "NAME:" << imie<<endl;
//               cout << "WYBRALES: NA MIEJSCU"<< endl;
//               cout <<"STOLIK ZAMOWIONY NA GODZINE:"<<godzina<<endl;
//                cout <<"NR.STOLIKA:"<<stolik<<endl;
//
//
//    }
//    cout <<""<< endl;
//    twojezamowienie();
//}

void info()
{
cout <<"POZNANSKA 28"<< endl<<"WLASCICIEL CDV"<< endl<<"GODZINY OTWARCIA 8-23"<<endl;
}

void zakonczenie()
{
    cout << "DZIEKI ZA ODWIEDZINY"<< endl;

}
//main

/*void plikTXTceny() {

    ifstream inputfile("cennik1.txt");

    if (!inputfile.is_open())
    cout<<"Error opening file";


    /*
    int numberline;
    while (std::getline(inputfile, linemenu)){
    numberline++; }
    int row = numberline;


    string linemenu;
    int row = 28;
    int rowhalf = row/2;
    int i,j;


    std::string TABtxt[row];
    std::string TABname[rowhalf];
    double TABprice[rowhalf];



    for (int r = 0; r < row; r++) {

        std::getline(inputfile, linemenu);
        TABtxt[r] = linemenu;

    }




    for(i=0,j=0 ; j<row ; i++,j+=2) {

        TABname[i]=TABtxt[j+1];

        double num;
        stringstream ss;
        ss << TABtxt[j];
        ss >> num;
        TABprice[i]= num;
    }


    for (int r = 0; r < row; r++) {
    cout << TABtxt[r];
    cout<<endl;}

    for (int a = 0; a < rowhalf; a++) {
    cout << TABprice[a];
    cout<<endl;}

    for (int b = 0; b < rowhalf; b++) {
    cout << TABname[b];
    cout<<endl;}


    inputfile.close();
}*/


double koszyk() {
    if (wartoscKoszyka != 0) {
        if (sposob == 2) {
            cout << "TWOJE ZAMOWIENIE: " << ilosc_koszyka << "x" << danie_koszyka << " O CENIE " << wartoscKoszyka
                 << " ZL" << endl;
            cout << "LACZNA WARTOSC " << wartoscKoszyka << " ZL" << endl;

        } else {
            cout << "TWOJE ZAMOWIENIE: " << ilosc_koszyka << "x" << danie_koszyka << " O CENIE " << wartoscKoszyka
                 << " ZL" << endl;
            cout << "LACZNA WARTOSC (KOSZT DOSTAWY 15 zl) " << (wartoscKoszyka * ilosc_koszyka) + 15 << " ZL" << endl;
        }

    } else {
        cout << "TWOJ KOSZYK JEST PUSTY " << endl;
    };
    return 0;
};

int paragon(){
    ofstream file_;
    file_.open("paragon.txt");
    if(sposob==2) {
        file_ << "POZNANSKA 28" << endl << "WLASCICIEL CDV" << endl << "GODZINY OTWARCIA 8-23" << endl << "NAME:" << imie << endl << "WYBRALES: NA MIEJSCU" << endl
              << "STOLIK ZAMOWIONY NA GODZINE: " << godzina << endl << "NR.STOLIKA:" << stolik << endl << "______PARAGON_FISKALNY______" << endl << ilosc_koszyka <<
              "x" << danie_koszyka << " - " << wartoscKoszyka << endl << "LACZNIE DO ZAPLATY:" << wartoscKoszyka * ilosc_koszyka << " ZL" << endl;

    } else{
        file_ << "POZNANSKA 28" << endl << "WLASCICIEL CDV" << endl << "GODZINY OTWARCIA 8-23" << "WYBRALES: DOSTAWE" << endl << "JEDZENIE DOSTARCZYMY POD ADRES:"
              << adres << endl << "O GODZINIE" << godzina << endl << "______PARAGON_FISKALNY______" << endl
              << ilosc_koszyka << "x" << danie_koszyka << " - " << wartoscKoszyka << endl << "LACZNIE DO ZAPLATY:" << (wartoscKoszyka * ilosc_koszyka) + 15 << " ZL" << endl;

    };
    file_.close();
    std::cin.get();
    return 0;
}
int main()
{
     cout<<"WITAMY W BARZE POSTAPO"<<endl;
     cout<<endl;
     while(menu=4){
     glowna();

     switch(menu)
    {
        //MENUUU
        case 1:
            plikTXTmenu();
            break;
        case 2:
            twojezamowienie();
            cout << endl;

            break;
        //SKLADANIE ZAMOWIEN
        case 3:
             zamowienie();
             cout<<endl;
            break;
        case 4:
            info();
            cout<<endl;
            break;
        case 5:
            koszyk();
            cout<<endl;
            break;
        case 6:
            zakonczenie();
            paragon();
            cout<<endl;
            return 0;

        }
     }
return 0;
}
