/*      
 * AUTHOR: Jianqiao Zhou
 
 * STUDENT NUMBER:200121495
 	 
 * CREATION DATE: Nov 29 2014 
 *
 * PROBLEM STATEMENT:  (This is a simple inventory program storging simple person profile which includes name, age, height and 
 						nationality.User can input,edit,remove,display,search,sort profile record.  )
 * 
 * PROGRAM DESCRIPTION:  (describe how your program solves the   
 *                        problem and describe any cool stuff
 *                        you've done also)
 *
 * RUN INSTRUCTIONS: (as the title says PLUS a listing of input
 *                    that shows off your program)
 */
 



#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cstdlib>
#include<vector> 
#include<fstream> 

using namespace std;


struct personProfile{
	string name;
	string age;   
	string height;
	string nationality;
	
};
//This is a struct storing a profile of a person

void getRecord(vector<personProfile>& );//get record from keyboard
void disPlay(const vector<personProfile>& );//display the record
void sortbyName(vector<personProfile>&);//sort records by name 
void sortbyAGE(vector<personProfile>&);//sort records by age
void findRecord(const vector<personProfile>& );//search the record
int sbfindRecord(const vector<personProfile>& );//get the index number of the record user wants to find
void openFile(vector<personProfile>& );//open a file which stores records
void saveFile(vector<personProfile>& );//save the record in memory into a text file
void removeRecord(vector<personProfile>&);//delete the record
void editRecord(vector<personProfile>&);//edit the record





int main()
{
	vector<personProfile>profiles;//container for storing record
	char select;//identifier of selection of function
	cout<<"Welcomte to profile system!"<<endl;
	
	do{
	cout<<"Select the function you want \n(G)et Record\n(F)ind Record\n(D)isplay Name\n(R)emove Rcord\n(S)ort by Name"<<
	"\n(A)sort by Age\n(V)saveFile\n(O)penFile\n(E)dit record"<<endl;
	cin>>select;
    cin.ignore(256, '\n');
    
	switch(toupper(select))
	{
		case 'G' : getRecord(profiles);break;
		case 'D' : disPlay(profiles);break;
		case 'R' : removeRecord(profiles);break;
		case 'S' : sortbyName(profiles);break;	
		case 'A' : sortbyAGE(profiles);break;
		case 'F' : findRecord(profiles);break;
	//  case 'i': indexSearch(profiles);break; 
	    case 'O': openFile(profiles);break;
	    case 'V': saveFile(profiles);break;
	    case 'E': editRecord(profiles);break;
	}
	}while(select!='q');
	
	
}


  /*
   * TASK:     Get record including name, age, height and nationality from keyboard. User can get record as many as you want.
   			   user can quit at any step.
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None
   *
   * MODIFIES: The vector is pass-by-reference.
   */
	
void getRecord(vector<personProfile>& profiles){
while (true)
	{	  int input;
		  string tmp;
		  stringstream ss;
		  string response;
		  personProfile addData;
		  cout<<"Enter the name(Firstname, Lastname or q to stop): ";
		  getline(cin,tmp);
		  if (tmp == "q") break;  
		  else
		  addData.name=tmp;
		  cout<<"Enter the age(in integer) : ";
		  getline(cin,tmp);
		  if (tmp == "q") break;
		  addData.age=tmp;
		  cout<<"Enter the height(in integer)(kg) : ";
		  getline(cin,tmp);
		  if (tmp == "q") break;  
		  addData.height=tmp;
		  cout<<"Enter the nationality : ";
		  getline(cin,tmp);
		  if (tmp == "q") break;  
		  addData.nationality=tmp;
		  cout<< "Add the record to the system? (y/n):";
		  getline(cin,response);
	      if(response=="y")
		  { 
		  profiles.push_back(addData);
		  cout<<"The profile has been added into system"<<endl;
		  cout<<endl;
		  } 
	}
		


		  
  /*
   * TASK:     Sort records by name using bubble sort algorithm  
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */


}
void sortbyName(vector<personProfile>& profiles)
{
		//if nothing in the container, cout nothing to sort and quit the function.
		if(profiles.size()==0)
		cout<<"Nothing to sort"<<endl;
		else
		{
			//bubble sort
		for (int i = 1; i <profiles.size(); i++)
	    	for (int j = 0; j < profiles.size()-i; j++) 
			{
		      if(profiles[j].name>profiles[j+1].name)
			  { 
			  	swap(profiles[j],profiles[j+1]);
		  	
		  	  }  
   
    		}
    	cout<<endl;
		cout<<"Record have been sorted by Name"<<endl;	
		}
    		
}



  /*
   * TASK:     Sort records by age using bubble sort algorithm  
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */

