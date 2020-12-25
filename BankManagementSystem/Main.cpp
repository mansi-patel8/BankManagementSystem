/*
* Name: Mansi Patel
* Problem: Bank Account System, which store the several accounts. Handles oprations such as deposite, withdraw and show account balance.
* Pseducode:
			- create a menu system
			- manage account
				- deposite
					- the deposite amount has to be > $0.00
					- there is bonus $5.00 for each $250 or more amount deposite
					- if the amount is < $250 no bonus
				- withdraw
					- the withdraw amount has to be > $0.00
					- it has $2 service fees so if service fees + withdraw amount >= balance - then let user withdraw amount otherwise show error message
				- show balance
					- show account id and the balance in the account
			- create account
				- create a new account using classes which are password protected
			- destroy account
				- delete the account by id - use will need to enter the password to do it
			- exit
				- close the code
*/

#include "BankManagement.h" 

int main()
{
	int i;
	int mainMenuUserInput;						//userinput for the main menu
	int manageMenuUserInput;					//userinput for the mmanage menu
	int userAccountIDInput;						//userinput as int to find which account - if the account even exists in the system
	char userAccountPasswordInput[PASSWORD_SIZE];  //password char array
	int foundAccountID = 0;				//this varible will store the ID entered by user and checks if it exists/created in the program
	bool flag = true;							//this flag will keep the program going unless user enters 5 to stop it


	//creating the class object
	BankAccount newAccount;

	cout << "Welcome to Banking Program main menu!" << endl;
	cout << "Please select one of the following options:" << endl;
	cout << "1. Manage an account" << endl;
	cout << "2. Create an account" << endl;
	cout << "3. Destroy an account" << endl;
	cout << "4. Exit the program" << endl;
	cin >> mainMenuUserInput;

	while (flag)
	{
		if (mainMenuUserInput == 1) 																			//Manage Account 
		{
			bool manageFlag = false;
			double moneyInput = 0.00f;

			//ask for userinput for which account he/she would like to delete
			cout << "Please enter the account ID you would like to manage." << endl;
			cin >> userAccountIDInput;
			//error check for correct userAccountIDInput
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Please enter correct input value for the acoount ID Now Try again: ";
				cin >> userAccountIDInput;
			}

			cout << "Please enter the account password you would like to manage." << endl;
			cin.ignore(INT_MAX, '\n');
			cin.getline(userAccountPasswordInput, PASSWORD_SIZE);
			//error check for correct userAccountPasswordInput
			while (cin.fail())
			{
				cin.clear();
				//cin.ignore(INT_MAX, '\n');
				cout << "Incorrect Input. Please try again!" << endl;
				cin.getline(userAccountPasswordInput, PASSWORD_SIZE);
			}

			//this will check if the entered id and password for the account are found in the system or not 
			foundAccountID = newAccount.searchAccount(userAccountIDInput, userAccountPasswordInput);

			//if not found show error message, else go to manage account sub menu 
			if (foundAccountID == -1)
			{
				cout << "Sorry the entered account ID with the password is not found in our system. Please try again." << endl;
			}
			else
			{
				manageFlag = true;
				cout << "Account ID and Password were accepted." << endl;
				cout << "Welcome to account ( " << foundAccountID << " ) management menu." << endl << endl;
			}

			while (manageFlag == true)
			{
				cout << "---------------------Option 1: Managing your Account...------------------------" << endl;
				cout << "Please select one of the following options: " << endl;
				cout << "1. Display balance" << endl;
				cout << "2. Deposit funds" << endl;
				cout << "3. Withdraw funds" << endl;
				cout << "4. Go to main menu" << endl;
				cin >> manageMenuUserInput;

				if (manageMenuUserInput == 1)																//Display Balance
				{
					cout << "1. Displaying balance" << endl;

					//calling displayBalance(id) method
					newAccount.displayBalance(foundAccountID);
				}
				else if (manageMenuUserInput == 2)													        //Deposit Money
				{
					cout << "2. Deposit funds" << endl;
					cout << "Please enter the amount you would like to deposit in your account: ";
					cin >> moneyInput;								//userinput for deposite amount

					//calling depositeAmount(id,money) method
					newAccount.depositeAmount(foundAccountID, moneyInput);

				}
				else if (manageMenuUserInput == 3)													        //Deposit Money
				{
					cout << "3. Withdrawing funds" << endl;
					cout << "Each withdraw will cost you $2.00 service fees." << endl;
					cout << "Please enter the amount you would like to withdraw from your account: ";
					cin >> moneyInput;							  //userinput for withdraw amount

					//calling withdrawAmount(id,money) method
					newAccount.withdrawAmount(foundAccountID, moneyInput);

				}
				else if (manageMenuUserInput == 4)												//Sign out and go back to main menu
				{

					cout << "4. Going back to main menu" << endl;
					cout << "Signing out from this account." << endl;
					break;
				}
				else
				{
					cout << "Invalid input. Please choose the options between 1 to 4." << endl;
				}
			}

		}
		else if (mainMenuUserInput == 2) 																       //Create Account 
		{
			cout << "---------------------Option 2: Creating new Account...------------------------" << endl;
			//calling createAccount() method
			newAccount.createAccount();

		}
		else if (mainMenuUserInput == 3) 																       //Delete Account
		{
			cout << "---------------------Option 3: Deleting the Account...------------------------" << endl;

			//ask for userinput for which account he/she would like to delete
			cout << "Please enter the account ID you would like to delete." << endl;
			cin >> userAccountIDInput;
			//error check for correct userAccountIDInput
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Please enter correct input value for the acoount ID Now Try again: ";
				cin >> userAccountIDInput;
			}

			cout << "Please enter the account password you would like to delete." << endl;
			cin.ignore(INT_MAX, '\n');
			cin.getline(userAccountPasswordInput, PASSWORD_SIZE);
			//error check for correct userAccountPasswordInput
			while (cin.fail())
			{
				cin.clear();
				//cin.ignore(INT_MAX, '\n');
				cout << "Incorrect Input. Please try again!" << endl;
				cin.getline(userAccountPasswordInput, PASSWORD_SIZE);
			}

			//this will check if the entered id and password for the account are found in the system or not 
			foundAccountID = newAccount.searchAccount(userAccountIDInput, userAccountPasswordInput);

			//if not found show error message, else call deleteAccount(id) method 
			if (foundAccountID == -1)
			{
				cout << "Sorry the entered account ID with the password is not found in our system. Please try again." << endl;
			}
			else
			{
				//calling deleteAccount(id) method
				newAccount.deleteAccount(foundAccountID);
			}
		}
		else if (mainMenuUserInput == 4) 																       //Close the program
		{
			cout << "---------------------Option 4: Stopping the program...------------------------" << endl;
			flag = false;
			exit(0);
		}
		else 																								//Invalid Input
		{
			cout << "Invalid input. Please choose the option between 1 to 4." << endl;
		}

		cout << endl << "Going back to the main menu. Please select what would you like to do next?" << endl;
		cout << "1. Manage an account" << endl;
		cout << "2. Create an account" << endl;
		cout << "3. Destroy an account" << endl;
		cout << "4. Exit the program" << endl;
		cin >> mainMenuUserInput;
	}
	return 0;
}