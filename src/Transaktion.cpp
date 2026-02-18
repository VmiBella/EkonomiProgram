#include "Transaktion.h"
#include <iostream>

Transaktion::Transaktion(std::string d, std::string t, std::string k, double b)
	: datum(d), typ(t), kategori(k), belopp(b) {}

	void Transaktion::visa(){
		std::cout << datum << " | " << typ << " | " << kategori << " | " << belopp << " kr" << std::endl;
	}
