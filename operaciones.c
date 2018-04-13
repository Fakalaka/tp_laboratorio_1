int suma(int n1,int n2,float* resultado)
{
    *resultado=n1+n2;
    return 0;
}

int resta(int n1,int n2,float* resultado)
{
    *resultado=n1-n2;
    return 0;
}

int multiplicacion(int n1,int n2,float* resultado)
{
    *resultado=n1*n2;
    return 0;
}

int division(int n1,int n2,float* resultado)
{
    float division;;
    if(n2==0) return -1;
    division=(float)n1/n2;
    *resultado=division;
    return 0;
}

int factorial(int n1,float*resultado)
{
    if(n1<0||n1>=35) return -1;
    *resultado=n1;
    do{
        if(n1<2){
            *resultado=1;
        }
        else{
            *resultado*=(n1-1);
        }
    n1--;
    }while(n1>1);
    return 0;
}
