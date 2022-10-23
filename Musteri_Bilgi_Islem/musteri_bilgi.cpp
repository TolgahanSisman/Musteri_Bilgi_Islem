#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Musteri{
public:
    string tc;
    string adi;
    string soyadi;
    float borc;
    float alacak;
    float bakiye;
};


void MusteriListele();
void MusteriEkle();
void MusteriSil();
void MusteriGuncelle();
void MusteriAra();
float ToplamBakiye();


int main() {
    cout<<endl<<"\t--Menu--"<<endl;
    cout<<"1-Musteri Listeleme"<<endl;
    cout<<"2-Musteri Ekleme"<<endl;
    cout<<"3-Musteri Silme"<<endl;
    cout<<"4-Musteri Guncelleme"<<endl;
    cout<<"5-Musteri Arama"<<endl;
    cout<<"6-Toplam Bakiye"<<endl;

    int secim;
    cout << "Hangi islemi yapmak istiyorsunuz ? " << endl;
    cin >> secim;

    switch (secim) {

        case 1:{
            MusteriListele();
        }
            break;
        case 2:{
            MusteriEkle();
        }
            break;

        case 3:{
            MusteriSil();
        }
            break;

        case 4:{
            MusteriGuncelle();
        }
            break;

        case 5:{
            MusteriAra();
        }
            break;

        case 6:{
            ToplamBakiye();
        }
            break;
    }
    return 0;
}


void MusteriListele(){
    fstream dosya;
    dosya.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\a.txt");
    string satir;
    cout << "    TC\t"<<"     Ad  "<<"Soyad "<<"Borc "<<"Alacak  "<<"Bakiye\n";
    cout <<"--------------------------------------------------\n";
    while (getline(dosya, satir)){
        cout << satir <<endl;
    }
    dosya.close();
}

void MusteriEkle(){
    string tc, ad,soyad;
    float borc,alacak,bakiye;
    fstream dosya;
    dosya.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\a.txt", ios::app);
    cout << "Eklenecek kullanicinin bilgilerini giriniz" << endl;
    cout << "Tc: ";
    cin >> tc;
    cout << "Ad: ";
    cin >> ad;
    cout << "Soyad: ";
    cin >> soyad;
    cout << "Borc: ";
    cin >> borc;
    cout << "Alacak: ";
    cin >> alacak;
    bakiye=(borc-alacak);
    dosya << tc + " " + ad + " " + soyad + " " +to_string(borc) + " " + to_string(alacak) + " "+to_string(bakiye) << endl;
    cout << "Musteri a.txt dosyasina eklendi.\n";
    dosya.close();
}

void MusteriSil() {
    string tc, kelime;
    vector <string> v1;
    vector <string> v2;
    cout << "Silinecek kisinin tcsi: ";
    cin >> tc;

    fstream dosya;
    fstream dosya2;
    dosya.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\a.txt");
    dosya2.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\c.txt", ios::app);

    while (dosya >> kelime) {
        v2.push_back(kelime);
    }
    for (int i = 0; i != v2.size(); ++i) {
        v1.push_back(v2[i]);
        if (tc == v2[i]) {
            v1.pop_back();
            cout << v2[i] + " " + v2[i + 1] + " " + v2[i + 2] + " " + v2[i + 3] + " " + v2[i + 4] + " " + v2[i + 5] +
                    " Kisisi Silindi.\n\n";
            i = i + 5;
        }
    }
    for (int i = 0; i != v1.size(); ++i) {
        dosya2 << v1[i] << " ";
        if ( i % 6 == 5) {
            dosya2 << endl;
        }
    }
    dosya2.close();

    cout << "Guncel liste c.txt dosyasina aktarildi." << endl;
    cout << "Guncel Musteri Listesi\n" <<endl;
    cout << "    TC\t"<<"     Ad  "<<"Soyad "<<"Borc "<<"Alacak  "<<"Bakiye\n";
    cout <<"--------------------------------------------------\n";
    fstream dosya3;
    dosya3.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\c.txt");
    string satir;
    while (getline(dosya3, satir)){
        cout << satir <<endl;
    }
    dosya3.close();

}

void MusteriGuncelle(){
    string tc, kelime;
    vector <string> v1;
    vector <string> v2;
    cout << "Guncellenecek kisinin tcsi: ";
    cin >> tc;

    fstream dosya;
    fstream dosya2;
    dosya.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\a.txt");
    dosya2.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\d.txt", ios::app);

    while (dosya >> kelime) {
        v2.push_back(kelime);
    }
    for (int i = 0; i != v2.size(); ++i) {
        v1.push_back(v2[i]);
        if (tc == v2[i]) {
            v1.pop_back();
            cout << v2[i] + " " + v2[i + 1] + " Kisisinin bilgilerini yeniden gir.\n";
            i = i + 5;
        }
    }
    for (int i = 0; i != v1.size(); ++i) {
        dosya2 << v1[i] << " ";
        if ( i % 6 == 5) {
            dosya2 << endl;
        }
    }
    dosya2.close();

    string Mtc, ad,soyad;
    float borc,alacak,bakiye;
    fstream dosya5;
    dosya5.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\d.txt", ios::app);
    cout << "\nTc: ";
    cin >> Mtc;
    cout << "\nAd: ";
    cin >> ad;
    cout << "\nSoyad: ";
    cin >> soyad;
    cout << "\nBorc: ";
    cin >> borc;
    cout << "\nAlacak: ";
    cin >> alacak;
    bakiye=(borc-alacak);
    dosya5 << Mtc + " " + ad + " " + soyad + " " +to_string(borc) + " " + to_string(alacak) + " "+to_string(bakiye) << endl;
    dosya5.close();
    cout << "\nMusteri d.txt dosyasina guncellendi" <<endl;
}

void MusteriAra(){
    string tc, kelime;
    vector <string> v1;
    cout << "Aranacak kisinin tcsi: ";
    cin >> tc;
    fstream dosya;
    dosya.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\a.txt");
    while (dosya >> kelime){
        v1.push_back(kelime);
    }
    int boyut=v1.size();
    for (int i=0; i != boyut; i++){
            if (tc==v1[i]) {
                cout << "\nMusteri bulundu.\n" << endl;
                cout << "    TC\t"<<"     Ad  "<<"Soyad "<<"Borc "<<"Alacak  "<<"Bakiye\n";
                cout <<"--------------------------------------------------\n";
                cout << v1[i] + " " + v1[i + 1] + " " + v1[i + 2] + " " + v1[i + 3] + " " + v1[i + 4] + " " + v1[i + 5]<< endl;
            }
        }
    }

float ToplamBakiye(){
    string kelime;
    vector <string> v3;
    float sayac;
    fstream dosya;
    dosya.open("C:\\Users\\tolga\\CLionProjects\\C++_Kodlar\\a.txt");
    while (dosya >> kelime) {
        v3.push_back(kelime);
    }
    for (int i = 0; i != v3.size(); ++i) {
        if ( i % 6 == 5){
            sayac += stof(v3[i]);
        }
    }
    cout << "Toplam Bakiye ---> " << sayac;

}