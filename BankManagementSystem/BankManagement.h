/*
* Name: Mansi Patel
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>

using namespace std;

const int PASSWORD_SIZE = 32;

class BankAccount
{
public:
	BankAccount(); //default constructor
	void createAccount();
	int searchAccount(int, char[PASSWORD_SIZE]);
	void deleteAccount(int);
	void displayBalance(int);
	void depositeAmount(int, double);
	void withdrawAmount(int, double);

private:
	int accountNo;
	char accountPassword[PASSWORD_SIZE];
	double balance;

};

#endif