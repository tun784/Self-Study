#include <iostream>
#include <fstream> // Include the <fstream> header file

using namespace std;
constexpr auto MAX = 50;
struct Graph
{
    int flag;
    int n;
    int m[MAX][MAX];
};

Graph Doc_ma_tran_ke(string fileName)
{
    Graph g;
    ifstream fileIn;

    fileIn.open(fileName, ios::in);
    if (fileIn.fail()){
        cout << "File khong ton tai";
        g.flag = -1;
        return g;
    }

    fileIn >> g.flag;
    fileIn >> g.n;

    for (int i = 0; i < g.n; i++)
        for (int j = 0; j < g.n; j++)
            fileIn >> g.m[i][j];

    fileIn.close();
    return g;
}

int main()
{
    return 0;
}