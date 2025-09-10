# Lab 1 A1
```c++
#include <iostream>
using namespace std;
int main()
{
double a;
double b;
double c;
cout <<"enter values for a, b, and c " << endl;
cin >> a >> b >> c;

cout <<"the value of x+y*z is " << a+b*c << endl;
cout <<"the value of (a + b) * c is " << (a + b) * c << endl;
cout <<"the value of a / b * c is " << a / b * c << endl;
cout <<"the value of a / (b * c) is " << a / (b * c) << endl;

return 0;
}
```

# Lab 1 A2
```c++
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double BALANCE=0;
    int DEPOSITS=0; 
    int WITHDRAWALS=0;
    double x = 25.50;
    double y = 12.75;
    
cout << fixed << setprecision(2);
cout <<"how much is your balance " << endl;
cin >> BALANCE;
cout <<"how many deposits you want to make? " << endl;
cin >> DEPOSITS;
cout <<"how many withdrawals you want to make?" << endl;
cin >> WITHDRAWALS;
    double FINAL_BALANCE = BALANCE + (DEPOSITS*x) - (WITHDRAWALS*y);
cout << "your new balance is: " << FINAL_BALANCE << endl;
return 0;
}
```

# Lab 1 B1
```c++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int x=0;
int y=0;
int z=0;
cout << fixed << setprecision(15);

cout << "give me 3 numbers, ill average them for you" << endl;
cin >> x >> y >> z;

int sum = x + y + z;

double w = static_cast<double>(sum) / 3;

cout <<"your average is " << w ;

return 0;
}
```

# Lab 1 B2
```c++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    int games = 0;
    int wins = 0;
    
cout << fixed << setprecision(1);  
cout << "how many games did you play?" << endl;
cin >> games;
if (games == 0)
{
    cout << "no games played" << endl;
}
else {


cout <<"how many did you win?" << endl;
cin >> wins;

double winrate = static_cast<double>(wins)/static_cast<double>(games)*100; 
cout << "your win percentage is " << winrate << "%" << endl;

if (wins == 0)
{
cout << "no wins";

}
return 0;
}
```

# Lab 1 C
```c++
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
cout << fixed << setprecision(2);

int hours;
double gross;
double taxes;
double takehomepay;

cout << "how many hours you work?" << endl;
cin >> hours;

if (hours < 40){
    gross = static_cast<double>(hours)*20;
    cout << "regular hour pay is $" << static_cast<double>(hours)*20 << "\n";
    cout << "overtime hour pay is $0.00" << "\n";}
else {
    gross = (800 + (static_cast<double>(hours) - 40)*30);
cout<<"regular hour pay is $800.00"<<endl;
cout<<"overtime hour pay is $" << (static_cast<double>(hours)-40)*30 << "\n";}
    taxes = (.18)*(gross);
    takehomepay = gross - taxes - 35;
cout << "your gross income is $" << gross << "\n";
cout << "you are taxed $" << taxes << "\n";
cout << "your benefits fee is $35.00" << "\n";
cout << "your net take home pay is $"<< takehomepay;
 return 0;
}
```
# Lab 1 D
```c++
#include <iostream>
#include <iomanip>
int main() {
    int items; double price;
    std::cout << "Enter items and price: ";
    std::cin >> items >> price;

    // BUG 1: uninitialized total
        //I changed what total was equal to from 0.0 to items * price
    double total = items * price; 

    // BUG 2: integer division
        //I changed the code to not need static cast and instead use implicit coercion
    int discountPercent = 15;
    double discount = total * (discountPercent / 100.0);

    // BUG 3: precedence & shipping
        //i replaced the if with an if else statement??? the bug is hard to see
    double afterDiscount = total - discount;
    double shipping;

    if (afterDiscount >= 100.0) {shipping = 0;}
    else {shipping =  5 + 2 * items;}



    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total: $" << total << "\n";
    std::cout << "Discount: $" << discount << "\n";
    std::cout << "Shipping: $" << shipping << "\n";
    std::cout << "Grand Total: $" << (afterDiscount + shipping) << "\n";
return 0;
}
```
