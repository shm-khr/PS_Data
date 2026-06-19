	public static void main(String[] args) {
		int A = Integer.parseInt(args[0]);
		int B = Integer.parseInt(args[1]);
		int C = Integer.parseInt(args[2]);
		
		if((A==5&&B==5) && (C==7)){
			System.out.println("YES");
		}
		
		else if((A==5&&C==5) &&(B==7)){
			System.out.println("YES");
		}
		
		else if((B==5&&C==5) && (A==7)){
			System.out.println("YES");
		}
		
		else {
			System.out.println("NO");
		}
		

	}