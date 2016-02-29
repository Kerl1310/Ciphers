#ifndef SECURITY_H
#define SECURITY_H
#include <iostream>
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
        void ROT13(static string);
        void VigenereEncrypt(static string, static string);
        void VigenereDecrypt(static string, static string);
		void Vernam(static string, static string);
		void RailFenceEncrypt(static string, static int);
		void RailFenceDecrypt(static string, static int);
};
#endif