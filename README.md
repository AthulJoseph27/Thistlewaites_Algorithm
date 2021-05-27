# Thistlewaite's Algorithm

- Algorithm to solve Rubik's Cube.

- It consists of 4 Phases , in my implementation , it can take upto 58 moves to solve the Rubik's Cube.

- In Phase 1 , we fix all the bad edges. After this the cube can be solved without using the moves U and D. A edge is good if it can be taken to its orginal position without using U or D moves, else it is bad.

- In Phase 2, we place all the Blue and Green facelets on either left or right face. To make things easier, we can consider both Blue and Green faclets as Green.(The cube is held in such a way that, front is Red, left is Blue , top is Yellow, back is Orange, right is Green and bottom is White ). Once this is done, we can solve this state without U,D,F,B moves.

- Phase 3 is split into 2 parts - 3A and 3B

- My implementation of Phase 3 is different from the Thistlewaite's algorithm, mainly becuase i didn't understand what he meant in his paper 😅.

- In Phase 3A, we place all colors either on its corresponding face or its oppossite face, i.e we bring the cube into a state such that all red and orange facelets are either in front or back face, all blue and green facelets are in left or right face, and all yellow and white facelets are in top or bottom.

- In Phase 3B, we try to bring the cube into a state in which all the corners of the same color can be brought back to the same face with only double moves, i.e there can be only even number of coners of the same color in one face and if the front face corners and back face corners are superimpossed, then same color can have only 0 or 2 overlaps. You can try this yourself, just take a solved Rubik's Cube and shuffle it with only moves in Group 4. Once this state is acheived, the cube can be solved using just double moves. Some example for invalid states are :
  ![alt text](assets/1.png)
  ![alt text](assets/2.png)

- Refer https://www.jaapsch.net/puzzles/thistle.htm for more infomation.

- In Phase 4, we try to bring each facelets to their repective faces.

| Phase             | 1     | 2         | 3A      | 3B  | 4           |
| ----------------- | ----- | --------- | ------- | --- | ----------- |
| Max Moves         | 7     | 11        | 11      | 14  | 15          |
| No of States      | 2,048 | 1,082,565 | 4,900   | 144 | 663,552     |
| Moves Not Allowed | \_    | U,D       | U,D,F,B | 144 | R,L,U,D,F,B |

![alt text](assets/RC.gif)
