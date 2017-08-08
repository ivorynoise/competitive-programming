import java.util.*;
import java.io.*;
public class uva11723_deepak {
	public static void main(String[] args) {
		//TODO TLE : Slow Input and Output
		int nstreets, nNumbers;
		// Scanner s = new Scanner(System.in);
		FastReader s = new FastReader();
		nstreets = s.nextInt();
		nNumbers = s.nextInt();
		int c = 0;
		while (nstreets != 0 && nNumbers != 0) {
			nstreets -= nNumbers;
			int nAlpha = (int)Math.ceil((double)nstreets / nNumbers);

			System.out.printf("Case %d: ", ++c);

			if (nAlpha > 26) System.out.println("impossible");
			else System.out.println(nAlpha);

			nstreets = s.nextInt();
			nNumbers = s.nextInt();
		}
	}
}
