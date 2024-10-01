#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int roll;
    public:
        void input(Student s[], int size){
            for(int i=0; i<size; ++i){
                cout<<"Enter Data of student - "<<(i+1)<<": ";
                cin>>s[i].roll>>s[i].name;
            }
    }
        void insertionSort(Student s[], int n){
            for(int i=1; i<=n; i++){
                int j=i-1;
                int key = s[i].roll;
                while(j>=0 && s[j].roll > key){
                    s[j+1].roll = s[j].roll;
                    j--;
                }
                s[j+1].roll = key;
            } 
        }
    
        void shellSort(Student s[], int n){
            int gap=n/2;
            while(gap>=1){
                for(int j=gap; j<n; j++){
                    for(int i=j-gap; i>=0;){
                        if(s[i+gap].roll > s[i].roll){
                            break;
                        }
                        else{
                            // Swap roll
                            int temp;
                            temp = s[i+gap].roll;
                            s[i+gap].roll = s[i].roll;
                            s[i].roll = temp;
                            
                            // Swap name
                            string tempo;
                            tempo = s[i+gap].name;
                            s[i+gap].name = s[i].name;
                            s[i].name = tempo;
                        }
                        i=i-gap;
                    }
                }
            gap = gap/2;
            }
        }
    
        void display(Student s[], int size){
            for(int i=0; i<size; ++i){
                cout<<"Data of student - "<<(i+1)<<": "<<s[i].roll<<" "<<s[i].name<<endl;
                }
        }    

};

int main(){
    Student s[3], x;
    int n=sizeof(s)/ sizeof(s[0]); 
    int choice;
    do{
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1:
                x.input(s,n); break;
            case 2:
                x.insertionSort(s,n); break;
            case 3:
                x.display(s,n); break;
            case 4:
                x.shellSort(s,n); break;
            default:
                cout<<"Exit or write correct choice: "<<endl;
        }
        } while(choice!=5);
        
        return 0;
}