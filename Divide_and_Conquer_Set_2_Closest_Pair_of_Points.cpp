#include <bits/stdc++.h>
using namespace std;
struct Point{
	int x;
	int y;
};
int cmpX(const void *a, const void *b){
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}
int cmpY(const void *a, const void *b){
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}
float dist(Point p1, Point p2){
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
float min(float a, float b){
	return (a < b) ? a : b;
}
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (dist(P[i], P[j]) < min){
                min = dist(P[i], P[j]);
            }
        }
    }
    return min;
}
float stripClosest(Point strip[], int size, float d){
	float min = d;
	qsort(strip, size, sizeof(Point), cmpY);
	for(int i = 0; i < size; ++i){
		for(int j = i + 1; j < size && (strip[i].y - strip[j].y) < min; ++j){
			if((dist(strip[i], strip[j])) < min){
				min =  dist(strip[i], strip[j]);
			}
		}
	}
	return min;
}
float closestUtil(Point P[], int n){
	if(n <= 3){
		return bruteForce(P, n);
	}
	int mid = n / 2;
	Point midPoint = P[mid];
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);
	float d = min(dl, dr);
	Point strip[n];
	int j = 0;
	for(int i = 0; i < n; ++i){
		if(abs(P[i].x - midPoint.x) < d){
			strip[j] = P[i];
			j++;
		}
	}
	return min(d, stripClosest(strip, j, d));
}
float closest(Point p[], int n){
	qsort(p, n, sizeof(Point), cmpX);
	return closestUtil(p, n);
}
int main(){
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("%lf \n", closest(P, n));
    printf("%f \n", sqrt(2));
    printf("%lf \n", sqrt(2));
	return 0;
}