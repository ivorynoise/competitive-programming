
import java.util.*;
import java.io.*;
class Main {
	// public static void main(){
	public static void main(String args[]){
		FastReader s = new FastReader();
		int n = s.nextInt();
		int c = 0;
		while(n-- > 0){
			int x = s.nextInt();
			int i = x / 2 + 1;
			int cur, ans = 0;
			for(int j = 0; j < x; ++j){
				cur = s.nextInt();
				--i;
				if (i == 0) ans = cur;
			}
			System.out.printf("Case %d: %d\n", ++c, ans);
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