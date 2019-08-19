import java.util.Scanner;
import java.math.BigInteger;

class Main
{

	static BigInteger Catalan(int n)
	{
		BigInteger cat = BigInteger.valueOf(1), two = BigInteger.valueOf(2);
		
		
		for(int i = 1;i <= n;i++)
			cat = (two.multiply(BigInteger.valueOf(2 * i - 1)).multiply(cat)).divide(BigInteger.valueOf(n + 1));
			
		System.out.println(cat);
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n;
		
		while(true)
		{
			n = sc.nextInt();
			if(n == 0)
				break;
			Catalan(n);
		}
	}
}
