import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        BigInteger a, b, gcd_val;

        for(int i = 0;i < t;i++)
        {
            a = sc.nextBigInteger();
            sc.skip(" / ");
            b = sc.nextBigInteger();

            gcd_val = a.gcd(b);
            a = a.divide(gcd_val);
            b = b.divide(gcd_val);

            System.out.println(a + " / " + b);
        }
    }
}