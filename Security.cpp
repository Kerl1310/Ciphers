#include "Security.h"
Security::Security()
{
}

Security::~Security()
{
}

// ROT13 cipher works by shifting the letters of the alphabet by 13 characters. Eg A becomes N
void Security::ROT13(const std::string varIn)
{
    length = varIn.length();

    for (int x = 0; x < length; x++)
    {
        if (isalpha(varIn[x]))
        {
            letter = toupper(varIn[x]);
            varOut += (((letter - 'A') + 13) % 26) + 'A';
        }
        else
        {
            varOut += varIn[x];
        }
    }

    std::cout << endl << "Input: " << varIn << endl << "Output: " << varOut << endl;
}

// Vigenere cipher works by taking a key and shifting the letters of the message
// using the key to determine the amount of shifts to make.
void Security::VigenereEncrypt(const std::string varIn, const std::string key)
{
    length = varIn.length();
    keyLength = key.length();
	int y = 0;

    for (int x = 0; x < length; x++)
    {
        if (y < keyLength)
        {
            if (isalpha(varIn[x]))
            {
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter + (int)keyLetter) % 26) + 'A';

                varOut += letter;
                y++;
            }
            else
            {
                varOut += varIn[x];
                y++;
            }
        }
        else
        {
            y = 0;

            if (isalpha(varIn[x]))
            {
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter + (int)keyLetter) % 26) + 'A';
                varOut += letter;
                y++;
            }
            else
            {
                varOut += varIn[x];
                y++;
            }
        }
    }
    std::cout << endl << "Input: " << varIn << endl << "Output: " << varOut << endl;
}

void Security::VigenereDecrypt(const std::string varIn, const std::string key)
{
    length = varIn.length();
    keyLength = key.length();
	int y = 0;

    for (int x = 0; x < length; x++)
    {
        if (y < keyLength)
        {
            if (isalpha(varIn[x]))
            {
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter - (int)keyLetter + 26) % 26) + 'A';

                varOut += letter;
                y++;
            }
            else
            {
                varOut += varIn[x];
                y++;
            }
        }
        else
        {
            y = 0;

            if (isalpha(varIn[x]))
            {
                letter = toupper(varIn[x]);
                keyLetter = toupper(key[y]);

                letter = (((int)letter + (int)keyLetter + 26) % 26) + 'A';
                varOut += letter;
                y++;
            }
            else
            {
                varOut += varIn[x];
                y++;
            }
        }
    }
    std::cout << endl << "Input: " << varIn << endl << "Output: " << varOut << endl;
}

// Vernam cipher functions by taking a message and a key before performing an XOR function on the two.
void Security::Vernam(const std::string varIn, const std::string key)
{
    length = varIn.length();
    keyLength = key.length();

    if (length == keyLength)
    {
        for(int x = 0; x < length; x++)
        {
            if ( (isalpha(varIn[x])) && (isalpha(key[x])) )
            {
                letter = toupper(varIn[x]);
                keyLetter = toupper(varIn[x]);

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
        std::cerr << "Error: Plaintext and key must be of matching length." << endl;
    }

    std::cout << endl << "Input: " << varIn << endl << "Output: " << varOut << endl;
}

// Rail Fence cipher functions by allocating the letters to a number of 'rails' before then encoding the message by
// taking the rails in order. Eg testing becomes tsigetn if 2 rails are used.
void Security::RailFenceEncrypt(const std::string varIn, const int numOfRails)
{
	int period = (2 * numOfRails) - 2;
	int j;
	std::string *lines = new std::string[numOfRails];
	std::string *rails = new std::string[numOfRails];
	int length = varIn.length();

	for (int repeats = 0; repeats < ((length / period) + 1); repeats++)
	{
		if ((repeats * period) < length)
		{
			lines[0] += varIn[repeats * period];
		}

		for (j = 1; j < period / 2; j++)
		{
			if ((j + (repeats * period)) < length)
			{
				lines[j] += varIn[j + (repeats * period)];
			}
    
			if ((((repeats + 1) * period) - j) < length)
			{
				lines[j] += varIn[((repeats + 1) * period) - j];
			}
		}

		if (((period / 2) + (repeats * period)) < length)
		{
			lines[j] += varIn[(period / 2) + (repeats * period)];
		}
	}

	for (int I = 0; I < numOfRails; I++)
	{
		varOut += lines[I];
	}

	std::cout << endl << "Input: " << varIn << endl << "Output: " << varOut << endl;
}

void Security::RailFenceDecrypt(const std::string varIn, const int numOfRails)
{
	int period = (2 * numOfRails) - 2;
	int I, j;
	std::string *lines = new std::string[numOfRails];
	std::string *rails = new std::string[numOfRails];

	length = varIn.length();
	int mod = length % period;
	int *railLength = new int[numOfRails];
    
	railLength[0] = length / period;
	railLength[numOfRails - 1] = railLength[0];

	for (I = 1; I < (numOfRails - 1); I++)
	{
		railLength[I] = railLength[0] * 2;    
	}

	for (I = 0; (I < mod) && (I < numOfRails); I++)
	{
		railLength[I]++;
	}

	for (j = (I - 2); (I < mod) && (j > -1); j--)
	{
		railLength[j]++;
		I++;
	}

	int k = 0;

	for (I = 0; I < numOfRails; I++)
	{
		for (j = 0; j < railLength[I]; j++)
		{
			rails[I] += varIn[k++];
		}
	}

	for (I = 0; I < ((length / period) + 1); I++)
	{
		if (rails[0][I])
		{
			varOut += rails[0][I];
		}
        
		for (j = 1; j < (numOfRails - 1); j++)
		{
			if (rails[j][I * 2])
			{
				varOut += rails[j][I * 2];
			}
		}

		if (I < railLength[j])
		{
			if (rails[numOfRails - 1][I])
			{
				varOut += rails[numOfRails - 1][I];
			}
		}

		for(j = (numOfRails - 2); j > 0; j--)
		{
			if (((I * 2) + 1) < railLength[j])
			{
				if (rails[j][((I * 2) + 1)])
				{
					varOut += rails[j][((I * 2) + 1)];
				}
			}
		}
	}

	std::cout << endl << "Input: " << varIn << endl << "Output: " << varOut << endl;
}
