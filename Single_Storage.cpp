# A simple inventory program which can store, sort, delete, find items 


#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cstdlib>
#include<vector> 
#include<fstream> 
using namespace std;




void getName(vector<string>& );
void findName(vector<string>&);
void disPlay(vector<string>&);
int sbfindName(vector<string>&);
void removeName(vector<string>&);
void sortName(vector<string>&); 
void testData(vector<string>&);
string sWap(string);
void getLastNameList(vector<string>&);
string lastNames(vector<string>&); 
int getNumInRange(int , int ); 
void indexSearch(vector<string>&);
void openFile(vector<string>&);
void saveFile(vector<string> & );
 



int main()
{
	vector<string> names;
	int size=0;
	char select;
	
	
	do{
	cout<<"Select the function you want \n(g)etname\n(f)indname\n(d)isplayname\n(r)emoveName\n(s)ort the vector\n(q)uit\n(t)estdata\n"
	<<"(l)getlastnamelist \n(i)ndexsearch\n(o)penfile\n(v)savefile "<<endl;
	cin>>select;
    	cin.ignore(256, '\n');
	switch(select)
	{
		case 'g' : getName(names);break;
		case 'f' : findName(names);break;
		case 'd' : disPlay(names);break;
		case 'r' : removeName(names);break;
		case 's' : sortName(names);break;	
	    case 't': testData(names);break;
	    case 'l': getLastNameList(names);break;
	    case 'i': indexSearch(names);break; 
	    case 'o': openFile(names);break;
	    case 'v': saveFile(names);break;
	}
	}while(select!='q');
	
 	

}

void getName(vector<string>& names){
while (true) 
{
  string tmp;
  cout<<"Enter the name(q to stop): ";
  getline(cin,tmp);
  if (tmp == "q") break;  
  else
  names.push_back(sWap(tmp));
  
 
}

}

string sWap(string swap ){
	int found;string swapName;
	found=swap.find(' ',0);
	swapName=swap.substr(found+1)+", "+swap.substr(0,found);
	return swapName;
	
}

void getLastNameList(vector<string>&names) {
  {
    cout << "Last Names List" << endl;
    cout << lastNames(names) << endl;
  }
}
string lastNames(vector<string> &names) {
  stringstream ss;
  for(int i = 0; i < names.size(); i++) 
  		{
    	 ss << '"' << names[i].substr(0, names[i].find(',', 0)) << '"' << ' ';
  		}
	
  return ss.str();
}
void indexSearch(vector<string>&names) {
  {
    cout << "Enter the number" << endl;
    cout << names[getNumInRange(1, names.size())-1] << endl;
    
  }
}
int getNumInRange(int min, int max) {
  stringstream ss;
  string input;
  int tmp;
  cout << "Enter an int between "<< min << " and " << max << ": ";
  getline(cin, input); 
  ss << input; 
 
  if (ss >> tmp && tmp >= min && tmp <= max) return tmp;
  else 
  return getNumInRange(min, max);
}


void findName(vector<string>&names)
{
int index;
if(names.size()==0)
cout<<"Nothing to sort, enter name first"<<endl;
else
{
int index;
index=sbfindName(names);
if(index>=0)
cout<<"Found the name: "<<names.at(index)<<" in the vector"<<endl;
else
cout<<"No name match"<<endl;
}

}

int sbfindName(vector<string>& names)
{
	string name;
	cout<<"Enter the name you want to find "<<endl;
	getline(cin,name);
	for(int i=0; i<names.size(); i++) 
    if (names[i] == name) return i; // return ndx of target
    return -1; // target was not found in intArr[0..size-1]

	
	
	
	
}

void disPlay(vector<string>& names)
{	cout<<"Number  Name "<<endl; 
	for(int i=0;i<names.size();i++)
		cout<<setw(4)<<i+1<<'\t'<<names[i]<<endl; 
		cout<<endl;
	
}


void removeName(vector<string>&names)
{	
	string removeName;
	int nameFound;
	if(names.size()==0)
	cout<<"No record, please enter a name first"<<endl;
	else{
	cout<<"Enter the name you want to erase"<<endl;
	getline(cin,removeName);
	for(int i=0; i<names.size();i++)
	{ 
	    if(names[i] == removeName)
	    nameFound=i;
	    else
	    nameFound=-1;
	    
	}
	if(nameFound==-1)
	cout<<"Nothing to remove"<<endl;
	else
	{
	    names.erase(names.begin()+nameFound);
		cout<<removeName<<" has been erased"<<endl;
		
	}
	
	
	}
}

//bubble sort
void sortName(vector<string>& names) 
{ 	
	if(names.size()==0)
	cout<<"Nothing to sort"<<endl;
	else
	
	for (int i = 1; i <names.size(); i++)
    for (int j = 0; j < names.size()-i; j++) 
	{
      if(names[j]>names[j+1])
	  { 
	  	string temp;
	  	temp=names[j+1];
	  	names[j+1]=names[j];
	  	names[j]=temp;
	  	
	  }  
   
    }
}
void openFile(vector<string> & names)
{
ifstream fin;
string fileName;
string name;
char response;
if(!names.size()==0)
{
cout<<"WARNING:REALLY WANT TO OPEN THE FILE? (y/n)";
cin>>response;
cin.ignore();
if(response=='y'){

cout << "Enter the input file name: ";
getline(cin, fileName);        
fin.open(fileName.c_str());
if (fin.fail()) {
    cerr << "could not open intput file "<<endl;
    cout<<endl;
}
else
getline(fin,name);
for (int ndx = 0; !fin.eof(); ndx++) { 
    // note the termination condition
    names.push_back(name);
    getline(fin,name);
}
cout<<names.size()<<" records have been read "<<endl;

fin.close();
}
    else
    system("cls");
}
else
{

cout << "Enter the input file name: ";
getline(cin, fileName);        
fin.open(fileName.c_str());
if (fin.fail()) {
    cerr << "could not open intput file "<<endl;
    cout<<endl;
}
else
getline(fin,name);
for (int ndx = 0; !fin.eof(); ndx++) { 
    // note the termination condition
    names.push_back(name);
    getline(fin,name);
}
cout<<names.size()<<" records have been read "<<endl;

fin.close();
}
}


void saveFile(vector<string> & names)
{
char response;
if(!names.size()==0){
cout<<"WARNING:REALLY WANT TO SAVE THE FILE? (y/n)";
cin>>response;
cin.ignore();
if(response=='y'){
ofstream fout("file.txt");
string filename;
if(fout.fail()){
	cerr<<"could not save files "<<endl;
	cout<<endl;
}
for(int i=0;i<names.size();i++){
	fout<<names[i]<<endl;
	
}
fout.close();
}
cout<<names.size()<<" records have been saved"<<endl;

}
else{
ofstream fout("file.txt");
string filename;
if(fout.fail()){
	cerr<<"could not save files "<<endl;
	cout<<endl;
}
for(int i=0;i<names.size();i++){
	fout<<names[i]<<endl;
	
}
fout.close();
}
}
void testData(vector<string>& names)
{
	names.push_back("Lin, David");
		names.push_back("Hu, Josh");
			names.push_back("Han, Tom");
			
	
}
