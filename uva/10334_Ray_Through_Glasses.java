import java.util.Scanner;
import java.math.BigInteger;

class Main
{   
    static BigInteger[] f = new BigInteger[1001];

    static void generate_fib()
    {
        f[0] = BigInteger.valueOf(1);
        f[1] = BigInteger.valueOf(2);

        for(int i = 2;i <= 1000;i++)
            f[i] = f[i - 1].add(f[i - 2]);
    }
    public static void main(String[] args)
    {
        generate_fib();
        Scanner sc = new Scanner(System.in);
        int n;
        while(sc.hasNext())
        {
            n = sc.nextInt();
            System.out.println(f[n]);
        }
    }
}