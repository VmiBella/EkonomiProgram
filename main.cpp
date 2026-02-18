#include <iostream>
#include <vector>
#include "Transaktion.h"


Transaktion skapaTransaktion() {
	std::string datum, typ, kategori;
	double belopp;

	std::cout << "Datum (YYYY-MM-DD): ";
	std::getline(std::cin, datum);

	std::cout << "Typ (Inkomst/Utgift): ";
	std::getline(std::cin, typ);

	std::cout << "Kategori: ";
	std::getline(std::cin, kategori);

	std::cout << "Belopp: ";
	std::getline(std::cin, belopp);
	std::cin.ignore(); //rensa nweline kvar i cin
			   
	return Transaktion(datum, typ, kategori, belopp);
}

int main(){
	std::vector<Transaktion> transaktioner;
	char val;

	do {
		std::cout << "n\1. Lägg till transaktion\n2. Visa alla transaktioner\n3. Visa saldo\n4. Avsluta\n";
		std::cout << "Välj ett alternativ: ";
		std::cin >> val;
		std::cin.ignore(); //rensa neewline

		if (val == '1') {
		Transaktion t = skapaTransaktion();
		transaktioner.push_back(t);
		}
		else if (val == '2') {
			std::cout << "\nAlla transaktioner:\n";
			for (auto &t : transaktioner) t.visa();
		}
		else if (val == '3') {
			double saldo = 0;
			for (auto &t : transaktioner)
				saldo += (typ.t == "Inkomst") ? t.belopp : -t.belopp;
			std::cout << "\nSaldo: " << saldo << " kr\n";
		}
		while (val!= '4');

		std::cout << "Hejdå!\n";
		return 0;
	}

	transaktioner.push_back(Transaktion("2025-02-18", "Inkomst", "Lön", 25000));
	transaktioner.push_back(Transaktion("2025-02-19", "Utgift", "Bensin", 700));

	std::cout << "Alla transaktioner:\n";
	for (auto &t : transaktioner) {
	t.visa();
	}

	double saldo = 0;
	for (auto &t : transaktioner) {
	saldo += (t.typ == "Inkomst") ? t.belopp : -t.belopp;
	}
	std::cout << "\nSaldo: " << saldo << "kr\n";

	return 0;
}
