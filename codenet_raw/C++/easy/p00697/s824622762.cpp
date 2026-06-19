#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<bitset>
#include<cmath>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<28)

using namespace std;

struct Puzzle
{
  char t,r,b,l;
  Puzzle(char t='$',char r='$',char b='$',char l='$'):t(t),r(r),b(b),l(l){}

  void rotate90()
  {
    char tmp = t;
    t = l;
    l = b;
    b = r;
    r = tmp;
  }

};

Puzzle puzzle[9];
Puzzle p2[9];
int cnt;
int dx[] = {0,1,0,-1};//下、右、上、左
int dy[] = {1,0,-1,0};

void print()
{
  rep(i,3)
    {
      rep(j,3)
	{
	  cout << "(" << puzzle[i*3+j].t << "," << puzzle[i*3+j].r << ","  << puzzle[i*3+j].b << "," << puzzle[i*3+j].l<< ") ";
	}
      cout << endl;
    }
  cout << endl;
}

bool match(char a,char b)
{
  if(a == 'R' && b == 'r')return true;
  if(a == 'G' && b == 'g')return true;
  if(a == 'B' && b == 'b')return true;
  if(a == 'W' && b == 'w')return true;
  if(a == 'w' && b == 'W')return true;
  if(a == 'b' && b == 'B')return true;
  if(a == 'g' && b == 'G')return true;
  if(a == 'r' && b == 'R')return true;
    return false;
}

bool check()
{
  rep(y,3)
    {
      rep(x,3)
	{
	  rep(k,4)
	    {
	      int nx = x + dx[k];
	      int ny = y + dy[k];
	      if(!(0 <= nx && nx < 3 && 0 <= ny && ny < 3))continue;
	      if(k == 0)
		{
		  if(!match(puzzle[ny*3+nx].t,puzzle[y*3+x].b))return false;
		}
	      if(k == 1)
		{
		  if(!match(puzzle[ny*3+nx].l,puzzle[y*3+x].r))return false;
		}
	      if(k == 2)
		{
		  if(!match(puzzle[ny*3+nx].b,puzzle[y*3+x].t))return false;
		}
	      if(k == 3)
		{
		  if(!match(puzzle[ny*3+nx].r,puzzle[y*3+x].l))return false;
		}
	    }
	}
    }
  return true;
}

void dfs(int p)
{
  if(p >= 9)
    {
      //print();
      if(check())cnt++;
      return;
    }
  int x = p%3;
  int y = p/3;
  rep(i,4)
    {
      bool ok = true;
      rep(j,4)
	{
	  int nx = x + dx[j];
	  int ny = y + dy[j];
	  if(!(0 <= nx && nx < 3 && 0 <= ny && ny < 3))continue;
	  if(nx+ny*3 > p)continue;
	  if(j == 0)
	    {
	      if(!match(puzzle[ny*3+nx].t,puzzle[y*3+x].b))
		{
		  ok = false;
		  break;
		}
	    }
	  if(j == 1)
	    {
	      if(!match(puzzle[ny*3+nx].l,puzzle[y*3+x].r))
		{
		  ok = false;
		  break;
		}
	    }
	  if(j == 2)
	    {
	      if(!match(puzzle[ny*3+nx].b,puzzle[y*3+x].t))
		{
		  ok = false;
		  break;
		}
	    }
	  if(j == 3)
	    {
	      if(!match(puzzle[ny*3+nx].r,puzzle[y*3+x].l))
		{
		  ok = false;
		  break;
		}
	    }
	}
      if(!ok)
	{
	  puzzle[p].rotate90();
	  continue;
	}
      dfs(p+1);
      puzzle[p].rotate90();
    }
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    {
      cnt = 0;
      rep(i,3)
	{
	  rep(j,3)
	    {
	      string s;
	      cin >> s;
	      p2[i*3+j].t = s[0];
	      p2[i*3+j].r = s[1];
	      p2[i*3+j].b = s[2];	      
	      p2[i*3+j].l = s[3];	      
	    }
	}

      //dfs(0);
      int bit = 0;
      int r = 0;
      rep(_1,9)
	{
	  bit = (1<<_1);
	  puzzle[0] = p2[_1];
	  rep(_2,9)
	    {
	      if((bit>>_2) & 1)continue;
	      bit |= (1<<_2);
	      puzzle[1] = p2[_2];
	      rep(_3,9)
		{
		  if((bit>>_3) & 1)continue;
		  bit |= (1<<_3);
		  puzzle[2] = p2[_3];
		  rep(_4,9)
		    {
		      if((bit>>_4) & 1)continue;
		      bit |= (1<<_4);
		      puzzle[3] = p2[_4];
		      rep(_5,9)
			{
			  if((bit>>_5) & 1)continue;
			  bit |= (1<<_5);
			  puzzle[4] = p2[_5];
			  rep(_6,9)
			    {
			      if((bit>>_6) & 1)continue;
			      bit |= (1<<_6);
			      puzzle[5] = p2[_6];
			      rep(_7,9)
				{
				  if((bit>>_7) & 1)continue;
				  bit |= (1<<_7);
				  puzzle[6] = p2[_7];
				  rep(_8,9)
				    {
				      if((bit>>_8) & 1)continue;
				      bit |= (1<<_8);
				      puzzle[7] = p2[_8];
				      rep(_9,9)
					{
					  if((bit>>_9) & 1)continue;
					  puzzle[8] = p2[_9];
					  //print();
					  dfs(0);
					}
				      r = (1<<_8);
				      r = ~r;
				      bit = bit&r;
				    }
				      r = (1<<_7);
				      r = ~r;
				      bit = bit&r;
				}
			      r = (1<<_6);
			      r = ~r;
			      bit = bit&r;
			    }
			  r = (1<<_5);
			  r = ~r;
			  bit = bit&r;
			}
		      r = (1<<_4);
		      r = ~r;
		      bit = bit&r;
		    }
		  r = (1<<_3);
		  r = ~r;
		  bit = bit&r;
		}
	      r = (1<<_2);
	      r = ~r;
	      bit = bit&r;
	    }
	  r = (1<<_1);
	  r = ~r;
	  bit = bit&r;
	}

      cout << cnt << endl;
    }
  return 0;
}