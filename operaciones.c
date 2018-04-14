/** \brief Suma dos enteros
 *
 * \param n1 int Primer entero
 * \param n2 int Segundo entero
 * \param resultado float* Suma
 * \return int
 *
 */
int suma(int n1,int n2,float* resultado)
{
    *resultado=n1+n2;
    return 0;
}

/** \brief Resta dos enteros
 *
 * \param n1 int Primer entero
 * \param n2 int Segundo entero
 * \param resultado float* Resta
 * \return int
 *
 */
int resta(int n1,int n2,float* resultado)
{
    *resultado=n1-n2;
    return 0;
}

/** \brief Multiplica dos enteros
 *
 * \param n1 int Primer entero
 * \param n2 int Segundo entero
 * \param resultado float* Multiplicación
 * \return int
 *
 */
int multiplicacion(int n1,int n2,float* resultado)
{
    *resultado=n1*n2;
    return 0;
}

/** \brief Divide dos enteros
 *
 * \param n1 int Primer entero
 * \param n2 int Segundo entero
 * \param resultado float* División
 * \return int Devuelve -1 en caso de error
 *
 */
int division(int n1,int n2,float* resultado)
{
    float division;;
    if(n2==0) return -1;
    division=(float)n1/n2;
    *resultado=division;
    return 0;
}

/** \brief Calcula el factorial de un número entero
 *
 * \param n1 int Número a calcular
 * \param resultado float* Factorial
 * \return int Devuelve -1 en caso de error
 *
 */
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
