#include <bits/stdc++.h>
using namespace std;
struct Points
{
	int x, y;
};
int orientation(Points p, Points q, Points r)
{
	int val = (r.x - q.x) * (q.y - p.y) - (q.x - p.x) * (r.y - q.y);
	if(val == 0)
	{
		return 0;
	}
	return (val > 0) ? 1 : 2;
}
bool line_segment(Points p1, Points q1, Points p2, Points q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if(o1 != o2 && o3 != o4)
	{
		return true;
	}
	return false;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		struct Points *arr, temp;
		int x, y;
		for(int i = 0; i < 4; i++)
		{
			cin>>x>>y;
			temp.x = x;
			temp.y = y;
			arr[i] = temp;
		}
		if(line_segment(arr[0], arr[1], arr[2], arr[3]))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
//How_to_check_if_two_given_line_segments_intersect.cpp