#include <iostream>
#include <vector>
#include "Transaktion.h"
#include <fstream>
#include <string>
#include <sstream>

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
	std::cin >> belopp;
	std::cin.ignore(); //rensa newline kvar i cin
			   
	return Transaktion(datum, typ, kategori, belopp);
}

void sparaTillFil(const std::vector<Transaktion>& transaktioner) {
	std::ofstream fil("transaktioner.txt"); // oppnar/skapar filen
if (!fil) { // kolla att filen oppnades korrekt
	std::cerr << "Kunde inte öppna filen för skrivning!\n";
	return;
     }


for (auto &t : transaktioner) {
       fil << t.datum << ";" << t.typ << ";"
           << t.kategori << ";" << t.belopp << "\n";
       }       

}

void lasaFranFil (std::vector<Transaktion>& transaktioner);{

	std::ifstream fil("transaktioner.txt");

	if (!fil) {
	return; // om fil ej finns- gor inget
	}
	std::string rad;
	while (std::getline(fil, rad)) {
		std::stringstream ss(rad);
		std::string datum, typ, kategori, beloppStr;

		std::getline(ss, datum, ';');
		std::getline(ss, typ, ";");
		std::getline(ss, kategori, ";");
		std::getline(ss, beloppStr, ";");

		double belopp = std::stod(beloppStr);

		transaktioner.push_back(Transaktion(datum, typ, kategori, belopp);)
	}
}

int main(){
	std::vector<Transaktion> transaktioner;
	lasaFranFil(transaktioner);
	char val;

	do {
		std::cout << "\n1. Lägg till transaktion\n2. Visa alla transaktioner\n3. Visa saldo\n4. Avsluta\n";
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
				saldo += (t.typ == "Inkomst") ? t.belopp : -t.belopp;
			std::cout << "\nSaldo: " << saldo << " kr\n";
		}
	}
		while (val!= '4');

		std::cout << "Hejdå!\n";
	sparaTillFil(transaktioner);
		return 0;
	
}
	
