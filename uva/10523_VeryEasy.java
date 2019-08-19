import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int i, n, A;
        BigInteger sum, power;

        while(sc.hasNextInt())
        {
            n = sc.nextInt();
            A = sc.nextInt();

            sum = BigInteger.ZERO;
            power = BigInteger.valueOf(A);

            for(i = 1;i <= n;i++)
            {
                sum = sum.add(power.multiply(BigInteger.valueOf(i)));
                power = power.multiply(BigInteger.valueOf(A));
            }

            System.out.println(sum);
        }
    }
}