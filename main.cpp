#include <iostream>
#include <vector>
#include "Transaktion.h"
#include <fstream>
#include <sstream>

std::string hamtaManad(const std::string& datum) {
	return datum.substr(0, 7);

}

void visaManad(const std::vector<Transaktion>& transaktioner, const std::string& manad) {
	double inkomster = 0;
	double utgifter = 0;

	for (auto&t : transaktioner){
	if (hamtaManad(t.datum) == manad) {
	
	    if (t.typ == "Inkomst")
	        inkomster += t.belopp;
	    else
	        utgifter += t.belopp;
	}
	
    }

        std::cout << "\nMånad: "  << "\n";
	std::cout << "Inkomster: " << inkomster << " kr\n";
	std::cout << "Utgifter: " << " kr\n";
	std::cout << "Saldo: " << (inkomster - utgifter) << " kr\n";

}

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
	std::cin.ignore(); //rensa nweline kvar i cin
			   
	return Transaktion(datum, typ, kategori, belopp);
}


void sparaTransaktion(const Transaktion& t) {
	std::ofstream fil("transaktioner.txt", std::ios::app);

	fil << t.datum << ";"
		<< t.typ << ";"
		<< t.kategori << ";"
		<< t.belopp << "\n";


}

void laddaTransaktioner(std::vector<Transaktion>& transaktioner) {
	std::ifstream fil("transaktioner.txt");
	std::string rad;

	while (std::getline(fil, rad)) {
	    std::stringstream ss(rad);

	    std::string datum;
	    std::getline(ss, datum, ';');

	    std::string typ;
	    std::getline(ss, typ, ';');

	    std::string kategori;
	    std::getline(ss, kategori, ';');

	    std::string beloppText;
	    std::getline(ss, beloppText, ';');
	    
		    double belopp = std::stod(beloppText);

	    Transaktion t(datum, typ, kategori, belopp);
	    transaktioner.push_back(t);
        }

}
    int main() {
    std::vector<Transaktion> transaktioner;
  
    laddaTransaktioner(transaktioner);

    char val;

    do {
        std::cout << "\n1. Lägg till transaktion\n2. Visa alla transaktioner\n3. Visa saldo\n5. Visa månad\n4. Avsluta\n";
        std::cout << "Välj ett alternativ: ";
        std::cin >> val;
        std::cin.ignore();

        if (val == '1') {
            Transaktion t = skapaTransaktion();
            transaktioner.push_back(t);
	    sparaTransaktion(t);
        }
        else if (val == '2') {
            std::cout << "\nAlla transaktioner:\n";
            for (auto &t : transaktioner) {
                t.visa();
            }
        }
        else if (val == '3') {
            double saldo = 0;
            for (auto &t : transaktioner) {
                saldo += (t.typ == "Inkomst") ? t.belopp : -t.belopp;
            }
            std::cout << "\nSaldo: " << saldo << " kr\n";
        }
        else if (val == '5') {
            std::string manad;
            std::cout << "Ange manad (YYYY-MM): ";
            std::getline(std::cin, manad);

            visaManad(transaktioner, manad);
        }

    } while (val != '4');

    std::cout << "Hejdå!\n";
    return 0;
}


