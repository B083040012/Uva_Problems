// 解法:
// *本題利用隨機增量法求解，最小外接圓必為vec個點中3(or2個)個點的外接圓，且最後可以包住全部vec個點
// (1) 將ans_cir(最小圓圓心)設為p_set[0]，將ans_r(最小圓半徑)設為0(以點p_set為圓心做圓)
// (2) 欲將第i(i:0~vec-1)個點加入現今最小圓:
//     (a1) 若p_set[i]在最小圓中，考慮第(i+1)個點:(a1)
//     (a2) 否則重畫最小圓(以p_set[i]為圓心(curr_cir)，0為半徑(curr_r))，並考慮p_set[j](j:0~i-1)是否在圓內:(b1)

//         (b1) 若p_set[j]在最小圓內，考慮第(k+1)個點:(b1)
//         (b2) 否則重畫最小圓(p_set[i],p_set[j]中點為圓心，中點到端點為半徑)，並考慮p_set[j](j:0~k-1)是否在圓內:(c1)

//             (c1) 若p_set[j]在最小圓內，考慮第(j+1)個點:(c1)
//             (c2) 否則重畫最小圓(p_set[i],p_set[k],p_set[j]三角形外心為原點，外心到端點距離為半徑)
        
//         -->b、c for迴圈必能找到一個涵蓋p_set[i],p_set[j=0~i-1],p_set[k=0~j-1]的外接圓-->存入ans_r、ans_cir
// (3) 最後若輸入半徑>=ans_r-->can packed，否則can't
// *外心計算參考:https://zhuanlan.zhihu.com/p/350624493

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct point{
    double x,y;
    point(double x,double y):x(x),y(y){};
};

double len(point p1,point p2){
    return sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
}

point middle(point p1,point p2){
    return point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
}

double cross_pro(point v1,point v2){
    return (v1.x*v2.y)-(v1.y*v2.x);
}

point cir(point p1,point p2,point p3){
    struct point m1(0,0),m2(0,0),v1((p1.y-p2.y),-(p1.x-p2.x)),v2((p3.y-p2.y),-(p3.x-p2.x));
    m1=middle(p1,p2);
    m2=middle(p2,p3);
    struct point temp(m2.x-m1.x,m2.y-m1.y);
    double t1=(cross_pro(temp,v2))/cross_pro(v1,v2);
    temp.x=m1.x+t1*v1.x;
    temp.y=m1.y+t1*v1.y;
    return temp;
}

int main(){
    int vec;
    while(cin >> vec){
        if(vec==0) return 0;
        vector<point> point_set;
        double radius;
        for(int i=0;i<vec;i++){
            int x,y;
            cin >> x >> y;
            struct point p(x,y);
            point_set.push_back(p);
        }
        // random_shuffle(point_set.begin(),point_set.end());
        struct point ans_cir=point_set[0],curr_cir(0,0);
        double ans_r=0,curr_r;
        cin >> radius;
        for(int i=1;i<vec;i++){
            if(len(point_set[i],ans_cir)<=ans_r) continue;
            curr_cir=point_set[i];
            curr_r=0;
            for(int j=0;j<=i-1;j++){
                // cout << point_set[j].x << " " << point_set[j].y << " " << curr_cir.x << " " << curr_cir.y << endl;
                if(len(point_set[j],curr_cir)<=ans_r) continue;
                curr_cir=middle(point_set[i],point_set[j]);
                curr_r=len(point_set[i],point_set[j])/2;
                // cout << "curr_r" << curr_r << endl;
                for(int k=0;k<=j-1;k++){
                    // cout << "in2\n";
                    if(len(point_set[k],curr_cir)<=ans_r) continue;
                    curr_cir=cir(point_set[i],point_set[j],point_set[k]);
                    curr_r=len(curr_cir,point_set[i]);
                }
            }
            ans_r=curr_r;
            ans_cir=curr_cir;
        }
        // cout << "ans=" << ans_r << endl;
        if(ans_r<=radius) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }    
}