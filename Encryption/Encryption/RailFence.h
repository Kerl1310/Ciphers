#ifndef H_RAILFENCE
#define H_RAILFENCE
#include "Cipher.h"
#include <string>
#include <iostream>
class RailFence: public Cipher
{
	public:
		RailFence();
		~RailFence();
	
		void Encrypt(const std::string) {};
		void Encrypt(const std::string, const int);
		void Encrypt(const std::string, const std::string) {};
		void Decrypt(const std::string) {};
		void Decrypt(const std::string, const int);
		void Decrypt(const std::string, const std::string) {};
};
#endif