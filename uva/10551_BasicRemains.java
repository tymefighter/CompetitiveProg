import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int b;
        BigInteger p, m;

        while(sc.hasNext())
        {
            b = sc.nextInt();
            if(b == 0)
                break;
            
            p = new BigInteger(sc.next(), b);
            m = new BigInteger(sc.next(), b);
            System.out.println((p.mod(m)).toString(b));
        }
    }
}