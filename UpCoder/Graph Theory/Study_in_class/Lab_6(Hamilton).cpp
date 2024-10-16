//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//#define MAX 20
//#define FOUND 1
//#define NOT_FOUND 0
//
//struct GRAPH {
//    int nV;
//    int arr[MAX][MAX];
//};
//
//void Read_Graph(string fn, GRAPH& g) {
//    ifstream f(fn);
//    if (!f.is_open()) {
//        cout << "Khong tim duoc file!" << endl;
//    }
//    else {
//        f >> g.nV; 
//
//        for (int i = 0; i < g.nV; i++) {
//            for (int j = 0; j < g.nV; j++) {
//                f >> g.arr[i][j];
//            }
//        }
//        f.close();
//    }
//}
//
//int visit(int u, int visited[], int& count, int& flag, int path[], GRAPH& g) {
//    if (flag == FOUND) return FOUND;
//
//    for (int v = 0; v < g.nV; v++) {
//        if (visited[v] == 0 && g.arr[u][v] == 1) {  
//            visited[v] = 1;
//            path[count] = v;
//            count++;
//
//            //co duong di Hamilton
//            if (count == g.nV && g.arr[v][path[0]] == 1) { 
//                flag = FOUND;
//                return FOUND;
//            }
//
//            //co chu trinh Hamilton
//            if (count > g.nV && g.arr[v][path[0]] == 1) {
//                flag = FOUND;
//                return FOUND;
//            }
//
//            visit(v, visited, count, flag, path, g);
//
//            if (flag == FOUND) return FOUND;
//
//            count--;
//            visited[v] = 0;
//        }
//    }
//
//    return NOT_FOUND;
//}
//
//int DFS_Hamilton(int path[], GRAPH& g) {
//    int start = 0;
//    int flag = NOT_FOUND;
//    int visited[MAX] = { 0 };
//    int count = 1;
//
//    path[0] = start;
//    visited[start] = 1;
//
//    visit(start, visited, count, flag, path, g);
//
//    return flag;
//}
//
//void Print_Hamilton_Path(int path[], GRAPH& g, ofstream& f) {
//    f << "Duong di Hamilton la:\n";
//    for (int i = 0; i < g.nV; i++) {
//        f << path[i] << " -> ";
//    }
//    f << path[0] << "\n";
//}
//
//void Print_Non_Hamilton_Path(int path[], GRAPH& g, ofstream& f) {
    /*f << "Khong co duong di Hamilton\n";
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
    f << endl;*/
//
//
//}
//
////void Print_Graph(string fn, GRAPH& g) {
////    ofstream f(fn, ios::app);
////    if (!f.is_open()) {
////        cout << "Khong tim duoc file!" << endl;
////    }
////    else {
////        f << "So dinh cua do thi: " << g.nV << "\nDo thi:\n";
////        for (int i = 0; i < g.nV; i++) {
////            for (int j = 0; j < g.nV; j++) {
////                f << g.arr[i][j] << " ";
////            }
////            f << "\n";
////        }
////
////        int path[MAX];
////        if (DFS_Hamilton(path, g) == FOUND)
////        {
////            Print_Hamilton_Path(path, g, f);
////        }
////
////        else
////        {
////            Print_Non_Hamilton_Path(path, g, f);
////        }
////
////        f << "\n\n";
////
////        f.close();
////    }
////}
//
//void Print_Graph(string fn, GRAPH& g) {
//    ofstream f(fn, ios::app);
//    if (!f.is_open()) {
//        cout << "Khong tim duoc file!" << endl;
//    }
//    else {
//        f << "So dinh cua do thi: " << g.nV << "\nDo thi:\n";
//        for (int i = 0; i < g.nV; i++) {
//            for (int j = 0; j < g.nV; j++) {
//                f << g.arr[i][j] << " ";
//            }
//            f << "\n";
//        }
//
//        int path[MAX];
//        if (DFS_Hamilton(path, g) == FOUND) {
//            Print_Hamilton_Path(path, g, f);
//            f << "Ket luan: Do thi co chu trinh Hamilton.\n";
//        }
//        else {
//            Print_Non_Hamilton_Path(path, g, f);
//            f << "Ket luan: Do thi khong co chu trinh Hamilton.\n";
//        }
//
//        f << "\n\n";
//        f.close();
//    }
//}
//
//
//int main() {
//    GRAPH g;
//    vector<string> files = { "G1.txt", "G2.txt", "G3.txt", "G4.txt" };
//
//    for (const string& file : files) {
//        Read_Graph(file, g);        
//        Print_Graph("output.txt", g);  
//    }
//
//    return 0;
//}


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAX 20
#define FOUND 1
#define NOT_FOUND 0

struct GRAPH {
    int nV;
    int arr[MAX][MAX];  
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
                f >> g.arr[i][j]; 
            }
        }
        f.close();
    }
}

int visit(int u, int visited[], int& count, int& flag, int path[], GRAPH& g, bool isCycleCheck) {
    if (flag == FOUND) return FOUND;  

    for (int v = 0; v < g.nV; v++) {
        if (visited[v] == 0 && g.arr[u][v] == 1) {  
            visited[v] = 1;
            path[count] = v;
            count++;

            if (count == g.nV) {  
                if (isCycleCheck && g.arr[v][path[0]] == 1) { 
                    flag = FOUND;
                    return FOUND;
                }
                else if (!isCycleCheck) { 
                    flag = FOUND;
                    return FOUND;
                }
            }

            visit(v, visited, count, flag, path, g, isCycleCheck);  

            if (flag == FOUND) return FOUND;  

            count--;  
            visited[v] = 0;
        }
    }

    return NOT_FOUND;
}

int DFS_Hamilton_Cycle(int path[], GRAPH& g) {
    int start = 0;
    int flag = NOT_FOUND;
    int visited[MAX] = { 0 };
    int count = 1;

    path[0] = start; 
    visited[start] = 1;

    visit(start, visited, count, flag, path, g, true);  

    return flag;
}

int DFS_Hamilton_Path(int path[], GRAPH& g) {
    int start = 0;
    int flag = NOT_FOUND;
    int visited[MAX] = { 0 };
    int count = 1;

    path[0] = start;  
    visited[start] = 1;

    visit(start, visited, count, flag, path, g, false);  

    return flag;
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
                f << g.arr[i][j] << " ";
            }
            f << "\n";
        }

        int path[MAX];

        if (DFS_Hamilton_Cycle(path, g) == FOUND) {
            Print_Hamilton_Cycle(path, g, f);
            f << "Ket luan: Do thi co chu trinh Hamilton.\n";
        }
        else {
            if (DFS_Hamilton_Path(path, g) == FOUND) {
                Print_Hamilton_Path(path, g, f);
                f << "Ket luan: Do thi co duong di Hamilton.\n";
            }
            else if (DFS_Hamilton_Path(path, g) == NOT_FOUND) {
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

int main() {
    GRAPH g;
    vector<string> files = { "G1.txt", "G2.txt", "G3.txt", "G4.txt" };

    for (const string& file : files) {
        Read_Graph(file, g);
        Print_Graph("output.txt", g);
    }

    return 0;
}
