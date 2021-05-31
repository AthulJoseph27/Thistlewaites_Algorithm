#include "Cube.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, string> phase1;
unordered_map<unsigned long long, string> phase2;
unordered_map<unsigned long long, string> phase3a;
unordered_map<unsigned long long, string> phase3b;
unordered_map<unsigned long long, string> phase4;

string currentShuffle = "";

const vector<char> moves = {'R', 'L', 'U', 'D', 'F', 'B', 'r', 'l', 'u', 'd', 'f', 'b'};
const vector<unsigned long long> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984};

void loadLookUpTable()
{
    fstream sol_file, state_file;

    string sl;
    unsigned long long st;

    phase1[0] = "";
    phase2[0] = "";
    phase3a[0] = "";
    phase3b[0] = "";
    phase4[0] = "";

    sol_file.open("Phase_1_sol.txt", ios::in);
    state_file.open("Phase_1_states.txt", ios::in);

    while (state_file >> st)
    {
        if (st == 0)
            continue;
        sol_file >> sl;
        phase1[st] = sl;
    }

    sol_file.close();
    state_file.close();

    sol_file.open("Phase_2_sol.txt", ios::in);
    state_file.open("Phase_2_states.txt", ios::in);

    while (state_file >> st)
    {
        if (st == 0)
            continue;
        sol_file >> sl;
        phase2[st] = sl;
    }

    sol_file.close();
    state_file.close();

    sol_file.open("Phase_3A_sol.txt", ios::in);
    state_file.open("Phase_3A_states.txt", ios::in);

    while (state_file >> st)
    {
        if (st == 0)
            continue;
        sol_file >> sl;
        phase3a[st] = sl;
    }

    sol_file.close();
    state_file.close();

    sol_file.open("Phase_3B_sol.txt", ios::in);
    state_file.open("Phase_3B_states.txt", ios::in);

    while (state_file >> st)
    {
        if (st == 0)
            continue;
        sol_file >> sl;
        phase3b[st] = sl;
    }

    sol_file.close();
    state_file.close();

    sol_file.open("Phase_4_sol.txt", ios::in);
    state_file.open("Phase_4_states.txt", ios::in);

    while (state_file >> st)
    {
        if (st == 0)
            continue;
        sol_file >> sl;
        phase4[st] = sl;
    }

    sol_file.close();
    state_file.close();
}

unsigned long long calculateP1Id(Cube *cube)
{

    unsigned long long id = 0;
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

    // cout<<id<<'\n';

    return id;
}

unsigned long long calculateP2Id(Cube *cube)
{

    unsigned long long id = 0;
    int pos = 0;

    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // cube->show();

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (j == 1 && i == 1)
                continue;
            if (cube->up[i][j] == 'G' || cube->up[i][j] == 'B')
                id += pow2[pos];
            pos++;
            if (cube->down[i][j] == 'G' || cube->down[i][j] == 'B')
                id += pow2[pos];
            pos++;
            if (cube->front[i][j] == 'G' || cube->front[i][j] == 'B')
                id += pow2[pos];
            pos++;
            if (cube->back[i][j] == 'G' || cube->back[i][j] == 'B')
                id += pow2[pos];
            pos++;
            if (cube->left[i][j] != 'G' && cube->left[i][j] != 'B')
                id += pow2[pos];
            pos++;
            if (cube->right[i][j] != 'G' && cube->right[i][j] != 'B')
                id += pow2[pos];
            pos++;
        }

    // cout<<id<<'\n';

    return id;
}

unsigned long long calculateP3AId(Cube *cube)
{

    unsigned long long id = 0;
    int pos = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (cube->up[i][j] != 'Y' && cube->up[i][j] != 'W')
                id += pow2[pos];
            pos++;
            if (cube->down[i][j] != 'Y' && cube->down[i][j] != 'W')
                id += pow2[pos];
            pos++;
            if (cube->front[i][j] != 'R' && cube->front[i][j] != 'O')
                id += pow2[pos];
            pos++;
            if (cube->back[i][j] != 'R' && cube->back[i][j] != 'O')
                id += pow2[pos];
            pos++;
        }
    }

    return id;
}

unsigned long long calculateP3BId(Cube *cube)
{

    unsigned long long id = 0;
    int pos = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 1 && j == 1)
                continue;
            if ((i == j) || ((i + j) == 2))
            {
                if (cube->up[0][0] != cube->up[i][j])
                    id += pow2[pos];
                pos++;
                if (cube->down[0][0] != cube->down[i][j])
                    id += pow2[pos];
                pos++;
                if (cube->left[0][0] != cube->left[i][j])
                    id += pow2[pos];
                pos++;
                if (cube->right[0][0] != cube->right[i][j])
                    id += pow2[pos];
                pos++;
                if (cube->front[0][0] != cube->front[i][j])
                    id += pow2[pos];
                pos++;
                if (cube->back[0][0] != cube->back[i][j])
                    id += pow2[pos];
                pos++;
            }
        }
    }

    return id;
}

