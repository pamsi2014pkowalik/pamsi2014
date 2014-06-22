#include"ObiektOblakania.h"
#include <cstdlib>
#include <cstdio>
#include <random>
#include <ctime>
class CPU{
public:
	ObiektOblakania* plan;
//	vector<ObiektOblakania>^ ostatniododane;

	CPU();
//	void dodajPoziomy(Int32 poziomy);
	void dodajpoziom();
	pole CPUmove(int tura);
	void PLAYERmove(Matryca X);
	void Utworz(Matryca X);
};

CPU::CPU(){
	plan=new ObiektOblakania;
//	ostatniododane=gcnew vector<ObiektOblakania^>;
}

void CPU::Utworz(Matryca X){
//	plan->starszy=NULL;
	plan->WinLooseBalance=0;
	plan->situation=X;
	plan->gracz='O';
	plan->mlodsze.clear();
	plan->UtworzMlodsze();
}

pole CPU::CPUmove(int tura){
	if(tura<2){
		while(1){
			srand((unsigned int)time(NULL));
			if(plan->situation.matrix[rand()%2+1][rand()%2+1][rand()%2+1].znacznik=='-'){
				return plan->situation.matrix[rand()%2+1][rand()%2+1][rand()%2+1];
			}
		}
	}
	ObiektOblakania* newplan=new ObiektOblakania;

	int max=(numeric_limits<int>::min)();
	vector<ObiektOblakania>::iterator it;
	for(it=plan->mlodsze.begin(); it!=plan->mlodsze.end(); it++){
		if(it->WinLooseBalance>max){
			*newplan=*it;
			max=it->WinLooseBalance;
		}
	}
	plan=newplan;
	return plan->situation.ostatni;
}

void CPU::PLAYERmove(Matryca X){
/*	vector<ObiektOblakania*>::iterator it;
	for(it=plan->mlodsze.begin(); it!=plan->mlodsze.end(); it++){
		if(wybor==(*it)->situation.ostatni){
			plan=(*it);
			break;
		}
	}*/
	plan->WinLooseBalance=0;
	plan->situation=X;
	plan->gracz=X.ostatni.znacznik;
	plan->mlodsze.clear();
	plan->UtworzMlodsze();

}

void CPU::dodajpoziom(){
	plan->UtworzMlodsze();

}