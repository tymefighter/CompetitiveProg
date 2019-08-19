import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;

/*
    Zeckendorf's Theorem and Greedy Solution
*/

class Main
{
    static ArrayList<BigInteger> f = new ArrayList<BigInteger>(0);
    public static void generate_fib()
    {
        String str = "1";
        f.add(BigInteger.valueOf(1));
        f.add(BigInteger.valueOf(2));
        int i;

        for(i = 0;i < 100;i++)
            str += "0";

        i = 2;
        BigInteger x = f.get(i - 1).add(f.get(i - 2));
        BigInteger limit = new BigInteger(str);

        while(x.compareTo(limit) <= 0)
        {
            f.add(x);
            i++;
            x = f.get(i - 1).add(f.get(i - 2));
        }
    }

    public static BigInteger convert(String s)
    {
        BigInteger x = BigInteger.ZERO;
        for(int i = 0;i < s.length();i++)
        {
            if(s.charAt(s.length() - i - 1) == '1')
                x = x.add(f.get(i));
        }

        return x;
    }

    public static String convert_back(BigInteger x)
    {
        int i = 0;
        String s = "";

        while(i < f.size() && f.get(i).compareTo(x) <= 0)
            i++;

        i--;
        while(i >= 0)
        {
            if(f.get(i).compareTo(x) <= 0)
            {
                x = x.subtract(f.get(i));
                s += '1';
            }
            else
            {
                s += '0';
            }
            i--;
        }

        if(s.length() == 0)
            s += '0';

        return s;
    }

    public static void solve(String a, String b)
    {
        BigInteger x = convert(a), y = convert(b);
        System.out.println(convert_back(x.add(y)));
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        generate_fib();
        String a, b;
        int ct = 0;

        while(sc.hasNext())
        {
            if(ct != 0)
                System.out.println("");
            a = sc.next();
            b = sc.next();
            solve(a, b);
            ct += 1;
        }
    }
}