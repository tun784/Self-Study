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

Graph khoi_tao(int n) {
    Graph g;
    // Initialize the graph here
    return g;
}

Graph Doc_ma_tran_ke(string fileName)
{
    Graph g;
    ifstream fileIn;

    fileIn.open(fileName, ios::in);
    if (fileIn.fail())
    {
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

Graph Doc_danh_sach_canh(string fileName)
{
    Graph g;

    ifstream fileIn;
    fileIn.open(fileName, ios::in);
    if (fileIn.fail())
    {
        cout << "File khong ton tai !!!\n";
        g.flag = -1;
        return g;
    }

    int flag, n;
    fileIn >> flag;
    fileIn >> n;
    g = khoi_tao(n);
    g.flag = flag;
    
    int so_canh;
    fileIn >> so_canh;

    for (int i = 0; i < so_canh; i++)
    {
        int dinh_dau, dinh_cuoi;
        fileIn >> dinh_dau;
        fileIn >> dinh_cuoi;

        g.m[dinh_dau][dinh_cuoi] = 1;
        if (g.flag == 0)
            g.m[dinh_cuoi][dinh_dau] = 1;
    }

    fileIn.close();
    return g;
}

int main()
{
    
    return 0;
}