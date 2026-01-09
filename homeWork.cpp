#include <iostream>
using namespace std;

void drawFigure(int n, int type)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            bool paint = false;

            switch (type)
            {
                // a) треугольник под главной диагональю
            case 1:  
                paint = (i >= j);                           
                break;
                // б) треугольник над главной диагональю
            case 2:  
                paint = (i <= j);                           
                break;
                // в) треугольник над побочной диагональю
            case 3:  
                paint = (i + j <= n - 1);                   
                break;
                // г) треугольник под побочной диагональю
            case 4:  
                paint = (i + j >= n - 1);                   
                break;
                // д) верхний + нижний треугольники (по двум диагоналям)
            case 5:  
                paint = ((i <= j && i + j <= n - 1) || (i >= j && i + j >= n - 1));     
                break;
                // е) левый + правый треугольники (по двум диагоналям)
            case 6:  
                paint = ((i <= j && i + j >= n - 1) || (i >= j && i + j <= n - 1));     
                break;
                // ж) верхний треугольник (между диагоналями)
            case 7:  
                paint = (i <= j && i + j <= n - 1);         
                break;
                // з) правый треугольник (между диагоналями)
            case 8:  
                paint = (i <= j && i + j >= n - 1);         
                break;
                // и) нижний треугольник (между диагоналями)
            case 9:  
                paint = (i >= j && i + j >= n - 1);         
                break;
                // к) левый треугольник (между диагоналями)
            case 10: 
                paint = (i >= j && i + j <= n - 1);         
                break;
            }

            cout << (paint ? '*' : ' ');
        }
        cout << '\n';
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер квадрата (рекомендуется 10–20): ";
    cin >> n;
    if (n < 2) n = 2;

    int choice;
    do
    {
        cout << "\nМеню фигур (квадрат " << n << "x" << n << "):\n";
        cout << " 1 - фигура а\n";
        cout << " 2 - фигура б\n";
        cout << " 3 - фигура в\n";
        cout << " 4 - фигура г\n";
        cout << " 5 - фигура д\n";
        cout << " 6 - фигура е\n";
        cout << " 7 - фигура ж\n";
        cout << " 8 - фигура з\n";
        cout << " 9 - фигура и\n";
        cout << "10 - фигура к\n";
        cout << " 0 - выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice >= 1 && choice <= 10)
        {
            cout << '\n';
            drawFigure(n, choice);
        }
        else if (choice != 0)
        {
            cout << "Неверный пункт меню!\n";
        }

    } while (choice != 0);

    return 0;
}

