#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string kecil(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void cetak(const vector<string>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << "[" << a[i] << "] ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah kata: ";
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "\nData awal : ";
    cetak(a);

    for (int i = 1; i < n; i++) {
        string key = a[i];
        int j = i - 1;

        cout << "\nLangkah " << i << ": sisipkan \"" << key << "\"" << endl;

        while (j >= 0 && kecil(a[j]) > kecil(key)) {
            a[j + 1] = a[j];  
            cout << "  Geser \"" << a[j] << "\" dari indeks " << j
                 << " ke indeks " << j + 1 << " -> ";
            cetak(a);
            j--;
        }

        a[j + 1] = key;
        cout << "  Tempatkan \"" << key << "\" di indeks " << j + 1 << " -> ";
        cetak(a);
    }

    cout << "\nHasil akhir (A-Z): ";
    cetak(a);

    return 0;
}