#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
using namespace std;
struct seat{
		string row_num;
		string class_name;
		string seats_avail;
		
	};

class flight{
	public:
		string fnum;
		string dtd;    //departure time and date
		string dair;   //departure airport
		string aair;   //arrival airport
		struct seat seatrow[70];
		    
		void Display_available_flight();
		void View_flight();
		void Seat_availibility(string clname);
		void Seat_booking(string rname, string fname, char sname);
		void Exit();	
		
	
		flight(){            //default constructor
			}
		
};
void exit1(flight farray[],int nof);
void flight::Display_available_flight(){
	int count_E=0,count_B=0;
			cout<<fnum<<"\n"<<dtd<<"\n"<<dair<<"\n"<<aair<<"\n";
			for(int k=0; seatrow[k].row_num.empty()!=1; k++){
				if(seatrow[k].class_name=="E"){
					count_E=count_E+seatrow[k].seats_avail.size();
				}else if(seatrow[k].class_name=="B"){
					count_B=count_B+seatrow[k].seats_avail.size();
				}
				cout<<seatrow[k].row_num<<" ";
			    cout<<seatrow[k].class_name<<" ";
			    cout<<seatrow[k].seats_avail<<endl;
			    
	}cout<< "No of Economic class : E   : " <<count_E <<"\n"<<"No of Bussiness class : B  : "<<count_B<<"\n";
	cout<< "\n";
	
}
void flight::View_flight(){
	int count_E=0,count_B=0;
			cout<<fnum<<"\n"<<dtd<<"\n"<<dair<<"\n"<<aair<<"\n";
			for(int k=0; seatrow[k].row_num.empty()!=1; k++){
				if(seatrow[k].class_name=="E"){
					count_E=count_E+seatrow[k].seats_avail.size();
				}else if(seatrow[k].class_name=="B"){
					count_B=count_B+seatrow[k].seats_avail.size();
				}
				cout<<seatrow[k].row_num<<" ";
			    cout<<seatrow[k].class_name<<" ";
			    cout<<seatrow[k].seats_avail<<endl;
	}cout<< "No of Economic class : E   : " <<count_E <<"\n"<<"No of Bussiness class :B  : "<<count_B<<"\n";
	cout<< "\n";
}
void flight::Seat_availibility(string clname){
	cout<<fnum<<"\n"<<dtd<<"\n"<<dair<<"\n"<<aair<<"\n";
	for(int k=0; seatrow[k].row_num.empty()!=1; k++){
		if(seatrow[k].class_name==clname){
			cout<<seatrow[k].row_num<<" "<<seatrow[k].class_name<<" "<<seatrow[k].seats_avail<<endl;
		}
	}
		
}

void flight::Seat_booking(string rname, string fname, char sname){
	int slength;
	cout<<fnum<<"\n"<<dtd<<"\n"<<dair<<"\n"<<aair<<"\n";
	for(int k=0; seatrow[k].row_num.empty()!=1; k++){
		if(seatrow[k].row_num==rname && seatrow[k].class_name==fname){
			slength=seatrow[k].seats_avail.size();
			for(int j=0;j<slength;j++){
				if(seatrow[k].seats_avail[j]==sname){
					cout<<seatrow[k].row_num<<" "<<seatrow[k].class_name<<" "<<seatrow[k].seats_avail<<endl;
					seatrow[k].seats_avail.erase(j,1);
					cout<<"After seat booking"<<endl;
					cout<<seatrow[k].row_num<<" "<<seatrow[k].class_name<<" "<<seatrow[k].seats_avail<<endl;
					
					
				}
			}
			
			
			
			
		}
		
	}
}


