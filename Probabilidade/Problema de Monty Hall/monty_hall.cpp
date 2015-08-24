#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int randInt(int low, int high){
	int k;
	double d;
	d = (double) rand() / ((double) RAND_MAX + 1);
	k = (int) ( d * ( high - low + 1));

	return (low + k);
}

double montyHallSwappingChoose(int inputs){
	srand (inputs);
	double corrects = 0;
	for(int i = 0; i < inputs; ++i){
		int doors[] = {0,0,0};
		int door = randInt(0,2);
		int choose = randInt(0,2);
		doors[door] = 1;
		doors[choose] = 1;

		if(doors[0] == 0){
			if(choose == 1)
				choose = 2;
			else
				choose = 1;
		}else if(doors[1] == 0){
			if(choose == 0)
				choose = 2;
			else
				choose = 0;
		}else{
			if(choose == 0)
				choose == 1;
			else
				choose = 0;
		}

		if(choose == door)
			++corrects;

	}
	return corrects/inputs;
}

double montyHallWithoutSwappingChoose(int inputs){
	srand (inputs);
	double corrects = 0;
	for(int i = 0; i < inputs; ++i){
		int door = randInt(0,2);
		int choose = randInt(0,2);		

		if(choose == door)
			++corrects;

	}
	return corrects/inputs;
}

int main(){
	cout<<"\n\n";
	cout<<"\t\t########################################"<<endl;
	cout<<"\t\t#        Problema do Monty Hall        #"<<endl;
	cout<<"\t\t########################################"<<endl;
	cout<<"\t\t# ######### || PORCENTAGEM DE ACERTOS  #"<<endl;
	cout<<"\t\t#--------------------------------------#"<<endl;
	cout<<"\t\t# ELEMENTOS ||  C/ TROCA ||  S/ TROCA  #"<<endl;
	cout<<"\t\t#--------------------------------------#"<<endl;
	printf("\t\t#  1        ||  %.3lf  %% || %.3lf %%  #\n",montyHallSwappingChoose(1)*100, montyHallWithoutSwappingChoose(1)*100);
	printf("\t\t#  10       ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(10)*100, montyHallWithoutSwappingChoose(10)*100);
	printf("\t\t#  100      ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(100)*100, montyHallWithoutSwappingChoose(100)*100);
	printf("\t\t#  1000     ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(1000)*100, montyHallWithoutSwappingChoose(1000)*100);
	printf("\t\t#  10000    ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(10000)*100, montyHallWithoutSwappingChoose(10000)*100);
	printf("\t\t#  100000   ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(100000)*100, montyHallWithoutSwappingChoose(100000)*100);
	printf("\t\t#  1000000  ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(1000000)*100, montyHallWithoutSwappingChoose(1000000)*100);
	printf("\t\t#  10000000 ||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(10000000)*100, montyHallWithoutSwappingChoose(10000000)*100);
	printf("\t\t#  100000000||  %.3lf %% ||  %.3lf %%  #\n",montyHallSwappingChoose(100000000)*100, montyHallWithoutSwappingChoose(100000000)*100);
	cout<<"\t\t########################################"<<endl;
	cout<<"\n\n";
	return 0;
}