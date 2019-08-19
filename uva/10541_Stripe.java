import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    static BigInteger[][] c = new BigInteger[1001][1001];

    static BigInteger choose(int n, int k)
    {
        int i, j;
        for(i = 0;i <= n;i++)
            c[i][0] = BigInteger.valueOf(1);
        for(j = 1;j <= k;j++)
            c[0][j] = BigInteger.ZERO;

        for(i = 1;i <= n;i++)
        {
            for(j = 1;j <= k;j++)
                c[i][j] = c[i - 1][j - 1].add(c[i - 1][j]);
        }

        return c[n][k];
    }

    public static void main(String[] args)
    {
        int t, n, k, i, j, sum, x;
        Scanner sc = new Scanner(System.in);

        t = sc.nextInt();
        for(i = 0;i < t;i++)
        {
            n = sc.nextInt();
            k = sc.nextInt();
            sum = 0;
            for(j = 0;j < k;j++)
            {
                x = sc.nextInt();
                sum += x;
            }

            System.out.println(choose(n + 1 - sum, k));
        }
    }
}