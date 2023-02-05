#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

/* Số bit thao tác các phép tính trên chuỗi nhị phân */
const int n = 8;

/* Hàm chuyển hệ 10 sang hệ 2 và chuẩn hoá thành n bit */
string Dec_to_Bin(int d, const int n);
/* Hàm tính giá trị thập phân của số bù 2 */
int Dec_value_TwoComplement(string b);
/* Hàm lấy số đối bằng số bù 2 */
string TwoComplement(string b, const int n);
/* Hàm xoay phải */
void ShiftRight(string& s1, string& s2);
/* Hàm xoay trái */
void ShiftLeft(string& s1, string& s2);

/* Hàm tính cộng */
string Addition(string A, string B, const int n);
/* Hàm tính trừ */
string Subtraction(string A, string B, const int n);
/* Hàm tính nhân */
string Multiplication(string M, string Q, const int n);
/* Hàm tính chia */
string Division(string Q, string M, const int n);
