#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OkiDoki {
public:
    virtual string getName() const = 0;
    virtual unsigned short getSize(unsigned short size) const = 0;
    virtual unsigned short getPrise(unsigned short size) const = 0;
    virtual unsigned short incSalt(unsigned short quantity, unsigned short size) const = 0;
    virtual unsigned short incCheese(unsigned short quantity, unsigned short size) const = 0;
};

class Family : public OkiDoki {
public:
    string getName() const override {
        return "Семейная";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 420 * (1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class Original : public OkiDoki {
public:
    string getName() const override {
        return "Оригинальная";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 400*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class BarbecueChicken : public OkiDoki {
public:
    string getName() const override {
        return "Курочка барбекю";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 420*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class Vegan : public OkiDoki {
public:
    string getName() const override {
        return "Вегетарианская";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 500*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class Seafood : public OkiDoki {
public:
    string getName() const override {
        return "С морепродуктами";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 600*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class Mexican : public OkiDoki {
public:
    string getName() const override {
        return "Месиканская";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 450*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class Russian : public OkiDoki {
public:
    string getName() const override {
        return "Русская";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 400*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class Meat : public OkiDoki {
public:
    string getName() const override {
        return "Мясная";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 450*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class ThreeCheeses : public OkiDoki {
public:
    string getName() const override {
        return "Три сыра";
    }
    unsigned short getSize(unsigned short size) const override {
        return size;
    }
    unsigned short getPrise (unsigned short size) const override {
        return 350*(1 + size/100);
    }
    unsigned short incSalt(unsigned short quantity, unsigned short size) const override {
        return  quantity * (size/5);
    }
    unsigned short incCheese(unsigned short quantity, unsigned short size) const override {
        return quantity * size;
    }
};

class PizzaOrder {
    vector<const OkiDoki *> Pizza;
    unsigned short TotalPrise = 0, salt = 0, cheese = 0;
    unsigned short PizzaSize = 25;
    unsigned short PriseSumm[20];
public:
    void add(const OkiDoki *pizza) {
        Pizza.push_back(pizza);
    }
    void print() {
        size_t size = Pizza.size();

        if (size == 0) {
            cout << "Вы ничего не заказали";
        }
        else{
            for (size_t i = 0; i < size; i++) {
                cout << "\nУточнение для заказа номер " << i+1 << ":" << endl;
                cout << "Введите размер пиццы (25, 30, 35): ";
                cin >> PizzaSize;
                cout << "\nСколько раз хотите добавить соли? ";
                cin >> salt;
                cout << "\nСколько раз хотите добавить сыра? ";
                cin >> cheese;
                PriseSumm[i] = Pizza[i]->getPrise(PizzaSize) + Pizza[i]->incSalt(salt, PizzaSize) + Pizza[i]->incCheese(cheese, PizzaSize);
                cout << "\nВаш заказ:\n " << Pizza[i]->getName() << " - " << Pizza[i]->getPrise(PizzaSize) << "р." << endl;
                cout << "Количество добавленной соли: " << salt << " - " << Pizza[i]->incSalt(salt, PizzaSize) << "р." << endl;
                cout << "Количество добавленного сыра: " << cheese << " - " << Pizza[i]->incCheese(cheese, PizzaSize) << "р." << endl;
                cout << "Общая сумма за данную пиццу: " << PriseSumm[i] << "р." << endl;
                TotalPrise += PriseSumm[i];
            }
        }
        cout << "\nИтого: " << TotalPrise << "р.";
    }
};

int main() {
    PizzaOrder MyOrder;
    short choice = -1;

    cout << "Меню:" << endl;
    cout << "1. Семейная. Состав: солёные огурчики, колбаса, яйцо, сыр, сладкий перец" << endl;
    cout << "2. Оригинальная. Состав: курица, сыр, помидоры" << endl;
    cout << "3. Курочка барбекю. Состав: курица, сыр, соус барбекю, острый перец" << endl;
    cout << "4. Вегетарианская. Состав: сладкий перец, помидоры, шампиньоны, горошек, оливки" << endl;
    cout << "5. С морепродуктами. Состав: креветки, мидии, крабовые палочки, помидоры, перец" << endl;
    cout << "6. Мексиканская. Состав: салями, очень острый перец, помидоры, сыр, оливки" << endl;
    cout << "7. Русская. Состав: колбаса, шампиньоны, российский сыр, помидоры, перец" << endl;
    cout << "8. Мясная. Состав: мясной фарш, сыр, помидоры, перец" << endl;
    cout << "9. Три сыра. Состав: моцарелла, чеддер, ламбер." << endl;

    do {
        cout << "\nВведите номер пицц которые хотите заказать. Если хотите закончить выбирать пиццы - введите '0'. ";
        cin >> choice;
        switch (choice) {
            case 1:
                MyOrder.add(new Family()); break;
            case 2:
                MyOrder.add(new Original()); break;
            case 3:
                MyOrder.add(new BarbecueChicken()); break;
            case 4:
                MyOrder.add(new Vegan()); break;
            case 5:
                MyOrder.add(new Seafood()); break;
            case 6:
                MyOrder.add(new Mexican()); break;
            case 7:
                MyOrder.add(new Russian()); break;
            case 8:
                MyOrder.add(new Meat()); break;
            case 9:
                MyOrder.add(new ThreeCheeses()); break;
        }
    }
    while (choice > 0);

    MyOrder.print();
}