#ifndef H_ROT13
#define H_ROT13
#include <string>
#include <iostream>
class ROT13
{
	public:
		ROT13();
		~ROT13();
	
		void Encrypt(const std::string);
		void Decrypt(const std::string);
};
#endif