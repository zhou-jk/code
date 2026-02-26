Wall Shooter
Problem Description

WallShooter: The Ultimate Bouncer Challenge!

Get Ready to Master the Paddle!

In WallShooter, you control a paddle at the bottom of the screen, your mission is to keep a bouncing ball in play and rack up as many points as possible!

Here's How It Works:

Starting Point: The paddle begins in the centre of the screen with length N. The ball launches from the middle of your paddle at a 45-degree angle, angled counterclockwise.
Bouncing Bonanza: The ball bounces off the top, left, and right walls, each bounce adding to your score.
Paddle Power: When the ball returns downward, you must position your paddle to catch it! The ball bounces off the paddle, continuing its journey (but catching it doesn't count towards your score).
Game Over: If the ball drops past your paddle and touches the bottom of the screen, you lose!
Special Note: The corners of the paddle behave differently:

Right Edge: If the ball hits the right edge, it bounces directly to the right (regardless of its original direction).

Left Edge: If the ball hits the left edge, it bounces directly to the left (regardless of its original direction).

Your Challenge:
You're given a target number of K bounces. Your mission is to minimize the maximum distance your paddle needs to travel in order to reflect the ball and keep it from hitting the bottom before reaching K bounces. Return the maximum distance the paddle will need to move at once to avoid losing the game before achieving K bounces.

Constraints

2 <= K <= 20

2 <= N <= 8 (N will always be an even integer)

0 <= x1, y1, x2, y2 <= 25

Input

First line consists of an integer K - number of bounces required before losing the game.

Second line consists of two space-separated integers (x, y coordinate) of the middle point of the paddle from where the ball is supposed to be shot.

Third line consists of an integer N - length of the paddle.

Last line contains four space-separated integers - x1, y1, x2, y2, where (x1, y1) is the bottom-left coordinate of the screen and (x2, y2) is the top-right coordinate of the screen.

Output

Single integer denoting the minimized maximum of all units travelled by the paddle to bounce the ball.

Time Limit (secs)

1

Examples

Example 1

Input

2

2 0

2

0 0 6 5

Output

0

Explanation

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7da77305:image1.gif

The ball is shot from the coordinate (2,0) at 45° angle anticlockwise. Since, before two bounces are encountered, paddle is not shifted, the distance travelled by the paddle is 0 units. Hence the answer.

Example 2

Input

5

2 0

2

0 0 6 5

Output

1

Explanation

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7da77305:image2.gif

The ball is shot from the middle of the paddle from coordinate (2,0). We can see that, before the 5 bounces are encountered, the ball comes in the downward direction because of which the paddle is shifted by 1 unit distance. Since the ball reflects from the paddle, it will not be counted as a 'bounce'.

Example 3

Input

3

3 1

2

1 1 9 6

Output

5

Explanation

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7da77305:image3.gif

The ball is shooted from the coordinate (3,1). Since the ball encounters the corner of the screen, the ball will follow the same path backwards after reflecting back from the paddle. Distance travelled by the paddle: 5 units.

*Note: GIFs added in the explanation are for illustration purpose only. The GIFs are explained till the purpose is acquired.