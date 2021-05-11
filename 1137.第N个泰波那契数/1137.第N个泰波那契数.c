int tribonacci(int n){
    int a[n+1];
    for(int i=0;i<=n;i++)
        {
          if(i==0)
             a[i]=0;
          else if(i==1||i==2)
                 a[i]=1;
               else
                 a[i]=a[i-1]+a[i-2]+a[i-3];
        }
    return a[n];  
}