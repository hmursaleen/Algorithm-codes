Binomial coefficients have many different properties. Here are the simplest of them:

Symmetry rule: NcK = Nc(N - K)

***Factoring in: NcK = (N/K) * ((N-1)c(K-1)) ***

Sum over k: Sum of all NcK for 0 <= K <= N, equals 2^N;

***Sum over n: Sum of all McK for 0 <= M <= N, equals (N+1)c(K+1) ***

Sum over n and k: Sum of all (N+K)cK, for 0 <= K <= M, equals (N+M+1)cM;

Sum of the squares: Sum of all (NcK)^2 for 0 <= K <= N, equals (2N)cN

Weighted sum: Sum of all K*(NcK), for 1 <= K <= N, equals N * 2^(N+1);

Connection with the Fibonacci numbers: Sum of all (N-K)cK, for 0 <= K <= N, equals = Fn+1;


***Calculation of NcR :

int NcR(int n, int r)
{
    double res = 1;
    for(int i = 1; i <= k; i++)
    {
        res *= res * (n-k+i) / i;
    }
    return (int) (res + 0.01);
}


***Pascal's Triangle :

const int M = ...;
int NcR[M][M];
NcR[0][0] = 1;
for(int n = 1; n <= M; n++)
{
    NcR[N][0] = NcR[N][N] = 1;
    for(int r = 1; r < N; r++)
    {
        NcR[n][r] = NcR[n-1][r-1] + NcR[n-1][r];
    }
}
