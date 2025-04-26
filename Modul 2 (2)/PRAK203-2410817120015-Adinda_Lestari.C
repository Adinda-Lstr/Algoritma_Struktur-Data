#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define n 10
using namespace std;

int F, R;
char Q[n];

void Inisialisasi() {
    F = R = -1;
    cout << "Queue berhasil diinisialisasi.\n";
}

int kosong() {
    return (F == -1 || F > R);
}

int penuh() {
    return (R == n - 1);
}

void INSERT() {
    char huruf;
    if (penuh()) {
        cout << "Queue penuh!\n";
    } else {
        cout << "Masukkan data: ";
        cin >> huruf;
        if (kosong()) {
            F = R = 0;
        } else {
            R++;
        }
        Q[R] = huruf;
        cout << "Data '" << huruf << "' berhasil dimasukkan ke queue.\n";
    }
}

void DELETE() {
    if (kosong()) {
        cout << "Queue kosong, tidak ada yang bisa dihapus.\n";
    } else {
        cout << "Data '" << Q[F] << "' dihapus dari queue.\n";
        F++;
    }
}

void CETAKLAYAR() {
    if (kosong()) {
        cout << "Queue kosong.\n";
    } else {
        cout << "Isi Queue:\n";
        for (int i = F; i <= R; i++) {
            cout << "Queue[" << i << "] = " << Q[i] << endl;
        }
    }
}

void RESET() {
    F = R = -1;
    cout << "Queue dikosongkan.\n";
}

int main() {
    int PIL;
    char PILIHAN[1];
    Inisialisasi();
    do {
        cout << "\nQUEUE\n";
        cout << "====================\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. CETAK QUEUE\n";
        cout << "4. CLEAR QUEUE\n";
        cout << "5. QUIT\n";
        cout << "PILIHAN : ";
        cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                break;
            case 5:
                cout << "TERIMA KASIH\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

        if (PIL != 5) {
            cout << "\nTekan tombol apa saja untuk melanjutkan...";
            getch();
            system("cls");
        }

    } while (PIL != 5);

    return 0;
}
