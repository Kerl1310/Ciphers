/*----------------------------------------------------------------------------------------
|	Personal project creating software to encode/decode messages using various ciphers.
|	Currently five (5) ciphers have been implemented, with plans for several more in the
|	near future.
|	Future Improvement: Use Qt toolkit or XAML for GUI.
|	Possible Future Improvement: Move Menu to seperate class.
|	Possible Future Improvement: Move Ciphers to seperate classes.
*----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "Security.h"
#include "SHA256.h"

int main()
{
    int cipherSelection = 0;
	int selection = 0;
	int numOfRails = 0;
    std::string varIn;
	std::string output;
	std::string key;
    Security Encryption;

    std::cout << "Enter a piece of text to be encoded." << std::endl;
    std::cin >> varIn;

	// Input validation required to reduce number of potential errors
    std::cout << "\nEnter a number to choose a type of encryption."
		 << "\n1. ROT13" << "\n2. Vigenere" << "\n3. Vernam"
         << "\n4. Rail Fence\n5. SHA256" << std::endl << std::endl;
    std::cin >> cipherSelection;

	// Switch case used to determine which encryption function to call due to potentially large quantities of options
    switch(cipherSelection)
    {
        case 1:
            Encryption.ROT13(varIn);
			break;
        case 2:
        	// Vigenere requires a key to determine the shifts to be applied
			std::cout << "\nEnter a key." << std::endl;
			std::cin >> key;

			std::cout << std::endl << "Do you wish to..." << std::endl << "1. Encrypt" << std::endl << "2. Decrypt" << std::endl << std::endl;
			std::cin >> selection;

			if (selection == 1)
				Encryption.VigenereEncrypt(varIn, key);
			else if (selection == 2)
				Encryption.VigenereDecrypt(varIn, key);
			else
				std::cerr << "Error: Invalid selection." << std::endl;

			break;
        case 3:
            // Vernam requires a key to perform the XOR operation
            std::cout << "Enter a key." << std::endl;
			std::cin >> key;
			
			Encryption.Vernam(varIn, key);
			break;
        case 4:
			// Rail Fence requires a number of rails be set prior to the algorithm being applied
            std::cout << "Enter a number of rails." << std::endl;
			std::cin >> numOfRails;
			
			std::cout << std::endl << "Do you wish to..." << std::endl << "1. Encrypt" << std::endl << "2. Decrypt" << std::endl << std::endl;
			std::cin >> selection;
			
			if (selection == 1)
				Encryption.RailFenceEncrypt(varIn, numOfRails);
			else if (selection == 2)
				Encryption.RailFenceDecrypt(varIn, numOfRails);
			else
				std::cerr << "Error: Invalid selection." << std::endl;
			break;
		case 5:
			// Call SHA256
			output = sha256(varIn);
			break;
        default:
            std::cerr << "Error: Invalid selection." << std::endl;
			break;
    }

	system("PAUSE");
    return 0;
}