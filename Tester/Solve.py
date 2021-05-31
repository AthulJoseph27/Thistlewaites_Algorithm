import numpy as np
import random
import time
import pickle
import RCube
from tqdm import tqdm


face = [['R', 'R', 'R'],
        ['R', 'R', 'R'],
        ['R', 'R', 'R']]
back = [['O', 'O', 'O'],
        ['O', 'O', 'O'],
        ['O', 'O', 'O']]
left = [['B', 'B', 'B'],
        ['B', 'B', 'B'],
        ['B', 'B', 'B']]
right = [['G', 'G', 'G'],
         ['G', 'G', 'G'],
         ['G', 'G', 'G']]
up = [['Y', 'Y', 'Y'],
      ['Y', 'Y', 'Y'],
      ['Y', 'Y', 'Y']]
down = [['W', 'W', 'W'],
        ['W', 'W', 'W'],
        ['W', 'W', 'W']]

cube = [[' ', ' ', ' ', 'Y', 'Y', 'Y', ' ', ' ', ' '],
        [' ', ' ', ' ', 'Y', 'Y', 'Y', ' ', ' ', ' '],
        [' ', ' ', ' ', 'Y', 'Y', 'Y', ' ', ' ', ' '],
        ['B', 'B', 'B', 'R', 'R', 'R', 'G', 'G', 'G'],
        ['B', 'B', 'B', 'R', 'R', 'R', 'G', 'G', 'G'],
        ['B', 'B', 'B', 'R', 'R', 'R', 'G', 'G', 'G'],
        [' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '],
        [' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '],
        [' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '],
        [' ', ' ', ' ', 'O', 'O', 'O', ' ', ' ', ' '],
        [' ', ' ', ' ', 'O', 'O', 'O', ' ', ' ', ' '],
        [' ', ' ', ' ', 'O', 'O', 'O', ' ', ' ', ' ']]

cost_p1 = [0, 0, 0, 0]
moves = ['R', 'L', 'F', 'B', 'U', 'D', 'r', 'l', 'f', 'b', 'u', 'd']
movesp1 = ['R()', 'L()', 'F()', 'B()', 'U()', 'D()',
           'r()', 'l()', 'f()', 'b()', 'u()', 'd()']
# rev_movesp1  = ['r()','l()','f()','b()','u()','d()']

#                                                           #PART2 - U2,D2,F2,B2
movesp2 = ['R()', 'L()', 'F()', 'B()', 'U2()', 'D2()',
           'r()', 'l()', 'f()', 'b()', 'U2()', 'D2()']
# rev_movesp2  = ['r()','l()','f()','b()','U2()','D2()']

movesp3 = ['R()', 'L()', 'F2()', 'B2()', 'U2()', 'D2()',
           'r()', 'l()', 'F2()', 'B2()', 'U2()', 'D2()']
# rev_movesp3  = ['r()','l()','F2()','B2()','U2()','D2()']

movesp4 = ['R2()', 'L2()', 'F2()', 'B2()', 'U2()', 'D2()',
           'R2()', 'L2()', 'F2()', 'B2()', 'U2()', 'D2()']

solution = []


def R():
    global cube
    t = cube[0][5]
    cube[0][5] = cube[3][5]
    cube[3][5] = cube[6][5]
    cube[6][5] = cube[9][5]
    cube[9][5] = t
    t = cube[2][5]
    cube[2][5] = cube[5][5]
    cube[5][5] = cube[8][5]
    cube[8][5] = cube[11][5]
    cube[11][5] = t
    t = cube[1][5]
    cube[1][5] = cube[4][5]
    cube[4][5] = cube[7][5]
    cube[7][5] = cube[10][5]
    cube[10][5] = t
    t = cube[3][6]
    cube[3][6] = cube[5][6]
    cube[5][6] = cube[5][8]
    cube[5][8] = cube[3][8]
    cube[3][8] = t
    t = cube[4][6]
    cube[4][6] = cube[5][7]
    cube[5][7] = cube[4][8]
    cube[4][8] = cube[3][7]
    cube[3][7] = t


