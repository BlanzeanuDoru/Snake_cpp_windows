class worm
{
	private:
		int direction;
		int body;
	struct body
	{
		int x;
		int y;
	}corp[800];
	
	public:
	void move();
	void SetX(int,int);
	void SetY(int,int);
	void SetDir(int);
	void SetBody(int);
	int  GetX(int);
	int  GetY(int);
	int  GetDir();
	int  GetBody();
	worm(int a=0,int b=0,int c=0,int d=1);
};
