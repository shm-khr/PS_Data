
import java.util.*;
  
public class Main {
    Scanner sc = new Scanner(System.in);
  
    public static void main(String[] args) {
        new Main(); 
    }
  
    public Main() {
        new aoj1116().doIt();
    }
    class aoj1116{
    	int result = 0;
    	char map[][] = new char [9][4];
    	boolean check[] = new boolean[9];
    	int t_map[][] = new int [3][3];
    	int alf[] = new int[256];
//    	int cnt = 0;
    	// 0 1 2
		// 3 4 5
		// 6 7 8
    	void rotate(int num){
//    		if(num == 0){
//    			for(int i = 0;i < 4;i++){
//    				System.out.print(map[num][i]);
//    			}
//    			System.out.println();
//    		}
    		char c = map[num][0];
    		for(int i = 0;i < 3;i++){
    			map[num][i] = map[num][i+1];
    		}
    		map[num][3] = c; 
    	}
    	void dfs(int num){
//    		cnt++;
//    		System.out.println(num);
    		if(num == 9)result++;
    		else{
    			for(int i = 0;i < 9;i++){
    				if(check[i])continue;
    				check[i] = true;
    				t_map[num/3][num%3] = i;
    				for(int j = 0;j < 4;j++){
    					if(num / 3 > 0 && num % 3 > 0){
    						if(alf[map[t_map[num/3][num%3]][1]] == -alf[map[t_map[num/3][(num%3)-1]][3]]
    								&& alf[map[t_map[num/3][num%3]][0]] == -alf[map[t_map[(num/3)-1][num%3]][2]])dfs(num+1);
    					}else if(num / 3 > 0){
    						if(alf[map[t_map[num/3][num%3]][0]] == -alf[map[t_map[(num/3)-1][num%3]][2]])dfs(num+1);
    					}else if(num % 3 > 0){
    						if(alf[map[t_map[num/3][num%3]][1]] == -alf[map[t_map[num/3][(num%3)-1]][3]])dfs(num+1);
    					}else{
    						dfs(num+1);
    					}
    					rotate(i);
    				}
    				check[i] = false;
    			}
    		}
    	}
    	void doIt(){
    		alf['r'] = 1;alf['g'] = 2; alf['b'] = 3;alf['w'] = 4;
    		alf['R'] = -1;alf['G'] = -2; alf['B'] = -3;alf['W'] = -4;
    		int n = sc.nextInt();
    		for(int i = 0;i < n;i++){
    			for(int j = 0;j < 9;j++){
    				String str = sc.next();
    				char ctr[] = str.toCharArray();
    				for(int k = 0;k < 4;k++){
    					map[j][k] = ctr[k];
    				}
    			}
    			result = 0;
    			dfs(0);
    			System.out.println(result);
//    			System.out.println(cnt);
    		}
    	}
    }
}