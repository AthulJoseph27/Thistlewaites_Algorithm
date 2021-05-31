import os
import sys
import time

cube = []


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


def display_cube(a, sol):
    import pygame

    global cube

    cube = [rows[:] for rows in a]

    pygame.font.init()

    moves = ['R', 'L', 'F', 'B', 'U', 'D', 'r', 'l', 'f',
             'b', 'u', 'd', 'R2', 'L2', 'F2', 'B2', 'U2', 'D2']
    movesq = ['R()', 'L()', 'F()', 'B()', 'U()', 'D()', 'r()', 'l()', 'f()',
              'b()', 'u()', 'd()', 'R2()', 'L2()', 'F2()', 'B2()', 'U2()', 'D2()']

    clock = pygame.time.Clock()
    STAT_FONT = pygame.font.SysFont("comicsans", 30)
    gameExit = False

    try:
        pygame.quit()
    finally:
        gameDisplay = pygame.display.set_mode((500, 500))
        pygame.display.set_caption("Cube")
    while not gameExit:
        clock.tick(3)

        nxt_x = 150
        nxt_y = 10

        if len(sol) != 0:
            if sol[0] != ' ':
                eval(movesq[moves.index(sol[0])])
            sol.pop(0)
        a = [rows[:] for rows in cube]
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                gameExit = True
        if gameExit:
            break

        # pygame.draw.rect(gameDisplay,(173,216,230),[nxt_x,nxt_y,30,30])
        gameDisplay.fill((0, 0, 0))

        for i in range(0, 3):

            for j in range(3, 6):

                if a[i][j] == 'B':
                    pygame.draw.rect(gameDisplay, (70, 216, 255), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'R':
                    pygame.draw.rect(gameDisplay, (225, 0, 0),
                                     [nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'G':
                    pygame.draw.rect(gameDisplay, (0, 255, 0),
                                     [nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'Y':
                    pygame.draw.rect(gameDisplay, (255, 255, 0), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'W':
                    pygame.draw.rect(gameDisplay, (255, 255, 255), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'O':
                    pygame.draw.rect(gameDisplay, (255, 165, 0), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
            nxt_y += 40
            nxt_x = 150

        nxt_x = 30
        for i in range(3, 6):

            for j in range(0, 9):

                if a[i][j] == 'B':
                    pygame.draw.rect(gameDisplay, (70, 216, 255), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'R':
                    pygame.draw.rect(gameDisplay, (225, 0, 0),
                                     [nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'G':
                    pygame.draw.rect(gameDisplay, (0, 255, 0),
                                     [nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'Y':
                    pygame.draw.rect(gameDisplay, (255, 255, 0), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'W':
                    pygame.draw.rect(gameDisplay, (255, 255, 255), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'O':
                    pygame.draw.rect(gameDisplay, (255, 165, 0), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40

            nxt_y += 40
            nxt_x = 30

        nxt_x = 150

        for i in range(6, 12):

            for j in range(3, 6):

                if a[i][j] == 'B':
                    pygame.draw.rect(gameDisplay, (70, 216, 255), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'R':
                    pygame.draw.rect(gameDisplay, (225, 0, 0),
                                     [nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'G':
                    pygame.draw.rect(gameDisplay, (0, 255, 0),
                                     [nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'Y':
                    pygame.draw.rect(gameDisplay, (255, 255, 0), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'W':
                    pygame.draw.rect(gameDisplay, (255, 255, 255), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
                elif a[i][j] == 'O':
                    pygame.draw.rect(gameDisplay, (255, 165, 0), [
                                     nxt_x, nxt_y, 30, 30])
                    nxt_x += 40
            nxt_y += 40
            nxt_x = 150

        pygame.display.update()
