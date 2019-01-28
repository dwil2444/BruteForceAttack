#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<unistd.h>
#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;

// function prototypes
void gen_str(const char*,std::string,const int, const int);
std::vector<std::string> permutations ;
int NumberOfPermutations = 0;
bool decrypt(std::string guess, std::string target);
int compare (const void * a, const void * b);
//////////////////////////////////////////////////////////

string dpass;
int main()
{
  string passwd; //original password
  string attempt; //attempts at decrypting password
  string epass; //encrypted password
  cout << "Please enter password to be cracked: "; // read a string from the user
  cin >> passwd;
  int length = passwd.length();
  char str[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
                'e', 'f', 'g' , 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z'};
  int n = sizeof str;
  for (int k = 1; k <= length; k++) // generate all the permutations of the string from length 1 to n
  {
    gen_str(str, "", n, k);
  }
  epass = crypt(passwd.c_str(), "ab");  // encrypt the password entered by the user using crypt function and salt value
  cout << "Encrypted password: " << epass << endl;
  std::string* permut_array =  new std::string[NumberOfPermutations];
  std::copy(permutations.begin(), permutations.end(), permut_array);
  std::clock_t start;
  start = std::clock();
  std::cout.precision(2);
  double duration;
  for (int k = 0; k < NumberOfPermutations; k++)
  {
    std:: string test = permut_array[k];
    if(decrypt(test, epass) == true)
    {
      duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
      cout << "The password is: " << dpass << endl;;
      cout <<"Found in: " << duration << " seconds" << endl;
      break;
    }
  }
  return 0;

}
bool decrypt(std::string guess, std::string target)
{
  if (crypt(guess.c_str(), "ab") == target)  // if the current string matches the password when encrypted
  {
    dpass = guess.c_str();
    return true;  // then this is the password entered by the user
  }
  return false; // otherwise it is not
}
void gen_str(const char str[],std::string prefix,const int n, const int length) //recursively generate all permutations of a string of length n
{
    if (length == 1)
    {
        for (int j = 0; j < n; j++)
        {
          permutations.push_back(prefix + str[j]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            gen_str(str, prefix + str[i], n, length - 1);
        }
    }
    NumberOfPermutations = permutations.size(); // keep track of the number of permutations
}
