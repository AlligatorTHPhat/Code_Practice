#include <iostream>
using namespace std;

string Demical_to_Hexandemical(int num)
{
	if (num == 0) return "0";

	string hex_char = "0123456789ABCDEF";
	string hexademical = "";
	while (num > 0)
	{
		int remainder = num % 16;
		hexademical = hex_char[remainder] + hexademical;
		num = num / 16;
	}
	return hexademical;

}
int main()
{
	int num;
	cin >> num;
	
	cout << Demical_to_Hexandemical(num);
	return 0;
}
