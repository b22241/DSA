#include <iostream>
using namespace std;
// IF ELSE
// int main() {
//     int marks;
//     cout<<"enter your makrs:" << std::endl;
//     cin>>marks;
//     char grade;
//     if (marks < 25) {
//         grade = 'F';
//     } else if (marks <= 44) {
//         grade = 'E';
//     } else if (marks <= 49) {
//         grade = 'D';
//     } else if (marks <= 59) {
//         grade = 'C';
//     } else if (marks <= 69) {
//         grade = 'B';
//     } else if (marks >= 70) {
//         grade = 'A';
//     } else {
//         grade = 'X'; // Use 'X' to indicate invalid marks
//     }
//     std::cout << "Grade: " << grade << std::endl;  
//     return 0;
// }


//SWITCH
// int main() {
//     int day;
//     cin>>day;
//     switch (day) {
//         case 1:
//             cout << "Monday";
//             break;
//         case 2:
//             cout << "Tuesday";
//             break;
//         case 3:
//             cout << "Wednesday";
//             break;
//         case 4:
//             cout << "Thursday";
//             break;
//         case 5:
//             cout << "Friday";
//             break;
//         case 6:
//             cout << "Saturday";
//             break;
//         case 7:
//             cout << "Sunday";
//             break;
//         default:
//             cout << "Invalid";
//     }
//     return 0;
// }


//ARRAY
// int main(){
//     int arr[4];
//     arr[2]=100;
//     cout<<arr[24];
//     return 0;
// }


//FUNCTIONS
// int max(int num1,int num2)
// {
//     if(num1>num2)
//     {
//         return num1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int main(){
//     int num1,num2;
//     cin >>num1; 
//     cin>>num2;
//     cout<<max(num1,num2);
// }



//REFERENCE
// int dosomething(int num)// here dosomething will copy num value from cin and perform and operation it won't affect original value of num. If I use & then original value will also get changed
// {
//     num=num+2;
//     return num;
// }

// int main()
// {
    // int num;
//     cout<<"the number"<<endl;
//     cin>>num;
//     cout<<dosomething(num)<<endl;
//     cout<<num;
// }



                                                                //    -----------------------PATTERNS------------------------
// int main()
// {
//     int rows,columns;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<endl;
//     cin>>rows;
//     //cin>>columns;
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=1;j<=rows-i;j++)
//         {
//             cout<<j;
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// int main()
// {
//     int rows,columns;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<endl;
//     cin>>rows;
//     columns=2*rows-1;
//     //cin>>columns;
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=1;j<=i+1;j++)
//         {
//             cout<<" ";
//         }
//         for(int k=2*rows-2*i-1;k>=1;k--)
//         {
//             cout<<"*";
//         }
//        for(int j=1;j<=i+1;j++)
//         {
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }





// int main()
// {
//     int rows,columns;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<endl;
//     cin>>rows;
//     columns=2*rows-1;
// for (int i = 1; i <= rows; i++) {
//         for (int j = 1; j <= rows - i; ++j) {
//             cout << " ";
//         }
//         for (int k = 1; k <= 2 * i - 1; ++k) {
//             cout << "*";
//         }
//         cout << endl;
//     }
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=2;j<=i+1;j++)
//         {
//             cout<<" ";
//         }
//         for(int k=2*rows-2*i-1;k>=1;k--)
//         {
//             cout<<"*";
//         }
//        for(int j=1;j<=i+1;j++)
//         {
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// int main()
// {
//     int rows,columns;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<endl;
//     cin>>rows;
//     //cin>>columns;
//     for(int i=1;i<=2*rows-1;i++)
//     {
//         int stars =i;
//         if(i>rows) stars=2*rows-i;
//         for(int j=1;j<=stars;j++)
//         {
//         cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// int main()
// {
//     int rows,columns,set = 1;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<endl;
//     cin>>rows;
//     for(int i=1;i<=rows;i++)
//     {
//         if (i%2==0) set=0;
//         else set=1;
//         for(int j=1;j<=i;j++)
//         {
//             cout<<set;
//             set=1-set;
//         }
//         cout<<endl;
//     }
// return 0;
// }    



