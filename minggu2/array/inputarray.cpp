#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": "; // digunakan untuk meminta input nilai dari user, dimana i + 1 digunakan untuk menampilkan nomor urut nilai yang dimasukkan, karena indeks array dimulai dari 0
        cin >> nilai[i];
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl; // digunakan untuk menampilkan nilai yang sudah dimasukkan oleh user, dimana i + 1 digunakan untuk menampilkan nomor urut nilai yang ditampilkan, karena indeks array dimulai dari 0
    }

    // Menghitung Rata-Rata
    int jumlah = 0;
    for (int i = 0; i < 5; i++) {
        jumlah += nilai[i];
    }
    double rata_rata = static_cast<double>(jumlah) / 5;
    cout << "Rata-rata nilai: " << rata_rata << endl;

    return 0;
}