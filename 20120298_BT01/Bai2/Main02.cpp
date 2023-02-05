#include "Header02.h"

int main()
{
	string b1;
	cout << "Enter 1st binary number: ";
	cin >> b1;
	string b2;
	cout << "Enter 2nd binary number: ";
	cin >> b2;
	while (true)
	{
		system("cls");
		cout << "\t\t1st binary number: " << b1 << endl;
		cout << "\t\t2nd binary number: " << b2 << endl;
		int opt;

		cout << "\n\t\t------------- " << n << " BIT BINARY CALCULATOR------------- ";
		cout << "\n\n\t\t\t1. Addition.";
		cout << "\n\t\t\t2. Subtraction.";
		cout << "\n\t\t\t3. Multiplication.";
		cout << "\n\t\t\t4. Division.";
		cout << "\n\t\t\t0. Exit.";
		cout << "\n\n\t\t--------------------------------------------------";
		cout << "\n\t\tEnter selection: ";
		cin >> opt;
		if (opt == 1)
		{
			cout << "\n\t\t------------- Addition  -------------";
			string result = Addition(b1, b2, n);
			cout << "\n\t\tSum: " << result << endl;
			system("pause");
		}
		else if (opt == 2)
		{
			cout << "\n\t\t------------- Subtraction  -------------";
			string result = Subtraction(b1, b2, n);
			cout << "\n\t\tDifference: " << result << endl;
			system("pause");
		}
		else if (opt == 3)
		{
			cout << "\n\t\t------------- Multiplication  -------------";
			string result = Multiplication(b1, b2, n);
			cout << "\n\t\tProduct: " << result << endl;
			system("pause");
		}
		else if (opt == 4)
		{
			cout << "\n\t\t------------- Division  -------------";
			string result = Division(b1, b2, n);
			cout << "\n\t\tQuotient: " << result << endl;
			system("pause");
		}
		else if (opt == 0)
		{
			cout << "The program ended. See you soon" << endl;
			system("pause");
			exit(0);
		}
		else
		{
			cout << "The selection is not valid, please enter again" << endl;
			system("pause");
		}
	}
	system("pause");
	return 0;
}