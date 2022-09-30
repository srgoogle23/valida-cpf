#include "validacpfcnpj.hpp"

#include <iostream>

int main()
{
	bool ok = ValidaCPFCNPJ::validaCPF("11111111111");
	std::cout << ok << std::endl;
	ok = ValidaCPFCNPJ::validaCNPJ("11111111111111");
	std::cout << ok << std::endl;
	return ok;
}