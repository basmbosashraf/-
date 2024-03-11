#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert a number to its corresponding alphabet letter
char numberToAlphabet(int n) {
    // Assuming n is in the range 0 to 25
    return 'A' + n;
}

int main() {
    string The_Message, cleanedInput;
    int a, b, c, new_alpha;
    char choice, continueChoice;

    // Loop to allow the user to continue entering messages
    do {
        // Prompt the user to choose an option
        cout << " Please choose the option " << endl;
        cout << " 1: encrypt the message " << endl;
        cout << " 2: decrypt the message " << endl;
        cin >> choice;

        // Ignore the newline character left in the input buffer
        cin.ignore();

        // Switch statement based on the user's choice
        switch (choice) {
            case '1':
                cout << " You entered 1  " << endl;

                // Prompt the user to enter the message to be encrypted
                cout << " Please Enter The Message That You Want To Encrypt: " << endl;
                getline(cin, The_Message);

                // Clean the input message by converting it to lowercase and removing non-alphabetic characters
                for (char m : The_Message) {
                    if (isalpha(m)) {
                        cleanedInput += tolower(m);
                    }
                }

                // Check if the cleaned input message contains any alphabetic characters
                if (cleanedInput.empty()) {
                    cout << "Error: The input message does not contain any alphabetic characters." << endl;
                    continue; // Return to the beginning of the loop to allow the user to enter another message
                }

                // Prompt the user to enter the encryption parameters
                cout << " The Function Of The Encryption is  ' E(x) = (a x + b) mod 26 ' " << endl;
                cout << " Please enter the arbitrary positive integers that satisfy the condition (a * c) mod 26 = 1 ' a,b,c ' with respect to order ";
                cin >> a >> b >> c;

                // Encrypt the cleaned input message using the provided parameters
                if ((a * c) % 26 == 1) {
                    for (char m : cleanedInput) {
                        int position = m - 'a'; // Subtract 'a' for lowercase characters
                        new_alpha = (a * position + b) % 26;
                        while (new_alpha < 0)
                            new_alpha += 26; // Ensure positive value
                        new_alpha %= 26; // Ensure within the range 0 to 25
                        char letter = numberToAlphabet(new_alpha);
                        cout << letter;
                    }
                }
                break;

            case '2':
                cout << " You entered 2 " << endl;

                // Prompt the user to enter the message to be decrypted
                cout << " Please Enter The Message That You Want To Decrypt: ";
                getline(cin, The_Message);

                // Clean the input message by converting it to lowercase and removing non-alphabetic characters
                for (char m : The_Message) {
                    if (isalpha(m)) {
                        cleanedInput += tolower(m);
                    }
                }

                // Check if the cleaned input message contains any alphabetic characters
                if (cleanedInput.empty()) {
                    cout << "Error: The input message does not contain any alphabetic characters." << endl;
                    continue; // Return to the beginning of the loop to allow the user to enter another message
                }

                // Prompt the user to enter the decryption parameters
                cout << " The Function Of The Decryption is  ' D(y) = c (y - b) mod 26 ' " << endl;
                cout << " Please enter the arbitrary positive integers that satisfy the condition (a * c) mod 26 = 1 ' a,b,c ' with respect to order ";
                cin >> a >> b >> c;

                // Decrypt the cleaned input message using the provided parameters
                if ((a * c) % 26 == 1) {
                    for (char m : cleanedInput) {
                        int position = m - 'a'; // Subtract 'a' for lowercase characters
                        new_alpha = c * (position - b) % 26;
                        while (new_alpha < 0)
                            new_alpha += 26; // Ensure positive value
                        new_alpha %= 26; // Ensure within the range 0 to 25
                        char letter = numberToAlphabet(new_alpha);
                        cout << letter;
                    }
                }
                break;

            default:
                cout << " Invalid choice " << endl;
        }
return 0;
    }
