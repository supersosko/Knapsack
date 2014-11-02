#include "knapsack.h"
using namespace std;

// Constructor
Knapsack::Knapsack(int s, float m, float si)
{


	// -set 3 values passed in
	size=s;
	mu=m;
	sigma=si;
	shop= new item[size];

	int *val=new int[size];
	int *wgt=new int[size];

	// -generate maxWeight, which is at least 100 times
	// greater than mu
	sRand(time(NULL));
	maxWeight=(rand()%101+25)*(5*mu);
    
    // -generate 2 normally distributed arrays of size "size"
    default_random_engine generator; 
    normal_distribution<int> distribution(mu,sigma);
	for (int j=0; j<size; j++)
	{
		shop[j].value=distribution(generator);
		shop[j].weight=distribution(generator);
	}
	// -put those values into Shop
	// for(int k=0; k<size; k++)
	// {
	// 	Shop[k].value= val[k];
	// 	Shop[k].weight= wgt[k]
	// }

	// -destroy value and weight subarrays
	delete val;
	delete wgt;
	
}


// Destructor
Knapsack::~Knapsack()
{
		delete Shop;
}

int Knapsack::Brute_Knapsack()
{
	item* myKnapSack;
	long runtime=0;
	int max=0;

	//Chrono stuff

	// pow_set_size is the number of times the algorithm 
	// needs to be done. In this case, it is 2^n which n
	// is the size of the array
	unsigned int pow_set_size = pow(2,size);
	// best_solution holds the array of items with the 
	// largest total value and is compared to
	// solution_value
	item solution[size];
	item best_solution[size];
	int solution_weight;
	int solution_value;
	int best_solution_value=0;
	auto start_time;
	auto end_time;

	for(int k=0; k<10; k++)
	{
		start_time= chrono::high_resolution_clock::now();

		for (int counter=0; counter<pow_set_size; counter++)
		{
			// Setting solution_weight and solution_value
			// and solution to be "empty"
			solution_weight=0;
			solution_value=0;
			for (int h=0; h<size; h++)
			{
				solution[h].value = 0;
				solution[h].weight = 0;
			}


			for (int j=0; j<size; j++)
			{
				// Generating the next possible subset.
				// Not sure how this magic works, but the 
				// Internet said to do it.
				if (counter & (1<<j))
				{
					solution[j].value = shop[j].value;
					solution[j].weight = shop[j].weight;
				}
			}


			for (int i=0; i<size;i++)
			{
				// Finding the total weight and total value of the
				// subset
				solution_weight += solution[i].weight;
				solution_value += solution[i].value;
			}

			// Checking to see if the weight of the subset doesn't 
			// "break the knapsack" and comparing its value to the
			// current best solution's value
			if (solution_weight<=maxWeight && solution_value>=best_solution_value)
			{
				// Changing the best solution of current subset
				// is a better solution
				for (int k=0; k<size; k++)
				{
					best_solution[k].value = solution[k].value;
				}
				best_solution_weight = solution_weight;
				best_solution_value = solution_value;
			}
		}

		end_time=chrono::high_resolution_clock::now();
		// Done! Making currentVal to the value of the
		// best solution
		max+=best_solution_value;
		runtime+=chrono::duration_cast<chrono::nanoseconds>(end_time-start_time).count;
	}
	runtime/=10;
	max/=10;
	cout << "Elapsed Average Runtime: " << runtime << "s" << endl;
	return max;
}

int Knapsack::Greedy_Knapsack()
{
	item* myKnapSack;
	long runtime=0;
	int max=0;
	int currentVal;
	auto start_time;
	auto end_time;
	for(int k=0; k<10; k++)
	{
		start_time= chrono::high_resolution_clock::now();



		end_time=chrono::high_resolution_clock::now();

		runtime+=chrono::duration_cast<chrono::nanoseconds>(end_time-start_time).count;
		max+=currentVal
	}
	runtime/=10;
	max/=10;
	cout << "Elapsed Average Runtime: " << runtime << "s" << endl;
	return max;

}

int Knapsack::Dynamic_Knapsack()
{
	int **V;
	bool **keep;
	item* myKnapSack;
	long runtime=0;
	int max=0;
	int currentVal;
	auto start_time;
	auto end_time;

	// Initializes V as a 2D array
	V= new int*[size];
	for(int j=0; j<size; j++)
	{
		V[j]=new int[size];
	}

	// Initializes keep as a 2D array of booleans
	bool = new bool*[size];
	for(int j=0; j<size; j++)
	{
		V[j]=new bool[size];
	}

	for(int k=0; k<10; k++)
	{
		for(int w=0; w<W; i++)
			V[0,w] = 0;

		for(int i=0; i<n; i++)
		{
			for(int w=0; w<W; w++)
			{
				if((shop[i].weight <= w) && (shop[i].value+V[i-1, w-shop[i].weight] > V[i-1,w])
				{
					V[i,w] = shop[i].value + V[i-1, w-shop[i].weight];
					keep[i,w] = 1;
				}
				else
				{
					V[i,w] = V[i-1, w];
					keep[i,w] = 0;
				}
			}	
		}
		int K = W;
		cout << "{ ";
		for(i=n; i>=1; i--)
		{
			if(keep[i,K] == 1)
			{
				cout << i << " ";
				K = K-shop[i].weight;
			}
		}
		cout << "}";

		runtime+=chrono::duration_cast<chrono::nanoseconds>(end_time-start_time).count();
		max+=V[n,W];
	}
	runtime/=10;
	max/=10;
	cout << "Elapsed Average Runtime: " << runtime << "s" << endl;
	return max;
}