#include <iostream>

int main()
{
double x, y;
std::cin>>x>>y;
if (y<-1 && y>1)
std::cout<<"false"<<std::endl;
else if ((y>=0 && x<=1 && x>=-1) ||
	(y<0 && y*y+x*x<=1))
std::cout<<"true"<<std::endl;
}

