#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        int id;        
    public:
        void input(Employee e[], int F, int L){
            for(int i=0; i<(L+1); ++i){
                cout<<"Enter Data of employee - "<<(i+1)<<": ";
                cin>>e[i].id>>e[i].name;
            }
        }
        void quickSort(Employee e[], int F, int L){            
            if(F<L){
                int pivot = F;
                int i = F+1;
                int j = L;
                while(i<j){
                    while(i <= L && e[i].id < e[pivot].id){
                        i++;
                    }
                    while(j >= F && e[j].id > e[pivot].id){
                        j--;
                    }
                    if(i<j){
                        Employee t;
                        t = e[i];
                        e[i] = e[j];
                        e[j] = t;
                    }
                    else{
                        break;
                    }    
                }
                Employee t1;
                t1 = e[j];
                e[j] = e[pivot];
                e[pivot] = t1;

            quickSort(e,F,j-1);
            quickSort(e,j+1,L);
            }
        }        
        void display(Employee e[], int F, int L){
            for(int i=0; i<(L+1); ++i){
                cout<<"Data of employee - "<<(i+1)<<": "<<e[i].id<<" "<<e[i].name<<endl;
                }
        }    
};

int main(){
    Employee e[5], x;
    int n=sizeof(e)/ sizeof(e[0]); 
    int F=0;
    int L=(n-1);
    int choice;
    do{
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1:
                x.input(e,F,L); break;
            case 2:
                x.quickSort(e,F,L); break;
            case 3:
                x.display(e,F,L); break;
            case 4:
                cout<<"Exit";
            default:
                break;
        }
    } while(choice != 4);
        
}