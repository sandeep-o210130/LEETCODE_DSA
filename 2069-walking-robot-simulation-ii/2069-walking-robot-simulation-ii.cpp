class Robot {
public:
    int x,y,dir,a,b,c=0;
    Robot(int width, int height) {
        x=0;
        y=0;
        dir=0;
        a=width;
        b=height;
    }
    
    void step(int num) {
        c++;
        int lenn = 2*(a+b)-4;
        num = num%lenn;
        while(num!=0){
        if(dir==0){
            x=x+num;
            if(x>=a){
                num = x-a+1;
                x=x-num;
                dir=(dir+1)%4;
            }
            else num=0;
        }
        else if(dir==1){
            y=y+num;
            if(y>=b){
                num = y-b+1;
                y=y-num;
                dir=(dir+1)%4;
            }
            else num=0;
        }
        else if(dir==2){
            x=x-num;
            if(x<0){
                num = 0-x;
                x=0;
                dir=(dir+1)%4;
            }
            else num=0;
        }
        else if(dir==3){
            y=y-num;
            if(y<0){
                num = 0-y;
                y=0;
                dir=(dir+1)%4;
            }
            else num=0;
        }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir==0){
            if(x==0 && y==0 && c) return "South";
            else return "East";
        }
        else if(dir==1) return "North";
        else if(dir==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */