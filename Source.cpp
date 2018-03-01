#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

ifstream fin("b_should_be_easy.in");
ofstream fout("a.out");

struct ride
{
	int a;
	int b;
	int x;
	int y;
	int s;
	int f;
	int dist;
	bool isFinished;
};

struct car
{
	int time;
	int x;
	int y;
	int rides[10000];
	int noRides;
};



int R, C, N, F, B, T, i;

bool comp(ride a, ride b)
{
	if (a.s == b.s)
		return (a.f < b.f);
	else
		return (a.s < b.s);
}

vector<ride> rides(10000);
vector<car> cars(1000);

bool searchClosestRide(car &c)
{
	int minDist = C * R;
	ride* closestRide = &*rides.begin();
	int rideID = 0;
	for (int i = 0 ; i < N; ++i)
	{
		if (!rides[i].isFinished)
		{
			int z = abs(c.x - rides[i].a) + abs(c.y - rides[i].b);
			if (z < minDist && c.time + rides[i].dist + z <= rides[i].f)
			{
				minDist = z;
				closestRide = &rides[i];
				rideID = i;
			}
		}
	}

	if (minDist < C*R)
	{
		c.x = closestRide->x;
		c.y = closestRide->y;
		c.time += closestRide->dist + minDist;

		closestRide->isFinished = true;
		c.rides[c.noRides++] = rideID;
		return true;
	}
	else
		return false;
}

int main()
{
	fin >> R >> C >> F >> N >> B >> T;

	for (i = 0; i < N; ++i)
	{
		fin >> rides[i].a >> rides[i].b >> rides[i].x >> rides[i].y >> rides[i].s >> rides[i].f;
		rides[i].dist = abs(rides[i].x - rides[i].a) + abs(rides[i].y - rides[i].b);
	}

	// Sorted by the starting time.
	//sort(rides.begin(), rides.end(), comp);

// 	for (i = 0; i < N; ++i)
// 	{
// 		fout << rides[i].s << ' ' <<rides[i].f << '\n';
// 	}


	int n = N;
	for(int j = 0; j < 800; ++j)
	{
		for (i = 0; i < F; ++i)
		{
			if (searchClosestRide(cars[i]))
			{
				//fout << i << ' ' << cars[i].x << ' ' << cars[i].y << ' ' << cars[i].time << '\n';
				--n;
			}
		}
	}

	for (i = 0; i < F; ++i)
	{
		fout << cars[i].noRides;
		for (int j = 0; j < cars[i].noRides; ++j)
			fout << ' ' << cars[i].rides[j];
		fout << '\n';
	}



	return 0;
}
