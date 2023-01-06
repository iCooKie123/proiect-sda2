#include <iostream>
#include <string>
#include <cstring>
using namespace std;


struct student {
    int id;
    char prenume[15];
    char nume[15];
    float medie[5];
    int nr_restante[4];
    student* next;
};

bool verif_existenta(student *cap, int id_dat){
    student *curent;
    if(cap==NULL){
        return false;
    }else{
        curent=cap;
        while(curent!=NULL){
            if(curent->id==id_dat){
                return true;
            }
            curent=curent->next;
        }
        return false;
    }
}

void parcurgere_totala(student *cap){
  student *curent;
  if(cap==NULL){
    cout<<"Lista este vida!"<<endl;
  }else{
    curent=cap;
    while(curent!=NULL){
      cout << curent->id << " " << curent->prenume << " " << curent->nume << " ";
      for (int i = 0; i < 5; i++) {
        cout << curent->medie[i] << " ";
      }
      for (int i = 0; i < 4; i++) {
        cout << curent->nr_restante[i] << " ";
      }
      cout << endl<<endl;
      curent=curent->next;
    }
  }
}

void afisare_dupa_id(student *cap){
  student *curent;
  int id_dat;
  cout<<"Introduceti id-ul studentului pe care vreti sa il afisati: ";
  cin>>id_dat;
  cout<<endl;
  if(cap==NULL){
    cout<<"Lista este vida!"<<endl;
  }else if (verif_existenta(cap,id_dat)==false){
    cout<<"Studentul cu id-ul "<<id_dat<<" nu exista in lista!"<<endl;
  }
  
  else{
    curent=cap;
    while(curent!=NULL){
      if(curent->id==id_dat){
        cout << curent->id << " " << curent->prenume << " " << curent->nume << " ";
        for (int i = 0; i < 5; i++) {
          cout << curent->medie[i] << " ";
        }
        for (int i = 0; i < 4; i++) {
          cout << curent->nr_restante[i] << " ";
        }
        cout << endl<<endl;
      }
      curent=curent->next;
    }
  }
}

student* adaugare_student(student *cap){
    student *curent;
  student *nou;
  int id_dat;
  
  
    curent=cap;
    cout<<"Introduceti id-ul studentului: ";
    cin>>id_dat;
    if(verif_existenta(cap,id_dat)==true){
      cout<<"Studentul cu id-ul "<<id_dat<<" exista deja in lista!"<<endl<<endl;
    }else{
        while(curent->next!=NULL){
            curent=curent->next;
        }
      nou=new student;
      nou->id=id_dat;
      cout<<"Introduceti prenumele studentului: ";
      cin>>nou->prenume;
      cout<<"Introduceti numele studentului: ";
      cin>>nou->nume;
      cout<<"Introduceti mediile studentului: ";
      for(int i=0;i<5;i++){
        cin>>nou->medie[i];
      }
      cout<<"Introduceti numarul de restante al studentului: ";
      for(int i=0;i<4;i++){
        cin>>nou->nr_restante[i];
      }
      nou->next=NULL;
      curent->next=nou;
    }
  cout<<endl<<endl;
  cap=curent;
  return cap;
}

student* modificare_medie(student*cap){

    student *curent;
    int id_dat;
    int nr_materie;
    float medie_noua;
    curent=cap;
    cout<<"Introduceti id-ul studentului: ";
    cin>>id_dat;
    if(verif_existenta(cap,id_dat)==false){
      cout<<"Studentul cu id-ul "<<id_dat<<" nu exista in lista!"<<endl;
    }else{
        while(curent->id!=id_dat){
            curent=curent->next;
        }
        cout<<"Introduceti numarul materiei: ";
        cin>>nr_materie;
        cout<<"Introduceti noua medie: ";
        cin>>medie_noua;
        curent->medie[nr_materie-1]=medie_noua;
    }
    cap=curent;
    return cap;
}

student* modificare_restante(student* cap){
    student *curent;
    int id_dat;
    int nr_materie;
    int nr_restante_nou;
    curent=cap;
    cout<<"Introduceti id-ul studentului: ";
    cin>>id_dat;
    if(verif_existenta(cap,id_dat)==false){
      cout<<"Studentul cu id-ul "<<id_dat<<" nu exista in lista!"<<endl;
    }else{
        while(curent->id!=id_dat){
            curent=curent->next;
        }
        cout<<"Introduceti numarul materiei: ";
        cin>>nr_materie;
        cout<<"Introduceti numarul de restante: ";
        cin>>nr_restante_nou;
        curent->nr_restante[nr_materie-1]=nr_restante_nou;
    }
    cap=curent;
    return cap;
}

