#include "Header01.h"

/* Chuyển cơ số 10 sang cơ số 2 */
string Dec_to_Bin(unsigned int d)
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
	return res;
}
/* Chuyển cơ số 10 sang cơ số 16 */
string Dec_to_Hex(unsigned int d)
{
	stack<int> s;
	string res;
	while (d != 0)
	{
		s.push(d % 16);
		d /= 16;
	}
	while (!s.empty())
	{
		int temp = s.top();
		if (temp < 10)
			res += to_string(temp);
		else
			switch (temp)
			{
			case 10:
				res += 'A';
				break;
			case 11:
				res += 'B';
				break;
			case 12:
				res += 'C';
				break;
			case 13:
				res += 'D';
				break;
			case 14:
				res += 'E';
				break;
			case 15:
				res += 'F';
				break;
			}
		s.pop();
	}
	return res;
}
/* Chuyển cơ số 2 sang cơ số 10 */
unsigned int Bin_to_Dec(string b)
{
	unsigned int res = 0;
	vector<int> v;
	for (int i = 0; i < b.size(); i++)
	{
		int temp = b[i] - '0';
		v.push_back(temp);
	}
	for (int i = 0; i < v.size(); i++)
		res += v[i] * pow(2, v.size() - i - 1);
	return res;
}
/* Chuyển cơ số 16 sang cơ số 10 */
unsigned int Hex_to_Dec(string h)
{
	unsigned int res = 0;
	vector<int> v;
	for (int i = 0; i < h.size(); i++)
	{
		int temp = 0;
		switch (h[i])
		{
		case 'A':
			temp = 10;
			break;
		case 'B':
			temp = 11;
			break;
		case 'C':
			temp = 12;
			break;
		case 'D':
			temp = 13;
			break;
		case 'E':
			temp = 14;
			break;
		case 'F':
			temp = 15;
			break;
		default:
			temp = h[i] - '0';
			break;
		}
		v.push_back(temp);
	}
	for (int i = 0; i < v.size(); i++)
		res += v[i] * pow(16, v.size() - i - 1);
	return res;
}
/* Chuyển cơ số 2 sang cơ số 16 */
string Bin_to_Hex(string b)
{
	string res;
	vector<int> s;

	/* Chuẩn hoá chuỗi nhị phân thành các nhóm 4 bit */
	switch (b.size() % 4)
	{
	case 1:
		b.insert(0, 3, '0');
		break;
	case 2:
		b.insert(0, 2, '0');
		break;
	case 3:
		b.insert(0, 1, '0');
		break;
	}

	/* Chuyển từng nhóm 4 bit thành số thập phân */
	for (int i = 0; i < b.size(); i += 4)
	{
		int sum = 0;
		int k = i;
		for (int j = 0; j < 4; j++)
		{
			int temp = b[k] - '0';
			sum += temp * pow(2, 3 - j);
			k++;
		}
		s.push_back(sum);
	}

	/* Chuyển từng số thập phân thành từng số thập lục phân */
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 10:
			res += 'A';
			break;
		case 11:
			res += 'B';
			break;
		case 12:
			res += 'C';
			break;
		case 13:
			res += 'D';
			break;
		case 14:
			res += 'E';
			break;
		case 15:
			res += 'F';
			break;
		default:
			res += to_string(s[i]);
			break;
		}
	}

	/* Xoá số 0 ở đầu (nếu có) */
	int count = 0;
	int i = 0;
	while (res[i] == '0' && i < res.size())
	{
		count++;
		i++;
	}
	res.erase(0, count);
	return res;
}