#include<bits/stdc++.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>



using namespace std;

struct foo{
    int a;
    float f;
    char c;
};

void printfoo(foo* f){

    cout<<"Foo.a = "<<f->a<<endl;
    cout<<"Foo.f = "<<f->f<<endl;
    cout<<"Foo.c = "<<f->c<<endl;
}

void* thd_fn(void* arg)
{
    foo *f = (foo*)arg;
    //cout<<" Hey !! "<<(char*)arg<<endl;
    cout<<"Printing from new thread :"<<endl;
    printfoo(f);
    pthread_exit((void*)f);
}



int main(){

   pthread_t ptid;

    struct foo *f = new foo();
    f->a=10;
    f->f=20.5;
    f->c='A';
    pthread_create(&ptid,NULL,thd_fn,(void*)f);
    sleep(2);
    
    void* foo;
    pthread_join(ptid, &foo);
    cout<<"Printing from Main thread  :"<<endl;
    printfoo((struct foo*)foo);
    exit(0);

return 0;
}
