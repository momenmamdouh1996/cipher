// welcome to vignere's cipher.
// it's explained in the (README.md) file in the repo.

#include <iostream>
#include <string>

using namespace std;


//global variables 

string message;
string keyword;

static void vignerekeyMapping() {

    //mapping the keyword so it would be the same length as the entered message with all its characters.

    for (int i = 0; i < message.length(); i++)
    {
        if (keyword.length() == message.length()) break; //assures the repetition of the keyword fits exactly the lenth of the message
        keyword.push_back(keyword[i]);
    }
}

static bool vignerevalidateKeyword(string kword) {
    if (kword.length() > 8) { // checks the keyword length to see if it passes 8
        cout << "the length of the entered keyword passed the limit (8) ,please enter a shorter keyword. " << endl;
        return false;
    }

    for (int i = 0; i < kword.length(); i++)
    {
        if (!isalpha(kword[i])) { //assures that the entered keyword is only letters
            cout << "please enter only alphabetic characters" << endl;
            return false;
        }
    }
    return true;
}

void vigneregetInputs() {


    // getting input message
    cout << "Enter Message: " <<endl;
    getline(cin, message);
    
    // assuring the message is not more than 80 characters.
    while (message.length() > 80)
    {
        cout << "the length of the entered message passed the limit (80) ,please enter a shorter message. ";
        getline(cin, message);

    }
    // makes the message Uppercase
    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    // getting input key
    do
    {
        cout << "Enter Key: " << endl;
        getline(cin, keyword);

    } while (!vignerevalidateKeyword(keyword)); //recalls the boolean function above which checks the keyword desired conditions


    
    // makes the keyword uppercase
    for (int i = 0; i < keyword.length(); i++) {
        keyword[i] = toupper(keyword[i]);
    }
    vignerekeyMapping(); // after making sure the message and true maps the keyword to the message by repeating the keyword to fit the message's length
}

static void vignereEncrypt() {
    string encryptedText;

    for (int i = 0; i < message.length(); i++) //makes sure to loop over the whole message to do the encryption in the following steps
    {

        if (message[i] >= 'A' && message[i] <= 'Z') { // a condition to make sure that the encryption happens to alphabetic characters only.

            char temp = ((message[i] + keyword[i]) % 26) + 'A'; //the formula of encryption
            encryptedText.push_back(temp); // pushes the encrypted character in the string (encryptedText).
        }
        else { // if charachter is not an alphabetic character leave it without encryption. 
            encryptedText.push_back(message[i]);
        }



    }

    cout << encryptedText;
}

static void vignereDecryption() { //makes sure to loop over the whole message to do the decryption in the following steps
    string decryptedText;

    for (int i = 0; i < message.length(); i++) 
    {
        
        if (message[i] >= 'A' && message[i] <= 'Z') { //makes sure that the decryption happens to alphabetic characters only
            
            char temp = ((message[i] - keyword[i] + 26) % 26) + 'A'; //the formula of decryption
            decryptedText.push_back(temp);// pushes the decrypted character in the string (decryptedText).
        }

        else
        {    // if charachter is not an alphabetic character leave it without decryption. 
            decryptedText.push_back(message[i]); 
        }



    }
    cout << decryptedText;
}




int main() {
    cout << "vignere cipher" << endl;
    
    int choice = 0 ; // operation choice (encryption/decryption)

    do  //assures that the choice is between encryption(1) and decryption(2)
    {
        cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
        cin >> choice;
        cin.ignore();
    } while (choice != 1 && choice != 2);


    if (choice == 1) { // when choice 1 it "outputs" encryption then recalls the getinputs function to get (message) and (keywword) the decryption function to do the decryption process.
        cout << "Encryption" << endl;
        vigneregetInputs();
        vignereEncrypt();
    }
   
    else if (choice == 2) {// when choice 2 it outputs "decryption" then recalls the getinputs function to get (message) and (keywword) the decryption function to do the decryption process.

        cout << "Decryption" << endl;
        vigneregetInputs();
        vignereDecryption();
    }
  

    return 0;
}