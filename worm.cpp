
void worm::SetX(int x1,int n)
{
	corp[n].x=x1;
}

void worm::SetY(int y1,int n)
{
	corp[n].y=y1;
}

void worm::SetDir(int Dir)
{
	direction=Dir;
}

void worm::SetBody(int Body)
{
	body=Body;
}

int worm::GetX(int n)
{
	return corp[n].x;
}

int worm::GetY(int n)
{
	return corp[n].y;
}

int worm::GetDir()
{
	return direction;
}

int worm::GetBody()
{
	return body;
}

worm::worm(int a,int b,int c,int d)  //constructor
{
	corp[0].x=a;
	corp[0].y=b;
	direction=c;
	body=d;
}
