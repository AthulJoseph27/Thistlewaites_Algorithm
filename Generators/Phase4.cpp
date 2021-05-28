#include "Cube.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<unsigned long long, string> mp;
long long cnt = 0;
int currentLevel = 0;

void executeMove(char c, Cube *cube)
{

    if (c == 'R')
    {
        cube->R();
        cube->R();
    }
    else if (c == 'L')
    {
        cube->L();
        cube->L();
    }
    else if (c == 'F')
    {
        cube->F();
        cube->F();
    }
    else if (c == 'B')
    {
        cube->B();
        cube->B();
    }
    else if (c == 'U')
    {
        cube->U();
        cube->U();
    }
    else if (c == 'D')
    {
        cube->D();
        cube->D();
    }
}

void reverseMove(char c, Cube *cube)
{

    if (c == 'R')
    {
        cube->R();
        cube->R();
    }
    else if (c == 'L')
    {
        cube->L();
        cube->L();
    }
    else if (c == 'F')
    {
        cube->F();
        cube->F();
    }
    else if (c == 'B')
    {
        cube->B();
        cube->B();
    }
    else if (c == 'U')
    {
        cube->U();
        cube->U();
    }
    else if (c == 'D')
    {
        cube->D();
        cube->D();
    }
}

string getSolution(string algo)
{
    string s = "";
    for (int i = algo.size() - 1; i >= 0; i--)
        s += algo[i];
    return s;
}

unsigned long long getStateId(Cube *cube, const vector<unsigned long long> &pow2)
{

    unsigned long long id = 0;
    int pos = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (cube->up[i][j] == 'W')
                id += pow2[pos];
            pos++;
            if (cube->down[i][j] == 'Y')
                id += pow2[pos];
            pos++;
            if (cube->front[i][j] == 'O')
                id += pow2[pos];
            pos++;
            if (cube->back[i][j] == 'R')
                id += pow2[pos];
            pos++;
            if (cube->left[i][j] == 'G')
                id += pow2[pos];
            pos++;
            if (cube->right[i][j] == 'B')
                id += pow2[pos];
            pos++;
        }
    return id;
}

void dfs(int level, string algo, Cube *cube, const vector<unsigned long long> &pow2, const vector<char> &moves)
{

    if (level == 15 || mp.size() == 663552)
        return;

    int n = algo.size();
    for (auto i : moves)
    {
        cnt++;
        if (n != 0)
        {
            if ((algo.back() == i))
            {
                continue;
            }
            if (((i == 'U' && algo.back() == 'D') || (i == 'R' && algo.back() == 'L') || (i == 'F' && algo.back() == 'B')))
            {
                continue;
            }
        }
        executeMove(i, cube);
        unsigned long long id = getStateId(cube, pow2);
        if (mp.find(id) == mp.end() || mp[id].size() > algo.size() + 1)
        {
            mp[id] = getSolution(algo + i);
            printf("%d  %d %.2lf\r", mp.size(), currentLevel, (((double)cnt) / 5642219814.91));
        }
        dfs(level + 1, algo + i, cube, pow2, moves);
        reverseMove(i, cube);
    }
}

void bfs(int level, string algo, Cube *cube, const vector<unsigned long long> &pow2, const vector<char> &moves)
{

    if (level == 0 || mp.size() == 663552)
        return;

    int n = algo.size();
    for (auto i : moves)
    {
        cnt++;
        if (n != 0)
        {
            if ((algo.back() == i))
            {
                continue;
            }
            if (((i == 'U' && algo.back() == 'D') || (i == 'R' && algo.back() == 'L') || (i == 'F' && algo.back() == 'B')))
            {
                continue;
            }
        }
        executeMove(i, cube);
        if (level == 1)
        {
            unsigned long long id = getStateId(cube, pow2);
            if (mp.find(id) == mp.end() || mp[id].size() > algo.size() + 1)
            {
                mp[id] = getSolution(algo + i);
                printf("%d  %d %.2lf\r", mp.size(), currentLevel, (((double)cnt) / 5642219814.91));
            }
        }
        bfs(level - 1, algo + i, cube, pow2, moves);
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
    fstream sol_file, state_file, solIn, statesIn, _statesIN, _solIN;
    vector<char> moves = {'R', 'L', 'U', 'D', 'F', 'B'};
    mp[0] = "";
    vector<unsigned long long> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984};
    
    dfs(0,"",&cube,pow2,moves);
    
    sol_file.open("Phase_4_sol.txt", ios::out);
    state_file.open("Phase_4_states.txt", ios::out);
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
