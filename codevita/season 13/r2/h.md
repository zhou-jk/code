Brick Breaker
Problem Description

Control the paddle, Master the game!

A collection of multi-colored bricks, each measuring 1x2 units (width = 1, length = 2), is provided. Each brick carries an associated point value that may be either positive or negative. The lower portion of the screen features a paddle of odd length, with a shooter positioned at its midpoint.

The game commences with the shooter launched at a 45° angle to the left. The shooter advances continuously, rebounding from both walls and bricks according to defined rules. The objective is to strike and break bricks, thereby impacting both the hit score and the paddle's length.

Brick Dependency Rules:

Bricks are considered dependent based on the following conditions.

Same color connection: Bricks of the same color which are attached horizontally or vertically are dependent on each other.
Vertical attachment: If the bricks are stacked vertically, the lower brick depends on the upper brick, even if they are of different color.
Horizontal attachment: Bricks attached horizontally are dependent only if they share the same color.
Chain Reaction: If one brick breaks, all its dependent bricks also break.
Shooter Movement and Bounce Rules:

The shooter starts at a 45° angle in left and maintains its angle unless it is redirected by collisions.
If the shooter hits a wall or brick from a cardinal direction (up, down, left, or right), its direction changes accordingly.
If the shooter hits a brick diagonally (corner hit), its path reverses.
If the shooter hits two bricks perpendicularly, its path reverses.
Special Paddle Edges:
Left Edge: Shooter bounces directly left (regardless of its original direction).
Right Edge: Shooter bounces directly right (regardless of its original direction)
Each brick hit counts as a bounce and has its special hit score.
Breaking Rules:

When the shooter hits a brick (from any side or corner), the following happens:
The targeted brick breaks.
All the dependent bricks also break.
Corner Hit condition: If the shooter hits a brick from a corner and not from a cardinal direction, the brick will break only if it lies in the shooter's path.
Bricks that fall due to disconnection are considered affected bricks. Their point values (positive or negative) contribute to the hit score.
Paddle Length Adjustment:

Paddle will have a minimum length given in the input. The maximum length paddle depends on the width of the screen.

Expansion: If the hit score becomes positive, the paddle length increases by 0 or 2 units. If the paddle is already at its maximum length, no change occurs.
Shrinking: If the hit score is negative, the paddle length decreases by 0 or2 units. If the paddle is already at its minimum length, no change occurs.
The paddle length can grow or shrink between min and max either on right or left.
If the hit score is zero, paddle length remains unchanged.
Your Task?

Given K bounces, find the maximum paddle length possible.

Constraints

20 <= R, C <= 30

M < R

0 < C

5 <= A, B <= 13

1 <= K <= 6

Input

The first line contains two integers, R and C, representing the screen's rows and columns.

The next line contains an integer M, representing the number of top rows of the screen with bricks.

Next M lines consist of C space separated characters:

Characters from 'A to Z' define the colors of the bricks.
Character '.' Defines empty space, meaning there is nothing at the spot.
Next line consists of all the color characters present above.

Next line consists of the points each color has, respectively.

Next line consists of an integer N - column number (0-based) from which the shooter is launched.

Next line consists of two space separated integers A and B - defining the current and minimum length of the paddle.

The last line contains an integer K, representing the number of bounces to be counted.

Output

A single integer specifying the maximum paddle length attained following bounces.

Time Limit (secs)

1

Examples

Example 1

Input

20 26

14

. . . . . . . B B B B B B B B B B B B . . . . . . .

. . . . . . B B . . R R R R R R . . B B . . . . . .

. . . . . B B . . R R V V V V R R . . B B . . . . .

. . . . B B . . R R V V V V V V R R . . B B . . . .

. . . B B . . R R V V V V V V V V R R . . B B . . .

. . B B . . R R V V V V V V V V V V R R . . B B . .

. B B . . R R R R R R R R R R R R R R R R . . B B .

B B B B B B B B B B B B B B B B B B B B B B B B B B

B B G G G G G G B B Y Y Y Y Y Y B B G G G G G G B B

B B G G Y Y G G B B Y Y . . Y Y B B G G Y Y G G B B

B B G G Y Y G G B B Y Y . . Y Y B B G G Y Y G G B B

B B G G Y Y G G B B Y Y . . Y Y B B G G Y Y G G B B

B B G G G G G G B B Y Y . . Y Y B B G G G G G G B B

B B B B B B B B B B Y Y . . Y Y B B B B B B B B B B

B G R V Y

10 -20 30 -40 50

5

5 5

1

Output

7

Explanation

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@27e5b378:image1.gif

GIF 1. Illustration for testcase 1

The shooter starts from column 5 (0-based) at 45° angle leftwards.

Bounce 1: When the shooter reaches the position of 5th row, 1st column, it hits the brick, and all the dependent bricks fall. Since the wall and brick are hit, the bounce will be counted, and path will be reversed. Hit score for the hit will be as follows:
19 Yellow: 19 × 50 = 950
24 Green: 24 × (-20) = -480
19 Red: 19 × 30 = 570
14 Violet: 14 × (-40) = -560
Total Hit Score = 950 - 480 + 570 - 560 = 480.

Since the hit score is greater than zero, the paddle length will increase by 2 units.

So, after 1 bounce, max paddle length achieved: 7

Example 2

Input

20 26

14

. . . . . . . B B B B B B B B B B B B . . . . . . .

. . . . . . B B . . R R R R R R . . B B . . . . . .

. . . . . B B . . R R V V V V R R . . B B . . . . .

. . . . B B . . R R V V V V V V R R . . B B . . . .

. . . B B . . R R V V V V V V V V R R . . B B . . .

. . B B . . R R V V V V V V V V V V R R . . B B . .

. B B . . R R R R R R R R R R R R R R R R . . B B .

B B B B B B B B B B B B B B B B B B B B B B B B B B

B B G G G G G G B B Y Y Y Y Y Y B B G G G G G G B B

B B G G Y Y G G B B Y Y . . Y Y B B G G Y Y G G B B

B B G G Y Y G G B B Y Y . . Y Y B B G G Y Y G G B B

B B G G Y Y G G B B Y Y . . Y Y B B G G Y Y G G B B

B B G G G G G G B B Y Y . . Y Y B B G G G G G G B B

B B B B B B B B B B Y Y . . Y Y B B B B B B B B B B

B G R V Y

10 -20 30 -40 50

15

5 5

2

Output

5

Explanation

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@27e5b378:image2.gif

GIF 2. Illustration for testcase 2

The shooter starts from column 15 (0-based) at 45° angle leftwards.

Bounce 1: When the shooter reaches the position of 5th row, 10th column, it hits the brick, no dependent bricks to fall. So, the hit score remains zero and so the paddle length. Since the brick is hit from upward direction, bounce will be counted, and shooter will change its direction.
When the shooter comes at the lowest part of the screen, the paddle is moved to capture the shooter. Shooter hits the paddle at right edge, so the angle will be changed.
Bounce 2: When the shooter reaches at the position of 10th row, 15th column, it hits the right-side brick, and all the dependent bricks fall. Since the brick is hit, bounce will be counted. Path will be changed. Hit score will be as follows:
6 Yellow: 6 × 50 = 300
24 Green: 24 × (-20) = -480
19 Red: 19 × 30 = 570
14 Violet: 14 × (-40) = -560
Total Hit Score = 300 - 480 + 570 - 560 = -170.

Since the hit score is less than zero, the paddle length should decrease by 2 units. But paddle length is already at its minimum, so no change in paddle length is done.

So, after 2 bounces, max paddle length achieved: 5.