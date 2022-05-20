#include <iostream> 
#include <string>
#define SIZE 10
using namespace std;

//Cart.h

class Cart;


class Cart
{
private:
    string CartID;
    Outfit* outfit[SIZE];
    int quantity;


public:

    Cart(string	pCartID);
    void addOutfit(Outfit* O);
    void displayCart();
};
//Outfit.h

class Outfit;
class Outfit
{
private:
    string OutfitID;
    float price;
    Cart* Car;
public:
    Outfit(string pOutfitID, float pPrice, Cart* pCar);
    void displayOut();
};
//Outfit.cpp

Outfit::Outfit(string pOutfitID, float pPrice, Cart* pCar)
{
    OutfitID = pOutfitID;
    price = pPrice;
    Car = pCar;
    Car->addOutfit(this);
}
void Outfit::displayOut()
{
    cout << " OutfitID : " << OutfitID << endl;
    cout << " price : " << price << endl;

}
//Cart.cpp

Cart::Cart(string	pCartID)
{
    CartID = pCartID;
    quantity = 0;
}
void Cart::addOutfit(Outfit* O)
{
    if (quantity < SIZE)
        outfit[quantity] = O;
    quantity++;
}
void Cart::displayCart()
{
    cout << " Cart ID : " << CartID << endl;
    cout << " Quantity : " << quantity << endl;
    for (int i = 0; i < quantity; i++)
        outfit[i]->displayOut();
}
int main()
{
    char ch;
    Cart* C1 = new Cart("123");
    Cart* C2 = new Cart("456");
    Outfit* O1 = new Outfit("001", 3450, C1);
    Outfit* O2 = new Outfit("002", 8500, C1);
    cout << "orders of" << endl;
    C1->displayCart();
    cin >> ch;
    return 0;
}