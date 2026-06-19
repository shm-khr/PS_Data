import java.util.Scanner;

public class Main {
	static String ban[];
	static int ban2[];
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		ban = sc.next().split("");
		ban2= new int[ban.length];

		int sum = 0;
		boolean flag = true;
		int left = 1;
		int right = ban.length-2;
		while(flag){
			/*for(int i = 0;i < ban.length;i++){
				System.out.print(ban2[i] + " ");
			}*/
			//System.out.println();
			String color = handan(0);
			for(int i = left;left < ban.length;left++){
				//System.out.println(left);
				if(!color.equals(handan(left))){
					sum++;
					for(int j = 0;j < left;j++){
						ban2[j]++;
					}
					break;
				}
				if(left == ban.length-1){
					flag = false;
				}
			}
		}
		System.out.println(sum);

	}

	static String handan(int a){
		if(ban2[a]%2 == 0){
			return ban[a];
		}else{
			if(ban[a].equals("B")){
				return "W";
			}else{
				return "B";
			}
		}
	}
}