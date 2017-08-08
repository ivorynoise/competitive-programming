import java.util.*;
import java.io.*;
class INTEST_deepak{
	static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

	public static void main(String args[]){
		FastReader s = new FastReader();
		// Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int t = s.nextInt();
		int x;
		int c = 0;
		while(n-- > 0){
			x  = s.nextInt();
			if (x % t == 0) ++c;
		}

		System.out.printf("%d", c);
	}
}