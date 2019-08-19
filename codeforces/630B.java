import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;

class Main
{
    static BigDecimal x = new BigDecimal("1.000000011");

    static BigDecimal pow(long n)
    {
        if(n == 0)
            return BigDecimal.ONE;

        if(n % 2 == 1)
        {
            BigDecimal val = pow(n - 1);
            val = val.multiply(x).setScale(20, RoundingMode.FLOOR);
            return val;
        }
        else
        {
            BigDecimal val = pow(n / 2);
            val = val.multiply(val).setScale(20, RoundingMode.FLOOR);
            return val;
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        BigDecimal n;
        long t;

        n = new BigDecimal(sc.next());
        t = sc.nextLong();

        BigDecimal ans = n.multiply(pow(t)).setScale(10, RoundingMode.FLOOR);
        System.out.println(ans);
    }
}