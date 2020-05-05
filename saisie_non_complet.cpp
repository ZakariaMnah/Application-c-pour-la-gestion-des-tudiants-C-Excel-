
void Etudiant::saisir(string**s,int l)
{          
            ofstream fichier ("C:/Users/Othman/Desktop/testtt.xls",ios::app) ;
          	int nbr_etudiant;
          
            cout<<"combien d'etudiant voulez-vous saisir?\t";cin>>nbr_etudiant;
            
  aa:       bool b=false;
            ifstream fexcel;
            fexcel.open("C:/Users/Othman/Desktop/testtt.xls");  
            cout<<"entrer le nom :";
        	cin>>nom;
        	cout<<"entrer le prenom :";
         	cin>>prenom;


        	    for(int i=0;i<l;i++)
           {
                  {  if(s[i][0]==nom && s[i][1]==prenom)
                     b=true;
				  } 
           }
           cout<<"verification :"<<b<<endl;
        if(b==true) goto next;

        	     next: if(b==true)
					{     
                        Sleep(3000);cout<<"l'etudiant "<<nom<<" "<<prenom<<" est deja existe dans le fichier!!!"<<endl;Sleep(2500);
                        cout<<"veuillez rentrer un autre etudiant s'il vous plait."<<endl;Sleep(3000);goto aa;
	                }
                       
        	
        if(b==false)
    {
		 
             for(int i=0;i<nbr_etudiant;i++)
        {
        	
        fichier<<nom<<"\t";
        fichier<<prenom<<"\t";
        do{
         	cout<<"entrer la note du controle continu :";
        	cin>>notecc;
          }while(notecc<0 || notecc>20);	
        	fichier<<notecc<<"\t";
        //	ss[i][2]=notecc;
        
        do{	
           	cout<<"entrer la note du tp :";
          	cin>>notetp;
          }while(notetp<0 || notetp>20);	
          	fichier<<notetp<<"\t";
         //	ss[i][3]=notetp;
          
		do{  	
          	cout<<"entrer la note du projet :";
	        cin>>noteprojet;
	      }while(noteprojet<0 || noteprojet>20);	    
	        fichier<<noteprojet<<"\t";
	       // ss[i][4]=noteprojet;
	       
		do{    
	        cout<<"entrer la note d examen  :";
	        cin>>noteexam;
	      }while(noteexam<0 || noteexam>20);	    
	        fichier<<noteexam<<"\t";
	       // ss[i][5]=noteexam;
	        
	        
	        notef=0.15*notecc+0.15*noteprojet+0.2*notetp+0.5*noteexam;
	        fichier<<notef<<"\t"<<endl;
	        //ss[i][6]=notef;
	        Sleep(2000);cout<<"l'etudiant "<<nom<<" "<<prenom<<" a ete ajoute"<<endl;Sleep(2000);system("pause");goto aa;
	    }
	}

	        
fichier.close();
		
}
