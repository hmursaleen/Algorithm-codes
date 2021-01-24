

    Divisor sum property
    This interesting property was established by Gauss:
    ***∑d|nϕ(d)=n
    Here the sum is over all positive divisors d of n.
    For instance the divisors of 10 are 1, 2, 5 and 10. Hence ϕ(1)+ϕ(2)+ϕ(5)+ϕ(10)=1+1+4+4=10.int main ()


    ***Finding the totient from 1 to n using the divisor sum property
    The divisor sum property also allows us to compute the totient of all numbers between 1 and n. This implementation is a little simpler than the previous implementation based on the Sieve of Eratosthenes, however also has a slightly worse complexity: O(nlogn)

    void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}



    ***Euler totient function from 1 to n in O(nloglogn)
If we need all all the totient of all numbers between 1 and n, then factorizing all n numbers is not efficient. We can use the same idea as the Sieve of Eratosthenes. It is still based on the property shown above, but instead of updating the temporary result for each prime factor for each number, we find all prime numbers and for each one update the temporary results of all numbers that are divisible by that prime number.

Since this approach is basically identical to the Sieve of Eratosthenes, the complexity will also be the same: O(nloglogn)
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

    ***The most famous and important property of Eulers totient function is expressed in Euler's theorem:
a^ϕ(m) ≡ 1(mod m), where a and m are co-prime.


    ***if p is prime, then phi(p) = p - 1;

    ***if p is prime and k >= 1 then, there are exactly
    (p^k / p) numbers between 1 and p^k that are divisible
    by p. which gives us,
    phi(p^k) = p^k - p^(k - 1);

    ***if a and b are relatively prime then,
    phi(ab) = phi(a) * phi(b);

    ***if a and b are not co-prime, then
    phi(ab) = phi(a) * phi(b) * (d / phi(d)) where d = gcd(a,b)

    ***normally, phi(n) = n * (1-(1/p1)) * (1-(1/p2))... * (1-(1/pk))

    ***sum of lcm(i, n) for 1 <= i <= n, is ∑LCM(i, n) = ((∑(d * ETF(d)) + 1) * n) / 2


    ***Sum of Co-prime Numbers of an Integer n : (n * phi(n)) / 2;

    ***Sum of gcd(i, n) for 1 <= i <= n is
    {
        product of (Ai+1)*Pi^(Ai) - Ai*Pi^(Ai-1)
        for 0 <= i <= k, where k = num of prime divisor of n,
        Pi = ith prime divisor, Ai = power of ith prime divisor
    }
