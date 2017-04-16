#ifndef H_VIGENERE
#define H_VIGENERE
#include <string>
#include <iostream>
class Vigenere
{
	public:
		Vigenere();
		~Vigenere();
	
		void Encrypt(const std::string, const std::string);
		void Decrypt(const std::string, const std::string);
};
#endif