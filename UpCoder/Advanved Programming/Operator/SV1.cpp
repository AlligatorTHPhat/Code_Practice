#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string FullName;
	double Mark[3];

	friend istream& operator >> (istream& is, Student& st)
	{
		getline(is, st.FullName);
		//gan gia tri mang cho mark tu st.Mark roi cin >>
		for (double& mark : st.Mark) is >> mark;
		return is;
	}

	friend ostream& operator << (ostream& os, Student st)
	{
		os << st.FullName;
		return os;
	}

	double AverageMark()
	{
		double sum = 0;
		for (double mark : this->Mark) sum += mark;
		return sum / 3;
	}

	bool operator < (Student st)
	{
		return this->AverageMark() < st.AverageMark();
	}

};

int main()
{
	int n = 0;  Student st[100];
	while (cin >> st[n])
	{
		cin.ignore();
		n++;
	}

	Student max = st[0];
	for (int i = 0; i < n; i++)
	{
		if (max < st[i]) max = st[i];
	}
	cout << max;
	return 0;
}
