#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float function(float);
float function_derivative(float);
void newton_raphson_method(float,float);
void main()
{
    float allowed_error=0.0,seed_value;
    printf("Enter the seed value\n");
    scanf("%f",&seed_value);
    printf("Enter the allowed error\n");
    scanf("%f",&allowed_error);
    newton_raphson_method(seed_value,allowed_error);
}
void newton_raphson_method(float seed_value,float allowed_error)
{
    float value=seed_value;
    float h=-function(value)/function_derivative(value);
    for(;fabs(function(value))>=allowed_error;)
    {
      if(fabs(function_derivative(value))>=0.00000001)
            h=-function(value)/function_derivative(value);
          else
      {
          printf("Newton_raphson method fails\n");
          exit(0);
      } 
      value=value+h;
    }
    printf("Root value is %f\n",value);
    printf("functional value: f(%f)=%f",value,function(value));

}
float function(float value)
{
  return (value*value*value-2);
}
float function_derivative(float value)
{
    return (3*value*value);
}
