#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
	Rect newR1,newR2;
	newR1.w = R1->x+R1->w;
	newR1.h = R1->y-R1->h;
	newR2.w = R2->x+R2->w;
	newR2.h = R2->y-R2->h;
	double xdis = min(newR1.w,newR2.w)-max(R1->x,R2->x);
	double ydis = min(R1->y,R2->y)-max(newR1.h,newR2.h);
	double area = 0;
	if(xdis > 0 && ydis > 0){
		double area = xdis*ydis;
		return area;
	}
	return area;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {7,2,3,3};	
	cout << overlap(&R1,&R2);		
}
