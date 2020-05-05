#include <iostream>
#include<fstream>
#include<sstream>
#include<math.h>
#include<string.h>
#include<string>
#include <windows.h>
using namespace std;

class Etudiant{
	
	protected:
		
	string nom;
	string prenom;
	float notecc;
	float notetp;
	float noteprojet;
	float noteexam;
	float  notef;
	
	public:
		

//	Etudiant(string,string,float,float,float,float);  //constructeur 
	void saisir(string**,int);
//	void afficher();
	char resultat();
	float init_excel();
	float affiche_excel();
	void afficher_mat(string**,int);
	void remplir_excel(string**,int);
	string accesseur(){return prenom;}
	string accesseur1(){return nom;}
	int Rechercher(string**,int);
	int Rechercherr(string**,int,string,string);
	void stocker(string**,int);
	void modifier(string**,int,string,string,string);
	void modifier_etu(string **,int) ;
	void supprimer(string**,int);
	void affmat(string **M,int l)
    {    //juste pour une bonne organization 
  
		    {cout<<M[0][0]<<" \t\t"; cout<<M[0][1]<<" \t\t"; cout<<M[0][2]<<" \t\t";cout<<M[0][3]<<" \t\t";cout<<M[0][4]<<" \t";cout<<M[0][5]<<" \t";cout<<M[0][6]<<" \t"; }          
		    cout<<endl;
			
			//a partir la ligne des etudiants
		for (int i=1; i<l; i++){
		    for (int j=0; j<7; j++)
		    {cout<<M[i][j]<<" \t\t";   }          
		    cout<<endl;
			}
    }
    int nbrlignes()
    {
    	  ifstream fichier("C:/Users/Othman/Desktop/testtt.xls") ;
  	      int nbrlignes=0;string ligne ;

                while(getline(fichier,ligne)) // Tant qu'on n'est pas à la fin, on lit
               {   nbrlignes++; }
            
          return nbrlignes;
	}
	
	
};

/*Etudiant::Etudiant(string nom,string prenom,float notecc,float notetp,float noteprojet,float noteexam)
{
	this->nom=nom;
	this->prenom=prenom;
	this->notecc=notecc;
	this->notetp=notetp;
	this->noteprojet=noteprojet;
	this->noteexam=noteexam;

}*/	

void Etudiant::saisir(string**s,int l)
{       int nbr_etudiant; 
        cout<<"Combien d'etudiant voulez-vous saisir?\t";cin>>nbr_etudiant;
        ofstream fichier ("C:/Users/Othman/Desktop/testtt.xls",ios::app) ;  
	if(fichier.is_open())
	{
		     
        for(int i=0;i<nbr_etudiant;i++)
      {
      
	do{  	
        cout<<"entrer le nom :";
        cin>>nom;
        //fichier<<nom<<"\t\t";
        
       
        cout<<"entrer le prenom :";
        cin>>prenom;
  
   
   
       if(Rechercherr(s,l,nom,prenom)==1)  
	    { 
	        cout<<"Verification ";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<"."<<endl; Sleep(1000);
		    cout<<"L'etudiant :  "<<nom<<" "<<prenom<<"  est  deja existe !!!"<<endl;Sleep(2000);
		    cout<<"Veuillez Entrer un autre etudiant s'il vous plait "<<endl;Sleep(1500);
		}
	 }while(Rechercherr(s,l,nom,prenom)==1)	;
/*	   else
	{*/
	   
	   		    //{
	    cout<<"Verification ";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<".  "; Sleep(1500);
	    cout<<"reussie"<<endl;Sleep(1500);
	   
       
       fichier<<nom<<"\t\t";
       fichier<<prenom<<"\t\t";
        
        do{
         	cout<<"Entrer la note du controle continu :";
        	cin>>notecc;
          }while(notecc<0 || notecc>20);	
        	fichier<<notecc<<"\t\t";
        //	ss[i][2]=notecc;
        
        do{	
           	cout<<"Entrer la note du tp :";
          	cin>>notetp;
          }while(notetp<0 || notetp>20);	
          	fichier<<notetp<<"\t\t";
         //	ss[i][3]=notetp;
          
		do{  	
          	cout<<"Entrer la note du projet :";
	        cin>>noteprojet;
	      }while(noteprojet<0 || noteprojet>20);	    
	        fichier<<noteprojet<<"\t\t";
	       // ss[i][4]=noteprojet;
	       
		do{    
	        cout<<"Entrer la note d examen  :";
	        cin>>noteexam;
	      }while(noteexam<0 || noteexam>20);	    
	        fichier<<noteexam<<"\t\t";
	       // ss[i][5]=noteexam;
	        
	        
	        notef=0.15*notecc+0.15*noteprojet+0.2*notetp+0.5*noteexam;
	        fichier<<notef<<"\t"<<endl;
	        //ss[i][6]=notef;
	        Sleep(2000);cout<<"L'etudiant "<<nom<<" "<<prenom<<" a ete ajoute"<<endl;Sleep(2000);system("pause");
	       
	      
	  } 
	 }  
	 else cout<<"Erreur"<<endl;

fichier.close();	
}
 /*void Etudiant::afficher(){
	cout<<"Le nom                  :"<<nom<<endl;
	cout<<"Le prenom               :"<<prenom<<endl;
	cout<<"La note de controle     :"<<notecc<<endl;
	cout<<"La note de tp           :"<<notetp<<endl;
	cout<<"La note de projet       :"<<noteprojet<<endl;
	cout<<"La note d'examen        :"<<noteexam<<endl;
	cout<<"La note finale          :"<<notef<<endl;

}*/

