#include<bits/stdc++.h>
using namespace std;

void autoStorageClass(){
    cout<<"***********************************************************************\n";
    // all the local variables that are declared in a block automatically belong to this class
    int a = 10;
    float b = 20.0;
    char c = 'T';
    char *d = &c;
    char* e = "This is string";

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<sizeof(d)<<'\n'; //pointers size = 8 bytes
    cout<<e<<'\t'<<sizeof(e)<<' '<<sizeof(*e)<<'\n'<<*e<<endl;
    cout<<"***********************************************************************\n";
}

int x; //Defined outside the block
void externalStorageClass(){
    extern int x; //telling compiler its defined outside.
    cout<<"x= "<<x<<endl;
    x = 10;
    cout<<"x= "<<x<<endl;
    cout<<"***********************************************************************\n";
}

int staticFun(){
    static int p = 10;
    p++;
    return p;
}
int nonStaticFun(){
    int p = 10;
    p++;
    return p;
}

void registerClass(){
    cout<<"***********************************************************************\n";
    // Register == auto variables.
    // The only difference is that the compiler tries to store these variables in the register 
    // of the microprocessor if a free register is available.
    register char p = '6';
    cout<<"Faster retrived value: "<<p<<endl;
    cout<<"***********************************************************************\n";
}

class mutableClassFun1{
    public:
    int x;
    mutable int y ;
    mutableClassFun1(){
        x = 12;
        y = 29;
    }       
};

class mutableClassFun2{
    int data;
    mutable int count;
    public:
       mutableClassFun2(int value):data(value),count(1024){}
       void display() const {
        cout<<"***********************************************************************\n";
        cout<<"Data: "<<data<<endl;
        // data = 256; Error: expression must be a modifiable lvalue.
        count+= 1024;
        cout<<"Count: "<<count<<endl;
        cout<<"***********************************************************************\n";
       }
};

thread_local int value = 10;

mutex mtx; //synchronization.

int main(){
    autoStorageClass();
    externalStorageClass();
    cout<<staticFun()<<' '<<staticFun()<<endl;
    cout<<nonStaticFun()<<' '<<nonStaticFun()<<endl;
    registerClass();

    const mutableClassFun1 obj ;
    // obj.x = 123; compile time ERROR!!
    cout<<obj.x<<endl;
    obj.y = 973;
    cout<<obj.y<<endl;

    mutableClassFun2 obj2(512);
    obj2.display();

// The thread_local variable can be combined with other storage specifiers like static or extern 
// and the properties of the thread_local object changes accordingly.

// Lifetime: Till the end of its thread
    thread th1([](){
        value += 18;
        lock_guard<mutex> lock(mtx);
        cout<<"Value of thread_local variable in thread1: "<<value<<endl;
    });
    thread th2([](){
        value += 28;
        lock_guard<mutex> lock(mtx);
        cout<<"Value of thread_local variable in thread2: "<<value<<endl;
    });
    thread th3([](){
        value += 38;
        lock_guard<mutex> lock(mtx);
        cout<<"Value of thread_local variable in thread3: "<<value<<endl;
    });

    th1.join();
    th2.join();
    th3.join();

    cout<<"Main function value: "<<value<<endl;

}