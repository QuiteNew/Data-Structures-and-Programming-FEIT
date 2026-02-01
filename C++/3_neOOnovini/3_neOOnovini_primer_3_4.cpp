#include <iostream>
using namespace std;

int main()
{
	const char naslov[] = " NASLOV ";
	const char podnaslov[] = "Podnaslov";
	char *tocki[] = { "Tocka eden", "Tocka dva", "Tocka tri" };
	void ruler(int n = 20, char c = '=', bool nl = true);
	ruler();
	cout << naslov << endl; ruler(sizeof naslov - 1);
	cout << podnaslov << endl; ruler(sizeof podnaslov - 1, '-');
	void list(int n, char **lt);
	list(3, tocki);
	ruler();
}

void list(int n, char **lt)
{
	void ruler(int n = 1, char c = '#', bool nl = false);

	for (int i = 0; i<n; i++)
	{
		ruler();
		cout << i + 1 << ' ' << lt[i] << endl;
	}
	ruler(15, '*', true);
	return;
}

void ruler(int n, char c, bool nl)
{
	for (int i = 0; i<n; i++)
		cout << c;
	if (nl) cout << endl;
}

