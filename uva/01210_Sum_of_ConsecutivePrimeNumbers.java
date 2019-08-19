import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;

class Main
{
    static ArrayList<Integer> a = new ArrayList<Integer>(0);
    public static void generate()
    {
        BigInteger val;
        int i;
        a.add(0);
        for(i = 2;i <= 10000;i++)
        {
            val = BigInteger.valueOf(i);
            if(val.isProbablePrime(10))
                a.add(i);
        }

        for(i = 2;i < a.size();i++)
            a.set(i, a.get(i) + a.get(i - 1));
    }

    public static int get_val(int n)
    {
        int ans = 0, i, j;

        for(i = 0;i < a.size();i++)
        {
            for(j = i + 1;j < a.size();j++)
            {
                if(a.get(j) - a.get(i) > n)
                    break;
                if(a.get(j) - a.get(i) == n)
                    ans += 1;
            }
        }

        return ans;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        generate();
        int n;

        while(sc.hasNextInt())
        {
            n = sc.nextInt();
            if(n == 0)
                break;
            System.out.println(get_val(n));
        }
    }
}