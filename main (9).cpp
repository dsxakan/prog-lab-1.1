#include <iostream>
#include <stdexcept>

class Drob
{
private:
    int ch; // Числитель дроби
    int zn; // Знаменатель дроби

public:
    Drob(int chVal = 0, int znVal = 1) : ch(chVal), zn(znVal)
    {
        if (znVal == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
    }

    Drob add(const Drob &dr) const // Метод сложения дробей
    {
        int newCh = ch * dr.zn + dr.ch * zn;
        int newZn = zn * dr.zn;
        return Drob(newCh, newZn);
    }

    Drob sub(const Drob &dr) const // Метод вычитания дробей
    {
        int newCh = ch * dr.zn - dr.ch * zn;
        int newZn = zn * dr.zn;
        return Drob(newCh, newZn);
    }

    Drob mul(const Drob &dr) const // Метод умножения дробей
    {
        int newCh = ch * dr.ch;
        int newZn = zn * dr.zn;
        return Drob(newCh, newZn);
    }

    Drob del(const Drob &dr) const // Метод деления дробей
    {
        if (dr.ch == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        int newCh = ch * dr.zn;
        int newZn = zn * dr.ch;
        return Drob(newCh, newZn);
    }

    friend std::ostream &operator<<(std::ostream &os, const Drob &dr); // Потоковый вывод дроби
    friend std::istream &operator>>(std::istream &is, Drob &dr);       // Потоковый ввод дроби
};

std::ostream &operator<<(std::ostream &os, const Drob &dr)
{
    os << dr.ch << '/' << dr.zn;
    return os;
}

std::istream &operator>>(std::istream &is, Drob &dr)
{
    char slash;
    is >> dr.ch >> slash >> dr.zn;
    if (dr.zn == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    return is;
}

int main()
{
    try
    {
        Drob a(3, 4);
        Drob b(1, 2);
        
        std::cout << "a + b = " << a.add(b) << std::endl;
        std::cout << "a - b = " << a.sub(b) << std::endl;
        std::cout << "a * b = " << a.mul(b) << std::endl;
        std::cout << "a / b = " << a.del(b) << std::endl;

        Drob c;
        std::cout << "Enter a fraction (e.g., 3/4): ";
        std::cin >> c;
        std::cout << "You entered: " << c << std::endl;
    }
    catch (const std::invalid_argument &ex)
    {
        std::cerr << "Invalid argument: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    return 0;
}
