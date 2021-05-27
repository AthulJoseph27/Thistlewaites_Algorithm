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
        if (c == 'F' || c == 'f' || c == 'B' || c == 'b')
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
        cube->U();
    }
    else if (c == 'D')
    {
        cube->D();
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
        cube->U();
        cube->U();
    }
    else if (c == 'd')
    {
        cube->D();
        cube->D();
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
        cube->U();
    }
    else if (c == 'd')
    {
        cube->D();
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

unsigned long long getStateId(Cube *cube, const vector<unsigned long long> &pow2)
{

    unsigned long long id = 0;
    int pos = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (j == 1 && i == 1)
                continue;
            if (cube->up[i][j] == 'G')
                id += pow2[pos];
            pos++;
            if (cube->down[i][j] == 'G')
                id += pow2[pos];
            pos++;
            if (cube->front[i][j] == 'G')
                id += pow2[pos];
            pos++;
            if (cube->back[i][j] == 'G')
                id += pow2[pos];
            pos++;
            if (cube->left[i][j] != 'G')
                id += pow2[pos];
            pos++;
            if (cube->right[i][j] != 'G')
                id += pow2[pos];
            pos++;
        }

    return id;
}

void bfs(int level, string algo, Cube *cube, const vector<unsigned long long> &pow2, const vector<char> &moves)
{

    if (level == 0 || mp.size() == 1082565)
        return;

    int n = algo.size();
    for (auto i : moves)
    {
        cnt++;
        if (n != 0)
        {
            if ((algo.back() == i) && (i == 'U' || i == 'D'))
            {
                continue;
            }
            if ((algo.back() != i) && (tolower(algo.back()) == tolower(i)))
            {
                continue;
            }
            if (((i == 'U' && algo.back() == 'D') || (i == 'R' && algo.back() == 'L') || (i == 'F' && algo.back() == 'B')))
            {
                continue;
            }
            if (((i == 'r' && algo.back() == 'l') || (i == 'f' && algo.back() == 'b')))
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
        if (level == 1 && validSolution(algo + i))
        {
            unsigned long long id = getStateId(cube, pow2);
            if ((mp.find(id) == mp.end() || mp[id].size() > (algo.size() + 1)))
            {
                mp[id] = getSolution(algo + i);
                printf("%lu %d %.2lf\r", mp.size(), currentLevel, (((double)cnt) / 1100000000));
            }
        }
        bfs(level - 1, algo + i, cube, pow2, moves);
        reverseMove(i, cube);
    }
}

void dfs(int level, string algo, Cube *cube, const vector<unsigned long long> &pow2, const vector<char> &moves)
{

    if (level == 11 || mp.size() == 1082565)
        return;

    int n = algo.size();
    for (auto i : moves)
    {
        cnt++;
        if (n != 0)
        {
            if ((algo.back() == i) && (i == 'U' || i == 'D'))
            {
                continue;
            }
            if ((algo.back() != i) && (tolower(algo.back()) == tolower(i)))
            {
                continue;
            }
            if (((i == 'U' && algo.back() == 'D') || (i == 'R' && algo.back() == 'L') || (i == 'F' && algo.back() == 'B')))
            {
                continue;
            }
            if (((i == 'r' && algo.back() == 'l') || (i == 'f' && algo.back() == 'b')))
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
            unsigned long long id = getStateId(cube, pow2);
            if ((mp.find(id) == mp.end() || mp[id].size() > (algo.size() + 1)))
            {
                mp[id] = getSolution(algo + i);
                printf("%lu %d %.2lf\r", mp.size(), level + 1, (((double)cnt) / 1100000000));
            }
        }
        dfs(level + 1, algo + i, cube, pow2, moves);
        reverseMove(i, cube);
    }
}

int main()
{
    Cube cube = Cube({{'G', 'G', 'G'},
                      {'G', 'G', 'G'},
                      {'G', 'G', 'G'}},

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
    vector<char> moves = {'R', 'L', 'U', 'D', 'F', 'B', 'r', 'l', 'f', 'b'};
    vector<unsigned long long> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984};
    mp[0] = "";
    dfs(0, "", &cube, pow2, moves);
    for (int i = 1; i <= 11; i++)
    {
        currentLevel = i;
        printf("%lu %d %.2lf\r", mp.size(), currentLevel, (((double)cnt) / 1100000000));
        bfs(i, "", &cube, pow2, moves);
    }
    sol_file.open("Phase_2_sol.txt", ios::out);
    state_file.open("Phase_2_states.txt", ios::out);
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