void sortbyAGE(vector<personProfile>& profiles)
{
		//if nothing in the container, cout nothing to sort and quit the function.
		if(profiles.size()==0)
		cout<<"Nothing to sort"<<endl;
		else
		{
		//bubble sort
		for(int i =1;i<profiles.size();i++)
			for(int j=0;j<profiles.size()-i;j++)	
			{
				if(profiles[j].age>profiles[j+1].age)
				swap(profiles[j],profiles[j+1]);
			}
		cout<<endl;
		cout<<"Record have been sorted by Age"<<endl;
		}
}


  /*
   * TASK:     Search the record by entering the name storing in the container 
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */

void findRecord(const vector<personProfile>& profiles)
{
	////if nothing in the container, cout nothing to sort and quit the function.
	if(profiles.size()==0)
		cout<<"Nothing to sort, enter name first"<<endl;
	else
	{
		//if such a record found, displey the record.
		int index;
		index=sbfindRecord(profiles);
		if(index>=0)
		{
			cout<<"Found the record ! "<<endl;
			cout<<"Number     Name        age       height(kg)     nationality"<<endl; 
			cout<<setw(4)<<left<<index+1<<'\t'<<"   "<<profiles[index].name<<'\t'<<profiles[index].age<<'\t'<<" "<<profiles[index].height<<
			'\t'<<'\t'<<profiles[index].nationality; 
			cout<<endl;
		}
		
		else
		//if no such a record found,cout No name match.
			cout<<"No name match"<<endl;
			
	}

}



/*
   * TASK:    Find the index number by the name    
   *
   * ACCEPTS:  The const perosonProfile type vector.
   *
   * RETURNS:  The index of the name that user wants to find.
   *
   * MODIFIES: None
*/
int sbfindRecord(const vector<personProfile>& sbProfiles)
{
	
	string name;
	cout<<"Enter the name field of record that  you want to find : ";
	getline(cin,name);
	cout<<endl;
	for(int i=0; i<sbProfiles.size(); i++)
		{
		// return the index number to findrecord if the record found.
   		if (sbProfiles[i].name ==name) return i;
		}
    	return -1; 

}


  /*
   * TASK:    Edit the record. however, if the record does not contained in the container, the record cannot be edited.   
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */

void editRecord(vector<personProfile>& profiles)
{
	disPlay(profiles);
	cout<<"Enter the name in the record you want to edit: ";
	string name;
	getline(cin,name);
	for(int i=0;i<profiles.size();i++)
	{
		//if such a name found, starting edit the record
		if(profiles[i].name==name)
		{
			personProfile newprofile;
			string n;
			cout<<"Enter a new name(Firstname, Lastname) :"<<endl;
			getline(cin,n);
			profiles[i].name=n;
			cout<<"Enter a new age :"<<endl;
			getline(cin,n);
			profiles[i].age=n;
			cout<<"Enter a new height :"<<endl;
			getline(cin,n);
			profiles[i].height=n;
			cout<<"Enter a new nationality :"<<endl;
			getline(cin,n);
			profiles[i].nationality=n;
			cout<<"The record has been edited "<<endl;
		}
		
	cout<<"No such a record "<<endl; 
	}
}


 /*
   * TASK:    Open the text file which have 5 records and store the record into container.   
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */

