#include<iostream>
#include<iomanip>
#include<string>
#include"MyLibMath.h";
#include"MyLibFile.h";
#include"MyLibString.h";
#include"MyLiSeting.h";
using namespace std;


const string clientFile = "FileClint.txt";
const string FileUser = "User.txt";




void MainueList();
void TransactionMinu();
void MainueListUser();
void Login();


struct stUser {
	string UserName;
	string UserPassword;
	int Permesion;
};

stUser LoginUser;
struct sClient
{
	string nameClint;
	string numberacount;
	string PinCode;
	string PhonClint;
	double AcountBaliance;
	bool MarkForDelete = false;
};

enum enChiceListMainMunue {
	 enshowclient=1, enaddClient = 2,
	enDeleteClient=3, enUdateClient=4,
	enFindclient=5,
	enTransaction=6,
	enManegUser = 7,
	enExist=8
};
enum enTransactions {
	enDeposit=1,
	enWithdrow=2,
	enTotalBalances=3,
	enMainMunue=4

};


enum Permesion {
	enAll = -1,	enPShowClient = 1, enPAddClient = 2, enPDeleteClient = 4,
	enPUpdateclient = 8, enPFindClient = 16, enPTransection = 32, enPManegUser = 64
};


void ClearUser(stUser& User){
	User.UserName = "";
	User.UserPassword = "";
	User.Permesion = 0;
}


enum  ChoiceListUser
{
	enShowUser = 1, enAddUser = 2,
	enUpdateUser = 3, enDeleteUser = 4,
	enFindUser = 5, enExit = 6
};

bool ChackAccessPermision(Permesion enPer) {

	if ( LoginUser.Permesion == Permesion::enAll)
		return true;
	if ((LoginUser.Permesion & enPer) == enPer) 
		return true;
	else
		return false;
}

void ShowAccessDinaid() {
	cout << "\n------------------------------------\n";
	cout << "Access Denied , \n You dont Have Permission To Do this,\nPleasw Contact Your ";
	cout << "\n------------------------------------\n";
}




short ReadMainMunue() {

	short choice ;
	cout << "\nShoces what to do you want to do? [1 to 6] ?";
	cin>>choice;
	return choice;
}

sClient ConvertLinetoRecord(string stLine) {

	vector<string> clint = MyLibString::SplitString(stLine, "#\\#");
	sClient stclint;
	stclint.numberacount = clint[0];
	stclint.PinCode = clint[1];
	stclint.nameClint = clint[2];
	stclint.PhonClint = clint[3];
	stclint.AcountBaliance = stod(clint[4]);



	return stclint;

}


void PrintRecordClient(sClient stclint) {
	cout << "The Information Client:\n";
	cout << "Clien The Name :" << stclint.nameClint << endl;
	cout << "Clien The NumberAcount :" << stclint.numberacount << endl;
	cout << "Clien The  Pin:" << stclint.PinCode << endl;
	cout << "Clien The  PhonNumber:" << stclint.PhonClint << endl;
	cout << "Clien The  AcountBalince:" << stclint.AcountBaliance << endl;
}


string ConvertClinttoString(sClient stclint) {

	string line = stclint.numberacount + "#\\#" + stclint.PinCode + "#\\#" + stclint.nameClint + "#\\#" + stclint.PhonClint + "#\\#" + to_string(stclint.AcountBaliance);
	return line;
}



vector<string> ConvertClinttoLine(sClient stclint) {

	return  MyLibString::SplitString(ConvertClinttoString(stclint), "&");
}




void AddNewClient(sClient& stclint) {
	


	cout << "Enter The  Pin:";

	getline(cin >> ws, stclint.PinCode);

	cout << "Enter The Name :";
	getline(cin, stclint.nameClint);

	cout << "Enter The  PhonNumber:";
	getline(cin, stclint.PhonClint);

	cout << "Enter The  AcountBalince:";
	cin >> stclint.AcountBaliance;

	MyLibFile::SaveLineToFile(clientFile, ConvertClinttoString(stclint));

}



void UpdateClient(sClient& stclint) {
	
	cout << "Update Information Client Acount Number "<<stclint.numberacount<<":\n";

	cout << "Enter The  Pin:";
	getline(cin >> ws, stclint.PinCode);

	cout << "Enter The Name :";
	getline(cin, stclint.nameClint);

	cout << "Enter The  PhonNumber:";
	getline(cin, stclint.PhonClint);

	cout << "Enter The  AcountBalince:";
	cin >> stclint.AcountBaliance;
}


