#include <iostream>
using namespace std;
/*
--------------------------------
Ahmed Maged Mohamed - 15P1047
Yasmeen Ibrahim Ahmed - 15P6049
--------------------------------
*/
void main() {
	int np, nr;
	cout << "Enter number of processes" << endl;
	cin >> np;
	cout << "Enter number of resources" << endl;
	cin >> nr;
	int** Allocation = new int*[np];
	int** Max = new int*[np];
	int** Need = new int*[np];
	int * Available = new int[nr];
	int * instance = new int[nr];
	int Finish[5] = { 0 };
	int Sequence[5];

	for (int i = 0; i < np; i++) {
		Allocation[i] = new int[nr];
		Max[i] = new int[nr];
		Need[i] = new int[nr];
	}

	///instance
	char res = 'A';
	for (int i = 0; i < nr; i++) {
		cout << "Enter instances " << res << endl;
		cin >> instance[i];
		res++;
	}
	//


	//Allocation
	res = 'A';
	for (int i = 0; i < nr; i++)
	{
		cout << "Enter Allocation for resource " << res << " for the " << np << " processes." << endl;
		for (int j = 0; j < np; j++)
		{
			cin >> Allocation[j][i];
		}
		res++;
	}

	//


	//Max
	res = 'A';
	for (int i = 0; i < nr; i++)
	{
		cout << "Enter Max for resource " << res << " for the " << np << " processes." << endl;
		for (int j = 0; j < np; j++)
		{
			cin >> Max[j][i];
		}
		res++;
	}
	//

	//Calculate Need
	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < np; j++)
		{
			Need[j][i] = Max[j][i] - Allocation[j][i];
		}
	}
		//Calculate Available
		for (int i = 0; i < nr; i++)
		{
			int sum = 0;
			for (int j = 0; j < np; j++)
			{
				sum += Allocation[j][i];
			}
			Available[i] = instance[i] - sum;
		}
		/////////////check state
		int i, j;
		int counter = 0;
		int* work = new int[nr];
		for (int i = 0; i < nr; i++) {
			work[i] = Available[i];
		}

		while (counter<np) {
			int flag = 0;
			for (int i = 0; i < np; i++) {
				if (Finish[i] == 0)
				{
					for (j = 0; j < nr; j++)
						if (Need[i][j] > work[j])
							break;
					if (j == nr) {
						for (int k = 0; k < nr; k++)
							work[k] += Allocation[i][k];
						Sequence[counter++] = i;
						Finish[i] = 1;
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				cout << "Processes are in unsafe state";
			}
		}
		cout << "Processes are in safe state" << endl << "Safe process sequence: " << endl;
		for (int i = 0; i < np; i++) {
			cout << "P" << Sequence[i];
			if (i != np-1)
				cout << " ,";
			else
				cout << endl;
		}
		//end check state
		system("PAUSE");
	}
