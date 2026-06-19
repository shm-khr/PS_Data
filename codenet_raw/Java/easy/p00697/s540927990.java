import java.util.*;
class Main{
    String[][] puzzle;
    String[][] field; 
    boolean[] used;
    void run(){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	for(int attend=0;attend<n;attend++){
	    field =new String[3][3];
	    puzzle=new String[9][4];
	    used=new boolean[9];
	    for(int i=0;i<9;i++){
		setPuzzle(i,sc.next());
	    }
	    System.out.println(dfs(0));
	}
    }
    void setPuzzle(int num,String pu){
	for(int i=0;i<4;i++){
	    puzzle[num][i]=pu.substring(i,pu.length())+pu.substring(0,i);
	}
    }
    int dfs(int step){
	if(step==9) return 1;
	int ans=0;
	for(int i=0;i<9;i++){
	    if(used[i]==true)continue;
	    for(int j=0;j<4;j++){
		if(step>2){
		    if(!puzzleCompare(field[step/3-1][step%3].charAt(2),puzzle[i][j].charAt(0)))continue;
		}
		if(step%3!=0){
		    if(!puzzleCompare(field[step/3][step%3-1].charAt(3),puzzle[i][j].charAt(1)))continue;
		}
		field[step/3][step%3]=puzzle[i][j];
		used[i]=true;
		ans+=dfs(step+1);
		used[i]=false;
	    }
	}
	return ans;
    }
    boolean puzzleCompare(char puz1,char puz2){
	if(puz1-'a'+'A'==puz2)return true;
	else if(puz2-'a'+'A'==puz1)return true;
	else return false;
    }
    public static void Main(String[] args){
	new AOJ1116().run();
    }
}