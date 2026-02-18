#ifndef TRANSAKTION_H
#define TRANSAKTION_H

#include <string>

class Transaktion {
	public:
		std::string datum;
		std::string typ; // inkomst elr utgift
		std::string kategori;
		double belopp;

		Transaktion(std::string d, std::string t, std::string k, double b);

		void visa();
};

#endif
