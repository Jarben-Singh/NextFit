// NextFit.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void nextFit(vector<int> processesSize, vector<int> blockSize)
{
	int n = processesSize.size();
	int m = blockSize.size();


	vector<int> allocation(n, -1);
	vector<int> blockRest = blockSize;

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < m && blockRest[j] < processesSize[i]) j++;
		if (j == m) break;
		allocation[i] = j;
		blockRest[j] -= processesSize[i];
	}

	cout << "Process No.\tProcess Size\tBlock No.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i + 1 << "\t\t" << processesSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}


}

int main()
{
    std::cout << "NextFit!\n";

	vector<int> processesSize = { 200, 417, 112, 426 };
	vector<int> blockSize = { 100, 500, 200, 300, 600 };

	nextFit(processesSize, blockSize);
	return 0;
}