def r():
    global cube
    t = cube[0][5]
    cube[0][5] = cube[9][5]
    cube[9][5] = cube[6][5]
    cube[6][5] = cube[3][5]
    cube[3][5] = t
    t = cube[1][5]
    cube[1][5] = cube[10][5]
    cube[10][5] = cube[7][5]
    cube[7][5] = cube[4][5]
    cube[4][5] = t
    t = cube[2][5]
    cube[2][5] = cube[11][5]
    cube[11][5] = cube[8][5]
    cube[8][5] = cube[5][5]
    cube[5][5] = t
    t = cube[3][6]
    cube[3][6] = cube[3][8]
    cube[3][8] = cube[5][8]
    cube[5][8] = cube[5][6]
    cube[5][6] = t
    t = cube[3][7]
    cube[3][7] = cube[4][8]
    cube[4][8] = cube[5][7]
    cube[5][7] = cube[4][6]
    cube[4][6] = t


def F():
    global cube
    t = cube[3][4]
    cube[3][4] = cube[4][3]
    cube[4][3] = cube[5][4]
    cube[5][4] = cube[4][5]
    cube[4][5] = t
    b = cube[3][5]
    cube[3][5] = cube[3][3]
    cube[3][3] = cube[5][3]
    cube[5][3] = cube[5][5]
    cube[5][5] = b
    c = cube[2][4]
    cube[2][4] = cube[4][2]
    cube[4][2] = cube[6][4]
    cube[6][4] = cube[4][6]
    cube[4][6] = c
    d = cube[2][5]
    cube[2][5] = cube[3][2]
    cube[3][2] = cube[6][3]
    cube[6][3] = cube[5][6]
    cube[5][6] = d
    h = cube[2][3]
    cube[2][3] = cube[5][2]
    cube[5][2] = cube[6][5]
    cube[6][5] = cube[3][6]
    cube[3][6] = h


def f():
    global cube

    t = cube[3][4]
    cube[3][4] = cube[4][5]
    cube[4][5] = cube[5][4]
    cube[5][4] = cube[4][3]
    cube[4][3] = t
    b = cube[3][5]
    cube[3][5] = cube[5][5]
    cube[5][5] = cube[5][3]
    cube[5][3] = cube[3][3]
    cube[3][3] = b
    c = cube[2][4]
    cube[2][4] = cube[4][6]
    cube[4][6] = cube[6][4]
    cube[6][4] = cube[4][2]
    cube[4][2] = c
    d = cube[2][5]
    cube[2][5] = cube[5][6]
    cube[5][6] = cube[6][3]
    cube[6][3] = cube[3][2]
    cube[3][2] = d
    h = cube[2][3]
    cube[2][3] = cube[3][6]
    cube[3][6] = cube[6][5]
    cube[6][5] = cube[5][2]
    cube[5][2] = h


def L():
    global cube
    t = cube[0][3]
    cube[0][3] = cube[9][3]
    cube[9][3] = cube[6][3]
    cube[6][3] = cube[3][3]
    cube[3][3] = t
    c = cube[2][3]
    cube[2][3] = cube[11][3]
    cube[11][3] = cube[8][3]
    cube[8][3] = cube[5][3]
    cube[5][3] = c
    b = cube[1][3]
    cube[1][3] = cube[10][3]
    cube[10][3] = cube[7][3]
    cube[7][3] = cube[4][3]
    cube[4][3] = b
    d = cube[3][0]
    cube[3][0] = cube[5][0]
    cube[5][0] = cube[5][2]
    cube[5][2] = cube[3][2]
    cube[3][2] = d
    h = cube[3][1]
    cube[3][1] = cube[4][0]
    cube[4][0] = cube[5][1]
    cube[5][1] = cube[4][2]
    cube[4][2] = h


def l():
    global cube
    t = cube[0][3]
    cube[0][3] = cube[3][3]
    cube[3][3] = cube[6][3]
    cube[6][3] = cube[9][3]
    cube[9][3] = t
    c = cube[2][3]
    cube[2][3] = cube[5][3]
    cube[5][3] = cube[8][3]
    cube[8][3] = cube[11][3]
    cube[11][3] = c
    b = cube[1][3]
    cube[1][3] = cube[4][3]
    cube[4][3] = cube[7][3]
    cube[7][3] = cube[10][3]
    cube[10][3] = b
    d = cube[3][0]
    cube[3][0] = cube[3][2]
    cube[3][2] = cube[5][2]
    cube[5][2] = cube[5][0]
    cube[5][0] = d
    h = cube[3][1]
    cube[3][1] = cube[4][2]
    cube[4][2] = cube[5][1]
    cube[5][1] = cube[4][0]
    cube[4][0] = h


