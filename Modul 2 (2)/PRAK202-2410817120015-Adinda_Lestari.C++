#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 20

using namespace std;

struct Tumpukan {
    int atas;        
    int data[max];   
};

Tumpukan Tumpuk; 

void inisialisasi() {
    Tumpuk.atas = -1;
    cout << "Stack berhasil diinisialisasi.\n";
}

int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh() {
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack ";
    }
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack ";
    }
    else {
        cout << "Tumpukan Penuh";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil";
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong";
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
    } else {
        cout << "Tumpukan Kosong";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

int main() {
    int pilihan;
    int dataMasuk;

    inisialisasi();

    do {
        cout << "\n--- MENU OPERASI STACK ---" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. PRINT STACK" << endl;
        cout << "4. CLEAR STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "SELECT [1-5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (penuh() == 0) {
                    cout << "Insert Value : ";
                    cin >> dataMasuk;
                    input(dataMasuk);
                } else {
                    cout << "Operasi Input Gagal: Tumpukan sudah penuh." << endl;
                }
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Terima kasih! Program berakhir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan masukkan angka 1-5." << endl;
        }

        if (pilihan != 5) {
            cout << "\n\nTekan tombol apa saja untuk melanjutkan...";
            getch();
            system("cls");
        }

    } while (pilihan != 5);

    return 0;
}
