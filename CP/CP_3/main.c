#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double Func(double x){
    return ((3*x)-5)/(pow(x,2)-(4*x)+3);
}

double FuncTaylor(double x, unsigned p){
    return (-(1.0+(2.0/pow(3.0,p+1)))*pow(x,p));

}
void calculateTeylor(double a,double b, unsigned n, double (*Etalon)(double), double (*Taylor)(double, unsigned)){
    double x = a, i = 0, step, epsilon = 1e-7;
    step = (b - a) / n;
    printf("%.14f", epsilon);
    printf("\n=========================================================================\n");
    printf("|| step\t  x\t  FuncTeylor             Function                i      ||\n");
    printf("||----------------------------------------------------------------------||\n");
    n = 0;
    while (x <= 0.5){
        int i = 0;
        double currentValueFunc = Etalon(x);
        double currentValueFuncTaylor = Taylor(x,i);
        double currentValue = 0, difference = 0;
        do{
            currentValue += Taylor(x, i);
            i++;
            difference = currentValueFunc - currentValue;
        } while ((difference > epsilon || difference < -epsilon) && i < 100);
        printf("||  %d\t %.2f\t %.17f\t %.17f\t %d\t||\n", n, x, currentValue, currentValueFunc, i);
        x += step;
        n++;
    }
    printf("=========================================================================\n");
}

int main(){
    float a = 0.0, b = 0.5;
    int n = 0;
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    calculateTeylor(a, b, n, &Func, &FuncTaylor);
    return 0;
}
