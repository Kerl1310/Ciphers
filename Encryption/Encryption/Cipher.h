#ifndef H_CIPHER
#define H_CIPHER
Class Cipher
{
    public:
        Cipher();
        ~Cipher();

        virtual void Encrypt(const std::string);
        virtual void Decrypt(const std::string);
};
#endif
