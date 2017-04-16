#include "RailFence.h"
	
RailFence::RailFence()
{
}

RailFence::~RailFence()
{
}

	/*-------------------------------------------------------------------
	|  Function:	Encrypt
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
void RailFence::Encrypt(const std::string varIn, const int numOfRails)
{
	std::string varOut;

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
	|  Function:	Decrypt
	|
	|  Purpose:		Rail Fence cipher functions by allocating the
	|				letters to a number of 'rails' before then encoding
	|				the message by taking the rails in order.
	|				Eg testing becomes tsigetn if 2 rails are used.
	|				This function decrypts the text provided.
	|
	|  Parameters:
	|		string varIn		- Ciphertext to be decrypted by the function.
	|		string numOfRails	- Specifies the number of rails to use.
	|
	|  Returns:	void
	*-------------------------------------------------------------------*/
void RailFence::Decrypt(const std::string varIn, const int numOfRails)
{
	std::string varOut;

	int period = (2 * numOfRails) - 2;
	int i, j;
	
	std::string *lines = new std::string[numOfRails];
	std::string *rails = new std::string[numOfRails];

	int length = varIn.length();
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