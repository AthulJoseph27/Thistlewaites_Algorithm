#include "Cube.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

map<long long, string> mp;
vector<unsigned long long> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984};
vector<char> moves = {'R', 'L', 'U', 'D', 'F', 'B', 'r', 'l', 'f', 'b', 'u', 'd'};
long long cnt = 0;
int currentLevel = 0;

bool validSolution(string algo)
{
    for (char c : algo)
        if (c == 'U' || c == 'u' || c == 'D' || c == 'd')
            return true;

    return false;
}

void executeMove(char c, Cube *cube)
{

    if (c == 'R')
        cube->R();
    else if (c == 'L')
        cube->L();
    else if (c == 'F')
        cube->F();
    else if (c == 'B')
        cube->B();
    else if (c == 'U')
    {
        cube->U();
    }
    else if (c == 'D')
    {
        cube->D();
    }
    else if (c == 'r')
        cube->r();
    else if (c == 'l')
        cube->l();
    else if (c == 'f')
        cube->f();
    else if (c == 'b')
        cube->b();
    else if (c == 'u')
    {
        cube->u();
    }
    else if (c == 'd')
    {
        cube->d();
    }
}

void reverseMove(char c, Cube *cube)
{

    if (c == 'r')
        cube->R();
    else if (c == 'l')
        cube->L();
    else if (c == 'f')
        cube->F();
    else if (c == 'b')
        cube->B();
    else if (c == 'u')
    {
        cube->U();
    }
    else if (c == 'd')
    {
        cube->D();
    }
    else if (c == 'R')
        cube->r();
    else if (c == 'L')
        cube->l();
    else if (c == 'F')
        cube->f();
    else if (c == 'B')
        cube->b();
    else if (c == 'U')
    {
        cube->u();
    }
    else if (c == 'D')
    {
        cube->d();
    }
}

string getSolution(string algo)
{
    string s = "";
    for (int i = algo.size() - 1; i >= 0; i--)
    {
        if (algo[i] > 90)
        {
            s += ((char)(algo[i] - 32));
        }
        else
        {
            s += ((char)(algo[i] + 32));
        }
    }
    return s;
}

long long getStateId(Cube *cube)
{

    long long id = 0;
    int pos = 0;

    if (cube->front[0][1] == 'G' || cube->front[0][1] == 'B' || cube->up[2][1] == 'R' || cube->up[2][1] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->front[1][0] == 'G' || cube->front[1][0] == 'B' || cube->left[1][2] == 'R' || cube->left[1][2] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->front[2][1] == 'G' || cube->front[2][1] == 'B' || cube->down[0][1] == 'R' || cube->down[0][1] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->front[1][2] == 'G' || cube->front[1][2] == 'B' || cube->right[1][0] == 'R' || cube->right[1][0] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->back[0][1] == 'G' || cube->back[0][1] == 'B' || cube->up[0][1] == 'R' || cube->up[0][1] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->back[1][0] == 'G' || cube->back[1][0] == 'B' || cube->right[1][2] == 'R' || cube->right[1][2] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->back[2][1] == 'G' || cube->back[2][1] == 'B' || cube->down[2][1] == 'R' || cube->down[2][1] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->back[1][2] == 'G' || cube->back[1][2] == 'B' || cube->left[1][0] == 'R' || cube->left[1][0] == 'O')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->left[0][1] == 'R' || cube->left[0][1] == 'O' || cube->up[1][0] == 'B' || cube->up[1][0] == 'G')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->left[2][1] == 'R' || cube->left[2][1] == 'O' || cube->down[1][0] == 'B' || cube->down[1][0] == 'G')
    {
        id += pow2[pos];
    }
    pos++;

    if (cube->right[0][1] == 'R' || cube->right[0][1] == 'O' || cube->up[1][2] == 'B' || cube->up[1][2] == 'G')
    {

        id += pow2[pos];
    }
    pos++;

    if (cube->right[2][1] == 'R' || cube->right[2][1] == 'O' || cube->down[1][2] == 'B' || cube->down[1][2] == 'G')
    {

        id += pow2[pos];
    }

    return id;
}

void dfs(int level, string algo, Cube *cube)
{

    if (level == 7)
        return;

    int n = algo.size();
    for (auto i : moves)
    {
        cnt++;
        if (n != 0)
        {
            if ((algo.back() != i) && (tolower(algo.back()) == tolower(i)))
            {
                continue;
            }
            if (((i == 'U' && algo.back() == 'D') || (i == 'R' && algo.back() == 'L') || (i == 'F' && algo.back() == 'B')))
            {
                continue;
            }
            if (((i == 'u' && algo.back() == 'd') || (i == 'r' && algo.back() == 'l') || (i == 'f' && algo.back() == 'b')))
            {
                continue;
            }
            if (n >= 2)
            {
                if ((i == 'F' && algo[n - 1] == 'F' && algo[n - 2] == 'F'))
                {
                    continue;
                }
                if ((i == 'B' && algo[n - 1] == 'B' && algo[n - 2] == 'B'))
                {
                    continue;
                }
                if ((i == 'L' && algo[n - 1] == 'L' && algo[n - 2] == 'L'))
                {
                    continue;
                }
                if ((i == 'R' && algo[n - 1] == 'R' && algo[n - 2] == 'R'))
                {
                    continue;
                }
                if ((i == 'f' && algo[n - 1] == 'f' && algo[n - 2] == 'f'))
                {
                    continue;
                }
                if ((i == 'b' && algo[n - 1] == 'b' && algo[n - 2] == 'b'))
                {
                    continue;
                }
                if ((i == 'l' && algo[n - 1] == 'l' && algo[n - 2] == 'l'))
                {
                    continue;
                }
                if ((i == 'r' && algo[n - 1] == 'r' && algo[n - 2] == 'r'))
                {
                    continue;
                }
            }
        }
        executeMove(i, cube);
        if (validSolution(algo + i))
        {
            long long id = getStateId(cube);
            if ((mp.find(id) == mp.end() || mp[id].size() > (algo.size() + 1)))
            {
                mp[id] = getSolution(algo + i);
                printf("%lu  %d  %.2f\r", mp.size(), level, ((float)cnt) / 32574.37);
            }
        }
        dfs(level + 1, algo + i, cube);
        reverseMove(i, cube);
    }
}

int main()
{
    Cube cube = Cube({{'B', 'B', 'B'},
                      {'B', 'B', 'B'},
                      {'B', 'B', 'B'}},

                     {{'R', 'R', 'R'},
                      {'R', 'R', 'R'},
                      {'R', 'R', 'R'}},

                     {{'G', 'G', 'G'},
                      {'G', 'G', 'G'},
                      {'G', 'G', 'G'}},

                     {{'O', 'O', 'O'},
                      {'O', 'O', 'O'},
                      {'O', 'O', 'O'}},

                     {{'Y', 'Y', 'Y'},
                      {'Y', 'Y', 'Y'},
                      {'Y', 'Y', 'Y'}},

                     {{'W', 'W', 'W'},
                      {'W', 'W', 'W'},
                      {'W', 'W', 'W'}});

    fstream sol_file, state_file, solIn, statesIn;
    mp[0] = "";
    dfs(0, "", &cube);
    sol_file.open("Phase_1_sol.txt", ios::out);
    state_file.open("Phase_1_states.txt", ios::out);
    cout << "Writing Generator Data on to the file" << endl;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        state_file << it->first << endl;
        sol_file << it->second << endl;
    }

    sol_file.close();
    state_file.close();

    cout << mp.size() << endl;

    return 0;
}