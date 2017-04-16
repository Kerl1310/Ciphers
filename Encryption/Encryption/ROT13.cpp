#include "ROT13.h"

ROT13::ROT13()
{
}

ROT13::~ROT13()
{
}

	/*-------------------------------------------------------------------
	|  Function:	Encrypt
	|
	|  Purpose:		ROT13 cipher works by shifting the letters of the
	|				alphabet by 13 characters. Eg A becomes N. This
	|				function encrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Plaintext to be encrypted by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void ROT13::Encrypt(const std::string varIn)
{
	int x;
    int length = varIn.length();
	char letter;
	std::string varOut;

    for (x = 0; x < length; ++x)
    {
		// Check if character is alphabetic
        if (isalpha(varIn[x]))
        {
			// Convert to uppercase
            letter = toupper(varIn[x]);
            varOut += (((letter - 'A') + 13) % 26) + 'A';
        }
        else
        {
            varOut += varIn[x];
        }
    }

    std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}

	/*-------------------------------------------------------------------
	|  Function:	Decrypt
	|
	|  Purpose:		ROT13 cipher works by shifting the letters of the
	|				alphabet by 13 characters. Eg A becomes N. This
	|				function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Ciphertext to be decrypted by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void ROT13::Decrypt(const std::string varIn)
{
	int x;
    int length = varIn.length();
	char letter;
	std::string varOut;

    for (x = 0; x < length; ++x)
    {
		// Check if character is alphabetic
        if (isalpha(varIn[x]))
        {
			// Convert to uppercase
            letter = toupper(varIn[x]);
            varOut += (((letter - 'A') + 13) % 26) + 'A';
        }
        else
        {
            varOut += varIn[x];
        }
    }

    std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}