def U():
    global cube
    t = cube[3][0]
    cube[3][0] = cube[3][3]
    cube[3][3] = cube[3][6]
    cube[3][6] = cube[11][5]
    cube[11][5] = t
    c = cube[3][2]
    cube[3][2] = cube[3][5]
    cube[3][5] = cube[3][8]
    cube[3][8] = cube[11][3]
    cube[11][3] = c
    b = cube[3][1]
    cube[3][1] = cube[3][4]
    cube[3][4] = cube[3][7]
    cube[3][7] = cube[11][4]
    cube[11][4] = b
    d = cube[2][3]
    cube[2][3] = cube[2][5]
    cube[2][5] = cube[0][5]
    cube[0][5] = cube[0][3]
    cube[0][3] = d
    h = cube[2][4]
    cube[2][4] = cube[1][5]
    cube[1][5] = cube[0][4]
    cube[0][4] = cube[1][3]
    cube[1][3] = h


def u():
    global cube
    t = cube[3][0]
    cube[3][0] = cube[11][5]
    cube[11][5] = cube[3][6]
    cube[3][6] = cube[3][3]
    cube[3][3] = t
    c = cube[3][2]
    cube[3][2] = cube[11][3]
    cube[11][3] = cube[3][8]
    cube[3][8] = cube[3][5]
    cube[3][5] = c
    b = cube[3][1]
    cube[3][1] = cube[11][4]
    cube[11][4] = cube[3][7]
    cube[3][7] = cube[3][4]
    cube[3][4] = b
    d = cube[2][3]
    cube[2][3] = cube[0][3]
    cube[0][3] = cube[0][5]
    cube[0][5] = cube[2][5]
    cube[2][5] = d
    h = cube[2][4]
    cube[2][4] = cube[1][3]
    cube[1][3] = cube[0][4]
    cube[0][4] = cube[1][5]
    cube[1][5] = h


def B():
    global cube
    b = cube[0][5]
    cube[0][5] = cube[5][8]
    cube[5][8] = cube[8][3]
    cube[8][3] = cube[3][0]
    cube[3][0] = b
    c = cube[0][4]
    cube[0][4] = cube[4][8]
    cube[4][8] = cube[8][4]
    cube[8][4] = cube[4][0]
    cube[4][0] = c
    d = cube[0][3]
    cube[0][3] = cube[3][8]
    cube[3][8] = cube[8][5]
    cube[8][5] = cube[5][0]
    cube[5][0] = d
    t = cube[9][4]
    cube[9][4] = cube[10][3]
    cube[10][3] = cube[11][4]
    cube[11][4] = cube[10][5]
    cube[10][5] = t
    h = cube[9][3]
    cube[9][3] = cube[11][3]
    cube[11][3] = cube[11][5]
    cube[11][5] = cube[9][5]
    cube[9][5] = h


def b():
    global cube
    b = cube[0][5]
    cube[0][5] = cube[3][0]
    cube[3][0] = cube[8][3]
    cube[8][3] = cube[5][8]
    cube[5][8] = b
    c = cube[0][4]
    cube[0][4] = cube[4][0]
    cube[4][0] = cube[8][4]
    cube[8][4] = cube[4][8]
    cube[4][8] = c
    d = cube[0][3]
    cube[0][3] = cube[5][0]
    cube[5][0] = cube[8][5]
    cube[8][5] = cube[3][8]
    cube[3][8] = d
    t = cube[9][4]
    cube[9][4] = cube[10][5]
    cube[10][5] = cube[11][4]
    cube[11][4] = cube[10][3]
    cube[10][3] = t
    h = cube[9][3]
    cube[9][3] = cube[9][5]
    cube[9][5] = cube[11][5]
    cube[11][5] = cube[11][3]
    cube[11][3] = h


