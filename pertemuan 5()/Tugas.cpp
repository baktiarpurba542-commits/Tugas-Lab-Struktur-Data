#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah] == target)
            return tengah;
        else if (arr[tengah] < target)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah data nilai mahasiswa: ";
    cin >> n;

    int nilai[100];
    cout << "Masukkan nilai (urut ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    int cari;
    cout << "Masukkan nilai yang dicari: ";
    cin >> cari;

    int hasil = binarySearch(nilai, n, cari);

    if (hasil != -1)
        cout << "Data ditemukan pada indeks " << hasil << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    return 0;
}