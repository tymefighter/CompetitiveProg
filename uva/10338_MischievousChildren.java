import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    static String s;
    static BigInteger[] fact = new BigInteger[21];
    static int[] alpha = new int[26];

    static void compute()
    {
        fact[0] = fact[1] = BigInteger.valueOf(1);
        for(int i = 2;i <= 20;i++)
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
    }

    static void solve(int case_no)
    {
        for(int i = 0;i < 26;i++)
            alpha[i] = 0;
        
        for(int i = 0;i < s.length();i++)
            alpha[s.charAt(i) - 'A']++;
        
        BigInteger ans = fact[s.length()];
    
        for(int i = 0;i < 26;i++)
            ans = ans.divide(fact[alpha[i]]);
    
        System.out.printf("Data set %d: %s\n", case_no, ans.toString());
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t;
        compute();

        t = sc.nextInt();
        for(int i = 1;i <= t;i++)
        {
            s = sc.next();
            solve(i);
        }
        sc.close();
    }
}