

import java.util.Scanner;

public class Main 
{
	static boolean debug = false;
	static int[][] floor = new int[5][5];
	static int[][] ceil = new int[5][5];
	
	static int[][] horizontal = new int[5][6]; //x = 3 means on left of tile x=3
	static int[][] vertical = new int[6][5]; //y = 3 means on top of tile y=3
	
	static boolean overlapped;
	
	static int lastx;
	static int lasty;
	
	static void mapOut()
	{
		if(!debug) {return;}
		for(int y = 0; y <= 5; y++)
		{
			for(int x = 0; x <= 5; x++)
			{
				if(x < 5 && horizontal[x][y] > 0)
				{
					System.out.print(" -");
				}
				else
				{
					System.out.print("  ");
				}
			}
			System.out.print("\n");
			
			for(int x = 0; x <= 5; x++)
			{
				if(y < 5 && vertical[x][y] > 0)
				{
					System.out.print("|");
				}
				else
				{
					System.out.print(" ");
				}
				
				if(x < 5 && y < 5)
				{
					System.out.print(floor[x][y]);
				}
			}
			System.out.print("\n");
		}
		
	}
	
	static void overlap()
	{
		if(debug)System.out.println("OVERLAP");
		overlapped = true;
	}
	
	static void foldHRight(int x, int y) //floor x and y
	{
		lastx = x+1;
		lasty = y;
		//ignore the would-be-overlap right
		if(debug)System.out.println("Folding h-right " + x + " " + y);
		
		//bottom
		if(horizontal[x][y+1] > 0)
		{
			if(vertical[x+2][y] > 0) {overlap(); return;}
			vertical[x+2][y] = horizontal[x][y+1];
			horizontal[x][y+1] = 0;
		}
		
		//left
		if(vertical[x][y] > 0)
		{
			if(horizontal[x+1][y+1] > 0) {overlap(); return;}
			horizontal[x+1][y+1] = vertical[x][y];
			vertical[x][y] = 0;
		}
		
		//top
		if(horizontal[x][y] > 0)
		{
			if(vertical[x+1][y] > 0) {overlap(); return;}
			vertical[x+1][y] = horizontal[x][y];
			horizontal[x][y] = 0;
		}

		//floor
		if(floor[x][y] > 0)
		{
			if(floor[x+1][y] > 0) {overlap();return;}
			floor[x+1][y] = floor[x][y];
			floor[x][y] = 0;
		}

		//ceil
		if(ceil[x][y] > 0)
		{
			if(ceil[x+1][y] > 0) {overlap();return;}
			ceil[x+1][y] = ceil[x][y];
			ceil[x][y] = 0;
		}
	}
	
	static void foldHDown(int x, int y) //floor x and y
	{
		lastx = x;
		lasty = y+1;
		//ignore the would-be-overlap down
		if(debug)System.out.println("Folding h-down " + x + " " + y + ", roof " + ceil[x][y]);
		
		//right
		if(vertical[x+1][y] > 0)
		{
			if(horizontal[x][y+1] > 0) {overlap(); return;}
			horizontal[x][y+1] = vertical[x+1][y];
			vertical[x+1][y] = 0;
		}
		
		//left
		if(vertical[x][y] > 0)
		{
			if(horizontal[x+1][y+2] > 0) {overlap(); return;}
			horizontal[x][y+2] = vertical[x][y];
			vertical[x][y] = 0;
		}
		
		//top
		if(horizontal[x][y] > 0)
		{
			if(vertical[x][y] > 0) {overlap(); return;}
			vertical[x][y+1] = horizontal[x][y];
			horizontal[x][y] = 0;
		}

		//floor
		if(floor[x][y] > 0)
		{
			if(floor[x][y+1] > 0) {overlap();return;}
			floor[x][y+1] = floor[x][y];
			floor[x][y] = 0;
		}

		//ceil
		if(ceil[x][y] > 0)
		{
			if(ceil[x][y+1] > 0) {overlap();return;}
			ceil[x][y+1] = ceil[x][y];
			ceil[x][y] = 0;
		}
	}
	
