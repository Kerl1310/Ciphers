#ifndef H_RAILFENCE
#define H_RAILFENCE
#include <string>
#include <iostream>
class RailFence
{
	public:
		RailFence();
		~RailFence();
	
		void Encrypt(const std::string, const int);
		void Decrypt(const std::string, const int);
};
#endif