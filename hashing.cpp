#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class HashFunctions
{
public:
    enum class hashFunctions
    {
        division,
        multiplication,
        midSquare,
        folding,
        universal
    };
    enum class colussionFunctions
    {
        seaprateChaning,
        openHasing,
        linearOpenAddressing,
        quadraticOpenAddressing,
        doubleOpenAdressing
    };
    vector<Node *> table;
    HashFunctions(int m = 0)
    {
        table = vector<Node *>(m);
    }
    int divisionHashFunction(int key, int size)
    {
        return (key % size);
    }
    int multiplicationHashFunction(int key, int size, float a = 0.618033)
    {
        return (size * (a * key - (a * key)));
    }
    int midSqureHashFunction(int value, int size)
    {
        value *= value;
        int index = 0, zeros = 1;
        if (value < 10)
            return value;

        value /= 10;
        if (value < 10)
            return value;
        while (value > 0 && index < size / 10)
        {
            index = ((value % 10) * zeros) + index;
            value /= 10;
            zeros *= 10;
        }
        return index % size;
    }
    int foldingHashFunction(int key, int size, bool isSimple = true)
    {
        int zeros = 1;
        int temp = 0;
        int digit = digitsFind(size);
        int index = 0;
        while (key > 0)
        {
            temp = (key % 10) * zeros + temp;
            if (temp >= (size / 10))
            {
                if (!isSimple && index != 0)
                {
                    temp = digitRevers(temp);
                    isSimple == false;
                }
                index += temp;
                zeros = 0.1;
                temp = 0;
            }
            zeros = (zeros == 0) ? 1 : zeros * 10;
            key /= 10;
        }
        index += temp;
        return index % size;
    }
    int universalHashFunction(int key, int size, const int primaryNumber = 10007, const int constA = 3, const int constB = 5)
    {
        return ((constA + key * constB) % primaryNumber) % size;
    }
    int creptographicHashFunction(int key, bool isEncription = true)
    {
        const int value = INT_MIN;
        if (isEncription)
            return value + key;
        else
            return key - value;
    }
    int digitsFind(int value)
    {
        int digits = 1;
        value = value / 10;
        while (value > 0)
        {
            digits *= 10;
            value = value / 10;
        }
        return digits;
    }
    int digitRevers(int value)
    {
        int result = 0;
        int zeros = 1;
        while (value > 0)
        {
            result = (result * zeros) + (value % 10);
            value /= 10;
            zeros = 10;
        }

        return result;
    }
    // this is serparteChaning and open hashing
    void seaprateChaning(int key, int data)
    {
        Node *head = table[key];
        while (head->next != nullptr)
        {
            head = head->next;
        }
        head->next = new Node(data);
    }
    void openHasing(int key, int data)
    {
        seaprateChaning(key, data);
    }
    // this is open addressing or closed hashing
    void linearOpenAddressingProbing(int key, int data)
    {
        for (int i = key; i < table.size(); i++)
        {
            if (table[i] != nullptr)
            {
                table[i] = new Node(data);
                return;
            }
        }
    }
    void quadraticOpenAddressingProbing(int key, int data, const int c1 = 0.5, const int c2 = 0.5)
    {
        int j = 1;
        for (int i = 0; i < table.size(); i++)
        {
            int value = (key + (c1 * i) + (c2 * (i * i))) % table.size();
            if (table[value] == nullptr)
            {
                table[value] = new Node(data);
                return;
            }
            else
            {
                j++;
            }
        }
    }
    void doubleOpenAdressingProbing(int key)
    {
        int m = table.size();
        int h1 = divisionHashFunction(key, m);
        int h2 = multiplicationHashFunction(key, m);
        int index = 0;
        for (int i = 0; table.size(); i++)
        {
            index = (h1 + i * h2) % m;
            if (table[index] == nullptr)
            {
                table[index] = new Node(key);
                return;
            }
        }
    }
};
class Hash : HashFunctions
{

    Hash(int m = 0) : HashFunctions(m)
    {
    }

public:
    int getSize()
    {
        return table.size();
    }
    void print()
    {
        for (int i = 0; i < table.size(); i++)
        {
            Node *head = table[i];
            do
            {
                cout << "i = " << i << " value = " << head->data << " ";
                head = head->next;
            } while (head != nullptr);
            cout << endl;
        }
    }
};