int main(){
	string line;
	ifstream file;
	file.open("set data.txt");
	if(!file.is_open()){
		cout<<"error";
	}
	int nof,m;
	int i=0,j;
	while(!file.eof()){         //count the number of objects
		getline(file,line);
		m=line.length();
		char arr[m+1];
		strcpy(arr,line.c_str());
		if(arr[0]=='V'&& arr[1]=='A'){
			nof++;
		}
	}
    file.close();
	
	
	flight *farray=new flight[nof];
	
	file.open("set data.txt");
	if(file.is_open()){
		while(!file.eof()){
			j=0;
			getline(file,line);
			farray[i].fnum=line; 
			
			getline(file,line);
			farray[i].dtd=line;
			
			getline(file,line);
			farray[i].dair=line;
			
			getline(file,line);
			farray[i].aair=line;
			
			while(!line.empty()){ 
				getline(file,line);
				
				stringstream ss(line);     // getting to seat details without spacing
				//cout << i << " " << j << " " << ss << endl;
				ss >> farray[i].seatrow[j].row_num >> farray[i].seatrow[j].class_name >> farray[i].seatrow[j].seats_avail;
				//cout << farray[i].seats[j].row_num << " " << farray[i].seats[j].class_name << " " << farray[i].seats[j].seats_avail << endl;
				j++;
			}
			i++;
	    }
	    i=0;
		j=0;
		for(i=0;i<nof;i++){
		    cout<<farray[i].fnum<<"\n"<<farray[i].dtd<<"\n"<<farray[i].dair<<"\n"<<farray[i].aair<<"\n";
		    for(j=0;farray[i].seatrow[j].row_num.empty()!=1;j++){
			    cout<<farray[i].seatrow[j].row_num<<" ";
			    cout<<farray[i].seatrow[j].class_name<<" ";
			    cout<<farray[i].seatrow[j].seats_avail<<endl;
		    }cout<< "\n";
	}

		
	while(1){
    
	cout<< "\n\nPlease select an option!" <<endl;
	cout<< "___________________________"<<endl;
	cout<< "1.Display_available_flight" <<endl;
	cout<< "2.View_flight"<<endl;
	cout<< "3.Seat_availibility"<<endl;
	cout<< "4.Seat_booking"<<endl;
	cout<< "5.Exit\n\n" <<endl;
	int op;
	cout<< "Enter the option:" << endl;
	cin>> op ;

string number;
	int seats=0,count1=0;
	string num;
	int count=0;
	switch(op){
		case 1:{
			for(int x=0;x<nof;x++){
		        farray[x].Display_available_flight();
		    }
			break;
			}
		case 2:{
			
	
			string num;
			int count=0;
			cout<<"Enter flight number :";
			cin>>num;
			
			for(int x=0;x<nof;x++){
			
				if(farray[x].fnum==num){
					farray[x].View_flight();
					break;
				}
				else{
					count++;
				}
				
			}if(count==5){
				cout<<"Flight number is not found that file!"<<endl;
			}
			break;
				}
			
		case 3:{
	        string number;
	        string clname;
			int seats,count1=0;
			cout<<"Enter flight number :";
			cin>>number;
			cout<<"Enter class name E/B :";
			cin>>clname;
			cout<< "Enter number of required seats :";
			cin>>seats;
			for(int x=0;x<nof;x++){
				if(farray[x].fnum==number){
					for(int k=0; farray[x].seatrow[k].row_num.empty()!=1; k++){
						if(farray[x].seatrow[k].class_name==clname){
							count1=count1+farray[x].seatrow[k].seats_avail.size();
						
					    }
				    }
					if(count1>=seats ){
						farray[x].Seat_availibility(clname);
					}
			        else{
						cout<<"It has not available seats!"<<endl;
					}
					
				}
				else{
					count++;
			    }
			}
			if(count==nof){
				cout<<"\nFlight number is not found that file!"<<endl;
		    }
			break;
			}
				
		case 4:{
			int flag =0;
			char sname;
			string fnumber,fname,rname;
			cout<<"Enter flight number :";
			cin>>fnumber;
			cout<<"Enter row number :";
			cin>>rname;
			cout<<"Enter class name E/B :";
			cin>>fname;
			cout<<"Enter booking available seat location name A,B,C,D or F :";
			cin>>sname;
			for(int x=0;x<nof;x++){
				if(farray[x].fnum==fnumber){
					for(int k=0; farray[x].seatrow[k].row_num.empty()!=1; k++){
						if(farray[x].seatrow[k].row_num==rname && farray[x].seatrow[k].class_name==fname ){
							int length=farray[x].seatrow[k].seats_avail.size();
							for(int j=0;j<length;j++){
								if(farray[x].seatrow[k].seats_avail[j]==sname)
									flag=1;
							    }
							farray[x].Seat_booking(rname,fname,sname);
							
						}
						
					
					}if(flag==0){
						cout<<"Not available seats!"<<endl;
					}
					
				}else{
					count++;
				}
			}
			if(count==nof){
				cout<<"\nFlight number is not found that file!"<<endl;
		    }
			
			break;
			}
			
			case 5:{
				exit1(farray,nof);
				
				break;
			}
		
			
		default:
			cout << "Wrong option!"<< endl;
		
	
    }
} 

	}
else{
		cout << "File is not open!" <<endl;
	}
	
	
	return 0;
}
void exit1(flight farray[],int nof){
	ofstream out;
	out.open("set data.dat");
		for(int x=0;x<nof;x++){
			out<<farray[x].fnum<<endl;
			out<<farray[x].dtd<<endl;
			out<<farray[x].dair<<endl;
			out<<farray[x].aair<<endl;
			for(int l=0;farray[x].seatrow[l].row_num.empty()!=1;l++){
				out<<farray[x].seatrow[l].row_num<<" "<<farray[x].seatrow[l].class_name<<" "<<farray[x].seatrow[l].seats_avail<<endl;
			}
			out<<endl;
		}
		out.close();
		exit(0);
}

