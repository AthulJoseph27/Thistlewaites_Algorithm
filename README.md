# Thistlewaite's Algorithm

<p>
<image src="assets/Cube2.png" height="500"/>  
</p>

**Left - Blue, Front - Red, Right - Green, Back - Orange, Up - Yellow, Down - White**

- Algorithm to solve Rubik's Cube.

- It consists of 4 Phases , in my implementation , it can take upto 58 moves to solve the Rubik's Cube.

- In Phase 1 , all the bad edges are fixed. A edge is good if it can be taken to its orginal position without using U or D moves, else it is bad. After this the cube can be solved without using the moves U and D.

- In Phase 2, place all the blue and green facelets on either left or right face. To make things easier, consider both blue and green faclets as a single color, say blue. Once this is done, we can solve this state without U,D,F,B moves.

- Phase 3 is split into 2 parts - 3A and 3B

- My implementation of Phase 3 is different from the Thistlewaite's algorithm, mainly becuase i didn't understand what he meant in his paper 😅.

- In Phase 3A, place all colors either on its corresponding face or its oppossite face, i.e we bring the cube into a state such that all red and orange facelets are either in front or back face, all blue and green facelets are in left or right face, and all yellow and white facelets are in top or bottom. In other words, consider red and orange facelets as red, blue and green facelets as blue, and yellow and white facelets as yellow and then solve the cube.

- In Phase 3B, the cube is brought into a state in which all the corners of the same color can be brought back to the same face with only double moves, i.e there can be only even number of coners of the same color in one face and on super superimposing any face and its oppossite face, corners of the same color can have only 0 or 2 overlaps. You can try this yourself, just take a solved Rubik's Cube and shuffle it with only moves in Group 4. Once this state is acheived, the cube can be solved using just double moves. Some example for invalid states are :
  <p>
  <image src="assets/1n.png" height="150"/>  
  <image src="assets/2n.png" height="150"/> 
  </p>

- In Phase 4, solve the cube by bringing every corners and edges to its actual place by using only 180-degree turns.

- Refer https://www.jaapsch.net/puzzles/thistle.htm for more infomation.

| Phase           | 1     | 2         | 3A      | 3B      | 4           |
| --------------- | ----- | --------- | ------- | ------- | ----------- |
| Max Moves       | 7     | 11        | 11      | 14      | 15          |
| No.of States    | 2,048 | 1,082,565 | 4,900   | 144     | 663,552     |
| Forbidden Moves | \_    | U,D       | U,D,F,B | U,D,F,B | R,L,U,D,F,B |

<br>
</br>

# How to Run this

- The Lookup table is already generated and can be found under the folder Lookup Table.

- The code used to generate these lookup tables can be found under the folder named Generators.

  ## Python

  - Copy the files Solve.py and RCube.py under the folder Tester and paste it inside the Lookup Table folder.

  - You will need python 3 to run this.

  - To install the required modules, run `pip3 install -r requirements.txt`

  - Now run `python3 Solve.py` and input the shuffle. Thats it!

  ## C++

  - Copy the files Solve.cpp under the folder Tester and paste it inside the Lookup Table folder.

  - compile the code with `g++ Solve.cpp`.

  - Now run `./a.out` and input the shuffle. Thats it!

  <p>
  <image src="assets/Solve.gif" height="500"/>
  </p>
