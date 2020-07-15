// CRUD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Created By Jeber
//aboutdevz@gmail.com
//Profile
//Jeber|Student At Vocational High School 2|XI RPL 2
//Supported by Songs: Summertime by Rainchy and coffee
//Reference......http://www.cplusplus.com/reference

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

class barang
{
public:
	string nama;
	int harga;
	string info()
	{
		return "Nama Barang : " + nama + "\n   Harga Barang : " + to_string(harga);
	}
};

vector<barang> produk;

void tambah(string nama, int harga)
{
	barang barang;
	barang.nama = nama;
	barang.harga = harga;
	produk.push_back(barang);
}

void hapus(int index)
{
	produk.erase(produk.begin() + index - 1);
}

void MainMenu()
{
	cout << "===============================================================\n";
	cout << "Simple Supermarket Inventory                 *Created By Jeber*\n";
	cout << "===============================================================\n";
	cout << "1. Tambah Barang\n";
	cout << "2. Edit Barang\n";
	cout << "3. Hapus Barang\n";
	cout << "4. Laporan\n";
	cout << "5. Exit\n";
}

void ShowItem()
{
	int i = 1;
	for (barang a : produk)
	{
		cout << i << ". " << a.info() << "\n";
		i++;
	}
}

void Menulaporan()
{
	system("cls");
	ShowItem();
	Sleep(500);
	system("Pause");
	MainMenu();
}

void MenuTambah()
{
	int hargabarang;
	string namabarang;
	cout << "=======================================\n";
	cout << "Tambah\n";
	cout << "=======================================\n";
	cout << "Nama Barang:";
	cin >> namabarang;
	cout << "\nharga barang:";
	cin >> hargabarang;
	tambah(namabarang, hargabarang);
	cout << "\nInput Sukses\n";
	Sleep(500);
	system("Pause");
	system("cls");
	MainMenu();
}

void MenuDelete()
{
	int option;
	cout << "=======================================\n";
	cout << "Delete\n";
	cout << "=======================================\n";
	ShowItem();
	cout << "\nNomor Berapa Yang Ingin Anda Delete: ";
	cin >> option;
	hapus(option);
	cout << "\nDelete Sukses\n";
	Sleep(500);
	system("Pause");
	system("cls");
	MainMenu();
}

void Edit(int index, string nama, int harga)
{
	barang goody;
	produk.at(index-1).nama = goody.nama = nama;
	produk.at(index-1).harga = goody.harga = harga;
}

void MenuEdit()
{
	int option;
	int harga;
	string nama;
	cout << "=======================================\n";
	cout << "Edit\n";
	cout << "=======================================\n";
	ShowItem();
	cout << "Pilih Barang Yang Ingin Di Edit : ";
	cin >> option;
	cout << "Nama Barang Yang Baru: ";
	cin >> nama;
	cout << "\nHarga Barang Yang Baru: ";
	cin >> harga;
	Edit(option, nama, harga);
	cout << "\nEdit Berhasil\n";
	Sleep(500);
	system("Pause");
	system("cls");
	MainMenu();
}

void MenuExit()
{
	string text[] = {"B","Y","E",".",".",".\n"};
	for (int i = 0; i <= 5;i++)
	{
		cout << text[i];
		Sleep(500);
	}
	Sleep(1000);
	system("Pause");
}

int main()
{
Menu:

	MainMenu();
	cout << "\nMasukkan Input > ";
	int MainInput; cin >> MainInput;
	switch (MainInput)
	{
	case 1:
		MenuTambah();
		break;
	case 2:
		MenuEdit();
		break;
	case 3:
		MenuDelete();
		break;
	case 4:
		Menulaporan();
		break;
	case 5:
		goto end;
		break;
	}
	system("cls");
	goto Menu;
end:
	MenuExit();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
