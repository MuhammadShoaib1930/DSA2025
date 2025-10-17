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
    vector<Node *> table;
    int hashFunctionSelected;
    int clousisonSelected;
    int size = table.size();
    HashFunctions(int m = 0, int hash = 0, int clos = 0)
    {
        table = vector<Node *>(m, nullptr);
        hashFunctionSelected = hash;
        clousisonSelected = clos;
    }
    int divisionHashFunction(int key)
    {
        return (key % table.size());
    }
    int multiplicationHashFunction(int key, float a = 0.618033)
    {
        return (size * (a * key - (a * key)));
    }
    int midSqureHashFunction(int value)
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
    int foldingHashFunction(int key, bool isSimple = true)
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
    int universalHashFunction(int key, const int primaryNumber = 10007, const int constA = 3, const int constB = 5)
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
    Node *seaprateChaning(int key, int data, bool isNotDelete = true)
    {
        if (isNotDelete)
        {
            Node *head = table[key];
            while (head->next != nullptr)
            {
                head = head->next;
            }
            head->next = new Node(data);
            return head;
        }
        else
        {
            Node *head = table[key];
            if (head->data == data)
            {
                table[key] = head->next;
                head = nullptr;
            }
            do
            {
                if (head->next->data == data)
                {
                    head = head->next;
                    head = nullptr;
                    return nullptr;
                }
            } while (head != nullptr);
        }
        return nullptr;
    }
    Node *openHasing(int key, int data, bool isNotDelete)
    {
        return seaprateChaning(key, data, isNotDelete);
    }
    // this is open addressing or closed hashing
    Node *linearOpenAddressingProbing(int key, int data)
    {
        for (int i = key; i < table.size(); i++)
        {
            if (table[i] != nullptr)
            {
                table[i] = new Node(data);
                return table[i];
            }
        }
        return nullptr;
    }
    Node *quadraticOpenAddressingProbing(int key, int data, const int c1 = 0.5, const int c2 = 0.5)
    {
        int j = 1;
        for (int i = 0; i < table.size(); i++)
        {
            int value = (key + (c1 * i) + (c2 * (i * i))) % table.size();
            if (table[value] == nullptr)
            {
                table[value] = new Node(data);
                return table[value];
            }
            else
            {
                j++;
            }
        }
        return nullptr;
    }
    Node *doubleOpenAdressingProbing(int key)
    {
        int m = table.size();
        int h1 = divisionHashFunction(key);
        int h2 = multiplicationHashFunction(key, m);
        int index = 0;
        for (int i = 0; table.size(); i++)
        {
            index = (h1 + i * h2) % m;
            if (table[index] == nullptr)
            {
                table[index] = new Node(key);
                return table[index];
            }
        }
        return nullptr;
    }
};
class Hash : public HashFunctions
{
public:
    Hash(int m = 0, int hashfunction = 0, int closion = 0) : HashFunctions(m, hashfunction, closion)
    {
        printHashFunctionsNames();
    }

