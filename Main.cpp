#include <iostream>
#include <string>
#include "Security.h"    // Future Improvement: Use Qt toolkit for GUI
using namespace std;

int main()
{
    int cipherSelection = 0;
	int selection = 0;
	int numOfRails = 0;
    string varIn;
	string key;
    Security Encryption;

    cout << "Enter a piece of text to be encoded." << endl;
    cin >> varIn;

    cout << "\n\nEnter a number to choose a type of encryption."
		 << "\n1. ROT13" << "\n2. Vigenere" << "\n3. Vernam"
         << "\n4. Rail Fence" << endl << endl;
    cin >> cipherSelection;

    switch(cipherSelection)
    {
        case 1:
            Encryption.ROT13(varIn);
        case 2:
            // Also requires a key
			cout << "\nEnter a key." << endl;
			cin >> key;

			cout << endl << "Do you wish to..." << endl << "1. Encrypt" << endl << "2. Decrypt" << endl;
			cin >> selection;

			if (selection == 1)
				Encryption.VigenereEncrypt(varIn, key);
			else if (selection == 2)
				Encryption.VigenereDecrypt(varIn, key);
			else
				cerr << "Error: Invalid selection." << endl;
        case 3:
            // Also requires a key
            cout << "Enter a key." << endl;
			cin >> key;
			
			Encryption.Vernam(varIn, key);
        case 4:
            // Future Improvement: Implement variable number of rails
            cout << "Enter a number of rails." << endl;
			cin >> numOfRails;
			
			cout << endl << "Do you wish to..." << endl << "1. Encrypt" << endl << "2. Decrypt" << endl;
			cin >> selection;
			
			if (selection == 1)
				Encryption.RailFenceEncrypt(varIn, numOfRails);
			else if (selection == 2)
				Encryption.RailFenceDecrypt(varIn, numOfRails);
			else
				cerr << "Error: Invalid selection." << endl;
        default:
            cerr << "Error: Invalid selection." << endl;
    }
	system("PAUSE");
    return 0;
}