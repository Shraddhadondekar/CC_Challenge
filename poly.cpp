#include<iostream>
using namespace std;
struct Points
{
  int x, y;
};

struct line
{
  Points p1,p2;
};

bool online(line l,Points p)
{
  if(p.x<=max(l.p1.x, l.p2.x)&& p.x<=min(l.p1.x, l.p2.x)&&(p.y<=max(l.p1.y, l.p2.y)&&p.y<=min(l.p1.y,l.p2.y)))
    return true;
  else
    return false;
}

int direction(Points a, Points b, Points c)
{
  int val =(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
  if(val==0)
    return 0;
  else if(val<0)
    return 2;
  else
    return 1;
}

bool isIntersect(line l1, line l2)
{
  int dir1= direction(l1.p1, l1.p2, l2.p1);
  int dir2= direction(l1.p1, l1.p2, l2.p2);
  int dir3= direction(l2.p1, l2.p2, l1.p1);
  int dir4= direction(l2.p1, l2.p2, l1.p2);

  if(dir1!=dir2 && dir3!=dir4)
    return true;
  if(dir1==0 && online(l1,l2.p1))
    return true;
  if(dir2==0 && online(l1,l2.p2))
    return true; 
  if(dir3==0 && online(l2,l1.p1))
     return true;
  if(dir4==0 && online(l2,l1.p2))
    return true;
  else return false;
}

bool checkInside(Points poly[],int n, Points p)
{
  if(n<3)
    return false;

  line exline={p,{9999,p.y}};
  int count =0;
  int i=0;
  do
    {
      line side = {poly[i],poly[(i+1)%n]};
      if(isIntersect(side, exline))
       {
       	  if(direction(side.p1,p,side.p2)==0)
	     return online(side,p);
	  else 
             count++;
       }
       i=(i+1)%n;
    }while(i!=0);
     return count&1;
}


int main()
{
   Points polygoan[]= {{1,0},{8,3},{8,8},{1,5}};    
   Points p={3,5};
   int n=4;

   if(checkInside(polygoan, n, p))
     cout<<"True";
   else
      cout<<"False";

}
   

