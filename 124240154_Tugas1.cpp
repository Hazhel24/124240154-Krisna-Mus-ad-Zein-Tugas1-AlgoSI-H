#include <iostream>
using namespace std;
struct Bataylon
{
    int id;
    int jumlah;
    string nama_general;
    string tipe;
};
string tipe_pasukan[3] = {"Infantry", "Kavaleri", "Archer"};
Bataylon pasukan[100];
int jml_index = 0;
bool nama_ada(Bataylon pasukan[], string nama)
{
    for (int i = 0; i < jml_index; i++)
    {
        if (pasukan[i].nama_general == nama)
        {
            return true;
        }
    }
    return false;
}
void sort_data(Bataylon pasukan[], int jml_index)
{
    for (int i = 0; i < jml_index; i++)
    {
        for (int j = 0; j < jml_index - i - 1; j++)
        {
            if (pasukan[j].nama_general > pasukan[j + 1].nama_general)
            {
                swap(pasukan[j], pasukan[j + 1]);
            }
        }
    }
}
void tambah_bataylon(Bataylon pasukan[])
{
    string *type = tipe_pasukan;
    cin.ignore();
    string nama;
    bool found = false;
    do
    {
        cout << "Input General Name : ";
        getline(cin, nama);

        if (nama_ada(pasukan, nama))
        {
            cout << "Error 303: Nama" << " - " << nama << " - " << "telah ada dalam list Silakan masukkan nama lain.\n ";
            system("pause");
        }
    } while (nama_ada(pasukan, nama)); // Ulangi jika nama sudah ada
    pasukan[jml_index].nama_general = nama; // NAMA
    pasukan[jml_index].id = jml_index + 1;  // ID
    while (!found)                          // sequential search
    {
        cout << "Input Soldier Type (Infantry, Kavaleri, Archer): ";
        cin >> pasukan[jml_index].tipe;
        for (int i = 0; i < 3; i++)
        {
            if (pasukan[jml_index].tipe == *(type + i))
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Tipe pasukan tidak valid! Silakan masukkan lagi.\n";
        }
    }
    cout << "Input Soldier Quantity: ";
    while (!(cin >> pasukan[jml_index].jumlah) || pasukan[jml_index].jumlah <= 1)
    {
        cout << "Error: Jumlah harus > 0, silakan coba lagi: ";
    }
    jml_index++;
    sort_data(pasukan, jml_index);
}
void cari_bataylon(Bataylon pasukan[])
// binary search
{
    cin.ignore();
    int awal = 0, akhir = jml_index - 1, tengah;
    bool found = false;
    string cari;
    cout << "Nama General yang ingin anda cari : " << '\n';
    getline(cin, cari);
    while (!found && (awal <= akhir))
    {
        tengah = (awal + akhir) / 2;
        if (pasukan[tengah].nama_general == cari)
        {
            found = true;
        }
        else if (pasukan[tengah].nama_general > cari)
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }
    if (found)
    {
        cout << "General ditemukan!" << '\n';
        cout << "ID : " << tengah + 1 << endl;
        cout << "Nama : " << pasukan[tengah].nama_general << '\n';
        cout << "Tipe Pasukan : " << pasukan[tengah].tipe << '\n';
        cout << "Jumlah Pasukan : " << pasukan[tengah].jumlah << '\n';
        system("pause");
    }
    else
    {
        cout << "Tidak ada general bernama " << cari << " dalam Array." << endl;
    }
}
int main()
{
    int pilihan;
    string ya_no;
    do
    {
        cout << "List\n";
        cout << "1. Tambah Bataylon\n";
        cout << "2. Cari Bataylon\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            tambah_bataylon(pasukan);
        }
        else if (pilihan == 2)
        {
            cari_bataylon(pasukan);
        }
        cout << "\nApakah anda ingin melanjutkan? (ya/tidak) = ";
        cin >> ya_no;
    } while (ya_no == "ya");

    return 0;
}