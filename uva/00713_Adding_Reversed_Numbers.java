import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static BigInteger reverse(BigInteger x)
    {
        BigInteger val = BigInteger.ZERO, ten = BigInteger.valueOf(10);


        while(x != BigInteger.ZERO)
        {
            val = (val.multiply(ten)).add(x.remainder(ten));
            x = x.divide(ten);
        }

        return val;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t;
        BigInteger a, b, ans;
        
        t = sc.nextInt();

        for(int i = 0;i < t;i++)
        {
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            a = reverse(a);
            b = reverse(b);

            ans = a.add(b);
            ans = reverse(ans);
            System.out.println(ans);
        }
    }
}