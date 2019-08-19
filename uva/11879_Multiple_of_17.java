import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger a, st;
        st = BigInteger.valueOf(17);

        while(true)
        {
            a = sc.nextBigInteger();
            if(a.equals(BigInteger.ZERO))  
                break;
            if(a.remainder(st) == BigInteger.ZERO)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}