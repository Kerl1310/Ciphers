#include "Vernam.h"
	
Vernam::Vernam()
{
}

Vernam::~Vernam()
{
}

	/*-------------------------------------------------------------------
	|  Function:	Encrypt
	|
	|  Purpose:		Vernam cipher functions by taking a message and a
	|				key before performing an XOR function on the two.
	|				This function encrypts the text provided.
	|
	|  Parameters:
	|		string varIn - Plaintext to be encrypted by the function.
	|		string key	 - Encryption key used by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Vernam::Encrypt(const std::string varIn, const std::string key)
{
    int length = varIn.length();
    int keyLength = key.length();
	char letter;
	char keyLetter;
	std::string varOut;

    if (length == keyLength)
    {
        for(int x = 0; x < length; ++x)
        {
			// Check if character is alphabetic
            if ( (isalpha(varIn[x])) && (isalpha(key[x])) )
            {
				// Convert to uppercase
                letter = toupper(varIn[x]);
                keyLetter = toupper(varIn[x]);

				// Encrypt
                varOut += ((letter - 'A') ^ (keyLetter - 'A') % 26) + 'A';
            }
            else
            {
                varOut += varIn[x];
            }
        }
    }
    else
    {
        std::cerr << "Error: Plaintext and key must be of matching length." << std::endl;
    }

    std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}

	/*-------------------------------------------------------------------
	|  Function:	Decrypt
	|
	|  Purpose:		Vernam cipher functions by taking a message and a
	|				key before performing an XOR function on the two.
	|				This function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn - Ciphertext to be decrypted by the function.
	|		string key	 - Encryption key used by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Vernam::Decrypt(const std::string varIn, const std::string key)
{
    int length = varIn.length();
    int keyLength = key.length();
	char letter;
	char keyLetter;
	std::string varOut;

    if (length == keyLength)
    {
        for(int x = 0; x < length; ++x)
        {
			// Check if character is alphabetic
            if ( (isalpha(varIn[x])) && (isalpha(key[x])) )
            {
				// Convert to uppercase
                letter = toupper(varIn[x]);
                keyLetter = toupper(varIn[x]);

				// Encrypt
                varOut += ((letter - 'A') ^ (keyLetter - 'A') % 26) + 'A';
            }
            else
            {
                varOut += varIn[x];
            }
        }
    }
    else
    {
        std::cerr << "Error: Plaintext and key must be of matching length." << std::endl;
    }

    std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}