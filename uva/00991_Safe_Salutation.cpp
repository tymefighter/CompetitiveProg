import java.util.Scanner;
import java.math.BigInteger;

class Main
{

	static void Catalan(int n)
	{
		BigInteger ans = BigInteger.valueOf(1);
		
		
		for(int i = n + 2;i <= 2*n;i++)
			ans = ans.multiply(BigInteger.valueOf(i));
		
		System.out.println(ans);
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
