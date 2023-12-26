#include <stdio.h>
#include <math.h>

class Vector{
    private :
        int x;
        int y;
    public :
        Vector(int x,int y){
            this->x = x;
            this->y = y;
        }
        int getX(){return x;}
        int getY(){return y;}
        static int l1Norm(Vector *x,Vector *y){
            return abs(x->x - y->x) + abs(x->y - y->y);
        }
        static Vector *toVector(int data,int size){
            return new Vector(data / size,data % size);
        }
        void write(){
            printf("%d : %d\n",x,y);
        }
};

class State{
    private :
        int size;
        int size2;
        int *data;
        int calculateHScoreOfItem(int index){
            return Vector::l1Norm(
                Vector::toVector(index,size),
                Vector::toVector(data[index],size)
            );
        }
    public :
        State(int size){
            this->size = size;
            size2 = size * size;
            data = (int *)malloc(sizeof(int) * size2);
        }
        int hScore(){
            int hScore = 0;
            for(int i = 0; i < size2;i++)
                hScore += calculateHScoreOfItem(i);
            return hScore;
        }
        void test(){
            data[0] = 7;
            data[1] = 2;
            data[2] = 4;
            data[3] = 5;
            data[4] = 0;
            data[5] = 6;
            data[6] = 8;
            data[7] = 3;
            data[8] = 1;
            printf("%d\n",hScore()); 
        }
};


int main(int argc, char const *argv[])
{
    Vector *s = Vector::toVector(7,3);
    Vector *i = Vector::toVector(0,3);
    int n = Vector::l1Norm(i,i);
    s->write();
    i->write();
    printf("%d\n",n);


    State *st = new State(3);
    st->test();
    return 0;
}
