#include <iostream>
#include <fstream>

using namespace std;

#define MAX 20
#define NOT_FOUND 0
#define FOUND 1

struct GRAPH
{
	int nV, adj[MAX][MAX];
};

void Read_Graph(string fn, GRAPH& g) {
	ifstream f(fn);
	if (!f.is_open()) {
		cout << "Khong tim duoc file!" << endl;
	}
	else {
		f >> g.nV;

		for (int i = 0; i < g.nV; i++) {
			for (int j = 0; j < g.nV; j++) {
				f >> g.adj[i][j];
			}
		}
		f.close();
	}
}

int visit(int u, int visited[], int& count, int& flag, int path[], GRAPH g) {

	if (flag == FOUND) return flag;

	for (int v = 0; v < g.nV; v++)
		if (visited[v] == 0 && g.adj[u][v] != 0)
		{

			visited[v] = 1;

			path[count] = v;

			count++;

			if (count == g.nV && g.adj[v][path[0]] == 1) 

				flag = FOUND;

			visit(v, visited, count, flag, path, g);

		}

	if (flag == NOT_FOUND)
	{
		visited[u] = 0; count--;
	}

	return flag;
}

int DFS_Hamilton(int path[], GRAPH g)
{
	int start = 0;
	int flag = NOT_FOUND;
	int visited[MAX];

	for (int i = 0; i < g.nV; i++)
		visited[i] = 0;

	int count = 0; 
	path[count] = start;
	count++;
	visited[start] = 1;

	flag = visit(start, visited, count, flag, path, g);

	if (flag) return FOUND;
	return NOT_FOUND;
}

void Print_Hamilton_Cycle(int path[], GRAPH& g, ofstream& f) {
	f << "Chu trinh Hamilton la:\n";
	for (int i = 0; i < g.nV; i++) {
		f << path[i] << " -> ";
	}
	f << path[0] << "\n";
}

void Print_Hamilton_Path(int path[], GRAPH& g, ofstream& f) {
	f << "Duong di Hamilton la:\n";
	for (int i = 0; i < g.nV - 1; i++) {
		f << path[i] << " -> ";
	}
	f << path[g.nV - 1] << "\n";
}

void Print_No_Hamilton(int path[], GRAPH& g, ofstream& f, bool isCycleCheck) {
	if (isCycleCheck) {
		f << "Khong co chu trinh Hamilton\n";
	}
	else {
		f << "Khong co duong di Hamilton\n";
	}

	for (int i = 0; i < g.nV; i++) {
		f << path[i];

		if (i < g.nV - 2 && path[i + 1] == path[i + 2]) {
			f << " -> " << path[i + 1];
			break;
		}

		if (i != g.nV - 1) {
			f << " -> ";
		}
	}
	f << endl;
}

void Print_Graph(string fn, GRAPH& g) {
	ofstream f(fn, ios::app);
	if (!f.is_open()) {
		cout << "Khong tim duoc file!" << endl;
	}
	else {
		f << "So dinh cua do thi: " << g.nV << "\nDo thi:\n";
		for (int i = 0; i < g.nV; i++) {
			for (int j = 0; j < g.nV; j++) {
				f << g.adj[i][j] << " ";
			}
			f << "\n";
		}

		int path[MAX];

		if (DFS_Hamilton(path, g) == FOUND) {
			Print_Hamilton_Cycle(path, g, f);
			f << "Ket luan: Do thi co chu trinh Hamilton.\n";
		}
		else {
			if (DFS_Hamilton(path, g) == FOUND) {
				Print_Hamilton_Path(path, g, f);
				f << "Ket luan: Do thi co duong di Hamilton.\n";
			}
			else if (DFS_Hamilton(path, g) == NOT_FOUND) {
				Print_No_Hamilton(path, g, f, false);
				f << "Ket luan: Do thi khong co duong di Hamilton.\n";
			}

			else {
				Print_No_Hamilton(path, g, f, true);
				f << "Ket luan: Do thi khong co chu trinh va duong di Hamilton.\n";
			}
		}



		f << "\n\n";
		f.close();
	}
}

int main()
{
	GRAPH g;
	string files[] = {"G1.txt", "G2.txt", "G3.txt", "G4.txt"};

	for (const string& file : files) {
		Read_Graph(file, g);
		Print_Graph("output.txt", g);
	}

	return 0;
}

// G1
// 5
// 0 1 0 1 0
// 1 0 1 0 0
// 0 1 0 1 1
// 1 0 1 0 1
// 0 0 1 1 0

// G2
// 5
// 0 1 1 0 0
// 1 0 0 0 1
// 1 0 0 1 1
// 0 0 1 0 1
// 0 1 1 1 0

// G3
// 4
// 0 1 0 0
// 1 0 1 1
// 0 1 0 1
// 0 1 1 0

// G4
// 7
// 0 1 0 0 0 0 0
// 1 0 1 0 0 0 0
// 0 1 0 1 1 1 0
// 0 0 1 0 0 0 0
// 0 0 1 0 0 1 0
// 0 0 1 0 1 0 1
// 0 0 0 0 0 0 1