void openFile(vector<personProfile>& profiles)
{
	
	ifstream fin;
	string fileName;
	string str;
	char response;
	//if the memory buffer already has records, prompt warning message because it will overwrite the buffer and erase the contents in buffer.
	if(!profiles.size()==0)
	{
		cout<<"WARNING:REALLY WANT TO OPEN THE FILE? (y/n)";
		cin>>response;
		cin.ignore();
		if(response=='y')
		{
			//erase the buffer
			profiles.clear();
			fin.open("file.txt");     
			if (fin.fail()) 
			{
			    cerr << "could not open intput file "<<endl;
			    cout<<endl;
			}
			else
				//read the file and getline file contents until the end of the file
				while (fin.peek()!=EOF) 
				{ 
					personProfile openData;
				    getline(fin, str,';');	
					openData.name = str;
				 	
				 	getline(fin, str, ';');
				 	openData.age = str;
				 	
				 	getline(fin, str,';');
				 	openData.height = str;
				 
				 	getline(fin, str);
				 	openData.nationality = str;
				    
					profiles.push_back(openData);

		    
				}
					cout<<profiles.size()<<" records have been read "<<endl;
		
			fin.close();
		}
		    system("cls");
	}
		else
		//if no record existed in the buffer, just open the file.
			fin.open("file.txt");     
			
			if (fin.fail()) 
			{
			    cerr << "could not open intput file "<<endl;
			    cout<<endl;
			}
			else
			{	
			//read the file and getline file contents until the end of the file
				while(fin.peek()!=EOF) 
				{ 
					personProfile openData;
				    // note the termination condition
				    getline(fin, str,';');	
					openData.name = str;
				 	
				 	getline(fin, str, ';');
				 	openData.age = str;
				 	
				 	getline(fin, str,';');
				 	openData.height = str;
				 
				 	getline(fin, str);
				 	openData.nationality = str;
				    profiles.push_back(openData);

			    }	
				cout<<profiles.size()<<" records have been read "<<endl;
		
			fin.close();
			}
		
	
	}
	
/*
   * TASK:   Save the contente in the buffer into a text file.  
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */
void saveFile(vector<personProfile>& profiles)
{
	char response;
	//prompt a waring message if there are records storing in the buffer.
	if(!profiles.size()==0)
	{
		cout<<"WARNING:REALLY WANT TO SAVE THE FILE? (y/n)";
		cin>>response;
		cin.ignore(256,'\n');
		if(response=='y'){
			string fileName;
			//name the file
			cout<<"Enter the file name you want save :";
			cin>>fileName;
			cin.ignore(256,'\n');
			ofstream fout(fileName.c_str());
			
			if(fout.fail()){
				cerr<<"could not save files "<<endl;
				cout<<endl;
			}
			//put the records in the buffer into text file. per groud of groupd per line
			for(int i=0;i<profiles.size();i++)
			{
			fout<<profiles[i].name<<';'
				<<profiles[i].age<<';'
				<<profiles[i].height<<';'
				<<profiles[i].nationality;
			fout<<endl;
				
				
			}
				fout.close();
				system("PAUSE");
		 		system("cls");
			}
		cout<<endl<<profiles.size()<<" records have been saved"<<endl;
		
	}
	
}




/*
   * TASK:   Delete the record by entering a name.  
   *
   * ACCEPTS:  The perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */
void removeRecord(vector<personProfile>& profiles)
{	string removerecord;
	int recordFound;
	//if no record stored in the buffer
	if(profiles.size()==0)
	cout<<"No record, please enter a name first"<<endl;
	else
	//if there is at least one record stored in the buffer
	{
		cout<<"Enter the name(Firstname, Lastname) of record you want to remove"<<endl;
		getline(cin,removerecord);
		for(int i=0; i<profiles.size();i++)
		{ 
		//if the name is found, return the index of the record
		    if(profiles[i].name==removerecord)
		    recordFound=i;
		    else
		    //if the name is not found ,return -1
		    recordFound=-1;
		    
		}
		if(recordFound==-1)
		cout<<"No Matching Record"<<endl;
		else
		{
			//the name is found, erase the record containing the name just entered
		    profiles.erase(profiles.begin()+recordFound);
			cout<<"The record has been erased"<<endl;
			
		}
	
	
	}
}
	


/*
   * TASK:  Display the record
   *
   * ACCEPTS:  The const perosonProfile type vector.
   *
   * RETURNS:  None.
   *
   * MODIFIES: The vector is pass-by-reference.
   */


void disPlay(const vector<personProfile>& profiles)
{	cout<<"Number     Name           age       height(kg)     nationality"<<endl; 
	for(int i=0;i<profiles.size();i++)
	{
		cout<<setw(4)<<left<<i+1<<'\t'<<"   "<<profiles[i].name<<'\t'<<"   "<<profiles[i].age<<'\t'<<"    "<<profiles[i].height<<
		'\t'<<'\t'<<profiles[i].nationality; 
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
	
}

