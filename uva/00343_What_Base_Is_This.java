import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static int max(int x, int y)
    {
        if(x > y)
            return x;
        else
            return y;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String a, b;
        BigInteger x, y;
        int i, j, v1, v2;
        while(sc.hasNext())
        {
            a = sc.next();
            b = sc.next();

            v1 = -1;
            v2 = -1;

            for(i = 0;i < a.length();i++)
            {
                if(a.charAt(i) >= 'A' && a.charAt(i) <= 'Z')
                    v1 = max(v1, (int)(a.charAt(i) - 'A') + 11);
                else
                    v1 = max(v1, (int)(a.charAt(i) - '0') + 1);
            }

            for(i = 0;i < b.length();i++)
            {
                if(b.charAt(i) >= 'A' && b.charAt(i) <= 'Z')
                    v2 = max(v2, (int)(b.charAt(i) - 'A') + 11);
                else
                    v2 = max(v2, (int)(b.charAt(i) - '0') + 1);
            }


            for(i = max(v1, 2);i <= 36;i++)
            {
                x = new BigInteger(a, i);
                for(j = max(v2, 2);j <= 36;j++)
                {
                    y = new BigInteger(b, j);
                    if(x.equals(y) == true)
                    {
                        System.out.println(a + " (base " + i + ") = " + b + " (base " + j + ")");
                        break;
                    }
                }
                if(j != 37)
                    break;
            }

            if(i == 37)
                System.out.println(a + " is not equal to " + b + " in any base 2..36");
        }
    }
}