// int main()
// {
//     int rows;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<endl;
//     cin>>rows;
//     for(int i=1;i<=rows;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             cout<<j;
//         }
//         for(int j=1;j<=-2*i+8;j++)
//         {
//             cout<<" ";
//         }
//         for(int j=i;j>=1;j--)
//         {
//             cout<<j;
//         }
//         cout<<endl;
//     }
// return 0;
// }   



// int main()
// {
//     int rows, value=1;
//     cout<<"Enter the number of rows:"<<endl;  //<<"Enter the number of columns:"<<
//     cin>>rows;
//     for(int i=1;i<=rows;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             cout<<value<<" ";
//             value++;
//         }
//         cout<<endl;
//     } 
// }



// int main() 
// {
//     int rows;
//     cout << "Enter the number of rows:" << endl;
//     cin >> rows;

//     for (int i = 1; i <= rows; i++) 
//     {
//         for (char ch = 'A'; ch < 'A' + (rows - i + 1); ch++) 
//         {
//             cout << ch << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// // A B C D
// // A B C
// // A B
// // A
// }



// int main() 
// {
//     int rows;
//     cout << "Enter the number of rows:" << endl;
//     cin >> rows;

//     for (int i = 1; i <= rows; i++) 
//     {
//         for (char ch = 'A'; ch <'A'+i; ch++) 
//         {
//             cout << ch << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// // A
// // A B
// // A B C
// // A B C D
// }




// int main() 
// {
//     int rows;
//     cout << "Enter the number of rows:" << endl;
//     cin >> rows;
//     char ch='A';
//     for (int i = 1; i <= rows; i++) 
//     {
//         for (int j = 1; j <=i; j++) 
//         {
//             cout << ch<< " ";
//         }
//         ch++;
//         cout << endl;
//     }
//     return 0;
// // A
// // B B
// // C C C
// // D D D D
// }



// int main() 
// {
//     int rows;
//     cout << "Enter the number of rows:" << endl;
//     cin >> rows;
//     for (int i = 1; i <= rows; i++) 
//     {
//         char ch='A';
//         for (int j = 1; j <=-i+4; j++) 
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <=i; j++)
//         {
//             cout <<ch;
//             ch++;
//         }
//         ch=ch-2;
//         for (int j = 1; j < i; j++) 
//         {
//             cout << ch;
//             ch--;
//         }
//         for (int j = 1; j <=-i+4; j++) 
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// //    A
// //   ABA
// //  ABCBA
// // ABCDCBA
// }




// int main() 
// {
//     int rows;
//     cout << "Enter the number of rows:" << endl;
//     cin >> rows;
//     for (int i = 1; i <= rows; i++) 
//     {
//         char ch='A'+rows-i;
//         for (int j = 1; j <=i; j++) 
//         {
//             cout << ch<< " ";
//             ch++;
//         }
//         cout << endl;
//     }
//     return 0;
// // E
// // D E
// // C D E
// // B C D E
// // A B C D E
// }




// #include <bits/stdc++.h>
// using namespace std;

// int max_sum(int n, int arr[]) {
//     int cnt = 0;

//     // Count the number of negative elements
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < 0) {
//             cnt++;
//             arr[i] = -arr[i];  // Flip negative numbers to positive
//         }
//     }

//     int sum = accumulate(arr, arr + n, 0); // Calculate the sum of the array

//     if (cnt % 2 == 0) {
//         return sum; // If count of negatives is even, return the sum
//     } else {
//         // If count of negatives is odd, subtract twice the smallest element
//         int minElement = *min_element(arr, arr + n);
//         return sum - 2 * minElement;
//     }
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         int arr[n];

//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         cout << max_sum(n, arr) << endl;
//     }
//     return 0;
// }

