def D():
    global cube
    t = cube[5][0]
    cube[5][0] = cube[9][5]
    cube[9][5] = cube[5][6]
    cube[5][6] = cube[5][3]
    cube[5][3] = t
    c = cube[5][2]
    cube[5][2] = cube[9][3]
    cube[9][3] = cube[5][8]
    cube[5][8] = cube[5][5]
    cube[5][5] = c
    b = cube[5][1]
    cube[5][1] = cube[9][4]
    cube[9][4] = cube[5][7]
    cube[5][7] = cube[5][4]
    cube[5][4] = b
    d = cube[6][3]
    cube[6][3] = cube[8][3]
    cube[8][3] = cube[8][5]
    cube[8][5] = cube[6][5]
    cube[6][5] = d
    h = cube[6][4]
    cube[6][4] = cube[7][3]
    cube[7][3] = cube[8][4]
    cube[8][4] = cube[7][5]
    cube[7][5] = h


def d():
    global cube
    t = cube[5][0]
    cube[5][0] = cube[5][3]
    cube[5][3] = cube[5][6]
    cube[5][6] = cube[9][5]
    cube[9][5] = t
    c = cube[5][2]
    cube[5][2] = cube[5][5]
    cube[5][5] = cube[5][8]
    cube[5][8] = cube[9][3]
    cube[9][3] = c
    b = cube[5][1]
    cube[5][1] = cube[5][4]
    cube[5][4] = cube[5][7]
    cube[5][7] = cube[9][4]
    cube[9][4] = b
    d = cube[6][3]
    cube[6][3] = cube[6][5]
    cube[6][5] = cube[8][5]
    cube[8][5] = cube[8][3]
    cube[8][3] = d
    h = cube[6][4]
    cube[6][4] = cube[7][5]
    cube[7][5] = cube[8][4]
    cube[8][4] = cube[7][3]
    cube[7][3] = h


def U2():
    U()
    U()


def D2():
    D()
    D()


def F2():
    F()
    F()


def B2():
    B()
    B()


def R2():
    R()
    R()


def L2():
    L()
    L()


def M2():
    global cube

    a = cube[4][0]
    b = cube[4][1]
    c = cube[4][2]
    cube[4][0] = cube[4][6]
    cube[4][1] = cube[4][7]
    cube[4][2] = cube[4][8]
    cube[4][6] = a
    cube[4][7] = b
    cube[4][8] = c

    a = cube[4][3]
    b = cube[4][4]
    c = cube[4][5]
    cube[4][3] = cube[10][3]
    cube[4][4] = cube[10][4]
    cube[4][5] = cube[10][5]
    cube[10][3] = a
    cube[10][4] = b
    cube[10][5] = c


def DF():
    global cube
    U2()
    D2()
    M2()


def splitCube():

    global cube, back, up, down, right, left, face

    for i in range(3):
        for j in range(3, 6):
            up[i][j-3] = cube[i][j]

    for i in range(6, 9):
        for j in range(3, 6):
            down[i-6][j-3] = cube[i][j]

    for i in range(3, 6):
        for j in range(6, 9):
            right[i-3][j-6] = cube[i][j]

    for i in range(3, 6):
        for j in range(3):
            left[i-3][j] = cube[i][j]

    back[0][0] = cube[11][5]
    back[0][1] = cube[11][4]
    back[0][2] = cube[11][3]
    back[1][0] = cube[10][5]
    back[1][1] = cube[10][4]
    back[1][2] = cube[10][3]
    back[2][0] = cube[9][5]
    back[2][1] = cube[9][4]
    back[2][2] = cube[9][3]

    for i in range(3, 6):
        for j in range(3, 6):
            face[i-3][j-3] = cube[i][j]


