Minimum Holes
Problem Description
The cardboard container measures n × m and features internal partitions. A top-view illustration is provided, showing the internal partitions within the container. The task is to create holes in the partition walls so that each partition contains at least one hole. Determine the minimum number of holes required. An example below illustrates the standard top view of such a cardboard box with its internal divisions.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@4e9658b5:image1.png

Fig.1

An input is considered invalid if the resulting partitions are neither squares nor rectangles.

Constraints
1 < N <= 50

1 <= n, m <= 100

0 <= x, y <= 100

Each partition line will be oriented parallel to either the X-axis or the Y-axis.

Partition lines may overlap.

Input
The first line contains two space-separated integers, representing the dimensions n and m of the cardboard box.

The subsequent line provides an integer N, which specifies the number of internal partition lines within the box.

Each of the following N lines contains four space-separated integers, denoting the start and end coordinates of a partition in the format: x1 y1 x2 y2.

Output
Output a single integer representing the minimum number of holes required so that each partition contains at least one hole. If the input is invalid, display "Invalid".

Time Limit (secs)
1

Examples
Example 1

Input

5 4

5

1 0 1 3

1 2 5 2

1 1 1 4

3 1 3 4

0 1 5 1

Output

4

Explanation

The cardboard structure given in the above input is shown below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@4e9658b5:image2.png

Fig.2

The input specifies that the cardboard box has dimensions 5×4 and contains 4 partition lines. These lines divide the box into 7 separate partitions.

As illustrated in the figure below, it is possible to create four holes while ensuring that each partition contains at least one hole.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@4e9658b5:image3.png

Fig.3

Please note that this represents one potential solution that achieves the minimum number of holes.

Example 2

Input

4 8

9

1 4 1 8

0 6 4 6

1 0 1 4

1 3 4 3

2 3 2 6

3 6 3 8

3 0 3 3

1 0 1 2

3 3 3 5

Output

Invalid

Explanation

The cardboard structure given in the above input is shown below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@4e9658b5:image4.png

Fig.4

The provided partitions are deemed invalid because some are incomplete and do not conform to square or rectangular shapes.