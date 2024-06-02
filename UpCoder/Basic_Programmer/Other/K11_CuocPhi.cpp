#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float x;
	cin >> x;
	
	if (x < 0) cout << "NHAP SAI";
	
	else {
	    if(x - (int)x >= 0.5) x = (int)x + 1.0;
	    else x = (int)x;
	    
		if (x < 2) cout << x * 3000;
		else if (x > 1 && x <= 10) cout << 3000 + (x - 1) * 2000;
		else if (x > 10) cout << 3000 + 9 * 2000 + (x - 10) * 1500;
	}
	return 0;
}
