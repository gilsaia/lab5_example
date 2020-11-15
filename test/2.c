int main(){
    int a=1700;
    a=2020;//a=1500;
    /*
    a=3000;
    */
    int s[20],i=20;
    while(i-=1){
        scanf("%d",&s[i]);
        s[i]=s[i]+040-'a';
    }
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