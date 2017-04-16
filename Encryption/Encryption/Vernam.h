#ifndef H_VERNAM
#define H_VERNAM
#include <string>
#include <iostream>
class Vernam
{
	public:
		Vernam();
		~Vernam();
	
		void Encrypt(const std::string, const std::string);
		void Decrypt(const std::string, const std::string);
};
#endif