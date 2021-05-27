#include "Cube.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, string> mp;
string currentSolution = "";
int currentLevel;
long long cnt = 0;
long long lastCnt = 0;
char lastInitialMove = 'E';

bool validSolution(string s)
{
    for (char c : s)
        if (c == 'R' || c == 'r' || c == 'L' || c == 'l')
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
}

void reverseMove(char c, Cube *cube)
{

    if (c == 'r')
        cube->R();
    else if (c == 'l')
        cube->L();
    else if (c == 'f')
    {
        cube->F();
        cube->F();
    }
    else if (c == 'b')
    {
        cube->B();
        cube->B();
    }
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
    {
        cube->f();
        cube->f();
    }
    else if (c == 'B')
    {
        cube->b();
        cube->b();
    }
    else if (c == 'U')
    {
        cube->u();
        cube->u();
    }
    else if (c == 'D')
    {
        cube->d();
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

// void handleFace(unsigned long long *id, int *pos, const vector<vector<char>>& front,const vector<vector<char>>& back){
    
//     if(front[0][0] == front[0][2] && front[0][2] == front[2][2] && front[2][2] == front[2][0])
//         return;
//     if(front[0][0] == front[0][2] && ((back[0][2] == back[0][0] && back[0][0] == front[0][2]) || (back[2][2] == back[2][0] && front[0][0] == back[2][0])))
//         return;
//     if(front[2][0] == front[2][2] && ((back[0][2] == back[0][0] && back[0][0] == front[0][2]) || (back[2][2] == back[2][0] && front[0][0] == back[2][0])))
//         return;

//     /*
//         Case 1:
//             - * -  +   - * *
//                        *
//                        _
//     */
// }

unsigned long long getStateId(Cube *cube, const vector<unsigned long long> &pow2)
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1)
                continue;
            if(cube->up[i][j] != 'W' && cube->up[i][j]!='Y')
                return 0;
            if(cube->down[i][j] != 'W' && cube->down[i][j]!='Y')
                return 0;
            if(cube->front[i][j] != 'R' && cube->front[i][j]!='O')
                return 0;
            if(cube->back[i][j] != 'R' && cube->back[i][j]!='O')
                return 0;
        }
    }

    unsigned long long id = 0;
    int pos = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==0 && j==0)
                continue;
            if(i==1 && j==1)
                continue;
            if((i==j)||((i+j)==2)){
                if(cube->up[0][0]!=cube->up[i][j])
                    id+=pow2[pos];
                pos++;
                if(cube->down[0][0]!=cube->down[i][j])
                    id+=pow2[pos];
                pos++;
                if(cube->left[0][0]!=cube->left[i][j])
                    id+=pow2[pos];
                pos++;
                if(cube->right[0][0]!=cube->right[i][j])
                    id+=pow2[pos];
                pos++;
                if(cube->front[0][0]!=cube->front[i][j])
                    id+=pow2[pos];
                pos++;
                if(cube->back[0][0]!=cube->back[i][j])
                    id+=pow2[pos];
                pos++;
            }
        }
    }

    return id;
}

void dfs(int level, string algo, Cube *cube, const vector<unsigned long long> &pow2, const vector<char> moves)
{

    if (level == 14)
        return;

    int n = algo.size();

    int startp = 0, endp = moves.size();

    if(level == 0){
        startp = 2;
        endp = 4;
    }
    for (int index = startp;index<endp;index++)
    {   
        char i = moves[index];
        cnt++;
        if (n != 0)
        {
            if ((algo.back() == i) && (i == 'U' || i == 'F' || i == 'D' || i == 'B'))
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
            if ((i == 'r' && algo.back() == 'l'))
            {
                continue;
            }
            if (n >= 2)
            {
                if ((i == 'L' && algo[n - 1] == 'L' && algo[n - 2] == 'L'))
                {
                    continue;
                }
                if ((i == 'R' && algo[n - 1] == 'R' && algo[n - 2] == 'R'))
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
            if (mp.find(id) == mp.end() || mp[id].size() > (algo.size() + 1))
            {
                mp[id] = getSolution(algo + i);
                printf("%lu %d\r", mp.size(), level);
            }
        }
        dfs(level + 1, algo + i, cube, pow2, moves);
        reverseMove(i, cube);
    }
}

int main()
{
    Cube cube = Cube();
    fstream sol_file, state_file, solIn, statesIn, _statesIN, _solIN, shuffleIn;
    vector<unsigned long long> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984};
    vector<char> moves = {'R', 'L', 'U', 'D', 'F', 'B', 'r', 'l'};
    mp[0] = "";
    dfs(0, "", &cube, pow2, moves);

    sol_file.open("Phase_3B_sol.txt", ios::out);
    state_file.open("Phase_3B_states.txt", ios::out);
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