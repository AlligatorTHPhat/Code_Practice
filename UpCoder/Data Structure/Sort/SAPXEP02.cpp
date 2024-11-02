#include <iostream>

using namespace std;

bool is_prime_number(int& n)
{
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void input(int& n, int& cntPrime, int vPrime[], int values[])
{
	cin >> n;

	cntPrime = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
		if (is_prime_number(values[i]))
			vPrime[cntPrime++] = values[i];
	}
}

template <typename DataType>
void interchange_sort(int n, DataType values[])
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (values[i] < values[j])
				swap(values[i], values[j]);
			
}

void solve_prime(int n, int cntPrime, int vPrime[], int values[])
{
	interchange_sort(cntPrime, vPrime);

	int iPrime = 0;
	for (int i = 0; i < n; i++)
		if (is_prime_number(values[i]))
			values[i] = vPrime[iPrime++];
}

void output(int n, int cntPrime, int vPrime[], int values[])
{
	solve_prime(n, cntPrime, vPrime, values); 

	for (int i = 0; i < n; i++)
		cout << values[i] << " ";
}

int main()
{
	int n, cntPrime;

	int values[100], vPrime[100];

	input(n, cntPrime, vPrime, values);
	output(n, cntPrime, vPrime, values);

	return 0l;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool Check_Prime_Number(int n)
// {
//     for (int i = 2; i * i <= n; i++)
//         if (n % i == 0) return false;
//     return n > 1;
// }

// void Input(int& n, vector<int>& prime, vector<int>& values)
// {
//     cin >> n;
//     values.resize(n);  
//     for (int i = 0; i < n; i++)
//     {
//         cin >> values[i];
//         if (Check_Prime_Number(values[i]))
//             prime.push_back(values[i]);
//     }
// }

// void Print_Prime(int n, vector<int>& prime, vector<int>& values)
// {
//     sort(prime.rbegin(), prime.rend());  

//     int Prime_index = 0;
//     for (int i = 0; i < n; i++)
//         if (Check_Prime_Number(values[i]))
//             values[i] = prime[Prime_index++]; 
// }

// void Output(int n, vector<int>& prime, vector<int>& values)
// {
//     Print_Prime(n, prime, values);  
//     for (int i = 0; i < n; i++)
//         cout << values[i] << " ";
//     cout << endl;
// }

// int main()
// {
//     int n;
//     vector<int> values;
//     vector<int> prime;

//     Input(n, prime, values);  
//     Output(n, prime, values);

//     return 0;
// }
