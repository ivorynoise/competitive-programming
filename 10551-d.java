import java.util.*;
import java.io.*;
import java.math.BigInteger;

//Given 2 strings p and m in base b return p % m in base b

class Main {
	public static void main(String args[]){
		int b;
		BigInteger p, m;
		String num, div, ans;
		Scanner s = new Scanner(System.in);

		while(true){
			b = s.nextInt();
			if (b == 0) break;

			p = new BigInteger(s.next(), b);	//converted to base 10
			m = new BigInteger(s.next(), b);
			ans = p.mod(m).toString(b);
			System.out.println(ans);
		}

	}
	
	static class FastReader {
	// static class FastReader extends Scanner{
	// INFO : final classes cant be extended

		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new
			                        InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException  e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}