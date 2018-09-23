#include <bits/stdc++.h>
using namespace std;
struct Geometry
{
	int x, y;
};
bool onSegment(Geometry p, Geometry q, Geometry r)
{
	if(q.x <= max(p.x, r.x) && q.x >=  min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >=  min(p.y, r.y)
		)
	{
		return true;  
	}
	return false;
}
int orientation(Geometry p, Geometry q, Geometry r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if(val == 0)
	{
		return 0;
	}
	return (val > 0) ? 1: 2;
}
int main()
{
	int T, N, x1, y1, x2, y2;
	cin >> N;
	struct Geometry seg1[N], seg2[N], p1, p2, q1, q2;
	for(int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		seg1[i].x = x1;
		seg1[i].y = y1;
		seg2[i].x = x2;
		seg2[i].y = y2;
	}
	int visited[N];
	for(int i = 0; i < N; i ++)
	{
		visited[i] = false;
	}
	int flag = false;
	for(int i = 0; i < N; i++)
	{
		visited[i] = true;
		p1 = seg1[i];
		q1 = seg2[i];
		for(int j = 0; j < N; j++)
		{
			if(visited[j])
			{
				continue;
			}
			p2 = seg1[j];
			q2 = seg2[j];
			int o1 = orientation(p1, q1, p2);
			int o2 = orientation(p1, q1, q2);
			int o3 = orientation(p2, q2, p1);
			int o4 = orientation(p2, q2, q1);
			if(o1 != o2 && o3 != o4)
			{
				cout << "(" << p1.x << "," << p1.y << ") & (" 
					<< q1.x << "," << q1.y << ")" << "   and   ("
					<< p2.x << "," << p2.y << ") & (" 
					<< q2.x << "," << q2.y
					<< ")\n";
					flag = true;
					break;
			}
			else if(o1 == 0 && onSegment(p1, p2, q1))
			{
				cout << "(" << p1.x << "," << p1.y << ") & (" 
					<< q1.x << "," << q1.y << ")" << "   and   ("
					<< p2.x << "," << p2.y << ") & (" 
					<< q2.x << "," << q2.y
					<< ")\n";
					flag = true;
					break;
			}
			else if(o2 == 0 && onSegment(p1, q2, q1))
			{
				cout << "(" << p1.x << "," << p1.y << ") & (" 
					<< q1.x << "," << q1.y << ")" << "   and   ("
					<< p2.x << "," << p2.y << ") & (" 
					<< q2.x << "," << q2.y
					<< ")\n";
					flag = true;
					break;
			}
			else if(o3 == 0 && onSegment(p2, p1, q2))
			{
				cout << "(" << p1.x << "," << p1.y << ") & (" 
					<< q1.x << "," << q1.y << ")" << "   and   ("
					<< p2.x << "," << p2.y << ") & (" 
					<< q2.x << "," << q2.y
					<< ")\n";
					flag = true;
					break;
			}
			else if(o4 == 0 && onSegment(p2, q1, q2))
			{
				cout << "(" << p1.x << "," << p1.y << ") & (" 
					<< q1.x << "," << q1.y << ")" << "   and   ("
					<< p2.x << "," << p2.y << ") & (" 
					<< q2.x << "," << q2.y
					<< ")\n";
					flag = true;
					break;
			}
		}
	}
	if(!flag)
	{
		cout << "No Intersection found\n";
	}
	return 0;
}