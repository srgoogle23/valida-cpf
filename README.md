# valida-cpf-cnpj
Classe para validação de CPF e CNPJ em C++

## Como usar

```c++
#include "validacpfcnpj.hpp"

int main() {
	std::string cpf = "12345678909";
	std::string cnpj = "12345678901234";

	if (ValidaCPF::valida(cpf)) {
		std::cout << "CPF válido" << std::endl;
	} else {
		std::cout << "CPF inválido" << std::endl;
	}

	if (ValidaCNPJ::valida(cnpj)) {
		std::cout << "CNPJ válido" << std::endl;
	} else {
		std::cout << "CNPJ inválido" << std::endl;
	}

	return 0;
}
```