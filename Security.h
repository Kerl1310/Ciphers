#ifndef SECURITY_H
#define SECURITY_H
#include <string>
using namespace std;

class Security
{
    private:
        string varIn;
        string varOut;
        string key;
        int length;
        int keyLength;
        char letter;
        char keyLetter;
    public:
        Security();
        ~Security();
        void ROT13(const string);
        void VigenereEncrypt(const string, const string);
        void VigenereDecrypt(const string, const string);
	void Vernam(const string, const string);
	void RailFenceEncrypt(const string, const int);
	void RailFenceDecrypt(const string, const int);
};
#endif
