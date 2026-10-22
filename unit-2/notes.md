# steps for convex hull

1. sort the points
2. divide the points by left half and right half
3. leftHalf=convex(leftHalf)
   rightHalf=convex(rightHalf)
4. return merge(leftHalf, rightHalf)