def calulatePhaseOneId():
    global cube

    stateId = 0
    pos = 0
    splitCube()

    if(face[0][1] == 'G' or face[0][1] == 'B' or up[2][1] == 'R' or up[2][1] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(face[1][0] == 'G' or face[1][0] == 'B' or left[1][2] == 'R' or left[1][2] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(face[2][1] == 'G' or face[2][1] == 'B' or down[0][1] == 'R' or down[0][1] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(face[1][2] == 'G' or face[1][2] == 'B' or right[1][0] == 'R' or right[1][0] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(back[0][1] == 'G' or back[0][1] == 'B' or up[0][1] == 'R' or up[0][1] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(back[1][0] == 'G' or back[1][0] == 'B' or right[1][2] == 'R' or right[1][2] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(back[2][1] == 'G' or back[2][1] == 'B' or down[2][1] == 'R' or down[2][1] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(back[1][2] == 'G' or back[1][2] == 'B' or left[1][0] == 'R' or left[1][0] == 'O'):

        stateId += pow(2, pos)

    pos += 1

    if(left[0][1] == 'R' or left[0][1] == 'O' or up[1][0] == 'B' or up[1][0] == 'G'):

        stateId += pow(2, pos)

    pos += 1

    if(left[2][1] == 'R' or left[2][1] == 'O' or down[1][0] == 'B' or down[1][0] == 'G'):

        stateId += pow(2, pos)

    pos += 1

    if(right[0][1] == 'R' or right[0][1] == 'O' or up[1][2] == 'B' or up[1][2] == 'G'):

        stateId += pow(2, pos)

    pos += 1

    if(right[2][1] == 'R' or right[2][1] == 'O' or down[1][2] == 'B' or down[1][2] == 'G'):

        stateId += pow(2, pos)

    return stateId


def calulatePhaseTwoId():

    splitCube()

    ids = 0
    pos = 0

    for i in range(3):
        for j in range(3):
            if (j == 1 and i == 1):
                continue
            if (up[i][j] == 'G' or up[i][j] == 'B'):
                ids += pow(2, pos)
            pos += 1
            if (down[i][j] == 'G' or down[i][j] == 'B'):
                ids += pow(2, pos)
            pos += 1
            if (face[i][j] == 'G' or face[i][j] == 'B'):
                ids += pow(2, pos)
            pos += 1
            if (back[i][j] == 'G' or back[i][j] == 'B'):
                ids += pow(2, pos)
            pos += 1
            if (left[i][j] != 'G' and left[i][j] != 'B'):
                ids += pow(2, pos)
            pos += 1
            if (right[i][j] != 'G' and right[i][j] != 'B'):
                ids += pow(2, pos)
            pos += 1

    return ids


def calculatePhaseThreeAId():

    pos = 0
    ids = 0

    for i in range(3):
        for j in range(3):

            if (j == 1 and i == 1):
                continue

            if (up[i][j] != 'Y' and up[i][j] != 'W'):
                ids += pow(2, pos)
            pos += 1
            if (down[i][j] != 'Y' and down[i][j] != 'W'):
                ids += pow(2, pos)
            pos += 1
            if (face[i][j] != 'R' and face[i][j] != 'O'):
                ids += pow(2, pos)
            pos += 1
            if (back[i][j] != 'R' and back[i][j] != 'O'):
                ids += pow(2, pos)
            pos += 1

    return ids


def calculatePhaseThreeBId():

    pos = 0
    ids = 0

    splitCube()

    for i in range(3):
        for j in range(3):

            if i == 1 and j == 1:
                continue

            if i == 0 and j == 0:
                continue

            if (i == j) or ((i+j) == 2):

                if up[0][0] != up[i][j]:
                    ids += pow(2, pos)
                pos += 1
                if down[0][0] != down[i][j]:
                    ids += pow(2, pos)
                pos += 1
                if left[0][0] != left[i][j]:
                    ids += pow(2, pos)
                pos += 1
                if right[0][0] != right[i][j]:
                    ids += pow(2, pos)
                pos += 1
                if face[0][0] != face[i][j]:
                    ids += pow(2, pos)
                pos += 1
                if back[0][0] != back[i][j]:
                    ids += pow(2, pos)
                pos += 1

    return ids


def calculatePhaseFourId():

    ids = 0
    pos = 0

    splitCube()

    for i in range(3):
        for j in range(3):
            if (i == 1 and j == 1):
                continue
            if (up[i][j] == 'W'):
                ids += pow(2, pos)
            pos += 1
            if (down[i][j] == 'Y'):
                ids += pow(2, pos)
            pos += 1
            if (face[i][j] == 'O'):
                ids += pow(2, pos)
            pos += 1
            if (back[i][j] == 'R'):
                ids += pow(2, pos)
            pos += 1
            if (left[i][j] == 'G'):
                ids += pow(2, pos)
            pos += 1
            if (right[i][j] == 'B'):
                ids += pow(2, pos)
            pos += 1

    return ids


def solvePhase1():
    global solution, cube

    with open('Phase_1_sol.txt', 'r') as file:
        dbSolution = file.read().split('\n')

    with open('Phase_1_states.txt', 'r') as file:
        dbStates = file.read().split('\n')

    stateId = str(calulatePhaseOneId())
    index = dbStates.index(stateId)

    solution.append(dbSolution[index])

    for i in solution[-1]:
        eval(movesp1[moves.index(i)])


def solvePhase2():

    global solution, cube

    with open('Phase_2_sol.txt', 'r') as file:
        dbSolution = file.read().split('\n')

    with open('Phase_2_states.txt', 'r') as file:
        dbStates = file.read().split('\n')

    stateId = str(calulatePhaseTwoId())

    index = dbStates.index(stateId)

    solution.append(dbSolution[index])

    for i in solution[-1]:
        eval(movesp2[moves.index(i)])


def solvePhase3():

    global cube

    with open('Phase_3A_sol.txt', 'r') as file:
        dbSolution = file.read().split('\n')

    with open('Phase_3A_states.txt', 'r') as file:
        dbStates = file.read().split('\n')

    s = 0
    e = len(dbStates)-1

    splitCube()

    stateId = str(calculatePhaseThreeAId())

    index = dbStates.index(stateId)
    solution.append(dbSolution[index])

    if len(solution) == 2:
        solution.append(-1)
    else:
        for i in solution[-1]:
            eval(movesp3[moves.index(i)])

    with open('Phase_3B_sol.txt', 'r') as file:
        dbSolution = file.read().split('\n')

    with open('Phase_3B_states.txt', 'r') as file:
        dbStates = file.read().split('\n')

    s = 0
    e = len(dbStates)-1

    splitCube()

    stateId = str(calculatePhaseThreeBId())

    index = dbStates.index(stateId)
    solution.append(dbSolution[index])

    if len(solution) == 2:
        solution.append(-1)
    else:
        for i in solution[-1]:
            eval(movesp3[moves.index(i)])


def solvePhase4():

    global cube

    with open('Phase_4_sol.txt', 'r') as file:
        dbSolution = file.read().split('\n')

    with open('Phase_4_states.txt', 'r') as file:
        dbStates = file.read().split('\n')

    splitCube()

    stateId = calculatePhaseFourId()

    index = dbStates.index(str(stateId))

    solution.append(dbSolution[index])

    if len(solution) == 3:
        solution.append(-1)
    else:
        for i in solution[-1]:
            eval(movesp4[moves.index(i)])


def solveCube(shuffle=''):
    global solution

    solution = []

    for i in shuffle:
        eval(movesp1[moves.index(i)])

    solvePhase1()
    solvePhase2()
    solvePhase3()
    solvePhase4()

    solution_f = []

    for i in solution[0]:
        solution_f.append(i)

    print(solution[0], end="")

    for i in solution[1]:
        if i == 'u' or i == 'U':
            print("U2", end="")
            solution_f.append('U2')
        elif i == 'd' or i == 'D':
            print("D2", end="")
            solution_f.append('D2')
        else:
            print(i, end="")
            solution_f.append(i)

    for i in solution[2]:
        if i == 'u' or i == 'U':
            print("U2", end="")
            solution_f.append('U2')
        elif i == 'd' or i == 'D':
            print("D2", end="")
            solution_f.append('D2')
        elif i == 'f' or i == 'F':
            print("F2", end="")
            solution_f.append('F2')
        elif i == 'b' or i == 'B':
            print("B2", end="")
            solution_f.append('B2')
        else:
            print(i, end="")
            solution_f.append(i)

    for i in solution[3]:
        if i == 'u' or i == 'U':
            print("U2", end="")
            solution_f.append('U2')
        elif i == 'd' or i == 'D':
            print("D2", end="")
            solution_f.append('D2')
        elif i == 'f' or i == 'F':
            print("F2", end="")
            solution_f.append('F2')
        elif i == 'b' or i == 'B':
            print("B2", end="")
            solution_f.append('B2')
        else:
            print(i, end="")
            solution_f.append(i)

    for i in solution[4]:
        print(i+"2", end="")
        solution_f.append(i+"2")

    print()

    for i in shuffle:
        eval(movesp1[moves.index(i)])

    RCube.display_cube(cube, solution_f)


shuffle = input("ENTER SHUFFLE ALGORITHM\n")

solveCube(shuffle)
