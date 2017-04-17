#ifndef H_VERNAM
#define H_VERNAM
#include "Cipher.h"
#include <string>
#include <iostream>
class Vernam: public Cipher
{
	public:
		Vernam();
		~Vernam();
	
		void Encrypt(const std::string) {};
		void Encrypt(const std::string, const int) {};
		void Encrypt(const std::string, const std::string);
		void Decrypt(const std::string) {};
		void Decrypt(const std::string, const int) {};
		void Decrypt(const std::string, const std::string);
};
#endif