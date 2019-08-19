import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger p, a;

        while(sc.hasNext())
        {
            p = sc.nextBigInteger();
            a = sc.nextBigInteger();
            if(p.equals(BigInteger.ZERO) && a.equals(BigInteger.ZERO))
                break;
            
            if((p.isProbablePrime(10) == false) && (a.modPow(p, p).equals(a) == true))
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}