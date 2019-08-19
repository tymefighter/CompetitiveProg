import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    static int n;
    static int[] a = new int[10];
    static void solve()
    {
        int i;
        BigInteger fact = BigInteger.valueOf(1);
        for(i = 2;i <= n;i++)
            fact = fact.multiply(BigInteger.valueOf(i));

        for(i = 0;i < 10;i++)
            a[i] = 0;
        String s = fact.toString();

        for(i = 0;i < s.length();i++)
            a[s.charAt(i) - '0']++;
        
        for(i = 0;i < 10;i++)
        {
            if(i % 5 != 0)
                System.out.print("    ");
            else
            System.out.print("   ");
            s = String.format("(%d)%5d", i, a[i]);
            System.out.print(s);
            if(i == 4)
                System.out.println("");
        }
        System.out.println("");
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s;

        while(sc.hasNext())
        {
            n = sc.nextInt();
            if(n == 0)
                break;
            s = String.format("%d! --", n);
            System.out.println(s);
            solve();
        }
        sc.close();
    }
}