#include "Vigenere.h"

Vigenere::Vigenere()
{
}

Vigenere::~Vigenere()
{
}

	/*-------------------------------------------------------------------
	|  Function:	VigenereEncrypt
	|
	|  Purpose:	Vigenere cipher works by taking a key and shifting the
	|				letters of the message using the key to determine the
	|				amount of shifts to make.
	|
	|  Parameters:
	|      string varIn - Plaintext to be encrypted by the function.
	|		string key	 - Encryption key used by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Vigenere::Encrypt(const std::string varIn, const std::string key)
{
	int length = varIn.length();
    int keyLength = key.length();
	int x, y = 0;
	char letter;
	char keyLetter;
	std::string varOut;

    for (x = 0; x < length; ++x)
    {
        if (y < keyLength)
        {
			// Check if character is alphabetic
            if (isalpha(varIn[x]))
            {
				// Convert to uppercase
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter + (int)keyLetter) % 26) + 'A';

                varOut += letter;
                ++y;
            }
            else
            {
                varOut += varIn[x];
                ++y;
            }
        }
        else
        {
            y = 0;

			// Check if character is alphabetic
            if (isalpha(varIn[x]))
            {
				// Convert to uppercase
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter + (int)keyLetter) % 26) + 'A';
                varOut += letter;
                ++y;
            }
            else
            {
                varOut += varIn[x];
                ++y;
            }
        }
    }
    std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}

	/*-------------------------------------------------------------------
	|  Function:	VigenereEncrypt
	|
	|  Purpose:		Vigenere cipher works by taking a key and shifting the
	|				letters of the message using the key to determine the
	|				amount of shifts to make. This function decrypts the
	|				text provided
	|
	|  Parameters:
	|      string varIn - Plaintext to be encrypted by the function.
	|		string key	 - Encryption key used by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Vigenere::Decrypt(const std::string varIn, const std::string key)
{
    int length = varIn.length();
    int keyLength = key.length();
	int x, y = 0;
	char letter;
	char keyLetter;
	std::string varOut;

    for (x = 0; x < length; ++x)
    {
        if (y < keyLength)
        {
			// Check if character is alphabetic
            if (isalpha(varIn[x]))
            {
				// Convert to uppercase
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter - (int)keyLetter + 26) % 26) + 'A';

                varOut += letter;
                ++y;
            }
            else
            {
                varOut += varIn[x];
                ++y;
            }
        }
        else
        {
            y = 0;

			// Check if character is alphabetic
            if (isalpha(varIn[x]))
            {
				// Convert to uppercase
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter + (int)keyLetter + 26) % 26) + 'A';
                varOut += letter;
                ++y;
            }
            else
            {
                varOut += varIn[x];
                ++y;
            }
        }
    }
    std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}