void TotalClient(int size) {

	cout << "\n" << MyLibString::Tabe(5) << "Client List(" << size << ") Clinets(s)";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(13) << "Numberacount";
	cout << "| " << left << setw(13) << "PaidCode";
	cout << "| " << left << setw(20) << "NameClint";
	cout << "| " << left << setw(12) << "PhonClint";
	cout << "| " << left << setw(12) << "ClintBlaince";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}



void TotalClientBalens(int size) {

	cout << "\n" << MyLibString::Tabe(5) << "Client List(" << size << ") Clinets(s)";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(13) << "Numberacount";
	cout << "| " << left << setw(20) << "NameClint";
	cout << "| " << left << setw(12) << "ClintBlaince";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}
void PrintClient(sClient clint) {

	cout << "| " << setw(13) << left << clint.numberacount;
	cout << "| " << setw(13) << left << clint.PinCode;
	cout << "| " << setw(20) << left << clint.nameClint;
	cout << "| " << setw(12) << left << clint.PhonClint;
	cout << "| " << setw(12) << left << clint.AcountBaliance;


}


void PrintBalenceClient(sClient clint) {

	cout << "| " << setw(13) << left << clint.numberacount;
	cout << "| " << setw(20) << left << clint.nameClint;
	cout << "| " << setw(12) << left << clint.AcountBaliance;


}

void PrintClientCard(sClient& clint) {
	cout << "\nInformation Client:\n";
	cout << "Numberacount :" << clint.numberacount << endl;
	cout << " PaidCode : " << clint.PinCode << endl;
	cout << "NameClint: " << clint.nameClint << endl;
	cout << " PhonClint :" << clint.PhonClint << endl;
	cout << " ClintBlaince : " << clint.AcountBaliance << endl;



}

double TotalBalinces(vector<sClient>& vClient){

	double total = 0;
	for(sClient &clien: vClient){
	
		total += clien.AcountBaliance;
	}
	return total;

}


void SaveVectirClientToFile(string filename, vector<sClient>& vclientUpdate) {
	MyLibFile::ClearFile(filename);

	for (sClient& line : vclientUpdate) {

		MyLibFile::SaveLineToFile(filename, ConvertClinttoString(line));
	}

}


void LoadDataUserFromFileToVector(string filename, vector<sClient>& vData) {
	fstream myfile;

	myfile.open(filename, ios::in);

	if (myfile.is_open()) {
		string line;
		while (getline(myfile, line)) {

			vData.push_back(ConvertLinetoRecord(line));
		}
		myfile.close();
	}

}



bool FindClientByAccountNumber(string ClientNumber, sClient& client, vector<sClient>& vclient) {

	LoadDataUserFromFileToVector(clientFile, vclient);


	for (sClient& clien : vclient) {
		if (clien.numberacount == ClientNumber) {
			clien.MarkForDelete = true;
			client = clien;
			return true;
		}
	}

	return false;
}


void GoBackMainMinue() {
	cout << "\n press any key to go back to main Muenu\n";
	system("pause>0");
	MyLiSeting::ClearScreen();
	MainueList();
}

void FindClient() {

	string clientNum;
	cout << "Pless Enter acount Number :";
	getline(cin >> ws ,clientNum);

	sClient client;
	vector<sClient> vclient;
	if (FindClientByAccountNumber(clientNum, client, vclient)) {
		cout << "client Is Sececse Fuind!\n";
		PrintClientCard(client);

	}
	else {
		cout << "client Is Not Fuind!\n";
	}

}
bool ValedateClientInFile(string ClientNumber) {
	sClient client;
	vector<sClient> vclient;
	return FindClientByAccountNumber(ClientNumber, client, vclient);
}

bool DeleteRecordFromfile(string AcountNumber, vector<sClient>& vclient) {


	vector<sClient> vclientUpdate;


	for (sClient& line : vclient) {
		if (!line.MarkForDelete) {

			vclientUpdate.push_back(line);
		}
		
	}

	SaveVectirClientToFile(clientFile, vclientUpdate);
	return true;

}

double UpdateBalences(double AcountBaliance, double Diposit){
	return (AcountBaliance + Diposit);
}



