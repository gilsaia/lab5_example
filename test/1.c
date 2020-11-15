int main(){
    int a;
    a=2020;//a=1500;
    /*
    a=3000;
    */
    if((a-2020)==0){
        printf("%d",a);
    }else{
        printf("%d",a%20);
    }
    while(a&&1){
        printf("%d",a);
        a=a/10;
    }
    return 0;
}