student* stergere_student(student* cap){
    student *curent;
    student *aux;
    int id_dat;
    curent=cap;
    cout<<"Introduceti id-ul studentului: ";
    cin>>id_dat;
    if(verif_existenta(cap,id_dat)==false){
      cout<<"Studentul cu id-ul "<<id_dat<<" nu exista in lista!"<<endl;
    }else{
        while(curent->id!=id_dat){
            aux=curent;
            curent=curent->next;
        }
        aux->next=curent->next;
        delete curent;
    }
    cap=aux;
    return cap;
}

student* modificare_nume(student* cap){
    student *curent;
    int id_dat;
    char nume_nou[20];
    curent=cap;
    cout<<"Introduceti id-ul studentului: ";
    cin>>id_dat;
    if(verif_existenta(cap,id_dat)==false){
      cout<<"Studentul cu id-ul "<<id_dat<<" nu exista in lista!"<<endl;
    }else{
        while(curent->id!=id_dat){
            curent=curent->next;
        }
        cout<<"Introduceti numele nou: ";
        cin>>nume_nou;
        strcpy(curent->nume,nume_nou);
    }
    cap=curent;
    return cap;
}

student* modificare_prenume(student* cap){
    student *curent;
    int id_dat;
    char prenume_nou[20];
    curent=cap;
    cout<<"Introduceti id-ul studentului: ";
    cin>>id_dat;
    if(verif_existenta(cap,id_dat)==false){
      cout<<"Studentul cu id-ul "<<id_dat<<" nu exista in lista!"<<endl;
    }else{
        while(curent->id!=id_dat){
            curent=curent->next;
        }
        cout<<"Introduceti prenumele nou: ";
        cin>>prenume_nou;
        strcpy(curent->prenume,prenume_nou);
    }
    cap=curent;
    return cap;
}

student* modificare_student(student* cap){
    int optiune;
    cout<<"Ce doriti sa modificati?"<<endl;
    cout<<"1. Nume"<<endl;
    cout<<"2. Prenume"<<endl;
    cout<<"3. Medie"<<endl;
    cout<<"4. Numar de restante"<<endl;
    cout<<"5. Inapoi"<<endl;
    cout<<"Optiunea dumneavoastra: ";
    cin>>optiune;
    switch(optiune){
        case 1: cap=modificare_nume(cap);
                break;
        case 2: cap=modificare_prenume(cap);
                break;
        case 3: cap=modificare_medie(cap);
                break;
        case 4: cap=modificare_restante(cap);
                break;
        case 5: break;
        default: cout<<"Optiunea nu exista!"<<endl;
    }
    return cap;
}

int main(){

    //initializare student 1 arbitrar
    student *cap = NULL;
    student *s1 = new student;
    s1->id=1;
    strcpy(s1->prenume,"Ion");
    strcpy(s1->nume,"Popescu");
    s1->medie[0]=9.5;
    s1->medie[1]=9.5;
    s1->medie[2]=9.5;
    s1->medie[3]=9.5;
    s1->medie[4]=9.5;
    s1->nr_restante[0]=0;
    s1->nr_restante[1]=0;
    s1->nr_restante[2]=0;
    s1->nr_restante[3]=0;
    s1->next=NULL;
    cap=s1;

    //program principal
    int optiune;
    do{
        cout<<"Ce doriti sa faceti?"<<endl;
        cout<<"1. Adaugare student"<<endl;
        cout<<"2. Afisare studenti"<<endl;
        cout<<"3. Modificare student"<<endl;
        cout<<"4. Stergere student"<<endl;
        cout<<"5. Afisare student dupa id"<<endl;
        cout<<"6. Iesire"<<endl;
        cout<<"Optiunea dumneavoastra: ";
        cin>>optiune;
        switch(optiune){
            case 1: cap=adaugare_student(cap);
                    break;
            case 2: parcurgere_totala(cap);
                    break;
            case 3: cap=modificare_student(cap);
                    break;
            case 4: cap=stergere_student(cap);
                    break;
            case 5: afisare_dupa_id(cap);
                    break;
            case 6: cout<<"La revedere!"<<endl;
                    break;
            default: cout<<"Optiunea nu exista!"<<endl;
        cout<<endl;
        }
}while (optiune!=6);
    return 0;

}