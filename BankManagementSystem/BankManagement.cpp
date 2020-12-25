/*
* Name: Mansi Patel
*/

#include "BankManagement.h"

using namespace std;

vector <BankAccount> BankAccountVector;

int i = 0;  //account ID var

/*
* This a default consutor for BankAccount() class
*/
BankAccount::BankAccount()
{
	accountNo = 0;
	accountPassword[0] = '/0';
	balance = 0.00f;
}

/*
* Method Name: searchAccount(id, password[])
* Parameters: accountid(int), accountpassword (char[])
* Purpose: This method will go through the BankAccountVector and will retun the id, if it finds the user entered id and password
*/
int BankAccount::searchAccount(int id, char password[PASSWORD_SIZE])
{

	for (int i = 0; i < BankAccountVector.size(); i++)
	{
		//check for parameter id == account No && paramter passowrd == account password
		if (id == BankAccountVector[i].accountNo && (string(password) == string(BankAccountVector[i].accountPassword)))
		{
			return id;
		}
	}
	return -1;
}

/*
* Method Name: createAccount()
* Parameters: No parameters
* Purpose: This method will create an account object using default constuctor and then store the id, default balance amount and password(user entered) in a vector called BankAccountVector
*/
void BankAccount::createAccount()
{
	//creating account object using deafult construtor
	BankAccount account;

	cin.ignore(INT_MAX, '\n');
	account.accountNo = i;			//setting account id value 

	cout << "To create an account, please provide a password." << endl
		<< "The password should be 8 to 32 characters long." << endl
		<< "New account password:" << endl;
	cin.getline(account.accountPassword, PASSWORD_SIZE);			//userinput for password

	//password check for characters, it has to be greater than 8 characters and less than 32 characters
	while (cin.fail() || strnlen(account.accountPassword, 32) < 8 || strnlen(account.accountPassword, 32) > 32)
	{
		cin.clear();
		//cin.ignore(INT_MAX, '\n');
		cout << "The password should be 8 to 32 characters long. Please try again!" << endl;
		cin.getline(account.accountPassword, PASSWORD_SIZE);
	}

	//pushing bakc the account object to the BankAccountVector vector
	BankAccountVector.push_back(account);
	cout << "Account with ID number ( " << account.accountNo << " ) has been successfully created!" << endl;
	i++;

}

/*
* Method Name: deleteAccount(id)
* Parameters: accountid(int)
* Purpose: This method will go through BankAccountVector and when the (passed)parmeter id will match the account id in vetor, it will remove that account from the vector
*/
void BankAccount::deleteAccount(int accID)
{
	for (int x = 0; x < BankAccountVector.size(); x++)
	{
		//check for parameter id == account No
		if (accID == BankAccountVector[x].accountNo)
		{
			cout << "Removing Account ID ( " << accID << " )" << endl;
			//erase the Account by ID
			BankAccountVector.erase(BankAccountVector.begin() + x);

			cout << "Account with ID ( " << accID << " ) was deleted successfully." << endl;
		}
	}
}

/*
* Method Name: displayBalance(id)
* Parameters: accountid(int)
* Purpose: This method will go through BankAccountVector and when the (passed)parmeter id will match the account id in vetor, it will disply that account with Id and balance for that account
*/
void BankAccount::displayBalance(int accID)
{
	cout << "Displaying the Balance for Account ID ( " << accID << " )" << endl;

	for (int x = 0; x < BankAccountVector.size(); x++)
	{
		//check for parameter id == account No
		if (accID == BankAccountVector[x].accountNo)
		{
			//displaying account id and balance
			cout << "Account ID is: " << BankAccountVector[x].accountNo << endl;
			cout << "Account Balance is: $" << fixed << setprecision(2) << BankAccountVector[x].balance << endl;
		}
	}
}

/*
* Method Name: depositeAmount(id, money)
* Parameters: accountid(int), depositeAmount(double)
* Purpose: This method will go through BankAccountVector and when the (passed)parmeter id will match the account id in vetor, it will deposite the amount entered by user to the user account
*/
void BankAccount::depositeAmount(int accID, double money)
{
	for (int x = 0; x < BankAccountVector.size(); x++)
	{
		//check for parameter id == account No
		if (accID == BankAccountVector[x].accountNo)
		{
			//check for positive deposite amount
			if (money < 0.00)
			{
				cout << "You cannot deposite negative amount to your account." << endl;
			}
			else
			{
				//if deposite amount >= 250.00 add bonus otherwise just deposite the amount
				if (money >= 250.00)
				{
					//bonus calculation
					int bonusAmount = 5 * (money / 250.00);

					//add bonus to the balance
					BankAccountVector[x].balance = BankAccountVector[x].balance + money + bonusAmount;
					cout << "You have earned $" << bonusAmount << " bonus on your deposite." << endl;
					cout << "You have successfully deposite $" << money << " to your account." << endl;
				}
				else
				{
					//adding amount to the balance without bonus
					BankAccountVector[x].balance += money;
					cout << "You have successfully deposite $" << money << " to your account." << endl;
				}
			}
		}
	}
}

/*
* Method Name:
* Parameters:
* Purpose: This method will go through BankAccountVector and when the (passed)parmeter id will match the account id in vetor, it will remove/withdraw the amount entered by user from the user account
*/
void BankAccount::withdrawAmount(int accID, double money)
{
	for (int x = 0; x < BankAccountVector.size(); x++)
	{
		//check for parameter id == account No
		if (accID == BankAccountVector[x].accountNo)
		{
			//check for positive withdraw amount
			if (money < 0.00)
			{
				cout << "You cannot withdraw negative amount from your account." << endl;
			}
			else
			{
				//service charges calculation 
				double totalWithdrawalAmount = money + 2.00;

				//check if balance >= withdrawamount then withdraw the amount, else show error message - 'No sufficient balance'
				if (BankAccountVector[x].balance >= totalWithdrawalAmount)
				{
					//subtracting amount from balance
					BankAccountVector[x].balance -= totalWithdrawalAmount;
					cout << "You have successfully withdraw $" << totalWithdrawalAmount << " from your account with servie fees." << endl;
				}
				else
				{
					cout << "Sorry you don't have sufficient balance to withdraw from your account!." << endl;
					cout << "Please check your balance." << endl;
				}
			}
		}
	}
}