	static void ceilFoldRight(int foldx)
	{
		//DISINI
		if(debug)System.out.println("Folding ceil right " + foldx);
		//in other words, we assume use of the method that we start the right-folding from the left.
		lastx = foldx;
		
		int x = foldx - 1;
		
		for(int y = 0; y <= 5; y++)
		{
			if(y <= 4)
			{
				//floor
				if(floor[x][y]>0)
				{
					if(floor[x][y] != 0 && vertical[x+2][y] != 0) {overlap();return;}
					vertical[x+2][y] = floor[x][y];
					floor[x][y] = 0;
				}
				
				//ceiling
				if(ceil[x][y] > 0)
				{
					if(ceil[x][y] != 0 && vertical[x+1][y] != 0) {overlap();return;}
					vertical[x+1][y] = ceil[x][y];
//					if(vertical[x+2][y] != 0) {System.out.println("fromceil " + x + " " + y);}
					ceil[x][y] = 0;
				}
				
				//vertical... we're currently ignoring the vertical to the right which would cause overlap.
				if(vertical[x][y] > 0)
				{
					if(vertical[x][y] != 0 && floor[x+1][y] != 0) {overlap();return;}
					floor[x+1][y] = vertical[x][y];
//					if(vertical[x][y] != 0) {System.out.println("newceil from ver " + x + " " + y);}
					vertical[x][y] = 0;
				}
			}
			
			//horizontal
			if(horizontal[x][y] != 0 && horizontal[x+1][y] != 0) {overlap();return;}
			if(horizontal[x][y] > 0)
			{
				horizontal[x+1][y] = horizontal[x][y];
				horizontal[x][y] = 0;
			}
		}		
	}
	
	static void foldRight(int foldx) //vertical-line.
	{ //we can assume that we're only folding foldx-1, the ones left to that are already folded to right.
		if(debug)System.out.println("Folding right " + foldx);
		//in other words, we assume use of the method that we start the right-folding from the left.
		lastx = foldx;
		
		int x = foldx - 1;
		
		for(int y = 0; y <= 5; y++)
		{
			if(y <= 4)
			{
				//floor
				if(floor[x][y]>0)
				{
					if(floor[x][y] != 0 && vertical[x+1][y] != 0) {overlap();return;}
					vertical[x+1][y] = floor[x][y];
					floor[x][y] = 0;
				}
				
				//ceiling
				if(ceil[x][y] > 0)
				{
					if(ceil[x][y] != 0 && vertical[x+2][y] != 0) {overlap();return;}
					vertical[x+2][y] = ceil[x][y];
//					if(vertical[x+2][y] != 0) {System.out.println("fromceil " + x + " " + y);}
					ceil[x][y] = 0;
				}
				
				//vertical... we're currently ignoring the vertical to the right which would cause overlap.
				if(vertical[x][y] > 0)
				{
					if(vertical[x][y] != 0 && ceil[x+1][y] != 0) {overlap();return;}
					ceil[x+1][y] = vertical[x][y];
//					if(vertical[x][y] != 0) {System.out.println("newceil from ver " + x + " " + y);}
					vertical[x][y] = 0;
				}
			}
			
			//horizontal
			if(horizontal[x][y] > 0)
			{
				if(horizontal[x][y] != 0 && horizontal[x+1][y] != 0) {overlap();return;}
				horizontal[x+1][y] = horizontal[x][y];
				horizontal[x][y] = 0;
			}
		}
	}
	
