//#include "stdafx.h"
#include <iostream>

using namespace std;

class Player
{
public:
	int N;
	int **Score;
	int Trustables = 0;
}Player;

void Input()
{
	cin >> Player.N;

	Player.Score = new int*[6];

	for (int i = 0; i < 6; i++)
	{
			Player.Score[i] = new int[Player.N];
	}

	for (int i = 0; i < Player.N; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cin >> Player.Score[i][j];
		}
	}
}

int A(int n) // minden versenyző legnagyobb értékű dobását;
{
	int Max = 0;
	for (int i = 0; i < 6; i++)
	{
		if (Player.Score[n][i] > Max)
		{
			Max = Player.Score[n][i];
		}
	}
	return Max;
}

int B(int n) // minden versenyző sikeres dobásai számát;
{
	int Success = 0;

	for (int i = 0; i < 6; i++)
	{
		if (Player.Score[n][i] != -1)
		{
			Success++;
		}
	}
	return Success;
}

int C(int n) // minden versenyző utolsó sikeres dobása sorszámát;
{
	int LastSuccess = 6;
	do 
	{
		LastSuccess--;
	}while (Player.Score[n][LastSuccess] == -1);
	LastSuccess++;
	return LastSuccess;
}

bool D(int n) // a megbízható versenyzőket (azokat, akik minden dobása sikeres volt, valamint a legnagyobb és a legkisebb dobásuk között legfeljebb 500 cm különbség volt);
{
	bool Trust = false;
	int Valid = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (Player.Score[n][i] != -1)
		{
			Valid++;
		}
	}
	if (Valid == 6)
	{
		int Min = 10000;
		int Max = 0;
		for (int i = 0; i < 6; ++i)
		{
			if (Max < Player.Score[n][i])
			{
				Max = Player.Score[n][i];
			}
			if (Min > Player.Score[n][i])
			{
				Min = Player.Score[n][i];
			}
		}
		if ((Max - Min) < 500)
		{
			Trust = true;
		}
	}
	return Trust;
}

void CountTrustables()
{
	for (int n = 0; n < Player.N; n++)
	{
		if (D(n) == true)
		{
			Player.Trustables++;
		}
	}
}

int E() // a verseny győztesét (ha többen értek el azonos legjobb eredményt, akkor sorrendben a második legnagyobb, harmadik legnagyobb, … dobás értéke számít)!
{
	int Winner[6];
	int WinnerNo;

	for (int i = 0; i < Player.N; ++i)
	{
		for (int k = 0; k < 6; ++k)
		{
			for (int j = 6 - 1; j > k; --j)
			{
				if ((Player.Score[i][j - 1] < Player.Score[i][j]) || (Player.Score[i][j - 1] == Player.Score[i][j]) && (Player.Score[i][j - 2] < Player.Score[i][j - 1]))
				{
					int temp = Player.Score[i][j - 1];
					Player.Score[i][j - 1] = Player.Score[i][j];
					Player.Score[i][j] = temp;
				}
			}
		}
	}

	int Max = 0;
	for (int i = 0; i < Player.N; ++i)
	{
		if (Player.Score[i][0] > Max)
		{				
			for (int k = 0; k < 6; k++)
			{
				Winner[k] = Player.Score[i][k];
			}
			Max = Winner[0];
			WinnerNo = i;
		}
		if (Player.Score[i][0] == Winner[0])
		{
			if (Player.Score[i][1] == Winner[1])
			{
				if (Player.Score[i][2] == Winner[2])
				{
					if (Player.Score[i][3] == Winner[3])
					{
						if (Player.Score[i][4] == Winner[4])
						{
							if (Player.Score[i][5] == Winner[5])
							{

							}
							else
							{
								if (Player.Score[i][5] > Winner[5])
								{
									for (int k = 0; k < 6; k++)
									{
										Winner[k] = Player.Score[i][k];
									}
									Max = Winner[0];
									WinnerNo = i;
								}
							}
						}
						else
						{
							if (Player.Score[i][4] > Winner[4])
							{
								for (int k = 0; k < 6; k++)
								{
									Winner[k] = Player.Score[i][k];
								}
								Max = Winner[0];
								WinnerNo = i;
							}
						}
					}
					else
					{
						if (Player.Score[i][3] > Winner[3])
						{
							for (int k = 0; k < 6; k++)
							{
								Winner[k] = Player.Score[i][k];
							}
							Max = Winner[0];
							WinnerNo = i;
						}
					}
				}
				else
				{
					if (Player.Score[i][2] > Winner[2])
					{
						for (int k = 0; k < 6; k++)
						{
							Winner[k] = Player.Score[i][k];
						}
						Max = Winner[0];
						WinnerNo = i;
					}
				}
			}
			else
			{
				if (Player.Score[i][1] > Winner[1])
				{
					for (int k = 0; k < 6; k++)
					{
						Winner[k] = Player.Score[i][k];
					}
					Max = Winner[0];
					WinnerNo = i;
				}
			}

		}
	}

	WinnerNo++;
	return WinnerNo;
}

void Output()
{
	// First Line:
	for (int i = 0; i < Player.N; i++)
	{
		cout << A(i);

		if (i < Player.N - 1)
		{
			cout << " ";
		}
	}
	// Second Line:
	cout << endl;
	for (int n = 0; n < Player.N; n++)
	{
		cout << B(n);

		if (n < Player.N - 1)
		{
			cout << " ";
		}
	}
	// Third Line:
	cout << endl;
	for (int n = 0; n < Player.N; n++)
	{
		cout << C(n);

		if (n < Player.N - 1)
		{
			cout << " ";
		}
	}
	// Fourth Line:
	cout << endl;
	cout << Player.Trustables << " ";
	for (int n = 0; n < Player.N; n++)
	{
		if (D(n) == true)
		{
			cout << n + 1 << " ";
		}
	}
	// Fifth Line:
	cout << endl << E();
}

int main()
{
	Input();
	CountTrustables();
	Output();
	return 0;
}