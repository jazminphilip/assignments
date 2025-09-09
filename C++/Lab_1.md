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
cout <<"hey how much your balance is" << endl;
cin >> BALANCE;
cout <<"how many deposits you want to make? " << endl;
cin >> DEPOSITS;
cout <<"how many withdrawals you want to make?" << endl;
cin >> WITHDRAWALS;
    double FINAL_BALANCE = BALANCE + (DEPOSITS*x) - (WITHDRAWALS*y);
cout << "your new balance is: " << FINAL_BALANCE << endl;

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
cout << "lol you suck";

}
}
```

# Lab 1 B3
```c++
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
cout << fixed << setprecision(2);

int hours;
double gross;
double grossOVERTIME;

cout << "how many hours you work?" << endl;
cin >> hours;

if (hours < 40){
double gross = static_cast<double>(hours)*20;
cout << "your gross income is " << gross << endl;}

else {
double grossOVERTIME = (800 + (hours - 40)*30);
cout <<"your gross income is " << grossOVERTIME << endl;}
// i tried to make the if statement only affect gross depending on the hours but it didnt work so i 
// split it into gross and grossOVERTIME... i feel like i really can shorten it but it wouldnt work :(

 return 0;
}
```