bool DipositBalencesToClientAcuentNumber(string AcountNumber, vector<sClient>& vclient, double Diposit) {


	

	for (sClient& line : vclient) {
		if (line.numberacount == AcountNumber) {
			line.AcountBaliance = UpdateBalences(line.AcountBaliance, Diposit);
			
			return true;
		}

		
	}

	
	return false;

}

void PrintAllClinets() {

	if (!ChackAccessPermision(Permesion::enPShowClient)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}
	vector<sClient>vclints;
	MyLiSeting::ClearScreen();
	LoadDataUserFromFileToVector(clientFile, vclints);

	TotalClientBalens(vclints.size());
	for (sClient& lin : vclints) {


		PrintBalenceClient(lin);
		cout << endl;

	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	

}

void printBalencesClinets() {
	vector<sClient>vclints;
	MyLiSeting::ClearScreen();
	LoadDataUserFromFileToVector(clientFile, vclints);

	TotalClientBalens(vclints.size());
	for (sClient& lin : vclints) {


		PrintBalenceClient(lin);
		cout << endl;

	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << MyLibString::Tabe(2) << "Total Balences :" << TotalBalinces(vclints) ;


}

void AddClient() {
	char addclient = 'Y';
	sClient stclint;
	string acountNum;
	do {
		cout << "add  Information Client:\n";
		cout << "Enter The ClintAcount :\n";
		cin>>acountNum;
		if (ValedateClientInFile(acountNum)) {
			cout << "Esist Acount Number clint In File\n";
			
		}
		else {
			stclint.numberacount = acountNum;
			AddNewClient(stclint);
		  }
		cout << "\nClient Add sececes Fuly , Do You Want To Add Mor Client ?";
		cin >> addclient;


	} while (addclient == 'y' || addclient == 'Y');


}


void DeleteClient() {
	char addclient = 'n';
	string clientNum;
	sClient client;
	vector<sClient> vclient;

	clientNum = MyLibString::ReadString("Pless Enter The client:");
	if (FindClientByAccountNumber(clientNum, client, vclient)) {


		PrintClientCard(client);

		cout << "\nare You Sure you want deleted client ? y/n ?";

		cin >> addclient;


		if (addclient == 'y' || addclient == 'Y') {

			DeleteRecordFromfile(client.numberacount, vclient);
			cout << "\n Deleted Client Number (" << clientNum << ") sececes Fuly!";

		}

	}
	else {

		cout << "\nClient Number Is(" << clientNum << ") Not sececes Fuly!";

	}





}

void UpdateClinetsToFile(string AcountNumber ,vector<sClient>& vClient) {

	for(sClient& clien: vClient){
	
		if (clien.numberacount == AcountNumber) {

			UpdateClient(clien);
			break;
		}
	
	}

	SaveVectirClientToFile(clientFile, vClient);

}

void UpdateClient() {
	char addclient = 'n';

	sClient client;
	vector<sClient> vclient;

	string clientNum;
	cout << "Pless Enter acount Number :";
	getline(cin >> ws, clientNum);

	
	if (FindClientByAccountNumber(clientNum, client, vclient)) {


		PrintClientCard(client);

		cout << "\nare You Sure you want Update client ? y/n ?";

		cin >> addclient;


		if (addclient == 'y' || addclient == 'Y') {

			UpdateClinetsToFile(client.numberacount ,vclient);
		
			cout << "\n Update Client Number (" << clientNum << ") sececes Fuly!";
		}
	}
	else {

		cout << "\nClient Number Is(" << clientNum << ") Not Found!";

	}
}



void GoBackTransictionMinue() {
	cout << "\n press any key to go back to main Muenu\n";
	system("pause>0");
	MyLiSeting::ClearScreen();
	TransactionMinu();
}


void DiposClient() {
	char addclient = 'n';
	string clientNum;
	sClient client;
	vector<sClient> vclient;
	double diposit = 0;
	clientNum = MyLibString::ReadString("Pless Enter The Anumber client:");

	while (!FindClientByAccountNumber(clientNum, client, vclient)) {

		clientNum = MyLibString::ReadString("Pless Enter The Anumber client:");
	}

		PrintClientCard(client);

		cout << "Enter Diposit :";
		cin >> diposit;
		

		cout << "\nare You Sure you want Diposit client ? y/n ?";
		cin >> addclient;
		if (addclient == 'y' || addclient == 'Y') {
			if (DipositBalencesToClientAcuentNumber(client.numberacount, vclient, diposit)) {
				SaveVectirClientToFile(clientFile, vclient);
				cout << "\n  Fuly Diposit TotalBalence(" << client.AcountBaliance + diposit << ") sececes !";
			}
			

		}

	}
	









void WithWardClient() {
	char addclient = 'n';
	string clientNum;
	sClient client;
	vector<sClient> vclient;
	double withward = 0;
	clientNum = MyLibString::ReadString("Pless Enter The Anumber client:");
	if (FindClientByAccountNumber(clientNum, client, vclient)) {


		PrintClientCard(client);
		cout << "Enter WithWard :";
		cin >> withward;

	
			while(withward > client.AcountBaliance){
				cout << "WithWard > Balences agine Enter WithWard :";
				cin >> withward;
			
			}

			cout << "\nare You Sure you want Diposit client ? y/n ?";

			cin >> addclient;

			if (addclient == 'y' || addclient == 'Y') {
				if (DipositBalencesToClientAcuentNumber(client.numberacount, vclient, withward*-1)) {

					SaveVectirClientToFile(clientFile, vclient);
					cout << "\n  Fuly WithWard TotalBalence(" << client.AcountBaliance - withward << ") sececes !";


			}
			
		}

	}
	else {

		cout << "\nClient Number Is(" << clientNum << ") Not sececes Fuly!";

	}





}

void ShowEndScreen(){
	cout << "\n------------------------------------";
	cout << MyLibString::Tabe(2) << "Programs end (:!\n";
	cout << "------------------------------------";


}
void ShowClientAddScreen() {
	if (!ChackAccessPermision(Permesion::enPAddClient)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}
	cout << "\n------------------------------------------";
	cout <<endl<< MyLibString::Tabe(1) << " Screen Add client:";
	cout << "\n--------------------------------------------\n";
	AddClient();

}

void ShowClientDeletScreen() {

	if (!ChackAccessPermision(Permesion::enPDeleteClient)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}
	cout << "\n------------------------------------------";
	cout << endl << MyLibString::Tabe(1) << " Screen Delet client:";
	cout << "\n--------------------------------------------\n";
	DeleteClient();

}

void ShowClientudateScreen() {
	if (!ChackAccessPermision(Permesion::enPUpdateclient)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}
	cout << "\n------------------------------------------";
	cout << endl << MyLibString::Tabe(2) << " Screen Udate client:";
	cout << "\n--------------------------------------------\n";
	UpdateClient();

}

void ShowClientFindScreen() {
	if (!ChackAccessPermision(Permesion::enPFindClient)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}
	cout << "\n------------------------------------------";
	cout <<endl <<MyLibString::Tabe(2) << " Screen find client:";
	cout << "\n--------------------------------------------\n";
	FindClient();
}
void DipostScreen() {

	cout << "\n------------------------------------------";
	cout << endl << MyLibString::Tabe(2) << " Dipost Screen :";
	cout << "\n--------------------------------------------\n";
	DiposClient();
}
void WithDrawScreen() {

	cout << "\n------------------------------------------";
	cout << endl << MyLibString::Tabe(2) << " With Draw Screen :";
	cout << "\n--------------------------------------------\n";
	WithWardClient();
}

void TotalBalencesScreen() {

	cout << "\n------------------------------------------";
	cout << endl << MyLibString::Tabe(2) << " Total Balences Screen :";
	cout << "\n--------------------------------------------\n";
	 printBalencesClinets();

}

void ShoiceTransection(enTransactions entransaction) {

	switch (entransaction) {
	case enTransactions::enDeposit:
		MyLiSeting::ClearScreen();
		DipostScreen();
		GoBackTransictionMinue();
		break;
	case enTransactions::enWithdrow:
		MyLiSeting::ClearScreen();
		WithDrawScreen();
		GoBackTransictionMinue();
		break;

	case enTransactions::enTotalBalances:
		MyLiSeting::ClearScreen();
		TotalBalencesScreen();
		GoBackTransictionMinue();
		break;

	case enTransactions::enMainMunue:
		MyLiSeting::ClearScreen();
		MainueList();

		break;

	}

}






void WrihtUser(stUser user) {
	cout << "Ditals Information User!\n";
	cout << "User Name :" << user.UserName << endl;
	cout << "User Password :" << user.UserPassword << endl;
	cout << "User Permesion :" << user.Permesion << endl;

}
void StartSystemBank(enChiceListMainMunue enChoice) {
	
         switch(enChoice){
		 
		 case enChiceListMainMunue::enshowclient:
				 MyLiSeting::ClearScreen();
				 PrintAllClinets();
				 GoBackMainMinue();
			
			 break;

			 case enChiceListMainMunue::enaddClient:
				
					 MyLiSeting::ClearScreen();
					 ShowClientAddScreen();
					 GoBackMainMinue();
					 break;
				
				
			 break;
			 case enChiceListMainMunue::enDeleteClient:
			
					 MyLiSeting::ClearScreen();
					 ShowClientDeletScreen();
					 GoBackMainMinue();
			
				
			 break;
			 case enChiceListMainMunue::enUdateClient:
		
					 MyLiSeting::ClearScreen();
					 ShowClientudateScreen();
					 GoBackMainMinue();
			
			 break;
			 case enChiceListMainMunue::enFindclient:
			
					 MyLiSeting::ClearScreen();
					 ShowClientFindScreen();
					 GoBackMainMinue();
			
			 break;
			 case enChiceListMainMunue::enTransaction:
				 
					 MyLiSeting::ClearScreen();
					 TransactionMinu();
					 GoBackMainMinue();
				
				 break;
			 case enChiceListMainMunue::enManegUser:
			
					 MyLiSeting::ClearScreen();
					 MainueListUser();
					 GoBackMainMinue();
				 break;

			 case enChiceListMainMunue::enExist:
				 MyLiSeting::ClearScreen();
				 ClearUser(LoginUser);
				 Login();
			 break;
		 }

	

}

void MainueList() {
	MyLiSeting::ClearScreen();
	cout << "\n======================================================";

	cout << "\n" << MyLibString::Tabe(2) << "Main Munue Screen!";
	cout << "\n======================================================\n";

	cout << MyLibString::Tabe(2) << "[ 1 ] Show Clients List" << endl;
	cout << MyLibString::Tabe(2) << "[ 2 ] Add CLient." << endl;
	cout << MyLibString::Tabe(2) << "[ 3 ] Delete Client." << endl;
	cout << MyLibString::Tabe(2) << "[ 4 ] Udate Client." << endl;
	cout << MyLibString::Tabe(2) << "[ 5 ] Found Client." << endl;
	cout << MyLibString::Tabe(2) << "[ 6 ] Transaction." << endl;
	cout << MyLibString::Tabe(2) << "[ 7 ] Manage User." << endl;
	cout << MyLibString::Tabe(2) << "[ 8 ] Login Screen." << endl;
	cout << "\n======================================================";

	StartSystemBank((enChiceListMainMunue)ReadMainMunue());

}


void TransactionMinu() {
	if (!ChackAccessPermision(Permesion::enPTransection)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}
	cout << "\n======================================================";

	cout << "\n" << MyLibString::Tabe(2) << "Transection Munue Screen!";
	cout << "\n======================================================\n";

	cout << MyLibString::Tabe(2) << "[ 1 ] Diposit" << endl;
	cout << MyLibString::Tabe(2) << "[ 2 ] WithDraw." << endl;
	cout << MyLibString::Tabe(2) << "[ 3 ] Total Balences." << endl;
	cout << MyLibString::Tabe(2) << "[ 4 ] Main Menu." << endl;

	cout << "\n======================================================";

	ShoiceTransection((enTransactions)ReadMainMunue());
}


//permison star


short Permision(Permesion per) {
	switch (per) {

	case Permesion::enPShowClient:
		return Permesion::enPShowClient;
		break;
	case Permesion::enPAddClient:
		return  Permesion::enPAddClient;
		break;
	case Permesion::enPDeleteClient:
		return  Permesion::enPDeleteClient;
		break;
	case Permesion::enPFindClient:
		return  Permesion::enPFindClient;
		break;
	case Permesion::enPTransection:
		return  Permesion::enPTransection;
		break;
	case Permesion::enPUpdateclient:
		return  Permesion::enPUpdateclient;
		break;
	}

}

bool validatePermasion(string messag) {
	string  add;
	cout << messag;
	cin >> add;
	while (MyLibString::LowerAllString(add) == "y" || MyLibString::LowerAllString(add) == "n") {
		if (add == "y")return true;
		else return false;

	}
}

short ReadPermisoin() {

	short permision = 0;

	if (validatePermasion("Do You all Permisions all System !"))return -1;

	while (true) {

		if (validatePermasion("Permision Show List y/n ? ")) {
			permision += Permision(Permesion::enPShowClient);
		}
		if (validatePermasion("Permision  Add Client y/n ? ")) {
			permision += Permision(Permesion::enPAddClient);
		}
		if (validatePermasion("Permision Delete CLient y/n ? ")) {
			permision += Permision(Permesion::enPDeleteClient);
		}
		if (validatePermasion("Permision Find Client y/n ? ")) {
			permision += Permision(Permesion::enPFindClient);
		}
		if (validatePermasion("Permision Update Client y/n ? ")) {
			permision += Permision(Permesion::enPUpdateclient);
		}
		if (validatePermasion("Permision Transection y/n ? ")) {
			permision += Permision(Permesion::enPTransection);
		}

		if (validatePermasion("Permision Maneger User y/n ? ")) {
			permision += Permision(Permesion::enPManegUser);

		}
		return permision;

	}
	return permision;

}
//permasion end 


// ConvertLineUsertoRecord

stUser ConvertLineUsertoRecord(string UserLine) {

	vector<string>vUsers = MyLibString::SplitString(UserLine, "#\\#");
	stUser User;
	User.UserName = vUsers[0];
	User.UserPassword = vUsers[1];
	User.Permesion = stoi(vUsers[2]);
	return User;
}

//ConvertUsertoString
string ConvertUsertoString(stUser stUser) {

	string line = stUser.UserName + "#\\#" + stUser.UserPassword + "#\\#" + to_string(stUser.Permesion);
	return line;
}


//Load Data File
void LoadDataUserFromFileToVector(string filename, vector<stUser>& vData) {
	fstream myfile;

	myfile.open(filename, ios::in);

	if (myfile.is_open()) {
		string line;
		while (getline(myfile, line)) {

			vData.push_back(ConvertLineUsertoRecord(line));
		}
		myfile.close();
	}

}

//FindUser
bool FindUserByName(string UserName, stUser& User, vector<stUser>& vUser) {
	
	LoadDataUserFromFileToVector(FileUser , vUser);
	for(stUser &users :vUser){
		if (users.UserName == UserName) {
			User = users;
			return true;
	}
	
	}
	return false;
}
 
//Save Item Vector To File
void  SaveVectirUserToFile(string FileName,vector<stUser>vUser){
	MyLibFile::ClearFile(FileName);
	for (stUser& user : vUser) {

		MyLibFile::SaveLineToFile(FileName, ConvertUsertoString(user));

	}



}







//Update User Start
void UpdateUserToFile(string UserName,stUser user ,vector<stUser>& vUser) {

	for (stUser& users : vUser) {
		if (users.UserName == UserName) {
			users.UserPassword = user.UserPassword;
			users.Permesion = user.Permesion;
			break;
		}

	}

	SaveVectirUserToFile(FileUser, vUser);
	
}

void ReadUpdateUser(stUser& NewUser) {

	cout << "\nEnter User Name :";
	cout << "********";
	cout << "\nEnter User Password :";
	getline(cin >> ws, NewUser.UserPassword);

	cout << "\nEnter Permasions :";
	NewUser.Permesion = ReadPermisoin();

	
}

void UpdateUser() {
	char UpdateUser = 'n';

	stUser User;
	vector<stUser> vUser;

	string UserName;
	cout << "Pless Enter UesrName :";
	getline(cin >> ws, UserName);


	if (FindUserByName(UserName , User ,vUser)) {


		WrihtUser(User);
	
		cout << "\nare You Sure you want Update User ? y/n ?";

		cin >> UpdateUser;


		if (UpdateUser == 'y' || UpdateUser == 'Y') {
			ReadUpdateUser(User);
			UpdateUserToFile(UserName,User ,vUser);

			cout << "\n Update User Name (" << UserName << ") sececes Fuly!";
		}
	}
	else {

		cout << "\UserName Is(" << UserName << ") Not Found!";

	}

}


void UpdateScreen(){
	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Screen Update User !!";
	cout << "\n======================================================\n";
	UpdateUser();
}

void ShowScereenUpdateUser() {
	char Updateuser = 'n';
	do {
		MyLiSeting::ClearScreen();
		UpdateScreen();

		cout << "\nare You Sure you want Update User agine ? y/n ?";

		cin >> Updateuser;

	} while (tolower(Updateuser) == 'y');


}

//End Update User 








//Start Delete User

void DeleteUserToFile(string UserName,vector<stUser>& vUser) {
	  MyLibFile::ClearFile(FileUser);
	for (stUser& users : vUser) {
		if (users.UserName != UserName) 
		MyLibFile::SaveLineToFile(FileUser, ConvertUsertoString(users));
			
	}

	

}

void DeleteUser() {
	char deleteUser = 'n';

	stUser User;
	vector<stUser> vUser;

	string UserName;
	cout << "Pless Enter UesrName To Deleted :";
	getline(cin >> ws, UserName);


	if (FindUserByName(UserName, User, vUser)) {


		WrihtUser(User);

		cout << "\nare You Sure you want Delete User ? y/n ?";

		cin >> deleteUser;


		if (deleteUser == 'y' || deleteUser == 'Y') {
			if (User.UserName == LoginUser.UserName) {
				cout << "I Cant No Deleted Yourself UserName (" << LoginUser.UserName << ")!\n";
				return;
			}
			
			DeleteUserToFile(UserName,vUser);

			cout << "\n Deleted User Te  Name (" << UserName << ") sececes Fuly!";
		}
	}
	else {

		cout << "\UserName Is(" << UserName << ") Not Found!";

	}

}

void DeletedScreen() {
	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Screen Deleted User !!";
	cout << "\n======================================================\n";
	DeleteUser();
}

void ShowScereenDeleteUser() {
	char Deleteuser = 'n';
	do {
		MyLiSeting::ClearScreen();
		DeletedScreen();

		cout << "\nare You Sure you want Deleted User agine ? y/n ?";

		cin >> Deleteuser;

	} while (tolower(Deleteuser) == 'y');


}

//End Deleted User






//Start Find User


void FindUser() {
	

	stUser User;
	vector<stUser> vUser;

	string UserName;
	
	cout << "Pless Enter UesrName To Find :";
	getline(cin >> ws, UserName);

	while (FindUserByName(UserName, User, vUser)) {

		if (FindUserByName(UserName, User, vUser)) {


			WrihtUser(User);

		}
		else {
			cout << "User Name :(" << UserName << ")Not Found :(-\n";
		}

	}


	
}


void FindScreen() {
	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Screen Find User !!";
	cout << "\n======================================================\n";
	FindUser();
}


void ShowScereenFindUser() {
	char Finduser = 'n';
	do {
		MyLiSeting::ClearScreen();
		FindScreen();

		cout << "\nare You Sure you want Deleted User agine ? y/n ?";

		cin >> Finduser;

	} while (tolower(Finduser) == 'y');


}

//End Find User







//Start User
void AddUser(stUser& NewUser) {

	cout << "\nEnter User Name :";
	getline(cin >> ws, NewUser.UserName);

	cout << "Enter User Password :";
	getline(cin, NewUser.UserPassword);

	NewUser.Permesion = ReadPermisoin();

	MyLibFile::SaveLineToFile(FileUser, ConvertUsertoString(NewUser));
}

void AddNewUser() {

	char MorAdd = 'y';
	stUser NewUser;

	do {

		cout << "Enter  The Information User :";
		AddUser(NewUser);
		cout << "secsess Full add User ,Doy You agin Add y/n ?";
		cin >> MorAdd;

	} while (MorAdd == 'y' || MorAdd == 'Y');

}

void UsaerScreen() {

	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Screen add !!";
	cout << "\n======================================================\n";

	AddNewUser();
}



void ShowScereenAddUser() {
	char Adduser = 'n';
	do {
		MyLiSeting::ClearScreen();
		UsaerScreen();

		cout << "\nare You Sure you want Deleted User agine ? y/n ?";

		cin >> Adduser;

	} while (tolower(Adduser) == 'y');


}



//End Add User







void PrintUsers(stUser user) {

	cout << "| " << setw(13) << left << user.UserName;
	cout << "| " << setw(15) << left << user.UserPassword;
	cout << "| " << setw(5) << left << user.Permesion;
}


void GetToBackManegScreen() {
	cout << "\n press any key to go back to main Muenu\n";
	system("pause>0");
	MyLiSeting::ClearScreen();
	MainueListUser();
}






//start show User
void ShowListUsers(vector<stUser>vuser) {

	cout << "\n" << MyLibString::Tabe(2) << "User List(" << vuser.size() << ") Users(s)";
	cout << "\n_____________________________";
	cout << "___________________________________\n" << endl;
	cout << "| " << left << setw(13) << "User Name";
	cout << "| " << left << setw(15) << "User Password";
	cout << "| " << left << setw(5) << " User Permison";

	cout <<
		"\n_____________________________";
	cout << "___________________________________\n" << endl;
	for (stUser& user : vuser) {
		PrintUsers(user);
		cout << endl;
	}
	
}

void LoadUserall() {
	vector<stUser>vuser;
	LoadDataUserFromFileToVector(FileUser, vuser);
	ShowListUsers(vuser);
}

void ShowScreenUsers() {

	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Screen User List!";
	cout << "\n======================================================\n";
	LoadUserall();
}

//End show User







void ShoiceListMenueUser(ChoiceListUser chois) {

	switch (chois) {
	case ChoiceListUser::enAddUser:
		MyLiSeting::ClearScreen();
		ShowScereenAddUser();
		GetToBackManegScreen();
		break;
	case ChoiceListUser::enShowUser:
		MyLiSeting::ClearScreen();

		ShowScreenUsers();
		GetToBackManegScreen();
		break;
	case ChoiceListUser::enUpdateUser:
		MyLiSeting::ClearScreen();

		ShowScereenUpdateUser();
		GetToBackManegScreen();
		break;
	case ChoiceListUser::enDeleteUser:
		MyLiSeting::ClearScreen();

		ShowScereenDeleteUser();
		GetToBackManegScreen();

		break;
		
	case ChoiceListUser::enFindUser:
		MyLiSeting::ClearScreen();
		ShowScereenFindUser();
		GetToBackManegScreen();

		break;

	case ChoiceListUser::enExit:
		MyLiSeting::ClearScreen();
		MainueList();
		break;

	}
}

void MainueListUser() {

	if (!ChackAccessPermision(Permesion::enPManegUser)) {
		ShowAccessDinaid();
		GoBackMainMinue();
		return;
	}

	cout << "\n======================================================";

	cout << "\n" << MyLibString::Tabe(2) << "User Munue Screen!";
	cout << "\n======================================================\n";

	cout << MyLibString::Tabe(2) << "[ 1 ] User List" << endl;
	cout << MyLibString::Tabe(2) << "[ 2 ] Add User." << endl;
	
	cout << MyLibString::Tabe(2) << "[ 3 ] Udate User." << endl;
	cout << MyLibString::Tabe(2) << "[ 4 ] Delete User." << endl;
	cout << MyLibString::Tabe(2) << "[ 5 ] Found User." << endl;
	cout << MyLibString::Tabe(2) << "[ 6 ] Main Menue ." << endl;
	cout << "\n======================================================";
	ShoiceListMenueUser((ChoiceListUser)ReadMainMunue());
}







//Start Login User 

bool ValidateUserNameAndPassword(string UserName,string UserPassWord, stUser User) {
	
		if (UserName == User.UserName  && UserPassWord == User.UserPassword) {
			
			return true;
		}


	    return false;
}

bool LoadUserInfo(string UserName , string UserPassword) {
	
	vector<stUser> vUser;
	
	if (FindUserByName(UserName,LoginUser , vUser)) {

		if (ValidateUserNameAndPassword(UserName, UserPassword, LoginUser))
			return true;
		else false;
	}
	else  return false; 

}


void LoginScreeen() {
	MyLiSeting::ClearScreen();
	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Login Screen !!";
	cout << "\n======================================================\n";



}

void Login() {

	string UserPassword , UserName ;


	bool LoadFalid = false;

	do {
		LoginScreeen();
		if (LoadFalid) {

			cout << "Invalid / UserName / Password !\n";
		}
		cout << "Enter UesrName:";
		getline(cin >> ws, UserName);
		cout << "Enter UserPassword:";
		getline(cin >> ws, UserPassword);

		LoadFalid = !LoadUserInfo(UserName, UserPassword);

	} while (LoadFalid);

		MainueList();

}





//End Login User





int main() {

	
	Login();

	
	system("pause>0");
	return 0;
}