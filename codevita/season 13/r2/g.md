Fun With Clock
Problem Description
Deva recently learned about angles in his mathematics class and is eager to explore them further! He began learning about angles using a wall clock.

He chose an ancient wall clock for his learning. This clock has only two hands: the hour hand and the minute hand. The hour hand moves to the next hour only after the minute hand completes a full rotation, staying at the current hour until then. The task is to form a given angle between the two hands of the clock. The rules for forming the angle are as follows -

Starting from the given position, you can move both hands, but in opposite directions without crossing each other. For example, if you move the hour hand clockwise, you must move the minute hand counterclockwise, and vice versa.
The hour hand can only be moved from one hour to the next or previous hour; it cannot be positioned between the hours. However, there are no such restrictions for the minute hand.
Moving a hand clockwise incurs cost of A rupees while moving in counterclockwise direction costs B rupees for each degree.
Moving the hour hand costs P rupees per degree for the first 90 degrees (inclusive), and then it costs Q rupees per degree for any movement beyond 90 degrees.
Similarly, moving the minute hand costs X rupees per degree for the first 90 degrees (inclusive), and then it costs Y rupees per degree for any movement beyond 90 degrees.
You can create the specified angle in any direction, whether as an internal or external angle.
For example, if the time is 12:15 and you need to form an angle of 300 degrees, you can achieve this by moving the minute hand 30 degrees in anti-clock wise direction (i.e., from the 3 to the 2), if the resulting cost is low, as shown in Figure 2 below.
com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image1.png


Fig. 1

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image2.png

Fig. 2

Given the initial time, an integer N representing the number of queries, and the values of A, B, P, Q, X and Y as defined above, you will be provided with an angle in each query that you need to form between the hands of the clock. For each query, determine the minimum cost required to form the specified angle and print the total minimum cost as the output.

Note: The queries should be processed sequentially remaining the same clock position obtained in previous query.

Constraints
0 <= Angle <= 360 degrees

1 <= A, B, P, Q, X, Y <= 10

A, B, P, Q, X and Y are unique.

1 <= N <=20

Input
The first line contains the initial time in the format hours:minutes.

The second line contains an integer N, representing the number of queries.

The third line contains two space separated integers A, B.

The fourth line contains two space separated integers P, Q.

The fifth line contains two space separated integers X, Y.

The next N lines each contain a single integer, representing the angle that you need to form between the hands of the clock.

Output
A single integer representing the total minimum cost for processing all queries.

Time Limit (secs)
1

Examples
Example 1

Input

2:35

5

10 12

4 6

5 1

200

160

60

130

360

Output

13960

Explanation

The initial time is 2:35, resembling the image below on the clock.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image3.png

There are 5 queries to be processed. Cost of A, B, P, Q, X and Y is 10, 12, 4, 6, 5 and 1, respectively.

The first query asks to form an angle of 200 degrees between the two hands. For this, we can set up the hands like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image4.png

Let the hours-hand remain in same position and move the minutes-hand 10 degrees in clockwise direction. This will incur a cost of

=> 10-degrees movement in clockwise direction * Minute-hand movement less than 90 degrees * cost of movement of minute-hand per degree

=> 10 * 10 * 5 = 500 Rupees.

Next query asks to form 160-degree angle between the two hands which is already present as shown below. Thus, we need not make any changes in this query. Hence no cost incurred.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image5.png

Third query is to form 60 degrees between the two hands. For this, we can set up the hands like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image6.png

Move the hours hand 90 degrees in clockwise direction and move the minutes hand 10 degrees in anticlockwise direction. This will incur a cost of 90 * 10 * 4 (90-degree rotation for hour hand in clockwise direction * cost per degree) + 10 * 12 * 5 (10-degree rotation for minute hand in anticlockwise direction * cost per degree) = 4200 rupees.

Fourth query is to form 130 degrees between the two hands. For this, we can set up the hands like below.

Rotate the hour hand 60 degrees in anticlockwise direction and rotate the minutes hand 10 degrees in clockwise direction which will incur a cost of 60 * 12 * 4 + 10 * 10 * 5 = 3380 rupees, after performing similar computations as explained above.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image7.png

Last query is to form 360 degrees between the two hands. For this, we can set up the hands like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image8.png

Let the hour hand remain in the same position and rotate the minutes hand 130 degrees in the anticlockwise direction which will incur us a cost of 12 * 90 * 5 + 12 * 40 * 1 = 5880 rupees.

Note that the two hands overlapped in the above figure.

Hence the total cost incurred is 500 + 0 + 4200 + 3380 + 5880 = 13960 rupees, which is the minimum possible.

Example 2

Input

8:25

2

6 3

1 2

4 7

68

0

Output

900

Explanation

The initial time is 8:25, resembling the image below on the clock.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image9.png

The first query is to form 68 degrees between the two hands. For this, we can set up the hands like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image10.png

Remain the hour hand in the same position and move the minutes hand 22 degrees in clockwise direction. This will incur a cost of 6 * 22 * 4 = 528 rupees.

Next query is to form 0 degrees between both the hands. For this, we can set up the hands like below.

Rotate the hour hand 60 degrees in the anti clock wise direction and minutes hand 8 degrees in the clock wise direction. This will incur a cost of 60 * 3 * 1 + 8 * 6 * 4 = 372 rupees.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c20aab9:image11.png

Note that the two hands overlapped in the above figure.

Hence the total cost incurred is 528 + 372 = 900 rupees, which is the minimum possible.