#include <cstdio>
#include <cmath>
using namespace std;
#define F(x) (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u)

int main()
{
    int p, q, r, s, t, u;
    while (scanf("%d %d %d %d %d %d",&p, &q, &r, &s, &t, &u)!=EOF)
    {
        double Min=0.0, Max=1.0, mid;
        for (int i=0; i<100; i++){
            mid = (Min+Max)/2;
            if (F(mid)>0) Min = mid;
            else Max = mid;
        }
        if (fabs(F(mid)-0) > 1e-10) printf ("No solution\n");
        else printf("%.4lf\n",mid);
    }
    return 0;
}