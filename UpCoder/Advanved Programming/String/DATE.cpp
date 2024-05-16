#include <iostream>
#include <cmath>

using namespace std;

struct Date {
	int day, month, year;
	int day_of_month[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };

	bool check_leap_year() {
		return this->year % 400 == 0 || (this->year % 100 != 0 && this->year % 4 == 0);
	}

	void set_day_number() {
		if (this->check_leap_year()) this->day_of_month[0] = 366;
		else this->day_of_month[0] = 365;
		return;
	}

	friend istream& operator >> (istream& is, Date& date) {
		is >> date.day >> date.month >> date.year;

		if (date.check_leap_year()) date.day_of_month[2] = 29;
		else date.day_of_month[2] = 28;

		date.set_day_number();
		return is;
	}

	friend ostream& operator << (ostream& os, Date date) {
		if (date.day < 10) os << 0;
		os << date.day << "/";

		if (date.month < 10) os << 0;
		os << date.month << "/";

		if (date.year < 1000) os << 0;
		if (date.year < 100) os << 0;
		if (date.year < 10) os << 0;

		os << date.year;
		return os;
	}

	int count_day() {
		int res = 0;
		for (int i = 1; i < this->month; i++) {
			res += this->day_of_month[i];
		}
		return res + this->day;
	}

	string Week() {
		int day = this->day;
		int month = this->month;
		int year = this->year;

		if (month < 3) month += 12, year -= 1;
		int n = (day + 2 * month + (3 * (month + 1)) / 5 + year + (year / 4)) % 7;

		if (n == 0) return "Sunday";
		else if (n == 1) return "Monday";
		else if (n == 2) return "Tuesday";
		else if (n == 3) return "Wednesday";
		else if (n == 4) return "Thursday";
		else if (n == 5) return "Friday";
		else if (n == 6) return "Saturday";
	}

	Date next_day() {
		Date res;
		res.day = this->day + 1;
		res.month = this->month;
		res.year = this->year;

		if (res.day > this->day_of_month[res.month])
			res.day = 1, res.month += 1;

		if (res.month > 12)
			res.month = 1, res.year += 1;

		return res;
	}

	bool operator == (Date other) {
		return this->day == other.day && this->month == other.month && this->year == other.year;
	}

	bool operator < (Date other) {
		if (this->year < other.year) return 1;
		else if (this->year == other.year) {
			if (this->month < other.month) return 1;
			else if (this->month == other.month)
				if (this->day < other.day) return 1;
		}
		return 0;
	}

	bool check(Date other) {
		return this->Week() == other.Week();
	}

	int operator - (Date other) {
		Date max, min;

		if (*this < other) max = other, min = *this;
		else max = *this, min = other;

		int res = max.count_day();
		while (--max.year > min.year) {
			max.set_day_number();
			res += max.day_of_month[0];
		}

		if (this->year == other.year) return res - min.count_day();
		else return res + (min.day_of_month[0] - min.count_day());
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Date x, y;
	cin >> x >> y;

	cout << x << " " << x.Week() << " " << x.count_day() << " ";
	cout << x.next_day() << " " << (x.check_leap_year() ? "TRUE" : "FALSE") << endl;

	cout << y << " " << y.Week() << " " << y.count_day() << " ";
	cout << y.next_day() << " " << (y.check_leap_year() ? "TRUE" : "FALSE") << endl;

	cout << (x.check(y) ? "TRUE" : "FALSE") << endl;

	if (x < y) cout << "1 < 2";
	else if (x == y) cout << "1 = 2";
	else cout << "1 > 2";

	cout << endl << x - y;
	return 0;
}
