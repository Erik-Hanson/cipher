/*
Author: Erik Hanson
Date: 8/3/2018
Program: Crypter 
Description: This program takes an input file and either decrypts or encrypts the message. It prompts the user if they would like to encrypt or decrypt.
Dev Env: Vim with g++
*/

#include <iostream> 	//used for input/output streaming
#include <fstream>	//used for file IO
#include <string>	//used for the filename

//Function Prototypes
bool encrypt(std::string theFileName);
bool decrypt(std::string theFileName); 

//===============================================================================================================
int main() {
	std::string userOption;
	std::string fileName;

	std::cout << "Hello..." << std::endl;
	std::cout << "Would you like to encrypt or decrypt?... (please type encrypt or decrypt)" << std::endl;
	std::cout << "> ";
	std::cin >> userOption;
	if(userOption != "encrypt" && userOption != "decrypt") {
		std::cout << "Sorry that is invalid input try again" << std::endl;
	}

	else if(userOption == "encrypt" || userOption == "decrypt") {
		std::cout << "You chose... " << userOption << std::endl;
		std::cout << "Please enter the filename..." << std::endl;
		std::cout << "> ";
		std::cin >> fileName;
		if(userOption == "encrypt") {
			encrypt(fileName);
		}

		else {
			decrypt(fileName);
		}
	}
	return 0;
}
//===============================================================================================================
//Name: encrypt
//Args: theFileName - a string containing the filename to read
//Description: This function takes a filename to read and encrypts the message by writing to a new file with a
//new extenstion (.enc), it simply just shifts the ascii values accordingly.
//===============================================================================================================
bool encrypt(std::string theFileName) {
	std::fstream fileToEncrypt;
	std::ofstream encryptedFile;
	std::string extension = ".enc";
	fileToEncrypt.open(theFileName);
	char dataToChange;

	if(fileToEncrypt.is_open()) {
		encryptedFile.open(theFileName.append(extension));
		while(fileToEncrypt >> std::noskipws >> dataToChange) {
			dataToChange += 3; 
			encryptedFile << dataToChange;
		}
		fileToEncrypt.close();
		encryptedFile.close();
		std::cout << "The file was successfully encrypted..." << std::endl;
		return true;
	}

	else std::cout << "The file could not be opened" << std::endl;

	return false;
}
//===============================================================================================================
//Name: decrypt
//Args: theFileName - a string containing the filename to read
//Description: This function takes a filename to read and decrypts the message by writing to a new file with a 
//new extension (.dec), it simply just shifts the ascii values accordingly.
//===============================================================================================================
bool decrypt(std::string theFileName) {
	std::fstream fileToDecrypt;
	std::ofstream decryptedFile;
	std::string extension = ".dec";
	fileToDecrypt.open(theFileName);
	char dataToChange;

	if(fileToDecrypt.is_open()) {
		decryptedFile.open(theFileName.append(extension));
		while(fileToDecrypt >> std::noskipws >> dataToChange) {
			dataToChange -= 3;
			decryptedFile << dataToChange;
		}
		fileToDecrypt.close();
		decryptedFile.close();
		std::cout << "The file was successfully decrypted..." << std::endl;
		return true;
	}

	else std::cout << "The file could not be opened" << std::endl;

	return false;
}
