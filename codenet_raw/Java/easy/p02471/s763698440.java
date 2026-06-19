import java.io.InputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;

public class Main{

static PrintWriter out;
static InputReader ir;

static void solve(){
 int a=ir.nextInt();
 int b=ir.nextInt();
 long[] g=extendedgcd(a,b);
 int p=(int)g[2]/a;
 int q=(int)g[2]/b;
 while(Math.abs(g[0])+Math.abs(g[1])>Math.abs(g[0]-p)+Math.abs(g[1]+q)||(Math.abs(g[0])+Math.abs(g[1])==Math.abs(g[0]-p)+Math.abs(g[1]+q)&&g[0]-p<=g[1]+q)){
  g[0]-=p;
  g[1]+=q;
 }
 while(Math.abs(g[0])+Math.abs(g[1])>Math.abs(g[0]+p)+Math.abs(g[1]-q)||(Math.abs(g[0])+Math.abs(g[1])==Math.abs(g[0]+p)+Math.abs(g[1]-q)&&g[0]+p<=g[1]-q)){
  g[0]+=p;
  g[1]-=q;
 }
 out.println(g[0]+" "+g[1]);
}

public static long[] extendedgcd(long a,long b){
 long[] ret=new long[3];
 ret[2]=_extendedgcd(a,b,ret);
 return ret;
}

public static long _extendedgcd(long a,long b,long[] x){
 long g=a;
 x[0]=1;
 x[1]=0;
 if(b!=0){
  g=_extendedgcd(b,a%b,x);
  long temp=x[0]; x[0]=x[1]; x[1]=temp;
  x[1]-=(a/b)*x[0];
 }
 return g;
}

public static void main(String[] args) throws Exception{
 ir=new InputReader(System.in);
 out=new PrintWriter(System.out);
 solve();
 out.flush();
}

static class InputReader {
 private InputStream in;
 private byte[] buffer=new byte[1024];
 private int curbuf;
 private int lenbuf;

 public InputReader(InputStream in) {this.in=in; this.curbuf=this.lenbuf=0;}
 
 public boolean hasNextByte() {
  if(curbuf>=lenbuf){
   curbuf= 0;
   try{
    lenbuf=in.read(buffer);
   }catch(IOException e) {
    throw new InputMismatchException();
   }
   if(lenbuf<=0) return false;
  }
  return true;
 }

 private int readByte(){if(hasNextByte()) return buffer[curbuf++]; else return -1;}
 
 private boolean isSpaceChar(int c){return !(c>=33&&c<=126);}
 
 private void skip(){while(hasNextByte()&&isSpaceChar(buffer[curbuf])) curbuf++;}
 
 public boolean hasNext(){skip(); return hasNextByte();}
 
 public String next(){
  if(!hasNext()) throw new NoSuchElementException();
  StringBuilder sb=new StringBuilder();
  int b=readByte();
  while(!isSpaceChar(b)){
   sb.appendCodePoint(b);
   b=readByte();
  }
  return sb.toString();
 }
 
 public int nextInt() {
  if(!hasNext()) throw new NoSuchElementException();
  int c=readByte();
  while (isSpaceChar(c)) c=readByte();
  boolean minus=false;
  if (c=='-') {
   minus=true;
   c=readByte();
  }
  int res=0;
  do{
   if(c<'0'||c>'9') throw new InputMismatchException();
   res=res*10+c-'0';
   c=readByte();
  }while(!isSpaceChar(c));
  return (minus)?-res:res;
 }
 
 public long nextLong() {
  if(!hasNext()) throw new NoSuchElementException();
  int c=readByte();
  while (isSpaceChar(c)) c=readByte();
  boolean minus=false;
  if (c=='-') {
   minus=true;
   c=readByte();
  }
  long res = 0;
  do{
   if(c<'0'||c>'9') throw new InputMismatchException();
   res=res*10+c-'0';
   c=readByte();
  }while(!isSpaceChar(c));
  return (minus)?-res:res;
 }

 public double nextDouble(){return Double.parseDouble(next());}

 public BigInteger nextBigInteger(){return new BigInteger(next());}

 public int[] nextIntArray(int n){
  int[] a=new int[n];
  for(int i=0;i<n;i++) a[i]=nextInt();
  return a;
 }

 public long[] nextLongArray(int n){
  long[] a=new long[n];
  for(int i=0;i<n;i++) a[i]=nextLong();
  return a;
 }

 public char[][] nextCharMap(int n,int m){
  char[][] map=new char[n][m];
  for(int i=0;i<n;i++) map[i]=next().toCharArray();
  return map;
 }
}
}