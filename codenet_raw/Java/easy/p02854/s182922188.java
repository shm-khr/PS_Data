import java.util.Scanner;

public class Main{
public static void main(String[] args){
Scanner scan=new Scanner(System.in);
int num=scan.nextInt();
int[] size=new int[num];
int[] coor=new int[num];

int i=0;
for(i=0;i<num;i++){
    size[i]=scan.nextInt();
}
coor[0]=size[0];
i=1;
for(i=1;i<num;i++){
    coor[i]=coor[i-1]+size[i];
}


if(coor[num-1]%2==0){
    int near=coor[num-1]/2;
    i=0;
    for(i=0;i<num;i++){
        if(near>Math.abs(coor[i]-coor[num-1]/2)){
            near=Math.abs(coor[i]-coor[num-1]/2);
        }else{
            break;
        }
    }
    System.out.println(near*2);
}
if(coor[num-1]%2==1){
    double nearr=((double)coor[num-1])/2;
    i=0;
    for(i=0;i<num;i++){
        if(nearr>Math.abs(((double)coor[i])-((double)coor[num-1])/2)){
            nearr=Math.abs(((double)coor[i])-((double)coor[num-1])/2);
        }else{
            break;
        }
    }
    System.out.println((int)(nearr*2));
}


}
}