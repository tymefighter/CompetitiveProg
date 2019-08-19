import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    static BigInteger[][] c = new BigInteger[55][55];

    static void get_values(int n)
    {
        int i, j;
        for(i = 0;i <= n;i++)
            c[i][0] = BigInteger.valueOf(1);
        for(j = 1;j <= n;j++)
            c[0][j] = BigInteger.ZERO;

        for(i = 1;i <= n;i++)
        {
            for(j = 1;j <= n;j++)
                c[i][j] = c[i - 1][j - 1].add(c[i - 1][j]);
        }
    }

    static void print_ans(String s1, String s2, int n, int c_no)
    {
        int i;
        
        System.out.print("Case " + c_no + ": ");

        for(i = 0;i <= n;i++)
        {
            if(i != 0)
                System.out.print("+");
            if(i != 0 && i != n)
                System.out.print(c[n][i] + "*");
            
            if(i != n)
            {
                System.out.print(s1);
                if(i != n - 1)
                    System.out.print("^" + (n - i));
            }

            if(i != 0 && i != n)
                System.out.print("*");

            if(i != 0)
            {
                System.out.print(s2);
                if(i != 1)
                    System.out.print("^" + i);
            }
        }
        
        System.out.println("");
    }

    public static void main(String[] args)
    {
        int t, n;
        Scanner sc = new Scanner(System.in);
        String inp, s1, s2;
        
        t = sc.nextInt();

        for(int i = 0;i < t;i++)
        {
            inp = sc.next();
            n = Integer.parseInt(inp.split("\\^")[1]);
            get_values(n);

            inp = inp.split("\\^")[0];
            String[] arr = inp.split("\\+");
            s1 = arr[0].substring(1);
            s2 = arr[1].substring(0, arr[1].length() - 1);

            print_ans(s1, s2, n, i+1);
        }

        sc.close();
    }
}
