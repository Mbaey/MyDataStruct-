package com.tcs.bean;

public class Map {
	public static int MAPX, MAPY;
	int	key;                            /*�������� */
	int	sum	= 1, over = 0;          /* �ߵĳ���, ��Ϸ����(�ԳԻ���ǽ) */
	public static int[] dx= { 0, 0, -1, 1 };      /* ���ҡ��ϡ��µķ��� */
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
