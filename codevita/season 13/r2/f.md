InterStellar
Problem Description
The universe is vast and full of secrets, but today you are tasked with simulating a cosmic chase.

In a distant galaxy, planets orbit around one another in square orbits. Each planet (except the central one) orbits its master planet in a perfect path. They move/orbit around one cell at a time.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@54e81b21:image1.png

Fig 1

The planet that gets orbited is called primary body and the planet that is orbiting is called secondary body. Primary and secondary bodies are relational. Every planet will get orbited by a planet and itself orbit another planet, except the central one. Fig 1 shows a planet A and a Planet B which orbits A. Radius of the orbit is 3 (Both the cells of primary and secondary body is counted). This will be mentioned in the input as

B A 3

i.e.,

Secondary Primary Radius

Each secondary body is related to its primary body. The planets can co-locate at the same cells without affecting.

Assume you are traveling from one planet to another. Where your spaceship can move in four cardinal directions and it can co-locate with another planet. Your spaceship's speed is also one cell per time.

You will be given details of the planets. Assume initial position of every secondary body is to right side and horizontally on same row of primary body at T = 0 as shown in Fig 1. They start orbiting their primary body at speed of 1 cell per unit time.

Your Spaceship is stationed at Orbit of Source planet and you are allowed to takeoff to your destination at anytime.

Given the planets you are traveling between, you must find the earliest time when you can reach the destination planet.

Constraints
0 <= Earliest time Required <= 50

2 <= Total of planets <= 20

Input
First line contains an Integer N.

Next N lines contain three space separated characters representing the orbiting details as mentioned in Problem Description.

Last line contains two characters, space separated representing the source and destination planet.

Output
Single integer representing the earliest time you can reach the destination planet.

Time Limit (secs)
1

Examples
Example 1

Input

2

B A 3

C A 5

B C

Output

5

Explanation

From the input we can see planet B is at radius 3 and planet C is at radius 5 and both are orbiting A which is represented in Fig.2.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@54e81b21:image2.png

Fig. 2

We need to reach planet C from planet B.

Figure 2 illustrates the orbital motion. Initially, both B and C are positioned horizontally to the right of their respective master planets, at their given radii. B₀ and C₀ represent the starting positions of B and C in their orbits.

Their orbits are traced up to 5 units of time. At time T = 2, planet B is in cell B₂, and planet C is also in cell C₂. Suppose you begin your journey (using a spaceship) from position B₂. At time T = 3, you reach cell S₃ while planet C is at C₃. At T = 4, you are at S₄ and C is at C₄. Finally, at T = 5, both you and planet C arrive at C₅. Therefore, 5 is the earliest time at which you can reach the destination planet.

Example 2

Input

2

B A 5

C B 3

A C

Output

6

Explanation

From the input we can see planet B is at radius 5 and is orbiting planet A while planet C is at radius 3 and is orbiting planet B which is represented in Fig.3.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@54e81b21:image3.png

Fig. 3

Your goal is to travel from A to C. In this scenario, planet C is in a relational orbit around planet B, i.e., C revolves around B, and B itself is also revolving around A. Therefore, the position of planet C at any time depends on the position of planet B.

Their orbits are traced up to 6 units of time. Starting from planet A at time T = 0, you can move vertically upward for 5 steps in 5 units of time, reaching cell S₅ as shown in Fig. 3. At time T = 6, planet C also arrives at cell C₆, which is the same cell you reach. Therefore, the earliest time required to reach the destination planet is 6.