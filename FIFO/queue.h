typedef struct Node *node;
double randomnum();
double burstsum(node first);
double waitav(int size, node first);
int enqueue(double bmid, double bvar,
	  double amid, double avar);
int dequeue();

double randomnum();
double burst(double bmid, double bvar);
double arrival(double amid, double avar);
void iterate();
double arrav(node first, int size);
double arravbt(node first, int size);
