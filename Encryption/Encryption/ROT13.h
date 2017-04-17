#ifndef H_ROT13
#define H_ROT13
#include "Cipher.h"
#include <string>
#include <iostream>
class ROT13: public Cipher
{
	public:
		ROT13();
		~ROT13();
	
		void Encrypt(const std::string);
		void Encrypt(const std::string, const int) {};
		void Encrypt(const std::string, const std::string) {};
		void Decrypt(const std::string);
		void Decrypt(const std::string, const int) {};
		void Decrypt(const std::string, const std::string) {};
};
#endif