#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
const string FileClinte = "Clinte.txt";


struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;

	string Phone;
	double AccountBalance = 0;


};


vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}




sClient ConvertLinetoRecord(string Line, string Seperator =
	"#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to

	return Client;
}


vector<sClient> LoadCleintsDataFromFile(string FileMy)
{

	vector<sClient> vClinte;
	fstream myFile;
	myFile.open(FileMy, ios::in);


	if (myFile.is_open())
	{

		string Line;
		sClient Clinte;
		while (getline(myFile, Line))
		{

			Clinte = ConvertLinetoRecord(Line);

			vClinte.push_back(Clinte);
		}
		myFile.close();
	}


	return vClinte;

}

bool FindClientByAccountNumber(string AcuontNumber, sClient& Client)
{

	for (sClient& Clinte : LoadCleintsDataFromFile(FileClinte))
	{
		if (Clinte.AccountNumber == AcuontNumber)
		{
			Client = Clinte;
			return true;
		}
	}
	return false;
}

string ReadClientData(sClient& Client)
{
	string AccountNumber = "";
	cout << "Enter Account Number: ";
	cin >> AccountNumber;
	return AccountNumber;


}

void PrintClientRecord(sClient Client)
{
	cout << "AccountNumber : " << Client.AccountNumber << endl;
	cout << "PinCode      : " << Client.PinCode << endl;
	cout << "Name         : " << Client.Name << endl;
	cout << "Phone        : " << Client.Phone << endl;
	cout << "AccountBalance: " << Client.AccountBalance << endl;
}













int main()
{
	sClient Client;
	string AccountNumber = ReadClientData(Client);
	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientRecord(Client);
	}
	else
	{
		cout << "Client Not Found" << endl;
	}
	system("pause>0");

	return 0;
}
