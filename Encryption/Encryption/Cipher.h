#ifndef H_CIPHER
#define H_CIPHER
#include <string>
class Cipher
{
    public:
        virtual void Encrypt(const std::string) = 0;
        virtual void Encrypt(const std::string, const int) = 0;
		virtual void Encrypt(const std::string, const std::string) = 0;
        virtual void Decrypt(const std::string) = 0;
        virtual void Decrypt(const std::string, const int) = 0;
		virtual void Decrypt(const std::string, const std::string) = 0;
};
#endif