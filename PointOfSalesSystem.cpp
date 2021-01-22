//  file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int ID/*ID card number of the customer*/, d1, d2, code;
    double price, quantity, pricetot, disc1, disc2;;
    double Total_Bill;//value after reducing all  the discount and adding tax
    double tax_rate, final_discount, sum;
    double Total_discount, price_discount, ac_discount;/*total sum of all price discount*//*disount of price*//*account type discount*/
    char item;//turning point value
    int num;//Lucky number
    int Random_num;//random number

    srand(time(0));//Random number generato
    Random_num = (rand() % 10) + 1;

    cout << "Enter the customer identification number : ";
    cin >> ID;
    d1 = ID / 1000;
    d2 = ID % 1000 / 100;
    code = (d1 * 10) + d2;
    do
    {
        cout << "Enter quantity : ";
        cin >> quantity;
        cout << "Enter price : ";
        cin >> price;
        pricetot = price * quantity;
        if (pricetot > 10000)//Total price discount
        {
            disc1 = pricetot * 10 / 100;
        }
        else if ((pricetot <= 10000) && (pricetot >= 5001))
        {
            disc1 = pricetot * 5 / 100;
        }
        else if ((pricetot <= 5000) && (pricetot >= 3001))
        {
            disc1 = pricetot * 3 / 100;
        }
        else if ((pricetot <= 3000) && (pricetot >= 2001))
        {
            disc1 = pricetot * 2 / 100;
        }
        if (quantity > 15) //Quantity discount
        {
            disc2 = pricetot * 3 / 100;
        }
        else if ((quantity <= 15) && (quantity >= 11))
        {
            disc2 = pricetot * 2 / 100;
        }
        else if ((quantity <= 10) && (quantity >= 6))
        {
            disc2 = 1 / 100;
        }
        price_discount = disc1 + disc2;
        Total_discount = Total_discount + price_discount;
        sum = sum + pricetot;

        cout << "Enter N to add next item : ";
        cin >> item;
    } while (item == 'N');

    Total_Bill = sum - Total_discount;
    cout << "Total Item Discount : " << Total_Bill << endl; //Memebrship code discount 
    if (code == 11)
    {
        ac_discount = Total_Bill * 10 / 100;
    }
    else if (code == 12)
    {
        ac_discount = Total_Bill * 5 / 100;
    }
    else if (code == 13)
    {
        ac_discount = Total_Bill * 3 / 100;
    }
    Total_Bill = Total_Bill - ac_discount;

    cout << "Total Bill after discounted price : " << Total_Bill << endl;//Calculating tax

    if (Total_Bill > 50000)
    {
        tax_rate = Total_Bill * 10 / 100;
    }
    else if (Total_Bill > 20000)
    {
        tax_rate = Total_Bill * 5 / 100;
    }
    else if (Total_Bill > 10000)
    {
        tax_rate = Total_Bill * 3 / 100;
    }
    Total_Bill = Total_Bill + tax_rate;

    cout << "Total bill after tax : " << Total_Bill << endl;
    if (Total_Bill > 10000)
    {
        
        cout << "Your lucky number is : " << Random_num << endl;//Lucky number Discount calcullation 
        if (Random_num == 7)
        {
            final_discount = Total_Bill * 30 / 100;
            cout << "Final Discount : " << final_discount << endl;
            Total_Bill = Total_Bill - final_discount;
            cout << "Final Bill value : " << Total_Bill << endl;
        }
        else
        {
            cout << "You loss try again" << endl;
        }
    }
    return 0;
}
