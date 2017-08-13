import java.util.*;
import java.io.*;
import java.math.*;	//for BigInteger
class Main {
	// public static void main(){
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		int c = 0;
		BigInteger sum = BigInteger.ZERO;

		while(true){
			++c;
			int n = s.nextInt();
			int f = s.nextInt();
			if (n == 0 && f == 0) break;
			sum = BigInteger.ZERO;
			while(n-- > 0){
				sum = sum.add(s.nextBigInteger());
			}
			// Bill #1 costs 16200000000: each friend should pay 540000000
			System.out.printf("Bill #%d costs %s: each friend should pay %s\n\n", 
				c, sum.toString(), sum.divide(BigInteger.valueOf(f)));
		}
	}
	
	static class FastReader {
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