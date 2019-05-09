#include <iostream>
#include <string>
using namespace std;

string w_3Letters[] = { "AFT", "ALE", "EEL", "LEE", "TIE" };
string w_4Letters[] = { "HEEL", "HIKE", "KEEL", "KNOT", "LINE" };
string w_5Letters[] = { "HOSES", "LASER", "SAILS", "SHEET", "STEER" };

int constraintsTested = 0;

bool satisfiesConstraints(string s_1ACROSS, string s_4ACROSS, string s_7ACROSS, string s_8ACROSS, string s_2DOWN, string s_3DOWN, string s_5DOWN, string s_6DOWN);

int main()
{
	int count = 0;

	for (int a = 0; a <= 4; ++a)
	{
		for (int b = 0; b <= 4; ++b)
		{
			for (int c = 0; c <= 4; ++c)
			{
				for (int d = 0; d <= 4; ++d)
				{
					for (int e = 0; e <= 4; ++e)
					{
						for (int f = 0; f <= 4; ++f)
						{
							for (int g = 0; g <= 4; ++g)
							{
								for (int h = 0; h <= 4; ++h)
								{
									string aWord = w_5Letters[a];
									string bWord = w_4Letters[b];
									string cWord = w_3Letters[c];
									string dWord = w_5Letters[d];
									string eWord = w_5Letters[e];
									string fWord = w_5Letters[f];
									string gWord = w_4Letters[g];
									string hWord = w_3Letters[h];
									if (satisfiesConstraints(aWord, bWord, cWord, dWord, eWord, fWord, gWord, hWord))
									{
										cout << "Found model: " << endl;
										cout << "1ACROSS = " << aWord << endl;
										cout << "4ACROSS = " << bWord << endl;
										cout << "7ACROSS = " << cWord << endl;
										cout << "8ACROSS = " << dWord << endl;
										cout << "2DOWN = " << eWord << endl;
										cout << "3DOWN = " << fWord << endl;
										cout << "5DOWN = " << gWord << endl;
										cout << "6DOWN = " << hWord << endl;
										cout << endl;
										cout << constraintsTested << endl;
										cout << endl;
									}

									count += 1;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << "Iterations: " << count << endl;
}

bool satisfiesConstraints(string s_1ACROSS, string s_4ACROSS, string s_7ACROSS, string s_8ACROSS, string s_2DOWN, string s_3DOWN, string s_5DOWN, string s_6DOWN)
{
	constraintsTested++;
	if (s_1ACROSS == s_8ACROSS)
	{
		return false;
	}

	constraintsTested++;
	if (s_1ACROSS == s_2DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_1ACROSS == s_3DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_8ACROSS == s_2DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_8ACROSS == s_3DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_2DOWN == s_3DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_4ACROSS == s_5DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_7ACROSS == s_6DOWN)
	{
		return false;
	}

	constraintsTested++;
	if (s_1ACROSS[2] != s_2DOWN[0])
	{
		return false;
	}

	constraintsTested++;
	if (s_1ACROSS[4] != s_3DOWN[0])
	{
		return false;
	}

	constraintsTested++;
	if (s_4ACROSS[1] != s_2DOWN[2])
	{
		return false;
	}

	constraintsTested++;
	if (s_4ACROSS[3] != s_3DOWN[2])
	{
		return false;
	}

	constraintsTested++;
	if (s_4ACROSS[2] != s_5DOWN[0])
	{
		return false;
	}

	constraintsTested++;
	if (s_7ACROSS[0] != s_2DOWN[3])
	{
		return false;
	}

	constraintsTested++;
	if (s_7ACROSS[1] != s_5DOWN[1])
	{
		return false;
	}

	constraintsTested++;
	if (s_7ACROSS[2] != s_3DOWN[3])
	{
		return false;
	}

	constraintsTested++;
	if (s_8ACROSS[0] != s_6DOWN[1])
	{
		return false;
	}

	constraintsTested++;
	if (s_8ACROSS[2] != s_2DOWN[4])
	{
		return false;
	}

	constraintsTested++;
	if (s_8ACROSS[3] != s_5DOWN[2])
	{
		return false;
	}

	constraintsTested++;
	if (s_8ACROSS[4] != s_3DOWN[4])
	{
		return false;
	}

	return true;
}