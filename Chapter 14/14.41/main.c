/*Modify the program given in Example 6.22 (solution of an algebraic equation) so that flag is an enumeration
variable whose value is either true or false.*/

/* determine the roots of an algebraic equation using an iterative procedure */

#include <stdio.h>
#include <math.h>

int main( )
{
    /*count = an iteration counter (count will increase by 1 at each successive iteration)
      guess = the value of x substituted into the right-hand side of the equation
      root = the newly calculated value ofx
      test = the quantity (10 - 3x2)
      error = the absolute difference between root and guess
      flag = an integer variable that signifies whether or not to continue the iteration
      
      We will continue the computation until one of the following conditions is satisfied.
        1. The value of error becomes less than 0.00001, in which case we have obtained a satisfactory solution.
        2. Fifty iterations have been completed (i.e., count = 50).
        3. The variable test takes on a negative value, in which case the computation cannot be continued.
      
      See example 6.22 on page 142 for more info 
    */

    /*enam assigns values to identifiers starting with 0
    so false=0, true=1 which are int types
    can also do false=-3 in which case true=-2*/
    enum conditions {false, true}continue_iteration;     

    int flag = true, count = 0;
    float guess, root, test, error;

    /* read input parameters */    
    printf ("Initial guess:  ");
    scanf ( "%f", &guess);

    while(flag)
    { 
        /* begin the main loop */
        ++count ;
        if (count == 50) 
        {
            flag = false;            
        }
        test = 10. - 3. * guess * guess;

        /* another iteration */
        if (test > 0)                       
        { 
            root = pow(test, 0.2);
            printf("\nIteration number: %2d", count);
            printf ("x= %7.5f", root);
            error = fabs(root - guess);

            if (error > 0.00001)
            {
                /* repeat the calculation */
                guess = root; 
            } 
            else 
            { 
                /* display the final answer */
                flag = false;
                printf("\n\nRoot= %7.5f", root);
                printf ("No. of iterations= %2d", count);
            }
        }
        else 
        {
            /* error message */ 
            flag = false;
            printf ("\nNumbers out of range - try another initial guess");
        }
    }
    
    /* another error message */
    if ((count == 50) && (error > 0.00001)) 
    {
        printf("\n\nConvergence not obtained after 50 iterations");
    }
    
}