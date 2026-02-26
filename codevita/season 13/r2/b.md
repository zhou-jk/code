Ascii Homes
Problem Description
You are required to develop a program that generates and displays several ASCII art houses with different sizes and orientations, ensuring they are aligned neatly side by side along a common base level.

Each house is represented using ASCII characters /, \, @, &, and #.
The house consists of a roof (formed by slashes) and walls (formed by @ and & representing the left and right walls), ending with a base (#).
The input consists of multiple specifications in the form <length>x<height><direction>, where:
          length -> width of the house

          height -> height of the walls

          direction -> orientation of the house (H,U, D, L, or R)

Depending on the direction:
          H -> No tilting, visualize the house as it is

          U -> Tilt the house upwards

          D -> Tilt the house downwards

          L -> Tilt left (mirror reflection along the left)

          R -> Tilt right (mirror reflection along the right)

All houses are padded and aligned such that their bases lie on the same level, appearing seamlessly side by side without any gaps between the houses.
A 2x4 home looks like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image1.png

Fig.1

A 4x6 home looks like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image2.png

Fig.2

Constraints
1 <= number of houses <= 100

2 <= length, height <= 100

direction ∈ {U, D, L, R, H}

Input
A single line containing one or more space-separated house specifications in the format defined above.

Output
Print the resulting multi-line ASCII art houses next to each other.

You may refer to Example section for better understanding.

Time Limit (secs)
1

Examples
Example 1

Input

6x3U 4x2U 8x4L 2x2H

Output

/\

/ \

###### / \

@ & / \

@ &####& @

\ /@ && @/\

\ / \ /& @@&

\/ \/ ##########

Explanation

The output is shown in the below diagram.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image3.png

Fig.3

The first two houses, sized 6x3 and 4x2, are tilted upward; the third house, sized 8x4, is tilted to the left; and the fourth house, sized 2x2, is displayed in its original orientation.

Example 2

Input

4x6R 12x8H 2x6D

Output

/\

/ \

/ \

/ \

/ \

/ \

/\ @ &

/ \@ &##

& @@ &@&

& @@ &@&

& @@ &@&

& @@ &@&

& @@ &@&

################\/

Explanation

The output is shown in the diagram below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image4.png

Fig.4

The first house, sized 4x6, is tilted to the right; the second house, sized 12x8, is displayed in its normal upright position; and the third house, sized 2x6, is tilted downward.