int fun(int t){
    int a=-2;
    int i=10;
    while(t-=1){
        a=a-i;
        i=i-t;
        if(t<2){
            break;
        }
    }
    return a;
}
int main(){
    int a=1700,t='t';
    a=2020;//a=1500;
    /*
    a=3000;
    */
    int s[21],i=20;
    while(i-=1){
        scanf("%d",&s[i]);
        s[i]=s[i]+040-'a';
    }
    s[20]=fun(t);
    if((a-2020)==0){
        printf("%d",a);
    }else{
        printf("%d",a%0xff);
    }
    while(a&&1){
        printf("%d",a);
        a/=10;
    }
    return 0;
}