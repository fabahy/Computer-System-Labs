#include "Header02.h"

/* Các hàm bổ trợ tính toán */

string Dec_to_Bin(int d, const int n)
{
	stack<int> s;
	string res;
	while (d != 0)
	{
		s.push(d % 2);
		d /= 2;
	}
	while (!s.empty())
	{
		res += to_string(s.top());
		s.pop();
	}
	res.insert(0, n - res.size(), '0');
	return res;
}

int Dec_value_TwoComplement(string b)
{
	int item = b[0] - '0';
	int res = -(item * pow(2, b.size() - 1));
	for (int i = 1; i < b.size(); i++)
	{
		int temp = b[i] - '0';
		res += temp * pow(2, b.size() - 1 - i);
	}
	return res;
}
string TwoComplement(string b, const int n)
{
	string res;

	/* Thêm các bit 0 ở đầu cho đủ n bit */
	b.insert(0, n - b.size(), '0');

	/* Thực hiện đảo từng bit trong chuỗi nhị phân */
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '0')
			b[i] = '1';
		else
			b[i] = '0';
	}

	/* Cộng thêm 1 sau khi đảo bit */
	res = Addition(b, "1", n);

	return res;
}
void ShiftRight(string& s1, string& s2)
{
	string res = s1 + s2;
	string temp = res.substr(0, res.size() - 1);
	res.replace(1, temp.size(), temp);
	s1 = res.substr(0, s1.size());
	s2 = res.substr(s1.size(), s2.size());
}
void ShiftLeft(string& s1, string& s2)
{
	string res = s1 + s2;
	string temp = res.substr(1, res.size() - 1);
	res.replace(1, temp.size(), temp);
	res.erase(0, 1);
	res.insert(res.size(), 1, '0');
	s1 = res.substr(0, s1.size());
	s2 = res.substr(s1.size(), s2.size());
}

/* Các phép tính cộng, trừ, nhân, chia trên chuỗi nhị phân n bit */
string Addition(string A, string B, const int n)
{
	/* result = A + B */
	string res;

	/* Chuẩn hoá 2 số thành n bit */
	A.insert(0, n - A.size(), '0');
	B.insert(0, n - B.size(), '0');

	/* Chuyển chuỗi nhị phân thành vector các bit 0, 1 */
	vector<int> b1, v2;
	for (int i = 0; i < n; i++)
	{
		int temp1 = A[i] - '0';
		b1.push_back(temp1);
		int temp2 = B[i] - '0';
		v2.push_back(temp2);
	}

	/* Thực hiện cộng 2 số nhị phân */
	stack<int> sum;
	int temp = 0;
	int q = (b1[n - 1] + v2[n - 1]) % 2;
	int r = (b1[n - 1] + v2[n - 1]) / 2;
	sum.push(q);

	for (int i = n - 2; i >= 0; i--)
	{
		if (r >= 1)
			temp = 1; // Biến nhớ
		q = (b1[i] + v2[i] + temp) % 2;
		r = (b1[i] + v2[i] + temp) / 2;
		sum.push(q);
		temp = 0;
	}

	/* Gán sang chuỗi kết quả và kiểm tra tràn số */
	while (!sum.empty())
	{
		res += to_string(sum.top());
		sum.pop();
	}

	/* Tính giá trị thập phân của từng chuỗi nhị phân */
	int num1 = Dec_value_TwoComplement(A);
	int num2 = Dec_value_TwoComplement(B);
	int range = num1 + num2;
	if (range > pow(2, n - 1) - 1 || range < -pow(2, n - 1)) // range = [ -2^(n-1) ; 2^(n-1) - 1 ]
		res = "Overflow";
	return res;
}
string Subtraction(string A, string B, const int n)
{
	/* result = A - B = A + (-B) */
	string res;
	/* Lấy số đối của s2 (số bù 2 của s2) */
	B = TwoComplement(B, n);
	/* Cộng s1 với số đối của s2 */
	res = Addition(A, B, n);
	return res;
}
string Multiplication(string M, string Q, const int n)
{
	/* Thuật toán nhân
	   result = M x Q */
	string res;

	/* Khởi tạo A */
	string A(n, '0');

	/* Thêm bit 0 vào cuối Q */
	Q.insert(Q.size(), 1, '0');

	/* Thực hiện thuật toán nhân cải tiến */
	int k = n;
	while (k > 0)
	{
		string tail = Q.substr(Q.size() - 2, 2);
		if (tail == "10")
		{
			A = Subtraction(A, M, n);
		}
		else if (tail == "01")
		{
			A = Addition(A, M, n);
		}
		/* Dịch phải A, Q*/
		ShiftRight(A, Q);
		k--;
	}
	/* Bỏ bit cuối của Q */
	Q.erase(Q.size() - 1, 1);
	/* Kết quả là A + Q (Q sau khi đã bỏ bit cuối Q0) */
	res = A + Q;
	return res;
}
string Division(string Q, string M, const int n)
{
	/* Thuật toán chia
	   result = Q / M */
	string res;
	string rmd;

	// Tính giá trị thập phân của Q
	int value_Q = Dec_value_TwoComplement(Q);

	// Kiểm tra giá trị thập của Q để khởi tạo A 
	string A(n, '0');

	/*string A1(n, '0'), A2(n, '1');
	if (dec > 0)
		A = A1;
	else
		A = A2;*/



	// Thực hiện thuật toán chia
	int k = n;
	int value_M = Dec_value_TwoComplement(M);
	int R_dec, Q_dec;
	if (value_Q <= 0 && value_Q != -128)
	{
		Q = TwoComplement(Q, n);
		if (value_M > 0)
		{
			while (k > 0)
			{
				ShiftLeft(A, Q);
				A = Subtraction(A, M, n);
				int temp = Dec_value_TwoComplement(A);
				if (temp < 0)
				{
					Q[Q.size() - 1] = '0';
					A = Addition(A, M, n);
				}
				else
					Q[Q.size() - 1] = '1';
				k--;
			}
		}
		else
		{
			while (k > 0)
			{
				ShiftLeft(A, Q);
				A = Addition(A, M, n);
				int temp = Dec_value_TwoComplement(A);
				if (temp < 0)
				{
					Q[Q.size() - 1] = '0';
					A = Subtraction(A, M, n);
				}
				else
					Q[Q.size() - 1] = '1';
				k--;
			}
		}
		res = Q;
		rmd = A;
	}
	else if (value_Q == -128 && value_M <= 0) /* TH: Q có giá trị thập phân là -128 */
	{
		R_dec = abs(value_Q) % abs(value_M);
		Q_dec = abs(value_Q) / abs(value_M);
		res = Dec_to_Bin(Q_dec, n);
		rmd = Dec_to_Bin(R_dec, n);
	}
	else
	{
		if (value_M > 0)
		{
			while (k > 0)
			{
				ShiftLeft(A, Q);
				A = Subtraction(A, M, n);
				int temp = Dec_value_TwoComplement(A);
				if (temp < 0)
				{
					Q[Q.size() - 1] = '0';
					A = Addition(A, M, n);
				}
				else
					Q[Q.size() - 1] = '1';
				k--;
			}
		}
		else
		{
			while (k > 0)
			{
				ShiftLeft(A, Q);
				A = Addition(A, M, n);
				int temp = Dec_value_TwoComplement(A);
				if (temp < 0)
				{
					Q[Q.size() - 1] = '0';
					A = Subtraction(A, M, n);
				}
				else
					Q[Q.size() - 1] = '1';
				k--;
			}
		}
		res = Q;
		rmd = A;
	}
	cout << "\n\t\tRemainder: " << rmd;
	return res;
}