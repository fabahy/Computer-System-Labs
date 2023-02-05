#include "Header01.h"

int main()
{
	while (true)
	{
		system("cls");

		int opt;
		
		cout << "\n\t\t------------- NUMBER CONVERSION -------------";
		cout << "\n\n\t\t\t1. Decimal to Binary.";
		cout << "\n\t\t\t2. Decimal to Hexadecimal.";
		cout << "\n\t\t\t3. Binary to Decimal.";
		cout << "\n\t\t\t4. Hexadecimal to Decimal.";
		cout << "\n\t\t\t5. Binary to Hexadecimal.";
		cout << "\n\t\t\t0. Exit.";
		cout << "\n\n\t\t---------------------------------------------";
		cout << "\n\t\tEnter selection: ";
		cin >> opt;
		if (opt == 1)
		{
			cout << "\n\t\t------------- Decimal to Binary  -------------";
			unsigned int d = 0;
			cout << "\n\n\t\tEnter decimal number: ";
			cin >> d;
			string D2B = Dec_to_Bin(d);
			cout << "\t\tResult: " << D2B << endl;
			system("pause");
		}
		else if (opt == 2)
		{
			cout << "\n\t\t------------- Decimal to Hexadecimal  -------------";
			unsigned int d = 0;
			cout << "\n\n\t\tEnter decimal number: ";
			cin >> d;
			string D2H = Dec_to_Hex(d);
			cout << "\t\tResult: " << D2H << endl;
			system("pause");
		}
		else if (opt == 3)
		{
			cout << "\n\t\t------------- Binary to Decimal  -------------";
			string b;
			cout << "\n\n\t\tEnter binary number: ";
			cin >> b;
			unsigned int B2D = Bin_to_Dec(b);
			cout << "\t\tResult: " << B2D << endl;
			system("pause");
		}
		else if (opt == 4)
		{
			cout << "\n\t\t------------- Hexadecimal to Decimal  -------------";
			string h;
			cout << "\n\n\t\tEnter hexadecimal number: ";
			cin >> h;
			unsigned int H2D = Hex_to_Dec(h);
			cout << "\t\tResult: " << H2D << endl;
			system("pause");
		}
		else if (opt == 5)
		{
			cout << "\n\t\t------------- Binary to Hexadecimal  -------------";
			string b;
			cout << "\n\n\t\tEnter binary number: ";
			cin >> b;
			string B2H = Bin_to_Hex(b);	
			cout << "\t\tResult: " << B2H << endl;
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