unsigned long long calculateP4Id(Cube *cube)
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

void solvePhase1(Cube *cube)
{

    unsigned long long stateId = calculateP1Id(cube);

    if (phase1.find(stateId) == phase1.end())
    {
        cout << currentShuffle << '\n';
        assert(false);
    }

    string sol = phase1[stateId];

    cout << sol;

    for (char c : sol)
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
            cube->U();
        else if (c == 'D')
            cube->D();
        else if (c == 'r')
            cube->r();
        else if (c == 'l')
            cube->l();
        else if (c == 'f')
            cube->f();
        else if (c == 'b')
            cube->b();
        else if (c == 'u')
            cube->u();
        else if (c == 'd')
            cube->d();
        else
        {
            cout << c << '\n';
            assert(false);
        }
    }
}

void solvePhase2(Cube *cube)
{

    unsigned long long stateId = calculateP2Id(cube);

    if (phase2.find(stateId) == phase2.end())
    {
        cout << stateId << endl;
        cout << currentShuffle << '\n';
        assert(false);
    }

    string sol = phase2[stateId];

    for (char c : sol)
    {
        if (c == 'u' || c == 'U')
        {
            cout << "U2";
        }
        else if (c == 'd' || c == 'D')
        {
            cout << "D2";
        }
        else
        {
            cout << c;
        }
    }

    for (char c : sol)
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
            cube->u();
            cube->u();
        }
        else if (c == 'd')
        {
            cube->d();
            cube->d();
        }
        else
        {
            cout << c << '\n';
            assert(false);
        }
    }
}

void solvePhase3(Cube *cube, bool a)
{

    unsigned long long stateId = a ? calculateP3AId(cube) : calculateP3BId(cube);

    if (a)
    {
        if (phase3a.find(stateId) == phase3a.end())
        {
            cout << stateId << endl;
            cout << currentShuffle << '\n';
            assert(false);
        }
    }
    else
    {
        if (phase3b.find(stateId) == phase3b.end())
        {
            cout << currentShuffle << '\n';
            assert(false);
        }
    }

    string sol = a ? phase3a[stateId] : phase3b[stateId];

    for (char c : sol)
    {
        if (c == 'u' || c == 'U')
        {
            cout << "U2";
        }
        else if (c == 'd' || c == 'D')
        {
            cout << "D2";
        }
        else if (c == 'f' || c == 'F')
        {
            cout << "F2";
        }
        else if (c == 'b' || c == 'B')
        {
            cout << "B2";
        }
        else
        {
            cout << c;
        }
    }

    for (char c : sol)
    {
        if (c == 'R')
            cube->R();
        else if (c == 'L')
            cube->L();
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
        else if (c == 'r')
            cube->r();
        else if (c == 'l')
            cube->l();
        else if (c == 'f')
        {
            cube->f();
            cube->f();
        }
        else if (c == 'b')
        {
            cube->b();
            cube->b();
        }
        else if (c == 'u')
        {
            cube->u();
            cube->u();
        }
        else if (c == 'd')
        {
            cube->d();
            cube->d();
        }
        else
        {
            cout << c << '\n';
            assert(false);
        }
    }
}

void solvePhase4(Cube *cube)
{

    unsigned long long stateId = calculateP4Id(cube);

    if (phase4.find(stateId) == phase4.end())
    {
        cout << currentShuffle << '\n';
        assert(false);
    }

    string sol = phase4[stateId];

    for (char c : sol)
    {
        cout << c << "2";
    }

    cout << endl;

    for (char c : sol)
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
        else
        {
            cout << "Phase 4" << '\n';
            cout << c << '\n';
            assert(false);
        }
    }
}

void Shuffle(Cube *cube, const string &s)
{

    for (char c : s)
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
            cube->U();
        else if (c == 'D')
            cube->D();
        else if (c == 'r')
            cube->r();
        else if (c == 'l')
            cube->l();
        else if (c == 'f')
            cube->f();
        else if (c == 'b')
            cube->b();
        else if (c == 'u')
            cube->u();
        else if (c == 'd')
            cube->d();
        else
        {
            cout << c << '\n';
            assert(false);
        }
    }
}

int main()
{
    srand(time(0));
    cout << "Loading Lookup Table ..." << '\n';
    loadLookUpTable();
    cout << "Done" << '\n';

    cout << "Testing ..." << '\n';

    Cube cube = Cube();

    cout << "Enter Shuffle Algorithm" << endl;

    string sh;

    cin >> sh;

    Shuffle(&cube, sh);
    solvePhase1(&cube);
    solvePhase2(&cube);
    solvePhase3(&cube, true);
    solvePhase3(&cube, false);
    solvePhase4(&cube);

    return 0;
}