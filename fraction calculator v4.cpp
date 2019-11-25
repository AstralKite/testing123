//
//  main.cpp
//  oop_book
//
//  Created by Administrator on 10/3/19.
//  Copyright © 2019 oop_book. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;


class fraction
{
    private:
        int numerator;
        int denominator;
    
    public:
        //constructor
        fraction(){}
        fraction(int n, int d): numerator(n), denominator(d){}
        //member functions
        void setNumerator(int n)
        {
            numerator = n;
        }
    
        void setDenominator(int n)
        {
            denominator = n;
        }
    
        int getNumerator()const
        {
         return numerator;
        }
    
        int getDenominator()const
        {
            return denominator;
        }
    
        void printFrac()const
        {
            cout << numerator << '/' << denominator;
        }
    
    
        int returnGCF(int *numArray, int *denArray, int numSIZE, int denSIZE)
        {
            int GCF = 0;
            int lookAt = 0;

            for(int i = 0; i<numSIZE; i++)
            {
                lookAt = numArray[i];
                for(int k = 0; k<denSIZE; k++)
                {
                    if( lookAt == denArray[k])
                    {
                        if(GCF < lookAt)
                        {
                            GCF = lookAt;
                        }
                    }
                }
            }// end for
           return GCF;
        }
    
    
        void simplify()
        {
            int MAX = numerator + 1;
            int numArray[MAX];
            int count = 0;
            int numerSIZE = 0;
            int denomSIZE = 0;
        
            //-------------------------------------------------{FIND NUMERATOR FACTOR}
            //loop to find factors for NUMERATOR
            for(int i = 1; i<MAX; i++)
            {
                if( (numerator % i) == 0 )
                {
                    numArray[count] = (numerator / i);
                    count++;
                    //cout << " " << (numerator / i) << "  ";
                    if( (numerator / i)==1 )
                        MAX = 0; // stops loop iteration when final factor is reached
                }
            }
            
            // loop to create final NUMERATOR factor array
            numerSIZE = count;
            int numArrayFinal[count];
            for(int i = 0; i<count; i++)
            {
                numArrayFinal[i] = numArray[i];
            }

            //-------------------------------------------------{FIND DENOMINATOR FACTOR}
            //reset Variables
            MAX = denominator + 1;
            int denArray[MAX];
            count = 0;
            
            for(int i = 1; i<MAX; i++)
            {
                if( (denominator % i) == 0 )
                {
                    denArray[count] = (denominator / i);
                    count++;
                    //cout << " " << (numerator / i) << "  ";
                    if( (denominator / i)==1 )
                        MAX = 0; // stops loop iteration when final factor is reached
                }
            }// end for
            
            // loop to create final NUMERATOR factor array
            denomSIZE = count;
            int denArrayFinal[count];
            for(int i = 0; i<count; i++)
            {
                denArrayFinal[i] = denArray[i];
            }
            
            int GCF = returnGCF(numArrayFinal, denArrayFinal, numerSIZE, denomSIZE);
            
            //cout << "GCF: " << GCF << endl;
            
            if(GCF > 0)
            {
                numerator = (numerator / GCF);
                denominator = (denominator / GCF);
            }
        }// end simplify()
};


//function declerations
fraction fadd(fraction frac1, fraction frac2);
fraction fsub(fraction frac1, fraction frac2);
fraction fmul(fraction frac1, fraction frac2);
fraction fdiv(fraction frac1, fraction frac2);
void doOperation(fraction frac1, char operand, fraction frac2, fraction fracResult);
void fractionTable(const int denominator);


//---------------------------------------------(MAIN)
int main(int argc, const char * argv[]) {

    // numbers
    //int a, b, c, d;
    //char opr, slash;
    int denominator = 0;
    char choice = 'y';
    fraction fracResult(3, 21);
    
    
    //fracResult.simplify();
    //fracResult.printFrac();
    

    do {
        //welcome user  ----------------- [SIMPLE FRACTION PROGRAM]
    /*
        cout << "\n\n****************\n";
        cout << "enter a fraction expression with ('+', '-', '*', '/')\n>> ";
        cin >> a >> slash >> b >> opr >> c >> slash >> d;
        fraction frac1(a, b), frac2(c, d);

        
        //run operation
        doOperation(frac1, opr, frac2, fracResult);
     
    */
    
        
    
        //welcome user ----------------- [CHART GENERATOR BASED ON DENOMINATOR]
        cout << "\n\n****************\n";
        cout << "enter denominator to make a chart\n>> ";
        cin >> denominator;
        
        //create chart
        fractionTable(denominator);
        
        //get user choice
        cout << "\n****************\n";
        cout << "\n\nWould you like to enter another fraction?\n('y' or 'n') >> ";
        cin >> choice;
    } while(choice != 'n');
    
    
    cout << "\n\n--Good bye--\n\n";
    return 0;
}//MAIN


