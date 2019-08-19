import java.util.Scanner;
import java.math.BigDecimal;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        String a;
        BigDecimal sum, x;

        for(int i = 0;i < t;i++)
        {
            sum = BigDecimal.ZERO;
            while(sc.hasNext())
            {
                a = sc.next();
                if(a.equals("0"))
                    break;
                
                x = new BigDecimal(a);
                sum = sum.add(x);
            }
            System.out.println(sum.stripTrailingZeros().toPlainString());
        }
        
    }
}