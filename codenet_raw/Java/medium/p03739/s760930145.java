import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int n = scan.nextInt();

	int[] a_ = new int[n];
	for(int i = 0; i < n; i++){
	    a_[i] = scan.nextInt();
	}

	int count = 0;
	int[] sum_ = new int[n];
	//i % 2 == 1 : sum_[i] <= -1
	if(a_[0] > 0){
	    sum_[0] = a_[0];
	    for(int i = 1; i < n;){
		sum_[i] = sum_[i-1] + a_[i];
		if(i % 2 != 0){
		    if(sum_[i] < 0){
			//OK
			i++;
		    }else{
			if(sum_[i-1] > 1){
			    sum_[i-1]--;			   
			}else{
			    a_[i]--;
			}
			count++;
		    }
		}else{
		    if(sum_[i] > 0){
			//OK
			i++;
		    }else{
			if(sum_[i-1] < -1){
			    sum_[i-1]++;			    
			}else{
			    a_[i]++;
			}
			count++;
		    }
		}if(count == 10)break;
	    }
	}else{
	    sum_[0] = a_[0];
	    for(int i = 1; i < n;){
		sum_[i] = sum_[i-1] + a_[i];
		if(i % 2 != 0){
		    if(sum_[i] > 0){
			//OK
			i++;
		    }else{
			if(sum_[i-1] < -1){
			    sum_[i-1]++;
			}else{
			    a_[i]++;
			}
			count++;
		    }
		}else{
		    if(sum_[i] < 0){
			//OK
			i++;
		    }else{
			if(sum_[i-1] > 1){
			    sum_[i-1]--;
			}else{
			    a_[i]--;
			}
			count++;
		    }
		}
	    }
	}

	System.out.println(count);
    }
}
