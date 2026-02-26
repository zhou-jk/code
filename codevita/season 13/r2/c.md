2D Jenga
Problem Description
Welcome to the Virtual 2D Floating Jenga Challenge. In this contest, you will interact with a digital version of Jenga, where blocks are arranged in a floating 2D matrix. Your objective is to extract a designated Jenga piece from the arrangement, incurring the minimum possible cost.

The Jenga arrangement is presented as a 2D matrix, with each piece represented by a unique integer. Some pieces may extend across multiple neighboring cells. You may extract pieces from any of the four sides: left, right, top, or bottom. The cost of extracting a piece is equal to its integer value. After extraction, unsupported pieces will be affected by gravity and may need to be removed as well, incurring additional costs. Your goal is to determine the most cost-effective side from which to extract the target piece.

Constraints
1 <= N, M <= 50

1 <= number representing Jenga piece <= 500

A piece will remain stationary as long as it is supported by at least one cell on the bottom. Otherwise, it will be subject to gravity and will fall.

Certain pieces may be completely enclosed by others. In order to remove those located within, it is necessary to first remove the surrounding outer pieces, and vice versa.

It is guaranteed that for each arrangement, only one side will result in the minimum cost.

Input
The first line contains two space-separated integers, N and M, representing the number of rows and columns in the Jenga matrix.

The next N lines describe the Jenga arrangement.

The final line contains a single integer indicating the target Jenga piece to be extracted.

Output
Print the output in the below format.

<Cost> via <Side> where the sides can be {down, up, left, right}

Time Limit (secs)
1

Examples
Example 1

Input

6 5

18 18 19 13 13

15 12 23 13 13

15 12 14 8 10

5 11 11 8 9

5 6 6 7 7

1 1 2 3 4

14

Output

20 via down

Explanation

The given target jenga piece is 14 and you can see that it is present in only one cell. According to the rules outlined, before removing the target piece, any blocking pieces must be removed.

If we choose to remove the piece from the right side, we must take out {13, 10, 8, 9}, resulting in a total cost of 40. Note that piece 13 also needs to be removed because once 8, 9, and 10 are taken out, 13 will fall due to gravity and block the target piece.
If we choose the left side, we must remove {15, 12, 18}, resulting in a cost of 45.
If we choose the top side, we will need to remove {23, 19}, with a cost of 42.
If we choose the bottom side, we will have to remove {11, 6, 1, 2}, which incurs the lowest cost of 20.
Therefore, the optimal choice is to choose the down side, with a cost of 20.

Example 2

Input

6 7

9 9 1 1 1 1 1

7 9 1 2 3 1 1

7 9 1 4 4 1 1

5 5 1 1 1 1 8

11 6 6 6 6 1 8

11 0 0 0 0 1 10

1

Output

9 via up

Explanation

The given target jenga piece is 1 and you can see that it is spanning multiple adjacent cells. According to the rules outlined, before removing the target piece, any blocking pieces must be removed.

If we choose the right side, we need to remove {8, 4, 2, 3, 10}, which will incur a cost of 27.
If we choose the left side, we must remove {0, 11, 9, 7, 5, 6, 4, 3, 2}, resulting in a cost of 47.
If we choose the top side, we will need to remove {4, 2, 3}, with a cost of 9.
If we choose the bottom side, we will have to remove {8, 10, 6, 4, 3, 2}, with cost of 33.
Therefore, the optimal choice is to choose the up side, with a cost of 9.