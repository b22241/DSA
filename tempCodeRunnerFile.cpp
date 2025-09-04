int main() 
{
    int rows;
    cout << "Enter the number of rows:" << endl;
    cin >> rows;

    for (int i = 1; i <= rows; i++) 
    {
        for (char ch = 'A'; ch < 'A' + (rows - i + 1); ch++) 
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
// A B C D
// A B C
// A B
// A
}
