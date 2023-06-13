#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

#define SoL 299792	// Stands for Speed of Light

class Planet {
private:
	string name;
	double sun_distance; // Always in km
	double diameter;	  // Always in km
	double mass;		  // Always in kg
public:
	Planet(string namee, double dist, double diam, double masss)
	{
		if (sizeof(namee) > 51)
		{
			printf("Name's too long!\n");
			return;
		}
		name = namee;
		sun_distance = dist;
		diameter = diam;
		mass = masss;

	}

	void print()
	{
		std::cout << "The planet's name is: " << name << ".\n";
		printf("The planet's distance to the sun is: %.0f km.\n", this->sun_distance);
		printf("The planet's diameter is: %.0f km.\n", this->diameter);
		printf("The planet's mass is: %.0f km.\n", this->mass);

	}

	double get_seconds_to_sun()
	{
		return this->sun_distance / SoL;

	}

};

class Solar_System {
private:
	Planet planets[15];
	int capacity;
	int count;
public:/*
	Solar_System(Planet planetss[], int cap, int cnt)
	{
		std::copy(planetss[0], planetss[cap], this->planets[0]);
		this->capacity = cap;
		this->count = cnt;


	}*/


	void create(int cap, int cnt, Planet planetss[15])
	{
		std::copy(planetss[0], planetss[15], this->planets[0]);
		this->capacity = cap;
		this->count = cnt;

	}

	Solar_System* copy(Solar_System system)
	{
		Solar_System* syst = new Solar_System(system.planets, system.capacity, system.count);
		if (!syst) return 0;
		return syst;

	}

};




int main()
{
	Planet Neptune("Neptune", 447460000, 49244, 102400000), Jupiter("Jupiter", 745320000, 139820, 189800000);

	puts("");
	return 0;
}