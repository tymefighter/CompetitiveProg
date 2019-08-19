import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n, m, c = 1;

        BigInteger sum, temp;

        while(true)
        {
            n = sc.nextInt();
            m = sc.nextInt();
            if(n == 0 && m == 0)
                break;
            
            sum = BigInteger.ZERO;
            for(int i = 0;i < n;i++)
            {
                temp = sc.nextBigInteger();
                sum = sum.add(temp);
            }
            System.out.println("Bill #" + c + " costs " + sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(m)) + "\n");
            c++;
        }
    }
}