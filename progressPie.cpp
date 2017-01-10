/*
ID: crazyco3
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>

using namespace std;
typedef pair<int, int> PII;

const int kRadius = 50;
const double kPi = acos(-1);

ofstream fout ("my.out");
ifstream fin ("progresspie.in");

void foutWhite(int i)
{
    fout << "Case #" << i << ": " << "white" << endl;
}

void foutBlack(int i)
{
    fout << "Case #" << i << ": " << "black" << endl;
}

bool inCircle(const int x, const int y)
{
    double r = x*x+y*y;
    return r <= kRadius*kRadius;
}

int main() {

    int n;
    fin >> n;
    cout << "pi" << kPi << endl;
    for(int i=1;i<=n;i++)
    {

        // 1. input arguments
        int p,x,y;
        fin >> p >> x >> y;
        x -= kRadius;
        y -= kRadius;

        if(!inCircle(x, y))
        {
            // 2. if point out of circle
            foutWhite(i);
        }
        else
        {
            cout << "i:" << i << endl;
            // 3. if point in circle, calculate angle
            double alpha, beta;
            alpha = (p/100.00)*kPi*2;
            int x1, y1;
            x1 = y;
            y1 = -x;
            beta = atan2(y1,x1);
            if (beta < 0) beta += 2 *kPi;
            if(beta < 2*kPi - alpha) foutWhite(i);
            else foutBlack(i);
            cout << "alpha:" << alpha << " beta" << beta << endl;
        }

    }

    return 0;
}
