#include <iostream>
#include <string>
using namespace std;

string pi;

int check1(int s, int f)
{
	for (int num = pi[s++]; s <= f; s++)
		if (pi[s] != num)
			return 0;
	return 1;
}

int check2(int s, int f)
{
	int num = pi[s + 1] - pi[s];
	if (num != 1 && num != -1)
		return 0;
	for (s=s+1; s < f; s++)
		if (pi[s+1]-pi[s] != num)
			return 0;
	return 2;
}

int check4(int s, int f)
{
	int n[2] = { pi[s], pi[s + 1] };
	s += 2;
	for (int i=0;s<=f;s++,i++)
		if (n[i%2]!=pi[s])
			return 0;
	return 4;
}

int check5(int s, int f)
{
	int num = pi[s + 1] - pi[s];
	for (s = s + 1; s < f; s++)
		if (pi[s + 1] - pi[s] != num)
			return 0;
	return 5;
}

int check(int s, int f) {
	int res = 0;
	if (!(res = check1(s, f))) {
		if (!(res = check2(s, f))) {
			if (!(res = check4(s, f))) {
				if (!(res = check5(s, f))) {
					res = 10;
				}
			}
		}
	}
	return res;
}

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> pi;
		int len = pi.length();
		int minValues[10001] = { 0 };

		minValues[2] = check(0, 2);
		minValues[3] = check(0, 3);
		minValues[4] = check(0, 4);

		for (int i = 5; i < len; i++) {
			minValues[i] = minValues[i - 3] + check(i - 2, i);
			for (int j = 4, value=0; j < 6; j++)
			{
				if (minValues[i - j] != 0) {
					if ((value = check(i - j + 1, i) + minValues[i - j]) < minValues[i])
						minValues[i] = value;
				}
			}
		}

		/*for (int i = 0; i < len; i++)
			cout << minValues[i] << ' ';
		cout << endl;
		cout << "minValue = " << minValues[len - 1] << endl << endl;*/

		cout << minValues[len - 1] << endl;
	}
	//system("pause");
}