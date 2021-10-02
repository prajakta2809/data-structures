// stack using array

#include <iostream>

using namespace std;

class Stack
{
    private:
        int top;
        int arrSize;
        int *arr;

    public:
        // initializing data using default constructor
        Stack ()
        {
            top = -1;
            cout << "Enter size of array: ";
            cin >> arrSize;

            arr = new int[arrSize];
            for (int i = 0; i < arrSize; i++)
            {
                arr[i] = 0;
            }
        }

        // to check whether stack is empty of not
        bool isEmpty ()
        {
            if (top == -1)
                return true;
            else
                return false;
        }

        // to check whether stack is full of not
        bool isFull ()
        {
            if (top == (arrSize-1))
                return true;
            else
                return false;
        }

        // to push elements into stack
        void push (int num)
        {
            if (isFull())
            {
                cout << "Stack overflow" << endl;
            }
            else
            {
                top++;
                arr[top] = num;
                cout << "Element pushed into the stack" << endl;
            }
        }

        // to pop elements from stack
        void pop ()
        {
            if (isEmpty())
            {
                cout << "Stack underflow" << endl;
            }
            else
            {
                int temp = arr[top];
                arr[top] = 0;
                top--;
                cout << "Popped element from the stack is: " << temp << endl;
            }
        }

        // to access element at specific index
        int peek (int index)
        {
            if (index < 0 || index > (arrSize-1))
            {
                cout << "Enter proper index between 0 and " << arrSize-1 << endl;
                return -1;
            }
            else
            {
                return arr[index];
            }
        }

        // to change value of stack at specific index
        void change (int index, int value)
        {
            if (index < 0 || index > (arrSize-1))
            {
                cout << "Enter proper index between 0 and " << arrSize-1 << endl;
            }
            else if (isEmpty())
            {
                cout << "STack is empty, first push elements in stack then try to change" << endl;
            }
            else
            {
                arr[index] = value;
            }
        }

        // to return count of elements in stack
        int count ()
        {
            return (top + 1);
        }

        // to display values of stack
        void display ()
        {
            if (isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Elements in STACK are: " << endl;
                for (int i = arrSize-1; i >= 0; i--)
                {
                    cout << arr[i] << endl;
                }
                cout << endl;
            }
        }
};

int main()
{
    Stack s;
    int index, value, choice, ans;

    do
    {
        cout << "Enter your choice: " << endl;
		cout << "0 -> exit" << endl;
		cout << "1 -> push()" << endl;
		cout << "2 -> pop()" << endl;
		cout << "3 -> isEmpty()" << endl;
		cout << "4 -> isFull()" << endl;
		cout << "5 -> count()" << endl;
		cout << "6 -> peek()" << endl;
		cout << "7 -> change()" << endl;
		cout << "8 -> display()" << endl;
		cout << "9 -> clear screen" << endl;
		
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element you want to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            if (s.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
            break;

        case 4:
            if (s.isFull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
            break;

        case 5:
            ans = s.count();
            cout << "Count of elements in stack are: " << ans << endl;
            break;

        case 6:
            cout << "Enter index value at which you want to see value: ";
            cin >> index;
            ans = s.peek(index);
            if (ans != -1)
            {
                cout << "Value of element at index " << index << " is: " << ans << endl;
            }
            break;

        case 7:
            cout << "Enter index at which you want to change value: ";
            cin >> index;
            cout << endl;
            cout << "Enter value you want to change: ";
            cin >> value;
            s.change(index, value);
            break;

        case 8:
            s.display();
            break;

        case 9:
            system("cls");
            break;
        
        case 0:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Enter valid choice between 0 to 9" << endl;
        }
        cout << endl;
    } 
    while (choice != 0);
    
    return 0;
}
