package com.tcs.bean;

public class Map {
	public static int MAPX, MAPY;
	int	key;                            /*按键保存 */
	int	sum	= 1, over = 0;          /* 蛇的长度, 游戏结束(自吃或碰墙) */
	public static int[] dx= { 0, 0, -1, 1 };      /* 左、右、上、下的方向 */
	public static int[] dy = { -1, 1, 0, 0 };
	
	public char[][] GameMap;
	
	
	public Map(int x, int y) {
		super();
		MAPX = x;
		MAPY = y;
		this.GameMap = new char[MAPX][MAPY];
	}
	public Map() {
		super();
		MAPX = 10;
		MAPY = 15;
		this.GameMap = new char[MAPX][MAPY];
	}
	public char[][] getMap() {
		return GameMap;
	}
	public void setMap(char[][] map) {
		this.GameMap = map;
	}	
	
	
}
