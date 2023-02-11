#include <iostream>
#include <cstring>

using namespace std;

bool pol(string num)
{
	int len = num.length();
	for(int i = 0; i < len/2; ++i)
		if(num[i] != num[len-i-1])
			return false;
	return true;
}
int main()
{
	string s;
	cin >> s;
	if(pol(s))
		cout << "YES"<<endl;
	else
	{
		cout << "NO"<<endl;
	}
	return 0;
}