	static void foldDown(int foldy) //horizontal-line.
	{ //we can assume that we're only folding foldy-1, the ones up to that are already folded to down.
		if(debug)System.out.println("Folding down " + foldy);
		//in other words, we assume use of the method that we start the down-folding from the top.
		lasty = foldy;
		
		int y = foldy - 1;
		
		for(int x = 0; x <= 5; x++)
		{
			if(x <= 4)
			{

				//that one
				if(horizontal[x][y+1] > 0)
				{
					if(horizontal[x][y+1] != 0 && floor[x][y+1] != 0) {overlap();return;}
					if(debug)System.out.println("wanna do " + x + " " + y);
					floor[x][y+1] = horizontal[x][y+1];
					horizontal[x][y+1] = 0;

				}				
				
				//floor
				if(floor[x][y]>0)
				{
					if(floor[x][y] != 0 && horizontal[x][y+1] != 0) {overlap();return;}
					horizontal[x][y+1] = floor[x][y];
	//				if(floor[x][y] > 0) {System.out.println("Fromfloor " + x + " " + y);}
					floor[x][y] = 0;
				}
				
				//ceiling
				if(ceil[x][y]>0)
				{
//					if(x == 2 && y == 1) {System.out.println("Ceil: " + ceil[2][1]);}
					if(ceil[x][y] != 0 && horizontal[x][y+2] != 0) {overlap();return;}
					horizontal[x][y+2] = ceil[x][y];
					if(debug && ceil[x][y] > 0) {System.out.println("Fromceil " + x + " " + y);}
					ceil[x][y] = 0;
				}
				

				//horizontal ignoring the one-to-the-down one
				if(horizontal[x][y] > 0)
				{
					if(horizontal[x][y] != 0 && ceil[x][y+1] != 0) {overlap();return;}
					ceil[x][y+1] = horizontal[x][y];
					if(debug && horizontal[x][y] > 0) {System.out.println("Newceilfrom h " + x + " " + y + ": " + ceil[x][y+1] + " at " + x + " " + (y+1));}
					horizontal[x][y] = 0;

				}

			}
			
			
			//vertical
			if(vertical[x][y] > 0)
			{
				if(vertical[x][y] != 0 && vertical[x][y+1] != 0) {overlap();return;}
				vertical[x][y+1] = vertical[x][y];
				vertical[x][y] = 0;
			}
		}
	}

