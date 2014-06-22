#include"Matryca.h"

class ObiektOblakania{
public:
	int WinLooseBalance;
//	ObiektOblakania* starszy;
	char gracz;
	Matryca situation;
	vector<ObiektOblakania> mlodsze;

	ObiektOblakania();
	ObiektOblakania(const ObiektOblakania& X);
	ObiektOblakania& operator=(const ObiektOblakania& X);
	void UtworzMlodsze();
	void Oblicz();
};
//typedef ObiektOblakania Objekt;

ObiektOblakania::ObiektOblakania(){
//	starszy=new ObiektOblakania;
//	starszy=NULL;
	WinLooseBalance=0;
	gracz='-';
	mlodsze.clear();
}

ObiektOblakania::ObiektOblakania(const ObiektOblakania& X){
	WinLooseBalance=X.WinLooseBalance;
	gracz=X.gracz;
//	starszy=X.starszy;
	situation=X.situation;
	mlodsze=X.mlodsze;
}

ObiektOblakania& ObiektOblakania::operator=(const ObiektOblakania& X){
	WinLooseBalance=X.WinLooseBalance;
	gracz=X.gracz;
//	starszy=X.starszy;
	situation=X.situation;
	mlodsze=X.mlodsze;
	return *this;
}
/*
bool ObiektOblakania::Przeanalizuj(){
	if(situation->Wygrana('X')){
		WinLooseBalance=10;
		last=true;
		return true;
	}
	if(situation->Wygrana('O')){
		WinLooseBalance=-10;
		last=true;
		return false;
	}
	if(situation->Pelny()){
		WinLooseBalance=1;
		last=true;
		return true;
	}
	WinLooseBalance=0;
	return true;
}
*/
/*
bool ObiektOblakania::DodajMlodsze(){
	cliext::vector<ObiektOblakania^> mlodsze1;
	vector<ObiektOblakania^>::iterator it;
	ObiektOblakania^ O;
	ObiektOblakania^ wsk;
	starszy=gcnew ObiektOblakania;

	O->starszy=this;
	if(gracz=='O'){
		O->gracz='X';
	} else {
		O->gracz='O';
	}
	O->mlodsze->clear();
	for(int k=0; k<4; k++){
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(situation->matrix[i][j][k]=='-'){
					O->situation=situation;
					O->situation->Add(i, j, k, O->gracz);
					if(O->gracz=='O'){
						if(O->Przeanalizuj()){
							wsk=gcnew ObiektOblakania;
							*wsk=O;
							mlodsze.push_back(wsk);
						} else {
							return false;
						}
					} else {
						if(O->Przeanalizuj() && (O->situation->Wygrana('X') || O->situation->Pelny())){
							wsk=gcnew ObiektOblakania;
							*wsk=O;
							mlodsze1.push_back(wsk);
						}
					}
				}
			}
		}
	}
}
*/

void ObiektOblakania::UtworzMlodsze(){
	ObiektOblakania O;
//	O->starszy=this;
	O.gracz=przeciwnik(gracz);
	O.mlodsze.clear();
	for(int k=0; k<4; k++){
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(situation.matrix[i][j][k]=='-'){
					O.situation=situation;
					O.situation.Add(i, j, k, O.gracz);
					O.WinLooseBalance=0;
					O.Oblicz();
					mlodsze.push_back(O);
				}
			}
		}
	}
}

void ObiektOblakania::Oblicz(){
	WinLooseBalance=situation.Analizuj(gracz);
}