#include <iostream>

using namespace std;


int** CreateArray(int row, int columns) {

    int** NewArr = new int* [row];

    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];
    }

    return NewArr;
}

void FillArray(int** NewArr, int& row, int& columns) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            NewArr[i][j] = rand() % 10;
        }
    }

}

void DeleteArray(int** arr, int row) {

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void ShowArray(int** Arr, int& row, int& columns) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }

}


int** PopIndexColumns(int** arr, int row, int& columns) {


    int pos;
    cout << "Index";
    cin >> pos;

    if (pos >= 0 && pos < columns) {

        for (int i = 0; i < row; i++)
        {
            for (int j = pos; j < columns - 1; j++)
            {
                arr[i][j] = arr[i][j + 1];
            }
        }
        columns--;
    }
    else
    {
        cout << "end";


    }

    return arr;
}


int** AddColumnsStart(int** arr, int row, int& columns) {

    int** NewArr = new int* [row];

    columns++;

    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];

        for (int j = 0; j < columns; j++)
        {

            NewArr[i][j + 1] = arr[i][j];


        }
        NewArr[i][0] = 10;

    }

    DeleteArray(arr, row);
    return NewArr;

}

int** AddColumnsEnd(int** arr, int row, int& columns) {

    int** NewArr = new int* [row];

    columns++;

    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];

        for (int j = 0; j < columns; j++)
        {

            NewArr[i][j] = arr[i][j];


        }
        NewArr[i][columns - 1] = 100;

    }




    DeleteArray(arr, row);
    return NewArr;

}


int** DeleteColumnsStart(int** arr, int row, int& columns) {

    int** NewArr = new int* [row];

    columns--;

    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];

        for (int j = 0; j < columns; j++)
        {
            NewArr[i][j] = arr[i][j + 1];
        }

    }

    DeleteArray(arr, row);
    return NewArr;

}

int** DeleteColumnsEnd(int** arr, int row, int& columns) {

    int** NewArr = new int* [row];

    columns--;

    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];

        for (int j = 0; j < columns; j++)
        {
            NewArr[i][j] = arr[i][j];
        }
    }

    DeleteArray(arr, row);
    return NewArr;

}


int** AddRowStart(int** arr, int& row, int columns) {

    int** NewArr;

    NewArr = CreateArray(row + 1, columns);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            NewArr[i + 1][j] = arr[i][j];
        }
        NewArr[0][i] = 10;
    }

    row++;

    DeleteArray(arr, row - 1);
    arr = NewArr;
    return arr;


}

int** AddRowEnd(int** arr, int& row, int columns) {

    int** NewArr;

    NewArr = CreateArray(row + 1, columns);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            NewArr[i][j] = arr[i][j];
        }
        NewArr[row][i] = 100;
    }

    row++;

    DeleteArray(arr, row - 1);
    arr = NewArr;
    return arr;


}


int** DeleteRowStart(int** arr, int& row, int columns) {


    row--;
    int** NewArr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];
    }
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < columns; k++)
        {
            NewArr[i][k] = arr[i + 1][k];
        }
    }

    DeleteArray(arr, row);
    return NewArr;

}

int** DeleteRowEnd(int** arr, int& row, int columns) {

    row--;
    int** NewArr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[columns];
    }
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < columns; k++)
        {
            NewArr[i][k] = arr[i][k];
        }
    }

    DeleteArray(arr, row);
    return NewArr;


}

int** DelR(int** arr, int& row, int col, int& num)
{
    int** NewArr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        NewArr[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            if (i != num)
                NewArr[i][k] = arr[i][k];
        }
    } if (num == 0) {
        for (int i = 1; i < row; i++)
        {
            for (int k = 0; k < col; k++)
            {
                NewArr[i - 1][k] = arr[i][k];
            }
        }
    }
    if (num < row && num != 0) {
        for (int i = num + 1; i < row; i++)
        {
            for (int k = 0; k < col; k++)
            {
                NewArr[i + 1][k] = arr[i][k];
            }
        }
    } row--;
    DeleteArray(arr, row);
    return NewArr;
}

int** AddRowIndex(int** arr, int& row, int columns)
{
    int** NewArr;
    int Index;
    cin >> Index;
    if (Index > row)
    {
        cout << "Такого индекса нету" << endl;
        return 0;
    }
    else
    {
        NewArr = CreateArray(row + 1, columns);
        for (int i = 0; i < Index; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                NewArr[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < row - Index; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                NewArr[i + Index + 1][j] = arr[i + Index][j];
            }
        }
        row++;
        for (int i = Index; i < Index + 1; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                NewArr[i][j] = 7;
            }
        }

        DeleteArray(arr, row - 1);

        arr = NewArr;
        return arr;

    }
}

int** AddColumnsIndex(int** arr, int row, int& columns) {

    int** NewArr;
    int pow;
    cin >> pow;
    if (pow > row)
    {
        cout << "end";
        return 0;
    }
    else
    {
        columns++;
        int** NewArr = new int* [row];
        for (int i = 0; i < row; i++)
        {
            NewArr[i] = new int[columns];
            for (int j = 0; j < columns; j++)
            {
                if (j < pow)
                {
                    NewArr[i][j] = arr[i][j];

                }
                else
                {
                    NewArr[i][j + 1] = arr[i][j];
                }
            }

            NewArr[i][pow] = 8;


        }
        DeleteArray(arr, row);
        return NewArr;
    }
}

int main()
{

    setlocale(LC_ALL, "Russian");


    int row;
    int columns;
    cout << "Введите количество строк: ";
    cin >> row;
    cout << "Введите количество столбцов: ";
    cin >> columns;
    int** arr;

    cout << endl;

    cout << "Неизененый массив: " << endl;
    arr = CreateArray(row, columns);
    FillArray(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Добавить столбец в начало" << endl;
    arr = AddColumnsStart(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Добавить столбец в конец" << endl;
    arr = AddColumnsEnd(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Удалить столбец в начале" << endl;
    arr = DeleteColumnsStart(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Удалить столбец в конце" << endl;
    arr = DeleteColumnsEnd(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Добавить строку в начало" << endl;
    arr = AddRowStart(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Добавить строку в конец" << endl;
    arr = AddRowEnd(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Удалить строку в начале" << endl;
    arr = DeleteRowStart(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;


    cout << "Удалить строку в конце" << endl;
    arr = DeleteRowEnd(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Введите индекс, что бы добавить новую строку: ";
    arr = AddRowIndex(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    cout << "Введите индекс, что бы добавить новый столбец: ";
    arr = AddColumnsIndex(arr, row, columns);
    ShowArray(arr, row, columns);
    cout << endl;

    DeleteArray(arr, row);

    return 0;
}