
import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String s = r.readLine();
		System.out.println(solve(s));
	}

	public int solve(String s) {
		int result = 0;
		for (int j = 1; j < s.length(); j++)
			if (s.charAt(j) != s.charAt(j - 1))
				result++;
		return result;
	}

}

