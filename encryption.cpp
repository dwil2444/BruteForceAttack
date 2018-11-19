#include <iostream>
#include <string>
#include<crypt.h>
#include <cstdio>
#include <ctime>
using namespace std;

std::string randStr(size_t length);
bool decrypt(std::string guess, std::string target);
string dpass;
int main()
{

  std::string ans = randStr(2);
  //build all possible permutations then add them to a hash map
  // do a foreach on the map
  cout << ans << endl;
  string passwd; //original password
  string attempt; //attempts at decrypting password
  string epass; //encrypted password
  //string dpass; //decrypted password
  // string alph[52] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
  //                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
  //                     "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d",
  //                    "e", "f", "g" , "h", "i", "j", "k", "l", "m", "n",
  //                    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
  //                     "y", "z"};

  cout << "Please enter a four letter password: ";
  cin >> passwd;
  epass = crypt(passwd.c_str(), "$1$ab$");
  cout << "Encrypted password: " << epass << endl;
  bool found = false;
  std::clock_t start;
  start = std::clock();
  double duration;
  while(!found)
  {
    found = decrypt(randStr(passwd.length()+1),epass);
  }
  std::cout.precision(2);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  cout <<"Found in: " << duration << " seconds\n";
  cout << dpass;
  return 0;

}
std::string randStr(size_t length) 
{
  srand(time(NULL));  //generate a seed by using the current time
  char str[length];
  str[length-1] = '\0';
  size_t i = 0;
  int r;

  for(i = 0; i < length-1; ++i) 
  {
    for(;;) 
    {
      r = rand() % 57 + 65; //interval between 65 ('A') and 65+57=122 ('z')
      if((r >= 65 && r <= 90) || (r >= 97 && r <= 122)) 
      { // exclude '[' to '`'
        str[i] = (char)r;
        break;
      }
    }
  }
  return string(str);
}
bool decrypt(std::string guess, std::string target)
{
  if (crypt(guess.c_str(), "$1$ab$") == target)
  {
    dpass = guess.c_str();
    return true;
  }
  return false;
}



/*
To run the code:
.....................

1-	Upload file.
2-  ch ..
3- ls
4- g++ solution.cpp -lcrypt -o file
5-./file


NOTE that, crypt function is defined only in linux for C++, I am not sure about Python or other languages
(If you are using windows you can use some online websites such as https://bellard.org/jslinux/vm.html?url=https://bellard.org/jslinux/buildroot-x86.cfg)



*/