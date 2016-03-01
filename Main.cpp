/*	Personal project creating software to encode/decode messages using various ciphers.
	Currently four (4) ciphers have been implemented, with plans for several more in the
	near future. */
#include <iostream>
#include <string>
#include "Security.h"    // Possible Future Improvement: Use Qt toolkit for GUI
using namespace std;

int main()
{
    int cipherSelection = 0;
    int selection = 0;
    int numOfRails = 0;
    string varIn;
    string key;
    Security Encryption;
    
    // Possible Future Improvement: Move Menu to seperate class
    cout << "Enter a piece of text to be encoded." << endl;
    cin >> varIn;
    
    // Input validation required to reduce number of potential errors
    cout << "\n\nEnter a number to choose a type of encryption."
    	<< "\n1. ROT13" << "\n2. Vigenere" << "\n3. Vernam"
        << "\n4. Rail Fence" << endl;
    cin >> cipherSelection;
    
    // Switch case used to determine which encryption function to call
    switch(cipherSelection)
    {
        case 1:
            Encryption.ROT13(varIn);
        case 2:
        	// Vigenere requires a key to determine the shifts to be applied
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
            // Vernam requires a key to perform the XOR operation
            cout << "Enter a key." << endl;
            cin >> key;
            
            Encryption.Vernam(varIn, key);
        case 4:
        // Rail Fence requires a number of rails be set prior to the algorithm being applied
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
        	// Code in the default runs following execution of other cases. Refactoring required.
        	cerr << "Error: Invalid selection." << endl;
    }
    system("PAUSE");
    return 0;
}
