#include <iostream>
#include <string>
using namespace std;

char* baseConverter(float number, int base);
int returnStrLen(string s);
string findIntRemainder(char bases[], float number, int base, int integerPart);
string findDecimalRemainder(char bases[], float number, int base, float decimalPart);

int main() {
	float number = 0.0f;
	int base = 0;

	//validation of number since this code doesnot involve neg- numbers
	do {
		cout << "Enter the number you wish to convert into desired base : ";
		cin >> number;
	} while (number < 0);

	//validation of base since least base is of order 2(0,1)
	//i made the max base hexadecimal(base-16)
	do {
		cout << "Enter the Desired Base : ";
		cin >> base;
	} while (base < 2 || base>16);

	char* result = baseConverter(number, base);

	cout << "The Converted Number in base " << base << " is : " << endl;
	//displaying the result
	for (int i = 0; result[i] != '\0'; i++) {
		cout << result[i];
	}

	//deallocating the memory
	delete[] result;

	return 0;
}

//this function returns the length of any string variable
int returnStrLen(string s) {

	int length = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		length++;
	}

	return length;
}

//this function finds the integer representation in desired base , then stores it in a string and returns the string
string findIntRemainder(char bases[],float number, int base, int integerPart) {
	
	string intResult = "";
	int i = 0, length = 0;

	while (integerPart > 0) {
		intResult = bases[integerPart % base] + intResult;
		integerPart /= base;
	}
	
	return intResult;
}

//this function finds the decimal/floating point representation of the number , stores in string and returns it.
string findDecimalRemainder(char bases[],float number, int base,float decimalPart) {

	string decResult = "";
	int precision = 0;

	while (decimalPart > 0 && precision < 16) {

		decimalPart *= base;
		int remainder = static_cast<int>(decimalPart);

		decResult += bases[remainder];
		decimalPart -= remainder;
		precision++;
	}

	return decResult;
}

//this function calls both int and float representation functions and concatenates the string returned by both functions
//then once the string is made , it converts it into dynamic array and returns the char array which is then displayed 
//in int main function.
char* baseConverter(float number, int base) {

	int integerPart = static_cast<int>(number);
	float decimalPart = number - integerPart;
	

	char bases[16] = { '0','1','2','3','4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' };

	string finalResult = findIntRemainder(bases,number, base, integerPart);

	if (decimalPart > 0) {

		finalResult += '.';
		finalResult += findDecimalRemainder(bases,number, base, decimalPart);
	}

	int length = returnStrLen(finalResult) + 1;

	char* array = new char[length];

	for (int i = 0; i < length; i++) {
		
		array[i] = finalResult[i];
	}

	return array;

}

//Thank u.

