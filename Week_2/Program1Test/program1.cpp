#include <iostream>

int main()
{
	int firstInteger;
	int secondInteger;
	int operation;

	std::cout <<"This program will prompt for two integers and an operationa dn then display the result of applying the operation to the number\n";

	std::cout <<"Enter the First Integer:\n";
	cin >> firstInteger;

	std::cout <<"Enter the Second Integer:\n"
	cin >> secondInteger;

	std::cout <<"Available Operations are:\n\t1.) Addition\n\t2.) Subtraction\n\t3.) Multiplication\n\t4.) Division\nPlease Select a Number:\n";
	cin >> operation

	//Preventing Divide by 0
	if (operation == 4 && secondInteger == 0) {
		std::cout <<"Can Not Divide by Zero; Program Exiting\n";
		return 0;
	}

	//Preventing Invalid Operation
	if (operation > 4 || operation < 1) {
		std::cout <<"\n Invalid Operation. Valid Operations were 1,2,3 or 4, Quitting Program\n";
		return 0;
	}

	case 1: 
