#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
void encrypted(char str1[], int shift);
void variable(char arr[]);
void imp1(char arr[], int s, int r);
void readimp1(char arr[], int &s, int &r);
void binary(char str1[], double arrbi[][7], int &x1);
void dencrypted(char str1[], int &s, int &k);
void dbinary(double arrbi[][7], int &x1, char ch1[], int &k);
int main()
{
   system("CLS");
   char str1[100], arr[9], ch1[100];
   int shift, i, rseries = 2, x1, s, r, k = 0;
   double arrbi[100][7];
   system("CLS");
   cout << "Enter the string that you want to encrypt(max 50 words): ";
   cin.getline(str1, 100);
   cout << "Enter the shift value(1-10): ";
   cin >> shift;
   cout << endl;
   encrypted(str1, shift);
   cout << endl;
   binary(str1, arrbi, x1);
   cout << "  ";
   variable(arr);
   imp1(arr, shift, rseries);
   for (i = 0; i < 9; i++)
   {
      if (arr[i] < 10)
         cout << int(arr[i]);
      else
         cout << arr[i];
   }
   cout << endl;
   dbinary(arrbi, x1, ch1, k);
   readimp1(arr, s, r);
   dencrypted(ch1, s, k);
   cout << " ";
   imp1(arr, s, r);
   for (i = 0; i < 9; i++)
   {
      if (arr[i] < 10)
         cout << int(arr[i]);
      else
         cout << arr[i];
   }
   getche();
   return 0;
}
void encrypted(char str1[], int shift)
{
   int i = 0;
   char ch;
   for (i = 0; str1[i] != '\0'; i++)
   {
      ch = str1[i];
      if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
      {

         if ((shift + ch) >= 97 && (shift + ch) <= 122)
         {
            ch = shift + ch;
            str1[i] = ch;
         }
         else if ((ch + shift) > 122)
         {
            ch = (shift + ch) - 58;
            str1[i] = ch;
         }
         else if ((shift + ch) >= 65 && (shift + ch) <= 90)
         {
            ch = shift + ch;
            str1[i] = ch;
         }
         else if ((ch + shift) > 90)
         {
            ch = (shift + ch) + 6;
            str1[i] = ch;
         }
      }
   }
   cout << "Output:\n";
   cout << "The encrypted text is: ";
   cout << str1;
}
void dencrypted(char ch1[], int &s, int &k)
{
   int i = 0;
   char ch;
   for (i = 0; i < k || ch1[i] != '\0'; i++)
   {
      if (ch1[i] == ' ')
         continue;
      ch = ch1[i];
      if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
      {
         if ((ch - s) >= 97 && (ch - s) <= 122)
         {
            ch = ch - s;
            ch1[i] = ch;
         }
         else if ((ch - s) < 65)
         {
            ch = (ch - s) + 58;
            ch1[i] = ch;
         }
         else if ((ch - s) >= 65 && (ch - s) <= 90)
         {
            ch = ch - s;
            ch1[i] = ch;
         }
         else if ((ch - s) < 97)
         {
            ch = (ch - s) - 6;
            ch1[i] = ch;
         }
      }
   }
   cout << endl
        << "Output:\n";
   cout << "The dencrypted text is: ";
   cout.write(ch1, k);
}
void variable(char arr[])
{
   int l, i;
   l = rand()%3;
   if (l == 0)
   {
      arr[1] = 'x';
      l = rand()%2;
      if (l == 0)
      {
         arr[4] = 'y';
         arr[7] = 'a';
      }
      else
      {
         arr[7] = 'y';
         arr[4] = 'a';
      }
   }
   else if (l == 1)
   {
      arr[4] = 'x';
      l = rand()%2;
      if (l == 0)
      {
         arr[1] = 'y';
         arr[7] = 'a';
      }
      else
      {
         arr[7] = 'y';
         arr[1] = 'a';
      }
   }
   else
   {
      arr[7] = 'x';
      l = rand()%2;
      if (l == 0)
      {
         arr[1] = 'y';
         arr[4] = 'a';
      }
      else
      {
         arr[4] = 'y';
         arr[1] = 'a';
      }
   }
}
void imp1(char arr[], int s, int r)
{
   srand(time(0));
   int i;
   arr[0] = rand()%10;
   arr[3] = rand()%10;
   arr[6] = rand()%10;
   for (i = 0; i < 9; i++)
   {
      if (arr[i] == 'x')
         arr[i + 1] = s;
      else if (arr[i] == 'y')
         arr[i + 1] = r;
      else if (arr[i] == 'a')
         arr[i + 1] = rand()%10;
   }
}
void readimp1(char arr[], int &s, int &r)
{
   int i;
   for (i = 0; i < 9; i++)
   {
      if (arr[i] == 'x')
      {
         s = arr[i + 1];
      }
      else if (arr[i] == 'y')
      {
         r = arr[i + 1];
      }
   }
}
void binary(char ch[], double arrbi[][7], int &x1)
{
   int num, r, j;
   x1 = strlen(ch);
   for (int i = 0; i < x1; i++)
   {
      if (ch[i] == ' ')
      {
         arrbi[i][1] = 9;
         continue;
      }
      num = ch[i];
      j = 0;
      do
      {
         r = num % 2;
         arrbi[i][j] = r;
         num = num / 2;
         j++;
      } while (num != 0);
   }
   cout << endl;
   cout << "In binary the code is:";
   for (int i = 0; i < x1; i++)
   {
      for (j = 0; j < 7; j++)
         cout << arrbi[i][7 - j - 1];
      cout << " ";
   }
}
void dbinary(double arrbi[][7], int &x1, char ch1[], int &k)
{
   int sum;
   for (int i = 0; i < x1; i++)
   {
      sum = 0;
      if (arrbi[i][1] == 9)
         ch1[i] = ' ';
      else
      {
         for (int j = 0; j < 7; j++)
            sum += (arrbi[i][j]) * pow(2, j);
         ch1[i] = sum;
      }
      k++;
   }
   cout << endl;
   cout << "The string is: ";
   cout << endl;
   cout.write(ch1, k);
}