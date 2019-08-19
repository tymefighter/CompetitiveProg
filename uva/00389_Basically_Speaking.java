import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String a;
        int b1, b2;
        BigInteger val;

        while(sc.hasNext())
        {
            a = sc.next();
            b1 = sc.nextInt();
            b2 = sc.nextInt();

            val = new BigInteger(a, b1);
            a = val.toString(b2);
            if(a.length() > 7)
                a = "ERROR";
            
            a = String.format("%7s", a);
            System.out.println(a.toUpperCase());
        }
    }
}