char Etudiant::resultat()
{   float moy;
	if(moy>=12) 
	return 'V';
	else
	return'R';
}
float Etudiant::init_excel(){
	ofstream fexcel;
	fexcel.open("C:/Users/Othman/Desktop/testtt.xls");
	fexcel << "nom \t\t prenom  \t\t notecc \t\t notetp \t\t noteprojet \t\t noteexam \t\t notef " << endl;

	fexcel.close();
}
float Etudiant::affiche_excel()
{
	/*ifstream fexcel;
	fexcel.open("C:/Users/Othman/Desktop/test.csv");
	//fexcel << "nom; prenom ; notecc ; notetp ; noteprojet ; noteexam " << endl;
	//fexcel << nom<<";"<<prenom<<";"<<notecc<<";"<<notetp <<";"<<noteprojet<<";"<<noteexam<< endl;*/
	
    ifstream fichier("C:/Users/Othman/Desktop/testtt.xls") ;
  	int nbrlignes=-1;
    if(fichier)
    {
        // L'ouverture s'est bien passée, on peut donc lire
 
        string ligne ; // Une variable pour stocker les lignes lues
      
        while(getline(fichier, ligne)) // Tant qu'on n'est pas à la fin, on lit
        {
       
            cout << ligne << endl;
        
            // Et on l'affiche dans la console
            // Ou alors on fait quelque chose avec cette ligne
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    cout<<"Ce fichier contient  "<<nbrlignes<<" etudiant(s)"<<endl;
	fichier.close();
}

void Etudiant::stocker(string **s,int l)
{

    string ligne;
    ifstream fichier ("C:/Users/Othman/Desktop/testtt.xls") ;
    if(fichier)
    { 
       // while(!fichier.eof()) // Tant qu'on n'est pas à la fin, on lit
        for(int i=0;i<l;i++)
        {
		          for(int j=0;j<7;j++)
                {
        	           fichier>>ligne;
        	          // cout<<ligne<<" ";
                       s[i][j]=ligne;
	        	}
		}  
    }
    else
    {
        cout << "ERREUR" << endl;
    }
	fichier.close();
}


void Etudiant::remplir_excel(string **s,int l )
{
	ofstream fexcel("C:/Users/Othman/Desktop/testtt.xls",ios::trunc);
	for(int i=0; i<l; i++)
	 {
		for(int j=0; j<7; j++)
		 {
			fexcel<<s[i][j]<<"\t\t";
		 }
		fexcel<<endl;
    }
}
// cette fonction permet de testet si un etudiant existe ou pas et aussi de retourner l'indice de la ligne dont trouve l'etudiant
int Etudiant::Rechercher(string **s,int l)
{   int indice;
	string nom1,prenom1;bool b=false;
	cout<<"Entrer le nom de l'etudiant:       ";cin>>nom1;
	cout<<"Entrer le prenom de l'etudiant:    ";cin>>prenom1;
    ifstream fexcel;
	fexcel.open("C:/Users/Othman/Desktop/testtt.xls");  
	    for(int i=0;i<l;i++)
	    {
	    	if(s[i][0]==nom1 && s[i][1]==prenom1)  
			{
				b=true;
				indice=i;
			}
	    }
if(b==true)  
            {
                  return indice;
			}
else return 0; 
}

int Etudiant::Rechercherr(string **s,int l,string nom,string prenom)
{   int indice;
	bool b=false;
    ifstream fexcel;
	fexcel.open("C:/Users/Othman/Desktop/testtt.xls");  
	    for(int i=0;i<l;i++)
	    {
	    	if(s[i][0]==nom && s[i][1]==prenom)  
			{
				b=true;
			}
	    }
if(b==true)  return 1;
else return 0; 
}

void Etudiant::modifier(string **s,int l,string in1,string in2,string out)
{

	float tab[5];int ch=1;bool b=false;
 do{
  
	cout<<"Entrer le nom : ";cin>>in1;
	cout<<"Entrer le prenom : ";cin>>in2;
	
	 if(Rechercherr(s,l,in1,in2)==0)  
	    { 
	        cout<<"Verification ";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<"."<<endl; Sleep(1500);
		    cout<<"L'etudiant :  "<<in1<<" "<<in2<<"  n'existe pas !!!"<<endl;Sleep(2000);
		    cout<<"Veuillez Entrer un autre etudiant s'il vous plait "<<endl;Sleep(2000);
		}
	 }while(Rechercherr(s,l,in1,in2)==0)	;
	 
	 	    cout<<"Verification ";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<".  "; Sleep(1500);
	    cout<<"reussie"<<endl;Sleep(1500);
	    
	for(int i=1; i<l;i++)  
	{
		if(s[i][0]==in1 && s[i][1]==in2) 
		{
	                           cout<<"Qu'est ce que vous-voulez modifier ?"<<endl;
					           cout<<"\t\t1/ Le nom ."<<endl;
							   cout<<"\t\t2/ Le prenom ."<<endl;
	                           cout<<"\t\t3/ La note de controle continu ."<<endl;	
							   cout<<"\t\t4/ La note de travaux pratiques."<<endl;
							   cout<<"\t\t5/ La note de projet."<<endl;
							   cout<<"\t\t6/ La note d'examen ."<<endl;	
							   cout<<"-->Votre choix :";cin>>ch;
							   cout<<"Saisir le nouveau champs :";cin>>out;Sleep(2000);
							   switch(ch)
							   {
							   	            case 1   :cout<<"Le nom a ete modifie"<<endl;Sleep(2000);system("pause");break;
							   	            case 2   :cout<<"Le prenom a ete modifie"<<endl;Sleep(2000);system("pause");break;
							   	            case 3   :cout<<"La note de controle continu a ete modifie"<<endl;Sleep(2000);system("pause");break;
							   	            case 4   :cout<<"La note de travaux pratiques a ete modifie"<<endl;Sleep(2000);system("pause");break;
							   	            case 5   :cout<<"La note de projet a ete modifie"<<endl;Sleep(2000);system("pause");break;
							   	            case 6   : cout<<"La note d'examen a ete modifie"<<endl;Sleep(2000);system("pause");break;
							   }while(ch<1 || ch>6);
							    s[i][ch-1]=out;
		                    	if(ch==3 || ch==4||ch==5 ||ch==6 )  //Dans cette partie on va stocker les champs de type float dans tab
		                    	                                //pour les convertir en string afin qu'on puisse les utiliser.
								{
			                              	for(int k=0; k<5; k++)
							                {
			             	                 	stringstream geek(s[i][2+k]);  //pour commencer à remplir à partir notecc
			            	                 	geek>>tab[k];
			                              	}
			                	tab[4]=0.15*tab[0]+0.15*tab[1]+0.2*tab[2]+0.5*tab[3];
			                	stringstream SS;
		                    	SS<<tab[4];
		                    	s[i][6]=SS.str();
							
		                      	}
		    	b=true;                
		}
	
	} 
	
	if(b==false) 
	    {
            	cout<<"L'etudiant "<<in1<<" "<<in2<<" n'existe pas dans la liste"<<endl;
            	system("pause");
        }
}
void Etudiant::modifier_etu(string **s,int l) {
	string in1,in2,out;
	stocker(s,l);
	modifier(s,l,in1,in2,out);
	remplir_excel(s,l);
}

void Etudiant::supprimer(string **s,int l) 
{
	string nom,prenom;
  do{
  
	cout<<"Entrer le nom : ";cin>>nom;
	cout<<"Entrer le prenom : ";cin>>prenom;
	
	 if(Rechercherr(s,l,nom,prenom)==0)  
	    { 
	        cout<<"Verification ";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<"."<<endl; Sleep(1500);
		    cout<<"L'etudiant :  "<<nom<<" "<<prenom<<"  n'existe pas !!!"<<endl;Sleep(2000);
		    cout<<"Veuillez Entrer un autre etudiant s'il vous plait "<<endl;Sleep(2000);
		}
	 }while(Rechercherr(s,l,nom,prenom)==0)	;
	 
	 	    cout<<"verification ";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<".  "; Sleep(1500);
	    cout<<"reussie"<<endl;Sleep(1500);
	   

	for(int i=1; i<l-1;i++) 
	{
		if(s[i][0]==nom && s[i][1]==prenom) 
		{
			for(int j=0; j<7; j++)
		    {
				s[i][j]=s[i+1][j];
			}
		}
	}
	int taille=l-1;
	remplir_excel(s,taille);
	cout<<"L'etudiant "<<nom<<" "<<prenom<<" a ete supprime"<<endl;
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int main()
{   
    Etudiant e1;
    int choix,n,n1,reponse,indice,ch,nbr_etudiant,t;
    string test;
zzz:    n=e1.nbrlignes();
    
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------Bienvenue , ce programme est realise par Zakaria Mnah et encardre par M.Hicham El Ghennioui -------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    
	    
	//e1.init_excel();       si je veux creer un nouveau fichier excel   
	    
	string **s;
	s=new string*[n];
	
	for(int i=0;i<n;i++)
	{s[i]=new string[7];}
    e1.stocker(s,n);

zz:
	do{
	cout<<"********************"<<endl;
	cout<<"*****"<<" Menu G.E "<<"*****"<<endl;
	cout<<"********************"<<endl;
	cout<<"Quelle operation voulez vous effectuer ?"<<endl;
	cout<<"\t\t1- Ajouter un etudiant ."<<endl;
	cout<<"\t\t2- Modifier la note d'un etudiant ."<<endl;
	cout<<"\t\t3- Rechercher un etudiant ."<<endl;
	cout<<"\t\t4- Supprimer un etudiant ."<<endl;
	cout<<"\t\t5- Afficher la liste des etudiants ."<<endl;
	cout<<"\t\t6- vider l'ecran et revenir au menu principale ."<<endl;
	cout<<"\t\t7- Sortir ."<<endl;
	cout<<"-->Tapez le numero de votre choix : ";cin>>choix;cout<<endl;
    switch(choix)
	        {
                    case 1  :  e1.saisir(s,n);
									n=e1.nbrlignes();

			                     	s=new string*[n];
				                    for(int i=0; i<n; i++) 
									{
				                        s[i]=new string[7];
			                      	}
			                    	e1.stocker(s,n);//e1.affmat(s,n1);
			                    	
				               goto zz;
				    case 2  :  e1.modifier_etu(s,n);
					           goto zz;				              
				    case 3  :  indice=e1.Rechercher(s,n);
					           if(indice==0)
							   {cout<<"L'etudiant(e) n'existe pas dans le fichier"<<endl;Sleep(1000);  system("pause");goto zz;}
				               else
				               {
							    cout<<"Etudiant(e) trouve(e)"<<endl;
							    cout<<"Son indice : "<<indice<<endl;
				                Sleep(500);
				                	
								cout<<"Voulez-vous affichez ses notes?"<<endl;
							    cout<<"1:Oui\n";
	                            cout<<"2:Non\n";
	                            cout<<"Votre reponse:\t";
							    cin>>reponse;
							    if(reponse==1)
							    {
							             for(int jj=0;jj<4;jj++)
							            {
							            	cout<<s[0][jj]<<"\t\t";
							            }
										 for(int jj=4;jj<7;jj++)
							            {
							            	cout<<s[0][jj]<<"\t";
							            }
										cout<<endl;
				                         for(int jj=0;jj<7;jj++)
							            {
										cout<<s[indice][jj]<<"\t\t";
										}cout<<endl;Sleep(1000);  system("pause"); goto zz;
							    }        
							    else 
								   goto zz;
							    }
								  
				    case 4  : {
				    	                e1.supprimer(s,n);	
				    	                	n=e1.nbrlignes();

			                     	s=new string*[n];
				                    for(int i=0; i<n; i++) 
									{
				                        s[i]=new string[7];
			                      	}
			                    	e1.stocker(s,n);
				                 		goto zz;
				         	} 
				    
					case 5  :  e1.affmat(s,n);
					           cout<<endl;
					           Sleep(1000);
					           system("pause");
					           
					           goto zz;
					           break; 	   
							         
				    case 6  :  system("cls");goto zzz;
				    
				    case 7  :  goto z  ;
			        default :  
					           cout<<"Code incorrect!!!"<<endl;Sleep(1000);system("cls");
			}
    }while(choix<1 || choix>7);

 for (int i = 0; i < n; i++)
         delete[] s[i];
      delete[] s;
z:	{	
        cout<<"Fin de programme"<<endl;
		cout<<"Au revoir"<<endl;
    }
}
