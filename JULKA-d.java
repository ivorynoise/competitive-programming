import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	// public static void main(){
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		for(int i = 0; i < 10; ++i){
			BigInteger sum = s.nextBigInteger();
			BigInteger excess = s.nextBigInteger();
			BigInteger h = sum.subtract(excess).divide(BigInteger.valueOf(2));
			System.out.println(h.add(excess));
			System.out.println(h);
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
