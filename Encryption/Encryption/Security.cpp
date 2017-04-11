#include "Security.h"
	/*-------------------------------------------------------------------
	|  Function:	Constructor
	|
	|  Purpose:		Provides custom setup instructions for class.
	|
	|  Parameters:
	|		N/A
	|
	|  Returns:	N/A
	*-------------------------------------------------------------------*/
Security::Security()
{
}

	/*-------------------------------------------------------------------
	|  Function:	Destructor
	|
	|  Purpose:		Provides custom deletion instructions for class.
	|
	|  Parameters:
	|		N/A
	|
	|  Returns:	N/A
	*-------------------------------------------------------------------*/
Security::~Security()
{
}

	/*-------------------------------------------------------------------
	|  Function:	Copy Constructor
	|
	|  Purpose:		ROT13 cipher works by shifting the letters of the
	|				alphabet by 13 characters. Eg A becomes N. This
	|				function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Plaintext to be encrypted by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
// TODO: Add copy constructor for class.

	/*-------------------------------------------------------------------
	|  Function:	ROT13
	|
	|  Purpose:		ROT13 cipher works by shifting the letters of the
	|				alphabet by 13 characters. Eg A becomes N. This
	|				function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Plaintext to be encrypted by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Security::ROT13(const std::string varIn)
{
	int x;
    length = varIn.length();

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
void Security::VigenereEncrypt(const std::string varIn, const std::string key)
{
    length = varIn.length();
    keyLength = key.length();
	int x, y = 0;

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
void Security::VigenereDecrypt(const std::string varIn, const std::string key)
{
    length = varIn.length();
    keyLength = key.length();
	int x, y = 0;

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

	/*-------------------------------------------------------------------
	|  Function:	Vernam
	|
	|  Purpose:		Vernam cipher functions by taking a message and a
	|				key before performing an XOR function on the two.
	|				This function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn - Plaintext to be encrypted by the function.
	|		string key	 - Encryption key used by the function.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Security::Vernam(const std::string varIn, const std::string key)
{
    length = varIn.length();
    keyLength = key.length();

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
	|  Function:	RailFenceEncrypt
	|
	|  Purpose:		Rail Fence cipher functions by allocating the
	|				letters to a number of 'rails' before then encoding
	|				the message by taking the rails in order.
	|				Eg testing becomes tsigetn if 2 rails are used.
	|				This function encrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Plaintext to be encrypted by the function.
	|		string numOfRails	- Specifies the number of rails to use.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Security::RailFenceEncrypt(const std::string varIn, const int numOfRails)
{
	int period = (2 * numOfRails) - 2;
	int i, j;
	std::string *lines = new std::string[numOfRails];
	std::string *rails = new std::string[numOfRails];
	int length = varIn.length();

	for (i = 0; i < ((length / period) + 1); ++i)
	{
		if ((i * period) < length)
		{
			lines[0] += varIn[i * period];
		}

		for (j = 1; j < period / 2; ++j)
		{
			if ((j + (i * period)) < length)
			{
				lines[j] += varIn[j + (i * period)];
			}
    
			if ((((i + 1) * period) - j) < length)
			{
				lines[j] += varIn[((i + 1) * period) - j];
			}
		}

		if (((period / 2) + (i * period)) < length)
		{
			lines[j] += varIn[(period / 2) + (i * period)];
		}
	}

	for (i = 0; i < numOfRails; ++i)
	{
		varOut += lines[i];
	}

	std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}

	/*-------------------------------------------------------------------
	|  Function:	RailFenceDecrypt
	|
	|  Purpose:		Rail Fence cipher functions by allocating the
	|				letters to a number of 'rails' before then encoding
	|				the message by taking the rails in order.
	|				Eg testing becomes tsigetn if 2 rails are used.
	|				This function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Plaintext to be encrypted by the function.
	|		string numOfRails	- Specifies the number of rails to use.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void Security::RailFenceDecrypt(const std::string varIn, const int numOfRails)
{
	int period = (2 * numOfRails) - 2;
	int i, j;
	std::string *lines = new std::string[numOfRails];
	std::string *rails = new std::string[numOfRails];

	length = varIn.length();
	int mod = length % period;
	int *railLength = new int[numOfRails];
    
	railLength[0] = length / period;
	railLength[numOfRails - 1] = railLength[0];

	for (i = 1; i < (numOfRails - 1); ++i)
	{
		railLength[i] = railLength[0] * 2;    
	}

	for (i = 0; (i < mod) && (i < numOfRails); ++i)
	{
		++railLength[i];
	}

	for (j = (i - 2); (i < mod) && (j > -1); --j)
	{
		++railLength[j];
		++i;
	}

	int k = 0;

	for (i = 0; i < numOfRails; ++i)
	{
		for (j = 0; j < railLength[i]; ++j)
		{
			rails[i] += varIn[++k];
		}
	}

	for (i = 0; i < ((length / period) + 1); ++i)
	{
		if (rails[0][i])
		{
			varOut += rails[0][i];
		}
        
		for (j = 1; j < (numOfRails - 1); ++j)
		{
			if (rails[j][i * 2])
			{
				varOut += rails[j][i * 2];
			}
		}

		if (i < railLength[j])
		{
			if (rails[numOfRails - 1][i])
			{
				varOut += rails[numOfRails - 1][i];
			}
		}

		for(j = (numOfRails - 2); j > 0; --j)
		{
			if (((i * 2) + 1) < railLength[j])
			{
				if (rails[j][((i * 2) + 1)])
				{
					varOut += rails[j][((i * 2) + 1)];
				}
			}
		}
	}

	std::cout << std::endl << "Input: " << varIn << std::endl << "Output: " << varOut << std::endl;
}