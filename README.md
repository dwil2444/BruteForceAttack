# BruteForceAttack
:lock: :unlock:
This is a C++ console application to perform a brute force attack using all possible string permutations to crack passwords of varying length

:exclamation::exclamation: This will only compile on unix systems as crypt() is a unix function :exclamation::exclamation:

1. Navigate to the root of the repository, then compile the program from the terminal with the following command:
    ```g++ encryption.cpp -lcrypt -o file```

2. Run the code by typing the following in the terminal:
   ```./file```
# OR 
1. From the terminal, enter the following command (only one time is necessary):
    ```chmod +x ./loader.sh```

2. Run the program subsequently using:
    ```./loader.sh```
# OR
1. From the terminal enter the following command to compile:
    ```make```
2. From the terminal enter the following command to run:
    ```./file```