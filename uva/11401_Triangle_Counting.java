import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    static BigInteger[] ans = new BigInteger[1000001];
    static void solve(int n)
    {
        ans[3] = BigInteger.ZERO;
        BigInteger val = BigInteger.ZERO;
        int x = 0;

        for(int i = 1;i <= n - 3;i++)
        {
            if(i % 2 == 1)
                x += 1;
            val = val.add(BigInteger.valueOf(x));
            ans[i + 3] = ans[i + 2].add(val);
        }
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n;

        solve(1000000);

        while(sc.hasNext())
        {
            n = sc.nextInt();
            if(n < 3)
                break;
            System.out.println(ans[n]);
        }

        sc.close();
    }
}