	public static void main(String[] args) 
	{
		int n;
		Scanner scan = new Scanner(System.in);
		
		n = scan.nextInt();
		
		for(int i = 0; i < n; i++)
		{
			overlapped = false;
			floor = new int[5][5];
			ceil = new int[5][5];
			
			horizontal = new int[5][6];
			vertical = new int[6][5];
			
			boolean[] numberappeared = new boolean[6];
			int appearednums = 0;
			
			boolean preout = false;
			for(int y = 0; y < 5; y++)
			{
				for(int x = 0; x < 5; x++)
				{
					floor[x][y] = scan.nextInt();
					if(floor[x][y] < 0 || floor[x][y] > 6) 
					{
						preout = true;
					}
					else if(floor[x][y] != 0) //valid non-zero number
					{
						if(numberappeared[floor[x][y]-1])
						{
//							System.out.println(floor[x][y] + " already appeared");
							preout = true;
						}
						
						numberappeared[floor[x][y]-1] = true;
						appearednums += 1;
						
						if(appearednums > 6) {preout = true;}
					}
				}
			}
			
			if(preout)
			{
//				System.out.println("PRE OUT");
				System.out.println("false");
				continue;
			}
			
			int curX = 0;
			boolean xfolding = true;
			boolean foldedxh;
			int xfoldtimes = 0;
			
			for(curX = 0; curX < 5; curX++)
			{
				if(overlapped) {break;}
				
				xfolding = false;
				foldedxh = false;
				
				//check for vertically-connected floors
				boolean prev = false;
				boolean prev2 = false;
				for(int ty = 0; ty < 5; ty++)
				{
					if(floor[curX][ty] > 0)
					{
//						if(prev)
						{
							for(int iy = 1; iy <= ty; iy++)
							{
								//if there's anything to fold here, fold
								boolean doit = false;
								for(int ttx = 0; ttx <= 4; ttx++)
								{
									if(floor[ttx][iy-1] > 0 && floor[ttx][iy] > 0) //DISINI YG -1
									{
										doit = true;
									}
									else
									{
										if(floor[ttx][iy-1] <= 0)
										{
//											System.out.println("WEIRD " + ttx + " " + (iy-1));
										}
									}
								}
								if(doit)
								{
									foldDown(iy);
								}
							}
							mapOut();
						}
						prev = true;
								

					}
					else
					{
						prev = false;
					}
					
					//
					if(vertical[curX+1][ty] > 0)
					{
//						if(prev2)
						{
							for(int iy = 1; iy <= ty; iy++)
							{
								//if there's anything to fold here, fold
								boolean doit2 = false;
								int lex = 0;
								for(int ttx = 1; ttx <= 4; ttx++)
								{
									if(vertical[ttx+1][iy-1] > 0 && vertical[ttx+1][iy] > 0) //DISINI YG -1
									{
										lex = ttx;
										doit2 = true;
									}
								}
								if(doit2)
								{
if(debug)									System.out.println("DOOO " + lex + " " + ty);
									foldHDown(lex, iy-1);
								}
							}
//							mapOut();
						}
						prev2 = true;
								

					}
					else
					{
						prev = false;
					}					

					//					
				}
				
				for(int ty = 0; ty < 5; ty++)
				{
					if(floor[curX][ty] > 0)
					{
						//if it's a floor, also check for connections to next x, for the next x-folding
						if(curX < 4 && floor[curX+1][ty] > 0)
						{
							if(debug)System.out.println("Can FR from " + curX + " " + ty);
							xfolding = true;
						}
					}
					if(xfolding && curX < 4)
					{
						xfoldtimes += 1;
						foldRight(curX+1);
						xfolding = false;
						mapOut();
					}
					
				}
				
				
				//cheese h-bar
				{
					if(floor[lastx][lasty] > 0 && horizontal[lastx][lasty] > 0 && horizontal[lastx][lasty+1] > 0 && vertical[lastx][lasty] > 0 && vertical[lastx+1][lasty] == 0 && ceil[lastx][lasty] > 0)
					{
						if(lastx <= 3 && horizontal[lastx+1][lasty+1] > 0 && vertical[lastx+1][lasty] == 0)
						{
							if(debug) {System.out.println("CHEESE");}
							vertical[lastx+1][lasty] = horizontal[lastx+1][lasty+1];
							horizontal[lastx+1][lasty+1] = 0;
						}
					}
					else
					{
//						if(debug)System.out.println("No cheese " + lastx + " " + lasty + " ceil " + ceil[lastx][lasty]);
					}
				}	

				
				
				if(xfolding == false && curX < 4) //check for XH folding
				{
					for(int ty = 0; ty < 5; ty++)
					{
						if(horizontal[curX][ty] > 0)
						{
							//if it's has a top, also check for connections to next top
							if(curX < 4 && horizontal[curX+1][ty] > 0)
							{
								if(debug)System.out.println("Can FHHHHR from " + curX + " " + ty);
								xfolding = true;
							}
						}
						if(xfolding && curX < 4)
						{
							xfoldtimes += 1;
							foldHRight(curX,ty);
							foldedxh = true;
							xfolding = false;
							mapOut();
						}					
					}
				}
//				else if(foldedxh == false)
				{
					for(int ty = 0; ty < 5; ty++)
					{
						if(ceil[curX][ty] > 0)
						{
							//if it has a ceil, also check for connections to next ceil
							if(curX < 4 && ceil[curX+1][ty] > 0)
							{
								if(debug)System.out.println("Can CCCCC from " + curX + " " + ty);
								
								xfoldtimes += 1;
								ceilFoldRight(curX+1);
								foldedxh = true;
								xfolding = false;
								mapOut();
							}
						}
					}					
				}
				
			
				
				//ceilFoldRight
			}
			
			
			boolean ans;
			if(overlapped)
			{
				ans = false;
//				System.out.println("overlapped");
			}
			else
			{
				if(floor[lastx][lasty] > 0 && horizontal[lastx][lasty] > 0 && horizontal[lastx][lasty+1] > 0 && vertical[lastx][lasty] > 0 && vertical[lastx+1][lasty] > 0 && ceil[lastx][lasty] > 0)
				{
					int f = floor[lastx][lasty];
					int c = ceil[lastx][lasty];
					int l = horizontal[lastx][lasty];
					int r = horizontal[lastx][lasty+1];
					int u = vertical[lastx][lasty];
					int d = vertical[lastx+1][lasty];
					
					if(f + c == 7 && l + r == 7 && u + d == 7)
					{
						ans = true;
					}
					else
					{
if(debug)						System.out.println("sum");
						ans = false;
					}
				}
				else
				{
//					System.out.println("hole");
					ans = false;
				}
			}
			System.out.println(ans);
if(debug)			System.out.println("FIN. x = " + lastx + ", y = " + lasty + " roof " + ceil[lastx][lasty]);
//			System.out.println(ceil[lastx+1][lasty]);
//			boolean ans = ;
			
		}
		
	}

}

