
import java.util.Scanner;

public class booths 
{
	public static void main(String[] args) 
	{
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the first number");
		int m1 = scn.nextInt(); 
		System.out.println("Enter the second number");
		int m2 = scn.nextInt(); 


		String m = getbinary(m1);
		System.out.println(m1 + ", the multiplicand in signed 2s complement notation is " + m);

		String r = getbinary(m2);
		System.out.println(m2 + ", the multiplier in signed 2s complement notation is " + r);
		int x = m.length();
		int y = r.length();
		System.out.println("-------------------------------------------------------------------------");

		if (m1 * m2 > 32767 || m1 * m2 < -32768) 
		{
			System.out.println("Product is out of range for a 16-bit register!!");
			return;
		}
		
		String A = m;
		for (int i = 0; i <= y; i++) 
		{
			A = A + "0";
		}

		System.out.println("The initial value of A is " + A);

		String S = get2scomplement(m.substring(1));

		if (m1 <= 0) 
		{
			S = "0" + S;
		} 
		else 
		{
			S = "1" + S;
		}

		for (int i = 0; i <= y; i++) 
		{
			S = S + "0";
		}
		System.out.println("The initial value of S is " + S);

		String P = "";
		for (int i = 0; i < x; i++) 
		{
			P += "0";
		}
		P = P + r + "0";
		System.out.println("The initial value of P is " + P);
		System.out.println("-------------------------------------------------------------------------");
		for (int i = 1; i <= y; i++) 
		{

			if (P.substring(P.length() - 2).equals("01")) 
			{
				P = binaryaddn(P, A);
				P = shiftright(P);
				System.out.println("The value of P after P + A operation and right shift is " + P + " when i is " + i);

			}

			else if (P.substring(P.length() - 2).equals("10")) 
			{
				P = binaryaddn(P, S);
				P = shiftright(P);
				System.out.println("The value of P after P + S operation and right shift is " + P + " when i is " + i);
			}

			else 
			{
				P = shiftright(P);
				System.out.println("The value of P after right shift is " + P + " when i is " + i);
			}
		}

		P = P.substring(0, P.length() - 1);
		System.out.println("-------------------------------------------------------------------------");

		System.out.println("The product of the numbers entered in binary is " + P);
		if (P.charAt(0) == '0') 
		{
			System.out.print("It's Decimal Equivalent is ");
			int i;
			for (i = 0; i < P.length(); i++) 
			{
				if (P.charAt(i) == '0') 
				{      
					continue;
				}
				break;
			}
			if (i == P.length()) 
			{ 
				System.out.print("0");		
				return;
			}
			binarytodec(P.substring(i));  
		}

		if (P.charAt(0) == '1') 
		{
			System.out.print("MSB = 1 indicates that the given number is negative."
					+ " It's magnitude is given by the magnitude of it's 2's complement, that is ");
			binarytodec(get2scomplement(P));
		}

	}

	public static String get2scomplement(String s1) 
	{
		String s2 = "";
		for (int i = 0; i < s1.length(); i++) 
		{ 
			if (s1.charAt(i) == '0') 
			{
				s2 += '1';
				continue;
			}
			s2 += '0';
		}

		String s3 = "";
		String carry = "1";
		for (int i = s2.length() - 1; i >= 0; i--) 
		{
			if (s2.charAt(s2.length() - 1) == '0') 
			{
				s2 = s2.substring(0, s2.length() - 1) + "1";
				return s2;
			}

			if (s2.charAt(i) == '1' && carry.equals("1")) 
			{
				s3 = '0' + s3;
				carry = "1";
			} 
			else if (s2.charAt(i) == '0' && carry.equals("1")) 
			{
				s3 = '1' + s3;
				carry = "0";
			} 
			else if (s2.charAt(i) == '0' && carry.equals("0")) 
			{
				s3 = '0' + s3;
				carry = "0";
			} 
			else 
			{
				s3 = '1' + s3;
				carry = "0";
			}
		}

		return s3;
	}

	public static String getbinary(int n) 
	{
		String str1 = "";
		if (n >= 0) 
		{
			str1 = Integer.toBinaryString(n);
			str1 = "0" + str1;
		} 
		else 
		{
			str1 = Integer.toBinaryString(-1 * n);
			str1 = get2scomplement(str1);
			str1 = "1" + str1;
		}
		return str1;
	}

	public static String shiftright(String str) 
	{
		return str.charAt(0) + str.substring(0, str.length() - 1);
	}

	public static String binaryaddn(String s1, String s2) 
	{
		String res = "";
		String carry = "0";
		for (int i = s1.length() - 1; i >= 0; i--) 
		{
			if (s1.charAt(i) == '1' && s2.charAt(i) == '1' && carry.equals("0")
					|| (s1.charAt(i) == '0' && s2.charAt(i) == '1' && carry.equals("1"))
					|| s1.charAt(i) == '1' && s2.charAt(i) == '0' && carry.equals("1")) 
			{
				res = '0' + res;
				carry = "1";
			} 
			else if (s1.charAt(i) == '1' && s2.charAt(i) == '1' && carry.equals("1")) 
			{
				res = '1' + res;
				carry = "1";
			} 
			else if (s1.charAt(i) == '0' && s2.charAt(i) == '1' && carry.equals("0")
					|| s1.charAt(i) == '1' && s2.charAt(i) == '0' && carry.equals("0")
					|| s1.charAt(i) == '0' && s2.charAt(i) == '0' && carry.equals("1")) 
			{
				res = '1' + res;
				carry = "0";
			} 
			else if (s1.charAt(i) == '0' && s2.charAt(i) == '0' && carry.equals("0")) 
			{
				res = '0' + res;
				carry = "0";
			}
		}
		return res;
	}

	public static void binarytodec(String s) 
	{
		Long n = Long.parseLong(s);
		Long rem = (long) 0;
		Long ans = (long) 0;
		Long val = (long) 1;

		while (n != 0) 
		{
			rem = n % 10;
			ans = ans + rem * val;
			n = n / 10;
			val = val * 2;
		}
		System.out.println(ans);
	}
}