#ifndef _VALIDA_CPF_
#define _VALIDA_CPF_

#include <string>

class ValidaCPFCNPJ
{
	protected:
		static ValidaCPFCNPJ* validacpfcnpj;
		ValidaCPFCNPJ();
	public:
		ValidaCPFCNPJ(ValidaCPFCNPJ &other) = delete;
		void operator=(const ValidaCPFCNPJ &) = delete;
		static ValidaCPFCNPJ *GetInstance();
		static bool validaCPF(std::string cpf);
		static bool validaCNPJ(std::string cnpj);
};

ValidaCPFCNPJ* ValidaCPFCNPJ::validacpfcnpj= nullptr;

ValidaCPFCNPJ::ValidaCPFCNPJ()
{
}

ValidaCPFCNPJ *ValidaCPFCNPJ::GetInstance()
{
    if(validacpfcnpj==nullptr){
        validacpfcnpj = new ValidaCPFCNPJ();
    }
    return validacpfcnpj;
}

bool ValidaCPFCNPJ::validaCPF(std::string cpf)
{
	// verifica se o cpf tem 11 digitos
	if (cpf.length() != 11)
		return false;
	
	// verifica se o cpf é composto por digitos iguais
	if (cpf == "00000000000" || cpf == "11111111111" || cpf == "22222222222" || cpf == "33333333333" || cpf == "44444444444" || cpf == "55555555555" || cpf == "66666666666" || cpf == "77777777777" || cpf == "88888888888" || cpf == "99999999999")
		return false;
	
	// verifica o primeiro digito verificador
	int soma = 0;
	for(int i = 0; i < 9; i++)
		soma += (cpf[i] - '0') * (10 - i);
	
	int resto = (soma * 10) % 11;
	if (resto == 10 || resto == 11)
		resto = 0;
	
	// se o digito verificador não bate com o primeiro digito verificador do cpf
	if (resto != (cpf[9] - '0'))
		return false;

	// verifica o segundo digito verificador
	soma = 0;
	for(int i = 0; i < 10; i++)
		soma += (cpf[i] - '0') * (11 - i);
	
	resto = (soma * 10) % 11;

	if (resto == 10 || resto == 11)
		resto = 0;

	// se o digito verificador não bate com o segundo digito verificador do cpf
	if (resto != (cpf[10] - '0'))
		return false;

	return true;
}

bool ValidaCPFCNPJ::validaCNPJ(std::string cnpj)
{
	// verifica se o cnpj tem 14 digitos
	if (cnpj.length() != 14)
		return false;

	// verifica se o cnpj é composto por digitos iguais
	if (cnpj == "00000000000000" || cnpj == "11111111111111" || cnpj == "22222222222222" || cnpj == "33333333333333" || cnpj == "44444444444444" || cnpj == "55555555555555" || cnpj == "66666666666666" || cnpj == "77777777777777" || cnpj == "88888888888888" || cnpj == "99999999999999")
		return false;

	int soma1 = 0, soma2 = 0;
	for(int i = 0, j = 5, k = 6; i < 13; i++, j--, k--)
	{
		j = j == 1 ? 9 : j;
		k = k == 1 ? 9 : k;

		soma2 += (cnpj[i] - '0') * k;

		if (i < 12)
			soma1 += (cnpj[i] - '0') * j;
	}

	int digito1 = soma1 % 11 < 2 ? 0 : 11 - soma1 % 11;
	int digito2 = soma2 % 11 < 2 ? 0 : 11 - soma2 % 11;

	return digito1 == (cnpj[12] - '0') && digito2 == (cnpj[13] - '0');
}

#endif