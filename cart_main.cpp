#include "datamodel.h"

vector<Product> allProducts = {
    Product(1, "Apple", 200),
    Product(3, "Mango", 80),
    Product(2, "Guava", 70),
    Product(5, "Banana", 40),
    Product(4, "Strawberry", 120),
    Product(6, "Pineapple", 100),
    Product(7, "Orange", 40),
    Product(8, "Litchi", 140)};

Product *chooseProduct()
{
    // display the list of products
    string productList;
    cout << "Available Products : " << endl;
    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;

    cout << "---------------------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Item not found !!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
        return false;

    int total = cart.getTotal();
    cout << "Pay in Cash" << endl;

    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change " << paid - total << endl;
        cout << "Successfull Checkout \nThankYou for Shopping with us..." << endl;
        return true;
    }

    else
    {
        cout << "Not enough cash";
        return false;
    }
}
int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action - (a)dd item, (v)iew item, (c)heckout" << endl;
        cin >> action;

        if (action == 'a')
        {

            // view all products + choose product + add to cart
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the Cart " << product->getDisplayName();
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            // view the cart
            cout << "----------------------" << endl;
            cout << cart.viewCart() << endl;
            cout << "----------------------" << endl;
        }
        else
        {
            // checkout
            cart.viewCart();
            if (checkout(cart))
            {
                break;
            }
        }
    }

    return 0;
}