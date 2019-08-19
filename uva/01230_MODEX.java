import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger x, y, n;
        int c = sc.nextInt();

        for(int i = 0;i < c;i++)
        {
            x = sc.nextBigInteger();
            y = sc.nextBigInteger();
            n = sc.nextBigInteger();

            System.out.println(x.modPow(y, n));
        }

        c = sc.nextInt();
    }
}