void fractionTable(const int denominator)
{
    fraction fracArray[denominator];
    fraction fracResult;
    
    //create fractions
    for(int i = 0; i<denominator; i++)
    {
        fracArray[i].setNumerator( i+1 );
        fracArray[i].setDenominator(denominator);
    }
    
    //loop to create header
    int width = 8;
    cout << "\n\n";
    for(int i = 0; i<denominator-1; i++)
    {
        //simplify frac
        fracArray[i].simplify();
        cout << setw(width + 1) << fracArray[i].getNumerator() << '/' << fracArray[i].getDenominator();
    }
    
    

    //print divider
    cout << "\n---------------------------------";
    
    //double loop to create the chart
    width = 8;
    for(int i = 0; i<denominator-1; i++)
    {
        cout << endl;
        cout << fracArray[i].getNumerator() << '/' << fracArray[i].getDenominator();
        for(int k = 0; k<denominator-1; k++)
        {
            fracResult = fmul(fracArray[i], fracArray[k]);
            fracResult.simplify();
            cout << setw(width) << fracResult.getNumerator() << '/' << fracResult.getDenominator();
        }
    }

    
    //print divider
    cout << "\n---------------------------------";
}


void doOperation(fraction frac1, char operand, fraction frac2, fraction fracResult)
{
    switch(operand)
    {
        case '+': //------------------- [ADDITION]
            cout << "\naddition ANSWER\n";
            //cout << (a*d + b*c) << '/' << (b*d);
            fracResult = fadd(frac1, frac2);
            cout << fracResult.getNumerator() << '/' << fracResult.getDenominator();
            break;
            
        case '-': //------------------- [SUBTRACTION]
            cout << "\nsubtraction ANSWER\n";
            //cout << (a*d - b*c) << '/' << (b*d);
            fracResult = fsub(frac1, frac2);
            cout << fracResult.getNumerator() << '/' << fracResult.getDenominator();
            break;
            
        case '*': //------------------- [MULTIPLICATION]
            cout << "\nmultiplication ANSWER\n";
            //cout << (a*c) << '/' << (b*d);
            fracResult = fmul(frac1, frac2);
            cout << fracResult.getNumerator() << '/' << fracResult.getDenominator();
            break;
            
        case '/': //------------------- [DIVISON]
            cout << "\ndivision ANSWER\n";
            //cout << (a*d) << '/' << (b*c);
            fracResult = fdiv(frac1, frac2);
            cout << fracResult.getNumerator() << '/' << fracResult.getDenominator();
            break;
            
        default:
            cout << "invalid choice!\n";
            break;
    }// end switch
}

//-- ADDITION
fraction fadd(fraction frac1, fraction frac2)
{
    //cout << (a*d + b*c) << '/' << (b*d);
    fraction fracReturn;
    int numer = (frac1.getNumerator() * frac2.getDenominator() + frac1.getDenominator() * frac2.getNumerator());
    fracReturn.setNumerator(numer);
    
    int denom = (frac1.getDenominator() * frac2.getDenominator());
    fracReturn.setDenominator(denom);
    
    return fracReturn;
}

//-- SUBTRACTION
fraction fsub(fraction frac1, fraction frac2)
{
    //cout << (a*d - b*c) << '/' << (b*d);
    fraction fracReturn;
    int numer = (frac1.getNumerator() * frac2.getDenominator() - frac1.getDenominator() * frac2.getNumerator());
    fracReturn.setNumerator(numer);
    
    int denom = (frac1.getDenominator() * frac2.getDenominator());
    fracReturn.setDenominator(denom);
    
    return fracReturn;
}

//-- MULTIPLICATION
fraction fmul(fraction frac1, fraction frac2)
{
    // (a*c) << '/' << (b*d);
    fraction fracReturn;
    int numer = (frac1.getNumerator() * frac2.getNumerator());
    fracReturn.setNumerator(numer);
    
    int denom = (frac1.getDenominator() * frac2.getDenominator());
    fracReturn.setDenominator(denom);
    
    return fracReturn;
}


//-- DIVISON
fraction fdiv(fraction frac1, fraction frac2)
{
    // (a*d) << '/' << (b*c);
    fraction fracReturn;
    int numer = (frac1.getNumerator() * frac2.getDenominator());
    fracReturn.setNumerator(numer);
    
    int denom = (frac1.getDenominator() * frac2.getNumerator());
    fracReturn.setDenominator(denom);
    
    return fracReturn;
}
