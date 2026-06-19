package javaapplication1;
import java.util.Scanner;
class JavaApplication1 {


public static void main(String args[]) {
Scanner s=new Scanner(System.in);
long ans,max;
int i,j,a[][];
int t=s.nextInt();
a=new int[t][2];
for(j=0;j<2;j++)
{for(i=0;i<t;i++)
a[i][j]=s.nextInt();
}
ans=a[0][0];
for(i=0;i<t;i++) ans=ans+a[i][1];
max=ans;
for(i=1;i<t;i++)
{
    ans=ans-a[i-1][1]+a[i][0];
    if(ans>max) max=ans;
}
System.out.println(max);
}
}