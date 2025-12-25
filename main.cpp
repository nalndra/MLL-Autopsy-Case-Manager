#include "MLL.h"

int main()
{
    ListKasus L;
    createListKasus(L);
    adrKasus current = nullptr;

    int pilih, jumlah;
    string id, nama, sebab;
    int umur;

    do
    {
        cout << "\n============================================================\n";
        cout << "                AUTOPSY CASE MANAGER\n";
        cout << "============================================================\n";
        cout << " [1] Tambah Kasus Mayat\n";
        cout << " [2] Tambah Penyebab Kematian\n";
        cout << " [3] Hapus Kasus\n";
        cout << " [4] Kasus Berikutnya\n";
        cout << " [5] Kasus Sebelumnya\n";
        cout << " [6] Tampilkan Arsip (Awal -> Akhir)\n";
        cout << " [7] Tampilkan Arsip (Akhir -> Awal)\n";
        cout << " [8] Tampilkan Kasus Sedang Dianalisis\n";
        cout << " [9] Cari Kasus Mayat\n";
        cout << " [10] Jumlah Kasus dalam Arsip\n";
        cout << " [11] Hapus Semua Kasus\n";
        cout << " [0] Exit\n";
        cout << "============================================================\n";
        cout << "Pilihan Anda : ";
        cin >> pilih;
        cin.ignore();

        switch (pilih)
        {
        case 1:
            cout << "ID Kasus   : ";
            cin >> id;

            cout << "Nama Mayat : ";
            cin >> nama;

            cout << "Umur       : ";
            cin >> umur;

            current = createElemenKasus(id, nama, umur);
            addKasus(L, current);
            break;
        case 2:
            cout << "Masukkan ID Kasus: ";
            cin >> id;

            current = searchKasus(L, id);
            if (current == nullptr)
            {
                cout << "Kasus tidak ditemukan.\n";
            }
            else
            {
                cout << "Jumlah penyebab: ";
                cin >> jumlah;

                for (int i = 0; i < jumlah; i++)
                {
                    cout << "Penyebab ke-" << i + 1 << ": ";
                    cin >> sebab;

                    adrPenyebab q = createElemenPenyebab(sebab);
                    addPenyebab(current, q);
                }
                cout << "Penyebab berhasil ditambahkan.\n";
            }
            break;
        case 3:
        {
            cout << "Masukkan ID Kasus yang akan dihapus: ";
            cin >> id;

            adrKasus target = searchKasus(L, id);
            if (target == nullptr)
            {
                cout << "Kasus tidak ditemukan.\n";
            }
            else
            {
                current = target;
                deleteKasus(L, current);
            }
            break;
        }
        case 4:
            if (current != nullptr)
            {
                nextKasus(current);
            }
            else
            {
                cout << "Belum ada kasus.\n";
            }
            break;
        case 5:
            if (current != nullptr)
            {
                prevKasus(current);
            }
            else
            {
                cout << "Belum ada kasus.\n";
            }
            break;
        case 6:
            if (isEmptyKasus(L))
            {
                cout << "Kasus tidak ada.\n";
            }
            else
            {
                displayList(L);
            }
            break;
        case 7:
            if (isEmptyKasus(L))
            {
                cout << "Kasus tidak ada.\n";
            }
            else
            {
                for (adrKasus p = L.last; p != nullptr; p = p->prev)
                {
                    displayKasus(p);
                    cout << endl;
                }
            }
            break;
        case 8:
            displayKasus(current);
            break;
        case 9:
            cout << "Masukkan ID Kasus: ";
            cin >> id;

            current = searchKasus(L, id);
            if (current == nullptr)
            {
                cout << "Kasus tidak ditemukan.\n";
            }
            else
            {
                displayKasus(current);
            }
            break;
        case 10:
            cout << "Jumlah Kasus: " << countKasus(L) << endl;
            break;

        case 11:
            deleteAllKasus(L);
            current = nullptr;
            cout << "Semua kasus dihapus.\n";
            break;

        case 0:
            cout << "Keluar program.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 0);

    return 0;
}
