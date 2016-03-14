#ifndef SECURITY_H
#define SECURITY_H
class Security
{
    private:
        std::string varIn;
        std::string varOut;
        std::string key;
        int length;
        int keyLength;
        char letter;
        char keyLetter;
    public:
        Security();
        ~Security();
        void ROT13(const std::string);
        void VigenereEncrypt(const std::string, const std::string);
        void VigenereDecrypt(const std::string, const std::string);
	void Vernam(const std::string, const std::string);
	void RailFenceEncrypt(const std::string, const int);
	void RailFenceDecrypt(const std::string, const int);
};
#endif
