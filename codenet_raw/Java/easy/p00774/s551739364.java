
import java.util.Scanner;

public class Main 
{
	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		while(true)
		{
			int input = scan.nextInt();
			
			if(input == 0)
			{
				break;
			}
			else
			{
				new DataSet(input);
			}
		}
	}

	static class DataSet
	{
		int[][] tile;
		int col;
		int score = 0;
		
		public DataSet(int arg)
		{
			col = arg;
			tile = new int[5][col];
			
			for(int y = 0; y < col; y++)
			{
				for(int x = 0; x < 5; x++)
				{
					tile[x][y] = scan.nextInt();
				}
			}
			
			while(true)
			{
				if(checkMatches() == 0)
				{
					break;
				}
				
				boolean fell = true;
				
				while(fell == true)
				{
					fell = fall();
				}
			}
			
			System.out.println(score);
		}

		boolean fall()
		{
//			System.out.println("FALL");
			boolean fell = false;
			for(int y = col-1; y >= 0; y--)
			{
				for(int x = 0; x < 5; x++)
				{
					if(tile[x][y] == 0)
					{
						if(y > 0)
						{
							if(tile[x][y-1] > 0) {fell = true;}

							tile[x][y] = tile[x][y-1];
							tile[x][y-1] = 0;
						}
					}
				}
			}
			
			return fell;
		}
		
		int checkMatches()
		{
			int scoreGot = 0;
			
			for(int y = 0; y < col; y++)
			{
				int curNum = -1;
				int occurences = 0;
				
				for(int x = 0; x < 5; x++)
				{
					int sel = tile[x][y];
					
					if(sel > 0)
					{
						if(sel == curNum)
						{
							occurences += 1;
						}
						else
						{
							if(occurences >= 3)
							{
								//left to this disappears
//								System.out.println("Score " + tile[x-1][y] + " x " + occurences + " at " + y);
								
								for(int xDis = x - occurences; xDis <= x-1; xDis++)
								{
									scoreGot += tile[xDis][y];
									tile[xDis][y] = 0;
								}
							}
							
							curNum = sel;
							occurences = 1;
						}
					}
				}
				
				//
				if(occurences >= 3)
				{
					//left to this disappears
//					System.out.println("Score " + tile[4][y] + " x " + occurences + " at " + y);
					
					for(int xDis = 5 - occurences; xDis <= 4; xDis++)
					{
						scoreGot += tile[xDis][y];
						tile[xDis][y] = 0;
					}
				}
				
				//
			}
			
			score += scoreGot;
			return scoreGot;
		}
	}
}

