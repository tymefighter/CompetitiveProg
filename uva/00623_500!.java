import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    static int n;

    static void solve()
    {
        BigInteger ans = BigInteger.valueOf(1);

        for(int i = 2;i <= n;i++)
            ans = ans.multiply(BigInteger.valueOf(i));
        System.out.printf("%d!\n", n);
        System.out.println(ans);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext())
        {
            n = sc.nextInt();
            solve();
        }
        sc.close();
    }
}