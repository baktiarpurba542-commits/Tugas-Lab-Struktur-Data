//Buat program C++ dengan array 3 dimensi ukuran [3][3][4], diisi angka kelipatan 2 (2, 4, 6, 8,...).
//Tampilkan hasilnya dalam bentuk 3 lapis tabel, di mana tiap lapis berukuran 3x4.
//Tips: pakai 3 loop bersarang (lapisan, baris, kolom).
#include <iostream>
using namespace std;

int main() {
        int angka[3][3][4];

    int nilai = 2;

        for (int lapis = 0; lapis < 3; lapis++) {
        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 4; kolom++) {
                angka[lapis][baris][kolom] = nilai;
                nilai += 2;
            }
        }
    }

        for (int lapis = 0; lapis < 3; lapis++) {

        cout << "lapis " << lapis + 1 << endl;
        cout << " " << endl;

        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 4; kolom++) {
                cout << angka[lapis][baris][kolom] << "\t";
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
