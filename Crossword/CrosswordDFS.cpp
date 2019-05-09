#include <iostream>
#include <stack>
//#include <string>
using namespace std;

const string NOTSET = "Not Set";
int solution = 0;
int constraintsTested = 0;

string threeL[] = { "AFT", "ALE", "EEL", "LEE", "TIE" };
string fourL[] = { "HEEL", "HIKE", "KEEL", "KNOT", "LINE" };
string fiveL[] = { "HOSES", "LASER", "SAILS", "SHEET", "STEER" };

int threeLength = sizeof(threeL) / sizeof(string);
int fourLength = sizeof(fourL) / sizeof(string);
int fiveLength = sizeof(fiveL) / sizeof(string);

char puzzle[6][5] = {	'1',' ','2',' ','3',
						'#','#',' ','#',' ',
						'#', '4',' ','5',' ',
						'6', '#','7',' ',' ',
						'8', ' ', ' ', ' ', ' ',
						' ','#', '#', ' ', '#' };

class Node
{
public:
	string w1{ NOTSET };
	string w2{ NOTSET };
	string w3{ NOTSET };
	string w4{ NOTSET };
	string w5{ NOTSET };
	string w6{ NOTSET };
	string w7{ NOTSET };
	string w8{ NOTSET };
};

void Draw()
{
	cout << "    1   2   3   4   5" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "  +---+---+---+---+---+" << endl;
		cout << i + 1 << " ";
		for (int j = 0; j < 5; j++)
		{
			cout << "| " << puzzle[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void traverse(Node& root)
{
	stack<Node> nodeStack;
	nodeStack.push(root);

	while (!nodeStack.empty())
	{
		Node n = nodeStack.top();
		nodeStack.pop();

		if (n.w1 == NOTSET)
		{ 
			int i = 0;
			for (int i = 0; i < fiveLength; i++)//while (!fiveL[i].empty())
			{ 				
				Node child;
				child.w1 = fiveL[i];

				nodeStack.push(child);
			}
		}
		else if (n.w2 == NOTSET)
		{
			for (int i = 0; i < fiveLength; i++)//while (!fiveL[i].empty())
			{				
				Node child;
				child.w1 = n.w1;
				child.w2 = fiveL[i];

				constraintsTested++;
				if (child.w1.at(2) != child.w2.at(0))
				{
					continue;
				}

				constraintsTested++;
				if (child.w2 == child.w1)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}
		else if (n.w3 == NOTSET)
		{
			for (int i = 0; i < fiveLength; i++)//while (!fiveL[i].empty())
			{
				Node child;
				child.w1 = n.w1;
				child.w2 = n.w2;
				child.w3 = fiveL[i];

				constraintsTested++;
				if (child.w1.at(4) != fiveL[i].at(0))
				{
					continue;
				}

				constraintsTested++;
				if (child.w3 == child.w1 || child.w3 == child.w2)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}
		else if (n.w4 == NOTSET)
		{
			for (int i = 0; i < fourLength; i++)//while (!fourL[i].empty())
			{
				Node child;
				child.w1 = n.w1;
				child.w2 = n.w2;
				child.w3 = n.w3;
				child.w4 = fourL[i];

				constraintsTested++;
				if (child.w2.at(2) != fourL[i].at(1))
				{
					continue;
				}

				constraintsTested++;
				if (child.w4 == child.w1 || child.w4 == child.w2 || child.w4 == child.w3)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}
		else if (n.w5 == NOTSET)
		{
			for (int i = 0; i < fourLength; i++)//while (!fourL[i].empty())
			{
				Node child;
				child.w1 = n.w1;
				child.w2 = n.w2;
				child.w3 = n.w3;
				child.w4 = n.w4;
				child.w5 = fourL[i];

				constraintsTested++;
				if (child.w4.at(2) != fourL[i].at(0))
				{
					continue;
				}

				constraintsTested++;
				if (child.w5 == child.w1 || child.w5 == child.w2 || child.w5 == child.w3 || child.w5 == child.w4)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}
		else if (n.w6 == NOTSET)
		{
			for (int i = 0; i < threeLength; i++)//while (!threeL[i].empty())
			{
				Node child;
				child.w1 = n.w1;
				child.w2 = n.w2;
				child.w3 = n.w3;
				child.w4 = n.w4;
				child.w5 = n.w5;
				child.w6 = threeL[i];

				constraintsTested++;
				if (child.w6 == child.w1 || child.w6 == child.w2 || child.w6 == child.w3 || child.w6 == child.w4 || child.w6 == child.w5)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}
		else if (n.w7 == NOTSET)
		{
			for (int i = 0; i < threeLength; i++)//while (!threeL[i].empty())
			{
				Node child;
				child.w1 = n.w1;
				child.w2 = n.w2;
				child.w3 = n.w3;
				child.w4 = n.w4;
				child.w5 = n.w5;
				child.w6 = n.w6;
				child.w7 = threeL[i];

				constraintsTested++;
				if (child.w2.at(3) != threeL[i].at(0))
				{
					continue;
				}

				constraintsTested++;
				if (child.w5.at(1) != threeL[i].at(1))
				{
					continue;
				}

				constraintsTested++;
				if (child.w3.at(3) != threeL[i].at(2))
				{
					continue;
				}

				constraintsTested++;
				if (child.w7 == child.w1 || child.w7 == child.w2 || child.w7 == child.w3 || child.w7 == child.w4 || child.w7 == child.w5 || child.w7 == child.w6)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}
		else if (n.w8 == NOTSET)
		{
			//while (!fiveL[i].empty())
			for(int i = 0; i < fiveLength; i++)
			{
				Node child;
				child.w1 = n.w1;
				child.w2 = n.w2;
				child.w3 = n.w3;
				child.w4 = n.w4;
				child.w5 = n.w5;
				child.w6 = n.w6;
				child.w7 = n.w7;
				child.w8 = fiveL[i];

				constraintsTested++;
				if (child.w2.at(4) != fiveL[i].at(2))
				{
					continue;
				}

				constraintsTested++;
				if (child.w5.at(2) != fiveL[i].at(3))
				{
					continue;
				}

				constraintsTested++;
				if (child.w3.at(4) != fiveL[i].at(4))
				{
					continue;
				}

				constraintsTested++;
				if (child.w6.at(1) != fiveL[i].at(0))
				{
					continue;
				}

				constraintsTested++;
				if (child.w8 == child.w1 || child.w8 == child.w2 || child.w8 == child.w3 || child.w8 == child.w4 || child.w8 == child.w5 || child.w8 == child.w6 || child.w8 == child.w7)
				{
					continue;
				}

				nodeStack.push(child);
			}
		}		
		else // all variables set means we have a solution.
		{
			solution++;

			for (int i = 0; i < 5; i++) //5 letters
			{
				puzzle[0][i] = n.w1.at(i); //1 across
				puzzle[4][i] = n.w8.at(i); //8 across

				puzzle[i][2] = n.w2.at(i); //2 down
				puzzle[i][4] = n.w3.at(i); //3 down
			}

			for (int i = 0; i < 4; i++) //4 letters
			{
				puzzle[2][1 + i] = n.w4.at(i); //4 across
				puzzle[2 + i][3] = n.w5.at(i); //5 down
			}

			for (int i = 0; i < 3; i++) //3 letters
			{
				puzzle[3][2 + i] = n.w7.at(i); //7 across
				puzzle[3 + i][0] = n.w6.at(i); //6 down
			}
			Draw();
			cout << "Constraints tested: " << constraintsTested << endl;
		}
	}
}

int main()
{
	Draw();
	Node root;
	traverse(root);
}