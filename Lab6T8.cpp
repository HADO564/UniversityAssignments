#include<iostream>
using namespace std;

bool solvable(int *, int, int, int, int);//function prototype
bool isdiv(int *prices, int length)//function that checks if the total of the art pieces
//values is dividable or not
{
    int total=0;
    for(int i =0; i<length;i++)
    {
        total+=prices[i];
    }
    if(total%2==0)//if the total is dividable
    {
        if(solvable(prices,length,0,total/2,0))//call the function 
        //to check if it is equally divisiable or not
        {
            cout<<"Bob gets the remainders"<<endl;//after all the function calls, person2
            //will get the remaining pieces
        }
        else
        {
            cout<<"Cannot be divided equally between two people"<<endl;
            //if it is not solvable, it can't be divided equally
            return false;
        }
    }
    else //if the sum isn't even, it can't be divided into 2 in the first
    // place
    {
        cout<<"Prices are indivisible"<<endl;
        return false;
    }
}


bool solvable(int *prices,int length,int a_half,int eq_div ,int curr_point)
{
    for(int i = curr_point; i<length;i++)//a_half stores the sum of Alice's share. Eq_div stores the price of half of the total.
    {
        int new_ahalf = a_half+prices[i];//add a piece to alice's share
        if(new_ahalf==eq_div)//if the price of the piece is equal to the half of the total
        {//means that the rest of the items should go to bob
            cout<<"Alice gets "<<prices[i]<<endl;
            return true;
        }//if the pointer exceeds from the length of the array
        //return false
        else if(curr_point>=length)
        {
            return false;
        }
        else if(new_ahalf<eq_div)//if alice's share is less than the total
        {
            if(solvable(prices,length,new_ahalf,eq_div,curr_point+1))//call function again, considering alice's share
            {
                cout<<"Alice gets "<<prices[i]<<endl;
                return true;
            }
        }
        new_ahalf-=prices[i];// if Alice's share exceeds the half price, remove current item from her share
        //and go back to calling recursive routine
    }
    return false;
    //this program checks if it is solvable. It will test all the variables in the array before making a decision.
    //however, if the half of the total price is achieved before all of the variables are tested,
    //it will unwind itself
}

int main()
{
    int array[] = {10, 15, 12, 18, 19, 17, 13, 35, 33};//data sets to test the code
    int array2[] ={2,20,13,6,9,3,1,15,6};
    isdiv(array, 9);
    cout << "Result for Array 2: " << endl;
    isdiv(array2, 9);


}