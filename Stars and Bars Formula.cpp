///stars and bars is a formula which tells how many ways n identical things can be partitioned
///so that every partition has >= 0 no. of things in it.
///If we have n identical things, and we want to divide those into k parts, where each part
///can contain any number of that thing, the total number of ways we can do it is,
///(n+k-1) C n, where C means combination.

///Applications:
///---------------------------------------///
///1. Number of non-negative integer sums:
///we want to count the number of solution of the eqn x1 + x2 + ... + xk = n, with xi >= 0
///It is easy to see, that this is exactly the stars an bars theorem. Therefore the
///solution is (n+k-1) C n


///2. Number of lower-bound integer sums
///we want to count the number of solutions for the equation x1+x2+...+xk = n with xi >= ai.
///(each x has a lowerbound value, which is ai)
///After substituting x′i = xi−ai, we receive the modified equation
///(x′1+a1) + (x′2+a2) + ... + (x′k+ak) = n
///x′1 + x′2+ ... + x′k = n - a1 - a2 - ... - ak, with x′i ≥ 0.
///So we have reduced the problem to the simpler case with x′i ≥ 0 and again can apply the
///stars and bars theorem. because, now the revised n is n-a1-a2-...ak. and we can use this
///value to calculate (n+k-1) C n . The value of k hasn't change. So here we go.