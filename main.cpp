#include <iostream>
#include <vector>
#include "Transaktion.h"

int main(){
	std::vector<Transaktion> transaktioner;

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
