import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int x, y;
        String a;
        BigInteger n;

        while(sc.hasNext())
        {
            x = sc.nextInt();
            n = BigInteger.valueOf(x);
            if(n.isProbablePrime(10) == false)
            {
                System.out.println(x + " is not prime.");
                continue;
            }
            y = Integer.parseInt(new StringBuffer(n.toString()).reverse().toString());

            if(x == y)
            {
                System.out.println(x + " is prime.");
                continue;
            }

            n = BigInteger.valueOf(y);

            if(n.isProbablePrime(10))
                System.out.println(x + " is emirp.");
            else
                System.out.println(x + " is prime.");
        }
    }
}