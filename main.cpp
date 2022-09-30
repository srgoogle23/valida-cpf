#include "validacpfcnpj.hpp"

#include <iostream>

int main()
{
	bool ok = ValidaCPFCNPJ::validaCPF("11111111111");
	std::cout << ok << std::endl;
	ok = ValidaCPFCNPJ::validaCNPJ("11111111111111");
	std::cout << ok << std::endl;
	ok = ValidaCPFCNPJ::validaCPF("21111111111");
	ok = ValidaCPFCNPJ::validaCNPJ("21111111111111");
	return ok;
}