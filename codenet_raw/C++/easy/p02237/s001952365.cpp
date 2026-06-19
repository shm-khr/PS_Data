#include <stdio.h>

int map_max;
int map[110][110];
int rows;
int cols[110];
int mat[110][110];

void get_map();
void print_map();
void conv_map();
void print_mat();

int main()
{

  get_map();
  //print_map();
  conv_map();
  print_mat();
  return 0;
}

void get_map()
{

  int k;
  scanf("%d", &map_max);//<100

  for(int i=0;i<map_max;i++)
    {
      scanf("%d", &k);
      scanf("%d", &cols[i]);
      for(int j=0;j<cols[i];j++)
	{
	  map[i-1][j-1]=0;
	  scanf("%d", &map[i-1][j-1]);
	}
    }

  
  return ;
}

void print_map()
{
  for(int i=0;i<map_max;i++)
    {
      for(int j=0;j<cols[i];j++)
	{
	  printf("%d", map[i-1][j-1]);
	}
      puts("");
    }
return ;
}


void conv_map()
{
  for(int i=0;i<map_max;i++)
    {
      for(int j=0;j<cols[i];j++)
	{
	  mat[i][map[i-1][j-1]-1]=1;
	}
    }
  return ;
}

void print_mat()
{
  for(int i=0;i<map_max;i++)
    {
      for(int j=0;j<map_max;j++)
	{
	  printf("%d", mat[i][j]);
	  if(j!=map_max-1)
	    {
	      printf(" ");
	    }
	}
      if(i!=map_max-1)
	{
      printf("\n");
	}
    }
}