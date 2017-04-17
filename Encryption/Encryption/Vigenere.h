#ifndef H_VIGENERE
#define H_VIGENERE
#include "Cipher.h"
#include <string>
#include <iostream>
class Vigenere: public Cipher
{
	public:
		Vigenere();
		~Vigenere();
	
		void Encrypt(const std::string) {};
		void Encrypt(const std::string, const int) {};
		void Encrypt(const std::string, const std::string);
		void Decrypt(const std::string) {};
		void Decrypt(const std::string, const int) {};
		void Decrypt(const std::string, const std::string);
};
#endif