    Node *choseColsisonFunction(int key, int data, bool isNotDelete = true)
    {
        if (clousisonSelected == 0)
        {
            // seaprateChaning
            return seaprateChaning(key, data, isNotDelete);
        }
        else if (clousisonSelected == 1)
        {
            // openHasing
            return openHasing(key, data, isNotDelete);
        }
        else if (clousisonSelected == 2)
        {
            // linearOpenAddressingProbing
            return linearOpenAddressingProbing(key, data);
        }
        else if (clousisonSelected == 3)
        {
            // quadraticOpenAddressingProbing
            return quadraticOpenAddressingProbing(key, data);
        }
        else if (clousisonSelected == 4)
        {
            // double
            return doubleOpenAdressingProbing(data);
        }
        else
        {
            // Not selected Closision function
            return nullptr;
        }
    }
    void inseart(int data)
    {
        int index = 0;
        if (hashFunctionSelected == 0)
        {
            // divisionHashFunction
            index = divisionHashFunction(data);
            if (table[index] == nullptr)
            {
                table[index] = new Node(data);
            }
            else
            {
                choseColsisonFunction(index, data);
            }
        }
        else if (hashFunctionSelected == 1)
        {
            // multiplicationHashFunction
            index = multiplicationHashFunction(data);
            if (table[index] == nullptr)
            {
                table[index] = new Node(data);
            }
            else
            {
                choseColsisonFunction(index, data);
            }
        }
        else if (hashFunctionSelected == 2)
        {
            // midSqureHashFunction
            index = midSqureHashFunction(data);
            if (table[index] == nullptr)
            {
                table[index] = new Node(data);
            }
            else
            {
                choseColsisonFunction(index, data);
            }
        }
        else if (hashFunctionSelected == 3)
        {
            // foldingHashFunction
            index = foldingHashFunction(data);
            if (table[index] == nullptr)
            {
                table[index] = new Node(data);
            }
            else
            {
                choseColsisonFunction(index, data);
            }
        }
        else if (hashFunctionSelected == 4)
        {
            // universalHashFunction
            index = universalHashFunction(data);
            if (table[index] == nullptr)
            {
                table[index] = new Node(data);
            }
            else
            {
                choseColsisonFunction(index, data);
            }
        }
        else
        {
            cout << endl
                 << "Not selected hash Function" << endl;
        }
    }
    bool search(int data)
    {
        int index = 0;
        if (hashFunctionSelected == 0)
        {
            // divisionHashFunction
            index = divisionHashFunction(data);
            if (table[index]->data == data)
            {
                return true;
            }
            else
            {
                return (choseColsisonFunction(index, data)->data == data);
            }
        }
        else if (hashFunctionSelected == 1)
        {
            // multiplicationHashFunction
            index = multiplicationHashFunction(data);
            if (table[index]->data == data)
            {
                return true;
            }
            else
            {
                return (choseColsisonFunction(index, data)->data == data);
            }
        }
        else if (hashFunctionSelected == 2)
        {
            // midSqureHashFunction
            index = midSqureHashFunction(data);
            if (table[index]->data == data)
            {
                return true;
            }
            else
            {
                return (choseColsisonFunction(index, data)->data == data);
            }
        }
        else if (hashFunctionSelected == 3)
        {
            // foldingHashFunction
            index = foldingHashFunction(data);
            if (table[index]->data == data)
            {
                return true;
            }
            else
            {
                return (choseColsisonFunction(index, data)->data == data);
            }
        }
        else if (hashFunctionSelected == 4)
        {
            // universalHashFunction
            index = universalHashFunction(data);
            if (table[index]->data == data)
            {
                return true;
            }
            else
            {
                return (choseColsisonFunction(index, data)->data == data);
            }
        }
        else
        {
            return false;
        }
    }

    bool deletion(int data)
    {
        int index = 0;
        if (hashFunctionSelected == 0)
        {
            // divisionHashFunction
            index = divisionHashFunction(data);
            if (table[index]->data == data)
            {
                table[index] = nullptr;
            }
            else
            {
                choseColsisonFunction(index, data, false);
            }
        }
        else if (hashFunctionSelected == 1)
        {
            // multiplicationHashFunction
            index = multiplicationHashFunction(data);
            if (table[index]->data == data)
            {
                table[index] = nullptr;
            }
            else
            {
                choseColsisonFunction(index, data, false);
            }
        }
        else if (hashFunctionSelected == 2)
        {
            // midSqureHashFunction
            index = midSqureHashFunction(data);
            if (table[index]->data == data)
            {
                table[index] = nullptr;
            }
            else
            {
                choseColsisonFunction(index, data, false);
            }
        }
        else if (hashFunctionSelected == 3)
        {
            // foldingHashFunction
            index = foldingHashFunction(data);
            if (table[index]->data == data)
            {
                table[index] = nullptr;
            }
            else
            {
                choseColsisonFunction(index, data, false);
            }
        }
        else if (hashFunctionSelected == 4)
        {
            // universalHashFunction
            index = universalHashFunction(data);
            if (table[index]->data == data)
            {
                table[index] = nullptr;
            }
            else
            {
                choseColsisonFunction(index, data, false);
            }
        }
        else
        {
            return false;
        }
    }
    void printHashFunctionsNames()
    {
        cout << endl
             << "0, Divission\n1, Multiplication,\n2, MidSquare,\n3, Folding,\n4, Universal" << endl;
        cout << endl
             << "0, seaprate Chaning Probing\n1, Open Hasing probing,\n2, Linear,\n3, Quadratic,\n4, double" << endl;
    }
    int encription(int data)
    {
        return creptographicHashFunction(data);
    }
    void insert(int data)
    {
    }
    int getSize()
    {
        return table.size();
    }
    vector<Node *> getTable()
    {
        return table;
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