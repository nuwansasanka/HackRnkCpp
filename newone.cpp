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
	private:
	    string fnum;
		string dtd;    //departure time and date
		string dair;   //departure airport
		string aair;   //arrival airport
		struct seat seatrow[70];
	public:
		void Display_available_flight();
		void View_flight();
		void Seat_availibility(string clname);
		void Seat_booking();
		
		string getFnum(){
			return fnum;
		}
		string getDtd(){
			return dtd;
		}
		string getDair(){
			return dair;
		}
		string getAair(){
			return aair;
		}
		seat getSeatrow(int i){
		    return seatrow[i];
	    }
	    void setFnum(string line){
		    fnum =line;
	    }
	    void setDtd(string line){
		    dtd =line;
	    }
	    void setDair(string line){
		    dair =line;
	    }
	    void setAair(string line){
		    aair =line;
	    }
	    void setSeats(int i ,seat s){
		    seatrow[i]=s;
	    }
		
};
void Exit(flight farray[],int nof);
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
	//cout<<fnum<<"\n"<<dtd<<"\n"<<dair<<"\n"<<aair<<"\n";
	for(int k=0; seatrow[k].row_num.empty()!=1; k++){
		if(seatrow[k].class_name==clname){
			cout<<seatrow[k].row_num<<" "<<seatrow[k].class_name<<" "<<seatrow[k].seats_avail<<endl;
		}
	}
		
}

void flight::Seat_booking(){
	int slength,nos,n=1;
	string rname,fname;
	char sname;
	//cout<<fnum<<"\n"<<dtd<<"\n"<<dair<<"\n"<<aair<<"\n";
	cout<<"Enter number of booking seats:";
	cin>>nos;
	for(int n=0;n<nos;n++){
		int flag=0;
		int status =0;
		cout<<"Enter row number :";
	    cin>>rname;
	    cout<<"Enter class name E/B :";
	    cin>>fname;
		cout<<"Enter booking seat location:";
	    cin>>sname;
		for(int k=0; seatrow[k].row_num.empty()!=1; k++){
			if(seatrow[k].row_num==rname && seatrow[k].class_name==fname){
				status=1;
				
				slength=seatrow[k].seats_avail.size();
			    	for(int j=0;j<slength;j++){
				        if(seatrow[k].seats_avail[j]==sname){
					        cout<<seatrow[k].row_num<<" "<<seatrow[k].class_name<<" "<<seatrow[k].seats_avail<<endl;
					        seatrow[k].seats_avail.erase(j,1);
					        cout<<"Seat booking is successful!"<<endl;
					        cout<<"After seat booking"<<endl;
					        cout<<seatrow[k].row_num<<" "<<seatrow[k].class_name<<" "<<seatrow[k].seats_avail<<endl;
					        flag=1;
					
			    	    }
			        
			    }if(flag==0){
			    	
				    cout<<"Not available seat!"<<endl;
				}
			
		    }
		
		
	    }if(status==0){
		    cout<<"Invalid row number or class name!"<<endl;
	    }
}
}	
int main(){
	string line;
	ifstream file;
	file.open("datafile.txt");
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
	file.open("datafile.txt");
	if(file.is_open()){
		while(!file.eof()){
			j=0;
			getline(file,line);
			farray[i].setFnum(line); 
			
			getline(file,line);
			farray[i].setDtd(line);
			
			getline(file,line);
			farray[i].setDair(line);
			
			getline(file,line);
			farray[i].setAair(line);
			
			while(!line.empty()){ 
				getline(file,line);
				
				stringstream ss(line);     // getting to seat details without spacing
				//cout << i << " " << j << " " << ss << endl;				
				seat s1;
				ss >> s1.row_num >> s1.class_name >> s1.seats_avail;
				farray[i].setSeats(j,s1);
				j++;
			}
			i++;
	    }
	    /*i=0;
		j=0;
		for(i=0;i<nof;i++){
		    cout<<farray[i].fnum<<"\n"<<farray[i].dtd<<"\n"<<farray[i].dair<<"\n"<<farray[i].aair<<"\n";
		    for(j=0;farray[i].seatrow[j].row_num.empty()!=1;j++){
			    cout<<farray[i].seatrow[j].row_num<<" ";
			    cout<<farray[i].seatrow[j].class_name<<" ";
			    cout<<farray[i].seatrow[j].seats_avail<<endl;
		    }cout<< "\n";
	}*/
	cout<< "\n___________________Airline Reservation Sysetem____________________" <<endl;
	while(1){
    
	cout<< "\nPlease select an option!" <<endl;
	
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
			
				if(farray[x].getFnum()==num){
					farray[x].View_flight();
					break;
				}
				else{
					count++;
				}
			}if(count==nof){
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
				if(farray[x].getFnum()==number){
					for(int k=0; farray[x].getSeatrow(k).row_num.empty()!=1; k++){
						if(farray[x].getSeatrow(k).class_name==clname){
							count1=count1+farray[x].getSeatrow(k).seats_avail.size();
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
			int flag =0,nos,n=1;        //nos=number of availble seats
			//char sname;
			string fnumber,fname,rname;
			cout<<"Enter flight number :";
			cin>>fnumber;
			int status=0;
			for(int m=0;m<nof;m++){
				if(farray[m].getFnum()==fnumber){
					farray[m].Seat_booking();
					    status=1;
				}
				
			}if(status==0){
					cout<<"\nFlight number is not found that file!"<<endl;
				}
			break;
			}
			case 5:{
				Exit(farray,nof);
				
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


void Exit(flight farray[],int nof){
	ofstream out;
	out.open("datafile.dat");
	cout<<"Update is successful!"<<endl;
	for(int x=0;x<nof;x++){
		out<<farray[x].getFnum()<<endl;
		out<<farray[x].getDtd()<<endl;
		out<<farray[x].getDair()<<endl;
		out<<farray[x].getAair()<<endl;
		for(int l=0;farray[x].getSeatrow(l).row_num.empty()!=1;l++){
			out<<farray[x].getSeatrow(l).row_num<<" "<<farray[x].getSeatrow(l).class_name<<" "<<farray[x].getSeatrow(l).seats_avail<<endl;
		}
		if(x!=nof-1){
			out<<endl;
		}
		
	}
	out.close();
	exit(0);
}
