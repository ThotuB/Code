#include <stdio.h>
#include <math.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

float fast_invsqrt(float x){
    long y_long;
    float y;

    y = x;

    y_long = * (long *) &y;
    y_long = 0x5f3759df - ( y_long >> 1 );

    y = * (float *) &y_long;

    return y;
}

float newton_approx(float number){
    float halfnumber = number * 0.5F;
    const float threehalfs = 1.5F;

    return number * ( threehalfs - ( halfnumber * number * number ));
}

int main(){
    printf("x\t\tBit Hack\tERROR 1\t\tNewton Approx\tERROR 2\t\tSolution\n");
    for (float x = 100 ; x <= 10000 ; x += 100){
        float y1 = fast_invsqrt(x);
        float y2 = newton_approx(y1);
        float y = 1/sqrt(x);

        printf("%5.0f\t\t"          , x             );
        printf("%f\t"               , y1            );
        printf(RED "%f\t" RESET     , fabs(y-y1)    );
        printf("%f\t"               , y2            );
        printf(RED "%f\t" RESET     , fabs(y-y2)    );
        printf(GREEN "%f\n" RESET   , y             );
    }
}

